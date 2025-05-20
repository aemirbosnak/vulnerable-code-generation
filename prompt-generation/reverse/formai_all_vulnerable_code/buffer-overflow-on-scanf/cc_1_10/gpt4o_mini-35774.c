//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
    float invest;
} PersonalFinance;

void displayMenu();
void addEntry(PersonalFinance *pf);
void viewEntries(PersonalFinance *pfArray, int count);
float calculateNetWorth(PersonalFinance *pf);

int main() {
    PersonalFinance *pfArray;
    int numEntries = 0, capacity = 2;
    char choice;

    pfArray = malloc(capacity * sizeof(PersonalFinance));
    if (!pfArray) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (1) {
        displayMenu();
        choice = getchar();
        while (getchar() != '\n');  // Clear input buffer

        switch (choice) {
            case '1':
                if (numEntries == capacity) {
                    capacity *= 2;
                    pfArray = realloc(pfArray, capacity * sizeof(PersonalFinance));
                    if (!pfArray) {
                        fprintf(stderr, "Memory allocation failed\n");
                        return 1;
                    }
                }
                addEntry(&pfArray[numEntries]);
                numEntries++;
                break;
            case '2':
                viewEntries(pfArray, numEntries);
                break;
            case '3':
                for (int i = 0; i < numEntries; i++) {
                    printf("Net Worth of %s: $%.2f\n", pfArray[i].name, calculateNetWorth(&pfArray[i]));
                }
                break;
            case '4':
                free(pfArray);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n--- Personal Finance Planner Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Calculate Net Worth\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void addEntry(PersonalFinance *pf) {
    printf("Enter your name: ");
    fgets(pf->name, sizeof(pf->name), stdin);
    pf->name[strcspn(pf->name, "\n")] = 0;  // Remove newline character

    printf("Enter your monthly income: $");
    scanf("%f", &pf->income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &pf->expenses);
    printf("Enter your monthly savings: $");
    scanf("%f", &pf->savings);
    printf("Enter your investments: $");
    scanf("%f", &pf->invest);
    
    while (getchar() != '\n');  // Clear input buffer
}

void viewEntries(PersonalFinance *pfArray, int count) {
    printf("\n--- List of Personal Finance Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", pfArray[i].name);
        printf("Income: $%.2f\n", pfArray[i].income);
        printf("Expenses: $%.2f\n", pfArray[i].expenses);
        printf("Savings: $%.2f\n", pfArray[i].savings);
        printf("Investments: $%.2f\n\n", pfArray[i].invest);
    }
}

float calculateNetWorth(PersonalFinance *pf) {
    return pf->income - pf->expenses + pf->savings + pf->invest;
}