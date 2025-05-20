//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

int num_items = 0;
item items[MAX_ITEMS];

void add_item(char *name, char *price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    strncpy(items[num_items].name, name, MAX_NAME_LEN);
    strncpy(items[num_items].price, price, MAX_PRICE_LEN);

    num_items++;
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, atof(items[i].price));
    }
}

void calculate_total() {
    double total = 0.0;

    for (int i = 0; i < num_items; i++) {
        total += atof(items[i].price);
    }

    printf("\nTotal: $%.2f\n", total);
}

int main() {
    while (1) {
        printf("Enter an option:\n");
        printf("1. Add item\n");
        printf("2. Print items\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char name[MAX_NAME_LEN];
                char price[MAX_PRICE_LEN];

                printf("Enter item name:\n");
                scanf("%s", name);

                printf("Enter item price:\n");
                scanf("%s", price);

                add_item(name, price);
                break;
            }
        case 2:
            {
                print_items();
                break;
            }
        case 3:
            {
                calculate_total();
                break;
            }
        case 4:
            {
                exit(0);
            }
        default:
            {
                printf("Invalid option.\n");
            }
        }
    }

    return 0;
}