//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    char name[20];
    int id;
    float price;
    int quantity;
};

int main() {
    struct product inventory[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    while (1) {
        printf("Welcome to the Product Inventory System!\n");
        printf("Menu:\n");
        printf("1. Add a product\n");
        printf("2. View all products\n");
        printf("3. Update a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%c", &choice);
        fflush(stdin);  // clear input buffer

        switch(choice) {
            case '1':   // add product
                if (num_products >= MAX_PRODUCTS) {
                    printf("Error: inventory full!\n");
                } else {
                    printf("Enter product name: ");
                    scanf("%s", inventory[num_products].name);
                    printf("Enter product id: ");
                    scanf("%d", &inventory[num_products].id);
                    printf("Enter product price: ");
                    scanf("%f", &inventory[num_products].price);
                    printf("Enter product quantity: ");
                    scanf("%d", &inventory[num_products].quantity);
                    num_products++;
                    printf("Product added successfully!\n");
                }
                break;

            case '2':   // view all products
                if (num_products == 0) {
                    printf("Inventory is empty!\n");
                } else {
                    printf("Product Inventory:\n");
                    printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Price", "Quantity");
                    for (int i = 0; i < num_products; i++) {
                        printf("%-20s %-10d $%-9.2f %-10d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
                    }
                }
                break;

            case '3':   // update product
                if (num_products == 0) {
                    printf("Inventory is empty!\n");
                } else {
                    int id, found = 0;
                    printf("Enter product id to update: ");
                    scanf("%d", &id);
                    for (int i = 0; i < num_products; i++) {
                        if (id == inventory[i].id) {
                            printf("Enter new product name (or leave blank to keep current name): ");
                            scanf("%s", inventory[i].name);
                            printf("Enter new product price (or enter 0 to keep current price): ");
                            scanf("%f", &inventory[i].price);
                            printf("Enter new product quantity (or enter 0 to keep current quantity): ");
                            scanf("%d", &inventory[i].quantity);
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) {
                        printf("Error: product with id %d not found!\n", id);
                    } else {
                        printf("Product updated successfully!\n");
                    }
                }
                break;

            case '4':   // delete product
                if (num_products == 0) {
                    printf("Inventory is empty!\n");
                } else {
                    int id, found = 0;
                    printf("Enter product id to delete: ");
                    scanf("%d", &id);
                    for (int i = 0; i < num_products; i++) {
                        if (id == inventory[i].id) {
                            found = 1;
                            for (int j = i; j < num_products-1; j++) {
                                strcpy(inventory[j].name, inventory[j+1].name);
                                inventory[j].id = inventory[j+1].id;
                                inventory[j].price = inventory[j+1].price;
                                inventory[j].quantity = inventory[j+1].quantity;
                            }
                            num_products--;
                            printf("Product deleted successfully!\n");
                            break;
                        }
                    }
                    if (found == 0) {
                        printf("Error: product with id %d not found!\n", id);
                    }
                }
                break;

            case '5':   // exit
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);

            default:
                printf("Error: invalid choice!\n");
        }
        printf("\n");
    }

    return 0;
}