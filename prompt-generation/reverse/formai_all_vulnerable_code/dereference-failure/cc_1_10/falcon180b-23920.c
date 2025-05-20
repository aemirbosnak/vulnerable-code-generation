//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the structure for a node
typedef struct {
    char data[MAX_SIZE];
    struct node *next;
} Node;

// Define the structure for the linked list
typedef struct {
    Node *head;
    int size;
} LinkedList;

// Function to create a new node
Node* createNode(char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

// Function to add a node to the end of the linked list
void addNode(LinkedList *list, char *data) {
    Node *node = createNode(data);
    if (!node) {
        return;
    }
    if (!list->head) {
        list->head = node;
    } else {
        Node *temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->size++;
}

// Function to search for a node in the linked list
Node* searchNode(LinkedList *list, char *data) {
    Node *temp = list->head;
    while (temp) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(LinkedList *list) {
    Node *temp = list->head;
    while (temp) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    // Add nodes to the linked list
    addNode(&list, "apple");
    addNode(&list, "banana");
    addNode(&list, "cherry");
    addNode(&list, "date");
    addNode(&list, "elderberry");

    // Print the linked list
    printf("Linked list:\n");
    printList(&list);

    // Search for a node in the linked list
    Node *result = searchNode(&list, "cherry");
    if (result) {
        printf("Found node: %s\n", result->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}