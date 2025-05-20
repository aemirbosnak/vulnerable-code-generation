//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(char data[], int size) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

// Function to search for a pattern in the linked list
Node* searchPattern(Node *head, char pattern[]) {
    Node *current = head;
    char *str = strstr(current->data, pattern);

    while (str == NULL) {
        current = current->next;
        if (current == NULL) {
            return NULL;
        }
        str = strstr(current->data, pattern);
    }

    return current;
}

// Function to print the linked list
void printList(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

// Main function
int main() {
    Node *head = NULL;
    char data[MAX_SIZE];
    int size;

    // Add nodes to the linked list
    while (1) {
        printf("Enter data (or -1 to stop): ");
        scanf("%s", data);
        if (strcmp(data, "-1") == 0) {
            break;
        }
        printf("Enter size: ");
        scanf("%d", &size);
        head = createNode(data, size);
        head->next = NULL;
        if (head == NULL) {
            printf("Memory error\n");
            exit(1);
        }
    }

    // Search for a pattern in the linked list
    char pattern[MAX_SIZE];
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    Node *result = searchPattern(head, pattern);

    // Print the linked list
    printf("\nLinked List:\n");
    printList(head);

    // Print the search result
    if (result!= NULL) {
        printf("\nPattern found in node: %s\n", result->data);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}