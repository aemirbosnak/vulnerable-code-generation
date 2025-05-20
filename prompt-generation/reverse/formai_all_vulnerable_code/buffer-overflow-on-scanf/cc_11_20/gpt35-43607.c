//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
};

int main() {
    int choice, i, n;
    char search[50];
    struct Item *warehouse;

    printf("Welcome to the Warehouse Management System\n\n");

    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &n);
    warehouse = (struct Item*) malloc(n * sizeof(struct Item));

    printf("Enter the details of the items in the warehouse:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", warehouse[i].name);
        printf("Quantity: ");
        scanf("%d", &warehouse[i].quantity);
    }

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Print the list of items in the warehouse\n");
        printf("2. Search for an item in the warehouse\n");
        printf("3. Add a new item to the warehouse\n");
        printf("4. Remove an item from the warehouse\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Print the list of items in the warehouse
                printf("\nList of items in the warehouse:\n");
                for (i = 0; i < n; i++) {
                    printf("Item %d:\n", i+1);
                    printf("Name: %s\n", warehouse[i].name);
                    printf("Quantity: %d\n\n", warehouse[i].quantity);
                }
                break;
            case 2: // Search for an item in the warehouse
                printf("\nEnter the name of the item you want to search for: ");
                scanf("%s", search);
                for (i = 0; i < n; i++) {
                    if (strcmp(warehouse[i].name, search) == 0) {
                        printf("\n%s is available in the warehouse.\n", search);
                        printf("Quantity: %d\n", warehouse[i].quantity);
                        break;
                    }
                }
                if (i == n) {
                    printf("\n%s is not available in the warehouse.\n", search);
                }
                break;
            case 3: // Add a new item to the warehouse
                n++;
                warehouse = (struct Item*) realloc(warehouse, n * sizeof(struct Item));
                printf("\nEnter the details of the new item:\n");
                printf("Name: ");
                scanf("%s", warehouse[n-1].name);
                printf("Quantity: ");
                scanf("%d", &warehouse[n-1].quantity);
                printf("\n%s has been added to the warehouse.\n", warehouse[n-1].name);
                break;
            case 4: // Remove an item from the warehouse
                printf("\nEnter the name of the item you want to remove: ");
                scanf("%s", search);
                for (i = 0; i < n; i++) {
                    if (strcmp(warehouse[i].name, search) == 0) {
                        printf("\n%s has been removed from the warehouse.\n", search);
                        for (int j = i; j < n-1; j++) {
                            strcpy(warehouse[j].name, warehouse[j+1].name);
                            warehouse[j].quantity = warehouse[j+1].quantity;
                        }
                        n--;
                        warehouse = (struct Item*) realloc(warehouse, n * sizeof(struct Item));
                        break;
                    }
                }
                if (i == n) {
                    printf("\n%s is not available in the warehouse.\n", search);
                }
                break;
            case 5: // Exit
                printf("\nThank you for using the Warehouse Management System.\n");
                free(warehouse);
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }

    } while (1);

    return 0;
}