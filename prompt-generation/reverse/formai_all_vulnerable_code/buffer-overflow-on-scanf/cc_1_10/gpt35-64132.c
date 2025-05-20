//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

//Function to calculate total expenses
double calculateTotalExpenses(double expensesArray[], int numOfExpenses){
    double totalExpenses = 0;
    for(int i = 0; i < numOfExpenses; i++){
        totalExpenses += expensesArray[i];
    }
    return totalExpenses;
}

//Function to calculate total income
double calculateTotalIncome(double incomeArray[], int numOfIncomes){
    double totalIncome = 0;
    for(int i = 0; i < numOfIncomes; i++){
        totalIncome += incomeArray[i];
    }
    return totalIncome;
}

//Function to calculate total saved amount
double calculateTotalSavings(double incomeArray[], double expensesArray[], int numOfIncomes, int numOfExpenses){
    double totalIncome = calculateTotalIncome(incomeArray, numOfIncomes);
    double totalExpenses = calculateTotalExpenses(expensesArray, numOfExpenses);
    double totalSavings = totalIncome - totalExpenses;
    return totalSavings;
}

int main(){
    printf("====== Welcome to Personal Finance Planner ======\n\n");

    //Taking input for number of expenses
    printf("Please enter the number of expenses you have: ");
    int numOfExpenses;
    scanf("%d", &numOfExpenses);

    //Taking input for expense amounts
    double expensesArray[numOfExpenses];
    for(int i = 0; i < numOfExpenses; i++){
        printf("Enter expense amount %d: ", i+1);
        scanf("%lf", &expensesArray[i]);
    }
    printf("Expenses added successfully!\n\n");

    //Taking input for number of incomes
    printf("Please enter the number of incomes you have: ");
    int numOfIncomes;
    scanf("%d", &numOfIncomes);

    //Taking input for income amounts
    double incomeArray[numOfIncomes];
    for(int i = 0; i < numOfIncomes; i++){
        printf("Enter income amount %d: ", i+1);
        scanf("%lf", &incomeArray[i]);
    }
    printf("Incomes added successfully!\n\n");

    //Calculating total expenses and printing
    double totalExpenses = calculateTotalExpenses(expensesArray, numOfExpenses);
    printf("Total Expenses: $%.2lf\n", totalExpenses);

    //Calculating total income and printing
    double totalIncome = calculateTotalIncome(incomeArray, numOfIncomes);
    printf("Total Income: $%.2lf\n", totalIncome);

    //Calculating total savings and printing
    double totalSavings = calculateTotalSavings(incomeArray, expensesArray, numOfIncomes, numOfExpenses);
    if(totalSavings >= 0){
        printf("Congratulations on saving $%.2lf this month!\n", totalSavings);
    } else{
        printf("Don't worry, you can still improve your financial situation!\n");
    }

    printf("\nThank you for using Personal Finance Planner!\n");
    return 0;
}