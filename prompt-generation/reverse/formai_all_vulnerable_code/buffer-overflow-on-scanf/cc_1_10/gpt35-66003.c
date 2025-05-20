//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Function to generate random numbers for products
int generateRandomNumber(int limit) {
    int num = (rand() % limit) + 1;
    return num;
} 

// Function to display menu
void displayMenu() {
    printf("\n");
    printf("Warehouse Management System\n");
    printf("---------------------------\n");
    printf("1. Add product to inventory\n");
    printf("2. Remove product from inventory\n");
    printf("3. Display inventory\n");
    printf("4. Exit program\n");
    printf("\n");
}

// Function to add product to inventory
void addProduct(int *inventory, int size) {
    int productCode = generateRandomNumber(1000);
    inventory[productCode - 1] = generateRandomNumber(50);
    printf("Product with code %d has been added to inventory.\n", productCode);
}

// Function to remove product from inventory
void removeProduct(int *inventory, int size) {
    int productCode;
    printf("Enter the product code: ");
    scanf("%d", &productCode);
    if (inventory[productCode - 1] == 0) {
        printf("Product with code %d is not in inventory.\n", productCode);
        return;
    }
    inventory[productCode - 1] = 0;
    printf("Product with code %d has been removed from inventory.\n", productCode);
}

// Function to display inventory
void displayInventory(int *inventory, int size) {
    printf("----------------------------------\n");
    printf("Product Code\t\tStock\n");
    printf("----------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (inventory[i] != 0) {
            printf("%d\t\t\t%d\n", i + 1, inventory[i]);
        }
    }
    printf("----------------------------------\n");
}

int main() {
    int inventorySize = 1000, choice;
    int *inventory = (int *)malloc(sizeof(int) * inventorySize);
    memset(inventory, 0, sizeof(int) * inventorySize);
    srand(time(0));
    
    printf("Welcome to our Warehouse Management System!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addProduct(inventory, inventorySize); break;
            case 2: removeProduct(inventory, inventorySize); break;
            case 3: displayInventory(inventory, inventorySize); break;
            case 4: break;
            default: printf("Invalid choice. Please try again.\n"); break;
        }
    } while (choice != 4);

    printf("Thank you for using our Warehouse Management System!\n");

    free(inventory);
    return 0;
}