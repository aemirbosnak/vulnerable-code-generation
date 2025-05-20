//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

//function to calculate total expenses
float total_expenses(float rent, float groceries, float transportation, float entertainment){
    return rent + groceries + transportation + entertainment;
}

//function to calculate total income
float total_income(float salary, float bonus){
    return salary + bonus;
}

//function to calculate net savings
float net_savings(float total_income, float total_expenses){
    return total_income - total_expenses;
}

//main function
int main(){
    float rent, groceries, transportation, entertainment, salary, bonus;
    char choice;
    
    do{
        //menu
        printf("\nPERSONAL FINANCE PLANNER\n");
        printf("-------------------------\n");
        printf("1. Enter monthly expenses\n");
        printf("2. Enter monthly income\n");
        printf("3. View financial summary\n");
        printf("4. Quit\n");
        printf("-------------------------\n");
        printf("Enter choice (1/2/3/4): ");
        scanf(" %c", &choice);
        
        switch(choice){
            case '1': //enter monthly expenses
                printf("\nEnter monthly rent amount: ");
                scanf("%f", &rent);
                printf("Enter monthly groceries amount: ");
                scanf("%f", &groceries);
                printf("Enter monthly transportation amount: ");
                scanf("%f", &transportation);
                printf("Enter monthly entertainment amount: ");
                scanf("%f", &entertainment);
                break;
            
            case '2': //enter monthly income
                printf("\nEnter monthly salary amount: ");
                scanf("%f", &salary);
                printf("Enter monthly bonus amount (if any): ");
                scanf("%f", &bonus);
                break;
                
            case '3': //view financial summary
                if(rent==0 || groceries==0 || transportation==0 || entertainment==0 || salary==0){
                    printf("\nPlease enter monthly expenses and income first!\n");
                }
                else{
                    printf("\nFinancial Summary\n");
                    printf("-------------------------\n");
                    printf("Total Expenses: $%.2f\n", total_expenses(rent, groceries, transportation, entertainment));
                    printf("Total Income: $%.2f\n", total_income(salary, bonus));
                    printf("Net Savings: $%.2f\n", net_savings(total_income(salary, bonus), total_expenses(rent, groceries, transportation, entertainment)));
                }
                break;
                
            case '4': //quit
                printf("\nThank you for using Personal Finance Planner!");
                exit(0);
            
            default: //invalid choice
                printf("\nInvalid choice! Please choose an option from 1 to 4.\n");
        }
        
    }while(choice!='4');
    
    return 0;
}