//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_AMOUNT_LENGTH 10
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
    char date[MAX_DATE_LENGTH];
} expense_item;

void add_item(expense_item *items, int *num_items) {
    printf("Enter expense item name: ");
    scanf("%s", &items[*num_items].name);
    printf("Enter expense item description: ");
    scanf("%s", &items[*num_items].description);
    printf("Enter expense item category: ");
    scanf("%s", &items[*num_items].category);
    printf("Enter expense item amount: ");
    scanf("%s", &items[*num_items].amount);
    printf("Enter expense item date: ");
    scanf("%s", &items[*num_items].date);

    (*num_items)++;
}

void print_item(expense_item item) {
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Category: %s\n", item.category);
    printf("Amount: %s\n", item.amount);
    printf("Date: %s\n", item.date);
}

void print_items(expense_item items[], int num_items) {
    printf("Expense Items:\n");
    for (int i = 0; i < num_items; i++) {
        print_item(items[i]);
    }
}

int main() {
    expense_item items[MAX_ITEMS];
    int num_items = 0;

    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    print_items(items, num_items);

    return 0;
}