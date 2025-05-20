//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item_t;

int main() {
    int num_items, i;
    item_t items[MAX_ITEMS];
    char choice;
    float total = 0;

    printf("Welcome to the C Cafe Billing System!\n");
    printf("Enter number of items in the menu: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter price of item %d: ", i+1);
        scanf("%s", items[i].price);
    }

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Order\n");
        printf("2. View Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter item number: ");
                scanf("%d", &i);
                if (i >= 1 && i <= num_items) {
                    printf("You ordered %s for $%s\n", items[i-1].name, items[i-1].price);
                    total += atof(items[i-1].price);
                } else {
                    printf("Invalid item number\n");
                }
                break;
            case '2':
                printf("Your total bill is $%.2f\n", total);
                break;
            case '3':
                printf("Thank you for using the C Cafe Billing System!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}