//FormAI DATASET v1.0 Category: Banking Record System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct account{
    char holderName[MAX];
    int balance;
};

void createAccount(struct account *customer){
    printf("\nEnter account holder name: ");
    scanf(" %[^\n]", customer->holderName);
    printf("\nEnter initial balance: ");
    scanf("%d", &customer->balance);
    printf("\nAccount successfully created!\n");
}

void displayAccount(struct account *customer){
    printf("\n\nAccount holder name: %s", customer->holderName);
    printf("\nAccount balance: %d", customer->balance);
    printf("\n");
}

void deposit(struct account *customer){
    int amount;
    printf("\nEnter amount to deposit: ");
    scanf("%d", &amount);
    customer->balance += amount;
    printf("\nDeposit successful!\n");
    displayAccount(customer);
}

void withdraw(struct account *customer){
    int amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%d", &amount);
    if(amount>customer->balance){
        printf("\nInsufficient balance!\n");
    }
    else{
        customer->balance -= amount;
        printf("\nWithdrawal successful!\n");
        displayAccount(customer);
    }
}

int main(){
    int choice;
    struct account customer;
    memset(&customer,0,sizeof(customer));
    printf("\n-----Banking Record System-----\n");
    printf("\n1. Create account\n2. Deposit amount\n3. Withdraw amount\n4. Display account details\n5. Exit\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: createAccount(&customer);
                    break;
            case 2: deposit(&customer);
                    break;
            case 3: withdraw(&customer);
                    break;
            case 4: displayAccount(&customer);
                    break;
            case 5: printf("\nThanks for using the system!\n");
                    exit(0);
                    break;
            default: printf("\nInvalid choice! Please enter again.\n");
        }
    }while(choice!=5);
    return 0;
}