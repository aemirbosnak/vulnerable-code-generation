//FormAI DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    int id;
    char name[20];
    int amount;
    char category[20];
    char date[20];
};

struct expense expenses[100];
int count = 0;

void add_expense() {
    printf("Enter name: ");
    scanf("%s", expenses[count].name);
    printf("Enter amount: ");
    scanf("%d", &expenses[count].amount);
    printf("Enter category: ");
    scanf("%s", expenses[count].category);
    printf("Enter date: ");
    scanf("%s", expenses[count].date);
    expenses[count].id = count+1;
    count++;
    printf("Expense added!");
}

void view_expenses() {
    printf("%-5s %-20s %-10s %-20s %-20s\n", "ID", "Name", "Amount", "Category", "Date");
    printf("--------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%-5d %-20s %-10d %-20s %-20s\n", expenses[i].id, expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void view_expense_by_id() {
    int id;
    printf("Enter expense id: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++) {
        if(expenses[i].id == id) {
            printf("%-5s %-20s %-10s %-20s %-20s\n", "ID", "Name", "Amount", "Category", "Date");
            printf("--------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-20s %-20s\n", expenses[i].id, expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
            return;
        }
    }
    printf("Expense with id %d not found\n", id);
}

void view_expense_by_category() {
    char category[20];
    int total_amount = 0;
    printf("Enter category: ");
    scanf("%s", category);
    printf("%-20s %-10s\n", "Name", "Amount");
    printf("-------------------------\n");
    for(int i=0; i<count; i++) {
        if(strcmp(expenses[i].category, category) == 0) {
            printf("%-20s %-10d\n", expenses[i].name, expenses[i].amount);
            total_amount += expenses[i].amount;
        }
    }
    printf("\nTotal amount: %d\n", total_amount);
}

void help() {
    printf("Welcome to the Medieval Expense Tracker!\n");
    printf("Commands:\n");
    printf("1. Add expense\n");
    printf("2. View all expenses\n");
    printf("3. View expense by id\n");
    printf("4. View expenses by category\n");
    printf("5. Help\n");
    printf("6. Quit\n");
}

int main() {
    int choice;
    help();
    while(1) {
        printf("\n> ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                view_expense_by_id();
                break;
            case 4:
                view_expense_by_category();
                break;
            case 5:
                help();
                break;
            case 6:
                printf("Fare thee well!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}