//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// define constants
#define MAX_SIZE 100
#define FILE_NAME "expense.txt"

// define functions
void add_expense(int num_expenses, float expenses[]);
void display_expenses(int num_expenses, float expenses[]);
float calculate_total(int num_expenses, float expenses[]);
void save_expenses(int num_expenses, float expenses[]);

int main() {
    float expenses[MAX_SIZE]; // array to store expenses
    int num_expenses = 0; // number of expenses entered so far

    // load expenses from file if it exists
    FILE *fp;
    fp = fopen(FILE_NAME, "r");
    if (fp != NULL) {
        float expense;
        while (fscanf(fp, "%f", &expense) == 1) {
            expenses[num_expenses++] = expense;
        }
        fclose(fp);
    }

    // print welcome message
    printf("Welcome to the Expense Tracker!\n");

    // loop until user quits
    char choice;
    while (1) {
        // print menu options
        printf("\nWhat would you like to do?\n");
        printf("  1. Add an Expense\n");
        printf("  2. Display Expenses\n");
        printf("  3. Calculate Total Expenses\n");
        printf("  4. Save Expenses to File\n");
        printf("  q. Quit\n");

        // get user choice
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // handle user choice
        switch(choice) {
            case '1':
                add_expense(num_expenses, expenses);
                num_expenses++;
                break;
            case '2':
                display_expenses(num_expenses, expenses);
                break;
            case '3':
                printf("Total expenses: $%.2f\n", calculate_total(num_expenses, expenses));
                break;
            case '4':
                save_expenses(num_expenses, expenses);
                printf("Expenses saved to file!\n");
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_expense(int num_expenses, float expenses[]) {
    // check if array is full
    if (num_expenses == MAX_SIZE) {
        printf("Cannot add more expenses. Array is full.\n");
        return;
    }

    // prompt user for expense amount
    float expense;
    printf("Enter expense amount: $");
    scanf("%f", &expense);

    // add expense to array
    expenses[num_expenses] = expense;

    printf("Expense added!\n");
}

void display_expenses(int num_expenses, float expenses[]) {
    if (num_expenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("$%.2f\n", expenses[i]);
    }
}

float calculate_total(int num_expenses, float expenses[]) {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i];
    }
    return total;
}

void save_expenses(int num_expenses, float expenses[]) {
    FILE *fp;
    fp = fopen(FILE_NAME, "w");
    for (int i = 0; i < num_expenses; i++) {
        fprintf(fp, "%.2f\n", expenses[i]);
    }
    fclose(fp);
}