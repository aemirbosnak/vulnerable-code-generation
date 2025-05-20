//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

int main() {
    int choice = 0;
    int num_products = 0;
    int id = 1;

    struct product products[100];

    while (choice != 4) {
        printf("1) Add product\n");
        printf("2) View all products\n");
        printf("3) Search product by ID\n");
        printf("4) Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name of product: ");
                scanf("%s", products[num_products].name);
                products[num_products].id = id;
                printf("Enter price of product: ");
                scanf("%f", &products[num_products].price);
                printf("Enter quantity of product: ");
                scanf("%d", &products[num_products].quantity);
                printf("Product %s added with ID %d\n", products[num_products].name, id);
                num_products++;
                id++;
                break;

            case 2:
                printf("All Products:\n");
                for (int i = 0; i < num_products; i++) {
                    printf("Name: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Quantity: %d\n", products[i].quantity);
                    printf("\n");
                }
                break;

            case 3:
                printf("Enter product ID: ");
                scanf("%d", &id);
                for (int i = 0; i < num_products; i++) {
                    if (products[i].id == id) {
                        printf("Name: %s\n", products[i].name);
                        printf("ID: %d\n", products[i].id);
                        printf("Price: $%.2f\n", products[i].price);
                        printf("Quantity: %d\n", products[i].quantity);
                        printf("\n");
                        break;
                    }
                }
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}