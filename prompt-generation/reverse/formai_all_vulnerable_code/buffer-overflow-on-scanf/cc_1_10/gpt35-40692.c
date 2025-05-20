//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
/* Romeo and Juliet Personal Finance Planner */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define custom data type for budget categories */
typedef struct {
    char name[50];
    double amount;
} BudgetCategory;

/* Define custom data type for users */
typedef struct {
    char name[30];
    int age;
    double income;
    BudgetCategory categories[5];
    int num_categories;
} User;

/* Function to initialize user struct and categories */
User initialize_user(char name[], int age, double income) {
    User user;
    strcpy(user.name, name);
    user.age = age;
    user.income = income;

    // Initialize default categories
    BudgetCategory housing = {"Housing", 0};
    BudgetCategory food = {"Food", 0};
    BudgetCategory transportation = {"Transportation", 0};
    BudgetCategory entertainment = {"Entertainment", 0};
    BudgetCategory other = {"Other", 0};

    // Add categories to user's array of categories
    user.categories[0] = housing;
    user.categories[1] = food;
    user.categories[2] = transportation;
    user.categories[3] = entertainment;
    user.categories[4] = other;

    user.num_categories = 5;

    return user;
}

/* Function to print user's budget categories */
void print_budget(User user) {
    printf("\n%s's Budget\n", user.name);
    printf("-----------------------\n");

    for (int i = 0; i < user.num_categories; i++) {
        printf("%s: $%.2f\n", user.categories[i].name, user.categories[i].amount);
    }

    printf("\n");
}

/* Function to update a user's budget category */
void update_budget(User *user, char category[], double amount) {
    for (int i = 0; i < user->num_categories; i++) {
        if (strcmp(user->categories[i].name, category) == 0) {
           user->categories[i].amount += amount;
           printf("%s's %s budget updated to $%.2f\n", user->name, category, user->categories[i].amount);
           return;
        }
    }

    printf("Error: Category not found in %s's budget\n", user->name);
}

/* Main function */
int main() {
    printf("The Budget Planner of Romeo and Juliet\n\n");
    printf("Enter Juliet's name: ");
    char juliet_name[30];
    scanf("%s", juliet_name);
  
    printf("Enter Juliet's age: ");
    int juliet_age;
    scanf("%d", &juliet_age);

    printf("Enter Juliet's monthly income: ");
    double juliet_income;
    scanf("%lf", &juliet_income);

    User juliet = initialize_user(juliet_name, juliet_age, juliet_income);
    print_budget(juliet);

    printf("Enter Romeo's name: ");
    char romeo_name[30];
    scanf("%s", romeo_name);

    printf("Enter Romeo's age: ");
    int romeo_age;
    scanf("%d", &romeo_age);

    printf("Enter Romeo's monthly income: ");
    double romeo_income;
    scanf("%lf", &romeo_income);

    User romeo = initialize_user(romeo_name, romeo_age, romeo_income);
    print_budget(romeo);

    // Juliet updates her budget
    printf("%s, how much would you like to allocate to Housing?\n", juliet_name);
    double housing_amount;
    scanf("%lf", &housing_amount);
    update_budget(&juliet, "Housing", housing_amount);
    print_budget(juliet);

    // Romeo updates his budget
    printf("%s, how much would you like to allocate to Entertainment?\n", romeo_name);
    double entertainment_amount;
    scanf("%lf", &entertainment_amount);
    update_budget(&romeo, "Entertainment", entertainment_amount);
    print_budget(romeo);

    // Juliet updates her budget again
    printf("%s, how much would you like to allocate to Transportation?\n", juliet_name);
    double transportation_amount;
    scanf("%lf", &transportation_amount);
    update_budget(&juliet, "Transportation", transportation_amount);
    print_budget(juliet);

    return 0;
}