//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

// Function prototypes
void createLinkedList(Node** head, char* str);
int search(Node* head, char* key);
void printList(Node* node);

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Create linked list from string
    Node* head = NULL;
    createLinkedList(&head, str);

    // Search for key in linked list
    char key[MAX_SIZE];
    printf("Enter a key to search for: ");
    scanf("%[^\n]", key);
    int result = search(head, key);

    // Print linked list
    printf("\nLinked List:\n");
    printList(head);

    // Print search result
    if (result == 1) {
        printf("\nKey found in linked list.\n");
    } else {
        printf("\nKey not found in linked list.\n");
    }

    return 0;
}

// Function to create linked list from string
void createLinkedList(Node** head, char* str) {
    *head = NULL;
    int len = strlen(str);
    int i = 0;

    // Create nodes for each character in string
    while (i < len) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory error.\n");
            exit(1);
        }
        strncpy(newNode->data, str + i, MAX_SIZE);
        newNode->next = NULL;

        // Add node to linked list
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        i += MAX_SIZE;
    }
}

// Function to search for key in linked list
int search(Node* head, char* key) {
    Node* currNode = head;
    int len = strlen(key);

    // Traverse linked list
    while (currNode!= NULL) {
        if (strncmp(currNode->data, key, len) == 0) {
            return 1;
        }
        currNode = currNode->next;
    }

    return 0;
}

// Function to print linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}