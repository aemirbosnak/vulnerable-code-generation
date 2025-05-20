//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} FinanceTracker;

void addTransaction(FinanceTracker *tracker);
void displayTransactions(const FinanceTracker *tracker);
void displaySummary(const FinanceTracker *tracker);
void saveToFile(const FinanceTracker *tracker);
void loadFromFile(FinanceTracker *tracker);
void clearScreen();

int main() {
    FinanceTracker tracker = { .transactionCount = 0 };
    int choice;

    loadFromFile(&tracker);

    do {
        clearScreen();
        printf("Personal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Display Summary\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&tracker);
                break;
            case 2:
                displayTransactions(&tracker);
                break;
            case 3:
                displaySummary(&tracker);
                break;
            case 4:
                saveToFile(&tracker);
                break;
            case 5:
                loadFromFile(&tracker);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (choice != 0) {
            printf("Press Enter to continue...");
            getchar(); // To consume the new line character left in the input buffer
            getchar();
        }
    } while (choice != 0);

    return 0;
}

void addTransaction(FinanceTracker *tracker) {
    if (tracker->transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached! Cannot add more transactions.\n");
        return;
    }
    
    Transaction t;
    printf("Enter transaction name: ");
    getchar(); // Clear the newline character
    fgets(t.name, MAX_NAME_LENGTH, stdin);
    t.name[strcspn(t.name, "\n")] = 0; // Remove newline character

    printf("Enter transaction amount: ");
    scanf("%f", &t.amount);

    printf("Enter transaction category: ");
    getchar(); // Clear the newline character
    fgets(t.category, MAX_NAME_LENGTH, stdin);
    t.category[strcspn(t.category, "\n")] = 0; // Remove newline character

    tracker->transactions[tracker->transactionCount] = t;
    tracker->transactionCount++;
    printf("Transaction added successfully!\n");
}

void displayTransactions(const FinanceTracker *tracker) {
    if (tracker->transactionCount == 0) {
        printf("No transactions to display.\n");
        return;
    }
    
    printf("Transactions:\n");
    for (int i = 0; i < tracker->transactionCount; i++) {
        printf("%d. %s | %.2f | %s\n", i + 1, tracker->transactions[i].name, tracker->transactions[i].amount, tracker->transactions[i].category);
    }
}

void displaySummary(const FinanceTracker *tracker) {
    float totalIncome = 0.0;
    float totalExpense = 0.0;

    for (int i = 0; i < tracker->transactionCount; i++) {
        if (tracker->transactions[i].amount >= 0) {
            totalIncome += tracker->transactions[i].amount;
        } else {
            totalExpense += tracker->transactions[i].amount;
        }
    }

    printf("Summary:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpense);
    printf("Net Savings: %.2f\n", totalIncome + totalExpense);
}

void saveToFile(const FinanceTracker *tracker) {
    FILE *file = fopen("transactions.txt", "w");
    if (!file) {
        printf("Error saving to file!\n");
        return;
    }

    for (int i = 0; i < tracker->transactionCount; i++) {
        fprintf(file, "%s|%.2f|%s\n", tracker->transactions[i].name, tracker->transactions[i].amount, tracker->transactions[i].category);
    }

    fclose(file);
    printf("Transactions saved to file successfully!\n");
}

void loadFromFile(FinanceTracker *tracker) {
    FILE *file = fopen("transactions.txt", "r");
    if (!file) {
        printf("No saved transactions found.\n");
        return;
    }

    while (fscanf(file, "%[^|]|%f|%[^/]\n", tracker->transactions[tracker->transactionCount].name,
                  &tracker->transactions[tracker->transactionCount].amount,
                  tracker->transactions[tracker->transactionCount].category) != EOF) {
        tracker->transactionCount++;
        if (tracker->transactionCount >= MAX_TRANSACTIONS) {
            break; // Stop if we reach maximum transactions
        }
    }

    fclose(file);
    printf("Transactions loaded from file successfully!\n");
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}