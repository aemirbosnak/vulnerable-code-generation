//FormAI DATASET v1.0 Category: Product Inventory System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int* count);
void removeProduct(Product products[], int* count);
void displayInventory(Product products[], int count);
void saveToFile(Product products[], int count);

int main() {
    int input, count = 0;
    Product products[50];

    printf("Welcome to our Product Inventory System!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a product to the inventory\n");
        printf("2. Remove a product from the inventory\n");
        printf("3. Display inventory\n");
        printf("4. Save inventory to file\n");
        printf("5. Exit program\n\n");

        scanf("%d", &input);

        switch(input) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                removeProduct(products, &count);
                break;
            case 3:
                displayInventory(products, count);
                break;
            case 4:
                saveToFile(products, count);
                break;
            case 5:
                printf("Thank you for using our Product Inventory System!\n");
                break;
            default:
                printf("Invalid input, please try again.\n");
        }
    } while(input != 5);

    return 0;
}

void addProduct(Product products[], int* count) {
    if(*count >= 50) {
        printf("Inventory is full, cannot add any more products.\n");
        return;
    }

    Product newProduct;

    printf("Please enter the name of the product: ");
    scanf("%s", newProduct.name);

    printf("Please enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);

    printf("Please enter the price of the product: ");
    scanf("%f", &newProduct.price);

    products[*count] = newProduct;

    printf("\nProduct added to inventory!\n");

    (*count)++;
}

void removeProduct(Product products[], int* count) {
    if(*count == 0) {
        printf("Inventory is empty, cannot remove any products.\n");
        return;
    }

    char name[50];
    printf("Please enter the name of the product you want to remove: ");
    scanf("%s", name);

    for(int i = 0; i < *count; i++) {
        if(strcmp(products[i].name, name) == 0) {
            for(int j = i; j < *count-1; j++) {
                products[j] = products[j+1];
            }

            (*count)--;

            printf("\nProduct removed from inventory!\n");

            return;
        }
    }

    printf("Product not found in inventory.\n");
}

void displayInventory(Product products[], int count) {
    if(count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");

    for(int i = 0; i < count; i++) {
        printf("%-20s %-10d $%-9.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void saveToFile(Product products[], int count) {
    if(count == 0) {
        printf("Inventory is empty, nothing to save.\n");
        return;
    }

    FILE *file = fopen("inventory.txt", "w");

    if(file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fputs("Product Name, Quantity, Price\n", file);

    for(int i = 0; i < count; i++) {
        fprintf(file, "%s, %d, %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    fclose(file);

    printf("Inventory saved to file.\n");
}