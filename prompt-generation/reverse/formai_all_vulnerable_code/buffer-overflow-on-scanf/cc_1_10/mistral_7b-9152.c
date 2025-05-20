//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Item;

typedef struct Node {
    Item data;
    struct Node* next;
} Node;

Node* head = NULL;

void addItem(char* name, int quantity) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    newNode->data.quantity = quantity;
    newNode->next = head;
    head = newNode;
}

void removeItem(char* name) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displayInventory() {
    Node* current = head;

    printf("\nCurrent Inventory:\n");
    while (current != NULL) {
        printf("%s: %d\n", current->data.name, current->data.quantity);
        current = current->next;
    }
}

int main() {
    char command[10];
    char name[50];
    int quantity;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("Enter command (add/remove/display/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            addItem(name, quantity);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter item name: ");
            scanf("%s", name);
            removeItem(name);
        } else if (strcmp(command, "display") == 0) {
            displayInventory();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}