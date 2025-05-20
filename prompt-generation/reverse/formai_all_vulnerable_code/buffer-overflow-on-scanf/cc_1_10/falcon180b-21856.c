//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_QUANTITY 1000

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

void paranoid_check(int success, char* function_name) {
    if (!success) {
        printf("Error in %s\n", function_name);
        exit(1);
    }
}

int main() {
    int choice;
    int product_count = 0;
    Product products[MAX_PRODUCT_QUANTITY];

    while (1) {
        printf("\n");
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View products\n");
        printf("4. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (product_count >= MAX_PRODUCT_QUANTITY) {
                printf("Maximum product limit reached.\n");
            } else {
                printf("Enter product name (max %d characters): ", MAX_PRODUCT_NAME_LENGTH - 1);
                scanf("%s", products[product_count].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[product_count].quantity);
                product_count++;
            }
            break;

        case 2:
            if (product_count <= 0) {
                printf("No products to remove.\n");
            } else {
                printf("Enter product ID to remove (0-%d): ", product_count - 1);
                int id;
                scanf("%d", &id);
                if (id < 0 || id >= product_count) {
                    printf("Invalid product ID.\n");
                } else {
                    product_count--;
                    for (int i = id; i < product_count; i++) {
                        products[i] = products[i + 1];
                    }
                }
            }
            break;

        case 3:
            if (product_count <= 0) {
                printf("No products to view.\n");
            } else {
                printf("Product ID\tProduct Name\tQuantity\n");
                for (int i = 0; i < product_count; i++) {
                    printf("%d\t%s\t%d\n", i + 1, products[i].name, products[i].quantity);
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}