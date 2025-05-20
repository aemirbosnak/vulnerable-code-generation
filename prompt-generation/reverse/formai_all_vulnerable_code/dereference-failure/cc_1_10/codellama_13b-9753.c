//Code Llama-13B DATASET v1.0 Category: Building a JSON Parser ; Style: protected
// Building a JSON Parser example program in a protected style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the parsed JSON data
struct json_data {
    char *key;
    char *value;
    struct json_data *next;
};

// Function to parse a JSON string
struct json_data *parse_json(char *json_string) {
    struct json_data *head = NULL;
    struct json_data *curr = NULL;
    char *token = strtok(json_string, "\"");

    while (token != NULL) {
        if (strcmp(token, "\"") == 0) {
            // Ignore quotes
            token = strtok(NULL, "\"");
            continue;
        }

        if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0) {
            // Ignore braces
            token = strtok(NULL, "{}");
            continue;
        }

        if (strcmp(token, ",") == 0) {
            // Ignore commas
            token = strtok(NULL, ",");
            continue;
        }

        if (strcmp(token, ":") == 0) {
            // Ignore colons
            token = strtok(NULL, ":");
            continue;
        }

        if (strcmp(token, "null") == 0) {
            // Ignore null values
            token = strtok(NULL, "null");
            continue;
        }

        // Add the token to the linked list
        struct json_data *new_data = malloc(sizeof(struct json_data));
        new_data->key = token;
        new_data->value = strtok(NULL, "\"");
        new_data->next = NULL;

        if (head == NULL) {
            head = new_data;
        } else {
            curr->next = new_data;
        }

        curr = new_data;

        token = strtok(NULL, "\"");
    }

    return head;
}

int main() {
    char *json_string = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    struct json_data *head = parse_json(json_string);

    // Print the parsed data
    struct json_data *curr = head;
    while (curr != NULL) {
        printf("Key: %s\nValue: %s\n", curr->key, curr->value);
        curr = curr->next;
    }

    return 0;
}