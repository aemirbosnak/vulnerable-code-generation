//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} item;

void add_item(item* items, int num_items) {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];

    printf("Enter the name of the item: ");
    scanf("%s", name);

    printf("Enter the amount of the item: ");
    scanf("%s", amount);

    strcpy(items[num_items].name, name);
    strcpy(items[num_items].amount, amount);

    num_items++;
}

void print_items(item* items, int num_items) {
    int i;

    for (i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, atof(items[i].amount));
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Would you like to add an item? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            add_item(items, num_items);
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    printf("Items added:\n");
    print_items(items, num_items);

    return 0;
}