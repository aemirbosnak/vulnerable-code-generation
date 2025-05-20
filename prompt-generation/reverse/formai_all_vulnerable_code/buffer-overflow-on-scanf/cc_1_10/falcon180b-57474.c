//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    char name[50];
    int acc_no;
    float balance;
};

void create_account(struct account *a);
void deposit(struct account *a);
void withdraw(struct account *a);
void check_balance(struct account *a);
void close_account(struct account *a);

int main(){
    int choice,i;
    struct account a[10];
    for(i=0;i<10;i++){
        a[i].acc_no=i+1;
        a[i].balance=0.0;
    }
    do{
        printf("\nBanking Record System\n");
        printf("1.Create Account\n2.Deposit\n3.Withdraw\n4.Check Balance\n5.Close Account\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter account holder name: ");
                scanf("%s",a[0].name);
                printf("Account created successfully with account number %d\n",a[0].acc_no);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d",&i);
                if(i>=1 && i<=10){
                    printf("Enter amount to be deposited: ");
                    scanf("%f",&a[i-1].balance);
                    printf("Deposit successful\n");
                }
                else{
                    printf("Invalid account number\n");
                }
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d",&i);
                if(i>=1 && i<=10){
                    printf("Enter amount to be withdrawn: ");
                    scanf("%f",&a[i-1].balance);
                    if(a[i-1].balance>=a[i-1].balance){
                        printf("Withdrawal successful\n");
                    }
                    else{
                        printf("Insufficient balance\n");
                    }
                }
                else{
                    printf("Invalid account number\n");
                }
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d",&i);
                if(i>=1 && i<=10){
                    printf("Account balance: %.2f\n",a[i-1].balance);
                }
                else{
                    printf("Invalid account number\n");
                }
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d",&i);
                if(i>=1 && i<=10){
                    close_account(&a[i-1]);
                }
                else{
                    printf("Invalid account number\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}

void create_account(struct account *a){
    strcpy(a->name,"");
    a->acc_no=0;
    a->balance=0.0;
}

void deposit(struct account *a){
    a->balance+=0.0;
}

void withdraw(struct account *a){
    a->balance-=0.0;
}

void check_balance(struct account *a){
    printf("Account balance: %.2f\n",a->balance);
}

void close_account(struct account *a){
    printf("Account closed successfully\n");
}