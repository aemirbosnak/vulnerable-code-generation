//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double price;
} item_t;

int main() {
    int num_items = 0;
    item_t *items = malloc(MAX_ITEMS * sizeof(item_t));

    while (1) {
        printf("Enter item name (or leave blank to finish): ");
        char name[MAX_NAME_LEN];
        fgets(name, MAX_NAME_LEN, stdin);
        if (name[0] == '\0') {
            break;
        }

        printf("Enter item price: ");
        double price;
        if (scanf("%lf", &price)!= 1) {
            printf("Invalid price format\n");
            continue;
        }

        if (num_items >= MAX_ITEMS) {
            printf("Too many items, cannot add more\n");
            continue;
        }

        strcpy(items[num_items].name, name);
        items[num_items].price = price;
        num_items++;
    }

    printf("Expense tracker initialized with %d items.\n", num_items);

    while (1) {
        printf("Enter action (A to add item, D to delete item, P to print expenses, Q to quit): ");
        char action;
        if (scanf(" %c", &action)!= 1) {
            printf("Invalid action\n");
            continue;
        }

        switch (action) {
        case 'A':
            if (num_items >= MAX_ITEMS) {
                printf("Too many items, cannot add more\n");
            } else {
                printf("Enter item name: ");
                char name[MAX_NAME_LEN];
                fgets(name, MAX_NAME_LEN, stdin);

                printf("Enter item price: ");
                double price;
                if (scanf("%lf", &price)!= 1) {
                    printf("Invalid price format\n");
                    break;
                }

                strcpy(items[num_items].name, name);
                items[num_items].price = price;
                num_items++;
            }
            break;

        case 'D':
            if (num_items == 0) {
                printf("No items to delete\n");
            } else {
                printf("Enter item name to delete: ");
                char name[MAX_NAME_LEN];
                fgets(name, MAX_NAME_LEN, stdin);

                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, name) == 0) {
                        for (int j = i; j < num_items - 1; j++) {
                            items[j] = items[j + 1];
                        }
                        num_items--;
                        break;
                    }
                }
            }
            break;

        case 'P':
            printf("Expenses:\n");
            for (int i = 0; i < num_items; i++) {
                printf("%s: $%.2lf\n", items[i].name, items[i].price);
            }
            break;

        case 'Q':
            printf("Exiting program...\n");
            free(items);
            return 0;

        default:
            printf("Invalid action\n");
        }
    }
}