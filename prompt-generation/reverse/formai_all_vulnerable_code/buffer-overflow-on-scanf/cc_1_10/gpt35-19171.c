//FormAI DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INPUT_SIZE 50

struct expense {
    char category[MAX_INPUT_SIZE];
    float amount;
};

void print_menu() {
    printf("\nExpense Tracker\n\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n\n");
}

struct expense read_expense() {
    struct expense e;
    printf("\nCategory: ");
    scanf("%s", e.category);
    printf("Amount: ");
    scanf("%f", &e.amount);
    return e;
}

void write_expense(FILE *fp, struct expense e) {
    fprintf(fp, "%s %.2f\n", e.category, e.amount);
}

void read_file(char* filename) {
    FILE *fp;
    char line[MAX_INPUT_SIZE];
    float total = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nNo Expenses Yet!\n");
        return;
    }

    printf("\nExpenses:\n");
    printf("Category\tAmount\n");
    printf("-----------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *category = strtok(line, " ");
        float amount = atof(strtok(NULL, " "));
        total += amount;
        printf("%s\t\t%.2f\n", category, amount);
    }

    fclose(fp);

    printf("-----------------------\n");
    printf("Total:\t\t%.2f\n", total);
}

int main() {
    int option;
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char filename[MAX_INPUT_SIZE];
    printf("\nEnter a filename to save expenses: ");
    scanf("%s", filename);

    while (1) {
        print_menu();
        printf("Option: ");
        scanf("%d", &option);

        if (option == 1) {
            if (num_expenses == MAX_EXPENSES) {
                printf("\nMaximum number of expenses reached!\n");
                continue;
            }
            struct expense e = read_expense();
            expenses[num_expenses++] = e;
            FILE *fp = fopen(filename, "a");
            write_expense(fp, e);
            fclose(fp);
        } else if (option == 2) {
            read_file(filename);
        } else if (option == 3) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid Option, Try Again!\n");
        }
    }

    return 0;
}