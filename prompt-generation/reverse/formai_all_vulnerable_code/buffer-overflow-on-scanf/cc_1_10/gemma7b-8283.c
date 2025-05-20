//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem {
    char name[50];
    int amount;
    time_t timestamp;
} ExpenseItem;

void write_expense(ExpenseItem item) {
    FILE *fp = fopen("expenses.txt", "a");
    fprintf(fp, "%s, %d, %ld\n", item.name, item.amount, item.timestamp);
    fclose(fp);
}

void main() {
    int num_items = 0;
    ExpenseItem items[MAX_EXPENSE_ITEMS];

    // Asynchronous loop to read expenses
    while (1) {
        char name[50];
        int amount;

        printf("Enter expense name: ");
        scanf("%s", name);

        printf("Enter expense amount: ");
        scanf("%d", &amount);

        time_t timestamp = time(NULL);

        ExpenseItem item = { .name = name, .amount = amount, .timestamp = timestamp };

        items[num_items++] = item;

        // Write the expense item to the file asynchronously
        write_expense(item);

        // Check if the user wants to continue
        char continue_yn;
        printf("Continue? (Y/N): ");
        scanf(" %c", &continue_yn);

        if (continue_yn == 'N') {
            break;
        }
    }

    // Print the list of expenses
    printf("List of expenses:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s, %d, %s\n", items[i].name, items[i].amount, ctime(&items[i].timestamp));
    }
}