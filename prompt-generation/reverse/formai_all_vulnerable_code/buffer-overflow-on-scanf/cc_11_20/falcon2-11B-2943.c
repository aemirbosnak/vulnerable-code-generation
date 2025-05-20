//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

int main() {
    Product products[10];
    int i, j, n, m;

    printf("Welcome to the Medical Store Management System!\n");
    printf("Enter the number of products:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter product ID: ");
        scanf("%d", &products[i].id);
        printf("Enter product name: ");
        scanf("%s", products[i].name);
        printf("Enter product price: ");
        scanf("%f", &products[i].price);
        printf("Enter product quantity: ");
        scanf("%d", &products[i].quantity);
    }

    printf("Product IDs:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s, $%.2f, %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    printf("Enter product ID to update: ");
    scanf("%d", &m);
    for (j = 0; j < n; j++) {
        if (products[j].id == m) {
            printf("Enter new product name: ");
            scanf("%s", products[j].name);
            printf("Enter new product price: ");
            scanf("%f", &products[j].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[j].quantity);
            break;
        }
    }

    printf("Product IDs:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s, $%.2f, %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    printf("Enter product ID to delete: ");
    scanf("%d", &m);
    for (j = 0; j < n; j++) {
        if (products[j].id == m) {
            for (i = j; i < n - 1; i++) {
                products[i] = products[i + 1];
            }
            n--;
            break;
        }
    }

    printf("Product IDs:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s, $%.2f, %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    printf("Enter product ID to add: ");
    scanf("%d", &m);
    for (j = 0; j < n; j++) {
        if (products[j].id == m) {
            printf("Enter new product name: ");
            scanf("%s", products[j].name);
            printf("Enter new product price: ");
            scanf("%f", &products[j].price);
            printf("Enter new product quantity: ");
            scanf("%d", &products[j].quantity);
            break;
        }
    }

    printf("Product IDs:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s, $%.2f, %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    return 0;
}