//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50

struct Item {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    float price;
};

void print_item(struct Item item) {
    printf("Name: %s\n", item.name);
    printf("Category: %s\n", item.category);
    printf("Price: $%.2f\n\n", item.price);
}

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    struct Item items[MAX_ITEMS];
    int curr_item = 0;

    while (curr_item < num_items) {
        printf("Item %d:\n", curr_item + 1);
        printf("Name: ");
        scanf("%s", items[curr_item].name);
        printf("Category: ");
        scanf("%s", items[curr_item].category);
        printf("Price: ");
        scanf("%f", &items[curr_item].price);

        printf("\n");
        curr_item++;
    }

    printf("Total items: %d\n", num_items);
    printf("Total cost: $%.2f\n", 0.0); // initialize total cost

    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        print_item(items[i]);
        printf("Total cost: $%.2f\n\n", 0.0); // initialize total cost for each item
    }

    return 0;
}