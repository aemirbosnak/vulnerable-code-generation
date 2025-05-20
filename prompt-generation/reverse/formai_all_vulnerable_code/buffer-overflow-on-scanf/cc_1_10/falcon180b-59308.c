//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    float price;
} item_t;

int compare_items(const void *a, const void *b) {
    const item_t *item1 = (const item_t *)a;
    const item_t *item2 = (const item_t *)b;
    return strcmp(item1->name, item2->name);
}

void print_menu(item_t *menu, int num_items) {
    printf("---------------------\n");
    printf("Cafe Menu:\n");
    printf("---------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
}

int main() {
    item_t menu[MAX_ITEMS];
    int num_items = 0;
    char input[MAX_NAME_LEN];

    // Initialize menu
    strcpy(menu[0].name, "Coffee");
    strcpy(menu[0].category, "Beverages");
    menu[0].price = 2.50;
    num_items++;

    strcpy(menu[1].name, "Tea");
    strcpy(menu[1].category, "Beverages");
    menu[1].price = 2.00;
    num_items++;

    strcpy(menu[2].name, "Sandwich");
    strcpy(menu[2].category, "Food");
    menu[2].price = 5.50;
    num_items++;

    // Add more items here

    qsort(menu, num_items, sizeof(item_t), compare_items);

    printf("Welcome to the Cafe!\n");
    while (1) {
        printf("Enter your order:\n");
        scanf("%s", input);

        int found = 0;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(menu[i].name, input) == 0) {
                printf("You ordered %s for $%.2f\n", menu[i].name, menu[i].price);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Sorry, we don't have that item.\n");
        }
    }

    return 0;
}