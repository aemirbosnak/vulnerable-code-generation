//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Account {
    int acnum;
    char name[30];
    float balance;
};
struct Account acc[50];
int n = 0;
void Add_Account(){
    printf("\n---- ADD ACCOUNT ----\n");
    printf("\nEnter Account Number:\t");
    scanf("%d", &acc[n].acnum);
    printf("\nEnter Name:\t");
    scanf("%s", acc[n].name);
    printf("\nEnter Balance:\t");
    scanf("%f", &acc[n].balance);
    n++;
    printf("\nAccount Successfully Added!!\n");
}
void Remove_Account(){
    printf("\n---- REMOVE ACCOUNT ----\n");
    int ac;
    printf("\nEnter Account Number:\t");
    scanf("%d", &ac);
    int i;
    for(i = 0; i < n; i++){
        if(acc[i].acnum == ac){
            while(i < n){
                acc[i] = acc[i+1];
                i++;
            }
            printf("\nAccount Successfully Removed!!\n");
            n--;
            return;
        }
    }
    printf("\nAccount not Found!!\n");
}
void Display_Account_Details(){
    printf("\n---- ACCOUNT DETAILS ----\n");
    int ac;
    printf("\nEnter Account Number:\t");
    scanf("%d", &ac);
    int i;
    for(i = 0; i < n; i++){
        if(acc[i].acnum == ac){
            printf("\nAccount Number:\t%d", acc[i].acnum);
            printf("\nName:\t%s", acc[i].name);
            printf("\nBalance:\t%.2f", acc[i].balance);
            return;
        }
    }
    printf("\nAccount not Found!!\n");
}
void Display_All_Accounts(){
    printf("\n---- ALL ACCOUNT DETAILS ----\n");
    int i;
    for(i = 0; i < n; i++){
        printf("\nAccount Number:\t%d", acc[i].acnum);
        printf("\nName:\t%s", acc[i].name);
        printf("\nBalance:\t%.2f\n", acc[i].balance);
    }
}
void Deposit_Amount(){
    printf("\n---- DEPOSIT ----\n");
    int ac;
    printf("\nEnter Account Number:\t");
    scanf("%d", &ac);
    int i;
    for(i = 0; i < n; i++){
        if(acc[i].acnum == ac){
            float amt;
            printf("\nEnter Amount to Deposit:\t");
            scanf("%f", &amt);
            acc[i].balance += amt;
            printf("\nAmount Successfully Deposited!!\n");
            return;
        }
    }
    printf("\nAccount not Found!!\n");
}
void Withdraw_Amount(){
    printf("\n---- WITHDRAW ----\n");
    int ac;
    printf("\nEnter Account Number:\t");
    scanf("%d", &ac);
    int i;
    for(i = 0; i < n; i++){
        if(acc[i].acnum == ac){
            float amt;
            printf("\nEnter Amount to Withdraw:\t");
            scanf("%f", &amt);
            if(acc[i].balance < amt){
                printf("\nInsufficient Balance!!!\n");
                return;
            }
            else{
                acc[i].balance -= amt;
                printf("\nAmount Successfully Withdrawn!!\n");
                return;
            }
        }
    }
    printf("\nAccount not Found!!\n");
}
int main(){
    int c;
    do{
        printf("\n---- BANKING RECORD SYSTEM ----\n");
        printf("\n1. Add Account");
        printf("\n2. Remove Account");
        printf("\n3. Display Account Details");
        printf("\n4. Display All Accounts");
        printf("\n5. Deposit Amount");
        printf("\n6. Withdraw Amount");
        printf("\n7. Exit");
        printf("\n\nEnter Choice:\t");
        scanf("%d", &c);
        switch(c){
            case 1:
                Add_Account();
                break;
            case 2:
                Remove_Account();
                break;
            case 3:
                Display_Account_Details();
                break;
            case 4:
                Display_All_Accounts();
                break;
            case 5:
                Deposit_Amount();
                break;
            case 6:
                Withdraw_Amount();
                break;
            case 7:
                printf("\nThank You for Using Banking Record System!!\n");
                break;
            default:
                printf("\nInvalid Choice!!\n");
        }
    }while(c != 7);
    return 0;
}