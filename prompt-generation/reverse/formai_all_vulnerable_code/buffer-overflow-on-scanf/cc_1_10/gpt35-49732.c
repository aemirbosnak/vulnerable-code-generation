//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EXPENSES 1000    // maximum number of expenses that can be stored
#define MAX_DESCRIPTION 50   // maximum length of description of each expense

// structure to hold an expense
struct expense {
    int id;                   // unique id of the expense
    char description[MAX_DESCRIPTION];  // description of the expense
    float amount;            // amount of the expense
    char category[MAX_DESCRIPTION];    // category of the expense
};

// structure to hold all expenses
struct expense_list {
    int count;               // count of number of expenses
    struct expense expenses[MAX_EXPENSES];  // array of expenses
};

// function to add a new expense to the list
void add_expense(struct expense_list *list, char *description, float amount, char *category) {
    // check if the list is full
    if (list->count == MAX_EXPENSES) {
        printf("Expense list is full. Cannot add more expenses.\n");
        return;
    }
    // create a new expense
    struct expense new_expense;
    new_expense.id = list->count + 1;
    strcpy(new_expense.description, description);
    new_expense.amount = amount;
    strcpy(new_expense.category, category);
    // add the new expense to the list
    list->expenses[list->count] = new_expense;
    list->count++;
    printf("Expense added successfully.\n");
}

// function to print all expenses in the list
void print_expenses(struct expense_list *list) {
    printf("ID\tDescription\tAmount\tCategory\n");
    for (int i=0; i<list->count; i++) {
        printf("%d\t%s\t%.2f\t%s\n", list->expenses[i].id, list->expenses[i].description,
               list->expenses[i].amount, list->expenses[i].category);
    }
}

// function to calculate total amount spent
float calculate_total(struct expense_list *list) {
    float total = 0.0;
    for (int i=0; i<list->count; i++) {
        total += list->expenses[i].amount;
    }
    return total;
}

// function to calculate total amount spent in a given category
float calculate_total_by_category(struct expense_list *list, char *category) {
    float total = 0.0;
    for (int i=0; i<list->count; i++) {
        if (strcmp(list->expenses[i].category, category) == 0) {
            total += list->expenses[i].amount;
        }
    }
    return total;
}

int main() {
    // create a list of expenses
    struct expense_list expenses;
    expenses.count = 0;
    // loop to get user inputs
    while (1) {
        printf("Enter command (add/print/total/category/quit): ");
        char command[20];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char description[MAX_DESCRIPTION];
            float amount;
            char category[MAX_DESCRIPTION];
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter amount: ");
            scanf("%f", &amount);
            printf("Enter category: ");
            scanf("%s", category);
            add_expense(&expenses, description, amount, category);
        } else if (strcmp(command, "print") == 0) {
            print_expenses(&expenses);
        } else if (strcmp(command, "total") == 0) {
            float total = calculate_total(&expenses);
            printf("Total amount spent: %.2f\n", total);
        } else if (strcmp(command, "category") == 0) {
            char category[MAX_DESCRIPTION];
            printf("Enter category: ");
            scanf("%s", category);
            float total = calculate_total_by_category(&expenses, category);
            printf("Total amount spent in %s category: %.2f\n", category, total);
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}