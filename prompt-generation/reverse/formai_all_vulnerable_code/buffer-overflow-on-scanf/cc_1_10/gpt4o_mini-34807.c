//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>

typedef struct {
    int accountNumber;
    char accountHolder[50];
    float balance;
} Account;

void displayMenu() {
    printf("\n--- ATM Menu ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

void checkBalance(Account account) {
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Current Balance: $%.2f\n", account.balance);
}

void depositMoney(Account *account) {
    float depositAmount;
    printf("Enter amount to deposit: $");
    scanf("%f", &depositAmount);
    if (depositAmount > 0) {
        account->balance += depositAmount;
        printf("Successfully deposited $%.2f. Current Balance: $%.2f\n", depositAmount, account->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdrawMoney(Account *account) {
    float withdrawAmount;
    printf("Enter amount to withdraw: $");
    scanf("%f", &withdrawAmount);
    if (withdrawAmount > 0 && withdrawAmount <= account->balance) {
        account->balance -= withdrawAmount;
        printf("Successfully withdrew $%.2f. Current Balance: $%.2f\n", withdrawAmount, account->balance);
    } else if (withdrawAmount > account->balance) {
        printf("Insufficient funds.\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

int main() {
    Account account = {12345678, "Ada Lovelace", 1000.00};
    int choice;
    
    printf("Welcome to the ATM System!\n");
    
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                checkBalance(account);
                break;
            case 2:
                depositMoney(&account);
                break;
            case 3:
                withdrawMoney(&account);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1-4.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}