//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_AMOUNT_LENGTH 20

struct item {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
};

void add_item(struct item* items, int num_items, char* name, char* category, char* amount) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Cannot add more items.\n");
        return;
    }

    strncpy(items[num_items].name, name, MAX_NAME_LENGTH);
    strncpy(items[num_items].category, category, MAX_CATEGORY_LENGTH);
    strncpy(items[num_items].amount, amount, MAX_AMOUNT_LENGTH);

    num_items++;
}

void print_items(struct item* items, int num_items) {
    printf("Item\tCategory\tAmount\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%s\t%s\n", items[i].name, items[i].category, items[i].amount);
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Post-Apocalyptic Expense Tracker!\n");
    printf("You can add items to track your expenses.\n");

    while (1) {
        printf("Enter 1 to add an item or 0 to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == '0') {
            break;
        }

        char name[MAX_NAME_LENGTH];
        char category[MAX_CATEGORY_LENGTH];
        char amount[MAX_AMOUNT_LENGTH];

        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter item category: ");
        scanf("%s", category);
        printf("Enter item amount: ");
        scanf("%s", amount);

        add_item(items, num_items, name, category, amount);
    }

    print_items(items, num_items);

    return 0;
}