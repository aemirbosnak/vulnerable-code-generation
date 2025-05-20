//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1000   // Maximum length of JSON string

int validateJSON(char *jsonString);
int parseJSONObject(char *jsonString, int size);
int parseJSONArray(char *jsonString, int size);

int main() {
    char jsonString[MAX_JSON_LENGTH];

    // Read JSON input from user
    printf("Enter JSON string:\n");
    fgets(jsonString, MAX_JSON_LENGTH, stdin);
    jsonString[strlen(jsonString) - 1] = '\0';   // Remove the newline character from end

    // Validate JSON syntax and parse the JSON
    if (validateJSON(jsonString)) {
        printf("Valid JSON!\n\n");
        printf("Parsed JSON:\n");
        parseJSONObject(jsonString, strlen(jsonString));
    } else {
        printf("Invalid JSON :(\n");
    }
    return 0;
}

// Validate JSON string for correct syntax
int validateJSON(char *jsonString) {
    int i, nested_count = 0;
    char current, prev = '\0';

    if (*jsonString == '[') {
        return parseJSONArray(jsonString, strlen(jsonString));
    } else if (*jsonString == '{') {
        for (i = 0; jsonString[i] != '\0'; i++) {
            current = jsonString[i];
            if (current == '{') {
                nested_count++;
            } else if (current == '}') {
                nested_count--;
            }
            if ((prev == '{' && current == '}') || (prev == '}' && current == '{') || nested_count < 0) {
                return 0;
            }
            prev = current;
        }
        return 1;
    } else {
        return 0;
    }
}

// Parse JSON object and print the key-value pairs
int parseJSONObject(char *jsonString, int size) {
    char *key, *value, *value_start;
    int finished = 0;
    while (*jsonString != '\0' && !finished) {
        jsonString = strstr(jsonString, "\"");
        if (jsonString != NULL) {
            jsonString += 1;   // Move to the next character after the double quote
            key = jsonString;
            jsonString = strstr(jsonString, "\"");
            *jsonString = '\0';   // Replace ending double quote with null character
            value_start = strstr(jsonString + 1, "\"");
            if (value_start != NULL) {
                value_start += 1;
                value = value_start;
                jsonString = strstr(value_start, "\"");
                *jsonString = '\0';   // Replace ending double quote with null character
                printf("%s: %s\n", key, value);
                if (*(jsonString + 1) == ',') {
                    jsonString += 2;
                } else {
                    finished = 1;
                }
            } else {
                printf("Error: Invalid JSON value.\n");
                finished = 1;
            }
        }
    }
    return 0;
}

// Parse JSON array and print all the elements
int parseJSONArray(char *jsonString, int size) {
    int i, value_start;
    printf("Parsed JSON:\n");

    // Remove the enclosing square brackets
    jsonString[size - 1] = '\0';
    jsonString += 1;
    size -= 2;

    for (i = 0; i < size; i++) {
        if (jsonString[i] == '\"') {
            // Ignore the JSON string values if present
            i++;
            while (jsonString[i] != '\"' && i < size) {
                i += 1;
            }
        } else if (jsonString[i] == '{') {
            // Parse the JSON object
            parseJSONObject(jsonString + i, size - i);
            break;
        } else if (jsonString[i] == ',') {
            // Move to the next array element
        } else {
            // Parse the JSON number value
            value_start = i;
            while (jsonString[i] != ',' && jsonString[i] != ']' && i < size) {
                i += 1;
            }
            printf("%.*s\n", i - value_start, jsonString + value_start);
            i -= 1;
        }
    }
    return 0;
}