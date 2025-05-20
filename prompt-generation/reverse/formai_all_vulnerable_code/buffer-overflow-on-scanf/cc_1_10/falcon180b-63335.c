//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float price;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;
    float total = 0.0;

    while(numItems < MAX_ITEMS) {
        printf("Enter the name of an item: ");
        scanf("%s", items[numItems].name);
        printf("Enter the price of %s: ", items[numItems].name);
        scanf("%f", &items[numItems].price);
        numItems++;
    }

    printf("\nWelcome to the Cafe!\n");

    while(1) {
        printf("\nWhat would you like to order?\n");
        for(int i = 0; i < numItems; i++) {
            printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
        }
        printf("%d. Exit\n", numItems+1);

        int choice;
        scanf("%d", &choice);

        if(choice == numItems+1) {
            printf("\nThank you for visiting our cafe!\n");
            break;
        }

        if(choice < 1 || choice > numItems) {
            printf("\nInvalid choice.\n");
            continue;
        }

        printf("\nYou ordered %s for $%.2f.\n", items[choice-1].name, items[choice-1].price);
        total += items[choice-1].price;
    }

    printf("\nYour total bill is $%.2f.\n", total);

    return 0;
}