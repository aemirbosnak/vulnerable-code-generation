//FormAI DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* Struct to hold expense details */
typedef struct Expense {
    char name[20];
    float amount;
    char category[20];
    char date[10];
} Expense;

/* Arrays to hold expenses and categories */
Expense expenses[MAX_SIZE];
char categories[MAX_SIZE][20];

/* Function to add new expense */
void addExpense(int *count) {
    printf("\nEnter expense details:\n");
    printf("Name: ");
    scanf("%s", expenses[*count].name);
    printf("Amount: ");
    scanf("%f", &expenses[*count].amount);
    printf("Category: ");
    scanf("%s", expenses[*count].category);
    printf("Date (dd-mm-yyyy): ");
    scanf("%s", expenses[*count].date);
    *count += 1;
}

/* Function to display all expenses */
void displayExpenses(int count) {
    if (count == 0) {
        printf("\nNo expenses added yet.\n");
        return;
    }
    printf("\nExpenses:\n");
    printf("Name\t\tAmount\t\tCategory\tDate\n");
    for (int i=0; i<count; i++) {
        printf("%s\t\t%.2f\t\t%s\t%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

/* Function to add new category */
void addCategory(int *num_categories) {
    printf("\nEnter new category: ");
    scanf("%s", categories[*num_categories]);
    printf("Category added successfully!\n");
    *num_categories += 1;
}

/* Function to display all categories */
void displayCategories(int num_categories) {
    if (num_categories == 0) {
        printf("\nNo categories added yet.\n");
        return;
    }
    printf("\nCategories:\n");
    for (int i=0; i<num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

/* Function to save expenses to file */
void saveExpensesToFile(int count) {
    FILE *fp;
    fp = fopen("expenses.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    for (int i=0; i<count; i++) {
        fprintf(fp, "%s,%.2f,%s,%s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
    fclose(fp);
    printf("\nExpenses saved to file successfully!\n");
}

/* Function to read expenses from file */
void readExpensesFromFile(int *count) {
    FILE *fp;
    fp = fopen("expenses.txt", "r");
    if (fp == NULL) {
        printf("\nError opening file.\n");
        return;
    }
    char line[100], *token;
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        strcpy(expenses[*count].name, token);
        token = strtok(NULL, ",");
        expenses[*count].amount = atof(token);
        token = strtok(NULL, ",");
        strcpy(expenses[*count].category, token);
        token = strtok(NULL, ",");
        strcpy(expenses[*count].date, token);
        *count += 1;
    }
    fclose(fp);
    printf("\nExpenses read from file successfully!\n");   
}

/* Main function */
int main() {
    int choice, count=0, num_categories=0;
    printf("Welcome to the Expense Tracker Program!\n");

    /* Menu */
    do {
        printf("\nChoose an option:\n");
        printf("1. Add new expense\n");
        printf("2. Display all expenses\n");
        printf("3. Add new category\n");
        printf("4. Display all categories\n");
        printf("5. Save expenses to file\n");
        printf("6. Read expenses from file\n");
        printf("7. Quit program\n");

        /* Paranoid input checking */
        char input[10];
        fgets(input, sizeof(input), stdin);
        while (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 7) {
            printf("\nInvalid input. Please enter a number between 1 and 7.\n");
            fgets(input, sizeof(input), stdin);
        }

        switch (choice) {
        case 1:
            addExpense(&count);
            break;
        case 2:
            displayExpenses(count);
            break;
        case 3:
            addCategory(&num_categories);
            break;
        case 4:
            displayCategories(num_categories);
            break;
        case 5:
            saveExpensesToFile(count);
            break;
        case 6:
            readExpensesFromFile(&count);
            break;
        case 7:
            printf("\nExiting program... Goodbye!\n");
            break;
        }
    } while (choice != 7);

    return 0;
}