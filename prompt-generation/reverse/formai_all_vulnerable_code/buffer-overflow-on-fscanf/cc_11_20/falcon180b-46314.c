//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

int main() {
    FILE *fp;
    struct product products[MAX_PRODUCTS];
    int num_products = 0;
    char filename[20] = "products.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: products file not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", products[num_products].name, &products[num_products].quantity)!= EOF) {
        num_products++;
        if (num_products == MAX_PRODUCTS) {
            printf("Error: too many products in file.\n");
            exit(2);
        }
    }

    fclose(fp);

    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product quantity\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product quantity: ");
                scanf("%d", &products[num_products].quantity);
                num_products++;
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", products[num_products - 1].name);
                num_products--;
                break;
            case 3:
                printf("Enter product name to update: ");
                scanf("%s", products[num_products - 1].name);
                printf("Enter new product quantity: ");
                scanf("%d", &products[num_products - 1].quantity);
                break;
            case 4:
                printf("\nProduct Name\tQuantity\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%s\t\t%d\n", products[i].name, products[i].quantity);
                }
                break;
            case 5:
                fp = fopen(filename, "w");
                for (int i = 0; i < num_products; i++) {
                    fprintf(fp, "%s %d\n", products[i].name, products[i].quantity);
                }
                fclose(fp);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}