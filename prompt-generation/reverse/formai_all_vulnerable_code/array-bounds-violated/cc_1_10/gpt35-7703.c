//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum buffer size
#define BUFFER_SIZE 1024

// define JSON structure
typedef struct {
    char *key;
    char *value;
} Json;

// define JSON parser function
Json* parseJson(char *jsonString) {
    // allocate memory for JSON object
    Json *json = (Json*) malloc(sizeof(Json));
    json->key = NULL;
    json->value = NULL;

    // loop through each character in JSON string
    int i = 0;
    while (jsonString[i] != '\0') {
        if (jsonString[i] == ':') {
            // set key for JSON object
            json->key = (char*) malloc(sizeof(char) * i);
            strncpy(json->key, jsonString, i);
            json->key[i] = '\0';

            // set value for JSON object
            int j = i+1;
            while (jsonString[j] != ',' && jsonString[j] != '\0') {
                j++;
            }
            json->value = (char*) malloc(sizeof(char) * (j-i));
            strncpy(json->value, jsonString+i+1, j-i-1);
            json->value[j-i-1] = '\0';

            // break out of loop
            break;
        }
        i++;
    }

    // return JSON object
    return json;
}

int main() {
    // get JSON string from user input
    char jsonString[BUFFER_SIZE];
    printf("Enter a JSON string: ");
    fgets(jsonString, BUFFER_SIZE, stdin);

    // remove newline character from end of string
    if (jsonString[strlen(jsonString)-1] == '\n') {
        jsonString[strlen(jsonString)-1] = '\0';
    }

    // parse JSON string
    Json *json = parseJson(jsonString);

    // print JSON object
    printf("Key: %s\nValue: %s\n", json->key, json->value);

    // free memory allocated for JSON object
    free(json->key);
    free(json->value);
    free(json);

    return 0;
}