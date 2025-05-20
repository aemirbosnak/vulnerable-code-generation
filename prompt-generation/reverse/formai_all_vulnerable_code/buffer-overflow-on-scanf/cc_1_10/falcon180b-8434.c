//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

int main() {
    int num_items, i;
    item items[MAX_ITEMS];

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter item price: ");
        scanf("%s", items[i].price);
    }

    printf("Enter order:\n");

    char order[100];
    scanf("%s", order);

    int total_price = 0;
    int num_items_ordered = 0;

    for (i = 0; i < strlen(order); i++) {
        if (isalpha(order[i])) {
            int j;
            for (j = 0; j < num_items; j++) {
                if (strcasecmp(items[j].name, order[i]) == 0) {
                    printf("%s: $%s\n", items[j].name, items[j].price);
                    total_price += atoi(items[j].price);
                    num_items_ordered++;
                    break;
                }
            }
        }
    }

    printf("Total price: $%d\n", total_price);
    printf("Number of items ordered: %d\n", num_items_ordered);

    return 0;
}