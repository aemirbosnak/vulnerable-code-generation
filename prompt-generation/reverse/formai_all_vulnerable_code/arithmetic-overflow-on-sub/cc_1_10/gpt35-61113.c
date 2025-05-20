//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

//Define struct for user input
typedef struct {
    int salary;
    int expenses;
    int savingsGoal;
} user;

//Define struct for savings calculations
typedef struct {
    int monthsToGoal;
    int totalSavings;
    int monthlySavings;
} savings;

//Function to calculate savings
savings calculateSavings(user user) {
    savings savings;
    int remainingSavings = user.salary - user.expenses;
    int totalSavings = 0;
    int monthsToGoal = 0;
    
    while (totalSavings < user.savingsGoal) {
        totalSavings += remainingSavings;
        monthsToGoal++;
    }
    
    savings.monthlySavings = remainingSavings;
    savings.monthsToGoal = monthsToGoal;
    savings.totalSavings = totalSavings;
    
    return savings;
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n\n");
    
    //Prompt user for input
    user user;
    printf("Please enter your monthly salary: ");
    scanf("%d", &user.salary);
    printf("Please enter your monthly expenses: ");
    scanf("%d", &user.expenses);
    printf("Please enter your savings goal: ");
    scanf("%d", &user.savingsGoal);
    
    //Calculate savings
    savings savings = calculateSavings(user);
    
    //Print results
    printf("\nIt will take %d months to save $%d with a monthly savings of $%d\n", 
           savings.monthsToGoal, user.savingsGoal, savings.monthlySavings);
    printf("Total savings will be $%d\n", savings.totalSavings);
    
    return 0;
}