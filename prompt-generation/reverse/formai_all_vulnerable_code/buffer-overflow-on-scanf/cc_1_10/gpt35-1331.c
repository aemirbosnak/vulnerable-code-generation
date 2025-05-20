//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define product struct */
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

/* Declare global variables */
Product products[100];
int num_of_products = 0;

/* Declare function prototypes */
void add_product();
void sell_product();
void display_products();
void display_sales();

int main() {
    /* Main menu */
    int choice;
    do {
        printf("Welcome to CyberMed - Your One-Stop Shop for Medical Supplies\n");
        printf("-----------------------------------------------------------\n");
        printf("1. Add product\n");
        printf("2. Sell product\n");
        printf("3. Display products\n");
        printf("4. Display sales\n");
        printf("5. Exit\n");
        printf("-----------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                sell_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                display_sales();
                break;
            case 5:
                printf("Thank you for using CyberMed!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/* Function to add product */
void add_product() {
    int id;
    char name[50];
    int quantity;
    float price;

    /* Get details of product from user */
    printf("Enter product id: ");
    scanf("%d", &id);
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%f", &price);

    /* Create product and add to products array */
    Product product = {id, name, quantity, price};
    products[num_of_products] = product;
    num_of_products++;

    printf("Product added successfully!\n");
}

/* Function to sell product */
void sell_product() {
    int id;
    int index = -1;

    /* Get id of product to sell from user */
    printf("Enter product id: ");
    scanf("%d", &id);

    /* Search for product with id in products array */
    for (int i = 0; i < num_of_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    /* If product found, sell it */
    if (index != -1) {
        printf("Selling %s...\n", products[index].name);

        /* Decrement product quantity */
        products[index].quantity--;

        printf("Sale successful!\n");
    } else {
        printf("No such product found. Please try again.\n");
    }
}

/* Function to display all products in store */
void display_products() {
    printf("Product ID   Product Name                Quantity    Price\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < num_of_products; i++) {
        printf("%-12d%-28s%-12d%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

/* Function to display sales history */
void display_sales() {
    printf("Sales History\n");
    printf("-------------\n");
    for (int i = 0; i < num_of_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity - products[i].quantity);
    }
}