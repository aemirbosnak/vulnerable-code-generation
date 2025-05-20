//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

struct product inventory[MAX_PRODUCTS];
int count = 0;

void display_products() {
    if(count == 0) {
        printf("No products available in the inventory.\n");
        return;
    }
    printf("Id\tName\tPrice\tQuantity\n");
    for(int i=0; i<count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void add_product() {
    if(count >= MAX_PRODUCTS) {
        printf("Cannot add more products, inventory is full.\n");
        return;
    }
    struct product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    p.id = count + 1;
    inventory[count++] = p;
}

void remove_product() {
    if(count == 0) {
        printf("Cannot remove product, inventory is empty.\n");
        return;
    }
    int id, found = 0;
    printf("Enter product id: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++) {
        if(inventory[i].id == id) {
            found = 1;
            for(int j=i; j<count-1; j++) {
                inventory[j] = inventory[j+1];
            }
            count--;
            printf("Product removed successfully.\n");
            break;
        }
    }
    if(!found) {
        printf("Product not found in the inventory.\n");
    }
}

void search_product() {
    if(count == 0) {
        printf("Cannot search for products, inventory is empty.\n");
        return;
    }
    char name[50];
    int found = 0;
    printf("Enter product name to search: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            found = 1;
            printf("Id\tName\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
            break;
        }
    }
    if(!found) {
        printf("Product not found in the inventory.\n");
    }
}

int main() {
    int choice;
    do {
        // Display menu
        printf("\n******* PRODUCT INVENTORY SYSTEM MENU *******\n");
        printf("1. Display Products\n");
        printf("2. Add Product\n");
        printf("3. Remove Product\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on choice
        switch(choice) {
            case 1:
                display_products();
                break;
            case 2:
                add_product();
                break;
            case 3:
                remove_product();
                break;
            case 4:
                search_product();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}