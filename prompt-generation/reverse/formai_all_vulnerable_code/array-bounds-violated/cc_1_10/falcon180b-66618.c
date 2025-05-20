//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct account {
    int acc_no;
    char name[20];
    char address[30];
    float balance;
};

struct account acc[MAX];

int main(){
    int choice,i;
    char ch;
    while(1){
        printf("\n\nWELCOME TO BANKING SYSTEM\n");
        printf("----------------------------------------\n");
        printf("1.Create Account\n");
        printf("2.Deposit Money\n");
        printf("3.Withdraw Money\n");
        printf("4.Check Balance\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Enter name: ");
                scanf("%s",acc[i].name);
                printf("Enter address: ");
                scanf("%s",acc[i].address);
                printf("Account created successfully!\n");
                break;
            case 2:
                printf("\nEnter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Enter amount to be deposited: ");
                scanf("%f",&acc[i].balance);
                printf("Amount deposited successfully!\n");
                break;
            case 3:
                printf("\nEnter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Enter amount to be withdrawn: ");
                scanf("%f",&acc[i].balance);
                printf("Amount withdrawn successfully!\n");
                break;
            case 4:
                printf("\nEnter account number: ");
                scanf("%d",&acc[i].acc_no);
                printf("Current balance: %.2f\n",acc[i].balance);
                break;
            case 5:
                printf("\nThank you for using our services.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}