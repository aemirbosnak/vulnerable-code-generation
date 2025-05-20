//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DESC_LEN 50
#define MAX_AMT_LEN 10
#define MAX_DATE_LEN 10

typedef struct {
    char desc[MAX_DESC_LEN];
    char amt[MAX_AMT_LEN];
    char date[MAX_DATE_LEN];
} Expense;

int main()
{
    int num_expenses, i;
    Expense *expenses;
    FILE *fp;
    char filename[50];
    char line[100];
    char *ptr;
    int total_amt;

    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);

    expenses = malloc(sizeof(Expense) * num_expenses);
    if (expenses == NULL) {
        printf("Error: Could not allocate memory for expenses.\n");
        return 1;
    }

    for (i = 0; i < num_expenses; i++) {
        printf("Enter the expense description: ");
        scanf("%s", expenses[i].desc);

        printf("Enter the expense amount: ");
        scanf("%s", expenses[i].amt);

        printf("Enter the expense date: ");
        scanf("%s", expenses[i].date);
    }

    printf("Enter the filename to save the expenses: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return 1;
    }

    fprintf(fp, "Expense Tracker\n");
    fprintf(fp, "Total Expenses: %d\n", num_expenses);
    fprintf(fp, "%-5s  %-20s  %-10s  %-10s\n", "No.", "Description", "Amount", "Date");

    total_amt = 0;
    for (i = 0; i < num_expenses; i++) {
        fprintf(fp, "%-5d  %-20s  %-10s  %-10s\n", i + 1, expenses[i].desc, expenses[i].amt, expenses[i].date);
        total_amt += atoi(expenses[i].amt);
    }

    fprintf(fp, "\nTotal Amount: %d\n", total_amt);

    fclose(fp);

    printf("Expenses saved to file %s.\n", filename);

    return 0;
}