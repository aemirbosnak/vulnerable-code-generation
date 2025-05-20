//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int price;
    int quantity;
};

struct Product products[] = {
    {"Aspirin", 1, 5},
    {"Band-Aid", 1, 10},
    {"Bandage", 1, 20}
};

int main() {
    int choice, count = 0;

    printf("Welcome to the Medical Store Management System!\n");
    printf("Please select an option:\n");
    printf("1. View products\n");
    printf("2. Add product\n");
    printf("3. Remove product\n");
    printf("4. Update product quantity\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 5) {
        switch (choice) {
            case 1:
                printf("Here are the available products:\n");
                for (int i = 0; i < sizeof(products) / sizeof(struct Product); i++) {
                    printf("%s - $%.2f - %d\n", products[i].name, products[i].price, products[i].quantity);
                }
                break;
            case 2:
                printf("Enter the name of the product you want to add: ");
                fgets(products[count].name, sizeof(products[count].name), stdin);
                printf("Enter the price of the product: ");
                scanf("%d", &products[count].price);
                printf("Enter the quantity of the product: ");
                scanf("%d", &products[count].quantity);
                count++;
                break;
            case 3:
                printf("Enter the name of the product you want to remove: ");
                fgets(products[count].name, sizeof(products[count].name), stdin);
                count--;
                break;
            case 4:
                printf("Enter the name of the product you want to update quantity for: ");
                fgets(products[count].name, sizeof(products[count].name), stdin);
                printf("Enter the new quantity: ");
                scanf("%d", &products[count].quantity);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("Thank you for using the Medical Store Management System!\n");

    return 0;
}