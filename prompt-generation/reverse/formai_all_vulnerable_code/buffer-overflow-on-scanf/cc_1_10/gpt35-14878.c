//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
/*
    Product Inventory System
    A Cyberpunk Style Program
    By [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

void addProduct(struct Product *inventory, int *count) {
    printf("\n--- ADDING PRODUCT ---\n");

    printf("\nEnter name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter price: ");
    scanf("%f", &inventory[*count].price);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*count].quantity);

    *count += 1;
    printf("\nProduct added successfully!");
}

void removeProduct(struct Product *inventory, int *count) {
    printf("\n--- REMOVING PRODUCT ---\n");

    if (*count > 0) {
        char name[50];
        printf("\nEnter product name: ");
        scanf("%s", name);

        bool found = false;
        for (int i = 0; i < *count; i++) {
            if (strcmp(inventory[i].name, name) == 0) {
                found = true;
                printf("Product removed successfully!\n");
                for (int j = i; j < *count - 1; j++) {
                    inventory[j] = inventory[j+1];
                }
                *count -= 1;
                break;
            }
        }

        if (!found) {
            printf("Product not found!\n");
        }
    } else {
        printf("\nNo products in inventory!\n");
    }
}

void printInventory(struct Product *inventory, int count) {
    printf("\n--- PRODUCT INVENTORY ---\n");

    if (count > 0) {
        printf("%-20s %-10s %-10s\n", "PRODUCT NAME", "PRICE", "QUANTITY");
        for (int i = 0; i < count; i++) {
            printf("%-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    } else {
        printf("\nNo products in inventory!\n");
    }
}

int main() {
    struct Product inventory[100];
    int count = 0;
    int choice;

    printf("\n--- PRODUCT INVENTORY MANAGEMENT SYSTEM ---\n");

    do {
        printf("\n1. Add Product");
        printf("\n2. Remove Product");
        printf("\n3. Print Inventory");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                removeProduct(inventory, &count);
                break;
            case 3:
                printInventory(inventory, count);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}