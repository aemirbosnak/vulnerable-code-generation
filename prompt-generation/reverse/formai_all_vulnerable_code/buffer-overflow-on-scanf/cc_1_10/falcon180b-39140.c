//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
} Item;

int main() {
    int numItems;
    Item items[MAX_ITEMS];
    float totalPrice = 0;
    char input[100];

    printf("Welcome to the Cafe Billing System!\n");

    // Get number of items from user
    printf("How many items do you want to order? ");
    scanf("%d", &numItems);

    // Get item information from user
    for (int i = 0; i < numItems; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter item description: ");
        scanf("%s", items[i].description);
        printf("Enter item price: ");
        scanf("%f", &items[i].price);
    }

    // Display item information and total price
    printf("\nOrder Summary:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", i+1);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Price: $%.2f\n\n", items[i].price);
        totalPrice += items[i].price;
    }

    printf("\nTotal Price: $%.2f\n", totalPrice);

    return 0;
}