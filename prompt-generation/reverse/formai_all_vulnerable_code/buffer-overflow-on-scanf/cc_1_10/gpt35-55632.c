//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct FinancialData{
    int salary;
    int expenses;
    int savings;
};

void displayMenu(){
    printf("--------------------\n");
    printf("Personal Finance Planner\n");
    printf("--------------------\n");
    printf("1. Enter Financial Data\n");
    printf("2. Calculate Monthly Savings\n");
    printf("3. Exit\n");
}

int main(){
    struct FinancialData data;
    int choice;
    int flag = 0; // Flag to ensure data is entered before option 2 is selected
    
    do{
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter your monthly salary: ");
                scanf("%d", &data.salary);
                printf("Enter your monthly expenses: ");
                scanf("%d", &data.expenses);
                printf("Data entered successfully!\n");
                flag = 1;
                break;
            case 2:
                if(flag == 0){
                    printf("Please enter financial data first!\n");
                }
                else{
                    data.savings = data.salary - data.expenses;
                    if(data.savings > 0){
                        printf("Congratulations! You have a monthly savings of $%d\n", data.savings);
                    }
                    else if(data.savings == 0){
                        printf("You are breaking even!\n");
                    }
                    else{
                        printf("Uh oh! You are spending more than you earn!\n");
                    }
                }
                break;
            case 3:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice, please enter a number between 1-3.\n");
        }
    }while(choice != 3);
    
    return 0;
}