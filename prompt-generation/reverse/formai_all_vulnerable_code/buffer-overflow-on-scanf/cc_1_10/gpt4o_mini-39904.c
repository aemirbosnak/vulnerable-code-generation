//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 50

typedef struct {
    char category[30];
    float amount;
    char date[11];  // Format: YYYY-MM-DD
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int transaction_count;
} PersonalFinance;

void initializeFinance(PersonalFinance *pf) {
    pf->transaction_count = 0;
}

void addTransaction(PersonalFinance *pf) {
    if (pf->transaction_count >= MAX_TRANSACTIONS) {
        printf("Oops! You can't add more transactions. Max limit reached!\n");
        return;
    }
    
    Transaction newTransaction;
    printf("🎉 Let's add a new transaction! 🎉\n");
    
    printf("Enter category: ");
    scanf(" %[^\n]", newTransaction.category);
    
    printf("Enter amount: ");
    scanf("%f", &newTransaction.amount);
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %10s", newTransaction.date);
    
    pf->transactions[pf->transaction_count] = newTransaction;
    pf->transaction_count++;
    
    printf("✅ Transaction added successfully!\n");
}

void viewTransactions(PersonalFinance *pf) {
    printf("\n📊 Your Transactions 📊\n");
    if (pf->transaction_count == 0) {
        printf("No transactions to display! Go ahead and add some! 😊\n");
        return;
    }
    
    for (int i = 0; i < pf->transaction_count; i++) {
        printf("Category: %s | Amount: $%.2f | Date: %s\n", 
            pf->transactions[i].category, 
            pf->transactions[i].amount, 
            pf->transactions[i].date);
    }
}

void calculateExpenses(PersonalFinance *pf) {
    float total = 0.0;
    for (int i = 0; i < pf->transaction_count; i++) {
        total += pf->transactions[i].amount;
    }
    
    printf("\n💰 Your Total Expenses: $%.2f 💰\n", total);
}

void printMenu() {
    printf("\n--------------------\n");
    printf("👛 Personal Finance Planner 👛\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("--------------------\n");
    printf("Choose an option: ");
}

int main() {
    PersonalFinance finance;
    initializeFinance(&finance);
    
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addTransaction(&finance);
                break;
            case 2:
                viewTransactions(&finance);
                break;
            case 3:
                calculateExpenses(&finance);
                break;
            case 4:
                printf("🎈 Thanks for using the Personal Finance Planner! Goodbye! 🎈\n");
                break;
            default:
                printf("Invalid choice! Please choose again! 😅\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}