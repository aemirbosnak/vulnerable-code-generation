//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct inventory {
    char name[50];
    int quantity;
    double cost;
};

void print_inventory(struct inventory inventory[]) {
    int i;
    for (i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        printf("%s - %d @ $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].cost);
    }
}

void add_to_inventory(struct inventory inventory[], char name[], int quantity, double cost) {
    int i;
    for (i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity;
            inventory[i].cost += (quantity * cost);
            break;
        }
    }
}

void remove_from_inventory(struct inventory inventory[], char name[]) {
    int i;
    for (i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity -= 1;
            if (inventory[i].quantity <= 0) {
                strcpy(inventory[i].name, "removed");
            }
            break;
        }
    }
}

int main() {
    struct inventory inventory[10];
    char name[50];
    int quantity;
    double cost;

    printf("Welcome to the C Warehouse Management System!\n");

    while (1) {
        printf("Please enter an option: \n");
        printf("1. Add to Inventory\n");
        printf("2. Remove from Inventory\n");
        printf("3. Print Inventory\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter cost: ");
                scanf("%lf", &cost);
                add_to_inventory(inventory, name, quantity, cost);
                break;
            case 2:
                printf("Enter item name: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                remove_from_inventory(inventory, name);
                break;
            case 3:
                print_inventory(inventory);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}