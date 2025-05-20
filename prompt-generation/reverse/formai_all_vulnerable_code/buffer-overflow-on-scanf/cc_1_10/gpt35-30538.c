//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Alan Touring
// C Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100 // Maximum number of products in stock

typedef struct {
    char name[100];
    int id;
    int quantity;
    float price;
} product;

product stock[MAX_STOCK];
int num_products = 0;

void add_product() {
    int id, quantity;
    float price;
    char name[100];

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product id: ");
    scanf("%d", &id);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%f", &price);
    
    // Check if the product already exists
    for (int i = 0; i < num_products; i++) {
        if (stock[i].id == id) {
            printf("Product with id %d already exists.\n", id);
            return;
        }
    }

    // Add the new product to the stock
    strcpy(stock[num_products].name, name);
    stock[num_products].id = id;
    stock[num_products].quantity = quantity;
    stock[num_products].price = price;
    
    num_products++;
    printf("Product added successfully.\n");
}

void remove_product() {
    int id;
    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (stock[i].id == id) {
            // Remove the product from the stock by shifting all the elements to the left
            for (int j = i; j < num_products - 1; j++) {
                stock[j] = stock[j + 1];
            }
            num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product with id %d not found.\n", id);
}

void display_stock() {
    printf("Stock\n");
    printf("---------------------------------------------\n");
    printf("ID\tName\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", stock[i].id, stock[i].name, stock[i].quantity, stock[i].price);
    }
    printf("---------------------------------------------\n");
}

void change_price() {
    int id;
    float new_price;
    printf("Enter product id: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; i++) {
        if (stock[i].id == id) {
            printf("Enter new price: ");
            scanf("%f", &new_price);
            stock[i].price = new_price;
            printf("Price changed successfully.\n");
            return;
        }
    }
    printf("Product with id %d not found.\n", id);
}

int main() {
    int option;

    while (1) {
        printf("\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display stock\n");
        printf("4. Change product price\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_stock();
                break;
            case 4:
                change_price();
                break;
            case 5:
                printf("Thanks for using our system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}