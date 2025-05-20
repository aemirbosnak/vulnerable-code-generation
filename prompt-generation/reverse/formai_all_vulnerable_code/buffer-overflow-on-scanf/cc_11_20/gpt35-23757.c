//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[50];
    int id;
    float price;
    int quantity;
} Product;

int main() {
    Product inventory[50];
    int num_products = 0;

    while (1) {
        printf("\nWelcome to the Product Inventory System!\n");
        printf("1. Add a new product\n");
        printf("2. View all products\n");
        printf("3. Update product quantity\n");
        printf("4. Search for a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", inventory[num_products].name);
                printf("Enter product ID: ");
                scanf("%d", &inventory[num_products].id);
                printf("Enter product price: ");
                scanf("%f", &inventory[num_products].price);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[num_products].quantity);
                num_products++;
                break;
            case 2:
                printf("\nID     Name              Price   Quantity\n");
                for (int i = 0; i < num_products; i++) {
                    printf("%-6d %-18s $%-5.2f  %-8d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;
            case 3:
                printf("\nEnter product ID: ");
                int id;
                scanf("%d", &id);
                for (int i = 0; i < num_products; i++) {
                    if (inventory[i].id == id) {
                        printf("Enter new quantity: ");
                        int quantity;
                        scanf("%d", &quantity);
                        inventory[i].quantity = quantity;
                    }
                }
                break;
            case 4:
                printf("\nEnter product name: ");
                char name[50];
                scanf("%s", name);
                for (int i = 0; i < num_products; i++) {
                    if (strcmp(inventory[i].name, name) == 0) {
                        printf("\nID: %d", inventory[i].id);
                        printf("\nPrice: $%.2f", inventory[i].price);
                        printf("\nQuantity: %d", inventory[i].quantity);
                        break;
                    }
                }
                break;
            case 5:
                printf("\nThank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}