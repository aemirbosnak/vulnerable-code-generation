//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to your personal finance planner!\n");
    printf("Please enter your monthly income: $");
    float income;
    scanf("%f", &income);
    printf("Thanks! Now let's see what you're working with here...\n");
    printf("Income: $%.2f\n", income);

    printf("How much do you spend on rent/mortgage each month? $");
    float housing;
    scanf("%f", &housing);
    printf("Got it. Now, how much do you spend on groceries each month? $");
    float groceries;
    scanf("%f", &groceries);
    printf("Okay. And how about monthly utility bills? $");
    float utilities;
    scanf("%f", &utilities);

    float expenses = housing + groceries + utilities;
    printf("Total Monthly Expenses: $%.2f\n", expenses);
    printf("Your remaining disposable income this month is $%.2f\n", income - expenses);

    if (income - expenses > 0) {
        printf("Looks like you've got some money to spare! What do you want to do with it?\n");
        printf("1. Save it.\n");
        printf("2. Treat yo self.\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Very responsible! How much would you like to save? $");
                float savings;
                scanf("%f", &savings);
                printf("Okay, you will save $%.2f this month.", savings);
                break;
            case 2:
                printf("Yolo! How much do you want to spend on treats? $");
                float treats;
                scanf("%f", &treats);
                printf("Alright, you will spend $%.2f on treats this month.", treats);
                break;
            default:
                printf("Invalid choice, let's just save it.");
                float defaultSavings = income - expenses;
                printf("You will save $%.2f this month.", defaultSavings);
        }
    } else {
        printf("Uh oh, looks like you're in the red this month. Time to tighten the budget!");
    }

    return 0;
}