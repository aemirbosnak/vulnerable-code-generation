//FormAI DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for Bank account
struct Account {
    int accNo;
    char holder[50];
    float balance;
};

// Function to add account
void createNewAccount(struct Account *acc) {
    printf("\nEnter Account Number: ");
    scanf("%d",&acc->accNo);
    printf("\nEnter Account Holder Name: ");
    scanf("%s",acc->holder);
    printf("\nEnter Initial Balance: ");
    scanf("%f",&acc->balance);
}

// Function to display account details
void displayAccount(struct Account *acc) {
    printf("\nAccount Number: %d",acc->accNo);
    printf("\nAccount Holder Name: %s",acc->holder);
    printf("\nAccount Balance: %.2f",acc->balance);
}

// Function to deposit money in account
void depositMoney(struct Account *acc) {
    float amount;
    printf("\nEnter Amount to be Deposited: ");
    scanf("%f",&amount);
    acc->balance += amount;
    printf("\nUpdated Balance: %.2f",acc->balance);
}

// Function to withdraw money from account
void withdrawMoney(struct Account *acc) {
    float amount;
    printf("\nEnter Amount to be Withdrawn: ");
    scanf("%f",&amount);
    if(amount > acc->balance) {
        printf("\nInsufficient Balance!");
        return;
    }
    acc->balance -= amount;
    printf("\nUpdated Balance: %.2f",acc->balance);
}

int main() {
    int option;
    struct Account acc;
    memset(&acc,0,sizeof(acc));
    printf("\n------ Bank Account System ------");
    do {
        printf("\n\n1. Create New Account\n2. Display Account Details\n3. Deposit Money\n4. Withdraw Money\n5. Quit\n");
        printf("\nEnter Your Option: ");
        scanf("%d",&option);
        switch(option) {
            case 1 :
                createNewAccount(&acc);
                break;
            case 2 :
                displayAccount(&acc);
                break;
            case 3 :
                depositMoney(&acc);
                break;
            case 4 :
                withdrawMoney(&acc);
                break;
            case 5 :
                printf("\nThank You for Using Our System!");
                break;
            default :
                printf("\nInvalid Option! Please Try Again!");
        }
    } while(option != 5);
    return 0;
}