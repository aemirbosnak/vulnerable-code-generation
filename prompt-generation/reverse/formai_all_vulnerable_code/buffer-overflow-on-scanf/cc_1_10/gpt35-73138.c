//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void print_menu() {
    printf("Menu:\n");
    printf("1. Add product\n");
    printf("2. Update product\n");
    printf("3. Delete product\n");
    printf("4. View all products\n");
    printf("5. View product by ID\n");
    printf("6. Exit\n");
}

void add_product(struct product *products, int *count) {
    printf("Enter product ID: ");
    scanf("%d", &products[*count].id);

    printf("Enter product name: ");
    scanf("%s", products[*count].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[*count].price);

    (*count)++;
    printf("Product added successfully!\n");
}

void update_product(struct product *products, int count) {
    int id, choice, i, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("Product found!\n");
            printf("1. Update name\n");
            printf("2. Update quantity\n");
            printf("3. Update price\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", products[i].name);
                    break;
                case 2:
                    printf("Enter new quantity: ");
                    scanf("%d", &products[i].quantity);
                    break;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &products[i].price);
                    break;
                default:
                    printf("Invalid choice!\n");
            }

            printf("Product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

void delete_product(struct product *products, int *count) {
    int id, i, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *count; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("Product found!\n");
            products[i] = products[(*count) - 1];
            (*count)--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

void view_all_products(struct product *products, int count) {
    int i;
    printf("ID\tName\tQuantity\tPrice\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void view_product_by_id(struct product *products, int count) {
    int id, i, found = 0;
    printf("Enter product ID to view: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
    }
}

int main() {
    struct product products[100];
    int count = 0, choice;

    while (1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &count);
                break;
            case 2:
                update_product(products, count);
                break;
            case 3:
                delete_product(products, &count);
                break;
            case 4:
                view_all_products(products, count);
                break;
            case 5:
                view_product_by_id(products, count);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}