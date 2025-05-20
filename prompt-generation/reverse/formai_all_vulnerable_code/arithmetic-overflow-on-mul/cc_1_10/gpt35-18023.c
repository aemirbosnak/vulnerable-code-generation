//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main(){
    int salary, rent, food, transport, other_expense, savings;
    int total_expense, balance;
    char choice;
    
    printf("\t\tPERSONAL FINANCE PLANNER\n\n");
    
    printf("Enter your salary: ");
    scanf("%d", &salary);
    
    printf("Enter your monthly expenses\n");
    
    printf("Rent: ");
    scanf("%d", &rent);
    
    printf("Food: ");
    scanf("%d", &food);
    
    printf("Transportation: ");
    scanf("%d", &transport);
    
    printf("Other expenses: ");
    scanf("%d", &other_expense);
    
    total_expense = rent + food + transport + other_expense;
    balance = salary - total_expense;
    
    printf("\n\n\tTotal Expense: %d\n", total_expense);
    
    if(balance>0){
        printf("\tBalance Left: %d\n\n", balance);
    }else if(balance == 0){
        printf("\tYou have no balance left. Watch your expenses!\n\n");
    }else{
        printf("\tYou are in debt. You need to adjust your expenses or earn more!\n\n");
    }
    
    printf("Would you like to save a portion of your salary for the future? (y/n)");
    scanf(" %c", &choice);
    
    if(choice == 'y' || choice == 'Y'){
        printf("\nEnter the percentage of salary you would like to save (integer from 0-100): ");
        int percentage;
        scanf("%d", &percentage);
        savings = (percentage * salary) / 100;
        printf("You will save: %d", savings);
    }else{
        printf("Thank you for using our Personal Finance Planner!");
    }
    
    return 0;
}