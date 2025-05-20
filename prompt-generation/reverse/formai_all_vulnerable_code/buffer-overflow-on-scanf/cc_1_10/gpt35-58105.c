//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    int acc_no;
    char name[20];
    float balance;
};
struct account bank[100];
int curr_acc=0;

void create_account(){
    printf("Enter Account Number: ");
    scanf("%d",&bank[curr_acc].acc_no);
    printf("Enter Name: ");
    scanf("%s",bank[curr_acc].name);
    printf("Enter Balance: ");
    scanf("%f",&bank[curr_acc].balance);
    curr_acc++;
    printf("\nAccount created successfully!\n");
}

void deposit(){
    int acc_no,flag=0;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<curr_acc;i++){
        if(bank[i].acc_no==acc_no){
           printf("Enter Deposit Amount: ");
           scanf("%f",&amount);
           bank[i].balance+=amount;
           printf("Balance updated successfully!\n");
           flag=1;
           break;
        }
    }
    if(!flag) printf("\nAccount not found!\n");
}

void withdraw(){
    int acc_no,flag=0;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<curr_acc;i++){
        if(bank[i].acc_no==acc_no){
           printf("Available Balance: %.2f\n",bank[i].balance);
           printf("Enter Withdraw Amount: ");
           scanf("%f",&amount);
           if(amount<=bank[i].balance){
             bank[i].balance-=amount;
             printf("Transaction Successful!\n");
           }
           else{
             printf("Insufficient Balance!\n");
           }
           flag=1;
           break;
        }
    }
    if(!flag) printf("\nAccount not found!\n");
}

void view_balance(){
    int acc_no,flag=0;
    printf("Enter Account Number: ");
    scanf("%d",&acc_no);
    for(int i=0;i<curr_acc;i++){
        if(bank[i].acc_no==acc_no){
           printf("Available Balance: %.2f\n",bank[i].balance);
           flag=1;
           break;
        }
    }
    if(!flag) printf("\nAccount not found!\n");
}

void transfer(){
    int acc_no1,acc_no2,flag1=0,flag2=0;
    float amount;
    printf("Enter Account Number to Transfer from: ");
    scanf("%d",&acc_no1);
    printf("Enter Account Number to Transfer to: ");
    scanf("%d",&acc_no2);
    for(int i=0;i<curr_acc;i++){
        if(bank[i].acc_no==acc_no1){
           printf("Available Balance: %.2f\n",bank[i].balance);
           printf("Enter Transfer Amount: ");
           scanf("%f",&amount);
           if(amount<=bank[i].balance){
             bank[i].balance-=amount;
             flag1=1;
           }
           else{
             printf("Insufficient Balance!\n");
             return;
           }
        }
        if(bank[i].acc_no==acc_no2){
           bank[i].balance+=amount;
           flag2=1;
           break;
        }
    }
    if(!flag1) printf("\nTransfer Account not found!\n");
    if(!flag2) printf("\nRecipient Account not found!\n");
    if(flag1&&flag2) printf("Transaction Successful!\n");
}

void view_all_accounts(){
    for(int i=0;i<curr_acc;i++){
        printf("Account Number: %d\n",bank[i].acc_no);
        printf("Name: %s\n",bank[i].name);
        printf("Balance: %.2f\n",bank[i].balance);
        printf("\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n**********BANKING RECORD SYSTEM**********\n");
        printf("1. Create Account\t2. Deposit\t3. Withdraw\n4. View Balance\t5. Transfer\t6. View all Accounts\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: create_account();
                    break;
            case 2: deposit();
                    break;
            case 3: withdraw();
                    break;
            case 4: view_balance();
                    break;
            case 5: transfer();
                    break;    
            case 6: view_all_accounts();
                    break;
            case 7: exit(0);
                    break;
            default: printf("\nInvalid Choice! Try Again...\n");  
        }
    }
    return 0;
}