//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
// C Product Inventory System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int menu() {
    int choice;
    printf("\n1. Add product\n2. List all products\n3. Search for product\n4. Modify product\n5. Remove product\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int addProduct(struct Product products[], int count) {
    if (count == MAX_PRODUCTS) {
        printf("Error: Reached maximum number of products.\n");
        return count;
    }
    printf("Enter product name: ");
    scanf("%s", products[count].name);
    printf("Enter product price: ");
    scanf("%f", &products[count].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);
    products[count].id = count + 1;
    printf("Product added successfully with ID: %d\n", products[count].id);
    return ++count;
}

void listProducts(struct Product products[], int count) {
    if (count == 0) {
        printf("No products to display.\n");
        return;
    }
    printf("ID\tNAME\t\tPRICE\tQUANTITY\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t$%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

void searchProduct(struct Product products[], int count) {
    if (count == 0) {
        printf("No products to search for.\n");
        return;
    }
    char searchTerm[50];
    printf("Enter product name to search for: ");
    scanf("%s", searchTerm);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(searchTerm, products[i].name) == 0) {
            printf("%d\t%s\t$%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No products found.\n");
    }
}

int modifyProduct(struct Product products[], int count) {
    if (count == 0) {
        printf("No products to modify.\n");
        return count;
    }
    int productId;
    printf("Enter product ID to modify: ");
    scanf("%d", &productId);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (products[i].id == productId) {
            printf("Enter new product name (or leave blank to keep old value): ");
            scanf("%s", products[i].name);
            printf("Enter new product price (or -1 to keep old value): ");
            scanf("%f", &products[i].price);
            if (products[i].price == -1) {
                products[i].price = products[i].price;
            }
            printf("Enter new product quantity (or -1 to keep old value): ");
            scanf("%d", &products[i].quantity);
            if (products[i].quantity == -1) {
                products[i].quantity = products[i].quantity;
            }
            printf("Product modified successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
    return count;
}

int removeProduct(struct Product products[], int count) {
    if (count == 0) {
        printf("No products to remove.\n");
        return count;
    }
    int productId;
    printf("Enter product ID to remove: ");
    scanf("%d", &productId);
    for (int i = 0; i < count; i++) {
        if (products[i].id == productId) {
            for (int j = i; j < count - 1; j++) {
                products[j] = products[j+1];
            }
            printf("Product removed successfully.\n");
            return --count;
        }
    }
    printf("Product not found.\n");
    return count;
}

int main() {
    struct Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;
    do {
        choice = menu();
        switch(choice) {
            case 1:
                count = addProduct(products, count);
                break;
            case 2:
                listProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                count = modifyProduct(products, count);
                break;
            case 5:
                count = removeProduct(products, count);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    return 0;
}