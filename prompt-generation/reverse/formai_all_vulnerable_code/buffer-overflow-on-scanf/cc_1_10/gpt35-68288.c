//FormAI DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[50];
    float price;
    int quantity;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Sorry, the inventory is full.\n");
        return;
    }
    
    struct product p;
    
    printf("Enter name of product: ");
    scanf("%s", &p.name);
    
    printf("Enter price of product: ");
    scanf("%f", &p.price);
    
    printf("Enter quantity of product: ");
    scanf("%d", &p.quantity);
    
    inventory[num_products++] = p;
    printf("%s added to inventory.\n", p.name);
}

void remove_product() {
    if (num_products == 0) {
        printf("Sorry, the inventory is empty.\n");
        return;
    }
    
    printf("Enter the name of the product to remove: ");
    char name[50];
    scanf("%s", name);
    
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Sorry, could not find product %s\n", name);
    } else {
        struct product p = inventory[index];
        for (int i = index; i < num_products - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_products--;
        printf("%s removed from inventory.\n", p.name);
    }
}

void display_inventory() {
    if (num_products == 0) {
        printf("The inventory is empty.\n");
        return;
    }
    
    printf("%-20s %-10s %-10s\n", "Product Name", "Price", "Quantity");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void prompt_user() {
    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("(A)dd a product\n");
        printf("(R)emove a product\n");
        printf("(D)isplay inventory\n");
        printf("(Q)uit\n");
        printf("Enter your choice: ");
        
        char choice;
        scanf(" %c", &choice);
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                add_product();
                break;
            case 'R':
                remove_product();
                break;
            case 'D':
                display_inventory();
                break;
            case 'Q':
                printf("Thank you for using the Product Inventory System.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    prompt_user();
    return 0;
}