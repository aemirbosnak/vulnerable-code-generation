//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double income, expense, saving;

    printf("Welcome to the Personal Finance Planner!\n\n");
    printf("Please enter your monthly income: $");
    scanf("%lf", &income);

    while(1) {
        printf("\n1. Add expense\n2. View expenses\n3. Set saving goal\n4. View progress\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter expense amount: $");
                scanf("%lf", &expense);
                printf("\nExpense added successfully!\n");
                break;
            case 2:
                printf("\nExpenses:\n");
                printf("- Rent: $%0.2lf\n", 800);
                printf("- Utilities: $%0.2lf\n", 150);
                printf("- Groceries: $%0.2lf\n", 300);
                printf("- Entertainment: $%0.2lf\n", 200);
                break;
            case 3:
                printf("\nEnter saving goal: $");
                scanf("%lf", &saving);
                printf("\nSaving goal set successfully!\n");
                break;
            case 4:
                printf("\nYour current progress:\n");
                printf("Income: $%0.2lf\n", income);
                printf("Expenses: $%0.2lf\n", 800+150+300+200);
                printf("Saving goal: $%0.2lf\n", saving);
                if(income - (800+150+300+200) >= saving) {
                    printf("\nCongratulations! You're on track to reach your saving goal.\n");
                } else {
                    printf("\nYou need to adjust your expenses or increase your income to reach your saving goal.\n");
                }
                break;
            case 5:
                printf("\nThank you for using the Personal Finance Planner! Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}