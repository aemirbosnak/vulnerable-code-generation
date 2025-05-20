//FormAI DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product inventory[MAX_SIZE];
int count = 0;

void addToInventory() {
    printf("Enter product name: ");
    scanf("%s", inventory[count].name);
    printf("Enter product price: ");
    scanf("%f", &inventory[count].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[count].quantity);
    inventory[count].id = count + 1;
    count++;
}

void viewInventory() {
    if(count == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("#\tName\tPrice\tQuantity\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void removeProduct() {
    int productId;
    printf("Enter product ID to remove: ");
    scanf("%d", &productId);
    for(int i = 0; i < count; i++) {
        if(inventory[i].id == productId) {
            for(int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            count--;
            printf("Product %d has been removed from inventory!\n", productId);
            return;
        }
    }
    printf("Product not found in inventory!\n");
}

int main() {
    int choice;
    printf("Welcome to the Product Inventory System\n");
    printf("========================================\n");
    do {
        printf("Menu\n");
        printf("====\n");
        printf("1. Add product to inventory\n");
        printf("2. View inventory\n");
        printf("3. Remove product from inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addToInventory();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}