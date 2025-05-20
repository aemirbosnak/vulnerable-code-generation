//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAMELEN 30
#define FILENAME "expense.txt"

typedef struct {
    int day, month, year;
}date;

typedef struct {
    char name[NAMELEN];
    float amount;
    date expense_date;
}expense;

void display_menu() {
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. View expenses for a specific date\n");
    printf("4. Delete all expenses\n");
    printf("5. Exit program\n");
}

void add_expense() {
    expense new_expense;
    FILE *fptr;
    fptr = fopen(FILENAME, "a");
    if(fptr == NULL) {
        printf("File error!");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", new_expense.name);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &new_expense.expense_date.day, &new_expense.expense_date.month, &new_expense.expense_date.year);

    fprintf(fptr, "%s %.2f %d/%d/%d\n", new_expense.name, new_expense.amount, new_expense.expense_date.day, new_expense.expense_date.month, new_expense.expense_date.year);
    printf("Expense added successfully!\n");
    fclose(fptr);
}

void view_all_expenses() {
    FILE *fptr;
    expense exp;
    fptr = fopen(FILENAME, "r");
    if(fptr == NULL) {
        printf("File error!");
        return;
    }

    printf("All expenses:\n");
    while(fscanf(fptr, "%s %f %d/%d/%d", exp.name, &exp.amount, &exp.expense_date.day, &exp.expense_date.month, &exp.expense_date.year) == 5) {
        printf("%s %.2f %d/%d/%d\n", exp.name, exp.amount, exp.expense_date.day, exp.expense_date.month, exp.expense_date.year);
    }
    fclose(fptr);
}

void view_expenses_for_date() {
    FILE *fptr;
    expense exp;
    date view_date;
    fptr = fopen(FILENAME, "r");
    if(fptr == NULL) {
        printf("File error!");
        return;
    }

    printf("Enter date to view expenses (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &view_date.day, &view_date.month, &view_date.year);
    printf("Expenses for %d/%d/%d:\n", view_date.day, view_date.month, view_date.year);

    while(fscanf(fptr, "%s %f %d/%d/%d", exp.name, &exp.amount, &exp.expense_date.day, &exp.expense_date.month, &exp.expense_date.year) == 5) {
        if(view_date.day == exp.expense_date.day && view_date.month == exp.expense_date.month && view_date.year == exp.expense_date.year) {
            printf("%s %.2f\n", exp.name, exp.amount);
        }
    }

    fclose(fptr);
}

void delete_all_expenses() {
    FILE *fptr;
    fptr = fopen(FILENAME, "w");
    fclose(fptr);
    printf("All expenses deleted!\n");
}

int main() {
    int option;
    do {
        display_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_expense();
                break;
            case 2:
                view_all_expenses();
                break;
            case 3:
                view_expenses_for_date();
                break;
            case 4:
                delete_all_expenses();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }

    }while(option != 5);
    return 0;
}