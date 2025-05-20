//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 1024

typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JSON_TYPE;

typedef struct JSON_VALUE {
    JSON_TYPE type;
    union {
        int boolean;
        double number;
        char *string;
        struct JSON_VALUE **array;
        int array_length;
        struct JSON_VALUE_PAIR **object;
        int object_length;
    } value;
} JSON_VALUE;

typedef struct JSON_VALUE_PAIR {
    char *key;
    JSON_VALUE *value;
} JSON_VALUE_PAIR;

JSON_VALUE *json_parse(const char *json);
void json_free(JSON_VALUE *json);
void json_print(JSON_VALUE *json, int indent);

int main() {
    const char *json_string = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";
    JSON_VALUE *json = json_parse(json_string);

    json_print(json, 0);

    json_free(json);

    return 0;
}

JSON_VALUE *json_parse(const char *json) {
    char token[MAX_TOKEN_LENGTH];
    int token_length = 0;

    JSON_VALUE *json_value = malloc(sizeof(JSON_VALUE));
    if (json_value == NULL) {
        return NULL;
    }

    while (*json != '\0') {
        // Skip whitespace
        while (*json == ' ' || *json == '\t' || *json == '\n' || *json == '\r') {
            json++;
        }

        // Get the next token
        token_length = 0;
        while (*json != '\0' && *json != ' ' && *json != '\t' && *json != '\n' && *json != '\r' && *json != ',' && *json != '}' && *json != ']') {
            token[token_length++] = *json++;
        }
        token[token_length] = '\0';

        // Determine the type of the token
        if (strcmp(token, "null") == 0) {
            json_value->type = JSON_NULL;
        } else if (strcmp(token, "true") == 0) {
            json_value->type = JSON_BOOL;
            json_value->value.boolean = 1;
        } else if (strcmp(token, "false") == 0) {
            json_value->type = JSON_BOOL;
            json_value->value.boolean = 0;
        } else if (strchr(token, '.') != NULL) {
            json_value->type = JSON_NUMBER;
            json_value->value.number = atof(token);
        } else if (token[0] == '"' && token[token_length - 1] == '"') {
            json_value->type = JSON_STRING;
            json_value->value.string = strndup(token + 1, token_length - 2);
        } else if (token[0] == '[' && token[token_length - 1] == ']') {
            json_value->type = JSON_ARRAY;
            json_value->value.array = NULL;
            json_value->value.array_length = 0;

            // Parse the array elements
            while (*json != '\0' && *json != ']') {
                JSON_VALUE *array_element = json_parse(json);
                if (array_element == NULL) {
                    return NULL;
                }

                json_value->value.array = realloc(json_value->value.array, sizeof(JSON_VALUE *) * (json_value->value.array_length + 1));
                json_value->value.array[json_value->value.array_length++] = array_element;

                // Skip the comma
                while (*json == ',') {
                    json++;
                }
            }

            if (*json == ']') {
                json++;
            }
        } else if (token[0] == '{' && token[token_length - 1] == '}') {
            json_value->type = JSON_OBJECT;
            json_value->value.object = NULL;
            json_value->value.object_length = 0;

            // Parse the object properties
            while (*json != '\0' && *json != '}') {
                // Get the key
                token_length = 0;
                while (*json != ':' && *json != '\0') {
                    token[token_length++] = *json++;
                }
                token[token_length] = '\0';

                // Parse the value
                JSON_VALUE *object_value = json_parse(json);
                if (object_value == NULL) {
                    return NULL;
                }

                // Add the property to the object
                json_value->value.object = realloc(json_value->value.object, sizeof(JSON_VALUE_PAIR *) * (json_value->value.object_length + 1));
                json_value->value.object[json_value->value.object_length++] = malloc(sizeof(JSON_VALUE_PAIR));
                json_value->value.object[json_value->value.object_length - 1]->key = strndup(token, token_length);
                json_value->value.object[json_value->value.object_length - 1]->value = object_value;

                // Skip the comma
                while (*json == ',') {
                    json++;
                }
            }

            if (*json == '}') {
                json++;
            }
        } else {
            return NULL;
        }
    }

    return json_value;
}

void json_free(JSON_VALUE *json) {
    switch (json->type) {
        case JSON_STRING:
            free(json->value.string);
            break;
        case JSON_ARRAY:
            for (int i = 0; i < json->value.array_length; i++) {
                json_free(json->value.array[i]);
            }
            free(json->value.array);
            break;
        case JSON_OBJECT:
            for (int i = 0; i < json->value.object_length; i++) {
                free(json->value.object[i]->key);
                json_free(json->value.object[i]->value);
                free(json->value.object[i]);
            }
            free(json->value.object);
            break;
    }

    free(json);
}

void json_print(JSON_VALUE *json, int indent) {
    char padding[indent + 1];
    memset(padding, ' ', indent);
    padding[indent] = '\0';

    switch (json->type) {
        case JSON_NULL:
            printf("%snull", padding);
            break;
        case JSON_BOOL:
            printf("%s%s", padding, json->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%s%f", padding, json->value.number);
            break;
        case JSON_STRING:
            printf("%s\"%s\"", padding, json->value.string);
            break;
        case JSON_ARRAY:
            printf("%s[\n", padding);
            for (int i = 0; i < json->value.array_length; i++) {
                json_print(json->value.array[i], indent + 2);
                printf(",\n");
            }
            printf("%s]", padding);
            break;
        case JSON_OBJECT:
            printf("%s{\n", padding);
            for (int i = 0; i < json->value.object_length; i++) {
                printf("%s\"%s\": ", padding, json->value.object[i]->key);
                json_print(json->value.object[i]->value, indent + 2);
                printf(",\n");
            }
            printf("%s}", padding);
            break;
    }
}