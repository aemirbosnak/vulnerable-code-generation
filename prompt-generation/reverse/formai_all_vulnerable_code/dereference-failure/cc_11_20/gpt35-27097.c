//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

typedef enum {JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_TRUE, JSON_FALSE, JSON_NULL} json_type;

typedef struct json {
    json_type type;
    union {
        struct json_object *obj;
        struct json_array *arr;
        char *str;
        double num;
        int boolean;
    } value;
} json;

typedef struct json_pair {
    char *key;
    struct json *value;
} json_pair;

typedef struct json_object {
    json_pair **pairs;
    size_t size;
} json_object;

typedef struct json_array {
    struct json **items;
    size_t size;
} json_array;

int parse_object(char **json_str, json_object **obj);
int parse_array(char **json_str, json_array **arr);
int parse_string(char **json_str, char **str);

int parse_object(char **json_str, json_object **obj) {
    int status = SUCCESS;

    // consume opening brace
    if (**json_str != '{') {
        status = FAILURE;
        goto exit;
    }
    (*json_str)++;

    // initialize object
    *obj = malloc(sizeof(json_object));
    (*obj)->pairs = NULL;
    (*obj)->size = 0;

    // consume any whitespace
    while (**json_str == ' ' || **json_str == '\t' || **json_str == '\r' || **json_str == '\n')
        (*json_str)++;

    // parse pairs
    while (**json_str != '}') {
        char *key = NULL;
        struct json *value = NULL;

        // parse key
        status = parse_string(json_str, &key);
        if (status != SUCCESS)
            goto exit;

        // consume any whitespace
        while (**json_str == ' ' || **json_str == '\t' || **json_str == '\r' || **json_str == '\n')
            (*json_str)++;

        // check for colon delimiter
        if (**json_str != ':') {
            status = FAILURE;
            goto exit;
        }
        (*json_str)++;

        // consume any whitespace
        while (**json_str == ' ' || **json_str == '\t' || **json_str == '\r' || **json_str == '\n')
            (*json_str)++;

        // parse value
        switch (**json_str) {
            case '{':
                status = parse_object(json_str, (json_object **)&value);
                break;
            case '[':
                status = parse_array(json_str, (json_array **)&value);
                break;
            case '\"':
                status = parse_string(json_str, (char **)&value);
                break;
            case 't':
                value = malloc(sizeof(json));
                value->type = JSON_TRUE;
                value->value.boolean = 1;
                (*json_str) += 4;
                break;
            case 'f':
                value = malloc(sizeof(json));
                value->type = JSON_FALSE;
                value->value.boolean = 0;
                (*json_str) += 5;
                break;
            case 'n':
                value = malloc(sizeof(json));
                value->type = JSON_NULL;
                (*json_str) += 4;
                break;
            default:
                status = FAILURE;
                goto exit;
        }

        // add pair to object
        json_pair *pair = malloc(sizeof(json_pair));
        pair->key = key;
        pair->value = value;

        (*obj)->pairs = realloc((*obj)->pairs, (++(*obj)->size) * sizeof(json_pair *));
        (*obj)->pairs[(*obj)->size - 1] = pair;

        // consume any whitespace
        while (**json_str == ' ' || **json_str == '\t' || **json_str == '\r' || **json_str == '\n')
            (*json_str)++;

        // check for comma delimiter
        if (**json_str == ',')
            (*json_str)++;
    }

    // consume closing brace
    (*json_str)++;

exit:
    if (status != SUCCESS) {
        free(*obj);
        *obj = NULL;
    }
    return status;
}

