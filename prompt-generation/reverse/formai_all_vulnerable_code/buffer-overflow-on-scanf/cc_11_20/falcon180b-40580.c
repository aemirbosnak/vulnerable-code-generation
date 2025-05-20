//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct account{
    char name[50];
    char acc_no[10];
    int balance;
};

int main(){
    int choice,i=0,j=0;
    char ch;
    struct account bank[MAX];

    while(1){
        system("clear");
        printf("\n\n\t\t\tBANKING RECORD SYSTEM\n\n");
        printf("Enter 1 to create a new account\n");
        printf("Enter 2 to deposit money\n");
        printf("Enter 3 to withdraw money\n");
        printf("Enter 4 to check balance\n");
        printf("Enter 5 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(i>=MAX){
                    printf("All accounts are full\n");
                }
                else{
                    printf("Enter name of account holder\n");
                    scanf("%s",bank[i].name);
                    printf("Enter account number\n");
                    scanf("%s",bank[i].acc_no);
                    printf("Account created successfully\n");
                    i++;
                }
                break;
            case 2:
                printf("Enter account number\n");
                scanf("%s",ch);
                for(j=0;j<i;j++){
                    if(strcmp(bank[j].acc_no,ch)==0){
                        printf("Enter amount to be deposited\n");
                        scanf("%d",&bank[j].balance);
                        printf("Amount deposited successfully\n");
                        break;
                    }
                }
                if(j==i){
                    printf("Account not found\n");
                }
                break;
            case 3:
                printf("Enter account number\n");
                scanf("%s",ch);
                for(j=0;j<i;j++){
                    if(strcmp(bank[j].acc_no,ch)==0){
                        printf("Enter amount to be withdrawn\n");
                        scanf("%d",&bank[j].balance);
                        printf("Amount withdrawn successfully\n");
                        break;
                    }
                }
                if(j==i){
                    printf("Account not found\n");
                }
                break;
            case 4:
                printf("Enter account number\n");
                scanf("%s",ch);
                for(j=0;j<i;j++){
                    if(strcmp(bank[j].acc_no,ch)==0){
                        printf("Current balance: %d\n",bank[j].balance);
                        break;
                    }
                }
                if(j==i){
                    printf("Account not found\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}