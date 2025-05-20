//FormAI DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
  int acc_no;
  char name[30];
  char address[100];
  float balance;
}cust[100];

int customer_count = 0;

void create_account(){
    printf("\nEnter Account Number: ");
    scanf("%d", &cust[customer_count].acc_no);

    printf("\nEnter Name: ");
    scanf("%s", cust[customer_count].name);

    printf("\nEnter Address: ");
    scanf("%s", cust[customer_count].address);

    printf("\nEnter Balance: ");
    scanf("%f", &cust[customer_count].balance);

    customer_count++;

    printf("Account Created Successfully!");
}

void deposit_amount(){
    int acc_no;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);
    int i;
    for(i = 0; i < customer_count; i++){
        if(cust[i].acc_no == acc_no){
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            cust[i].balance += amount;
            printf("Deposit successful! New balance: %f", cust[i].balance);
            return;
        }
    }
    printf("Account not found!");
}

void withdraw_amount(){
    int acc_no;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);
    int i;
    for(i = 0; i < customer_count; i++){
        if(cust[i].acc_no == acc_no){
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if(cust[i].balance - amount >= 0){
                cust[i].balance -= amount;
                printf("Withdrawal successful! New balance: %f", cust[i].balance);
            }
            else{
                printf("Insufficient balance!");
            }
            return;
        }
    }
    printf("Account not found!");
}

void display_account(){
    int acc_no;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_no);
    int i;
    for(i = 0; i < customer_count; i++){
        if(cust[i].acc_no == acc_no){
            printf("Account Number: %d\n", cust[i].acc_no);
            printf("Name: %s\n", cust[i].name);
            printf("Address: %s\n", cust[i].address);
            printf("Balance: %f\n", cust[i].balance);
            return;
        }
    }
    printf("Account not found!");
}

int main(){
    int choice;
    do{
        printf("\n\n\t\t\tMenu\n");
        printf("\n1. Create Account");
        printf("\n2. Deposit Amount");
        printf("\n3. Withdraw Amount");
        printf("\n4. Display Account");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_account();
                break;
            case 2:
                deposit_amount();
                break;
            case 3:
                withdraw_amount();
                break;
            case 4:
                display_account();
                break;
            case 5:
                printf("Thank you for using our banking system!");
                break;
            default:
                printf("\nInvalid choice!");
        }

    }while(choice != 5);

    return 0;
}