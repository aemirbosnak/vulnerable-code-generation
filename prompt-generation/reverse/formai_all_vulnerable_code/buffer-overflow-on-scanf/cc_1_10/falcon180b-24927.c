//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 20
#define MAX_CUSTOMERS 50

typedef struct {
    int id;
    char name[50];
    char category[20];
    float price;
    int quantity;
} Product;

typedef struct {
    int id;
    char name[50];
    int credit_limit;
    float balance;
} Customer;

typedef struct {
    int id;
    char name[20];
} Category;

Product products[MAX_PRODUCTS];
Category categories[MAX_CATEGORIES];
Customer customers[MAX_CUSTOMERS];

int num_products = 0, num_categories = 0, num_customers = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product category: ");
    scanf("%s", products[num_products].category);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    num_products++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[num_customers].name);
    printf("Enter customer credit limit: ");
    scanf("%d", &customers[num_customers].credit_limit);
    customers[num_customers].balance = customers[num_customers].credit_limit;
    num_customers++;
}

void display_products() {
    printf("\nProduct List:\n");
    for(int i=0; i<num_products; i++) {
        printf("%d. %s - %s - %.2f - %d\n", i+1, products[i].name, products[i].category, products[i].price, products[i].quantity);
    }
}

void display_categories() {
    printf("\nCategory List:\n");
    for(int i=0; i<num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
}

void display_customers() {
    printf("\nCustomer List:\n");
    for(int i=0; i<num_customers; i++) {
        printf("%d. %s - Credit Limit: %d - Balance: %.2f\n", i+1, customers[i].name, customers[i].credit_limit, customers[i].balance);
    }
}

int main() {
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Product\n");
        printf("2. Add Category\n");
        printf("3. Add Customer\n");
        printf("4. Display Products\n");
        printf("5. Display Categories\n");
        printf("6. Display Customers\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                add_category();
                break;
            case 3:
                add_customer();
                break;
            case 4:
                display_products();
                break;
            case 5:
                display_categories();
                break;
            case 6:
                display_customers();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 7);

    return 0;
}