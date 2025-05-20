//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NAME_LENGTH 50

typedef struct CyberPunkNode {
    char name[NAME_LENGTH];
    int cyborgLevel;
    struct CyberPunkNode *next;
} CyberPunkNode;

// Function prototypes
CyberPunkNode* createNode(const char *name, int level);
void insertAtEnd(CyberPunkNode **head, const char *name, int level);
void displayList(CyberPunkNode *head);
void deleteNode(CyberPunkNode **head, const char *name);
void freeList(CyberPunkNode *head);

int main() {
    CyberPunkNode *head = NULL;
    char name[NAME_LENGTH];
    int level, choice;

    printf("Welcome to the CyberPunk Linked List Manager!\n");
    while (1) {
        printf("\n=== Cybernetic Operations ===\n");
        printf("1. Add CyberPunk\n");
        printf("2. Display CyberPunks\n");
        printf("3. Remove CyberPunk\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Name of CyberPunk: ");
                scanf("%s", name);
                printf("Cyborg Level (1-10): ");
                scanf("%d", &level);
                insertAtEnd(&head, name, level);
                printf("CyberPunk %s with level %d inserted into the matrix.\n", name, level);
                break;
            case 2:
                printf("\n=== Current CyberPunks in the Matrix ===\n");
                displayList(head);
                break;
            case 3:
                printf("Name of CyberPunk to remove: ");
                scanf("%s", name);
                deleteNode(&head, name);
                break;
            case 4:
                freeList(head);
                printf("Exiting... Stay cybernetic!\n");
                exit(0);
            default:
                printf("Invalid option. Select again.\n");
        }
    }
    return 0;
}

// Create a new CyberPunkNode
CyberPunkNode* createNode(const char *name, int level) {
    CyberPunkNode *newNode = (CyberPunkNode *)malloc(sizeof(CyberPunkNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->name, name, NAME_LENGTH);
    newNode->cyborgLevel = level;
    newNode->next = NULL;
    return newNode;
}

// Insert a new CyberPunkNode at the end of the list
void insertAtEnd(CyberPunkNode **head, const char *name, int level) {
    CyberPunkNode *newNode = createNode(name, level);
    if (*head == NULL) {
        *head = newNode;
    } else {
        CyberPunkNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Display all CyberPunks in the list
void displayList(CyberPunkNode *head) {
    if (head == NULL) {
        printf("No CyberPunks in the matrix.\n");
        return;
    }
    CyberPunkNode *current = head;
    while (current != NULL) {
        printf("CyberPunk: %s, Cyborg Level: %d\n", current->name, current->cyborgLevel);
        current = current->next;
    }
}

// Delete a CyberPunkNode from the list
void deleteNode(CyberPunkNode **head, const char *name) {
    if (*head == NULL) {
        printf("The matrix has empty data. Can't delete anything.\n");
        return;
    }

    CyberPunkNode *current = *head;
    CyberPunkNode *previous = NULL;

    while (current != NULL && strncmp(current->name, name, NAME_LENGTH) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("CyberPunk %s not found.\n", name);
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Removing head
    } else {
        previous->next = current->next; // Bypass the current node
    }
    free(current);
    printf("CyberPunk %s deleted from the matrix.\n", name);
}

// Free the entire list
void freeList(CyberPunkNode *head) {
    CyberPunkNode *current = head;
    CyberPunkNode *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}