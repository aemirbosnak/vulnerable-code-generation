//FormAI DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

void addProduct(struct product* products, int* count) {
    printf("\n===== Adding Product =====\n");

    int id, quantity;
    char name[50];
    float price;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    // Check if the product ID already exists
    for (int i = 0; i < *count; i++) {
        if (products[i].id == id) {
            printf("\nProduct with the ID %d already exists!\n", id);
            return;
        }
    }

    printf("Enter Product Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Product Price: ");
    scanf("%f", &price);

    printf("Enter Product Quantity: ");
    scanf("%d", &quantity);

    struct product p = { id, name, price, quantity };
    products[*count] = p;
    (*count)++;

    printf("\nProduct added successfully!\n");
}

void removeProduct(struct product* products, int* count) {
    printf("\n===== Removing Product =====\n");

    int id;
    printf("Enter Product ID: ");
    scanf("%d", &id);

    // Search for the product
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (products[i].id == id) {
            // Remove the product by shifting all the elements after it to the left by one position
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("\nProduct removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct with the ID %d not found!\n", id);
    }
}

void viewProduct(struct product* products, int* count) {
    printf("\n===== View Products =====\n");

    if (*count == 0) {
        printf("\nNo products found!\n");
        return;
    }

    printf("\nID\tNAME\t\t\tPRICE\tQUANTITY\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < *count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    struct product products[100];
    int count = 0, choice;

    while (1) {
        printf("\n===== Product Inventory System =====\n");
        printf("1. Add Product\n2. Remove Product\n3. View Products\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, &count);
            break;

        case 2:
            removeProduct(products, &count);
            break;

        case 3:
            viewProduct(products, &count);
            break;

        case 4:
            printf("\nExiting the program...\n");
            return 0;

        default:
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}