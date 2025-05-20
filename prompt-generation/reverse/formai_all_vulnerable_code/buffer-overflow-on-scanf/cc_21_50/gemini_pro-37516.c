//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Item;

int main() {
    Item inventory[100];
    int numItems = 0;

    // Load inventory from file
    FILE *file = fopen("inventory.txt", "r");
    if (file != NULL) {
        while (!feof(file)) {
            fscanf(file, "%s %d", inventory[numItems].name, &inventory[numItems].quantity);
            numItems++;
        }
        fclose(file);
    }

    // Display inventory
    printf("Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }

    // Process transactions
    char command[50];
    while (strcmp(command, "quit") != 0) {
        printf("\nEnter command (add, remove, sell, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[50];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            // Find item in inventory
            int index = -1;
            for (int i = 0; i < numItems; i++) {
                if (strcmp(inventory[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }

            // If item is not in inventory, add it
            if (index == -1) {
                strcpy(inventory[numItems].name, name);
                inventory[numItems].quantity = quantity;
                numItems++;
            }
            // Otherwise, just increase the quantity
            else {
                inventory[index].quantity += quantity;
            }
        }
        else if (strcmp(command, "remove") == 0) {
            char name[50];
            printf("Enter item name: ");
            scanf("%s", name);

            // Find item in inventory
            int index = -1;
            for (int i = 0; i < numItems; i++) {
                if (strcmp(inventory[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }

            // If item is not in inventory, do nothing
            if (index == -1) {
                printf("Item not found in inventory.\n");
            }
            // Otherwise, remove it
            else {
                for (int i = index; i < numItems - 1; i++) {
                    strcpy(inventory[i].name, inventory[i + 1].name);
                    inventory[i].quantity = inventory[i + 1].quantity;
                }
                numItems--;
            }
        }
        else if (strcmp(command, "sell") == 0) {
            char name[50];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            // Find item in inventory
            int index = -1;
            for (int i = 0; i < numItems; i++) {
                if (strcmp(inventory[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }

            // If item is not in inventory, do nothing
            if (index == -1) {
                printf("Item not found in inventory.\n");
            }
            // Otherwise, sell it
            else {
                if (inventory[index].quantity < quantity) {
                    printf("Insufficient quantity in stock.\n");
                }
                else {
                    inventory[index].quantity -= quantity;
                    printf("Item sold.\n");
                }
            }
        }
    }

    // Save inventory to file
    file = fopen("inventory.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numItems; i++) {
            fprintf(file, "%s %d\n", inventory[i].name, inventory[i].quantity);
        }
        fclose(file);
    }

    return 0;
}