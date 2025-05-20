//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type_t;

typedef struct {
    json_type_t type;
    char value[MAX_SIZE];
} json_object_t;

void trim(char *str) {
    int i, j = strlen(str) - 1;
    while (i < j && (isspace(str[i]) || str[i] == '\"')) i++;
    while (j > i && (isspace(str[j]) || str[j] == '\"')) j--;
    str[j + 1] = '\0';
    strcpy(str, &str[i]);
}

json_object_t *parse_json_object(char *json) {
    json_object_t *object = malloc(sizeof(json_object_t));
    char *cur = json;
    switch (*cur) {
        case '{':
            object->type = JSON_OBJECT;
            cur++;
            while (*cur != '}') {
                //parse key
                char key[MAX_SIZE];
                sscanf(cur, "\"%[^\"]", key); //extracts the key between two quotes
                cur += strlen(key) + 2; //add 2 to skip the quotes
                trim(key);

                //parse value
                json_object_t *value = parse_json_object(cur);
                cur += strlen(value->value);

                printf("Key: %s,", key);
                printf(" Value: %s\n", value->value);
            }
            object->value[0] = '\0'; //empty as objects don't have values...
            break;
        case '[':
            object->type = JSON_ARRAY;
            cur++;
            while (*cur != ']') {
                json_object_t *value = parse_json_object(cur);
                cur += strlen(value->value);
                printf("Value: %s\n", value->value);
            }
            object->value[0] = '\0';
            break;
        case '\"':
            object->type = JSON_STRING;
            sscanf(cur, "\"%[^\"]", object->value);
            break;
        case '-':
        case '0'...'9':
            object->type = JSON_NUMBER;
            sscanf(cur, "%s", object->value);
            break;
        case 't':
            object->type = JSON_TRUE;
            strcpy(object->value, "true");
            cur += strlen("true");
            break;
        case 'f':
            object->type = JSON_FALSE;
            strcpy(object->value, "false");
            cur += strlen("false");
            break;
        case 'n':
            object->type = JSON_NULL;
            strcpy(object->value, "null");
            cur += strlen("null");
            break;
    }
    return object;
}

int main() {
    char json[] = 
    "{"
        "\"name\": \"John\","
        "\"age\": 30,"
        "\"city\": \"New York\","
        "\"interests\": [\"Reading\",\"Hiking\",\"Coding\"],"
        "\"isStudent\": true,"
        "\"friends\": {"
            "\"name\": \"Adam\","
            "\"age\": 29"
        "}"
    "}";
    json_object_t *object = parse_json_object(json);
    return 0;
}