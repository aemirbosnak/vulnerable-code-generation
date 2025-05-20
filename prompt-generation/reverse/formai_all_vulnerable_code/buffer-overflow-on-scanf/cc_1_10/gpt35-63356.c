//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct expense {
    char date[20];
    char item[50];
    float amount;
    char category[20];
} expenses[MAX];

int count = 0;

void add_expense() {
    if (count == MAX) {
        printf("Sorry, expense tracker is full\n");
        return;
    }

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", expenses[count].date);

    printf("Enter item name: ");
    scanf(" %[^\n]s", expenses[count].item);

    printf("Enter amount: ");
    scanf("%f", &expenses[count].amount);

    printf("Enter category: ");
    scanf("%s", expenses[count].category);

    count++;
}

void display_expenses() {
    if (count == 0) {
        printf("No expenses to display\n");
        return;
    }

    printf("Date\t Item\t Amount\t Category\n");
    printf("-------------------------------------\n");

    float total = 0;
    for (int i = 0; i < count; i++) {
        printf("%s\t %s\t %.2f\t %s\n", expenses[i].date, expenses[i].item, expenses[i].amount, expenses[i].category);
        total += expenses[i].amount;
    }

    printf("-------------------------------------\n");
    printf("Total expenses: %.2f\n", total);
}

int find_expense(char item[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].item, item) == 0) {
            return i;
        }
    }
    return -1;
}

void edit_expense() {
    if (count == 0) {
        printf("No expenses to edit\n");
        return;
    }

    char item[50];
    printf("Enter item name to edit: ");
    scanf(" %[^\n]s", item);

    int index = find_expense(item);
    if (index == -1) {
        printf("Item not found\n");
        return;
    }

    printf("Enter new date (dd/mm/yyyy): ");
    scanf("%s", expenses[index].date);

    printf("Enter new item name: ");
    scanf(" %[^\n]s", expenses[index].item);

    printf("Enter new amount: ");
    scanf("%f", &expenses[index].amount);

    printf("Enter new category: ");
    scanf("%s", expenses[index].category);
}

void delete_expense() {
    if (count == 0) {
        printf("No expenses to delete\n");
        return;
    }

    char item[50];
    printf("Enter item name to delete: ");
    scanf(" %[^\n]s", item);

    int index = find_expense(item);
    if (index == -1) {
        printf("Item not found\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    count--;
    printf("Expense deleted successfully\n");
}

int main() {
    int choice;

    do {
        printf("\n");
        printf("EXPENSE TRACKER\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Edit Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                edit_expense();
                break;
            case 4:
                delete_expense();
                break;
            case 5:
                printf("Thank you for using Expense Tracker\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}