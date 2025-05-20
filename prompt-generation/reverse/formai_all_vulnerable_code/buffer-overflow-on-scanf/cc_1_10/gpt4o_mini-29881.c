//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

typedef struct {
    int id;
    char name[50];
    float totalSpent;
} Customer;

Product products[MAX_PRODUCTS];
Customer customers[MAX_CUSTOMERS];
int productCount = 0;
int customerCount = 0;

// Function prototypes
void addProduct();
void displayProducts();
void addCustomer();
void displayCustomers();
void billCustomer();
void displayBill(int customerId);
int findProductById(int id);
int findCustomerById(int id);

// Entry point of the program
int main() {
    int choice;
    
    do {
        printf("\n=== Futuristic Cafe Billing System ===\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Add Customer\n");
        printf("4. Display Customers\n");
        printf("5. Bill Customer\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: addCustomer(); break;
            case 4: displayCustomers(); break;
            case 5: billCustomer(); break;
            case 6: printf("Exiting... Thank you for using the system!\n"); break;
            default: printf("Invalid option, please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Maximum product limit reached.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    products[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayProducts() {
    printf("\n=== Product List ===\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void addCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Maximum customer limit reached.\n");
        return;
    }
    
    Customer newCustomer;
    newCustomer.id = customerCount + 1;
    printf("Enter customer name: ");
    scanf("%s", newCustomer.name);
    newCustomer.totalSpent = 0.0;
    
    customers[customerCount] = newCustomer;
    customerCount++;
    printf("Customer added successfully!\n");
}

void displayCustomers() {
    printf("\n=== Customer List ===\n");
    for (int i = 0; i < customerCount; i++) {
        printf("ID: %d, Name: %s, Total Spent: %.2f\n", customers[i].id, customers[i].name, customers[i].totalSpent);
    }
}

void billCustomer() {
    int customerId;
    printf("Enter Customer ID for billing: ");
    scanf("%d", &customerId);
    
    int customerIndex = findCustomerById(customerId);
    
    if (customerIndex == -1) {
        printf("Customer not found.\n");
        return;
    }
    
    int productId;
    float total = 0.0;
    printf("Enter product IDs to bill (0 to checkout): \n");
    displayProducts();
    
    while (1) {
        printf("Product ID (0 to finish): ");
        scanf("%d", &productId);
        if (productId == 0) break;
        
        int productIndex = findProductById(productId);
        if (productIndex == -1) {
            printf("Product not found.\n");
        } else {
            total += products[productIndex].price;
            printf("Added %s to bill. Current total: %.2f\n", products[productIndex].name, total);
        }
    }
    
    customers[customerIndex].totalSpent += total;
    displayBill(customerId);
}

void displayBill(int customerId) {
    int customerIndex = findCustomerById(customerId);
    if (customerIndex != -1) {
        printf("\n=== Bill ===\n");
        printf("Customer: %s, Total Amount Due: %.2f\n", customers[customerIndex].name, customers[customerIndex].totalSpent);
    }
}

int findProductById(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findCustomerById(int id) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            return i;
        }
    }
    return -1;
}