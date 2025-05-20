//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

/* define a struct to represent an expense */
struct expense {
    char name[10];
    float amount;
};

/* function to get total expenses amount */
float getTotalExpenseAmount(struct expense *expenses, int numExpenses) {
    float totalAmount = 0.0;
    for(int i = 0; i < numExpenses; i++) {
        totalAmount += expenses[i].amount;
    }
    return totalAmount;
}

/* function to get average expense amount */
float getAverageExpenseAmount(struct expense *expenses, int numExpenses) {
    float totalAmount = getTotalExpenseAmount(expenses, numExpenses);
    float averageAmount = totalAmount / numExpenses;
    return averageAmount;
}

int main() {
    int numExpenses;

    // get number of expenses
    printf("Enter number of expenses: ");
    scanf("%d", &numExpenses);

    // create an array of expenses
    struct expense *expenses = malloc(numExpenses * sizeof(struct expense));

    // get expense details for each expense
    for(int i = 0; i < numExpenses; i++) {
        printf("Enter expense %d name: ", i+1);
        scanf("%s", expenses[i].name);
        printf("Enter expense %d amount: ", i+1);
        scanf("%f", &expenses[i].amount);
    }

    // output total expenses amount and average expense amount
    printf("Total expenses amount: %.2f\n", getTotalExpenseAmount(expenses, numExpenses));
    printf("Average expense amount: %.2f\n", getAverageExpenseAmount(expenses, numExpenses));

    // free memory allocated for expenses array
    free(expenses);
    
    return 0;
}