//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[20];
	float amount;
} Expense;

typedef struct{
	char name[20];
	float amount;
} Income;

void addExpense(Expense list[], int* numExpenses){
	Expense newExpense;
	
	printf("What is the expense name?\n");
	fgets(newExpense.name, 20, stdin);
	newExpense.name[strcspn(newExpense.name, "\n")] = 0;
	
	printf("How much did you spend?\n");
	scanf("%f", &newExpense.amount);
	
	list[*numExpenses] = newExpense;
	*numExpenses += 1;
	
	printf("\nExpense added!\n\n");
}

void addIncome(Income list[], int* numIncomes){
	Income newIncome;
	
	printf("What is the income source?\n");
	fgets(newIncome.name, 20, stdin);
	newIncome.name[strcspn(newIncome.name, "\n")] = 0;
	
	printf("How much did you earn?\n");
	scanf("%f", &newIncome.amount);
	
	list[*numIncomes] = newIncome;
	*numIncomes += 1;
	
	printf("\nIncome added!\n\n");
}

void displayExpenses(Expense list[], int* numExpenses){
	printf("\nExpenses:\n");
	for(int i = 0; i < *numExpenses; i++){
		printf("%s : $%.2f\n", list[i].name, list[i].amount);
	}
	printf("\n");
}

void displayIncomes(Income list[], int* numIncomes){
	printf("\nIncomes:\n");
	for(int i = 0; i < *numIncomes; i++){
		printf("%s : $%.2f\n", list[i].name, list[i].amount);
	}
	printf("\n");
}

void displaySummary(Expense expenses[], int* numExpenses, Income incomes[], int* numIncomes){
	float totalExpenses = 0;
	float totalIncomes = 0;
	
	for(int i = 0; i < *numExpenses; i++){
		totalExpenses += expenses[i].amount;
	}
	
	for(int i = 0; i < *numIncomes; i++){
		totalIncomes += incomes[i].amount;
	}
	
	printf("\n====== SUMMARY ======\n\n");
	printf("Total Expenses: $%.2f\n", totalExpenses);
	printf("Total Income: $%.2f\n", totalIncomes);
	printf("Net Income: $%.2f\n\n", totalIncomes - totalExpenses);
}

int main(){
	int option = 0;
	int numExpenses = 0;
	int numIncomes = 0;
	Expense expenses[100];
	Income incomes[100];
	
	printf("======================\n");
	printf("Personal Finance Planner\n");
	printf("======================\n\n");
	
	printf("What would you like to do?\n\n");
	
	while(option != 4){
		printf("1. Add an expense\n");
		printf("2. Add an income\n");
		printf("3. Display Summary\n");
		printf("4. Quit\n\n");
		
		scanf("%d", &option);
		
		switch(option){
			case 1:
				fflush(stdin);
				addExpense(expenses, &numExpenses);
				break;
			case 2:
				fflush(stdin);
				addIncome(incomes, &numIncomes);
				break;
			case 3:
				displayExpenses(expenses, &numExpenses);
				displayIncomes(incomes, &numIncomes);
				displaySummary(expenses, &numExpenses, incomes, &numIncomes);
				break;
			case 4:
				printf("\nGoodbye! Happy Saving!\n");
				exit(0);
			default:
				printf("\nInvalid option!\n\n");
				break;
		}
	}
	
	return 0;
}