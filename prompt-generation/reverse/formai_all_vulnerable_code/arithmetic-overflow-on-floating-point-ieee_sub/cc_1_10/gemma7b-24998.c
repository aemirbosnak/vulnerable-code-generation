//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Define an array of structures to store financial data
    struct FinancialData {
        char name[50];
        int age;
        double income;
        double expenses;
        double savings;
    } person[100];

    // Create a variable to store the number of people
    int numPeople = 0;

    // Loop to get financial data from the user
    while (1) {
        // Get the person's name, age, income, and expenses
        printf("Enter your name: ");
        scanf("%s", person[numPeople].name);

        printf("Enter your age: ");
        scanf("%d", &person[numPeople].age);

        printf("Enter your income: ");
        scanf("%lf", &person[numPeople].income);

        printf("Enter your expenses: ");
        scanf("%lf", &person[numPeople].expenses);

        // Calculate the person's savings
        person[numPeople].savings = person[numPeople].income - person[numPeople].expenses;

        // Increment the number of people
        numPeople++;

        // Check if the user wants to continue
        char answer;
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    // Print the financial data for each person
    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s\n", person[i].name);
        printf("Age: %d\n", person[i].age);
        printf("Income: %.2lf\n", person[i].income);
        printf("Expenses: %.2lf\n", person[i].expenses);
        printf("Savings: %.2lf\n", person[i].savings);
        printf("\n");
    }

    return 0;
}