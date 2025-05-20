//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};
typedef struct product Product;

void add_product(Product product_array[], int *size) {
    if (*size == MAX) {
        printf("Inventory is full!\n");
        return;
    }
    Product new_product;
    printf("\nEnter Product Name: ");
    scanf("%s", new_product.name);
    printf("Enter Product ID: ");
    scanf("%d", &new_product.id);
    printf("Enter Product Price: ");
    scanf("%f", &new_product.price);
    printf("Enter Product Quantity: ");
    scanf("%d", &new_product.quantity);
    product_array[*size] = new_product;
    (*size)++;
    printf("Product added successfully.\n\n");
}

void search_product(Product product_array[], int size) {
    if (size == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter ID of the product to search for: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (product_array[i].id == id) {
            printf("\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n\n", product_array[i].id, product_array[i].name,
                   product_array[i].price, product_array[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Product not found!\n\n");
}

void delete_product(Product product_array[], int *size) {
    if (*size == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int id, found = 0, index;
    printf("\nEnter ID of the product to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *size; i++) {
        if (product_array[i].id == id) {
            index = i;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found!\n\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        product_array[i] = product_array[i + 1];
    }
    (*size)--;
    printf("Product deleted successfully.\n\n");
}

void update_product(Product product_array[], int size) {
    if (size == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter ID of the product to update: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (product_array[i].id == id) {
            printf("\nCurrent details of the product are:\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n\n",
                   product_array[i].id, product_array[i].name, product_array[i].price, product_array[i].quantity);
            printf("Enter new Product Name (press enter to leave unchanged): ");
            char c = getchar();
            fgets(product_array[i].name, sizeof(product_array[i].name), stdin);
            product_array[i].name[strcspn(product_array[i].name, "\n")] = 0;
            printf("Enter new Product Price (0 to leave unchanged): ");
            float price;
            scanf("%f", &price);
            if (price != 0)
                product_array[i].price = price;
            printf("Enter new Product Quantity (0 to leave unchanged): ");
            int quantity;
            scanf("%d", &quantity);
            if (quantity != 0) {
                product_array[i].quantity = quantity;
            }
            found = 1;
            printf("\nProduct updated successfully.\n\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found!\n\n");
    }
}

void print_all_products(Product product_array[], int size) {
    if (size == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\nAll products in inventory are:\n");
    printf("ID\tNAME\tPRICE\tQUANTITY\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\t%d\n", product_array[i].id, product_array[i].name, product_array[i].price,
               product_array[i].quantity);
    }
    printf("\n");
}

int main() {
    Product product_array[MAX];
    int size = 0;
    int choice;
    while (1) {
        printf("Inventory Menu\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Delete Product\n");
        printf("4. Update Product\n");
        printf("5. Print All Products\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                add_product(product_array, &size);
                break;
            case 2:
                search_product(product_array, size);
                break;
            case 3:
                delete_product(product_array, &size);
                break;
            case 4:
                update_product(product_array, size);
                break;
            case 5:
                print_all_products(product_array, size);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n\n");
                break;
        }
    }
    return 0;
}