//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JSONValue {
    enum {
        JSON_STRING,
        JSON_NUMBER,
        JSON_OBJECT,
        JSON_ARRAY,
        JSON_TRUE,
        JSON_FALSE,
        JSON_NULL
    } type;
    union {
        char* string;
        double number;
        struct JSONObject* object;
        struct JSONArray* array;
    } value;
} JSONValue;

typedef struct JSONPair {
    char* key;
    JSONValue* value;
} JSONPair;

typedef struct JSONObject {
    int num_pairs;
    JSONPair** pairs;
} JSONObject;

typedef struct JSONArray {
    int num_elements;
    JSONValue** elements;
} JSONArray;

JSONValue* parse_value(char* json);
JSONValue* parse_object(char* json);
JSONValue* parse_array(char* json);
JSONValue* parse_string(char* json);
JSONValue* parse_number(char* json);
JSONValue* parse_boolean(char* json);
JSONValue* parse_null(char* json);
char* skip_whitespace(char* json);

char* skip_whitespace(char* json) {
    while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') {
        json++;
    }
    return json;
}

JSONValue* parse_value(char* json) {
    json = skip_whitespace(json);
    switch (*json) {
        case '{':
            return parse_object(json);
        case '[':
            return parse_array(json);
        case '\"':
            return parse_string(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case 'n':
            return parse_null(json);
        default:
            return parse_number(json);
    }
}

JSONValue* parse_object(char* json) {
    JSONObject* obj = malloc(sizeof(JSONObject));
    obj->num_pairs = 0;
    obj->pairs = NULL;
    json = skip_whitespace(json + 1);
    if (*json == '}') {
        return (JSONValue*) obj;
    }
    while (1) {
        obj->num_pairs++;
        obj->pairs = realloc(obj->pairs, sizeof(JSONPair*) * obj->num_pairs);
        char* key = parse_string(json);
        obj->pairs[obj->num_pairs - 1] = malloc(sizeof(JSONPair));
        obj->pairs[obj->num_pairs - 1]->key = key;
        json = skip_whitespace(json);
        if (*json != ':') {
            fprintf(stderr, "Error: Object key-value pair missing ':'\n");
            exit(1);
        }
        json = skip_whitespace(json + 1);
        JSONValue* value = parse_value(json);
        obj->pairs[obj->num_pairs - 1]->value = value;
        json = skip_whitespace((char*) obj->pairs[obj->num_pairs - 1]->value);
        if (*json == '}') {
            return (JSONValue*) obj;
        }
        if (*json != ',') {
            fprintf(stderr, "Error: Object missing ','\n");
            exit(1);
        }
        json = skip_whitespace(json + 1);
    }
}

JSONValue* parse_array(char* json) {
    JSONArray* arr = malloc(sizeof(JSONArray));
    arr->num_elements = 0;
    arr->elements = NULL;
    json = skip_whitespace(json + 1);
    if (*json == ']') {
        return (JSONValue*) arr;
    }
    while (1) {
        arr->num_elements++;
        arr->elements = realloc(arr->elements, sizeof(JSONValue*) * arr->num_elements);
        JSONValue* value = parse_value(json);
        arr->elements[arr->num_elements - 1] = value;
        json = skip_whitespace((char*) arr->elements[arr->num_elements - 1]);
        if (*json == ']') {
            return (JSONValue*) arr;
        }
        if (*json != ',') {
            fprintf(stderr, "Error: Array missing ','\n");
            exit(1);
        }
        json = skip_whitespace(json + 1);
    }
}

JSONValue* parse_string(char* json) {
    char* start = json + 1;
    char* end = start + 1;
    while (*end != '\"' || *(end - 1) == '\\') {
        end++;
    }
    *end = '\0';
    char* string = malloc(end - start + 1);
    char* out = string;
    while (*start) {
        if (*start == '\\') {
            start++;
            switch (*start) {
                case '\"':
                    *out++ = '\"';
                    break;
                case '\\':
                    *out++ = '\\';
                    break;
                case '/':
                    *out++ = '/';
                    break;
                case 'b':
                    *out++ = '\b';
                    break;
                case 'f':
                    *out++ = '\f';
                    break;
                case 'n':
                    *out++ = '\n';
                    break;
                case 'r':
                    *out++ = '\r';
                    break;
                case 't':
                    *out++ = '\t';
                    break;
                case 'u':
                    //TODO: handle unicode
                    break;
                default:
                    *out++ = *start;
                    break;
            }
        } else {
            *out++ = *start;
        }
        start++;
    }
    *out = '\0';
    JSONValue* value = malloc(sizeof(JSONValue));
    value->type = JSON_STRING;
    value->value.string = string;
    return value;
}

JSONValue* parse_number(char* json) {
    JSONValue* value = malloc(sizeof(JSONValue));
    value->type = JSON_NUMBER;
    sscanf(json, "%lf", &value->value.number);
    return value;
}

JSONValue* parse_boolean(char* json) {
    JSONValue* value = malloc(sizeof(JSONValue));
    value->type = (*json == 't' ? JSON_TRUE : JSON_FALSE);
    return value;
}

JSONValue* parse_null(char* json) {
    JSONValue* value = malloc(sizeof(JSONValue));
    value->type = JSON_NULL;
    return value;
}

int main() {
    char input[1024];
    printf("Enter JSON input: ");
    fgets(input, 1024, stdin);
    JSONValue* value = parse_value(input);
    switch (value->type) {
        case JSON_STRING:
            printf("Parsed string: \"%s\"\n", value->value.string);
            break;
        case JSON_NUMBER:
            printf("Parsed number: %lf\n", value->value.number);
            break;
        case JSON_OBJECT:
            printf("Parsed object with %d pairs:\n", ((JSONObject*) value->value.object)->num_pairs);
            for (int i=0; i < ((JSONObject*) value->value.object)->num_pairs; i++) {
                printf("%s: ", ((JSONObject*) value->value.object)->pairs[i]->key);
                JSONValue* v = ((JSONObject*) value->value.object)->pairs[i]->value;
                switch (v->type) {
                    case JSON_STRING:
                        printf("\"%s\"", v->value.string);
                        break;
                    case JSON_NUMBER:
                        printf("%lf", v->value.number);
                        break;
                    case JSON_TRUE:
                        printf("true");
                        break;
                    case JSON_FALSE:
                        printf("false");
                        break;
                    case JSON_NULL:
                        printf("null");
                        break;
                    default:
                        fprintf(stderr, "Error: invalid object value type\n");
                        exit(1);
                }
                printf("\n");
            }
            break;
        case JSON_ARRAY:
            printf("Parsed array with %d elements:\n", ((JSONArray*) value->value.array)->num_elements);
            for (int i=0; i < ((JSONArray*) value->value.array)->num_elements; i++) {
                JSONValue* v = ((JSONArray*) value->value.array)->elements[i];
                switch (v->type) {
                    case JSON_STRING:
                        printf("\"%s\"", v->value.string);
                        break;
                    case JSON_NUMBER:
                        printf("%lf", v->value.number);
                        break;
                    case JSON_TRUE:
                        printf("true");
                        break;
                    case JSON_FALSE:
                        printf("false");
                        break;
                    case JSON_NULL:
                        printf("null");
                        break;
                    default:
                        fprintf(stderr, "Error: invalid array element type\n");
                        exit(1);
                }
                printf("\n");
            }
            break;
        case JSON_TRUE:
            printf("Parsed boolean: true\n");
            break;
        case JSON_FALSE:
            printf("Parsed boolean: false\n");
            break;
        case JSON_NULL:
            printf("Parsed null\n");
            break;
        default:
            fprintf(stderr, "Error: invalid value type\n");
            exit(1);
    }
    return 0;
}