//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (1) {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display products\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_products >= MAX_PRODUCTS) {
                printf("Inventory is full.\n");
            } else {
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter price: ");
                scanf("%f", &products[num_products].price);
                num_products++;
            }
            break;

        case 2:
            printf("Enter product name to remove: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);

            int index = -1;
            for (int i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                printf("Product not found.\n");
            } else {
                num_products--;
                for (int i = index; i < num_products; i++) {
                    memcpy(&products[i], &products[i+1], sizeof(Product));
                }
            }
            break;

        case 3:
            printf("Enter product name to update: ");
            char name2[MAX_NAME_LENGTH];
            scanf("%s", name2);

            int index2 = -1;
            for (int i = 0; i < num_products; i++) {
                if (strcmp(products[i].name, name2) == 0) {
                    index2 = i;
                    break;
                }
            }

            if (index2 == -1) {
                printf("Product not found.\n");
            } else {
                printf("Enter new product name: ");
                scanf("%s", products[index2].name);
                printf("Enter new quantity: ");
                scanf("%d", &products[index2].quantity);
                printf("Enter new price: ");
                scanf("%f", &products[index2].price);
            }
            break;

        case 4:
            printf("Inventory:\n");
            for (int i = 0; i < num_products; i++) {
                printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}