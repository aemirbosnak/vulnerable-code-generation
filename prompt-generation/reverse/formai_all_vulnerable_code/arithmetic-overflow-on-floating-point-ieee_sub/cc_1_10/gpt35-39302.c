//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include<stdio.h>
#include<string.h>

//function to display menu
void display_menu(){
    printf("**PERSONAL FINANCE PLANNER**\n");
    printf("Enter 1 to calculate your monthly budget\n");
    printf("Enter 2 to calculate your net worth\n");
    printf("Enter 3 to set your savings goal\n");
    printf("Enter 4 to exit\n");
}

int main(){
    int option;
    float income, expenses, savings, net_worth, savings_goal;

    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\n--MONTHLY BUDGET CALCULATOR--\n");
                printf("Enter your income: ");
                scanf("%f", &income);
                printf("Enter your expenses: ");
                scanf("%f", &expenses);
                savings = income - expenses;
                printf("Your monthly savings: %f\n\n", savings);
                break;
            case 2:
                printf("\n--NET WORTH CALCULATOR--\n");
                printf("Enter your total assets: ");
                float assets;
                scanf("%f", &assets);
                printf("Enter your total liabilities: ");
                float liabilities;
                scanf("%f", &liabilities);
                net_worth = assets - liabilities;
                printf("Your net worth: %f\n\n", net_worth);
                break;
            case 3:
                printf("\n--SAVINGS GOAL SETTER--\n");
                printf("Enter your current savings: ");
                float current_savings;
                scanf("%f", &current_savings);
                printf("Enter your savings goal: ");
                scanf("%f", &savings_goal);
                if(current_savings >= savings_goal){
                    printf("Congratulations! You have already reached your savings goal!\n\n");
                }
                else{
                    float remaining_savings = savings_goal - current_savings;
                    printf("You need to save %f more to reach your savings goal.\n\n", remaining_savings);
                }
                break;
            case 4:
                printf("\nThank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("\nInvalid input. Please enter a valid option.\n\n");
        }
    }while(option!=4);

    return 0;
}