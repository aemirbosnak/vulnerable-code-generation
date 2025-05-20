//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct account{
    char name[30];
    char type[10];
    long long int balance;
    int account_number;
    int pin;
};

void create_account(struct account *a){
    printf("Enter account name: ");
    scanf("%[^\n]",a->name);
    printf("Enter account type (Savings/Current): ");
    scanf("%[^\n]",a->type);
    a->account_number = rand()%10000;
    a->pin = rand()%1000;
    a->balance = 0;
    printf("Your account has been created.\n");
}

void deposit(struct account *a){
    printf("Enter amount to deposit: ");
    scanf("%lld",&a->balance);
    printf("Deposit successful.\n");
}

void withdraw(struct account *a){
    printf("Enter amount to withdraw: ");
    scanf("%lld",&a->balance);
    printf("Withdrawal successful.\n");
}

void check_balance(struct account *a){
    printf("Your current balance is: %lld\n",a->balance);
}

int main(){
    struct account a;
    int choice,pin_correct = 0;
    char pin[5];
    while(1){
        printf("\nEnter your account number: ");
        scanf("%d",&a.account_number);
        printf("Enter your PIN: ");
        scanf("%s",pin);
        if(strcmp(pin,"1234")==0){
            pin_correct = 1;
            break;
        }
        else{
            printf("Invalid PIN. Try again.\n");
        }
    }
    while(1){
        printf("\nWhat would you like to do?\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                deposit(&a);
                break;
            case 2:
                withdraw(&a);
                break;
            case 3:
                check_balance(&a);
                break;
            case 4:
                printf("Thank you for using our services.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}