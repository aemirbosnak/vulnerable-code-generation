//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include<stdio.h>
#include<string.h>

#define MAX 100

struct account{
    int acc_no;
    char name[20];
    char address[30];
    float balance;
};

struct account acc[MAX];

int main(){
    int choice,i;

    do{
        printf("\n\nBanking Record System\n");
        printf("1.Create Account\n");
        printf("2.Deposit Money\n");
        printf("3.Withdraw Money\n");
        printf("4.Display Records\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Enter name: ");
                scanf("%s",acc[i].name);
                printf("Enter address: ");
                scanf("%s",acc[i].address);
                printf("Account Created Successfully!!\n");
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Enter amount to deposit: ");
                scanf("%f",&acc[i].balance);
                printf("Deposit Successful!!\n");
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Enter amount to withdraw: ");
                scanf("%f",&acc[i].balance);
                printf("Withdrawal Successful!!\n");
                break;
            case 4:
                printf("Account Number\tName\tAddress\tBalance\n");
                for(i=0;i<MAX;i++){
                    if(acc[i].acc_no!=0){
                        printf("%d\t%s\t%s\t%.2f\n",acc[i].acc_no,acc[i].name,acc[i].address,acc[i].balance);
                    }
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }

    }while(choice!=5);

    return 0;
}