int parse_array(char **json_str, json_array **arr) {
    int status = SUCCESS;

    // consume opening bracket
    if (**json_str != '[') {
        status = FAILURE;
        goto exit;
    }
    (*json_str)++;

    // initialize array
    *arr = malloc(sizeof(json_array));
    (*arr)->items = NULL;
    (*arr)->size = 0;

    // consume any whitespace
    while (**json_str == ' ' || **json_str == '\t' || **json_str == '\r' || **json_str == '\n')
        (*json_str)++;

    // parse items
    while (**json_str != ']') {
        struct json *item = NULL;

        // parse value
        switch (**json_str) {
            case '{':
                status = parse_object(json_str, (json_object **)&item);
                break;
            case '[':
                status = parse_array(json_str, (json_array **)&item);
                break;
            case '\"':
                status = parse_string(json_str, (char **)&item);
                break;
            case 't':
                item = malloc(sizeof(json));
                item->type = JSON_TRUE;
                item->value.boolean = 1;
                (*json_str) += 4;
                break;
            case 'f':
                item = malloc(sizeof(json));
                item->type = JSON_FALSE;
                item->value.boolean = 0;
                (*json_str) += 5;
                break;
            case 'n':
                item = malloc(sizeof(json));
                item->type = JSON_NULL;
                (*json_str) += 4;
                break;
            default:
                status = FAILURE;
                goto exit;
        }

        // add item to array
        (*arr)->items = realloc((*arr)->items, (++(*arr)->size) * sizeof(json *));
        (*arr)->items[(*arr)->size - 1] = item;

        // consume any whitespace
        while (**json_str == ' ' || **json_str == '\t' || **json_str == '\r' || **json_str == '\n')
            (*json_str)++;

        // check for comma delimiter
        if (**json_str == ',')
            (*json_str)++;
    }

    // consume closing bracket
    (*json_str)++;

exit:
    if (status != SUCCESS) {
        free(*arr);
        *arr = NULL;
    }
    return status;
}

int parse_string(char **json_str, char **str) {
    int status = SUCCESS;

    // consume opening quote
    if (**json_str != '\"') {
        status = FAILURE;
        goto exit;
    }
    (*json_str)++;

    // initialize string
    char *temp_str = malloc(sizeof(char));
    temp_str[0] = '\0';

    while (**json_str != '\"' && **json_str != '\0') {
        char *temp = NULL;

        // escape characters
        if (**json_str == '\\') {
            (*json_str)++;
            switch (**json_str) {
                case '\\':
                    temp = "\\\\";
                    break;
                case '\"':
                    temp = "\\\"";
                    break;
                case '/':
                    temp = "\\/";
                    break;
                case 'b':
                    temp = "\\b";
                    break;
                case 'f':
                    temp = "\\f";
                    break;
                case 'n':
                    temp = "\\n";
                    break;
                case 'r':
                    temp = "\\r";
                    break;
                case 't':
                    temp = "\\t";
                    break;
                case 'u':
                    temp = malloc(6 * sizeof(char));
                    strncpy(temp, *json_str, 6);
                    temp[6] = '\0';
                    (*json_str) += 5;
                    break;
                default:
                    status = FAILURE;
                    goto exit;
            }
        }
        // regular characters
        else {
            temp = malloc(2 * sizeof(char));
            strncpy(temp, *json_str, 1);
            temp[1] = '\0';
        }

        // append to string
        temp_str = realloc(temp_str, (strlen(temp_str) + strlen(temp) + 1) * sizeof(char));
        strcat(temp_str, temp);

        // free temp memory
        if (**json_str == 'u')
            free(temp);
        (*json_str)++;
    }

    // consume closing quote
    (*json_str)++;

    // return string
    *str = temp_str;

exit:
    if (status != SUCCESS) {
        free(temp_str);
        *str = NULL;
    }
    return status;
}

int main() {
    char *json_str = "{\"name\":\"John\",\"age\":26,\"city\":\"New York\"}";
    json_object *obj = NULL;

    int status = parse_object(&json_str, &obj);

    if (status == SUCCESS) {
        for (size_t i = 0; i < obj->size; i++) {
            printf("%s: ", obj->pairs[i]->key);
            switch (obj->pairs[i]->value->type) {
                case JSON_STRING:
                    printf("%s\n", obj->pairs[i]->value->value.str);
                    break;
                case JSON_NUMBER:
                    printf("%f\n", obj->pairs[i]->value->value.num);
                    break;
                case JSON_TRUE:
                    printf("true\n");
                    break;
                case JSON_FALSE:
                    printf("false\n");
                    break;
                case JSON_NULL:
                    printf("null\n");
                    break;
                default:
                    printf("Invalid or unsupported JSON type.\n");
            }
        }
    } else {
        printf("Failed to parse JSON.\n");
    }

    return status;
}