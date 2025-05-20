//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    int year;
    double price;
} Item;

int compare(const void *a, const void *b) {
    return ((Item *)b)->price - ((Item *)a)->price;
}

int main() {
    Item *items = NULL;
    int num_items = 0;
    int max_items = 10;

    items = (Item *)malloc(max_items * sizeof(Item));

    while (1) {
        char title[100];
        char author[100];
        int year;
        double price;

        printf("Enter item title (or 'done' to exit): ");
        scanf("%s", title);

        if (strcmp(title, "done") == 0) {
            break;
        }

        printf("Enter item author: ");
        scanf("%s", author);

        printf("Enter item year: ");
        scanf("%d", &year);

        printf("Enter item price: ");
        scanf("%lf", &price);

        if (num_items == max_items) {
            max_items *= 2;
            items = realloc(items, max_items * sizeof(Item));
        }

        strcpy(items[num_items].title, title);
        strcpy(items[num_items].author, author);
        items[num_items].year = year;
        items[num_items].price = price;

        num_items++;
    }

    qsort(items, num_items, sizeof(Item), compare);

    printf("\nAuction Results:\n");
    printf("-----------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s by %s, %d, $%.2f\n", items[i].title, items[i].author, items[i].year, items[i].price);
    }

    free(items);

    return 0;
}