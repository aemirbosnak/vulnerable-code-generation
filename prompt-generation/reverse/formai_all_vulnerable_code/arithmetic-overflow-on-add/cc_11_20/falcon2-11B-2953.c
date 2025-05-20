//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
    int discount;
} Product;

typedef struct {
    char name[50];
    int quantity;
    float price;
    int discount;
} Customer;

typedef struct {
    char name[50];
    int quantity;
    float price;
    int discount;
} Supplier;

int main() {
    int choice, n, q;
    Product products[50], suppliers[50], customers[50];
    Customer c[50], s[50];

    do {
        printf("1. Add a product\n2. View products\n3. Update product details\n4. Delete a product\n5. Add a supplier\n6. View suppliers\n7. Update supplier details\n8. Delete a supplier\n9. Add a customer\n10. View customers\n11. Update customer details\n12. Delete a customer\n0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[n].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[n].quantity);
                printf("Enter product price: ");
                scanf("%f", &products[n].price);
                printf("Enter product discount: ");
                scanf("%d", &products[n].discount);
                n++;
                break;
            case 2:
                printf("Product details:\n");
                for (int i = 0; i < n; i++) {
                    printf("Name: %s, Quantity: %d, Price: %.2f, Discount: %d\n", products[i].name, products[i].quantity, products[i].price, products[i].discount);
                }
                break;
            case 3:
                printf("Enter product name to update: ");
                scanf("%s", products[q].name);
                printf("Enter new product name: ");
                scanf("%s", products[q].name);
                break;
            case 4:
                printf("Enter product name to delete: ");
                scanf("%s", products[q].name);
                break;
            case 5:
                printf("Add a supplier\n");
                printf("Enter supplier name: ");
                scanf("%s", suppliers[n].name);
                printf("Enter supplier quantity: ");
                scanf("%d", &suppliers[n].quantity);
                printf("Enter supplier price: ");
                scanf("%f", &suppliers[n].price);
                printf("Enter supplier discount: ");
                scanf("%d", &suppliers[n].discount);
                n++;
                break;
            case 6:
                printf("Supplier details:\n");
                for (int i = 0; i < n; i++) {
                    printf("Name: %s, Quantity: %d, Price: %.2f, Discount: %d\n", suppliers[i].name, suppliers[i].quantity, suppliers[i].price, suppliers[i].discount);
                }
                break;
            case 7:
                printf("Update supplier details\n");
                printf("Enter supplier name to update: ");
                scanf("%s", suppliers[q].name);
                printf("Enter new supplier name: ");
                scanf("%s", suppliers[q].name);
                break;
            case 8:
                printf("Delete a supplier\n");
                printf("Enter supplier name to delete: ");
                scanf("%s", suppliers[q].name);
                break;
            case 9:
                printf("Add a customer\n");
                printf("Enter customer name: ");
                scanf("%s", customers[n].name);
                printf("Enter customer quantity: ");
                scanf("%d", &customers[n].quantity);
                printf("Enter customer price: ");
                scanf("%f", &customers[n].price);
                printf("Enter customer discount: ");
                scanf("%d", &customers[n].discount);
                n++;
                break;
            case 10:
                printf("Customer details:\n");
                for (int i = 0; i < n; i++) {
                    printf("Name: %s, Quantity: %d, Price: %.2f, Discount: %d\n", customers[i].name, customers[i].quantity, customers[i].price, customers[i].discount);
                }
                break;
            case 11:
                printf("Update customer details\n");
                printf("Enter customer name to update: ");
                scanf("%s", customers[q].name);
                printf("Enter new customer name: ");
                scanf("%s", customers[q].name);
                break;
            case 12:
                printf("Delete a customer\n");
                printf("Enter customer name to delete: ");
                scanf("%s", customers[q].name);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice!= 0);

    return 0;
}