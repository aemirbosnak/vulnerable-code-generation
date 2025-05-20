//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LEN];
    int stock;
} Item;

Item inventory[MAX_ITEMS];
int numItems = 0;

void addItem(char *name, int quantity) {
    if (numItems >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add item: %s\n", name);
        return;
    }
    strcpy(inventory[numItems].name, name);
    inventory[numItems].stock = quantity;
    numItems++;
}

void displayInventory() {
    printf("Current inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].stock);
    }
}

int main() {
    char command[10];
    char name[MAX_NAME_LEN];
    int quantity;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("Enter command (add|display|quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            addItem(name, quantity);
        } else if (strcmp(command, "display") == 0) {
            displayInventory();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command: %s\n", command);
        }
    }

    return 0;
}