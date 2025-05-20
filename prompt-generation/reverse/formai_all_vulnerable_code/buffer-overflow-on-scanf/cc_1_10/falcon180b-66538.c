//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 50
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    float price;
} item;

int main() {
    int num_items, i;
    char choice;
    float total = 0;
    item items[MAX_ITEMS];

    printf("Welcome to the C Cafe!\n");
    printf("Please choose an option:\n");
    printf("1. Order\n");
    printf("2. View menu\n");
    printf("3. Exit\n");
    scanf("%c", &choice);

    while (choice!= '3') {
        switch (choice) {
            case '1':
                printf("Enter number of items: ");
                scanf("%d", &num_items);
                for (i = 0; i < num_items; i++) {
                    printf("Enter item %d name: ", i+1);
                    scanf("%s", items[i].name);
                    printf("Enter item %d price: ", i+1);
                    scanf("%f", &items[i].price);
                    total += items[i].price;
                }
                printf("Your order total is: $%.2f\n", total);
                break;
            case '2':
                printf("Menu:\n");
                for (i = 0; i < num_items; i++) {
                    printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Order\n");
        printf("2. View menu\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
    }

    return 0;
}