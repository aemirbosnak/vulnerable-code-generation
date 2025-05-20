//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense;

void read_expenses(expense expenses[], int num_expenses) {
    FILE *fp;
    char filename[MAX_NAME_LEN];
    int i = 0;
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s", expenses[i].name, expenses[i].category, expenses[i].amount)!= EOF) {
        i++;
        if (i >= num_expenses) {
            printf("Too many expenses in file.\n");
            exit(1);
        }
    }
    fclose(fp);
}

void write_expenses(expense expenses[], int num_expenses) {
    FILE *fp;
    char filename[MAX_NAME_LEN];
    printf("Enter filename to save expenses to: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < num_expenses; i++) {
        fprintf(fp, "%s %s %s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
    fclose(fp);
}

void display_expenses(expense expenses[], int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s %s %s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    int num_expenses;
    printf("Enter number of expenses: ");
    scanf("%d", &num_expenses);
    expense expenses[num_expenses];
    read_expenses(expenses, num_expenses);
    display_expenses(expenses, num_expenses);
    write_expenses(expenses, num_expenses);
    return 0;
}