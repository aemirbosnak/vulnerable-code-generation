//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: real-life
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

void add_item(item *items, int count, char *name, char *amount) {
    if (count >= MAX_ITEMS) {
        printf("Error: Too many items!\n");
        return;
    }

    strcpy(items[count].name, name);
    strcpy(items[count].amount, amount);

    printf("Item added: %s - $%.2f\n", items[count].name, atof(items[count].amount));
}

void display_items(item *items, int count) {
    printf("\nItems:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, atof(items[i].amount));
    }
}

void calculate_total(item *items, int count) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += atof(items[i].amount);
    }

    printf("\nTotal: $%.2f\n", total);
}

int main() {
    item items[MAX_ITEMS];
    int count = 0;

    printf("Expense Tracker\n");
    while (count < MAX_ITEMS) {
        printf("\nEnter item name: ");
        scanf("%s", items[count].name);

        printf("Enter item amount: $");
        scanf("%s", items[count].amount);

        add_item(items, count, items[count].name, items[count].amount);
        count++;
    }

    printf("\nItems:\n");
    display_items(items, count);

    calculate_total(items, count);

    return 0;
}