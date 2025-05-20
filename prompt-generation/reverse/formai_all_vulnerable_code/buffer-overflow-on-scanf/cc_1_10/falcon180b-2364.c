//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct item {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
};

void add_item(struct item* items, int count, char* name, char* price) {
    if (count >= MAX_ITEMS) {
        printf("Elementary, my dear Watson! The list is full.\n");
        return;
    }

    strcpy(items[count].name, name);
    strcpy(items[count].price, price);

    printf("Item added successfully, Watson.\n");
}

void display_items(struct item* items, int count) {
    if (count == 0) {
        printf("The list is empty, Watson.\n");
        return;
    }

    printf("Item\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", items[i].name, items[i].price);
    }
}

void calculate_total_cost(struct item* items, int count) {
    if (count == 0) {
        printf("There are no items in the list, Watson.\n");
        return;
    }

    float total_cost = 0;
    for (int i = 0; i < count; i++) {
        total_cost += atof(items[i].price);
    }

    printf("The total cost of the items is £%.2f, Watson.\n", total_cost);
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    while (1) {
        printf("1. Add item\n2. Display items\n3. Calculate total cost\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                char price[MAX_PRICE_LEN];

                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: ");
                scanf("%s", price);

                add_item(items, count, name, price);
                break;
            }
            case 2: {
                display_items(items, count);
                break;
            }
            case 3: {
                calculate_total_cost(items, count);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice, Watson.\n");
            }
        }
    }

    return 0;
}