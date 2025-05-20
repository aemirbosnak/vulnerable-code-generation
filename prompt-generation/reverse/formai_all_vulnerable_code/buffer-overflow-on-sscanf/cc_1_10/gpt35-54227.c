//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

// Expense structure
typedef struct {
    float amount;
    char category[50];
    time_t timestamp;
} Expense;

// Function prototypes
void print_menu();
int get_choice();
void add_expense(Expense expenses[], int *num_expenses);
void print_expenses(Expense expenses[], int num_expenses);
float calculate_total(Expense expenses[], int num_expenses);
void save_expenses(Expense expenses[], int num_expenses);
void load_expenses(Expense expenses[], int *num_expenses);

int main() {
    int choice;
    int num_expenses = 0;
    Expense expenses[MAX_EXPENSES];

    load_expenses(expenses, &num_expenses);

    do {
        print_menu();
        choice = get_choice();

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                print_expenses(expenses, num_expenses);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculate_total(expenses, num_expenses));
                break;
            case 4:
                save_expenses(expenses, num_expenses);
                printf("Expenses saved.\n");
                break;
            case 5:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Print the main menu
void print_menu() {
    printf("\nExpense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. Print Expenses\n");
    printf("3. Calculate Total\n");
    printf("4. Save Expenses\n");
    printf("5. Quit\n");
}

// Get the user's choice
int get_choice() {
    int choice;
    printf("Choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline
    return choice;
}

// Add an expense
void add_expense(Expense expenses[], int *num_expenses) {
    float amount;
    char category[50];
    time_t timestamp = time(NULL);

    printf("Enter amount: ");
    scanf("%f", &amount);

    printf("Enter category: ");
    fgets(category, 50, stdin);
    category[strcspn(category, "\n")] = '\0'; // remove newline

    Expense expense = {amount, category, timestamp};
    expenses[(*num_expenses)++] = expense;

    printf("Expense added.\n");
}

// Print all expenses
void print_expenses(Expense expenses[], int num_expenses) {
    printf("All Expenses\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%ld - $%.2f - %s\n", expenses[i].timestamp, expenses[i].amount, expenses[i].category);
    }
}

// Calculate the total of all expenses
float calculate_total(Expense expenses[], int num_expenses) {
    float total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Save expenses to a file
void save_expenses(Expense expenses[], int num_expenses) {
    FILE *file = fopen("expenses.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < num_expenses; i++) {
            fprintf(file, "%.2f,%s,%ld\n", expenses[i].amount, expenses[i].category, expenses[i].timestamp);
        }
        fclose(file);
    }
}

// Load expenses from a file
void load_expenses(Expense expenses[], int *num_expenses) {
    FILE *file = fopen("expenses.txt", "r");
    if (file != NULL) {
        char line[100];
        while (fgets(line, 100, file) != NULL) {
            float amount;
            char category[50];
            time_t timestamp;
            sscanf(line, "%f,%[^,],%ld\n", &amount, category, &timestamp);
            Expense expense = {amount, category, timestamp};
            expenses[(*num_expenses)++] = expense;
        }
        fclose(file);
    }
}