//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    double cost;
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter the name of the item (or type 'done' to finish): ");
        char input[100];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        Item* current_item = &items[num_items];
        strcpy(current_item->name, input);
        printf("Enter the cost of the item: ");
        scanf("%lf", &current_item->cost);

        num_items++;
    }

    printf("\nEnter the name of the item you want to track expenses for: ");
    char search_item[MAX_NAME_LEN];
    fgets(search_item, sizeof(search_item), stdin);

    int found_item = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, search_item) == 0) {
            found_item = 1;
            break;
        }
    }

    if (!found_item) {
        printf("Item not found.\n");
        return 1;
    }

    double total_cost = 0;
    while (1) {
        printf("\nEnter the cost of the %s (or type 'done' to finish): ", search_item);
        char input[100];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        double cost = strtod(input, NULL);
        total_cost += cost;
    }

    printf("\nTotal cost for %s: $%.2f\n", search_item, total_cost);

    return 0;
}