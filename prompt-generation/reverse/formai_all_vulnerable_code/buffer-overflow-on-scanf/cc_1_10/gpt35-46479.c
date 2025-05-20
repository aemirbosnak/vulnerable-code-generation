//FormAI DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>

// function to display menu options
void displayMenu() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please select an option from the menu below:\n");
    printf("1. Add an expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    float expenses[100]; // maximum number of expenses is 100
    int numExpenses = 0; // initialize number of expenses to 0

    printf("Thank you for choosing to use our Expense Tracker!\n");

    do {
        displayMenu();
        scanf("%d", &choice); // get user input for menu choice

        switch(choice) {
            case 1:
                {
                    float expense;
                    printf("Enter the expense amount: ");
                    scanf("%f", &expense);
                    expenses[numExpenses] = expense;
                    numExpenses++;
                    printf("Expense added successfully!\n\n");
                }
                break;
            case 2:
                {
                    printf("Expenses:\n");
                    for(int i=0; i<numExpenses; i++) {
                        printf("%.2f\n", expenses[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("Thank you for using the Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    } while(choice != 3);

    return 0;
}