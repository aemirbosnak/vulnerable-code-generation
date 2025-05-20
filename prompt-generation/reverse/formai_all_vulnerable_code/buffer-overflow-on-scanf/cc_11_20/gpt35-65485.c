//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, i, n;
    char search[50];
    struct product inventory[50];
    printf("Enter number of products: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter name, quantity and price of product %d: ", i+1);
        scanf("%s %d %f", &inventory[i].name, &inventory[i].quantity, &inventory[i].price);
    }
    do {
        printf("\n1. Display current inventory");
        printf("\n2. Add new product");
        printf("\n3. Search for product");
        printf("\n4. Exit program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nCurrent inventory:\n");
                printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
                for (i = 0; i < n; i++) {
                    printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 2:
                printf("\nEnter name, quantity and price of new product: ");
                scanf("%s %d %f", &inventory[n].name, &inventory[n].quantity, &inventory[n].price);
                n++;
                break;
            case 3:
                printf("\nEnter name of product to search: ");
                scanf("%s", &search);
                for (i = 0; i < n; i++) {
                    if (strcmp(search, inventory[i].name) == 0) {
                        printf("\nProduct found!\n");
                        printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
                        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nProduct not found!");
                }
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice!");
                break;
        }
    } while (choice != 4);
    return 0;
}