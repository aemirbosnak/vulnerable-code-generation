//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    float amount;
    char date[20];
} Expense;

int main() {
    char choice;
    Expense expenses[MAX_ITEMS];
    int num_expenses = 0;
    float total_expenses = 0;

    do {
        printf("Expense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_expenses >= MAX_ITEMS) {
                    printf("Maximum number of expenses reached.\n");
                } else {
                    printf("Enter expense name: ");
                    scanf("%s", expenses[num_expenses].name);
                    printf("Enter expense category: ");
                    scanf("%s", expenses[num_expenses].category);
                    printf("Enter expense amount: $");
                    scanf("%f", &expenses[num_expenses].amount);
                    strcpy(expenses[num_expenses].date, __DATE__);
                    num_expenses++;
                    printf("Expense added successfully.\n");
                }
                break;
            case '2':
                printf("View all expenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%s - %s - $%.2f - %s\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
                }
                break;
            case '3':
                for (int i = 0; i < num_expenses; i++) {
                    total_expenses += expenses[i].amount;
                }
                printf("Total expenses: $%.2f\n", total_expenses);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}