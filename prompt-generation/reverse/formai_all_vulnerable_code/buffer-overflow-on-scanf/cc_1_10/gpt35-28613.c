//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// Function prototypes
void add_expense();
void view_expenses();
void search_expenses();

// Global variables
char descriptions[MAX_EXPENSES][50];
int amounts[MAX_EXPENSES];
int num_expenses = 0;

int main() {
    int choice;

    printf("Expense Tracker\n");
    printf("================\n");

    while (1) {
        printf("\n1. Add an expense\n");
        printf("2. View expenses\n");
        printf("3. Search expenses\n");
        printf("4. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                search_expenses();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void add_expense() {
    char description[50];
    int amount;

    if (num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter description: ");
    scanf("%s", description);
    printf("Enter amount: ");
    scanf("%d", &amount);

    strcpy(descriptions[num_expenses], description);
    amounts[num_expenses] = amount;
    num_expenses++;

    printf("Expense added.\n");
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to show.\n");
        return;
    }

    int total = 0;

    printf("%-20s %s\n", "Description", "Amount");
    printf("-------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%d\n", descriptions[i], amounts[i]);
        total += amounts[i];
    }

    printf("\nTotal: $%d\n", total);
}

void search_expenses() {
    char search_term[50];

    printf("Enter search term: ");
    scanf("%s", search_term);

    int found = 0;

    printf("%-20s %s\n", "Description", "Amount");
    printf("-------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        if (strstr(descriptions[i], search_term) != NULL) {
            printf("%-20s $%d\n", descriptions[i], amounts[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses matching \"%s\".\n", search_term);
    }
}