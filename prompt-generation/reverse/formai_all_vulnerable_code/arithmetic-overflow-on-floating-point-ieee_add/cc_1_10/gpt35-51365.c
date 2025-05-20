//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGETS 100 // Maximum number of budgets
#define MAX_CATEGORIES 10 // Maximum number of expense categories

// Structure to hold information about each budget
struct Budget {
    int id;
    char name[100];
    float income;
    float expenses[MAX_CATEGORIES];
    float totalExpenses;
};

// Function to get input from user
void getInput(char *prompt, char *input, int inputSize) {
    printf("%s", prompt);
    fgets(input, inputSize, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character
}

int main() {
    struct Budget budgets[MAX_BUDGETS]; // Array of budgets
    int budgetCount = 0; // Number of budgets entered so far

    // Loop until user chooses to quit
    while (1) {
        printf("\n");
        printf("Personal Finance Planner\n");
        printf("1. Enter budget\n");
        printf("2. View budgets\n");
        printf("3. Quit\n");

        char choice[10];
        getInput("Select an option: ", choice, 10);

        // Process user input
        if (strcmp(choice, "1") == 0) {
            // Get budget name
            char name[100];
            getInput("Enter budget name: ", name, 100);

            // Get budget income
            char incomeInput[20];
            float income;
            getInput("Enter income: ", incomeInput, 20);
            sscanf(incomeInput, "%f", &income);

            // Get expense categories and amounts
            int categoryCount = 0;
            float totalExpenses = 0;

            while (1) {
                if (categoryCount == MAX_CATEGORIES) {
                    printf("Maximum number of categories reached. Cannot add more.\n");
                    break;
                }

                char categoryName[100];
                getInput("Enter category name (or 'stop' to stop): ", categoryName, 100);

                if (strcmp(categoryName, "stop") == 0) {
                    break;
                }

                char categoryAmountInput[20];
                float categoryAmount;
                getInput("Enter amount: ", categoryAmountInput, 20);
                sscanf(categoryAmountInput, "%f", &categoryAmount);

                // Add category and amount to current budget
                strcpy(budgets[budgetCount].name, name);
                budgets[budgetCount].income = income;
                budgets[budgetCount].expenses[categoryCount] = categoryAmount;
                totalExpenses += categoryAmount;
                budgets[budgetCount].totalExpenses = totalExpenses;

                categoryCount++;
            }

            // Add budget to array of budgets
            budgets[budgetCount].id = budgetCount + 1;
            budgetCount++;

            printf("Budget added successfully.\n");
        } else if (strcmp(choice, "2") == 0) {
            // Print all budgets entered so far
            if (budgetCount == 0) {
                printf("No budgets entered yet.\n");
            } else {
                printf("ID  Name                  Income   Expenses   Balance\n");
                printf("-----------------------------------------------------\n");
                for (int i = 0; i < budgetCount; i++) {
                    printf("%-4d%-20s%-9.2f", budgets[i].id, budgets[i].name, budgets[i].income);

                    float totalExpenses = budgets[i].totalExpenses;
                    printf("%-11.2f", totalExpenses);

                    float balance = budgets[i].income - totalExpenses;
                    printf("%.2f", balance);

                    printf("\n");
                }
            }
        } else if (strcmp(choice, "3") == 0) {
            // Quit program
            printf("Exiting program...\n");
            break;
        } else {
            // Invalid input
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}