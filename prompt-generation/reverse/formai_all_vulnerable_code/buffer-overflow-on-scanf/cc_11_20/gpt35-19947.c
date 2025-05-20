//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

int main() {
    Product inventory[50];
    int num_products = 0;

    // Main menu
    while (1) {
        printf("\n~~~~~ Product Inventory System ~~~~~\n");
        printf("1. Add a Product\n");
        printf("2. Search a Product\n");
        printf("3. Update a Product\n");
        printf("4. Delete a Product\n");
        printf("5. View Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n~~~~~ Add a Product ~~~~~\n");

                printf("Enter the name of the product: ");
                scanf("%s", &inventory[num_products].name);

                printf("Enter the quantity of the product: ");
                scanf("%d", &inventory[num_products].quantity);

                printf("Enter the price of the product: ");
                scanf("%f", &inventory[num_products].price);

                num_products++;
                break;

            case 2:
                printf("\n~~~~~ Search a Product ~~~~~\n");

                printf("Enter the name of the product: ");
                char search_name[50];
                scanf("%s", &search_name);

                int found = 0;
                int i;
                for (i = 0; i < num_products; i++) {
                    if (strcmp(search_name, inventory[i].name) == 0) {
                        printf("Found %s: %d units at $%.2f each\n", 
                            inventory[i].name,
                            inventory[i].quantity,
                            inventory[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Product not found\n");
                }
                break;

            case 3:
                printf("\n~~~~~ Update a Product ~~~~~\n");

                printf("Enter the name of the product: ");
                char update_name[50];
                scanf("%s", &update_name);

                found = 0;
                for (i = 0; i < num_products; i++) {
                    if (strcmp(update_name, inventory[i].name) == 0) {
                        printf("Enter the new quantity of the product: ");
                        scanf("%d", &inventory[i].quantity);

                        printf("Enter the new price of the product: ");
                        scanf("%f", &inventory[i].price);

                        printf("Product updated successfully\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Product not found\n");
                }
                break;

            case 4:
                printf("\n~~~~~ Delete a Product ~~~~~\n");

                printf("Enter the name of the product: ");
                char delete_name[50];
                scanf("%s", &delete_name);

                found = 0;
                for (i = 0; i < num_products; i++) {
                    if (strcmp(delete_name, inventory[i].name) == 0) {
                        for (int j = i; j < num_products - 1; j++) {
                            inventory[j] = inventory[j+1];
                        }
                        num_products--;
                        printf("Product deleted successfully\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Product not found\n");
                }
                break;

            case 5:
                printf("\n~~~~~ View Inventory ~~~~~\n");

                printf("Name\tQuantity\tPrice\n");
                for (i = 0; i < num_products; i++) {
                   printf("%s\t%d\t$%.2f\n", 
                        inventory[i].name,
                        inventory[i].quantity,
                        inventory[i].price);
                }
                break;

            case 6:
                printf("\nThank you for using our Product Inventory System!\n");
                return 0;

            default:
                printf("\nInvalid choice, please try again\n");
        }
    }
}