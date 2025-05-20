//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    char description[100];
    int quantity;
    double price;
};

struct product products[100];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;

    printf("Product added successfully!\n\n");
}

void view_products() {
    if (num_products == 0) {
        printf("There are no products in the inventory.\n\n");
        return;
    }

    printf("%-20s %-40s %-10s %-10s\n", "Name", "Description", "Quantity", "Price");

    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-40s %-10d $%-.2lf\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    printf("\n");
}

void view_product_details(char name[]) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%-20s %-40s %-10s %-10s\n", "Name", "Description", "Quantity", "Price");
            printf("%-20s %-40s %-10d $%-.2lf\n\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
            return;
        }
    }

    printf("Product not found.\n\n");
}

void remove_product(char name[]) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                strcpy(products[j].name, products[j+1].name);
                strcpy(products[j].description, products[j+1].description);
                products[j].quantity = products[j+1].quantity;
                products[j].price = products[j+1].price;
            }

            num_products--;

            printf("Product removed successfully.\n\n");
            return;
        }
    }

    printf("Product not found.\n\n");
}

void save_to_file() {
    FILE *fp;

    fp = fopen("inventory.txt", "w");

    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n\n");
        return;
    }

    for (int i = 0; i < num_products; i++) {
        fprintf(fp, "%s|%s|%d|%.2lf\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    fclose(fp);

    printf("Inventory saved to file successfully!\n\n");
}

void load_from_file() {
    FILE *fp;

    fp = fopen("inventory.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file for reading.\n\n");
        return;
    }

    while (!feof(fp)) {
        fscanf(fp, "%[^|]|%[^|]|%d|%lf\n", products[num_products].name, products[num_products].description, &products[num_products].quantity, &products[num_products].price);
        num_products++;
    }

    fclose(fp);

    printf("Inventory loaded from file successfully!\n\n");
}

int main() {
    int choice;
    char name[50];

    do {
        printf("-------------------------------\n");
        printf("Product Inventory System\n");
        printf("-------------------------------\n\n");

        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. View product details\n");
    printf("4. Remove product\n");
    printf("5. Save to file\n");
    printf("6. Load from file\n");
    printf("7. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:
                add_product();
                break;

            case 2:
                view_products();
                break;

            case 3:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("\n");

                view_product_details(name);
                break;

            case 4:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("\n");

                remove_product(name);
                break;

            case 5:
                save_to_file();
                break;

            case 6:
                load_from_file();
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }

    } while (choice != 7);

    return 0;
}