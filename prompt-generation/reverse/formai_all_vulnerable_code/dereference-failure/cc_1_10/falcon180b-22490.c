//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1000000 // Maximum size of JSON string

// Structure to store JSON data
typedef struct json_data {
    char *key;
    char *value;
} json_data;

// Function to parse JSON string
void parse_json(char *json_string, json_data *data) {
    int i = 0;
    int key_start = 0;
    int value_start = 0;
    int in_quotes = 0;
    int in_escape = 0;
    char *key = (char *)malloc(MAX_JSON_SIZE);
    char *value = (char *)malloc(MAX_JSON_SIZE);

    // Initialize key and value strings
    key[0] = '\0';
    value[0] = '\0';

    // Loop through JSON string
    while (json_string[i]) {
        // Check for start of key
        if (json_string[i] == '\"' &&!in_quotes) {
            key_start = i + 1;
            in_quotes = 1;
        }
        // Check for end of key
        else if (json_string[i] == '\"' && in_quotes) {
            in_quotes = 0;
            json_string[i] = '\0';
            data->key = strdup(key_start);
            key_start = i + 1;
        }
        // Check for start of value
        else if (json_string[i] == ':' &&!in_quotes) {
            value_start = i + 1;
            in_quotes = 1;
        }
        // Check for end of value
        else if (json_string[i] == ',' || json_string[i] == '}' && in_quotes) {
            in_quotes = 0;
            json_string[i] = '\0';
            data->value = strdup(value_start);
            value_start = i + 1;
        }
        // Check for escape characters
        else if (json_string[i] == '\\' && in_quotes) {
            in_escape = 1;
        }
        // Copy key and value strings
        else if (in_quotes &&!in_escape) {
            if (i - key_start < MAX_JSON_SIZE - 1) {
                key[i - key_start] = json_string[i];
            }
            if (i - value_start < MAX_JSON_SIZE - 1) {
                value[i - value_start] = json_string[i];
            }
        }
        // Increment i
        i++;
    }

    // Free memory
    free(key);
    free(value);
}

// Function to print JSON data
void print_json_data(json_data *data) {
    printf("Key: %s\nValue: %s\n", data->key, data->value);
}

// Main function
int main() {
    char json_string[MAX_JSON_SIZE];
    json_data data;

    // Read JSON string from user
    printf("Enter JSON string: ");
    fgets(json_string, MAX_JSON_SIZE, stdin);

    // Parse JSON string
    parse_json(json_string, &data);

    // Print JSON data
    print_json_data(&data);

    return 0;
}