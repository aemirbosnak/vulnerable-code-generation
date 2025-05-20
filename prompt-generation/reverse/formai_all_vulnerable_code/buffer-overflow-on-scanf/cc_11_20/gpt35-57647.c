//FormAI DATASET v1.0 Category: Product Inventory System ; Style: calm
#include<stdio.h>
#include<string.h>

#define MAX_LEN 100

struct Product {
    char name[MAX_LEN];
    int code;
    float price;
    int quantity;
};

int main() {
    int choice, numProducts = 0, i;
    struct Product products[MAX_LEN];

    printf("=== Product Inventory System ===\n\n");

    do {
        printf("Choose an option:\n1. Add Product\n2. Search Product\n3. Remove Product\n4. Display Inventory\n0. Exit Program\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (numProducts == MAX_LEN) {
                    printf("The inventory is full.\n");
                    break;
                }
                printf("Enter the product name: ");
                scanf("%s", products[numProducts].name);
                printf("Enter the product code: ");
                scanf("%d", &products[numProducts].code);
                printf("Enter the product price: ");
                scanf("%f", &products[numProducts].price);
                printf("Enter the product quantity: ");
                scanf("%d", &products[numProducts].quantity);

                numProducts++;
                printf("\nProduct added successfully!\n");
                break;

            case 2:
                printf("Enter the product code: ");
                int searchCode;
                scanf("%d", &searchCode);
                for (i = 0; i < numProducts; i++) {
                    if (products[i].code == searchCode) {
                        printf("Product details:\nName: %s\nCode: %d\nPrice: %.2f\nQuantity: %d\n\n", products[i].name, products[i].code, products[i].price, products[i].quantity);
                        break;
                    }
                }
                if (i == numProducts) {
                    printf("Product not found.\n");
                }
                break;

            case 3:
                printf("Enter the product code: ");
                int removeCode;
                scanf("%d", &removeCode);
                for (i = 0; i < numProducts; i++) {
                    if (products[i].code == removeCode) {
                        for (int j = i; j < numProducts - 1; j++) {
                            products[j] = products[j + 1];
                        }
                        numProducts--;
                        printf("The product has been removed.\n");
                        break;
                    }
                }
                if (i == numProducts) {
                    printf("Product not found.\n");
                }
                break;

            case 4:
                printf("Inventory:\n");
                for (i = 0; i < numProducts; i++) {
                    printf("%d. %s (code: %d, price: %.2f, quantity: %d)\n", i + 1, products[i].name, products[i].code, products[i].price, products[i].quantity);
                }
                printf("\n");
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}