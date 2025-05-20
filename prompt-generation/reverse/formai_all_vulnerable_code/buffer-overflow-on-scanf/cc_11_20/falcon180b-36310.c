//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 10000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

int main() {
    int choice;
    char filename[100];
    FILE *fp;
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the Product Inventory System!\n");
    printf("Please enter a filename to use for the inventory data:\n");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %f", products[num_products].name, &products[num_products].quantity, &products[num_products].price)!= EOF) {
        num_products++;
    }

    fclose(fp);

    while (1) {
        printf("\nProduct Inventory System Menu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product quantity\n");
        printf("4. Display all products\n");
        printf("5. Save changes to file\n");
        printf("6. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                printf("Enter product price: ");
                scanf("%f", &products[num_products].price);
                num_products++;
                printf("Product added successfully.\n");
                break;

            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", products[num_products - 1].name);
                num_products--;
                printf("Product removed successfully.\n");
                break;

            case 3:
                printf("Enter product name to update quantity: ");
                scanf("%s", products[num_products - 1].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[num_products - 1].quantity);
                printf("Product quantity updated successfully.\n");
                break;

            case 4:
                printf("All products:\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%s %d $%.2f\n", products[i].name, products[i].quantity, products[i].price);
                }
                break;

            case 5:
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Error: could not open file.\n");
                    exit(1);
                }
                for (int i = 0; i < num_products; i++) {
                    fprintf(fp, "%s %d %f\n", products[i].name, products[i].quantity, products[i].price);
                }
                fclose(fp);
                printf("Changes saved to file.\n");
                break;

            case 6:
                printf("Thank you for using the Product Inventory System.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}