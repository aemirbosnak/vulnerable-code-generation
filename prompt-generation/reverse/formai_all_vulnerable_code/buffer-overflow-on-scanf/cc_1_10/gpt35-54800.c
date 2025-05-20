//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

struct expense {
    char name[20];
    float amount;
    char date[12];
};

int num_expenses = 0;
struct expense expenses[MAX_EXPENSES];

void add_expense() {
    system("clear");
    printf("Enter expense details:\n\n");

    printf("Name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Date (DD/MM/YYYY): ");
    scanf("%s", expenses[num_expenses].date);

    num_expenses++;
    printf("\nExpense added successfully!\n");
}

void view_expenses() {
    system("clear");
    printf("List of expenses:\n\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Date: %s\n\n", expenses[i].date);
    }
}

void display_menu() {
    system("clear");
    printf("Cyber Expense Tracker\n\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n\n");
    printf("Enter your choice (1-3): ");
}

int main() {
    int choice;

    while (1) {
        display_menu();

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nPress Enter key to continue...");
        getchar();
    }

    return 0;
}