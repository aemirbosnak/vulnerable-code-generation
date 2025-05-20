//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Product;

void addProduct(Product *p, int *count) {
    p[*count].id = *count + 1;
    printf("Please enter the name of the product: ");
    scanf("%s", p[*count].name);
    printf("Please enter the quantity of the product: ");
    scanf("%d", &p[*count].quantity);
    printf("Please enter the price of the product: ");
    scanf("%f", &p[*count].price);
    (*count)++;
}

void viewProduct(Product *p, int count) {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t$%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
    }
}

void searchProduct(Product *p, int count) {
    char keyword[20];
    printf("Please enter the name of the product: ");
    scanf("%s", keyword);
    for (int i = 0; i < count; i++) {
        if (strcmp(keyword, p[i].name) == 0) {
            printf("ID\tName\tQuantity\tPrice\n");
            printf("%d\t%s\t%d\t\t$%.2f\n", p[i].id, p[i].name, p[i].quantity, p[i].price);
            return;
        }
    }
    printf("No matching product found.\n");
}

void updateProduct(Product *p, int count) {
    int id;
    printf("Please enter the ID of the product: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (id == p[i].id) {
            printf("Please enter the name of the product: ");
            scanf("%s", p[i].name);
            printf("Please enter the quantity of the product: ");
            scanf("%d", &p[i].quantity);
            printf("Please enter the price of the product: ");
            scanf("%f", &p[i].price);
            return;
        }
    }
    printf("Invalid ID.\n");
}

void deleteProduct(Product *p, int *count) {
    int id;
    printf("Please enter the ID of the product: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (id == p[i].id) {
            for (int j = i; j < *count - 1; j++) {
                p[j] = p[j + 1];
            }
            (*count)--;
            return;
        }
    }
    printf("Invalid ID.\n");
}

int main() {
    Product *products = malloc(sizeof(Product) * 100);
    int count = 0;
    int choice;

    do {
        printf("\n========== Warehouse Management System ==========\n");
        printf("1. Add a product\n");
        printf("2. View all products\n");
        printf("3. Search a product\n");
        printf("4. Update a product\n");
        printf("5. Delete a product\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                viewProduct(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                updateProduct(products, count);
                break;
            case 5:
                deleteProduct(products, &count);
                break;
            case 0:
                printf("Thank you for using Warehouse Management System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free(products);
    return 0;
}