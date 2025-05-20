//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char address[50];
    char phone[20];
} Customer;

typedef struct {
    int id;
    char product[50];
    int quantity;
    float price;
} Order;

int main() {
    FILE *customerFile;
    FILE *orderFile;

    customerFile = fopen("customers.txt", "a+");
    orderFile = fopen("orders.txt", "a+");
    
    if (customerFile == NULL || orderFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char choice;
    do {
        printf("Select an action:\n");
        printf("1. Add customer\n");
        printf("2. Add order\n");
        printf("3. View customers\n");
        printf("4. View orders\n");
        printf("5. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter customer details:\n");
                Customer c;
                printf("ID: ");
                scanf("%d", &c.id);
                printf("Name: ");
                scanf("%s", c.name);
                printf("Address: ");
                scanf("%s", c.address);
                printf("Phone: ");
                scanf("%s", c.phone);
                fprintf(customerFile, "%d %s %s %s\n", c.id, c.name, c.address, c.phone);
                printf("Customer added successfully!\n");
                break;
            case '2':
                printf("Enter order details:\n");
                Order o;
                printf("ID: ");
                scanf("%d", &o.id);
                printf("Product: ");
                scanf("%s", o.product);
                printf("Quantity: ");
                scanf("%d", &o.quantity);
                printf("Price: ");
                scanf("%f", &o.price);
                fprintf(orderFile, "%d %s %d %.2f\n", o.id, o.product, o.quantity, o.price);
                printf("Order added successfully!\n");
                break;
            case '3':
                printf("Customers:\n");
                char line[200];
                rewind(customerFile);
                while (fgets(line, 200, customerFile) != NULL) {
                    Customer c;
                    sscanf(line, "%d %s %s %s", &c.id, c.name, c.address, c.phone);
                    printf("%d %s %s %s\n", c.id, c.name, c.address, c.phone);
                }
                break;
            case '4':
                printf("Orders:\n");
                rewind(orderFile);
                while (fgets(line, 200, orderFile) != NULL) {
                    Order o;
                    sscanf(line, "%d %s %d %f", &o.id, o.product, &o.quantity, &o.price);
                    printf("%d %s %d %.2f\n", o.id, o.product, o.quantity, o.price);
                }
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != '5');

    fclose(customerFile);
    fclose(orderFile);

    return 0;
}