//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    float price;
    int quantity;
} Product;

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add new product\n");
    printf("2. View all products\n");
    printf("3. Update product price\n");
    printf("4. Update product quantity\n");
    printf("5. Delete product\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    Product products[MAX_SIZE];
    int product_count = 0;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add new product
                printf("Enter product name: ");
                scanf("%s", products[product_count].name);
                printf("Enter product price: ");
                scanf("%f", &products[product_count].price);
                printf("Enter product quantity: ");
                scanf("%d", &products[product_count].quantity);
                product_count++;
                break;
            case 2: // View all products
                printf("Product name\tPrice\tQuantity\n");
                for (int i = 0; i < product_count; i++) {
                    printf("%s\t%f\t%d\n", products[i].name, products[i].price, products[i].quantity);
                }
                break;
            case 3: // Update product price
                printf("Enter product name to update: ");
                scanf("%s", products[product_count].name);
                printf("Enter new product price: ");
                scanf("%f", &products[product_count].price);
                break;
            case 4: // Update product quantity
                printf("Enter product name to update: ");
                scanf("%s", products[product_count].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[product_count].quantity);
                break;
            case 5: // Delete product
                printf("Enter product name to delete: ");
                scanf("%s", products[product_count].name);
                product_count--;
                break;
            case 6: // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 6);

    return 0;
}