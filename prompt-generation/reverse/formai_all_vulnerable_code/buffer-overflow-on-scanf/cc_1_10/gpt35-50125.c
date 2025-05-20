//FormAI DATASET v1.0 Category: Banking Record System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} record;

void deposit(record *cur_record,float amount){
    cur_record->balance+=amount;
    printf("Deposited Rs. %.2f\n",amount);
    printf("New balance: Rs. %.2f\n",cur_record->balance);
}

void withdraw(record *cur_record,float amount){
    if(cur_record->balance>=amount){
        cur_record->balance-=amount;
        printf("Withdrawn Rs. %.2f\n",amount);
        printf("New balance: Rs. %.2f\n",cur_record->balance);
    }
    else{
        printf("Withdrawal failed! Insufficient balance.\n");
    }
}

void display(record cur_record){
    printf("Account details:\n");
    printf("Name: %s\n",cur_record.name);
    printf("Account number: %d\n",cur_record.account_number);
    printf("Balance: Rs. %.2f\n",cur_record.balance);
}

int main(){
    record customer;
    strcpy(customer.name,"John Doe");
    customer.account_number=123456789;
    customer.balance=5000.00;

    printf("\nWelcome, %s!\n\n",customer.name);

    printf("Press 1 to deposit money.\n");
    printf("Press 2 to withdraw money.\n");
    printf("Press 3 to display account details.\n");
    printf("Press 0 to exit.\n");

    int opt;
    float amount;

    do{
        printf("\nEnter your choice: ");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                printf("\nEnter amount to deposit: Rs. ");
                scanf("%f",&amount);
                deposit(&customer,amount);
                break;
            case 2:
                printf("\nEnter amount to withdraw: Rs. ");
                scanf("%f",&amount);
                withdraw(&customer,amount);
                break;
            case 3:
                display(customer);
                break;
            case 0:
                printf("Thank you for using our banking system!");
                break;
            default:
                printf("Invalid input! Please try again.");
        }
    }while(opt!=0);

    return 0;
}