//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct node {
    char *key;
    struct node *next;
};

// Function prototypes
void addNode(struct node** head, char* key);
void printList(struct node* head);
void freeList(struct node* head);

// Main function
int main() {
    FILE* fp;
    char line[1000];
    char* token;
    struct node* head = NULL;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read each line and parse resume data
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            addNode(&head, token);
            token = strtok(NULL, ",");
        }
    }

    // Print parsed data
    printf("Parsed data:\n");
    printList(head);

    // Free memory
    freeList(head);

    return 0;
}

// Function to add node to linked list
void addNode(struct node** head, char* key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Error: could not allocate memory for new node.\n");
        exit(1);
    }
    newNode->key = strdup(key);
    newNode->next = *head;
    *head = newNode;
}

// Function to print linked list
void printList(struct node* head) {
    while (head!= NULL) {
        printf("%s -> ", head->key);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free memory used by linked list
void freeList(struct node* head) {
    while (head!= NULL) {
        free(head->key);
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
}