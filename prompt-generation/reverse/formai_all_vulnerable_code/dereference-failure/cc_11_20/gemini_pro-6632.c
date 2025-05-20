//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_NULL "null"
#define JSON_TRUE "true"
#define JSON_FALSE "false"

typedef struct json_value {
    enum {
        JSON_TYPE_NULL,
        JSON_TYPE_BOOL,
        JSON_TYPE_NUM,
        JSON_TYPE_STR,
        JSON_TYPE_ARR,
        JSON_TYPE_OBJ
    } type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            size_t count;
            struct json_value **values;
        } array;
        struct {
            size_t count;
            char **keys;
            struct json_value **values;
        } object;
    } data;
} json_value;

static json_value *json_parse(const char *json) {
    json_value *value;
    const char *start = json;
    const char *end = json;
    while (*end != '\0') { end++; }

    // Skip leading whitespace
    while (start != end && *start == ' ') { start++; }

    // Check for null
    if (strncmp(start, JSON_NULL, strlen(JSON_NULL)) == 0) {
        value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_NULL;
        return value;
    }

    // Check for boolean
    if (strncmp(start, JSON_TRUE, strlen(JSON_TRUE)) == 0) {
        value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_BOOL;
        value->data.boolean = 1;
        return value;
    }
    if (strncmp(start, JSON_FALSE, strlen(JSON_FALSE)) == 0) {
        value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_BOOL;
        value->data.boolean = 0;
        return value;
    }

    // Check for number
    if (*start >= '0' && *start <= '9') {
        value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_NUM;
        value->data.number = strtod(start, NULL);
        return value;
    }

    // Check for string
    if (*start == '"') {
        start++;
        end--;
        while (start != end && *end != '"') { end--; }
        if (*end == '"') {
            value = malloc(sizeof(json_value));
            value->type = JSON_TYPE_STR;
            value->data.string = malloc(end - start + 1);
            strncpy(value->data.string, start, end - start);
            value->data.string[end - start] = '\0';
            return value;
        }
    }

    // Check for array
    if (*start == '[') {
        value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_ARR;
        value->data.array.count = 0;
        value->data.array.values = NULL;

        start++;
        while (start != end && *start != ']') {
            json_value *element = json_parse(start);
            if (element == NULL) { return NULL; }

            value->data.array.values = realloc(value->data.array.values, (value->data.array.count + 1) * sizeof(json_value *));
            value->data.array.values[value->data.array.count++] = element;

            while (start != end && *start == ' ') { start++; }
            if (*start == ',') { start++; }
        }
        if (*start == ']') {
            return value;
        }
    }

    // Check for object
    if (*start == '{') {
        value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_OBJ;
        value->data.object.count = 0;
        value->data.object.keys = NULL;
        value->data.object.values = NULL;

        start++;
        while (start != end && *start != '}') {
            const char *key_start = start;
            const char *key_end = start;
            while (key_end != end && *key_end != ':') { key_end++; }
            if (*key_end == ':') {
                size_t key_length = key_end - key_start;
                char *key = malloc(key_length + 1);
                strncpy(key, key_start, key_length);
                key[key_length] = '\0';

                start = key_end + 1;
                json_value *element = json_parse(start);
                if (element == NULL) { return NULL; }

                value->data.object.keys = realloc(value->data.object.keys, (value->data.object.count + 1) * sizeof(char *));
                value->data.object.values = realloc(value->data.object.values, (value->data.object.count + 1) * sizeof(json_value *));
                value->data.object.keys[value->data.object.count] = key;
                value->data.object.values[value->data.object.count++] = element;

                while (start != end && *start == ' ') { start++; }
                if (*start == ',') { start++; }
            }
        }
        if (*start == '}') {
            return value;
        }
    }

    return NULL;
}

static void json_free(json_value *value) {
    switch (value->type) {
        case JSON_TYPE_STR:
            free(value->data.string);
            break;
        case JSON_TYPE_ARR:
            for (size_t i = 0; i < value->data.array.count; i++) {
                json_free(value->data.array.values[i]);
            }
            free(value->data.array.values);
            break;
        case JSON_TYPE_OBJ:
            for (size_t i = 0; i < value->data.object.count; i++) {
                free(value->data.object.keys[i]);
                json_free(value->data.object.values[i]);
            }
            free(value->data.object.keys);
            free(value->data.object.values);
            break;
        default:
            break;
    }
    free(value);
}

static void json_print(json_value *value) {
    switch (value->type) {
        case JSON_TYPE_NULL:
            printf("null");
            break;
        case JSON_TYPE_BOOL:
            printf(value->data.boolean ? "true" : "false");
            break;
        case JSON_TYPE_NUM:
            printf("%f", value->data.number);
            break;
        case JSON_TYPE_STR:
            printf("\"%s\"", value->data.string);
            break;
        case JSON_TYPE_ARR:
            printf("[");
            for (size_t i = 0; i < value->data.array.count; i++) {
                json_print(value->data.array.values[i]);
                if (i < value->data.array.count - 1) { printf(", "); }
            }
            printf("]");
            break;
        case JSON_TYPE_OBJ:
            printf("{");
            for (size_t i = 0; i < value->data.object.count; i++) {
                printf("\"%s\": ", value->data.object.keys[i]);
                json_print(value->data.object.values[i]);
                if (i < value->data.object.count - 1) { printf(", "); }
            }
            printf("}");
            break;
        default:
            break;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <json>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *json = argv[1];
    json_value *value = json_parse(json);
    if (value == NULL) {
        fprintf(stderr, "Error: Invalid JSON\n");
        return EXIT_FAILURE;
    }

    json_print(value);
    printf("\n");

    json_free(value);
    return EXIT_SUCCESS;
}