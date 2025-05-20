//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// JSON data structure
typedef struct {
    char *key;
    char *value;
    struct json_data *next;
} json_data;

// Function to create a new JSON data node
json_data *create_node(char *key, char *value) {
    json_data *new_node = (json_data *)malloc(sizeof(json_data));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;
    return new_node;
}

// Function to parse a JSON string and build a data structure
json_data *parse_json(char *json_string) {
    char *token;
    char *key = NULL;
    char *value = NULL;
    json_data *root = NULL;
    json_data *current = NULL;

    // Initialize the root node
    root = create_node("", "");

    // Loop through the JSON string
    token = strtok(json_string, "{");
    while (token!= NULL) {
        // Check if the token is a key-value pair
        if (strlen(token) > 1) {
            key = strtok(token, ":");
            value = strtok(NULL, ",");

            // Create a new JSON data node
            current = create_node(key, value);

            // Add the new node to the root node
            if (root->next == NULL) {
                root->next = current;
            } else {
                json_data *temp = root->next;
                while (temp->next!= NULL) {
                    temp = temp->next;
                }
                temp->next = current;
            }
        }

        // Move to the next token
        token = strtok(NULL, ",");
    }

    return root;
}

// Function to print the JSON data structure
void print_json(json_data *node) {
    while (node!= NULL) {
        printf("{\"%s\": \"%s\"}\n", node->key, node->value);
        node = node->next;
    }
}

int main() {
    char *json_string = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    json_data *root = parse_json(json_string);
    print_json(root);

    return 0;
}