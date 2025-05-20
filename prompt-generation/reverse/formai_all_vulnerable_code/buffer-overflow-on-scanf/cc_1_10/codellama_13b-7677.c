//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char name[20];
    float amount;
    char date[10];
};

int main() {
    struct expense expenses[10];
    int num_expenses = 0;

    printf("Enter the name of the expense: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter the date of the expense (MM/DD/YYYY): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;

    printf("Enter another expense (y/n)? ");
    char answer;
    scanf(" %c", &answer);

    while (answer == 'y') {
        printf("Enter the name of the expense: ");
        scanf("%s", expenses[num_expenses].name);

        printf("Enter the amount of the expense: ");
        scanf("%f", &expenses[num_expenses].amount);

        printf("Enter the date of the expense (MM/DD/YYYY): ");
        scanf("%s", expenses[num_expenses].date);

        num_expenses++;

        printf("Enter another expense (y/n)? ");
        scanf(" %c", &answer);
    }

    printf("You have entered %d expenses.\n", num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %0.2f (%s)\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }

    return 0;
}