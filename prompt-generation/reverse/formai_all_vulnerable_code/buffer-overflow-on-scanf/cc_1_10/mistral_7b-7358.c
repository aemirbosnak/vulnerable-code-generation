//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float income;
    float expense;
    float savings;
} Category;

void initCategories(Category** categories, int* numCategories) {
    *categories = (Category*) calloc(MAX_CATEGORIES, sizeof(Category));
    if (*categories == NULL) {
        printf("Error: Could not allocate memory for categories.\n");
        exit(EXIT_FAILURE);
    }

    *numCategories = 0;
}

void addCategory(Category** categories, int* numCategories, const char* name, float income, float expense, float savings) {
    if (*numCategories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }

    strcpy((*categories)[*numCategories].name, name);
    (*categories)[*numCategories].income = income;
    (*categories)[*numCategories].expense = expense;
    (*categories)[*numCategories].savings = savings;

    (*numCategories)++;
}

void displayCategories(const Category* categories, int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        printf("\nCategory: %s\n", categories[i].name);
        printf("Income: $%.2f\n", categories[i].income);
        printf("Expenses: $%.2f\n", categories[i].expense);
        printf("Savings: $%.2f\n", categories[i].savings);
    }
}

int main() {
    Category* categories = NULL;
    int numCategories = 0;

    initCategories(&categories, &numCategories);

    int choice = 0;
    while (choice != 5) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Category\n");
        printf("2. Display Categories\n");
        printf("3. Update Category\n");
        printf("4. Delete Category\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50];
                float income, expense, savings;

                printf("Enter category name: ");
                scanf("%s", name);
                printf("Enter income: ");
                scanf("%f", &income);
                printf("Enter expenses: ");
                scanf("%f", &expense);
                printf("Enter savings: ");
                scanf("%f", &savings);

                addCategory(&categories, &numCategories, name, income, expense, savings);
                break;
            }
            case 2: {
                displayCategories(categories, numCategories);
                break;
            }
            case 3: {
                // Update category code here
                break;
            }
            case 4: {
                // Delete category code here
                break;
            }
            default:
                printf("Invalid choice.\n");
        }
    }

    free(categories);

    return 0;
}