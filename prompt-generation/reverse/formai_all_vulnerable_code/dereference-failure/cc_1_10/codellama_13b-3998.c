//Code Llama-13B DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Node {
    char *tag;
    char *value;
    struct Node *next;
} Node;

Node *create_node(char *tag, char *value) {
    Node *node = malloc(sizeof(Node));
    node->tag = tag;
    node->value = value;
    node->next = NULL;
    return node;
}

void add_node(Node *head, Node *node) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

Node *parse_xml(char *buffer) {
    Node *head = NULL;
    Node *node = NULL;
    char *tag = NULL;
    char *value = NULL;
    char *end = NULL;

    while (buffer != NULL) {
        // Find the next '<' character
        buffer = strchr(buffer, '<');
        if (buffer == NULL) {
            break;
        }

        // Find the end of the tag
        end = strchr(buffer, '>');
        if (end == NULL) {
            break;
        }

        // Extract the tag and value
        tag = buffer + 1;
        value = end + 1;
        *end = '\0';

        // Create a new node
        node = create_node(tag, value);

        // Add the node to the list
        if (head == NULL) {
            head = node;
        } else {
            add_node(head, node);
        }

        // Move to the next node
        buffer = end + 1;
    }

    return head;
}

int main() {
    char *xml = "<root><node1>value1</node1><node2>value2</node2></root>";
    Node *head = parse_xml(xml);
    Node *node = head;
    while (node != NULL) {
        printf("%s: %s\n", node->tag, node->value);
        node = node->next;
    }
    return 0;
}