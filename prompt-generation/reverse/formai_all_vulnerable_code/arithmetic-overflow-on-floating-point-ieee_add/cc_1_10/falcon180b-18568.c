//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char *name;
    float amount;
} item_t;

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;
    float total_amount = 0.0;
    char input[100];

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your income and expenses:\n");

    while (fgets(input, 100, stdin)!= NULL) {
        char *pos = strchr(input, ':');
        if (pos == NULL) {
            printf("Invalid input: %s\n", input);
            continue;
        }
        *pos = '\0';

        char *name = input;
        float amount = atof(pos + 1);

        if (num_items >= MAX_ITEMS) {
            printf("Too many items, please remove some before adding more.\n");
            continue;
        }

        items[num_items] = (item_t) {
           .name = strdup(name),
           .amount = amount
        };
        num_items++;
        total_amount += amount;
    }

    printf("\nSummary:\n");
    printf("Total income: $%.2f\n", total_amount);
    printf("Expenses:\n");

    for (int i = 0; i < num_items; i++) {
        printf("  %s: $%.2f\n", items[i].name, items[i].amount);
    }

    for (int i = 0; i < num_items; i++) {
        free(items[i].name);
    }
    free(items);

    return 0;
}