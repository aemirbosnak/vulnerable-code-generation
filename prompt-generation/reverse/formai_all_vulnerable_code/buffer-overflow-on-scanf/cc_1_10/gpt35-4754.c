//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold expense information */
typedef struct {
    char date[11];
    char item[30];
    float cost;
} Expense;

int main() {
    Expense expenses[100]; // Array to hold up to 100 expenses
    int count = 0; // Counter for number of expenses entered
    char choice;

    while (1) {
        printf("Enter expense [Y/N]: ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            break;
        }

        // Prompt for date and store in expense struct
        printf("Enter date [mm/dd/yyyy]: ");
        scanf(" %s", expenses[count].date);

        // Prompt for item and store in expense struct
        printf("Enter item description: ");
        scanf(" %[^\n]s", expenses[count].item);

        // Prompt for cost and store in expense struct
        printf("Enter cost: ");
        scanf(" %f", &expenses[count].cost);

        count++;
    }

    // Print expense report
    printf("\n\nExpense Report\n");
    printf("==============\n");
    printf("Date        Item                          Cost\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s    %-30s $%.2f\n", expenses[i].date, expenses[i].item, expenses[i].cost);
    }

    return EXIT_SUCCESS;
}