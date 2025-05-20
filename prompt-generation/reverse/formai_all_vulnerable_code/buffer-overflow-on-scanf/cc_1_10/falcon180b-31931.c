//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int price;
} Item;

int main() {
    int num_items, i;
    Item items[MAX_ITEMS];
    char choice;
    double total_price = 0;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter the number of items on the menu (up to %d): ", MAX_ITEMS);
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter item #%d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]", items[i].name);
        items[i].name[strcspn(items[i].name, "\n")] = '\0';

        printf("Description: ");
        scanf(" %[^\n]", items[i].description);
        items[i].description[strcspn(items[i].description, "\n")] = '\0';

        printf("Price: ");
        scanf("%d", &items[i].price);
    }

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View menu\n");
        printf("2. Place an order\n");
        printf("3. View total price\n");
        printf("4. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nMenu:\n");
                for (i = 0; i < num_items; i++) {
                    printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price/100);
                }
                break;

            case '2':
                printf("\nPlease enter the item number: ");
                scanf("%d", &i);
                if (i >= 1 && i <= num_items) {
                    total_price += items[i-1].price;
                    printf("\nItem added to order: %s - $%.2f\n", items[i-1].name, items[i-1].price/100);
                } else {
                    printf("\nInvalid item number.\n");
                }
                break;

            case '3':
                printf("\nTotal price: $%.2f\n", total_price);
                break;

            case '4':
                printf("\nThank you for using the Cafe Billing System!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}