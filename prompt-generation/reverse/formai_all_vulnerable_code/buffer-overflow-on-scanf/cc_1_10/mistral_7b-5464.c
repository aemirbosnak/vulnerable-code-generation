//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to store expense details
struct Expense {
    char name[50];
    float amount;
    time_t time;
};

// Function to format the time
char* formatTime(time_t time) {
    struct tm* tmInfo = localtime(&time);
    char timeString[80];
    strftime(timeString, sizeof(timeString), "%d/%m/%Y %H:%M:%S", tmInfo);
    return strdup(timeString);
}

// Function to add an expense
void addExpense(struct Expense expenses[], int* size, const char* name, float amount) {
    if (*size >= 10) {
        printf("Oops! You've reached the maximum number of expenses.\n");
        return;
    }
    expenses[*size].amount = amount;
    strcpy(expenses[*size].name, name);
    expenses[*size].time = time(NULL);
    (*size)++;
}

// Function to print all expenses
void printExpenses(struct Expense expenses[], int size) {
    printf("\nExpenses:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
        printf("Time: %s\n", formatTime(expenses[i].time));
        printf("------------------------\n");
    }
}

int main() {
    struct Expense expenses[10];
    int size = 0;

    // Funny welcome message
    printf("*** Welcome to ExpenseTracker 3000! ***\n");
    printf("Please input your expenses in the following format:\n");
    printf("ExpenseName Amount\n");
    printf("For example: Ramen 5.99\n");

    while (1) {
        char name[50];
        float amount;
        scanf("%s %f", name, &amount);

        // Check for invalid input
        if (strlen(name) > 49) {
            printf("Whoa there, ExpenseName is too long! Try again.\n");
            continue;
        }

        addExpense(expenses, &size, name, amount);

        printf("Expense added successfully!\n");
        printf("Do you want to add another expense? (y/n)\n");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    printExpenses(expenses, size);

    return 0;
}