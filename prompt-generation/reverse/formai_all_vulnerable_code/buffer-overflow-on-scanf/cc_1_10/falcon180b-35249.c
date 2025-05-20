//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

// Creating a structure for Bank Account
struct BankAccount{
    int accountNumber;
    char name[50];
    char address[100];
    float balance;
};

// Function to create a new account
void createAccount(struct BankAccount *account){
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your address: ");
    scanf("%s", account->address);
    account->accountNumber = rand() % 1000; // Generating random account number
    account->balance = 0.0;
    printf("Your account number is %d\n", account->accountNumber);
}

// Function to deposit money
void depositMoney(struct BankAccount *account){
    printf("Enter amount to deposit: ");
    scanf("%f", &account->balance);
    account->balance += rand() % 100; // Adding some random amount to the balance
    printf("Amount deposited successfully. Your new balance is %.2f\n", account->balance);
}

// Function to withdraw money
void withdrawMoney(struct BankAccount *account){
    printf("Enter amount to withdraw: ");
    scanf("%f", &account->balance);
    if(account->balance - rand() % 100 < 0){
        printf("Insufficient balance\n");
    }
    else{
        account->balance -= rand() % 100; // Deducting some random amount from the balance
        printf("Amount withdrawn successfully. Your new balance is %.2f\n", account->balance);
    }
}

// Function to check balance
void checkBalance(struct BankAccount *account){
    printf("Your current balance is %.2f\n", account->balance);
}

// Main function
int main(){
    struct BankAccount account;
    int choice;
    do{
        printf("Enter 1 to create account\n");
        printf("Enter 2 to deposit money\n");
        printf("Enter 3 to withdraw money\n");
        printf("Enter 4 to check balance\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                createAccount(&account);
                break;
            case 2:
                depositMoney(&account);
                break;
            case 3:
                withdrawMoney(&account);
                break;
            case 4:
                checkBalance(&account);
                break;
            case 0:
                printf("Thank you for using our banking services.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!= 0);
    return 0;
}