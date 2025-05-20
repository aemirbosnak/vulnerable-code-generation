//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char date[20];
    char category[50];
    char description[100];
    double amount;
} Expense;

int main() {
    FILE *fp;
    char filename[50] = "expenses.txt";
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    // Load expenses from file
    fp = fopen(filename, "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %s %s %lf", expenses[num_expenses].date, expenses[num_expenses].category, expenses[num_expenses].description, &expenses[num_expenses].amount)!= EOF) {
            num_expenses++;
        }
        fclose(fp);
    }

    // Display expenses
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s %s %s $%.2lf\n", expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
    }

    // Add new expense
    char input_date[20];
    char input_category[50];
    char input_description[100];
    double input_amount;

    printf("\nEnter new expense details:\n");
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", input_date);
    printf("Category: ");
    scanf("%s", input_category);
    printf("Description: ");
    scanf("%s", input_description);
    printf("Amount: ");
    scanf("%lf", &input_amount);

    fp = fopen(filename, "a");
    if (fp!= NULL) {
        fprintf(fp, "%s %s %s %lf\n", input_date, input_category, input_description, input_amount);
        fclose(fp);
        printf("\nExpense added successfully!\n");
    }

    return 0;
}