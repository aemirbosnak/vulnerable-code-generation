//FormAI DATASET v1.0 Category: Banking Record System ; Style: modular
#include<stdio.h>
#include<stdlib.h>

struct account{
    int acc_no;
    char name[50];
    double balance;
};

void create_account(struct account *a, int n){
    for(int i=0;i<n;i++){
        printf("Enter Account Number: ");
        scanf("%d", &(a+i)->acc_no);
        printf("Enter Name: ");
        scanf("%s", (a+i)->name);
        printf("Enter Balance: ");
        scanf("%lf", &((a+i)->balance));
    }
    printf("\n");
}

void display_accounts(struct account *a, int n){
    printf("Account Number\t\tName\t\tBalance\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t\t%s\t\t%.2lf\n", (a+i)->acc_no, (a+i)->name, (a+i)->balance);
    }
    printf("\n");
}

void deposit(struct account *a, int n){
    int acc;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc);
    for(int i=0;i<n;i++){
        if((a+i)->acc_no==acc){
            printf("Enter Amount to be Deposited: ");
            scanf("%lf", &amount);
            (a+i)->balance += amount;
            printf("Amount Deposited Successfully!\nUpdated Balance: %.2lf\n\n", (a+i)->balance);
            return;
        }
    }
    printf("Account not Found. Please Try Again...\n\n");
}

void withdraw(struct account *a, int n){
    int acc;
    double amount;
    printf("Enter Account Number: ");
    scanf("%d", &acc);
    for(int i=0;i<n;i++){
        if((a+i)->acc_no==acc){
            printf("Enter Amount to be Withdrawn: ");
            scanf("%lf", &amount);
            if((a+i)->balance < amount){
                printf("Insufficient Balance. Please Try Again...\n\n");
                return;
            }
            (a+i)->balance -= amount;
            printf("Amount Withdrawn Successfully!\nUpdated Balance: %.2lf\n\n", (a+i)->balance);
            return;
        }
    }
    printf("Account not Found. Please Try Again...\n\n");
}

int main(){
    int n;
    printf("Enter Number of Accounts: ");
    scanf("%d", &n);
    struct account *acc = (struct account *)malloc(n*sizeof(struct account));
    int ch;
    do{
        printf("\n----Menu----\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch(ch){
            case 1: create_account(acc, n);
                    break;
            case 2: display_accounts(acc, n);
                    break;
            case 3: deposit(acc, n);
                    break;
            case 4: withdraw(acc, n);
                    break;
            case 5: printf("Thank You for Using the Program!\n");
                    break;
            default:printf("Invalid Choice. Please Try Again...\n");
                    break;
        }
    }while(ch!=5);
    free(acc);
    return 0;
}