//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int price;
    time_t date;
} Item;

void addItem(Item *items, int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item price: ");
    scanf("%d", &items[numItems].price);
    printf("Enter purchase date (YYYY-MM-DD): ");
    scanf("%s", items[numItems].date);
    printf("\n");
}

void displayItems(Item *items, int numItems) {
    printf("Item Name\tPrice\tPurchase Date\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t%s\n", items[i].name, items[i].price, ctime(&items[i].date));
    }
}

void sortItems(Item *items, int numItems) {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = i + 1; j < numItems; j++) {
            if (items[i].price > items[j].price) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the futuristic expense tracker!\n\n");

    while (numItems < MAX_ITEMS) {
        printf("Enter 1 to add an item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            addItem(items, numItems);
            numItems++;
        } else if (choice!= 0) {
            printf("Invalid input.\n");
        }
    }

    printf("\nSorting items by price...\n");
    sortItems(items, numItems);

    printf("\nDisplaying items in order of price:\n");
    displayItems(items, numItems);

    return 0;
}