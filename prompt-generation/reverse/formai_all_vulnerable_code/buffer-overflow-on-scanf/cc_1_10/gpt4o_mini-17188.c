//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} PersonalFinance;

void printMenu() {
    printf("=== Personal Finance Planner ===\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Save & Exit\n");
    printf("Select an option (1-4): ");
}

void addIncome(PersonalFinance *pf) {
    printf("Enter amount of income: ");
    float income;
    scanf("%f", &income);
    pf->income += income;
    pf->savings += income; // Add income to savings
    printf("Income added successfully!\n");
}

void addExpense(PersonalFinance *pf) {
    printf("Enter amount of expense: ");
    float expense;
    scanf("%f", &expense);
    pf->expenses += expense;
    pf->savings -= expense; // Deduct expense from savings
    printf("Expense added successfully!\n");
}

void viewSummary(PersonalFinance *pf) {
    printf("\n=== Financial Summary ===\n");
    printf("Total Income: %.2f\n", pf->income);
    printf("Total Expenses: %.2f\n", pf->expenses);
    printf("Total Savings: %.2f\n", pf->savings);
    printf("*************************\n");
}

void saveToFile(PersonalFinance *pf) {
    FILE *file = fopen("finance_summary.txt", "w");
    if (file == NULL) {
        printf("Error saving to file.\n");
        return;
    }
    fprintf(file, "Name: %s\n", pf->name);
    fprintf(file, "Total Income: %.2f\n", pf->income);
    fprintf(file, "Total Expenses: %.2f\n", pf->expenses);
    fprintf(file, "Total Savings: %.2f\n", pf->savings);
    fclose(file);
    printf("Data saved successfully! Goodbye.\n");
}

int main() {
    PersonalFinance pf = {"", 0.0, 0.0, 0.0};

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your name: ");
    fgets(pf.name, sizeof(pf.name), stdin);
    pf.name[strcspn(pf.name, "\n")] = '\0'; // Remove newline character

    int option;
    while (1) {
        printMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addIncome(&pf);
                break;
            case 2:
                addExpense(&pf);
                break;
            case 3:
                viewSummary(&pf);
                break;
            case 4:
                saveToFile(&pf);
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}