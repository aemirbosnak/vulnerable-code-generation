//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char description[101];
    double amount;
} ExpenseEntry;

int main() {
    ExpenseEntry entries[MAX_ENTRIES];
    int entryCount = 0;
    double totalExpense = 0.0;

    while (1) {
        printf("Enter expense date (YYYY/MM/DD): ");
        scanf("%s", entries[entryCount].date);

        printf("Enter expense description: ");
        scanf(" %[^\n]", entries[entryCount].description);

        printf("Enter expense amount: ");
        scanf("%lf", &entries[entryCount].amount);

        totalExpense += entries[entryCount].amount;
        entryCount++;

        char choice;
        printf("Do you want to add another expense? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            break;
        } else if (entryCount == MAX_ENTRIES) {
            printf("You have reached the maximum number of entries.\n");
            break;
        }
    }

    printf("\n\nExpense Report\n");
    printf("------------------------------------\n");
    printf("  Date        Description      Amount\n");
    printf("------------------------------------\n");

    for (int i = 0; i < entryCount; i++) {
        printf(" %s  %s  %.2lf\n", entries[i].date, entries[i].description, entries[i].amount);
    }

    printf("------------------------------------\n");
    printf(" Total Expense: %.2lf\n", totalExpense);

    return 0;
}