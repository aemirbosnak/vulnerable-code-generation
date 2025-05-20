//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store financial data
typedef struct {
    char *name;              // Name of the category
    double amount;           // Amount allocated to this category
    double spent;            // Amount spent in this category
    double balance;          // Balance remaining in this category
} category_t;

// Define a struct to store the financial plan
typedef struct {
    int num_categories;     // Number of categories in the plan
    category_t *categories;  // Array of categories
} plan_t;

// Function to create a new financial plan
plan_t *create_plan()
{
    plan_t *plan = malloc(sizeof(plan_t));
    plan->num_categories = 0;
    plan->categories = NULL;
    return plan;
}

// Function to add a new category to a financial plan
void add_category(plan_t *plan, char *name, double amount)
{
    // Reallocate the categories array to make space for the new category
    plan->categories = realloc(plan->categories, (plan->num_categories + 1) * sizeof(category_t));

    // Initialize the new category
    plan->categories[plan->num_categories].name = strdup(name);
    plan->categories[plan->num_categories].amount = amount;
    plan->categories[plan->num_categories].spent = 0.0;
    plan->categories[plan->num_categories].balance = amount;

    // Increment the number of categories
    plan->num_categories++;
}

// Function to print a financial plan
void print_plan(plan_t *plan)
{
    printf("Financial Plan\n");
    printf("---------------\n");
    for (int i = 0; i < plan->num_categories; i++) {
        printf("%s: $%.2f / $%.2f\n",
            plan->categories[i].name,
            plan->categories[i].spent,
            plan->categories[i].balance);
    }
}

// Function to get user input for a financial plan
void get_user_input(plan_t *plan)
{
    // Get the number of categories from the user
    printf("How many categories would you like to track? ");
    int num_categories;
    scanf("%d", &num_categories);

    // Get the name and amount for each category
    for (int i = 0; i < num_categories; i++) {
        char name[100];
        double amount;
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", name);
        printf("Enter the amount allocated to category %d: ", i + 1);
        scanf("%lf", &amount);
        add_category(plan, name, amount);
    }
}

// Function to main
int main() {
  plan_t *my_plan = create_plan();
  get_user_input(my_plan);
  print_plan(my_plan);
  return 0;
}