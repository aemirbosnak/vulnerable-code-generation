//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char name[50];
    float cost;
};

int main() {
    int num_expenses;
    printf("Enter the number of expenses: ");
    scanf("%d",&num_expenses);

    struct expense *expenses;
    expenses = (struct expense*)malloc(num_expenses*sizeof(struct expense));

    for(int i=0; i<num_expenses; i++) {
        printf("Enter the name of expense #%d: ",i+1);
        scanf("%s",expenses[i].name);
        printf("Enter the cost of expense #%d: ",i+1);
        scanf("%f",&expenses[i].cost);
    }

    float total_expense = 0;
    for(int i=0; i<num_expenses; i++) {
        total_expense += expenses[i].cost;
    }

    printf("\nYour expenses:\n");
    for(int i=0; i<num_expenses; i++) {
        printf("%s: $%.2f\n",expenses[i].name,expenses[i].cost);
    }
    printf("Total: $%.2f\n",total_expense);

    float income;
    printf("\nEnter your monthly income: $");
    scanf("%f",&income);

    float remaining_money = income - total_expense;
    printf("Remaining money: $%.2f\n",remaining_money);
    if(remaining_money > 0) {
        printf("You have $%.2f extra money this month. Great Job!\n",remaining_money);
    }
    else if(remaining_money == 0) {
        printf("You have no extra money left this month. Better luck next time!\n");
    }
    else {
        printf("WARNING: You have overspent your budget by $%.2f this month. Adjust your expenses accordingly.\n",total_expense-income);
    }

    free(expenses);

    return 0;
}