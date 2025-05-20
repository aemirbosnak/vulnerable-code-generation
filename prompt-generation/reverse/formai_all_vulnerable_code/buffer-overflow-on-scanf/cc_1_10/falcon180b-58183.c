//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense_t;

int main() {
    int num_items = 0;
    expense_t expenses[MAX_ITEMS];

    while (1) {
        printf("Enter expense name: ");
        scanf("%s", expenses[num_items].name);

        printf("Enter expense category: ");
        scanf("%s", expenses[num_items].category);

        printf("Enter expense amount: ");
        scanf("%s", expenses[num_items].amount);

        if (strlen(expenses[num_items].amount) <= 0) {
            printf("Invalid expense amount. Please try again.\n");
            continue;
        }

        if (strlen(expenses[num_items].category) <= 0) {
            printf("Invalid expense category. Please try again.\n");
            continue;
        }

        if (num_items >= MAX_ITEMS) {
            printf("Maximum number of items reached. Please delete an item to add a new one.\n");
            continue;
        }

        num_items++;
        printf("Expense added successfully.\n");
    }

    return 0;
}