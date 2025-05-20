//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_categories;
int num_expenses;

void add_category() {
    char category_name[50];
    printf("Enter category name: ");
    scanf("%s", category_name);
    strcpy(categories[num_categories], category_name);
    num_categories++;
}

void add_expense() {
    char name[50];
    float amount;
    int category;
    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    printf("Enter expense category (0-%d): ", num_categories-1);
    scanf("%d", &category);
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].category = category;
    num_expenses++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, categories[expenses[i].category]);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to the Sherlock Holmes Expense Tracker!\n");
    printf("Please enter your name: ");
    char user_name[50];
    scanf("%s", user_name);
    printf("Hello, %s! Let's get started.\n", user_name);

    num_categories = 0;
    while (num_categories < MAX_CATEGORIES) {
        printf("Would you like to add a category? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            add_category();
        }
    }

    num_expenses = 0;
    while (num_expenses < MAX_EXPENSES) {
        printf("Would you like to add an expense? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            add_expense();
        }
    }

    printf("\n%s, here are your expenses:\n", user_name);
    display_expenses();

    printf("\n%s, here are your categories:\n", user_name);
    display_categories();

    return 0;
}