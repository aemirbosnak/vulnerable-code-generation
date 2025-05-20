//FormAI DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure to represent a product
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function prototypes
void addProduct(struct Product products[], int *count);
void editProduct(struct Product products[], int count);
void deleteProduct(struct Product products[], int *count);
void displayProducts(struct Product products[], int count);
void searchProduct(struct Product products[], int count);

int main() {
    struct Product products[100];
    int count = 0;
    char choice;

    while (1) {
        // Display menu
        printf("\n===== PRODUCT INVENTORY SYSTEM =====\n");
        printf("1. Add a product\n");
        printf("2. Edit a product\n");
        printf("3. Delete a product\n");
        printf("4. Display all products\n");
        printf("5. Search for a product\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");

        choice = getchar();
        if (!(isdigit(choice))) {
            fflush(stdin);
            printf("\nInvalid choice, please try again.\n");
            continue;
        }
        switch (choice - '0') {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                editProduct(products, count);
                break;
            case 3:
                deleteProduct(products, &count);
                break;
            case 4:
                displayProducts(products, count);
                break;
            case 5:
                searchProduct(products, count);
                break;
            case 6:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
        fflush(stdin);
    }
}

// Function to add a product to the inventory
void addProduct(struct Product products[], int *count) {
    if (*count >= 100) {
        printf("\nInventory is full, cannot add more products.\n");
        return;
    }
    printf("\nEnter product details:\n");
    printf("Name: ");
    fgets(products[*count].name, 50, stdin);
    printf("Quantity: ");
    scanf("%d", &products[*count].quantity);
    printf("Price: ");
    scanf("%f", &products[*count].price);
    (*count)++;
    printf("\nProduct added successfully.\n");
}

// Function to edit a product in the inventory
void editProduct(struct Product products[], int count) {
    if (count == 0) {
        printf("\nInventory is empty, cannot edit a product.\n");
        return;
    }
    printf("\nEnter the name of the product to be edited: ");
    char name[50];
    fgets(name, 50, stdin);
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nEnter new product details:\n");
            printf("Name: ");
            fgets(products[i].name, 50, stdin);
            printf("Quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Price: ");
            scanf("%f", &products[i].price);
            printf("\nProduct edited successfully.\n");
            return;
        }
    }
    printf("\nProduct not found.\n");
}

// Function to delete a product from the inventory
void deleteProduct(struct Product products[], int *count) {
    if (*count == 0) {
        printf("\nInventory is empty, cannot delete a product.\n");
        return;
    }
    printf("\nEnter the name of the product to be deleted: ");
    char name[50];
    fgets(name, 50, stdin);
    for (int i = 0; i < *count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < (*count) - 1; j++) {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("\nProduct deleted successfully.\n");
            return;
        }
    }
    printf("\nProduct not found.\n");
}

// Function to display all products in the inventory
void displayProducts(struct Product products[], int count) {
    if (count == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    printf("\n%-50s | %-10s | %-10s\n", "Name", "Quantity", "Price");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-50s | %-10d | %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to search for a product in the inventory
void searchProduct(struct Product products[], int count) {
    if (count == 0) {
        printf("\nInventory is empty, cannot search for a product.\n");
        return;
    }
    printf("\nEnter the name of the product to be searched: ");
    char name[50];
    fgets(name, 50, stdin);
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\n%-50s | %-10s | %-10s\n", "Name", "Quantity", "Price");
            printf("-------------------------------------------------------------\n");
            printf("%-50s | %-10d | %-10.2f\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("\nProduct not found.\n");
}