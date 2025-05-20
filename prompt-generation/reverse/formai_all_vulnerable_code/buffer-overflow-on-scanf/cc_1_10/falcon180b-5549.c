//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 20
#define MAX_DESCRIPTION_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int price;
} Item;

void add_item(Item items[], int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the description of the item: ");
    scanf("%s", items[num_items].description);
    printf("Enter the price of the item: ");
    scanf("%d", &items[num_items].price);
    num_items++;
}

void display_items(Item items[], int num_items) {
    printf("\nItem Name\t\t\tItem Description\t\tItem Price\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s\t\t\t%s\t\t\t\t$%d\n", items[i].name, items[i].description, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    printf("\nWelcome to the Cafe Billing System!\n");

    while (num_items < MAX_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_item(items, num_items);
        } else {
            break;
        }
    }

    if (num_items == 0) {
        printf("\nNo items added. Exiting program...\n");
        return 0;
    }

    printf("\n\nChoose an item:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\t\t\t$%d\n", i+1, items[i].name, items[i].price);
    }

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > num_items) {
        printf("\nInvalid choice. Exiting program...\n");
        return 0;
    }

    printf("\nYou chose item %s for $%d.\n", items[choice-1].name, items[choice-1].price);

    return 0;
}