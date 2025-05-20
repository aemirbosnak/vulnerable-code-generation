//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Expense structure
typedef struct Expense {
    char category[20];
    float amount;
    char date[11];
} Expense;

// Function prototypes
void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void saveExpenses(Expense expenses[], int count, char *filename);
void loadExpenses(Expense expenses[], int *count, char *filename);

int main() {
    int choice;
    int count = 0;
    Expense expenses[MAX_EXPENSES];
    char filename[20];

    printf("Welcome to the Expense Tracker!\n");

    // Load expenses from file
    printf("Enter a filename to load your expenses from (leave blank for none): ");
    fgets(filename, 20, stdin);
    strtok(filename, "\n"); // Remove trailing newline character
    loadExpenses(expenses, &count, filename);

    // Main menu
    do {
        printf("\nMenu:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Save expenses to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Enter a filename to save your expenses to (leave blank for default): ");
                fgets(filename, 20, stdin);
                strtok(filename, "\n"); // Remove trailing newline character
                saveExpenses(expenses, count, filename);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add an expense to the array
void addExpense(Expense expenses[], int *count) {
    if (*count == MAX_EXPENSES) {
        printf("Cannot add more expenses. Array is full.\n");
        return;
    }

    Expense expense;

    // Get input from user
    printf("Enter the category of the expense (20 characters max): ");
    scanf("%s", expense.category);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expense.amount);
    printf("Enter the date of the expense (YYYY-MM-DD): ");
    scanf("%s", expense.date);

    // Add expense to array and increment count
    expenses[*count] = expense;
    (*count)++;

    printf("Expense added successfully.\n");
}

// Function to view all expenses in the array
void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("Expenses:\n");
    printf("%-20s%-10s%s\n", "Category", "Amount", "Date");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-10.2f%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

// Function to save expenses to a file
void saveExpenses(Expense expenses[], int count, char *filename) {
    FILE *file;

    if (strcmp(filename, "") == 0) {
        file = fopen("expenses.txt", "w");
    } else {
        file = fopen(filename, "w");
    }

    if (file == NULL) {
        printf("Error saving expenses to file.\n");
        return;
    }

    fprintf(file, "%-20s%-10s%s\n", "Category", "Amount", "Date");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%-20s%-10.2f%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }

    fclose(file);

    printf("Expenses saved to file successfully.\n");
}

// Function to load expenses from a file
void loadExpenses(Expense expenses[], int *count, char *filename) {
    FILE *file;

    if (strcmp(filename, "") == 0) {
        file = fopen("expenses.txt", "r");
    } else {
        file = fopen(filename, "r");
    }

    if (file == NULL) {
        printf("No expenses file found.\n");
        return;
    }

    char line[50];
    fgets(line, 50, file); // Read and discard header line

    while (fgets(line, 50, file) != NULL && *count < MAX_EXPENSES) {
        sscanf(line, "%s%f%s", expenses[*count].category, &expenses[*count].amount, expenses[*count].date);
        (*count)++;
    }

    fclose(file);

    printf("Expenses loaded from file successfully.\n");
}