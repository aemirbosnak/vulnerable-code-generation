//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

struct expense {
    char category[MAX_CATEGORIES];
    double amount;
    char date[20];
};

int main() {
    FILE *file;
    int num_expenses = 0;
    int choice = 0;
    struct expense expenses[MAX_EXPENSES];

    file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No expenses found.\n");
        exit(1);
    }

    while (fscanf(file, "%s %lf %s\n", expenses[num_expenses].category, &expenses[num_expenses].amount, expenses[num_expenses].date)!= EOF) {
        num_expenses++;
    }

    fclose(file);

    while (choice!= 4) {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. View expenses by category\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter category: ");
                scanf("%s", expenses[num_expenses].category);
                printf("Enter amount: ");
                scanf("%lf", &expenses[num_expenses].amount);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", expenses[num_expenses].date);
                num_expenses++;
                break;
            case 2:
                printf("Expenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s %.2lf %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                }
                break;
            case 3:
                printf("Enter category: ");
                char category[MAX_CATEGORIES];
                scanf("%s", category);
                printf("Expenses in category '%s':\n", category);
                for (int i = 0; i < num_expenses; i++) {
                    if (strcmp(expenses[i].category, category) == 0) {
                        printf("%s %.2lf %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}