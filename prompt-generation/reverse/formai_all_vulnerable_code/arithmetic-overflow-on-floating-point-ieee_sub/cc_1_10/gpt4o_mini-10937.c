//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    double income;
    double expenses;
    double savings;
} User;

void welcomeMessage() {
    printf("****************************************\n");
    printf("*   Welcome to Your Personal Finance   *\n");
    printf("*            Planner App               *\n");
    printf("****************************************\n");
}

void initializeUser(User *user) {
    printf("Please enter your name: ");
    fgets(user->name, sizeof(user->name), stdin);
    
    printf("Enter your monthly income: ");
    scanf("%lf", &user->income);
    
    printf("Enter your monthly expenses: ");
    scanf("%lf", &user->expenses);
    
    user->savings = user->income - user->expenses;
    printf("Thank you, %sYour savings for this month: %.2lf\n\n", user->name, user->savings);
}

void displayBudget(User *user) {
    printf("=== Monthly Financial Overview ===\n");
    printf("Name: %s", user->name);
    printf("Monthly Income: %.2lf\n", user->income);
    printf("Monthly Expenses: %.2lf\n", user->expenses);
    printf("Savings: %.2lf\n\n", user->savings);
}

void allocateToSavings(User *user) {
    if (user->savings < 0) {
        printf("You are in deficit! Consider cutting down on your expenses.\n");
    } else {
        double allocation;
        printf("How much would you like to allocate to savings this month (up to %.2lf)? ", user->savings);
        scanf("%lf", &allocation);
        
        if (allocation > user->savings) {
            printf("You cannot allocate more than your actual savings!\n");
        } else {
            user->savings -= allocation;
            printf("You have successfully allocated %.2lf to savings.\n", allocation);
            printf("Remaining savings: %.2lf\n\n", user->savings);
        }
    }
}

void viewSavingsGoal(User *user) {
    double goal;
    printf("Enter your savings goal: ");
    scanf("%lf", &goal);

    double remaining = goal - user->savings;
    if (remaining > 0) {
        printf("You need to save %.2lf more to reach your goal of %.2lf.\n\n", remaining, goal);
    } else {
        printf("Congratulations! You have reached your savings goal of %.2lf!\n\n", goal);
    }
}

void exitApp() {
    printf("Thank you for using the Personal Finance Planner. Have a peaceful day!\n");
}

int main() {
    User user;
    int choice;
    
    welcomeMessage();
    initializeUser(&user);

    do {
        printf("Please select an option:\n");
        printf("1. View Monthly Budget\n");
        printf("2. Allocate to Savings\n");
        printf("3. View Savings Goal\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayBudget(&user);
                break;
            case 2:
                allocateToSavings(&user);
                break;
            case 3:
                viewSavingsGoal(&user);
                break;
            case 4:
                exitApp();
                break;
            default:
                printf("Invalid choice. Please select again.\n\n");
                break;
        }
    } while (choice != 4);

    return 0;
}