//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
    char description[50];
    float amount;
    int category;
} expense;

// Define the categories of expenses
enum categories {
    FOOD,
    TRANSPORTATION,
    ENTERTAINMENT,
    OTHER
};

// Function to print the menu
void print_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add an expense\n");
    printf("2. View expenses\n");
    printf("3. Search expenses\n");
    printf("4. Delete an expense\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

// Function to get an integer from the user
int get_int() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to get a float from the user
float get_float() {
    float num;
    scanf("%f", &num);
    return num;
}

// Function to get a string from the user
void get_string(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

// Function to add an expense
void add_expense(expense *expenses, int *num_expenses) {
    // Get the description of the expense
    printf("Enter the description of the expense: ");
    get_string(expenses[*num_expenses].description, 50);

    // Get the amount of the expense
    printf("Enter the amount of the expense: ");
    expenses[*num_expenses].amount = get_float();

    // Get the category of the expense
    printf("Enter the category of the expense (1 for Food, 2 for Transportation, 3 for Entertainment, 4 for Other): ");
    expenses[*num_expenses].category = get_int();

    // Increment the number of expenses
    (*num_expenses)++;
}

// Function to view expenses
void view_expenses(expense *expenses, int num_expenses) {
    // Print the header
    printf("\nExpenses:\n");
    printf("%-5s %-20s %-10s %-10s\n", "No.", "Description", "Amount", "Category");

    // Print the expenses
    for (int i = 0; i < num_expenses; i++) {
        printf("%-5d %-20s %-10.2f ", i + 1, expenses[i].description, expenses[i].amount);

        // Print the category of the expense
        switch (expenses[i].category) {
            case FOOD:
                printf("Food");
                break;
            case TRANSPORTATION:
                printf("Transportation");
                break;
            case ENTERTAINMENT:
                printf("Entertainment");
                break;
            case OTHER:
                printf("Other");
                break;
        }

        printf("\n");
    }
}

// Function to search expenses
void search_expenses(expense *expenses, int num_expenses) {
    // Get the search term
    printf("Enter the search term: ");
    char search_term[50];
    get_string(search_term, 50);

    // Print the header
    printf("\nSearch Results:\n");
    printf("%-5s %-20s %-10s %-10s\n", "No.", "Description", "Amount", "Category");

    // Search the expenses
    int found = 0;
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].description, search_term) != NULL) {
            printf("%-5d %-20s %-10.2f ", i + 1, expenses[i].description, expenses[i].amount);

            // Print the category of the expense
            switch (expenses[i].category) {
                case FOOD:
                    printf("Food");
                    break;
                case TRANSPORTATION:
                    printf("Transportation");
                    break;
                case ENTERTAINMENT:
                    printf("Entertainment");
                    break;
                case OTHER:
                    printf("Other");
                    break;
            }

            printf("\n");
            found = 1;
        }
    }

    // If no expenses were found, print a message
    if (!found) {
        printf("No expenses found.\n");
    }
}

// Function to delete an expense
void delete_expense(expense *expenses, int *num_expenses) {
    // Get the number of the expense to delete
    printf("Enter the number of the expense to delete: ");
    int num = get_int();

    // Delete the expense
    for (int i = num - 1; i < *num_expenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    // Decrement the number of expenses
    (*num_expenses)--;
}

// Main function
int main() {
    // Define the array of expenses
    expense expenses[MAX_EXPENSES];

    // Define the number of expenses
    int num_expenses = 0;

    // Print the menu
    print_menu();

    // Get the user's choice
    int choice = get_int();

    // While the user does not choose to quit
    while (choice != 5) {
        // Switch on the user's choice
        switch (choice) {
            case 1:
                // Add an expense
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                // View expenses
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                // Search expenses
                search_expenses(expenses, num_expenses);
                break;
            case 4:
                // Delete an expense
                delete_expense(expenses, &num_expenses);
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }

        // Print the menu
        print_menu();

        // Get the user's choice
        choice = get_int();
    }

    // Quit the program
    printf("Thank you for using the Expense Tracker.\n");
    return 0;
}