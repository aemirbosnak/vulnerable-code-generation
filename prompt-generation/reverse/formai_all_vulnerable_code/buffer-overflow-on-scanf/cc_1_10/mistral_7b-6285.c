//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct Node {
    char data[MAX_LEN];
    struct Node *next;
} Node;

Node *head = NULL;

void displayMenu() {
    printf("\nLinked List Operations Menu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");
}

void insert(char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = head;
    head = newNode;
    printf("Inserted %s successfully.\n", str);
}

void delete(char *str) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data, str) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%s deleted successfully.\n", str);
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: %s not found in the list.\n", str);
    }
}

void traverse() {
    Node *current = head;
    printf("\nList elements:\n");

    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    char str[MAX_LEN];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string to insert: ");
                scanf("%s", str);
                insert(str);
                break;
            case 2:
                printf("Enter the string to delete: ");
                scanf("%s", str);
                delete(str);
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}