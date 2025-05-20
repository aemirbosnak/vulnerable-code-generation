//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100
#define MAX_DESC 50

// Structure to hold expense data
typedef struct Expense {
    char description[MAX_DESC];
    float amount;
} Expense;

// Function prototypes
void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void printSummary(Expense expenses[], int count);

int main() {
    Expense expenses[MAX_EXPENSES]; // Array to hold expenses
    int count = 0; // Count of expenses
    int choice;

    printf("Welcome to the Squirrel Expense Tracker!\n");
    printf("Where every acorn (cents) counts!\n");
    printf("Ready to make your financial status a little nutty?\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add an expense\n");
        printf("2. View expenses\n");
        printf("3. Print summary\n");
        printf("4. Exit (make the squirrel sad)\n");
        
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printSummary(expenses, count);
                break;
            case 4:
                printf("Goodbye! Don't forget to save some nuts!\n");
                exit(0);
            default:
                printf("Oops! That wasn't an option. Try again!\n");
        }
    }

    return 0;
}

// Function to add expense
void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Whoa there! You are spending like a buffet lover! Can't add more expenses!\n");
        return;
    }

    printf("Enter a description for your expense (Please limit it to %d characters): ", MAX_DESC - 1);
    scanf(" %[^\n]", expenses[*count].description); // Read string with spaces
    printf("How much did you spend (in acorns)? ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added! A hidden stash was ransacked.\n");
}

// Function to view expenses
void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses logged yet. Looks like you're a responsible squirrel!\n");
        return;
    }

    printf("Here are your recorded expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2f acorns!\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

// Function to print summary
void printSummary(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to summarize! Keep hoarding your acorns wisely!\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("You've spent a total of %.2f acorns on %d adventures!\n", total, count);
    printf("Your squirrel heart should now evaluate: Did I need all that?\n");
}