//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    float amount;
} Expense;

int main() {
    int choice, counter = 0;
    Expense expenses[MAX_EXPENSES];

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (counter >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                    break;
                }
                printf("Enter expense category: ");
                scanf("%s", expenses[counter].category);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[counter].amount);
                counter++;
                break;
            case 2:
                if (counter == 0) {
                    printf("No expenses recorded.\n");
                    break;
                }
                printf("\nExpenses:\n");
                for (int i = 0; i < counter; i++) {
                    printf("\nExpense %d:\n", i+1);
                    printf("Category: %s\n", expenses[i].category);
                    printf("Amount: %.2f\n", expenses[i].amount);
                }
                break;
            case 3:
                if (counter == 0) {
                    printf("No expenses recorded.\n");
                    break;
                }
                int index;
                printf("Enter expense index to delete: ");
                scanf("%d", &index);
                index--;
                if (index < 0 || index >= counter) {
                    printf("Invalid expense index.\n");
                    break;
                }
                for (int i = index; i < counter-1; i++) {
                    expenses[i] = expenses[i+1];
                }
                counter--;
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}