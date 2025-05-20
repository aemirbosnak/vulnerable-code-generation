//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: creative
/*
 * JSON Parser
 *
 * A creative JSON parser example program in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *key;
    char *value;
} JSONObject;

JSONObject* parse_json(char *json_string) {
    JSONObject *json_obj = malloc(sizeof(JSONObject));
    json_obj->key = malloc(BUFFER_SIZE);
    json_obj->value = malloc(BUFFER_SIZE);

    char *token = strtok(json_string, "{");
    if (token == NULL) {
        return NULL;
    }

    strcpy(json_obj->key, token);

    token = strtok(NULL, ":");
    if (token == NULL) {
        return NULL;
    }

    strcpy(json_obj->value, token);

    return json_obj;
}

int main() {
    char *json_string = "{\"name\":\"John Doe\",\"age\":35}";
    JSONObject *json_obj = parse_json(json_string);

    printf("Key: %s\n", json_obj->key);
    printf("Value: %s\n", json_obj->value);

    free(json_obj->key);
    free(json_obj->value);
    free(json_obj);

    return 0;
}