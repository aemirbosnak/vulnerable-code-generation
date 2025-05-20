//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    time_t time;
} Expense;

int main() {
    int i, num_expenses = 0;
    Expense expenses[MAX_EXPENSES];

    printf("Welcome to the Ultimate Fun-tastic Expense Tracker 3000!\n");
    printf("Where your money goes to have a laugh instead of disappearing in a poof!\n");
    printf("Press ENTER to add an expense, or type 'quit' to exit.\n");

    while (1) {
        getchar(); // clear newline from buffer

        printf("Name of expense: ");
        scanf("%[^,],", expenses[num_expenses].name);
        getchar(); // consume comma

        printf("Amount spent ($): ");
        scanf("%f", &expenses[num_expenses].amount);

        printf("Description of expense (optional): ");
        gets(expenses[num_expenses].name + strlen(expenses[num_expenses].name));

        expenses[num_expenses].time = time(NULL);

        num_expenses++;

        if (num_expenses >= MAX_EXPENSES) {
            printf("Expense list is full! Clear some expenses or increase the size of the array.\n");
            break;
        }

        printf("Expense added: %s - $%.2f\n", expenses[num_expenses - 1].name, expenses[num_expenses - 1].amount);

        printf("Press ENTER to add another expense, or type 'quit' to exit.\n");
    }

    printf("\nExpense Report:\n");

    for (i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f, added on %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].time));
    }

    return 0;
}