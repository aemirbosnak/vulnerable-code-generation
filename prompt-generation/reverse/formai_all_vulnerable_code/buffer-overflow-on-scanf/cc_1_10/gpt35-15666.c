//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define MAX_EXPENSES 100 // maximum number of expenses

struct expense {
    int id;
    char category[20];
    float amount;
    char description[100];
};

void add_expense(struct expense expenses[], int *num_expenses);
void display_expenses(struct expense expenses[], int num_expenses);
void display_menu();
void search_expenses(struct expense expenses[], int num_expenses);
void delete_expense(struct expense expenses[], int *num_expenses);
void update_expense(struct expense expenses[], int num_expenses);

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    int choice;

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                search_expenses(expenses, num_expenses);
                break;
            case 4:
                delete_expense(expenses, &num_expenses);
                break;
            case 5:
                update_expense(expenses, num_expenses);
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

void display_menu() {
    printf("\n---------- Expense Tracker Menu ----------\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Search Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Update Expense\n");
    printf("6. Exit Program\n");
}

void add_expense(struct expense expenses[], int *num_expenses) {
    if (*num_expenses == MAX_EXPENSES) {
        printf("Maximum number of expenses reached!\n");
        return;
    }

    printf("\nEnter Expense Details:\n");
    printf("Category: ");
    scanf("%s", expenses[*num_expenses].category);
    printf("Amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Description: ");
    scanf("%s", expenses[*num_expenses].description);

    expenses[*num_expenses].id = *num_expenses + 1;
    (*num_expenses)++;

    printf("\nExpense added successfully!\n");
}

void display_expenses(struct expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    printf("\n---------- Expenses ----------\n");
    printf("%-5s %-15s %-10s %s\n", "ID", "Category", "Amount", "Description");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-5d %-15s %-10.2f %s\n", expenses[i].id, expenses[i].category, expenses[i].amount, expenses[i].description);
    }
}

void search_expenses(struct expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    printf("\nEnter search category: ");
    char search_category[20];
    scanf("%s", search_category);

    printf("\n---------- Search Results ----------\n");
    printf("%-5s %-15s %-10s %s\n", "ID", "Category", "Amount", "Description");

    int results_found = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, search_category) == 0) {
            printf("%-5d %-15s %-10.2f %s\n", expenses[i].id, expenses[i].category, expenses[i].amount, expenses[i].description);
            results_found = 1;
        }
    }

    if (!results_found) {
        printf("\nNo results found in category '%s'.\n", search_category);
    }
}

void delete_expense(struct expense expenses[], int *num_expenses) {
    if (*num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    printf("\nEnter ID of expense to delete: ");
    int delete_id;
    scanf("%d", &delete_id);

    int expense_found = 0;

    for (int i = 0; i < *num_expenses; i++) {
        if (expenses[i].id == delete_id) {
            for (int j = i; j < *num_expenses - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            
            (*num_expenses)--;
            expense_found = 1;
            printf("\nExpense with ID %d deleted successfully!\n", delete_id);
            break;
        }
    }

    if (!expense_found) {
        printf("\nExpense with ID %d not found!\n", delete_id);
    }
}

void update_expense(struct expense expenses[], int num_expenses) {
    if (num_expenses == 0) {
        printf("\nNo expenses added yet!\n");
        return;
    }

    printf("\nEnter ID of expense to update: ");
    int update_id;
    scanf("%d", &update_id);

    int expense_found = 0;

    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].id == update_id) {
            printf("\nEnter updated expense details:\n");
            printf("Category: ");
            scanf("%s", expenses[i].category);
            printf("Amount: ");
            scanf("%f", &expenses[i].amount);
            printf("Description: ");
            scanf("%s", expenses[i].description);

            expense_found = 1;
            printf("\nExpense with ID %d updated successfully!\n", update_id);
            break;
        }
    }

    if (!expense_found) {
        printf("\nExpense with ID %d not found!\n", update_id);
    }
}