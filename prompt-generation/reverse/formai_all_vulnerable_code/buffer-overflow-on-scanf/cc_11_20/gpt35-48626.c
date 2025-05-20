//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, n = 0, i, found = 0;
    char search[50];
    struct product prod[100];

    while (1) {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("-------------------------\n");
        printf("1. Add a product\n");
        printf("2. Search product\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter product id: ");
                scanf("%d", &prod[n].id);

                printf("Enter product name: ");
                scanf("%s", prod[n].name);

                printf("Enter product price: ");
                scanf("%f", &prod[n].price);

                printf("Enter product quantity: ");
                scanf("%d", &prod[n].quantity);

                n++;
                printf("\nProduct added successfully!\n");
                break;

            case 2:
                printf("\nEnter product name to search: ");
                scanf("%s", search);

                for (i = 0; i < n; i++) {
                    if (strcmp(prod[i].name, search) == 0) {
                        printf("\nProduct found\n");
                        printf("ID: %d\n", prod[i].id);
                        printf("Name: %s\n", prod[i].name);
                        printf("Price: %.2f\n", prod[i].price);
                        printf("Quantity: %d\n", prod[i].quantity);
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nProduct not found!\n");
                }
                break;

            case 3:
                printf("\nEnter product name to update: ");
                scanf("%s", search);

                for (i = 0; i < n; i++) {
                    if (strcmp(prod[i].name, search) == 0) {
                        printf("\nEnter new product id: ");
                        scanf("%d", &prod[i].id);

                        printf("Enter new product name: ");
                        scanf("%s", prod[i].name);

                        printf("Enter new product price: ");
                        scanf("%f", &prod[i].price);

                        printf("Enter new product quantity: ");
                        scanf("%d", &prod[i].quantity);

                        printf("\nProduct updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nProduct not found!\n");
                }
                break;

            case 4:
                printf("\nEnter product name to delete: ");
                scanf("%s", search);

                for (i = 0; i < n; i++) {
                    if (strcmp(prod[i].name, search) == 0) {
                        for (int j = i; j < n - 1; j++) {
                            prod[j] = prod[j+1];
                        }

                        n--;
                        printf("\nProduct deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nProduct not found!\n");
                }
                break;

            case 5:
                printf("\nPRODUCT LIST\n");
                printf("-------------\n");
                
                if (n == 0) {
                    printf("No products available!\n");
                } else {
                    for (i = 0; i < n; i++) {
                        printf("ID: %d\n", prod[i].id);
                        printf("Name: %s\n", prod[i].name);
                        printf("Price: %.2f\n", prod[i].price);
                        printf("Quantity: %d\n", prod[i].quantity);
                        printf("-----------------\n");
                    }
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}