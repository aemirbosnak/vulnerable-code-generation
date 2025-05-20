//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>

int main() {
    int choice;
    float income, expenses, savings, investment, debt;
    
    printf("Welcome to Personal Finance Planner!\n");
    
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Track income\n");
        printf("2. Track expenses\n");
        printf("3. Calculate monthly savings\n");
        printf("4. Plan for investment\n");
        printf("5. Manage debt\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter your income for the month: ");
                scanf("%f", &income);
                printf("You have earned %.2f this month.\n", income);
                break;
            case 2:
                printf("\nEnter your expenses for the month: ");
                scanf("%f", &expenses);
                printf("Your total expenses for the month is %.2f.\n", expenses);
                break;
            case 3:
                printf("\nCalculating monthly savings...\n");
                savings = income - expenses;
                printf("You have saved %.2f this month.\n", savings);
                break;
            case 4:
                printf("\nPlanning for investment...\n");
                printf("Enter the amount you want to invest: ");
                scanf("%f", &investment);
                printf("Your investment of %.2f is successfully made.\n", investment);
                break;
            case 5:
                printf("\nManaging debt...\n");
                printf("Enter your total debt: ");
                scanf("%f", &debt);
                printf("You have to pay back a total debt of %.2f.\n", debt);
                break;
            case 6:
                printf("\nThank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("\nInvalid Choice.\n");
        }
    } while (choice != 6);
    
    return 0;
}