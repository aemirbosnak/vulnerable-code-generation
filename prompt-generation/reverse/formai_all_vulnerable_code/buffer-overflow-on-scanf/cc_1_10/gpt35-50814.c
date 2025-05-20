//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <string.h>

/* Struct to represent a product in warehouse */
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

/* Function to print all products in warehouse */
void printProducts(Product* products, int count) {
    printf("Warehouse Inventory:\n");
    printf("ID \t NAME \t PRICE \t QUANTITY\n");
    for (int i=0; i<count; i++) {
        printf("%d \t %s \t %.2f \t %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

int main() {
    int choice, count = 0;
    Product products[100];

    /* Loop for user options */
    while (1) {
        printf("Select an option:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Print Warehouse Inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                /* Add product option */
                printf("\nEnter product ID: ");
                scanf("%d", &products[count].id);
                printf("Enter product name: ");
                scanf("%s", products[count].name);
                printf("Enter product price: ");
                scanf("%f", &products[count].price);
                printf("Enter product quantity: ");
                scanf("%d", &products[count].quantity);
                count++;
                printf("\nProduct added successfully!\n\n");
                break;

            case 2:
                /* Remove product option */
                printf("\nEnter product ID to remove: ");
                int idToRemove;
                scanf("%d", &idToRemove);
                int found = 0;
                for (int i=0; i<count; i++) {
                    if (products[i].id == idToRemove) {
                        found = 1;
                        for (int j=i+1; j<count; j++) {
                            products[j-1] = products[j];
                        }
                        count--;
                        break;
                    }
                }
                if (found) {
                    printf("\nProduct removed successfully!\n\n");
                } else {
                    printf("\nProduct not found in warehouse!\n\n");
                }
                break;

            case 3:
                /* Print all products option */
                printProducts(products, count);
                break;

            case 4:
                /* Exit option */
                printf("Exiting program...\n");
                return 0;

            default:
                /* Invalid option */
                printf("Invalid option selected, please try again.\n\n");
        }
    }

    return 0;
}