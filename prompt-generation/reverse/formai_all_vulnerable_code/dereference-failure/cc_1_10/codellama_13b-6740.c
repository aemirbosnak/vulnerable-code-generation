//Code Llama-13B DATASET v1.0 Category: Building a XML Parser ; Style: lively
// Building a XML Parser in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an XML element
typedef struct {
    char* name;
    char* value;
    struct element* child;
} element;

// Function to parse an XML string
element* parse_xml(char* xml) {
    // Initialize the root element
    element* root = (element*)malloc(sizeof(element));
    root->name = NULL;
    root->value = NULL;
    root->child = NULL;

    // Parse the XML string
    char* start = xml;
    while (*start != '\0') {
        // Skip whitespace
        while (*start == ' ' || *start == '\t' || *start == '\n') {
            start++;
        }

        // Check for end of string
        if (*start == '\0') {
            break;
        }

        // Check for element start tag
        if (*start == '<') {
            // Find the element name
            char* name = start + 1;
            while (*name != '\0' && *name != ' ' && *name != '\t' && *name != '\n') {
                name++;
            }

            // Create a new element
            element* elem = (element*)malloc(sizeof(element));
            elem->name = strndup(start + 1, name - start - 1);
            elem->value = NULL;
            elem->child = NULL;

            // Add the element to the root element
            if (root->child == NULL) {
                root->child = elem;
            } else {
                element* last = root->child;
                while (last->child != NULL) {
                    last = last->child;
                }
                last->child = elem;
            }

            // Skip to the element end tag
            char* end = strchr(start, '>');
            if (end == NULL) {
                // Error: missing end tag
                break;
            }
            start = end + 1;
        } else if (*start == '>') {
            // Skip the element end tag
            start++;
        } else if (*start == ' ' || *start == '\t' || *start == '\n') {
            // Skip whitespace
            start++;
        } else {
            // Error: unexpected character
            break;
        }
    }

    // Return the root element
    return root;
}

// Function to print an XML element
void print_xml(element* elem) {
    // Print the element name
    printf("<%s", elem->name);

    // Print the element value
    if (elem->value != NULL) {
        printf(">%s</%s>", elem->value, elem->name);
    } else {
        printf("/>");
    }

    // Print the child elements
    if (elem->child != NULL) {
        printf("\n");
        for (element* child = elem->child; child != NULL; child = child->child) {
            print_xml(child);
        }
    }
}

// Example usage
int main() {
    // Parse an XML string
    char* xml = "<root><child>value</child></root>";
    element* root = parse_xml(xml);

    // Print the root element
    print_xml(root);

    // Free the memory
    free(root);
    return 0;
}