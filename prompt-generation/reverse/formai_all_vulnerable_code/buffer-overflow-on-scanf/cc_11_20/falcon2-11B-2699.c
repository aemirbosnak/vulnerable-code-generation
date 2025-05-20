//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_STOCK 100
#define MAX_ITEMS 100

typedef struct {
    char name[20];
    float price;
    int stock;
} Product;

typedef struct {
    char name[20];
    int id;
} Customer;

int main() {
    Product products[MAX_ITEMS];
    int numProducts = 0;
    Customer customers[MAX_ITEMS];
    int numCustomers = 0;

    int choice = 0;
    int menu = 0;
    int i;

    while (choice!= 99) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View products\n");
        printf("4. Update product price\n");
        printf("5. View customer details\n");
        printf("6. Add customer\n");
        printf("7. Remove customer\n");
        printf("8. View customer details\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[numProducts].name);
                printf("Enter product price: ");
                scanf("%f", &products[numProducts].price);
                printf("Enter product stock: ");
                scanf("%d", &products[numProducts].stock);
                numProducts++;
                break;
            case 2:
                for (i = 0; i < numProducts; i++) {
                    if (products[i].stock > 0) {
                        printf("Removing %s...\n", products[i].name);
                        products[i].stock--;
                    }
                }
                break;
            case 3:
                printf("Product list:\n");
                for (i = 0; i < numProducts; i++) {
                    printf("%s - %d units in stock\n", products[i].name, products[i].stock);
                }
                break;
            case 4:
                printf("Enter product name: ");
                scanf("%s", products[numProducts].name);
                printf("Enter new price: ");
                scanf("%f", &products[numProducts].price);
                break;
            case 5:
                printf("Customer list:\n");
                for (i = 0; i < numCustomers; i++) {
                    printf("%s - %d\n", customers[i].name, customers[i].id);
                }
                break;
            case 6:
                printf("Enter customer name: ");
                scanf("%s", customers[numCustomers].name);
                printf("Enter customer id: ");
                scanf("%d", &customers[numCustomers].id);
                numCustomers++;
                break;
            case 7:
                for (i = 0; i < numCustomers; i++) {
                    if (customers[i].id > 0) {
                        printf("Removing %s...\n", customers[i].name);
                        customers[i].id--;
                    }
                }
                break;
            case 8:
                printf("Customer details:\n");
                for (i = 0; i < numCustomers; i++) {
                    printf("%s - %d\n", customers[i].name, customers[i].id);
                }
                break;
            case 9:
                printf("Exiting...\n");
                choice = 99;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\nPress any key to continue...\n");
        getchar();
        menu++;
    }

    return 0;
}