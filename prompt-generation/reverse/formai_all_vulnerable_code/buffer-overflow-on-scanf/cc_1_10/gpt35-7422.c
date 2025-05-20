//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[20];
    int accountNumber;
    double balance;
} Account;

void deposit(Account *account, double amount){
    account->balance += amount;
    printf("\nDeposit of %.2lf Successful!\nNew Balance: %.2lf\n", amount, account->balance);
}

void withdraw(Account *account, double amount){
    if(account->balance < amount){
        printf("\nWithdrawal Failed! Not enough balance.\n");
    }
    else{
        account->balance -= amount;
        printf("\nWithdrawal of %.2lf Successful!\nNew Balance: %.2lf\n", amount, account->balance);
    }
}

void transfer(Account *sender, Account *receiver, double amount){
    if(sender->balance < amount){
        printf("\nTransfer Failed! Not enough balance.\n");
    }
    else{
        sender->balance -= amount;
        receiver->balance += amount;
        printf("\nTransfer of %.2lf Successful!\nSender's New Balance: %.2lf\nReceiver's New Balance: %.2lf\n", amount, sender->balance, receiver->balance);
    }
}

int main(){
    int choice;
    int numOfAccounts = 0;
    Account *accounts = NULL;
    
    while(1){
        printf("\n========= BANKING RECORD SYSTEM =========\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                numOfAccounts++;
                accounts = (Account*)realloc(accounts, numOfAccounts * sizeof(Account));
                printf("\nEnter account holder name: ");
                scanf("%s", accounts[numOfAccounts-1].name);
                printf("Enter account number: ");
                scanf("%d", &accounts[numOfAccounts-1].accountNumber);
                accounts[numOfAccounts-1].balance = 0;
                printf("\nAccount Created Successfully!\n");
                break;
            }
            case 2:{
                int accountNum;
                printf("\nEnter account number: ");
                scanf("%d", &accountNum);
                
                int accountIndex = -1;
                for(int i=0; i<numOfAccounts; i++){
                    if(accounts[i].accountNumber == accountNum){
                        accountIndex = i;
                        break;
                    }
                }
                if(accountIndex == -1){
                    printf("\nAccount not found!\n");
                }
                else{
                    double amount;
                    printf("Enter deposit amount: ");
                    scanf("%lf", &amount);
                    deposit(&accounts[accountIndex], amount);
                }
                break;
            }
            case 3:{
                int accountNum;
                printf("\nEnter account number: ");
                scanf("%d", &accountNum);
                
                int accountIndex = -1;
                for(int i=0; i<numOfAccounts; i++){
                    if(accounts[i].accountNumber == accountNum){
                        accountIndex = i;
                        break;
                    }
                }
                if(accountIndex == -1){
                    printf("\nAccount not found!\n");
                }
                else{
                    double amount;
                    printf("Enter withdrawal amount: ");
                    scanf("%lf", &amount);
                    withdraw(&accounts[accountIndex], amount);
                }
                break;
            }
            case 4:{
                int senderNum, receiverNum;
                printf("\nEnter sender's account number: ");
                scanf("%d", &senderNum);
                printf("Enter receiver's account number: ");
                scanf("%d", &receiverNum);
                
                int senderIndex = -1, receiverIndex = -1;
                for(int i=0; i<numOfAccounts; i++){
                    if(accounts[i].accountNumber == senderNum){
                        senderIndex = i;
                    }
                    if(accounts[i].accountNumber == receiverNum){
                        receiverIndex = i;
                    }
                    if(senderIndex != -1 && receiverIndex != -1){
                        break;
                    }
                }
                if(senderIndex == -1){
                    printf("\nSender account not found!\n");
                }
                else if(receiverIndex == -1){
                    printf("\nReceiver account not found!\n");
                }
                else{
                    double amount;
                    printf("Enter transfer amount: ");
                    scanf("%lf", &amount);
                    transfer(&accounts[senderIndex], &accounts[receiverIndex], amount);
                }
                break;
            }
            case 5:{
                printf("\nThank you for using Banking Record System!\n");
                exit(0);
            }
            default:{
                printf("\nInvalid choice. Try again!\n");
            }
        }
    }
    return 0;
}