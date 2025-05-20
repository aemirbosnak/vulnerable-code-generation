//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} item_t;

void add_item(item_t *items, int *num_items) {
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);
    printf("Enter item amount: ");
    scanf("%s", items[*num_items].amount);
    (*num_items)++;
}

void remove_item(item_t *items, int *num_items) {
    printf("Enter item index to remove: ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < *num_items) {
        memmove(&items[index], &items[index+1], sizeof(item_t) * (*num_items - index - 1));
        (*num_items)--;
    } else {
        printf("Invalid index.\n");
    }
}

void print_items(item_t *items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - %s\n", i+1, items[i].name, items[i].amount);
    }
}

void main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("Personal Finance Planner\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Print items\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                print_items(items, num_items);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}