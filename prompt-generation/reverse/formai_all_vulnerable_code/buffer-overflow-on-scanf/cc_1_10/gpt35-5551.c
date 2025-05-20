//FormAI DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 //maximum number of products that can be added to the inventory
#define MAX_NAME_LEN 20 //maximum length of product name
#define MAX_STOCK 1000 //maximum stock of each product

typedef struct {
    char name[MAX_NAME_LEN];
    int stock;
    float price;
} product;

product inventory[MAX_PRODUCTS]; //array to store the inventory

int num_products = 0; //number of products currently in the inventory

void add_product() {
    if(num_products == MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter name of new product: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter stock of new product: ");
    scanf("%d", &inventory[num_products].stock);

    printf("Enter price of new product: ");
    scanf("%f", &inventory[num_products].price);

    num_products++;

    printf("Product added to inventory.\n");
}

void remove_product() {
    if(num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Enter name of product to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    int index = -1;
    for(int i = 0; i < num_products; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    for(int i = index; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    num_products--;

    printf("Product removed from inventory.\n");
}

void display_inventory() {
    if(num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Name\tStock\tPrice\n");
    for(int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

void update_stock() {
    if(num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Enter name of product to update stock: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    int index = -1;
    for(int i = 0; i < num_products; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter new stock: ");
    int new_stock;
    scanf("%d", &new_stock);
    inventory[index].stock = new_stock;

    printf("Stock updated.\n");
}

void update_price() {
    if(num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Enter name of product to update price: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    int index = -1;
    for(int i = 0; i < num_products; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter new price: ");
    float new_price;
    scanf("%f", &new_price);
    inventory[index].price = new_price;

    printf("Price updated.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Add product\n2. Remove product\n3. Display inventory\n4. Update stock\n5. Update price\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                update_stock();
                break;
            case 5:
                update_price();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}