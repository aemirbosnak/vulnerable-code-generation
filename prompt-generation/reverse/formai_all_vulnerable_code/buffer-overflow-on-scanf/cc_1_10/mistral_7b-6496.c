//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node *next;
} Node;

Node *head = NULL;

void printMenu() {
    printf("\n==============================\n");
    printf("| Welcome to WMS!             |\n");
    printf("|------------------------------|\n");
    printf("| 1. Add Item                 |\n");
    printf("| 2. Remove Item              |\n");
    printf("| 3. View Inventory           |\n");
    printf("| 4. Quit                     |\n");
    printf("|------------------------------|\n");
    printf("| Enter your choice:          |\n");
    printf("===============================\n");
}

void addItem(Item newItem) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("\nMemory error! Exiting...\n");
        exit(1);
    }

    newNode->data = newItem;
    newNode->next = head;
    head = newNode;

    printf("\nItem added successfully!");
}

void removeItem(char *itemName) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->data.name, itemName) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nItem not found in inventory.\n");
    } else {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        free(current);
        printf("\nItem removed successfully!\n");
    }
}

void viewInventory() {
    Node *current = head;

    printf("\nCurrent inventory:\n");

    while (current != NULL) {
        printf("%s\t- %d\n", current->data.name, current->data.quantity);
        current = current->next;
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char command;
    Item newItem;

    while (1) {
        printMenu();
        scanf(" %c", &command);

        switch(command) {
            case '1':
                printf("Enter item name: ");
                scanf("%s", name);
                name[strlen(name)-1] = '\0'; // remove newline character
                strcpy(newItem.name, name);
                printf("Enter quantity: ");
                scanf("%d", &newItem.quantity);
                addItem(newItem);
                break;
            case '2':
                printf("Enter item name: ");
                scanf("%s", name);
                name[strlen(name)-1] = '\0'; // remove newline character
                removeItem(name);
                break;
            case '3':
                viewInventory();
                break;
            case '4':
                printf("\nThank you for using WMS! Bye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}