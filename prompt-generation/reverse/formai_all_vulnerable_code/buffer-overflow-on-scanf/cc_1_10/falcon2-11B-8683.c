//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    double price;
} Product;

int main() {
    Product product[10];
    int n = 0;
    char choice;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Update a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter product name: ");
                scanf("%s", product[n].name);
                printf("Enter quantity: ");
                scanf("%d", &product[n].quantity);
                printf("Enter price: ");
                scanf("%lf", &product[n].price);
                n++;
                break;
            case '2':
                printf("Enter product name: ");
                scanf("%s", product[n].name);
                n--;
                break;
            case '3':
                printf("Enter product name: ");
                scanf("%s", product[n].name);
                printf("Enter new quantity: ");
                scanf("%d", &product[n].quantity);
                printf("Enter new price: ");
                scanf("%lf", &product[n].price);
                break;
            case '4':
                printf("\nAll products:\n");
                for (int i = 0; i < n; i++) {
                    printf("%s - Quantity: %d - Price: $%.2lf\n", product[i].name, product[i].quantity, product[i].price);
                }
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}