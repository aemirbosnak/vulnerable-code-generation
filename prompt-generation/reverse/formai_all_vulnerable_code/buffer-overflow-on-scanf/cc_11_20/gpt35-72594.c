//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int quantity;
    float price;
};

int main() {
    int choice, i, n = 0;
    struct item inventory[50];

    do {
        printf("\nMenu:\n1. Add item\n2. Display inventory\n3. Search item\n4. Update inventory\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter item name: ");
                fflush(stdin);
                fgets(inventory[n].name, 20, stdin);
                printf("Enter quantity: ");
                scanf("%d", &inventory[n].quantity);
                printf("Enter price: ");
                scanf("%f", &inventory[n].price);
                n++;
                break;
            case 2:
                printf("\nInventory:\n");
                for (i = 0; i < n; i++) {
                    printf("%-20s %-10d $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 3:
                printf("\nEnter item name to search: ");
                char search[20];
                fflush(stdin);
                fgets(search, 20, stdin);
                for (i = 0; i < n; i++) {
                    if (strcmp(search, inventory[i].name) == 0) {
                        printf("%-20s %-10d $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;
            case 4:
                printf("\nEnter item name to update: ");
                char update[20];
                fflush(stdin);
                fgets(update, 20, stdin);
                for (i = 0; i < n; i++) {
                    if (strcmp(update, inventory[i].name) == 0) {
                        printf("Enter new quantity for %s: ", inventory[i].name);
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter new price for %s: ", inventory[i].name);
                        scanf("%f", &inventory[i].price);
                    }
                }
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}