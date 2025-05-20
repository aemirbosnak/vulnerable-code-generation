//Code Llama-13B DATASET v1.0 Category: Building a XML Parser ; Style: invasive
// Build an XML parser in an invasive style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an XML node
typedef struct node {
    char* name;
    char* value;
    struct node* next;
    struct node* prev;
} node_t;

// Function to create a new XML node
node_t* create_node(char* name, char* value) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to add a child node to a parent node
void add_child(node_t* parent, node_t* child) {
    if (parent->next == NULL) {
        parent->next = child;
    } else {
        node_t* current = parent->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

// Function to print an XML node
void print_node(node_t* node) {
    printf("<%s>%s</%s>\n", node->name, node->value, node->name);
}

// Function to print an XML document
void print_document(node_t* root) {
    print_node(root);
    node_t* current = root->next;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

int main() {
    // Create an XML document
    node_t* root = create_node("root", "");
    node_t* child1 = create_node("child1", "value1");
    node_t* child2 = create_node("child2", "value2");
    node_t* child3 = create_node("child3", "value3");

    // Add child nodes to the root node
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);

    // Print the XML document
    print_document(root);

    // Free the memory allocated for the XML document
    free(root);
    free(child1);
    free(child2);
    free(child3);

    return 0;
}