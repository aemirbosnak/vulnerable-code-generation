//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Max items and categories
#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

// Struct to hold category information
typedef struct {
    char name[50];
    double total_expense;
} Category;

// Struct to hold expense details
typedef struct {
    char description[100];
    double amount;
    char category[50];
    time_t timestamp;
} Expense;

// Global variables
Expense expenses[MAX_ITEMS];
Category categories[MAX_CATEGORIES];
int expense_count = 0;
int category_count = 0;

// Function prototypes
void add_category(char *name);
void add_expense(char *description, double amount, char *category);
void show_expenses();
void show_categories();
void filter_expenses_by_category(char *category);
void calculate_total_expenses();
void show_menu();

// Main function
int main() {
    show_menu();
    return 0;
}

// Function to show the user menu
void show_menu() {
    int choice;
    char description[100];
    double amount;
    char category[50];

    while (1) {
        printf("\n===== Futuristic Expense Tracker =====\n");
        printf("1. Add Category\n");
        printf("2. Add Expense\n");
        printf("3. Show Expenses\n");
        printf("4. Show Categories\n");
        printf("5. Filter Expenses by Category\n");
        printf("6. Total Expenses\n");
        printf("7. Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter category name: ");
                fgets(categories[category_count].name, sizeof(categories[category_count].name), stdin);
                categories[category_count].name[strcspn(categories[category_count].name, "\n")] = 0; // Remove newline
                categories[category_count].total_expense = 0.0;
                add_category(categories[category_count].name);
                printf("Category '%s' added!\n", categories[category_count].name);
                category_count++;
                break;
            case 2:
                printf("Enter expense description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline

                printf("Enter expense amount: ");
                scanf("%lf", &amount);
                getchar(); // Consume newline

                printf("Enter category for this expense: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = 0; // Remove newline
                add_expense(description, amount, category);
                printf("Expense '%s' of amount %.2f added under category '%s'.\n", description, amount, category);
                break;
            case 3:
                show_expenses();
                break;
            case 4:
                show_categories();
                break;
            case 5:
                printf("Enter category to filter expenses: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = 0; // Remove newline
                filter_expenses_by_category(category);
                break;
            case 6:
                calculate_total_expenses();
                break;
            case 7:
                printf("Exiting... Thank you for using the Futuristic Expense Tracker!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a category
void add_category(char *name) {
    // Future categories handling can be implemented here
    printf("Category '%s' is now registered in the system.\n", name);
}

// Function to add an expense
void add_expense(char *description, double amount, char *category) {
    if (expense_count < MAX_ITEMS) {
        strcpy(expenses[expense_count].description, description);
        expenses[expense_count].amount = amount;
        strcpy(expenses[expense_count].category, category);
        expenses[expense_count].timestamp = time(NULL);
        expenses[expense_count].timestamp = time(NULL);

        // Update the category total
        for (int i = 0; i < category_count; i++) {
            if (strcmp(categories[i].name, category) == 0) {
                categories[i].total_expense += amount;
                break;
            }
        }

        expense_count++;
    } else {
        printf("Cannot add more expenses. Limit reached!\n");
    }
}

// Function to show all expenses
void show_expenses() {
    printf("\n===== All Expenses =====\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Description: %s | Amount: %.2f | Category: %s | Date: %s",
               expenses[i].description,
               expenses[i].amount,
               expenses[i].category,
               ctime(&expenses[i].timestamp));
    }
}

// Function to show all categories
void show_categories() {
    printf("\n===== All Categories =====\n");
    for (int i = 0; i < category_count; i++) {
        printf("Category: %s | Total Expense: %.2f\n",
               categories[i].name,
               categories[i].total_expense);
    }
}

// Function to filter expenses by category
void filter_expenses_by_category(char *category) {
    printf("\n===== Expenses in Category: %s =====\n", category);
    int found = 0;
    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("Description: %s | Amount: %.2f | Date: %s",
                   expenses[i].description,
                   expenses[i].amount,
                   ctime(&expenses[i].timestamp));
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found for category '%s'.\n", category);
    }
}

// Function to calculate the total expenses
void calculate_total_expenses() {
    double total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses recorded: %.2f\n", total);
}