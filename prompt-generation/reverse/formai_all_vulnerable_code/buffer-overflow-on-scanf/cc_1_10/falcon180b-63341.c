//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_NAME_LENGTH 30

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int expenses[MAX_EXPENSES];
} category;

int main() {
    int expenses[MAX_EXPENSES];
    category categories[MAX_CATEGORIES];
    int num_categories = 0;
    int num_expenses = 0;

    // Initialize categories
    strcpy(categories[num_categories].name, "Food");
    num_categories++;
    strcpy(categories[num_categories].name, "Transportation");
    num_categories++;
    strcpy(categories[num_categories].name, "Housing");
    num_categories++;

    // Initialize expenses
    expenses[num_expenses++] = 50;
    expenses[num_expenses++] = 100;
    expenses[num_expenses++] = 75;

    // Assign expenses to categories
    for (int i = 0; i < num_expenses; i++) {
        int category_index = -1;
        printf("Enter the category for expense %d (0-2): ", i);
        scanf("%d", &category_index);
        if (category_index >= 0 && category_index < num_categories) {
            categories[category_index].expenses[num_categories - 1] = expenses[i];
        }
    }

    // Print expenses by category
    for (int i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        for (int j = 0; j < num_expenses; j++) {
            if (categories[i].expenses[j]!= 0) {
                printf("Expense %d: %d\n", j + 1, categories[i].expenses[j]);
            }
        }
        printf("\n");
    }

    return 0;
}