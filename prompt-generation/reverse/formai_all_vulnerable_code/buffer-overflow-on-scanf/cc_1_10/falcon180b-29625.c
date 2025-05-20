//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define MAX 100
#define SIZE 100

struct account{
    int acc_no;
    char name[SIZE];
    char address[SIZE];
    char phone[10];
    float balance;
    time_t timestamp;
};

struct account acc[MAX];

void deposit(){
    int choice,i;
    float amt;

    printf("\nEnter account number: ");
    scanf("%d",&choice);

    for(i=0;i<MAX;i++){
        if(acc[i].acc_no==choice){
            printf("\nEnter amount to deposit: ");
            scanf("%f",&amt);
            acc[i].balance+=amt;
            acc[i].timestamp=time(0);
            printf("\nDeposit successful!");
            return;
        }
    }

    printf("\nAccount not found!");
}

void withdraw(){
    int choice,i;
    float amt;

    printf("\nEnter account number: ");
    scanf("%d",&choice);

    for(i=0;i<MAX;i++){
        if(acc[i].acc_no==choice){
            printf("\nEnter amount to withdraw: ");
            scanf("%f",&amt);

            if(amt>acc[i].balance){
                printf("\nInsufficient balance!");
                return;
            }

            acc[i].balance-=amt;
            acc[i].timestamp=time(0);
            printf("\nWithdrawal successful!");
            return;
        }
    }

    printf("\nAccount not found!");
}

void display(){
    int choice;

    printf("\nEnter account number: ");
    scanf("%d",&choice);

    for(int i=0;i<MAX;i++){
        if(acc[i].acc_no==choice){
            printf("\nAccount Number: %d",acc[i].acc_no);
            printf("\nName: %s",acc[i].name);
            printf("\nAddress: %s",acc[i].address);
            printf("\nPhone Number: %s",acc[i].phone);
            printf("\nBalance: %.2f",acc[i].balance);
            printf("\nTimestamp: %s",ctime(&acc[i].timestamp));
        }
    }
}

int main(){
    int choice;

    while(1){
        printf("\n\nBanking Record System\n");
        printf("1. Deposit\n2. Withdraw\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                deposit();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}