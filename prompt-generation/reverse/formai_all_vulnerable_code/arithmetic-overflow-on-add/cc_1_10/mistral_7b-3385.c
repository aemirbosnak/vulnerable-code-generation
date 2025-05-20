//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIST_SIZE 10

typedef struct BraveNode {
    char name[50];
    int randomNumber;
    struct BraveNode *next;
} BraveNode;

BraveNode *head = NULL;

void generateRandomNumber(BraveNode *node) {
    srand(time(NULL) + node->randomNumber);
    node->randomNumber = rand();
}

void createNode(BraveNode **head_ref, const char *name) {
    BraveNode *newNode = (BraveNode *)malloc(sizeof(BraveNode));

    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }

    strcpy(newNode->name, name);
    newNode->next = *head_ref;
    *head_ref = newNode;
    generateRandomNumber(newNode);
}

void printList(BraveNode *node) {
    while (node != NULL) {
        printf("Name: %s, Random Number: %d\n", node->name, node->randomNumber);
        node = node->next;
    }
}

void deleteNode(BraveNode **head_ref, const char *key) {
    BraveNode *temp = *head_ref, *prev;

    if (temp != NULL && strcmp(temp->name, key) == 0) {
        *head_ref = temp->next;  // Changed head
        free(temp);              // Free old node
        return;
    }

    while (temp != NULL && strcmp(temp->name, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    int choice;
    char name[50];
    char deleteName[50];

    printf("Welcome to BraveList!\n");

    while (1) {
        printf("\n1. Create a new node\n");
        printf("2. Print List\n");
        printf("3. Delete a node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                createNode(&head, name);
                printf("Node created successfully!\n");
                break;

            case 2:
                printf("List:\n");
                printList(head);
                break;

            case 3:
                printf("Enter name to delete: ");
                scanf("%s", deleteName);
                deleteNode(&head, deleteName);
                printf("Node deleted successfully!\n");
                break;

            case 4:
                printf("Exiting BraveList...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}