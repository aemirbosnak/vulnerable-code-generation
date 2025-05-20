//Falcon-180B DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 1000
#define MAX_LENGTH 100

struct item {
    char name[MAX_LENGTH];
    int price;
};

int compare_prices(const void *a, const void *b) {
    struct item *item1 = (struct item *)a;
    struct item *item2 = (struct item *)b;

    if (item1->price < item2->price) {
        return -1;
    } else if (item1->price == item2->price) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    srand(time(NULL));

    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        char name[MAX_LENGTH];
        int price;

        printf("Enter item name: ");
        scanf("%s", name);

        printf("Enter item price: ");
        scanf("%d", &price);

        strcpy(items[num_items].name, name);
        items[num_items].price = price;

        num_items++;
    }

    qsort(items, num_items, sizeof(struct item), compare_prices);

    printf("Sorted items by price:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s: $%d\n", items[i].name, items[i].price);
    }

    return 0;
}