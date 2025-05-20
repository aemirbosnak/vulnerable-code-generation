//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializes a linked list node for storing XML tags and their values
struct xml_node {
    char tag[50];
    char value[100];
    struct xml_node *next;
};

// Function for parsing XML file and creating linked list of tag-value pairs
void parse_xml_file(char *filename, struct xml_node **head) {

    // Open the XML file
    FILE *file = fopen(filename, "r");

    // Make sure the file opened successfully
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Initialize buffer for reading lines from file
    char line[100];

    // Initialize variables for tracking state of XML parsing
    int in_tag = 0;
    char current_tag[50];
    char current_value[100];
    int value_started = 0;
    int value_ended = 0;

    // Loop through lines of XML file
    while (fgets(line, 100, file)) {

        // Loop through characters in line
        for (int i = 0; i < strlen(line); i++) {
            char c = line[i];

            // If we are currently in a tag and the current character is not a closing tag symbol
            if (in_tag && c != '>') {
                strncat(current_tag, &c, 1); // Append the character to the current tag
            }

            // If we are currently in a tag and the current character is a closing tag symbol
            else if (in_tag && c == '>') {
                in_tag = 0; // We are no longer in a tag
                current_tag[strlen(current_tag) - 1] = '\0'; // Remove the closing tag symbol from the end of the tag name
            }

            // If we are not in a tag and the current character is an opening tag symbol
            else if (!in_tag && c == '<') {
                in_tag = 1; // We are now in a tag
                memset(current_tag, 0, sizeof(current_tag)); // Clear the current tag string
                memset(current_value, 0, sizeof(current_value)); // Clear the current value string
                value_started = 0; // Reset value state variables
                value_ended = 0;
            }

            // If we are not in a tag and the current character is not an opening tag symbol
            else if (!in_tag && c != '<') {
                if (!value_started) { // If we have not yet started reading the value
                    value_started = 1; // Start reading the value
                }
                strncat(current_value, &c, 1); // Append the character to the current value
            }

        }

        // If we have finished reading a tag-value pair
        if (!in_tag && value_started && !value_ended) {
            struct xml_node *new_node = malloc(sizeof(struct xml_node)); // Allocate memory for new linked list node
            strcpy(new_node->tag, current_tag); // Set the node's tag and value values
            strcpy(new_node->value, current_value);
            new_node->next = *head; // Insert the node at the beginning of the linked list
            *head = new_node;

            memset(current_tag, 0, sizeof(current_tag)); // Clear the current tag and value strings
            memset(current_value, 0, sizeof(current_value));
            value_started = 0; // Reset value state variables
            value_ended = 0;
        }
    }

    fclose(file); // Close the file
}

// Main function
int main() {

    // Initialize linked list head node
    struct xml_node *head = NULL;

    // Parse the XML file and create linked list
    parse_xml_file("example.xml", &head);

    // Display the linked list
    printf("Parsed XML:\n");
    struct xml_node *current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->tag, current->value);
        current = current->next;
    }

    return 0;
}