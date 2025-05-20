//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceManager;

void initializeFinanceManager(FinanceManager* fm) {
    fm->count = 0;
}

void addTransaction(FinanceManager* fm, const char* name, float amount) {
    if (fm->count < MAX_TRANSACTIONS) {
        strcpy(fm->transactions[fm->count].name, name);
        fm->transactions[fm->count].amount = amount;
        fm->count++;
    } else {
        printf("Transaction limit reached. Cannot add more transactions.\n");
    }
}

void displayTransactions(const FinanceManager* fm) {
    printf("\n--- Transaction List ---\n");
    for (int i = 0; i < fm->count; i++) {
        printf("%d: %s - %.2f\n", i + 1, fm->transactions[i].name, fm->transactions[i].amount);
    }
    printf("------------------------\n");
}

float calculateTotal(const FinanceManager* fm) {
    float total = 0.0;
    for (int i = 0; i < fm->count; i++) {
        total += fm->transactions[i].amount;
    }
    return total;
}

void saveTransactionsToFile(const FinanceManager* fm, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving transactions.\n");
        return;
    }

    for (int i = 0; i < fm->count; i++) {
        fprintf(file, "%s,%.2f\n", fm->transactions[i].name, fm->transactions[i].amount);
    }
    fclose(file);
    printf("Transactions saved to %s.\n", filename);
}

void loadTransactionsFromFile(FinanceManager* fm, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading transactions.\n");
        return;
    }
    
    while (!feof(file) && fm->count < MAX_TRANSACTIONS) {
        char line[100];
        if (fgets(line, sizeof(line), file)) {
            char name[MAX_NAME_LENGTH];
            float amount;
            sscanf(line, "%49[^,],%f", name, &amount);
            addTransaction(fm, name, amount);
        }
    }
    fclose(file);
    printf("Transactions loaded from %s.\n", filename);
}

int main() {
    FinanceManager fm;
    initializeFinanceManager(&fm);
    
    int choice;
    char name[MAX_NAME_LENGTH];
    float amount;
    char filename[100];
    
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Calculate Total\n");
        printf("4. Save Transactions to File\n");
        printf("5. Load Transactions from File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter transaction name: ");
                scanf(" %49[^\n]", name);
                printf("Enter transaction amount: ");
                scanf("%f", &amount);
                addTransaction(&fm, name, amount);
                break;
            case 2:
                displayTransactions(&fm);
                break;
            case 3:
                printf("Total Amount: %.2f\n", calculateTotal(&fm));
                break;
            case 4:
                printf("Enter filename to save: ");
                scanf(" %99s", filename);
                saveTransactionsToFile(&fm, filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                scanf(" %99s", filename);
                loadTransactionsFromFile(&fm, filename);
                break;
            case 0:
                printf("Exiting planner. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}