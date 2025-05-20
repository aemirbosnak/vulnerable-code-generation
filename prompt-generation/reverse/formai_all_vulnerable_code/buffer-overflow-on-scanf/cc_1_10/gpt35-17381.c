//FormAI DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100 // maximum number of expenses to track

// define structure for expense records
struct ExpenseRecord {
    char description[50];
    double amount;
    int day;
    int month;
    int year;
};

// function to input an expense record from the keyboard
void inputExpense(struct ExpenseRecord *record) {
    printf("Enter expense description: ");
    fgets(record->description, 50, stdin);
    printf("Enter expense amount: ");
    scanf("%lf", &record->amount);
    printf("Enter expense day: ");
    scanf("%d", &record->day);
    printf("Enter expense month: ");
    scanf("%d", &record->month);
    printf("Enter expense year: ");
    scanf("%d", &record->year);
    getchar(); // consume the newline character left over from scanf
}

// function to display an expense record
void displayExpense(struct ExpenseRecord *record) {
    printf("%02d/%02d/%4d - %-50s $%.2f\n", record->day, record->month, record->year, record->description, record->amount);
}

int main() {

    struct ExpenseRecord expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char choice;

    do {
        printf("Expense Tracker\n");
        printf("--------------\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);
        getchar(); // consume the newline character left over from scanf

        switch (choice) {
            case '1': // add expense
                if (numExpenses < MAX_EXPENSES) {
                    inputExpense(&expenses[numExpenses]);
                    numExpenses++;
                } else {
                    printf("Maximum number of expenses reached!\n");
                }
                break;
            case '2': // display all expenses
                if (numExpenses == 0) {
                    printf("No expenses to display!\n");
                } else {
                    printf("All Expenses\n");
                    printf("------------\n");
                    for (int i = 0; i < numExpenses; i++) {
                        displayExpense(&expenses[i]);
                    }
                }
                break;
            case '3': // quit
                printf("Goodbye!\n");
                break;
            default: // invalid choice
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");

    } while (choice != '3');

    return 0;
}