//FormAI DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures
struct product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct product inv[], int* numProducts);
void removeProduct(struct product inv[], int* numProducts);
void displayInventory(struct product inv[], int numProducts);

int main() {
    struct product inventory[100];
    int numProducts = 0;
    int choice;

    do {
        // menu
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // add product
                addProduct(inventory, &numProducts);
                break;
            case 2: // remove product
                removeProduct(inventory, &numProducts);
                break;
            case 3: // display inventory
                displayInventory(inventory, numProducts);
                break;
            case 4: // exit program
                printf("Thank you for using Product Inventory System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// addProduct function
void addProduct(struct product inv[], int* numProducts) {
    char name[50];
    int quantity;
    float price;

    printf("\nEnter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%f", &price);

    strcpy(inv[*numProducts].name, name);
    inv[*numProducts].quantity = quantity;
    inv[*numProducts].price = price;

    (*numProducts)++;
    printf("Product added successfully!\n");
}

// removeProduct function
void removeProduct(struct product inv[], int* numProducts) {
    char name[50];
    int i, j;

    printf("\nEnter product name to remove: ");
    scanf("%s", name);

    // check if product exists
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(inv[i].name, name) == 0) {
            // shift the remaining products one position left
            for (j = i; j < *numProducts - 1; j++) {
                strcpy(inv[j].name, inv[j + 1].name);
                inv[j].quantity = inv[j + 1].quantity;
                inv[j].price = inv[j + 1].price;
            }

            (*numProducts)--;
            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

// displayInventory function
void displayInventory(struct product inv[], int numProducts) {
    int i;

    printf("\nProduct Inventory\n");
    printf("%-50s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < numProducts; i++) {
        printf("%-50s %-10d %-10.2f\n", inv[i].name, inv[i].quantity, inv[i].price);
    }

    printf("Total number of products: %d\n", numProducts);
}