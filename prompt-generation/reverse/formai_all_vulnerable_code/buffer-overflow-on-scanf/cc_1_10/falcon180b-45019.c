//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50

typedef struct {
    char name[50];
    int age;
    char address[100];
} Customer;

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

void addProduct(Product products[], int *numProducts) {
    printf("Enter product name: ");
    scanf("%s", &(products[*numProducts].name));
    printf("Enter product price: ");
    scanf("%f", &(products[*numProducts].price));
    printf("Enter product quantity: ");
    scanf("%d", &(products[*numProducts].quantity));
    (*numProducts)++;
}

void displayProducts(Product products[], int numProducts) {
    printf("Product List:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - $%.2f - %d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

void addCustomer(Customer customers[], int *numCustomers) {
    printf("Enter customer name: ");
    scanf("%s", &(customers[*numCustomers].name));
    printf("Enter customer age: ");
    scanf("%d", &(customers[*numCustomers].age));
    printf("Enter customer address: ");
    scanf("%s", &(customers[*numCustomers].address));
    (*numCustomers)++;
}

void displayCustomers(Customer customers[], int numCustomers) {
    printf("Customer List:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%s - %d - %s\n", customers[i].name, customers[i].age, customers[i].address);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    addProduct(products, &numProducts);
    displayProducts(products, numProducts);

    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;
    addCustomer(customers, &numCustomers);
    displayCustomers(customers, numCustomers);

    return 0;
}