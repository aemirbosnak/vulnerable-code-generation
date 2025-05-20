//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    int category;
} expense_t;

int main() {
    expense_t expenses[MAX_ITEMS];
    int num_expenses = 0;
    int num_categories = 0;
    char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
    int category_index = 0;

    // Initialize categories
    strcpy(categories[0], "Food");
    strcpy(categories[1], "Transportation");
    strcpy(categories[2], "Entertainment");
    strcpy(categories[3], "Clothing");
    strcpy(categories[4], "Housing");
    strcpy(categories[5], "Utilities");
    strcpy(categories[6], "Education");
    strcpy(categories[7], "Healthcare");
    strcpy(categories[8], "Travel");
    strcpy(categories[9], "Other");

    // Read expenses from file
    FILE* fp = fopen("expenses.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open expenses file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %lf %d", expenses[num_expenses].name, &expenses[num_expenses].amount, &expenses[num_expenses].category)!= EOF) {
        if (num_expenses >= MAX_ITEMS) {
            printf("Error: Maximum number of expenses exceeded.\n");
            return 1;
        }
        num_expenses++;
    }
    fclose(fp);

    // Count number of categories
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].category >= num_categories) {
            num_categories++;
        }
    }

    // Sort expenses by category
    for (int i = 0; i < num_expenses; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (expenses[i].category > expenses[j].category) {
                expense_t temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }

    // Print expenses by category
    for (int i = 0; i < num_categories; i++) {
        printf("\n%s:\n", categories[i]);
        for (int j = 0; j < num_expenses; j++) {
            if (expenses[j].category == i) {
                printf("%s $%.2f\n", expenses[j].name, expenses[j].amount);
            }
        }
    }

    return 0;
}