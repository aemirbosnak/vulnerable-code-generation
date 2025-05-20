//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Product {
    char* name;
    int quantity;
    double price;
};

void add_product(struct Product* product) {
    printf("Enter product name: ");
    scanf("%s", product->name);

    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter product price: ");
    scanf("%lf", &product->price);
}

void display_product(struct Product* product) {
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
    printf("Price: $%.2lf\n", product->price);
}

int main() {
    struct Product product;
    int choice = 0;

    while (1) {
        printf("1. Add product\n");
        printf("2. Display product\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&product);
                break;
            case 2:
                display_product(&product);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}