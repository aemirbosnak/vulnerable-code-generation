//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Bank_Record{
    char name[50];
    int accnum;
    float balance;
};

void deposit(struct Bank_Record* record, float amount){
    record->balance += amount;
    printf("\nAmount deposited successfully! Your new balance is: %.2f\n", record->balance);
}

void withdraw(struct Bank_Record* record, float amount){
    if(record->balance < amount){
        printf("\nInsufficient balance! Current balance: %.2f\n", record->balance);
    }else{
        record->balance -= amount;
        printf("\nAmount withdrawn successfully! Your new balance is: %.2f\n", record->balance);
    }
}

int main(){

    printf("-----------------------\n");
    printf("Welcome to Bank Record System\n");
    printf("-----------------------\n");
    printf("\n");

    struct Bank_Record record = {"John Doe", 123456, 500.00};
    int choice;
    float amount;

    while(1){
        printf("\nHi %s, What would you like to do?\n", record.name);
        printf("\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nYour current balance is: %.2f\n", record.balance);
                break;
            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&record, amount);
                break;
            case 3:
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&record, amount);
                break;
            case 4:
                printf("\nGoodbye %s! Thank you for using our system.\n", record.name);
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}