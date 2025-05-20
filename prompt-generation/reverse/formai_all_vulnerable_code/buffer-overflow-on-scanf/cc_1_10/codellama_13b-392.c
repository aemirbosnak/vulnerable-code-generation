//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

void print_menu(Item items[], int n_items) {
    for (int i = 0; i < n_items; i++) {
        printf("%d. %s\n", i + 1, items[i].name);
    }
}

void purchase_item(Item items[], int n_items, char *name) {
    for (int i = 0; i < n_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("You purchased %s for $%.2f\n", items[i].name, items[i].price);
            break;
        }
    }
}

int main() {
    Item items[MAX_ITEMS] = {
        {"Apple", 0.50},
        {"Orange", 0.75},
        {"Banana", 0.35},
        {"Chocolate Bar", 0.65},
        {"Candy", 0.45},
        {"Coffee", 1.00},
        {"Tea", 0.50},
        {"Milk", 0.75},
        {"Bread", 1.25},
        {"Eggs", 2.00},
    };

    int n_items = sizeof(items) / sizeof(items[0]);

    print_menu(items, n_items);

    char name[MAX_NAME_LEN];
    printf("Enter the name of the item you want to purchase: ");
    scanf("%s", name);

    purchase_item(items, n_items, name);

    return 0;
}