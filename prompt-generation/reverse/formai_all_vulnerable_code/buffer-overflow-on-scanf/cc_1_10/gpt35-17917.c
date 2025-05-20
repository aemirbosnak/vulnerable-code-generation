//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[20];
    int quantity;
    float price;
} Product;

void addProduct(Product inventory[], int *count);
void updateProduct(Product inventory[], int count);
void deleteProduct(Product inventory[], int *count);
void searchProduct(Product inventory[], int count);

int main() {
    Product inventory[100];
    int count = 0;
    int choice;

    do {
        printf("PRODUCT INVENTORY SYSTEM\n");
        printf("------------------------\n");
        printf("1. Add a product\n");
        printf("2. Update a product\n");
        printf("3. Delete a product\n");
        printf("4. Search for a product\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                updateProduct(inventory, count);
                break;
            case 3:
                deleteProduct(inventory, &count);
                break;
            case 4:
                searchProduct(inventory, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}

void addProduct(Product inventory[], int *count) {
    Product newProduct;

    printf("\nEnter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[*count] = newProduct;
    (*count)++;

    printf("\nProduct added successfully\n");
}

void updateProduct(Product inventory[], int count) {
    char name[20];
    int i, option, newQuantity;
    float newPrice;

    printf("\nEnter product name: ");
    scanf("%s", name);

    for(i = 0; i < count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nWhat do you want to update?\n");
            printf("1. Quantity\n");
            printf("2. Price\n");
            printf("\nEnter your choice: ");
            scanf("%d", &option);

            switch(option) {
                case 1:
                    printf("Enter new quantity: ");
                    scanf("%d", &newQuantity);
                    inventory[i].quantity = newQuantity;
                    printf("\nQuantity updated successfully\n");
                    break;
                case 2:
                    printf("Enter new price: ");
                    scanf("%f", &newPrice);
                    inventory[i].price = newPrice;
                    printf("\nPrice updated successfully\n");
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            return;
        }
    }

    printf("\nProduct not found\n");
}

void deleteProduct(Product inventory[], int *count) {
    char name[20];
    int i, j;

    printf("\nEnter product name: ");
    scanf("%s", name);

    for(i = 0; i < *count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            for(j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("\nProduct deleted successfully\n");
            return;
        }
    }

    printf("\nProduct not found\n");
}

void searchProduct(Product inventory[], int count) {
    char name[20];
    int i;

    printf("\nEnter product name: ");
    scanf("%s", name);

    for(i = 0; i < count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nProduct details:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }

    printf("\nProduct not found\n");
}