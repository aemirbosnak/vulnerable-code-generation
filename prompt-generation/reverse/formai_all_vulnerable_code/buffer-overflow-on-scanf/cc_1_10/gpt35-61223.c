//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
// The Expense Tracker: A Tragic Love Story

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses and characters allowed for each string
#define MAX_EXPENSES 50
#define MAX_DESC_LEN 50
#define MAX_CAT_LEN 20

// Define the structure for each expense
struct expense {
    char description[MAX_DESC_LEN];
    char category[MAX_CAT_LEN];
    double amount;
};

// Define the function to input expenses
int input_expense(struct expense *expenses, int count);

// Define the function to output expenses
void output_expenses(struct expense *expenses, int count);

int main() {
    // Declare the array of expenses and the count variable
    struct expense expenses[MAX_EXPENSES];
    int count = 0;

    // Prompt the user to input expenses or exit the program
    printf("Welcome to The Expense Tracker!\n");
    printf("Press 1 to input expenses, 2 to output expenses, or 3 to exit the program.\n");
    int choice = 0;
    scanf("%d", &choice);

    while (choice != 3) {
        switch (choice) {
            case 1:
                // Input expenses and increment the count
                count += input_expense(&expenses[count], MAX_EXPENSES - count);
                break;
            case 2:
                // Output expenses
                output_expenses(expenses, count);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Prompt the user to input expenses or exit the program again
        printf("Press 1 to input expenses, 2 to output expenses, or 3 to exit the program.\n");
        scanf("%d", &choice);
    }

    // Exit the program
    printf("Farewell, dear user! May your expenses be forever tracked.\n");
    return 0;
}

int input_expense(struct expense *expenses, int count) {
    // Declare the local count variable
    int local_count = 0;

    // Input expenses until the maximum number of expenses is reached or the user inputs "done"
    while (local_count < count) {
        printf("Please input the description of Expense #%d or type \"done\".\n", local_count + 1);
        scanf("%s", expenses[local_count].description);

        if (!strcmp(expenses[local_count].description, "done")) {
            break;
        }

        printf("Please input the category of Expense #%d.\n", local_count + 1);
        scanf("%s", expenses[local_count].category);

        printf("Please input the amount of Expense #%d.\n", local_count + 1);
        scanf("%lf", &expenses[local_count].amount);

        printf("Expense #%d successfully added!\n", local_count + 1);
        local_count++;
    }

    return local_count;
}

void output_expenses(struct expense *expenses, int count) {
    // Output the header
    printf("Description\tCategory\tAmount\n");

    // Output each expense
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t$%.2lf\n", expenses[i].description, expenses[i].category, expenses[i].amount);
    }
}