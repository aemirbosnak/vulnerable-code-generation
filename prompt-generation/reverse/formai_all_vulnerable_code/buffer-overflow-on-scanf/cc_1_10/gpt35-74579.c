//FormAI DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product *inventory, int *numProducts);
void showInventory(Product inventory[], int numProducts);
int searchProduct(Product inventory[], int numProducts, int id);
void updateProduct(Product inventory[], int numProducts);
void deleteProduct(Product inventory[], int *numProducts);

int main() {
    int numProducts = 0;
    Product inventory[100];

    int choice;

    do {
        printf("\n------------------------ MENU -----------------------\n");
        printf("1. Add new product\n");
        printf("2. Show inventory\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("0. Exit\n");
        printf("------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                showInventory(inventory, numProducts);
                break;
            case 3:
                updateProduct(inventory, numProducts);
                break;
            case 4:
                deleteProduct(inventory, &numProducts);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 0);

    return 0;
}

void addProduct(Product *inventory, int *numProducts) {
    printf("\n----------------------------- ADD NEW PRODUCT -----------------------------\n");

    printf("Enter product ID: ");
    scanf("%d", &inventory[*numProducts].id);

    printf("Enter product name: ");
    scanf("%s", inventory[*numProducts].name);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[*numProducts].quantity);

    printf("Enter product price: ");
    scanf("%f", &inventory[*numProducts].price);

    (*numProducts)++;
}

void showInventory(Product inventory[], int numProducts) {
    if(numProducts == 0) {
        printf("\nInventory is empty!\n");
    } else {
        printf("\n----------------------------- INVENTORY -----------------------------\n");
        printf("ID\tNAME\t\tQUANTITY\tPRICE\n");
        
        for(int i = 0; i < numProducts; i++) {
            printf("%d\t%-15s\t%d\t\t$%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int searchProduct(Product inventory[], int numProducts, int id) {
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == id) {
            return i;
        }
    }

    return -1;
}

void updateProduct(Product inventory[], int numProducts) {
    printf("\n----------------------------- UPDATE PRODUCT -----------------------------\n");

    int id = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    int index = searchProduct(inventory, numProducts, id);

    if(index == -1) {
        printf("\nProduct not found!\n");
    } else {
        printf("Product found!\n");
        printf("ID\tNAME\t\tQUANTITY\tPRICE\n");
        printf("%d\t%-15s\t%d\t\t$%.2f\n", inventory[index].id, inventory[index].name, inventory[index].quantity, inventory[index].price);

        printf("\nEnter new product name: ");
        scanf("%s", inventory[index].name);

        printf("Enter new product quantity: ");
        scanf("%d", &inventory[index].quantity);

        printf("Enter new product price: ");
        scanf("%f", &inventory[index].price);

        printf("Product updated successfully!\n");

    }
}

void deleteProduct(Product inventory[], int *numProducts) {
    printf("\n----------------------------- DELETE PRODUCT -----------------------------\n");

    int id = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    int index = searchProduct(inventory, *numProducts, id);

    if(index == -1) {
        printf("\nProduct not found!\n");
    } else {
        printf("Product found!\n");
        printf("ID\tNAME\t\tQUANTITY\tPRICE\n");
        printf("%d\t%-15s\t%d\t\t$%.2f\n", inventory[index].id, inventory[index].name, inventory[index].quantity, inventory[index].price);

        for(int i = index; i < (*numProducts) - 1; i++) {
            inventory[i] = inventory[i+1];
        }

        (*numProducts)--;
        printf("Product deleted successfully!\n");

    }
}