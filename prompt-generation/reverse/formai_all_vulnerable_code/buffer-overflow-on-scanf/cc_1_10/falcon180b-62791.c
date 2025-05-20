//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_QUANTITY_LENGTH 10
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char quantity[MAX_QUANTITY_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item_t;

int main() {
    int num_items = 0;
    item_t items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter name of item (%d characters or less): ", MAX_NAME_LENGTH - 1);
        scanf("%s", items[num_items].name);

        printf("Enter description of item (%d characters or less): ", MAX_DESCRIPTION_LENGTH - 1);
        scanf("%s", items[num_items].description);

        printf("Enter category of item (%d characters or less): ", MAX_CATEGORY_LENGTH - 1);
        scanf("%s", items[num_items].category);

        printf("Enter quantity of item: ");
        scanf("%s", items[num_items].quantity);

        printf("Enter price of item: ");
        scanf("%s", items[num_items].price);

        num_items++;
    }

    printf("\nExpense Tracker\n");
    printf("================\n");

    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Category: %s\n", items[i].category);
        printf("Quantity: %s\n", items[i].quantity);
        printf("Price: %s\n", items[i].price);
        printf("\n");
    }

    return 0;
}