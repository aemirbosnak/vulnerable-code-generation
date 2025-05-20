//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        printf("%s\n", tmp->email);
        tmp = tmp->next;
    }
}

void addToList(Node** headRef, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("ERROR: Failed to allocate memory for new node!\n");
        return;
    }
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (*headRef == NULL) {
        // First node in list
        *headRef = newNode;
    }
    else {
        // Add to end of list
        Node* tmp = *headRef;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }

    printf("%s added to list!\n", email);
}

void removeFromList(Node** headRef, char* email) {
    Node* tmp = *headRef;
    Node* prev = NULL;

    while (tmp != NULL) {
        if (strcmp(tmp->email, email) == 0) {
            if (prev == NULL) {
                // Remove first node
                *headRef = tmp->next;
            }
            else {
                prev->next = tmp->next;
            }
            free(tmp);
            printf("%s removed from list!\n", email);
            return;
        }

        prev = tmp;
        tmp = tmp->next;
    }

    printf("%s not found in list!\n", email);
}

int main() {
    Node* head = NULL;
    int choice;
    char email[50];

    while (1) {
        printf("\n1. Add Email to List\n");
        printf("2. Remove Email from List\n");
        printf("3. View List\n");
        printf("4. Quit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter email to add: ");
            scanf("%s", email);
            addToList(&head, email);
            break;
        case 2:
            printf("\nEnter email to remove: ");
            scanf("%s", email);
            removeFromList(&head, email);
            break;
        case 3:
            printf("\nMailing list:\n");
            printList(head);
            break;
        case 4:
            printf("\nExiting program...\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}