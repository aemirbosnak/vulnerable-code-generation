//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    double price;
} Product;

typedef struct {
    int id;
    char name[50];
} Customer;

typedef struct {
    int id;
    char name[50];
    double total;
} Transaction;

int main() {
    // Declare an array of products
    Product products[10] = {
        {1, "Aspirin", 5.99},
        {2, "Tylenol", 4.99},
        {3, "Ibuprofen", 6.99},
        {4, "Panadol", 3.99},
        {5, "Zofran", 6.99},
        {6, "Vicodin", 12.99},
        {7, "Codeine", 9.99},
        {8, "Motrin", 4.99},
        {9, "Paracetamol", 3.99},
        {10, "Capsules", 2.99}
    };

    // Declare an array of customers
    Customer customers[5] = {
        {1, "John Doe"},
        {2, "Jane Doe"},
        {3, "Dr. Smith"},
        {4, "Dr. Johnson"},
        {5, "Dr. Williams"}
    };

    // Declare an array of transactions
    Transaction transactions[5] = {
        {1, "John Doe", 10.00},
        {2, "Jane Doe", 20.00},
        {3, "Dr. Smith", 30.00},
        {4, "Dr. Johnson", 40.00},
        {5, "Dr. Williams", 50.00}
    };

    int i, j, k, n, m, index;
    char choice, productName[50], customerName[50], transactionID[50];
    double price, totalPrice;

    // Loop until the user decides to exit
    while (1) {
        // Display the main menu
        printf("\nMedical Store Management System\n");
        printf("1. View Products\n");
        printf("2. View Customers\n");
        printf("3. View Transactions\n");
        printf("4. Add Product\n");
        printf("5. Add Customer\n");
        printf("6. Add Transaction\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Process the user's choice
        switch (choice) {
            case '1':
                printf("View Products\n");
                printf("Enter the product ID to view details: ");
                scanf(" %d", &n);

                for (i = 0; i < n; i++) {
                    index = i;
                    printf("Product ID: %d\n", products[index].id);
                    printf("Product Name: %s\n", products[index].name);
                    printf("Price: $%.2f\n", products[index].price);
                    printf("\n");
                }
                break;

            case '2':
                printf("View Customers\n");
                printf("Enter the customer ID to view details: ");
                scanf(" %d", &n);

                for (i = 0; i < n; i++) {
                    index = i;
                    printf("Customer ID: %d\n", customers[index].id);
                    printf("Customer Name: %s\n", customers[index].name);
                    printf("\n");
                }
                break;

            case '3':
                printf("View Transactions\n");
                printf("Enter the transaction ID to view details: ");
                scanf(" %d", &n);

                for (i = 0; i < n; i++) {
                    index = i;
                    printf("Transaction ID: %d\n", transactions[index].id);
                    printf("Customer Name: %s\n", transactions[index].name);
                    printf("Total Price: $%.2f\n", transactions[index].total);
                    printf("\n");
                }
                break;

            case '4':
                printf("Add Product\n");
                printf("Enter the product ID: ");
                scanf(" %d", &n);
                printf("Enter the product name: ");
                scanf(" %s", productName);
                printf("Enter the price: ");
                scanf(" %lf", &price);
                products[n].id = n;
                strcpy(products[n].name, productName);
                products[n].price = price;
                printf("Product added successfully!\n");
                break;

            case '5':
                printf("Add Customer\n");
                printf("Enter the customer ID: ");
                scanf(" %d", &n);
                printf("Enter the customer name: ");
                scanf(" %s", customerName);
                customers[n].id = n;
                strcpy(customers[n].name, customerName);
                printf("Customer added successfully!\n");
                break;

            case '6':
                printf("Add Transaction\n");
                printf("Enter the transaction ID: ");
                scanf(" %d", &n);
                printf("Enter the customer name: ");
                scanf(" %s", customerName);
                printf("Enter the total price: ");
                scanf(" %lf", &price);
                transactions[n].id = n;
                strcpy(transactions[n].name, customerName);
                transactions[n].total = price;
                printf("Transaction added successfully!\n");
                break;

            case '7':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}