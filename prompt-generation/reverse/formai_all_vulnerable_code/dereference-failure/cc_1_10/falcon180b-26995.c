//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

int main() {
    int num_expenses = 0;
    Expense expenses[MAX_EXPENSES];

    char input[100];
    while (fgets(input, 100, stdin)!= NULL) {
        if (input[0] == '#') {
            if (num_expenses >= MAX_EXPENSES) {
                printf("Error: too many expenses\n");
                exit(1);
            }

            char *name = strtok(input, " ");
            float amount = atof(strtok(NULL, " "));
            int category = atoi(strtok(NULL, " "));

            expenses[num_expenses] = (Expense) {
               .name = name,
               .amount = amount,
               .category = category
            };

            num_expenses++;
        }
    }

    int num_categories = 0;
    char categories[MAX_CATEGORIES][50];

    printf("Enter categories (one per line):\n");
    while (fgets(input, 100, stdin)!= NULL) {
        if (num_categories >= MAX_CATEGORIES) {
            printf("Error: too many categories\n");
            exit(1);
        }

        strcpy(categories[num_categories], input);
        num_categories++;
    }

    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].name, expenses[i].amount, categories[expenses[i].category]);
    }

    return 0;
}