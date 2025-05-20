//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 20

struct product {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    int quantity;
    float price;
};

struct product inventory[MAX_PRODUCTS];
int count = 0;

/* Function to add new product to inventory */
void add_product() {
    if(count == MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    struct product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product category: ");
    scanf("%s", p.category);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    inventory[count] = p;
    count++;
    printf("Product added to inventory!\n");
}

/* Function to search for a product by name */
void search_product() {
    char name[MAX_NAME_LEN];
    printf("Enter product name to search: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("Product found in inventory!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Category: %s\n", inventory[i].category);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Product not found in inventory!\n");
}

/* Function to display all products in inventory */
void display_products() {
    if(count == 0) {
        printf("No products in inventory!\n");
        return;
    }
    printf("Name\tCategory\tQuantity\tPrice\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].category, inventory[i].quantity, inventory[i].price);
    }
}

/* Function to remove a product from inventory */
void remove_product() {
    char name[MAX_NAME_LEN];
    printf("Enter product name to remove: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            for(int j=i; j<count-1; j++) {
                inventory[j] = inventory[j+1];
            }
            count--;
            printf("Product removed from inventory!\n");
            return;
        }
    }
    printf("Product not found in inventory!\n");
}

int main() {
    int choice = 0;
    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Search product\n");
        printf("3. Display all products\n");
        printf("4. Remove product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                search_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                remove_product();
                break;
            case 5:
                printf("Exiting program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}