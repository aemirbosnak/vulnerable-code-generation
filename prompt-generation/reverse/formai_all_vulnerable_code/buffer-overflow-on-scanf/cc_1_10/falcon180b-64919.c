//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_PRICE 10

struct item {
    char name[MAX_NAME];
    float price;
};

int main() {
    int num_items;
    struct item items[MAX_ITEMS];
    char choice;
    float total_price = 0.0;

    printf("Welcome to our romantic cafe!\n");
    printf("Please choose an option:\n");
    printf("1. Order\n2. View bill\n3. Exit\n");
    scanf("%c", &choice);

    while (choice!= '3') {
        switch (choice) {
            case '1':
                printf("Please enter the number of items you would like to order:\n");
                scanf("%d", &num_items);

                printf("Enter the name and price of each item:\n");
                for (int i = 0; i < num_items; i++) {
                    scanf("%s %f", items[i].name, &items[i].price);
                }

                printf("Your order has been placed. Thank you for choosing our cafe!\n");
                break;

            case '2':
                printf("Your bill:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%s - $%.2f\n", items[i].name, items[i].price);
                }
                printf("Total price: $%.2f\n", total_price);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Please choose an option:\n");
        printf("1. Order\n2. View bill\n3. Exit\n");
        scanf("%c", &choice);
    }

    return 0;
}