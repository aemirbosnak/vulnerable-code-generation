//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int amount;
} Expense;

int main() {
    int num_expenses = 0;
    Expense *expenses = NULL;

    while (1) {
        printf("Greetings, wanderer. What brings you to my humble abode?\n");
        printf("1. Add an expense\n");
        printf("2. Remove an expense\n");
        printf("3. List expenses\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[100];
                int amount;
                printf("Enter the name of the expense: ");
                scanf("%s", name);
                printf("Enter the amount of the expense: ");
                scanf("%d", &amount);

                Expense expense = {strdup(name), amount};
                expenses = realloc(expenses, (num_expenses + 1) * sizeof(Expense));
                expenses[num_expenses++] = expense;

                printf("Expense recorded.\n");
                break;
            }
            case 2: {
                if (num_expenses == 0) {
                    printf("No expenses to remove.\n");
                    break;
                }

                int index;
                printf("Enter the index of the expense you want to remove: ");
                scanf("%d", &index);

                if (index < 0 || index >= num_expenses) {
                    printf("Invalid index.\n");
                    break;
                }

                free(expenses[index].name);
                memmove(&expenses[index], &expenses[index + 1], (num_expenses - index - 1) * sizeof(Expense));
                num_expenses--;

                printf("Expense removed.\n");
                break;
            }
            case 3: {
                if (num_expenses == 0) {
                    printf("No expenses to list.\n");
                    break;
                }

                printf("Expenses:\n");
                for (int i = 0; i < num_expenses; i++) {
                    printf("%d. %s: %d\n", i + 1, expenses[i].name, expenses[i].amount);
                }
                break;
            }
            case 4: {
                printf("Farewell, wanderer. May your travels be safe.\n");
                for (int i = 0; i < num_expenses; i++) {
                    free(expenses[i].name);
                }
                free(expenses);
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}