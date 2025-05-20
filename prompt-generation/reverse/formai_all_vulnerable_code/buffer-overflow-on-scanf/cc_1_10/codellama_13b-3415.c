//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: protected
/*
 * Unique C Product Inventory System example program in a protected style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for a product
struct product {
    char name[50];
    int quantity;
    float price;
};

// Define the struct for a user
struct user {
    char name[50];
    int id;
    char password[50];
};

// Define the struct for a transaction
struct transaction {
    char name[50];
    int quantity;
    float price;
    char date[50];
};

// Function to add a product
void add_product(struct product *products, int *num_products) {
    // Prompt the user for the product details
    printf("Enter the product name: ");
    scanf("%s", products[*num_products].name);
    printf("Enter the product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    printf("Enter the product price: ");
    scanf("%f", &products[*num_products].price);

    // Increment the number of products
    (*num_products)++;
}

// Function to add a user
void add_user(struct user *users, int *num_users) {
    // Prompt the user for the user details
    printf("Enter the user name: ");
    scanf("%s", users[*num_users].name);
    printf("Enter the user id: ");
    scanf("%d", &users[*num_users].id);
    printf("Enter the user password: ");
    scanf("%s", users[*num_users].password);

    // Increment the number of users
    (*num_users)++;
}

// Function to add a transaction
void add_transaction(struct transaction *transactions, int *num_transactions) {
    // Prompt the user for the transaction details
    printf("Enter the transaction name: ");
    scanf("%s", transactions[*num_transactions].name);
    printf("Enter the transaction quantity: ");
    scanf("%d", &transactions[*num_transactions].quantity);
    printf("Enter the transaction price: ");
    scanf("%f", &transactions[*num_transactions].price);
    printf("Enter the transaction date: ");
    scanf("%s", transactions[*num_transactions].date);

    // Increment the number of transactions
    (*num_transactions)++;
}

// Function to display all products
void display_products(struct product *products, int num_products) {
    // Print the header
    printf("Name\tQuantity\tPrice\n");

    // Loop through the products and print their details
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to display all users
void display_users(struct user *users, int num_users) {
    // Print the header
    printf("Name\tID\tPassword\n");

    // Loop through the users and print their details
    for (int i = 0; i < num_users; i++) {
        printf("%s\t%d\t%s\n", users[i].name, users[i].id, users[i].password);
    }
}

// Function to display all transactions
void display_transactions(struct transaction *transactions, int num_transactions) {
    // Print the header
    printf("Name\tQuantity\tPrice\tDate\n");

    // Loop through the transactions and print their details
    for (int i = 0; i < num_transactions; i++) {
        printf("%s\t%d\t%.2f\t%s\n", transactions[i].name, transactions[i].quantity, transactions[i].price, transactions[i].date);
    }
}

// Main function
int main() {
    // Define the arrays for the products, users, and transactions
    struct product products[100];
    struct user users[100];
    struct transaction transactions[100];

    // Initialize the number of products, users, and transactions
    int num_products = 0;
    int num_users = 0;
    int num_transactions = 0;

    // Add a product
    add_product(products, &num_products);

    // Add a user
    add_user(users, &num_users);

    // Add a transaction
    add_transaction(transactions, &num_transactions);

    // Display all products
    display_products(products, num_products);

    // Display all users
    display_users(users, num_users);

    // Display all transactions
    display_transactions(transactions, num_transactions);

    return 0;
}