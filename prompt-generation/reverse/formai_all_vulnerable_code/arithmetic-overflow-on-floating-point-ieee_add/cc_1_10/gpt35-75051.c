//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include<stdio.h>

struct bank_record{
    int account_no;
    char name[20];
    float balance;
    int pin;
};

void add_record(struct bank_record *b){
    printf("Enter account number: ");
    scanf("%d", &b->account_no);
    printf("Enter name: ");
    scanf("%s", b->name);
    printf("Enter balance: ");
    scanf("%f", &b->balance);
    printf("Enter pin: ");
    scanf("%d", &b->pin);
}

void display_record(struct bank_record b){
    printf("\nAccount number: %d\n", b.account_no);
    printf("Name: %s\n", b.name);
    printf("Balance: %.2f\n", b.balance);
}

void deposit(struct bank_record *b, float amount){
    b->balance += amount;
}

void withdraw(struct bank_record *b, float amount){
    if(amount > b->balance){
        printf("Insufficient balance!\n");
        return;
    }
    b->balance -= amount;
}

int main(){
    int option;
    struct bank_record b1;

    printf("Welcome to Modular Bank Record System!\n");

    printf("Enter account details:\n");
    add_record(&b1);

    while(1){
        printf("\n1. Display record\n2. Deposit\n3. Withdraw\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                display_record(b1);
                break;
            case 2:
                {
                    float amount; 
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount);
                    deposit(&b1, amount);
                    printf("Deposit successfully completed!\n");
                    break;
                }
            case 3:
                {
                    float amount;
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount);
                    withdraw(&b1, amount);
                    printf("Withdrawal successfully completed!\n");
                    break;
                }
            case 4:
                printf("Thank you for using Modular Bank Record System!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}