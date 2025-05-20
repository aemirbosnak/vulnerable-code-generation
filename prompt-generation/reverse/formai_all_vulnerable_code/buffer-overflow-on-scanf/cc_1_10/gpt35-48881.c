//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>

// Define constant values for different types of expenses
#define HOUSING 1
#define FOOD 2
#define TRANSPORTATION 3
#define UTILITIES 4
#define ENTERTAINMENT 5
#define HEALTH_CARE 6
#define INSURANCE 7
#define SAVINGS 8
#define OTHER 9

// Define a struct to hold each expense
struct Expense {
    char name[100];
    double amount;
    int type;
};

// Define a function to calculate the total amount spent in a given category
double calculateTotal(struct Expense expenses[], int numExpenses, int type) {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (expenses[i].type == type) {
            total += expenses[i].amount;
        }
    }
    return total;
}

int main() {
    // Define an array to store up to 100 expenses
    struct Expense expenses[100];
    int numExpenses = 0;

    // Loop to collect expense information from the user
    while (1) {
        printf("Enter the name of your expense (or \"stop\" if you're done): ");
        scanf("%s", expenses[numExpenses].name);
        if (strcmp(expenses[numExpenses].name, "stop") == 0) {
            break;
        }

        printf("Enter the amount of the expense: ");
        scanf("%lf", &expenses[numExpenses].amount);

        printf("Select the type of expense (1 - Housing, 2 - Food, 3 - Transportation, 4 - Utilities, 5 - Entertainment, 6 - Health Care, 7 - Insurance, 8 - Savings, 9 - Other): ");
        scanf("%d", &expenses[numExpenses].type);

        numExpenses++;
    }

    // Print out a summary of expenses by category
    printf("Expense Summary:\n");
    printf("Housing: $%.2f\n", calculateTotal(expenses, numExpenses, HOUSING));
    printf("Food: $%.2f\n", calculateTotal(expenses, numExpenses, FOOD));
    printf("Transportation: $%.2f\n", calculateTotal(expenses, numExpenses, TRANSPORTATION));
    printf("Utilities: $%.2f\n", calculateTotal(expenses, numExpenses, UTILITIES));
    printf("Entertainment: $%.2f\n", calculateTotal(expenses, numExpenses, ENTERTAINMENT));
    printf("Health Care: $%.2f\n", calculateTotal(expenses, numExpenses, HEALTH_CARE));
    printf("Insurance: $%.2f\n", calculateTotal(expenses, numExpenses, INSURANCE));
    printf("Savings: $%.2f\n", calculateTotal(expenses, numExpenses, SAVINGS));
    printf("Other: $%.2f\n", calculateTotal(expenses, numExpenses, OTHER));

    return 0;
}