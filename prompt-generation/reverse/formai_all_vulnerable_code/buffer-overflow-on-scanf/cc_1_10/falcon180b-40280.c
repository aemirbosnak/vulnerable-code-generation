//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

// Define structures for categories and expenses
struct category {
    char name[50];
    int id;
};

struct expense {
    char description[100];
    float amount;
    int category_id;
};

// Function prototypes
void add_category(struct category* categories, int num_categories);
int get_category_id(struct category* categories, int num_categories, char* name);
void add_expense(struct expense* expenses, int num_expenses, struct category* categories, int num_categories);
void print_expenses(struct expense* expenses, int num_expenses, struct category* categories, int num_categories);

int main() {
    struct category categories[MAX_CATEGORIES];
    int num_categories = 0;

    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    // Initialize categories
    categories[num_categories].id = 1;
    strcpy(categories[num_categories].name, "Food");
    num_categories++;

    categories[num_categories].id = 2;
    strcpy(categories[num_categories].name, "Transportation");
    num_categories++;

    categories[num_categories].id = 3;
    strcpy(categories[num_categories].name, "Entertainment");
    num_categories++;

    // Add expenses
    add_expense(expenses, num_expenses, categories, num_categories);

    // Print expenses
    print_expenses(expenses, num_expenses, categories, num_categories);

    return 0;
}

void add_category(struct category* categories, int num_categories) {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].id = num_categories + 1;
    num_categories++;
}

int get_category_id(struct category* categories, int num_categories, char* name) {
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, name) == 0) {
            return categories[i].id;
        }
    }
    return -1;
}

void add_expense(struct expense* expenses, int num_expenses, struct category* categories, int num_categories) {
    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    int category_id = get_category_id(categories, num_categories, "Food");
    if (category_id == -1) {
        add_category(categories, num_categories);
        category_id = 1;
    }
    expenses[num_expenses].category_id = category_id;

    num_expenses++;
}

void print_expenses(struct expense* expenses, int num_expenses, struct category* categories, int num_categories) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: $%.2f\n", expenses[i].amount);
        printf("Category: %s\n\n", categories[expenses[i].category_id - 1].name);
    }
}