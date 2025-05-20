//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to get user input for expenses
float getExpense(char* expenseType) {
    float expense;

    printf("Enter your %s expense: ", expenseType);
    scanf("%f", &expense);

    return expense;
}

// Function to display a random joke
void tellJoke() {
    int jokeNum = rand() % 5;

    switch(jokeNum) {
        case 0:
            printf("\nWhy did the programmer quit his job? He didn't get arrays!\n");
            break;
        case 1:
            printf("\nWhy do programmers prefer dark mode? Less watts mean less bugs!\n");
            break;
        case 2:
            printf("\nWhy do programmers use Github? Because they don't have CVS!\n");
            break;
        case 3:
            printf("\nWhy do programmers prefer dark chocolate? It's byte-sized!\n");
            break;
        case 4:
            printf("\nWhy don't programmers get lost in the wilderness? They always follow the binary tree!\n");
            break;
        default:
            printf("\nWhy don't programmers tell jokes in octal? Because 7 10 11!\n");
            break;
    }
}

int main() {
    // Starting balance
    float balance = 5000;
    float totalExpenses = 0;
    int numExpenses = 0;

    // Welcome message
    printf("\nWelcome to the C Expense Tracker!\n");

    // Loop until the user decides to quit
    char cont = 'y';
    while (cont == 'y') {
        // Get user input for expense type and amount
        char expenseType[20];
        float expenseAmt;

        printf("\nWhat type of expense was it?\n");
        scanf("%s", expenseType);

        expenseAmt = getExpense(expenseType);
        totalExpenses += expenseAmt;
        numExpenses++;

        // Display information about the expenses so far
        printf("\nBalance: $%.2f\n", balance);
        printf("Total expenses: $%.2f\n", totalExpenses);
        printf("Number of expenses: %d\n", numExpenses);

        // Display a random joke to lighten the mood
        tellJoke();

        // Ask the user if they want to continue tracking expenses
        printf("\nWould you like to continue (y/n)? ");
        scanf(" %c", &cont);
    }

    printf("\nThank you for using the C Expense Tracker!\n");

    return 0;
}