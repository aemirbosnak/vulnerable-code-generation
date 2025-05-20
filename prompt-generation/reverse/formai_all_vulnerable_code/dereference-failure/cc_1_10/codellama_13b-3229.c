//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
/*
 * JSON Parser
 *
 * A program to parse a JSON string and store the values in a data structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

/*
 * Structure to store the JSON object
 */
typedef struct {
    char* key;
    char* value;
    struct json_object* next;
} json_object;

/*
 * Structure to store the JSON array
 */
typedef struct {
    json_object* data;
    struct json_array* next;
} json_array;

/*
 * Function to parse the JSON string
 */
void parse_json(char* json_string) {
    // Initialize the JSON object and array
    json_object* json_obj = NULL;
    json_array* json_arr = NULL;

    // Initialize the buffer to store the key and value
    char key_buffer[MAX_BUFFER_SIZE];
    char value_buffer[MAX_BUFFER_SIZE];

    // Initialize the flag to indicate whether the current character is a quote or not
    bool in_quote = false;

    // Loop through the JSON string
    for (int i = 0; json_string[i] != '\0'; i++) {
        // Check if the current character is a quote
        if (json_string[i] == '"') {
            // Toggle the in_quote flag
            in_quote = !in_quote;
        } else if (!in_quote) {
            // If the current character is not a quote, check if it is a colon
            if (json_string[i] == ':') {
                // If the current character is a colon, store the key in the key buffer
                strcpy(key_buffer, json_string + i + 1);
            } else if (json_string[i] == ',') {
                // If the current character is a comma, store the value in the value buffer
                strcpy(value_buffer, json_string + i + 1);

                // Create a new JSON object and add it to the JSON object list
                json_object* new_obj = (json_object*) malloc(sizeof(json_object));
                new_obj->key = key_buffer;
                new_obj->value = value_buffer;
                new_obj->next = json_obj;
                json_obj = new_obj;
            }
        }
    }

    // Print the JSON object list
    json_object* obj = json_obj;
    while (obj != NULL) {
        printf("%s: %s\n", obj->key, obj->value);
        obj = obj->next;
    }
}

int main() {
    char json_string[] = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    parse_json(json_string);
    return 0;
}