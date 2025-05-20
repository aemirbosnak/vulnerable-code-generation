//FormAI DATASET v1.0 Category: Banking Record System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct bank_record{
    long long int account_number;
    char name[MAX];
    double balance;
};

void print_records(struct bank_record cust_records[], int n);
void find_customer(struct bank_record cust_records[], int n, long long int acct_num);
void deposit(struct bank_record cust_records[], int n, long long int acct_num, double amt);
void withdrawal(struct bank_record cust_records[], int n, long long int acct_num, double amt);

int main(){
    struct bank_record customer_records[MAX];
    int n,choice,i;
    long long int acct_num;
    double amt;

    printf("Enter number of customers: ");
    scanf("%d",&n);

    printf("Enter customer records:\n");

    for(i=0;i<n;i++){
        printf("Customer %d:\n",i+1);

        printf("Account Number: ");
        scanf("%lld",&customer_records[i].account_number);

        printf("Name: ");
        scanf(" %[^\n]", customer_records[i].name);

        printf("Balance: ");
        scanf("%lf",&customer_records[i].balance);
    }

    do{
        printf("\nBanking Record System Menu:\n");
        printf("1. Display all records\n");
        printf("2. Find a customer\n");
        printf("3. Deposit\n");
        printf("4. Withdrawal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                print_records(customer_records,n);
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%lld",&acct_num);
                find_customer(customer_records,n,acct_num);
                break;
            
            case 3:
                printf("Enter account number: ");
                scanf("%lld",&acct_num);
                printf("Enter amount to deposit: ");
                scanf("%lf",&amt);
                deposit(customer_records,n,acct_num,amt);
                break;

            case 4:
                printf("Enter account number: ");
                scanf("%lld",&acct_num);
                printf("Enter amount to withdraw: ");
                scanf("%lf",&amt);
                withdrawal(customer_records,n,acct_num,amt);
                break;

            case 5:
                printf("Program terminated!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
        
    }while(choice!=5);

    return 0;
}

void print_records(struct bank_record cust_records[], int n){
    int i;
    printf("Account Number\tName\tBalance\n");
    for(i=0;i<n;i++){
        printf("%lld\t%s\t%.2lf\n", cust_records[i].account_number, cust_records[i].name, cust_records[i].balance);
    }
}

void find_customer(struct bank_record cust_records[], int n, long long int acct_num){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(cust_records[i].account_number==acct_num){
            flag=1;
            printf("Account Number: %lld\nName: %s\nBalance: %.2lf\n", 
                    cust_records[i].account_number, cust_records[i].name, cust_records[i].balance);
            break;
        }
    }
    if(flag==0){
        printf("Customer not found in records!\n");
    }
}

void deposit(struct bank_record cust_records[], int n, long long int acct_num, double amt){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(cust_records[i].account_number==acct_num){
            flag=1;
            cust_records[i].balance+=amt;
            printf("Amount deposited successfully!\nNew balance: %.2lf\n",cust_records[i].balance);
            break;
        }
    }
    if(flag==0){
        printf("Customer not found in records!\n");
    }
}

void withdrawal(struct bank_record cust_records[], int n, long long int acct_num, double amt){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(cust_records[i].account_number==acct_num){
            flag=1;
            if(cust_records[i].balance<amt){
                printf("Insufficient balance!\n");
            }
            else{
                cust_records[i].balance-=amt;
                printf("Amount withdrawn successfully!\nNew balance: %.2lf\n",cust_records[i].balance);
            }
            break;
        }
    }
    if(flag==0){
        printf("Customer not found in records!\n");
    }
}