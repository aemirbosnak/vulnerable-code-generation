//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void printMenu() {
    printf("=== Product Inventory System ===\n");
    printf("[1] Add Product\n");
    printf("[2] Update Product\n");
    printf("[3] View Product\n");
    printf("[4] Exit\n");
}

int main() {
    int choice = 0;
    int count = 0;
    struct Product products[50];

    while (choice != 4) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("=== Add Product ===\n");
                printf("Enter Product ID: ");
                scanf("%d", &products[count].id);
                printf("Enter Product Name: ");
                scanf("%s", products[count].name);
                printf("Enter Product Quantity: ");
                scanf("%d", &products[count].quantity);
                printf("Enter Product Price: ");
                scanf("%f", &products[count].price);
                count++;
                printf("Product added successfully!\n");
                break;
            case 2:
                printf("=== Update Product ===\n");
                printf("Enter Product ID: ");
                int id;
                scanf("%d", &id);
                int i;
                for (i = 0; i < count; i++) {
                    if (products[i].id == id) {
                        printf("Enter Product Name: ");
                        scanf("%s", products[i].name);
                        printf("Enter Product Quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Enter Product Price: ");
                        scanf("%f", &products[i].price);
                        printf("Product updated successfully!\n");
                        break;
                    }
                }
                if (i == count) {
                    printf("Product not found!\n");
                }
                break;
            case 3:
                printf("=== View Products ===\n");
                printf("ID\tNAME\tQUANTITY\tPRICE\n");
                int j;
                for (j = 0; j < count; j++) {
                    printf("%d\t%s\t%d\t%.2f\n", products[j].id, products[j].name, products[j].quantity, products[j].price);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}