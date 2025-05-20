//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LEN 50

typedef struct {
    char description[MAX_DESCRIPTION_LEN];
    float amount;
} Transaction;

typedef struct {
    float balance;
    Transaction transactions[MAX_ENTRIES];
    int transaction_count;
} PersonalFinance;

void initFinance(PersonalFinance *pf) {
    pf->balance = 0.0;
    pf->transaction_count = 0;
}

void addTransaction(PersonalFinance *pf, const char *description, float amount) {
    if (pf->transaction_count < MAX_ENTRIES) {
        strncpy(pf->transactions[pf->transaction_count].description, description, MAX_DESCRIPTION_LEN);
        pf->transactions[pf->transaction_count].amount = amount;
        pf->transaction_count++;
        pf->balance += amount;
    } else {
        printf("Transaction limit reached.\n");
    }
}

void viewTransactions(PersonalFinance *pf) {
    printf("Transactions:\n");
    for (int i = 0; i < pf->transaction_count; i++) {
        printf("%d: %s - %.2f\n", i + 1, pf->transactions[i].description, pf->transactions[i].amount);
    }
}

void viewBalance(PersonalFinance *pf) {
    printf("Current Balance: %.2f\n", pf->balance);
}

void saveToFile(PersonalFinance *pf, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(pf, sizeof(PersonalFinance), 1, file);
        fclose(file);
        printf("Data saved to %s\n", filename);
    } else {
        perror("Failed to save data");
    }
}

void loadFromFile(PersonalFinance *pf, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        fread(pf, sizeof(PersonalFinance), 1, file);
        fclose(file);
        printf("Data loaded from %s\n", filename);
    } else {
        perror("Failed to load data");
    }
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. View Balance\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    PersonalFinance pf;
    initFinance(&pf);
    int option;
    char description[MAX_DESCRIPTION_LEN];
    float amount;
    char filename[100];

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter description: ");
                scanf(" %[^\n]", description); // Read string with spaces
                printf("Enter amount: ");
                scanf("%f", &amount);
                addTransaction(&pf, description, amount);
                break;
            case 2:
                viewTransactions(&pf);
                break;
            case 3:
                viewBalance(&pf);
                break;
            case 4:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveToFile(&pf, filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadFromFile(&pf, filename);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}