//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct product {
    int id;
    char name[50];
    float price;
};

int main() {
    struct product products[10];
    int num_products = 0;
    int choice, id, i;

    printf("Product Inventory System\n");
    printf("1. Add product\n");
    printf("2. List products\n");
    printf("3. Update product\n");
    printf("4. Delete product\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter product name: ");
                scanf("%s", products[num_products].name);
                printf("Enter product price: ");
                scanf("%f", &products[num_products].price);
                num_products++;
                break;
            case 2:
                printf("Product Inventory:\n");
                for (i = 0; i < num_products; i++) {
                    printf("%d. %s - $%.2f\n", i+1, products[i].name, products[i].price);
                }
                break;
            case 3:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Enter new product name: ");
                scanf("%s", products[id].name);
                printf("Enter new product price: ");
                scanf("%f", &products[id].price);
                break;
            case 4:
                printf("Enter product ID: ");
                scanf("%d", &id);
                printf("Are you sure you want to delete product %d? (y/n): ", id);
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    for (i = id; i < num_products-1; i++) {
                        products[i] = products[i+1];
                    }
                    num_products--;
                    printf("Product deleted.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}