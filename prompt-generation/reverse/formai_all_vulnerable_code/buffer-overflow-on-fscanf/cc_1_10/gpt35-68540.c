//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

struct Expense {
    char desc[100];
    float amount;
};

int num_expenses = 0;
struct Expense expenses[MAX_EXPENSES];

void display_menu();
void add_expense();
void view_expenses();
void delete_expense();
void save_to_file();
void load_from_file();

int main() {
    load_from_file();
    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                save_to_file();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}

void display_menu() {
    printf("Expense Tracker\n");
    printf("---------------\n");
    printf("1. Add an expense\n");
    printf("2. View expenses\n");
    printf("3. Delete an expense\n");
    printf("4. Exit\n");
}

void add_expense() {
    if (num_expenses < MAX_EXPENSES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]s", expenses[num_expenses].desc);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[num_expenses].amount);
        num_expenses++;
        printf("Expense added successfully.\n");
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
    } else {
        printf("Expenses:\n");
        for (int i = 0; i < num_expenses; i++) {
            printf("%d. %s - $%.2f\n", i+1, expenses[i].desc, expenses[i].amount);
        }
    }
}

void delete_expense() {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
    } else {
        printf("Enter the number of the expense you want to delete: ");
        int expense_num;
        scanf("%d", &expense_num);
        if (expense_num < 1 || expense_num > num_expenses) {
            printf("Invalid expense number.\n");
        } else {
            for (int i = expense_num-1; i < num_expenses-1; i++) {
                expenses[i] = expenses[i+1];
            }
            num_expenses--;
            printf("Expense deleted successfully.\n");
        }
    }
}

void save_to_file() {
    FILE* fp;
    fp = fopen("expenses.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < num_expenses; i++) {
            fprintf(fp, "%s %.2f\n", expenses[i].desc, expenses[i].amount);
        }
        fclose(fp);
        printf("Expenses saved to file.\n");
    } else {
        printf("Error opening file.\n");
    }
}

void load_from_file() {
    FILE* fp;
    fp = fopen("expenses.txt", "r");
    if (fp != NULL) {
        char desc[100];
        float amount;
        while (fscanf(fp, " %[^\n]s", desc) != EOF) {
            fscanf(fp, "%f", &amount);
            strcpy(expenses[num_expenses].desc, desc);
            expenses[num_expenses].amount = amount;
            num_expenses++;
        }
        fclose(fp);
        printf("Expenses loaded from file.\n");
    }
}