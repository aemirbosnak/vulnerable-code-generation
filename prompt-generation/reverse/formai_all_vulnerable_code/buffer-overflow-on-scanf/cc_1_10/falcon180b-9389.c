//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float balance;
} Category;

typedef struct {
    char description[100];
    float amount;
    int categoryIndex;
} Expense;

int main() {
    int numCategories, numExpenses;
    Category categories[MAX_CATEGORIES];
    Expense expenses[MAX_EXPENSES];

    printf("Enter number of categories: ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        printf("Enter name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].balance = 0;
    }

    printf("Enter number of expenses: ");
    scanf("%d", &numExpenses);

    for (int i = 0; i < numExpenses; i++) {
        printf("Enter description of expense %d: ", i + 1);
        scanf("%s", expenses[i].description);
        printf("Enter amount of expense %d: ", i + 1);
        scanf("%f", &expenses[i].amount);
        printf("Enter category index for expense %d: ", i + 1);
        scanf("%d", &expenses[i].categoryIndex);
    }

    for (int i = 0; i < numExpenses; i++) {
        categories[expenses[i].categoryIndex - 1].balance += expenses[i].amount;
    }

    printf("Expense Tracker\n");
    printf("================\n");

    for (int i = 0; i < numCategories; i++) {
        printf("%s\t%s\n", categories[i].name, "$");
        for (int j = 0; j < categories[i].balance; j++) {
            printf("=");
        }
        printf("\n");
    }

    return 0;
}