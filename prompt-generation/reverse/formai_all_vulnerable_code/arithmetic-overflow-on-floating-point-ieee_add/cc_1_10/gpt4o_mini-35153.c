//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} UserProfile;

void calculateSavings(UserProfile *profile) {
    profile->savings = profile->income - profile->expenses;
}

void displayProfile(UserProfile profile) {
    printf("\n----- Personal Finance Summary -----\n");
    printf("Name: %s\n", profile.name);
    printf("Income: $%.2f\n", profile.income);
    printf("Expenses: $%.2f\n", profile.expenses);
    printf("Savings: $%.2f\n", profile.savings);
    printf("------------------------------------\n");
}

void addExpense(UserProfile *profile) {
    float expense;
    printf("Enter the amount of the expense: $");
    scanf("%f", &expense);
    profile->expenses += expense;
    printf("Expense of $%.2f added.\n", expense);
}

void adjustIncome(UserProfile *profile) {
    float incomeChange;
    printf("Enter the amount to change the income by: $");
    scanf("%f", &incomeChange);
    profile->income += incomeChange;
    printf("Income adjusted by $%.2f.\n", incomeChange);
}

void budgetOverview(UserProfile profile) {
    printf("\n----- Budget Overview -----\n");
    printf("Remaining budget (Income - Expenses): $%.2f\n", profile.income - profile.expenses);
    if (profile.savings < 0) {
        printf("Caution! You are over your budget!\n");
    } else {
        printf("Great job! You have savings of $%.2f\n", profile.savings);
    }
    printf("-----------------------------\n");
}

void writeBudgetToFile(UserProfile profile) {
    FILE *file = fopen("personal_budget.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    fprintf(file, "Name: %s\nIncome: $%.2f\nExpenses: $%.2f\nSavings: $%.2f\n",
            profile.name, profile.income, profile.expenses, profile.savings);
    fclose(file);
    printf("Budget details written to personal_budget.txt\n");
}

int main() {
    UserProfile user;
    int choice;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = 0; // Remove newline character

    printf("Enter your monthly income: $");
    scanf("%f", &user.income);
    user.expenses = 0.0;
    user.savings = 0.0;
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. Adjust Income\n");
        printf("3. Calculate Savings\n");
        printf("4. Display Profile\n");
        printf("5. Budget Overview\n");
        printf("6. Write budget to file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&user);
                calculateSavings(&user);
                break;
            case 2:
                adjustIncome(&user);
                calculateSavings(&user);
                break;
            case 3:
                calculateSavings(&user);
                printf("Savings calculated.\n");
                break;
            case 4:
                displayProfile(user);
                break;
            case 5:
                budgetOverview(user);
                break;
            case 6:
                writeBudgetToFile(user);
                break;
            case 0:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}