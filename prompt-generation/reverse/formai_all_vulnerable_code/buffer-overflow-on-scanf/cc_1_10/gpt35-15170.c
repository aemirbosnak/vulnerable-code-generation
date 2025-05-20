//FormAI DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[100];
int count = 0;

void addProduct(char name[], int quantity, float price) {
    if (count >= 100) {
        printf("Sorry, your inventory is full.\n");
        return;
    }
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;
    inventory[count] = newProduct;
    count++;
    printf("%s has been added to your inventory.\n", name);
}

void displayInventory() {
    if (count == 0) {
        printf("Your inventory is currently empty.\n");
        return;
    }
    printf("PRODUCT          QUANTITY          PRICE\n");
    for (int i = 0; i < count; i++) {
        printf("%s          %d          $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void removeProduct(char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("%s has been removed from your inventory.\n", name);
            return;
        }
    }
    printf("%s is not found in your inventory.\n", name);
}

int main() {
    printf("Welcome to your product inventory system. What would you like to do?\n");
    while(1) {
        int choice;
        char name[50];
        int quantity;
        float price;
        printf("1. Add a product to your inventory\n");
        printf("2. Display your inventory\n");
        printf("3. Remove a product from your inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("What is the name of the product? ");
                scanf("%s", name);
                printf("How many do you have? ");
                scanf("%d", &quantity);
                printf("What is the price? ");
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                printf("What is the name of the product? ");
                scanf("%s", name);
                removeProduct(name);
                break;
            case 4:
                printf("Thank you for using your product inventory system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}