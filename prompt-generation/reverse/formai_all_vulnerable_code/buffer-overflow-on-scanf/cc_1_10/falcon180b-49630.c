//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct account{
    int account_number;
    char name[30];
    float balance;
};

void create_account(struct account *acc);
void deposit_money(struct account *acc);
void withdraw_money(struct account *acc);
void check_balance(struct account *acc);

int main(){
    struct account account;
    int choice;

    printf("Welcome to the Post-Apocalyptic Banking System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                create_account(&account);
                break;

            case 2:
                deposit_money(&account);
                break;

            case 3:
                withdraw_money(&account);
                break;

            case 4:
                check_balance(&account);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void create_account(struct account *acc){
    printf("Enter your name: ");
    scanf("%s",acc->name);

    printf("Enter your account number: ");
    scanf("%d",&acc->account_number);

    printf("Account created successfully!\n");
}

void deposit_money(struct account *acc){
    printf("Enter the amount to deposit: ");
    scanf("%f",&acc->balance);

    printf("Deposit successful!\n");
}

void withdraw_money(struct account *acc){
    printf("Enter the amount to withdraw: ");
    scanf("%f",&acc->balance);

    if(acc->balance < 0){
        printf("Insufficient balance!\n");
    }else{
        printf("Withdrawal successful!\n");
    }
}

void check_balance(struct account *acc){
    printf("Your current balance is: %.2f\n",acc->balance);
}