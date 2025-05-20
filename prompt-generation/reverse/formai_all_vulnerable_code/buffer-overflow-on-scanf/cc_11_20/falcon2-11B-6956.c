//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[100];
    float price;
    int quantity;
};

int main() {
    struct Product products[10];
    int numProducts = 0;
    int choice;

    printf("Product Inventory System\n");
    printf("---------------------------\n");

    while (1) {
        printf("\n1. Add Product\n2. Display Products\n3. Update Quantity\n4. Delete Product\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Product Name: ");
                scanf("%s", products[numProducts].name);
                printf("Enter Product Price: ");
                scanf("%f", &products[numProducts].price);
                printf("Enter Product Quantity: ");
                scanf("%d", &products[numProducts].quantity);
                printf("\n");
                numProducts++;
                break;
            case 2:
                printf("\nProduct List:\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("Product %d: %s - $%.2f (%d)\n", i + 1, products[i].name, products[i].price, products[i].quantity);
                }
                break;
            case 3:
                printf("Enter Product Number to Update Quantity: ");
                scanf("%d", &choice);
                if (choice >= 0 && choice <= numProducts) {
                    printf("Enter Updated Quantity: ");
                    scanf("%d", &products[choice].quantity);
                }
                break;
            case 4:
                printf("Enter Product Number to Delete: ");
                scanf("%d", &choice);
                if (choice >= 0 && choice <= numProducts) {
                    for (int i = choice; i < numProducts - 1; i++) {
                        products[i] = products[i + 1];
                    }
                    numProducts--;
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}