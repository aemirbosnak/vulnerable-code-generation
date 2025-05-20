//FormAI DATASET v1.0 Category: Expense Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100 //max number of entries

// Structure for an expense entry
struct Expense {
    int day, month, year; //date of expense
    char category[20]; //category of expense
    float cost; //cost of expense
};

// Array to store expense entries
struct Expense expenses[MAX_ENTRIES];

// Count of expense entries in the array
int count = 0;

// Add an expense entry to the array
void addExpense() {
    struct Expense expense;
    printf("Enter date of expense (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expense.day, &expense.month, &expense.year);
    printf("Enter category of expense: ");
    scanf("%s", expense.category);
    printf("Enter cost of expense: ");
    scanf("%f", &expense.cost);
    expenses[count] = expense;
    count++;
}

// Display all expense entries in the array
void displayExpenses() {
    printf("Expense Tracker\n");
    printf("--------------------------------------------------\n");
    printf("|Date\t\t|Category\t|Cost\t\t|\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("|%d/%d/%d\t|%s\t\t|%.2f\t\t|\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].category, expenses[i].cost);
    }
    printf("--------------------------------------------------\n");
}

// Save expense entries to a file in decentralized style (each node saves its own file)
void saveExpenses(char* node) {
    FILE *file;
    char filename[20];
    sprintf(filename, "%s-expenses.txt", node);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving expenses to file\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d/%d/%d,%s,%.2f\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].category, expenses[i].cost);
    }
    fclose(file);
    printf("Expenses saved to file %s\n", filename);
}

// Load expense entries from a file
void loadExpenses(char* node) {
    FILE *file;
    char filename[20];
    sprintf(filename, "%s-expenses.txt", node);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading expenses from file\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char date[20], category[20], cost[20];
        sscanf(line, "%[^,],%[^,],%[^,\n]", date, category, cost);
        struct Expense expense;
        sscanf(date, "%d/%d/%d", &expense.day, &expense.month, &expense.year);
        strcpy(expense.category, category);
        expense.cost = atof(cost);
        expenses[count] = expense;
        count++;
    }
    fclose(file);
    printf("Expenses loaded from file %s\n", filename);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [node]\n", argv[0]);
        return 1;
    }
    char* node = argv[1];
    printf("Welcome to the Expense Tracker (node: %s)\n", node);
    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Add an expense\n");
        printf("2. Display all expenses\n");
        printf("3. Save expenses\n");
        printf("4. Load expenses\n");
        printf("5. Quit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                saveExpenses(node);
                break;
            case 4:
                loadExpenses(node);
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}