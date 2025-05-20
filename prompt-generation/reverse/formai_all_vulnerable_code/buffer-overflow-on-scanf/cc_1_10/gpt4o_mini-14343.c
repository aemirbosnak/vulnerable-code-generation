//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LENGTH 256

// Struct to represent a financial entry
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    char type; // 'I' for income, 'E' for expense
} Entry;

// Function prototypes
void addEntry(Entry entries[], int *count);
void displayEntries(const Entry entries[], int count);
void analyzeFinance(const Entry entries[], int count);
void menu();

// Main function
int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                displayEntries(entries, count);
                break;
            case 3:
                analyzeFinance(entries, count);
                break;
            case 4:
                printf("Exit from the Financial Planner has been initiated. Farewell, dear user!\n");
                exit(0);
            default:
                printf("Elementary, dear user! Please choose a valid option!\n");
        }
    }
    return 0;
}

// Function to display the menu
void menu() {
    printf("\n--- Sherlock Holmes Personal Finance Planner ---\n");
    printf("1. Add a financial entry\n");
    printf("2. Display all financial entries\n");
    printf("3. Analyze your finances\n");
    printf("4. Exit\n");
}

// Function to add a financial entry
void addEntry(Entry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Alas! You have reached the maximum number of entries.\n");
        return;
    }

    printf("Enter a description for the entry: ");
    getchar(); // Clean the newline buffer
    fgets(entries[*count].description, MAX_DESCRIPTION_LENGTH, stdin);
    entries[*count].description[strcspn(entries[*count].description, "\n")] = 0; // Remove newline

    printf("Enter the amount (positive for income, negative for expense): ");
    scanf("%f", &entries[*count].amount);

    printf("Enter the type of entry (I for income, E for expense): ");
    getchar(); // Clean the newline buffer
    entries[*count].type = getchar();

    (*count)++;
    printf("Entry recorded with precision, just like a well-planned deduction!\n");
}

// Function to display all entries
void displayEntries(const Entry entries[], int count) {
    if (count == 0) {
        printf("Your financial ledger is empty, yet the mysteries of finance await!\n");
        return;
    }

    printf("\n-- Financial Entries --\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s | Amount: %.2f | Type: %c\n", i + 1, entries[i].description, entries[i].amount, entries[i].type);
    }
}

// Function to analyze finances
void analyzeFinance(const Entry entries[], int count) {
    float totalIncome = 0.0f, totalExpense = 0.0f;

    for (int i = 0; i < count; i++) {
        if (entries[i].type == 'I') {
            totalIncome += entries[i].amount;
        } else if (entries[i].type == 'E') {
            totalExpense += entries[i].amount;
        }
    }

    printf("\n--- Financial Analysis ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", totalIncome + totalExpense);
    
    if (totalIncome + totalExpense > 0) {
        printf("Elementary, my dear user! You are currently in good financial standing!\n");
    } else {
        printf("A deduction indeed, dear user. It seems you ought to curb your expenses.\n");
    }
}