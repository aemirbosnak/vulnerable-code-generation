//FormAI DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50
#define MIN_ENTRY 3

typedef struct Node {
    char email[MAX_SIZE];
    struct Node* next;
} Node;

int count = 0;
Node* head = NULL;

void addEmail(char email[]) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed while creating new node.\n");
        return;
    }
    strncpy(newNode->email, email, MAX_SIZE);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    count++;
    printf("\nEmail %s added to the mailing list.\n", email);
}

void removeEmail(char email[]) {
    Node* currentNode = head;
    Node* prevNode = NULL;
    while (currentNode != NULL) {
        if (strncmp(currentNode->email, email, MAX_SIZE) == 0) {
            if (prevNode == NULL) {
                head = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            printf("\nEmail %s removed from the mailing list.\n", email);
            count--;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("\nEmail %s not found in the mailing list.\n", email);
}

void displayList() {
    if (head == NULL) {
        printf("\nMailing list is empty.\n");
        return;
    }
    printf("\nMailing List:\n");
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%s\n", currentNode->email);
        currentNode = currentNode->next;
    }
}

int main() {
    int choice;
    char email[MAX_SIZE];
    printf("********* Mailing List Manager *********\n");
    do {
        printf("\nEnter your choice:\n1. Add email\n2. Remove email\n3. Display mailing list\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("\nEnter email address to add: ");
                scanf("%s", email);
                addEmail(email);
                break;
            }
            case 2: {
                if (count < MIN_ENTRY) {
                    printf("\nCannot remove email. Mailing list must have at least %d email(s).\n", MIN_ENTRY);
                    break;
                }
                printf("\nEnter email address to remove: ");
                scanf("%s", email);
                removeEmail(email);
                break;
            }
            case 3: {
                displayList();
                break;
            }
            case 4: {
                printf("\nExiting Mailing List Manager...\n");
                break;
            }
            default: {
                printf("\nInvalid choice entered.\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}