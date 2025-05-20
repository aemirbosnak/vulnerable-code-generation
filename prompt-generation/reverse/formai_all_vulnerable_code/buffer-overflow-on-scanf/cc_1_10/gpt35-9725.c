//FormAI DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[20];
    int stock;
    float price;
};

void addProduct(struct Product inventory[], int * count);
void removeProduct(struct Product inventory[], int * count);
void displayInventory(struct Product inventory[], int count);

int main() {
    struct Product inventory[50];
    int count = 0;
    int choice;

    do {
        printf("\nPRODUCT INVENTORY SYSTEM\n\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                removeProduct(inventory, &count);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                printf("Thank you for using the program!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addProduct(struct Product inventory[], int * count) {
    char name[20];
    int stock;
    float price;

    printf("\nEnter name of product: ");
    scanf("%s", name);
    printf("Enter stock of product: ");
    scanf("%d", &stock);
    printf("Enter price of product: ");
    scanf("%f", &price);

    strcpy(inventory[*count].name, name);
    inventory[*count].stock = stock;
    inventory[*count].price = price;

    printf("\nProduct added successfully!\n");

    (*count)++;
}

void removeProduct(struct Product inventory[], int * count) {
    char name[20];

    printf("\nEnter name of product to remove: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*count)--;
            printf("\nProduct removed successfully!\n");
            return;
        }
    }

    printf("\nProduct not found. Try again.\n");
}

void displayInventory(struct Product inventory[], int count) {
    printf("\nPRODUCT INVENTORY\n\n");
    printf("%-20s %-10s %-10s\n", "Name", "Stock", "Price");
    printf("-------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }

    printf("\n");
}