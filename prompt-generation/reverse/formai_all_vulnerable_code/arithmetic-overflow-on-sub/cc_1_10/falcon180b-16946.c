//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    int quantity;
    int price;
} Product;

int main() {
    int choice, id, quantity;
    char name[50];
    float price;
    Product products[MAX_SIZE];
    int num_products = 0;

    printf("Welcome to the Warehouse Management System!\n");
    printf("Please choose an option:\n");
    printf("1. Add product\n");
    printf("2. Update product\n");
    printf("3. Delete product\n");
    printf("4. View products\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter product ID: ");
            scanf("%d", &id);

            printf("Enter product name: ");
            scanf("%s", products[num_products].name);

            printf("Enter product quantity: ");
            scanf("%d", &products[num_products].quantity);

            printf("Enter product price: ");
            scanf("%f", &products[num_products].price);

            num_products++;
            printf("Product added successfully!\n");
            break;

        case 2:
            printf("Enter product ID to update: ");
            scanf("%d", &id);

            printf("Enter new product name: ");
            scanf("%s", products[id-1].name);

            printf("Enter new product quantity: ");
            scanf("%d", &products[id-1].quantity);

            printf("Enter new product price: ");
            scanf("%f", &products[id-1].price);

            printf("Product updated successfully!\n");
            break;

        case 3:
            printf("Enter product ID to delete: ");
            scanf("%d", &id);

            for (int i = 0; i < num_products; i++) {
                if (products[i].id == id) {
                    for (int j = i; j < num_products-1; j++) {
                        products[j] = products[j+1];
                    }
                    num_products--;
                    printf("Product deleted successfully!\n");
                    break;
                }
            }

            break;

        case 4:
            printf("Product ID\tProduct Name\tQuantity\tPrice\n");

            for (int i = 0; i < num_products; i++) {
                printf("%d\t\t%s\t\t%d\t\t$%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            }

            break;

        case 5:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}