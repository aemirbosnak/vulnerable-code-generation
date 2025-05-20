//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 1000 // maximum number of expenses that can be tracked
#define MAX_DESCRIPTION_LEN 50 // maximum length of expense description
#define MAX_CATEGORY_LEN 20 // maximum length of expense category

struct Expense {
    int id;
    char description[MAX_DESCRIPTION_LEN];
    double cost;
    char category[MAX_CATEGORY_LEN];
};

int num_expenses = 0; // number of expenses currently stored in expenses[] array
struct Expense expenses[MAX_EXPENSES]; // array of expenses
int next_id = 1; // next available ID for a new expense

// forward declaration of function prototypes
void add_expense();
void display_expenses();
void search_expenses();
void delete_expense();
void save_to_file();
void load_from_file();
int get_option();

int main() {
    int option;

    load_from_file(); // load any previously saved expenses from file

    do {
        option = get_option();

        switch (option) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                search_expenses();
                break;
            case 4:
                delete_expense();
                break;
            case 5:
                save_to_file();
                break;
            case 6:
                puts("Exiting program...");
                break;
            default:
                puts("Invalid option, please try again.");
                break;
        }
    } while (option != 6);

    return 0;
}

/**
 * Adds a new expense to the expenses array.
 */
void add_expense() {
    struct Expense new_expense;

    // assign the next available ID to the new expense, and increment the next_id counter
    new_expense.id = next_id++;
    
    printf("Enter expense description (max %d characters): ", MAX_DESCRIPTION_LEN);
    fflush(stdin); // clear input buffer before reading string
    fgets(new_expense.description, MAX_DESCRIPTION_LEN, stdin);

    printf("Enter expense cost: ");
    scanf("%lf", &new_expense.cost);

    printf("Enter expense category (max %d characters): ", MAX_CATEGORY_LEN);
    fflush(stdin); // clear input buffer before reading string
    fgets(new_expense.category, MAX_CATEGORY_LEN, stdin);

    expenses[num_expenses++] = new_expense; // add the new expense to the array
}

/**
 * Displays all expenses currently stored in the expenses array.
 */
void display_expenses() {
    if (num_expenses == 0) {
        puts("No expenses to display.");
    } else {
        printf("%-5s %-30s %-10s %-15s\n", "ID", "DESCRIPTION", "COST", "CATEGORY");
        printf("%-5s %-30s %-10s %-15s\n", "--", "-----------", "----", "--------");

        for (int i = 0; i < num_expenses; i++) {
            printf("%-5d %-30s %-10.2lf %-15s\n", expenses[i].id, expenses[i].description, expenses[i].cost, expenses[i].category);
        }
    }
}

/**
 * Searches expenses by description or category.
 */
void search_expenses() {
    char search_str[100];
    int count = 0;

    printf("Enter search string: ");
    fflush(stdin); // clear input buffer before reading string
    fgets(search_str, 100, stdin);

    // strip newline character from end of search string (if there is one)
    if (search_str[strlen(search_str) - 1] == '\n') {
        search_str[strlen(search_str) - 1] = '\0';
    }

    // search for matching expenses and display them
    for (int i = 0; i < num_expenses; i++) {
        if (strstr(expenses[i].description, search_str) || strstr(expenses[i].category, search_str)) {
            printf("%-5d %-30s %-10.2lf %-15s\n", expenses[i].id, expenses[i].description, expenses[i].cost, expenses[i].category);
            count++;
        }
    }

    if (count == 0) {
        puts("No matching expenses found.");
    } else {
        printf("%d matching expenses found.\n", count);
    }
}

/**
 * Deletes an expense with the given ID from the expenses array.
 */
void delete_expense() {
    int id, index = -1;

    printf("Enter ID of expense to delete: ");
    scanf("%d", &id);

    // find the index of the expense with the given ID
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No expense found with ID %d.\n", id);
    } else {
        // shift all subsequent expenses in the array down by one position
        for (int i = index + 1; i < num_expenses; i++) {
            expenses[i - 1] = expenses[i];
        }

        num_expenses--;
        puts("Expense deleted.");
    }
}

/**
 * Saves the current expenses[] array to a file.
 */
void save_to_file() {
    FILE *file = fopen("expenses.txt", "w");

    if (file != NULL) {
        for (int i = 0; i < num_expenses; i++) {
            fprintf(file, "%d\t%s\t%f\t%s\n", expenses[i].id, expenses[i].description, expenses[i].cost, expenses[i].category);
        }

        fclose(file);
        puts("Expenses saved to file.");
    } else {
        puts("Error saving expenses to file.");
    }
}

/**
 * Loads previously saved expenses from a file into the expenses[] array.
 */
void load_from_file() {
    FILE *file = fopen("expenses.txt", "r");

    if (file != NULL) {
        while (!feof(file) && num_expenses < MAX_EXPENSES) {
            struct Expense expense;
            fscanf(file, "%d\t%[^\t]\t%lf\t%[^\n]\n", &expense.id, expense.description, &expense.cost, expense.category);
            expenses[num_expenses++] = expense;
        }

        fclose(file);
        next_id = expenses[num_expenses - 1].id + 1; // set the next available ID to the highest ID in the file + 1
        puts("Expenses loaded from file.");
    } else {
        puts("No saved expenses found.");
    }
}

/**
 * Displays the main menu of the program and prompts the user for an option.
 * Returns the user's chosen option.
 */
int get_option() {
    int option;

    puts("\nExpense Tracker");
    puts("---------------");
    puts("1. Add expense");
    puts("2. Display all expenses");
    puts("3. Search expenses");
    puts("4. Delete expense");
    puts("5. Save expenses to file");
    puts("6. Exit program");

    printf("Enter option: ");
    scanf("%d", &option);

    return option;
}