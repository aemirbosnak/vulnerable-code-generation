//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
} Entry;

void addIncome(Entry incomeEntries[], int *incomeCount);
void addExpense(Entry expenseEntries[], int *expenseCount);
void calculateBalance(Entry incomeEntries[], int incomeCount, Entry expenseEntries[], int expenseCount);
void displaySummary(Entry incomeEntries[], int incomeCount, Entry expenseEntries[], int expenseCount);

int main() {
    Entry incomeEntries[MAX_ENTRIES];
    Entry expenseEntries[MAX_ENTRIES];
    int incomeCount = 0, expenseCount = 0;
    int choice;

    while (1) {
        printf("\nPersonal Budget Tracker\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Calculate Balance\n");
        printf("4. Display Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(incomeEntries, &incomeCount);
                break;
            case 2:
                addExpense(expenseEntries, &expenseCount);
                break;
            case 3:
                calculateBalance(incomeEntries, incomeCount, expenseEntries, expenseCount);
                break;
            case 4:
                displaySummary(incomeEntries, incomeCount, expenseEntries, expenseCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void addIncome(Entry incomeEntries[], int *incomeCount) {
    if (*incomeCount < MAX_ENTRIES) {
        printf("Enter income description: ");
        scanf(" %[^\n]", incomeEntries[*incomeCount].description);
        printf("Enter amount: ");
        scanf("%f", &incomeEntries[*incomeCount].amount);
        (*incomeCount)++;
        printf("Income added successfully!\n");
    } else {
        printf("Maximum income entries reached.\n");
    }
}

void addExpense(Entry expenseEntries[], int *expenseCount) {
    if (*expenseCount < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]", expenseEntries[*expenseCount].description);
        printf("Enter amount: ");
        scanf("%f", &expenseEntries[*expenseCount].amount);
        (*expenseCount)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum expense entries reached.\n");
    }
}

void calculateBalance(Entry incomeEntries[], int incomeCount, Entry expenseEntries[], int expenseCount) {
    float totalIncome = 0.0, totalExpense = 0.0;

    for (int i = 0; i < incomeCount; i++) {
        totalIncome += incomeEntries[i].amount;
    }

    for (int i = 0; i < expenseCount; i++) {
        totalExpense += expenseEntries[i].amount;
    }

    float balance = totalIncome - totalExpense;
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpense);
    printf("Current Balance: %.2f\n", balance);
}

void displaySummary(Entry incomeEntries[], int incomeCount, Entry expenseEntries[], int expenseCount) {
    printf("\nSummary of your finances:\n");
    printf("Income Entries:\n");

    for (int i = 0; i < incomeCount; i++) {
        printf("Description: %s, Amount: %.2f\n", incomeEntries[i].description, incomeEntries[i].amount);
    }

    printf("\nExpense Entries:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Description: %s, Amount: %.2f\n", expenseEntries[i].description, expenseEntries[i].amount);
    }

    calculateBalance(incomeEntries, incomeCount, expenseEntries, expenseCount);
}