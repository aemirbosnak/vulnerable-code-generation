//FormAI DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the structure for product
struct Product {
    char name[50];
    int quantity;
    float price;
};

//define a function to add new product
void add_product(struct Product *products, int *counter) {
    printf("\n-----Add New Product-----\n");
    printf("Enter product name: ");
    scanf("%s", products[*counter].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*counter].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*counter].price);
    *counter += 1;
    printf("\nProduct added successfully!\n");
}

//define a function to display all products
void display_products(struct Product *products, int counter) {
    if (counter == 0) {
        printf("\nNo product found!\n");
    }
    else {
        printf("\n-----Product List-----\n");
        for (int i = 0; i < counter; i++) {
            printf("Product %d\n", i+1);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
        }
    }
}

//define a function to search for a product
void search_product(struct Product *products, int counter) {
    char name[50];
    printf("\n-----Search Product-----\n");
    printf("Enter product name: ");
    scanf("%s", name);
    for (int i = 0; i < counter; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nProduct found!\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//define a function to update a product
void update_product(struct Product *products, int counter) {
    char name[50];
    printf("\n-----Update Product-----\n");
    printf("Enter product name: ");
    scanf("%s", name);
    for (int i = 0; i < counter; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("\nProduct updated successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//define a function to delete a product
void delete_product(struct Product *products, int *counter) {
    char name[50];
    printf("\n-----Delete Product-----\n");
    printf("Enter product name: ");
    scanf("%s", name);
    for (int i = 0; i < *counter; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < *counter-1; j++) {
                products[j] = products[j+1];
            }
            *counter -= 1;
            printf("\nProduct deleted successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//main function
int main() {
    struct Product products[100];
    int counter = 0;
    int choice;
    do {
        printf("\n-----Product Inventory System-----\n");
        printf("1. Add new product\n");
        printf("2. Display all products\n");
        printf("3. Search a product\n");
        printf("4. Update a product\n");
        printf("5. Delete a product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product(products, &counter);
                break;
            case 2:
                display_products(products, counter);
                break;
            case 3:
                search_product(products, counter);
                break;
            case 4:
                update_product(products, counter);
                break;
            case 5:
                delete_product(products, &counter);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 6);
    return 0;
}