//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} Item;

void addItem(Item* items, int* numItems) {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];

    printf("Enter the name of the item: ");
    scanf("%s", name);
    printf("Enter the amount of the item: ");
    scanf("%s", amount);

    strcpy(items[*numItems].name, name);
    strcpy(items[*numItems].amount, amount);

    (*numItems)++;
}

void displayItems(Item* items, int numItems) {
    printf("\nItem\tAmount\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%s\n", items[i].name, items[i].amount);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("\nWelcome to the Medieval Expense Tracker!\n");
    printf("Enter 'add' to add an item or 'display' to display items.\n");

    while (1) {
        char choice[MAX_NAME_LEN];
        scanf("%s", choice);

        if (strcmp(choice, "add") == 0) {
            addItem(items, &numItems);
        } else if (strcmp(choice, "display") == 0) {
            displayItems(items, numItems);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}