//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define structure for personal finance planner
typedef struct {
    char name[50];
    int age;
    float income;
    float expenses;
    float savings;
} PersonalFinance;

// Function to create a new personal finance planner
PersonalFinance* createPersonalFinance() {
    PersonalFinance* pf = (PersonalFinance*)malloc(sizeof(PersonalFinance));
    pf->name[0] = '\0';
    pf->age = 0;
    pf->income = 0;
    pf->expenses = 0;
    pf->savings = 0;
    return pf;
}

// Function to display personal finance planner
void displayPersonalFinance(PersonalFinance* pf) {
    printf("Name: %s\n", pf->name);
    printf("Age: %d\n", pf->age);
    printf("Income: $%.2f\n", pf->income);
    printf("Expenses: $%.2f\n", pf->expenses);
    printf("Savings: $%.2f\n", pf->savings);
}

// Function to calculate savings based on income and expenses
float calculateSavings(float income, float expenses) {
    return income - expenses;
}

// Main function
int main() {
    PersonalFinance* pf = createPersonalFinance();

    // Get user input for name, age, income, and expenses
    printf("Enter your name: ");
    scanf("%s", pf->name);

    printf("Enter your age: ");
    scanf("%d", &pf->age);

    printf("Enter your income: ");
    scanf("%f", &pf->income);

    printf("Enter your expenses: ");
    scanf("%f", &pf->expenses);

    // Calculate savings and display personal finance planner
    pf->savings = calculateSavings(pf->income, pf->expenses);
    displayPersonalFinance(pf);

    return 0;
}