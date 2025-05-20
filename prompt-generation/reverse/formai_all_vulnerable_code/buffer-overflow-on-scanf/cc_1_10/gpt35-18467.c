//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

int menu() {
    int choice;
    printf("PRODUCT INVENTORY SYSTEM\n");
    printf("------------------------\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display All Products\n");
    printf("4. Search Product\n");
    printf("5. Update Product\n");
    printf("6. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    return choice;
}

int search(Product products[], int count, char name[]) {
    int i;
    for (i=0; i<count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add(Product products[], int *count) {
    char name[50];
    int quantity;
    float price;
    printf("Enter Product Name: ");
    scanf("%s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);
    strcpy(products[*count].name, name);
    products[*count].quantity = quantity;
    products[*count].price = price;
    (*count)++;
}

void remove_product(Product products[], int *count) {
    char name[50];
    int i, index;
    printf("Enter Product Name: ");
    scanf("%s", name);
    index = search(products, *count, name);
    if (index == -1) {
        printf("Product not found\n");
    } else {
        for (i=index; i<*count-1; i++) {
            products[i] = products[i+1];
        }
        (*count)--;
        printf("Product removed successfully\n");
    }
}

void display_all(Product products[], int count) {
    int i;
    if (count == 0) {
        printf("No products found\n");
    } else {
        printf("%-20s%-10s%-10s\n", "Name", "Quantity", "Price");
        for (i=0; i<count; i++) {
            printf("%-20s%-10d%-10.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

void search_product(Product products[], int count) {
    char name[50];
    int index;
    printf("Enter Product Name: ");
    scanf("%s", name);
    index = search(products, count, name);
    if (index == -1) {
        printf("Product not found\n");
    } else {
        printf("%-20s%-10s%-10s\n", "Name", "Quantity", "Price");
        printf("%-20s%-10d%-10.2f\n", products[index].name, products[index].quantity, products[index].price);
    }
}

void update_product(Product products[], int count) {
    char name[50];
    int index, quantity;
    float price;
    printf("Enter Product Name: ");
    scanf("%s", name);
    index = search(products, count, name);
    if (index == -1) {
        printf("Product not found\n");
    } else {
        printf("Enter Quantity: ");
        scanf("%d", &quantity);
        printf("Enter Price: ");
        scanf("%f", &price);
        products[index].quantity = quantity;
        products[index].price = price;
        printf("Product updated successfully\n");
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int choice, count=0;
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                add(products, &count);
                break;
            case 2:
                remove_product(products, &count);
                break;
            case 3:
                display_all(products, count);
                break;
            case 4:
                search_product(products, count);
                break;
            case 5:
                update_product(products, count);
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}