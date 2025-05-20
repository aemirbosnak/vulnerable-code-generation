//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Item;

int main() {
    int numItems;
    scanf("%d", &numItems);

    Item items[MAX_ITEMS];
    for (int i = 0; i < numItems; i++) {
        strcpy(items[i].name, "");
        strcpy(items[i].category, "");
        strcpy(items[i].description, "");
        items[i].quantity = 0;
        items[i].price = 0;
    }

    for (int i = 0; i < numItems; i++) {
        printf("Enter item %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Category: ");
        scanf("%s", items[i].category);
        printf("Description: ");
        scanf("%s", items[i].description);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price: ");
        scanf("%lf", &items[i].price);
    }

    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %s (%d @ $%.2f)\n", i+1, items[i].name, items[i].category, items[i].quantity, items[i].price);
    }

    return 0;
}