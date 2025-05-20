//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct PersonalFinance {
    char name[MAX];
    int age;
    double income;
    double expenses;
    double savings;
} PersonalFinance;

int main() {
    PersonalFinance pf[MAX];

    // Initialize the array of PersonalFinance structs
    for (int i = 0; i < MAX; i++) {
        pf[i].name[0] = '\0';
        pf[i].age = 0;
        pf[i].income = 0.0;
        pf[i].expenses = 0.0;
        pf[i].savings = 0.0;
    }

    // Get the number of PersonalFinance structs to be created
    int num_pf = 0;
    printf("How many Personal Finance structs do you want to create? ");
    scanf("%d", &num_pf);

    // Create the PersonalFinance structs
    for (int i = 0; i < num_pf; i++) {
        printf("Enter the name of the Personal Finance struct: ");
        scanf("%s", pf[i].name);

        printf("Enter the age of the Personal Finance struct: ");
        scanf("%d", &pf[i].age);

        printf("Enter the income of the Personal Finance struct: ");
        scanf("%lf", &pf[i].income);

        printf("Enter the expenses of the Personal Finance struct: ");
        scanf("%lf", &pf[i].expenses);

        printf("Enter the savings of the Personal Finance struct: ");
        scanf("%lf", &pf[i].savings);
    }

    // Print the PersonalFinance structs
    for (int i = 0; i < num_pf; i++) {
        printf("Name: %s\n", pf[i].name);
        printf("Age: %d\n", pf[i].age);
        printf("Income: %.2lf\n", pf[i].income);
        printf("Expenses: %.2lf\n", pf[i].expenses);
        printf("Savings: %.2lf\n", pf[i].savings);
        printf("\n");
    }

    return 0;
}