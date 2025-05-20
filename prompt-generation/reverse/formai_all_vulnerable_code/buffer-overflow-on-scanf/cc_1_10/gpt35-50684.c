//FormAI DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char description[50];
    float amount;
    int day;
    int month;
    int year;
};

void addExpense(struct Expense *expenses, int *numExpenses);
void printExpenses(struct Expense *expenses, int numExpenses);
float calculateTotalExpenses(struct Expense *expenses, int numExpenses);
float calculateAverageDailyExpenses(struct Expense *expenses, int numExpenses);
void saveExpensesToFile(struct Expense *expenses, int numExpenses);
void readExpensesFromFile(struct Expense *expenses, int *numExpenses);

int main() {
    struct Expense expenses[100];
    int numExpenses = 0;
    int option;

    readExpensesFromFile(expenses, &numExpenses);

    do {
        printf("Expense Tracker\n");
        printf("==============\n");
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Calculate average daily expenses\n");
        printf("5. Save expenses to file\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                printExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculateTotalExpenses(expenses, numExpenses));
                break;
            case 4:
                printf("Average daily expenses: $%.2f\n", calculateAverageDailyExpenses(expenses, numExpenses));
                break;
            case 5:
                saveExpensesToFile(expenses, numExpenses);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }

        printf("\n");
    } while(option != 6);

    return 0;
}

void addExpense(struct Expense *expenses, int *numExpenses) {
    printf("\nEnter expense details:\n");

    printf("Description: ");
    getchar();
    fgets(expenses[*numExpenses].description, 50, stdin);

    printf("Amount: $");
    scanf("%f", &expenses[*numExpenses].amount);

    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expenses[*numExpenses].day, &expenses[*numExpenses].month, &expenses[*numExpenses].year);

    (*numExpenses)++;
}

void printExpenses(struct Expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");

    for(int i = 0; i < numExpenses; i++) {
        printf("%d/%d/%d - %s: $%.2f\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].description, expenses[i].amount);
    }
}

float calculateTotalExpenses(struct Expense *expenses, int numExpenses) {
    float total = 0;

    for(int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

float calculateAverageDailyExpenses(struct Expense *expenses, int numExpenses) {
    int numDays = 0;
    float totalExpenses = 0;

    for(int i = 0; i < numExpenses; i++) {
        int j = i;
        while(j < numExpenses && expenses[j].day == expenses[i].day && expenses[j].month == expenses[i].month && expenses[j].year == expenses[i].year) {
            totalExpenses += expenses[j].amount;
            j++;
        }
        numDays++;
        i = j - 1;
    }

    return totalExpenses / numDays;
}

void saveExpensesToFile(struct Expense *expenses, int numExpenses) {
    FILE *fp;

    fp = fopen("expenses.txt", "w");

    for(int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%d/%d/%d;%s;%.2f\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].description, expenses[i].amount);
    }

    fclose(fp);

    printf("\nExpenses saved to file\n");
}

void readExpensesFromFile(struct Expense *expenses, int *numExpenses) {
    FILE *fp;
    char line[100];
    char *token;

    fp = fopen("expenses.txt", "r");

    if(fp == NULL) {
        return;
    }

    while(fgets(line, 100, fp) != NULL) {
        token = strtok(line, ";");
        sscanf(token, "%d/%d/%d", &expenses[*numExpenses].day, &expenses[*numExpenses].month, &expenses[*numExpenses].year);

        token = strtok(NULL, ";");
        strcpy(expenses[*numExpenses].description, token);

        token = strtok(NULL, ";");
        sscanf(token, "%f", &expenses[*numExpenses].amount);

        (*numExpenses)++;
    }

    fclose(fp);
}