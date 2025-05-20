//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

void read_products(struct product products[]) {
    FILE *fp;
    char filename[50] = "products.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d %f\n", products[count].name, &products[count].quantity, &products[count].price)!= EOF) {
        count++;
        if (count >= MAX_PRODUCTS) {
            printf("Maximum number of products reached.\n");
            break;
        }
    }

    fclose(fp);
}

void display_products(struct product products[]) {
    int count = 0;
    while (count < MAX_PRODUCTS && products[count].name[0]!= '\0') {
        printf("%s - %d units in stock - $%.2f each\n", products[count].name, products[count].quantity, products[count].price);
        count++;
    }
}

void update_quantity(struct product products[], char name[], int quantity) {
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            break;
        }
    }
}

int main() {
    struct product products[MAX_PRODUCTS];

    read_products(products);

    char choice;
    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Display products\n");
        printf("2. Update quantity\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                display_products(products);
                break;
            case '2':
                printf("Enter product name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter quantity: ");
                int qty;
                scanf("%d", &qty);
                update_quantity(products, name, qty);
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}