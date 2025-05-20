//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    char description[100];
    int price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if(num_products == MAX_PRODUCTS) {
        printf("Unable to add new product, inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter product description: ");
    scanf(" %[^\n]s", inventory[num_products].description);
    printf("Enter price: ");
    scanf("%d", &inventory[num_products].price);
    printf("Enter quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    num_products++;
    printf("New product added successfully.\n");
}

void list_inventory() {
    printf("Product\t\tDescription\t\tPrice\t\tQuantity\n");
    for(int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t$%d\t\t%d\n", inventory[i].name, inventory[i].description, inventory[i].price, inventory[i].quantity);
    }
}

void remove_product() {
    char name[50];
    printf("Enter name of product to remove: ");
    scanf("%s", name);

    for(int i = 0; i < num_products; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            for(int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Unable to find product with name %s.\n", name);
}

void menu() {
    printf("\n-------- Product Inventory System --------\n");
    printf("1. Add product\n");
    printf("2. List inventory\n");
    printf("3. Remove product\n");
    printf("4. Exit\n");
    printf("-----------------------------------------\n");
}

int main() {
    int choice = 0;

    while(choice != 4) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                list_inventory();
                break;
            case 3:
                remove_product();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}