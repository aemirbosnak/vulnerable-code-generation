//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>

float expenses = 0;
float income = 0;

void addIncome();
void addExpense();
void viewSummary();
void displayMenu();

int main(){
    displayMenu();
    return 0;
}

/* Function to display the main menu */
void displayMenu(){
    int option;
    
    printf("******************************************\n");
    printf("*           Personal Finance Planner      *\n");
    printf("******************************************\n\n");
    
    printf("Please Select an Option: \n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit\n\n");
    
    printf("Option: ");
    scanf("%d", &option);
    
    switch(option){
        case 1: 
            addIncome();
            break;
        case 2: 
            addExpense();
            break;
        case 3: 
            viewSummary();
            break;
        case 4: 
            printf("\nThank you for using Personal Finance Planner!\n");
            break;
        default: 
            printf("\nInvalid Option. Please Try again.\n");
            displayMenu();
    }
}

/* Function to add income */
void addIncome(){
    float amount;
    
    printf("\nAdd Income: "); 
    scanf("%f", &amount);
    
    // Update income
    income += amount;
    
    printf("\nIncome of $%.2f added successfully!\n\n", amount);
    
    // Display main menu
    displayMenu();
}

/* Function to add expense */
void addExpense(){
    float amount;
    
    printf("\nAdd Expense: "); 
    scanf("%f", &amount);
    
    // Update expenses
    expenses += amount;
    
    printf("\nExpense of $%.2f added successfully!\n\n", amount);
    
    // Display main menu
    displayMenu();
}

/* Function to view summary */
void viewSummary(){
    float balance = income - expenses;
    
    printf("\n====================================\n");
    printf("              Summary                 \n");
    printf("====================================\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Balance: $%.2f\n", balance);
    printf("\n");
    
    // Display main menu
    displayMenu();
}