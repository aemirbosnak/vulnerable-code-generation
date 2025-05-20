//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define structure for product
struct Product {
    char name[50];
    float price;
    int quantity;
};

// Function to display products
void displayProducts() {
    struct Product products[5];

    // Input data for the first product
    printf("Enter product name: ");
    scanf("%s", products[0].name);
    printf("Enter product price: ");
    scanf("%f", &products[0].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[0].quantity);

    // Input data for the second product
    printf("Enter product name: ");
    scanf("%s", products[1].name);
    printf("Enter product price: ");
    scanf("%f", &products[1].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[1].quantity);

    // Input data for the third product
    printf("Enter product name: ");
    scanf("%s", products[2].name);
    printf("Enter product price: ");
    scanf("%f", &products[2].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[2].quantity);

    // Input data for the fourth product
    printf("Enter product name: ");
    scanf("%s", products[3].name);
    printf("Enter product price: ");
    scanf("%f", &products[3].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[3].quantity);

    // Input data for the fifth product
    printf("Enter product name: ");
    scanf("%s", products[4].name);
    printf("Enter product price: ");
    scanf("%f", &products[4].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[4].quantity);

    // Display products
    printf("Products:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f (%d units)\n", products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    displayProducts();
    return 0;
}