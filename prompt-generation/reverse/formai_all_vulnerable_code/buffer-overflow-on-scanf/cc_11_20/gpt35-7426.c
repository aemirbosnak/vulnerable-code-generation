//FormAI DATASET v1.0 Category: Banking Record System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
  char name[100];
  char address[200];
  int account_no;
  float balance;
};

int main(){
  int n,account_number,choice,i;
  float amount;
  char account_name[100];
  struct account bank[10];
  
  printf("Enter the number of account holders: ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    printf("\nEnter Account Holder #%d's Name: ",i+1);
    scanf("%s",bank[i].name);
    printf("Enter Account Holder #%d's Address: ",i+1);
    scanf("%s",bank[i].address);
    printf("Enter Account Holder #%d's Account Number: ",i+1);
    scanf("%d",&bank[i].account_no);
    printf("Enter Account Holder #%d's Account Balance: ",i+1);
    scanf("%f",&bank[i].balance);
  }
  
  while(1){
    printf("\nMenu:\n");
    printf("1. Check Account Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice){
      case 1:
        printf("\nEnter the Account Number: ");
        scanf("%d",&account_number);
        for(i=0;i<n;i++){
          if(bank[i].account_no==account_number){
            printf("\nAccount Holder Name: %s\nAccount Balance: %.2f\n",bank[i].name,bank[i].balance);
            break;
          }
        }
        if(i==n){
          printf("\nInvalid Account Number!\n");
        }
        break;
        
      case 2:
        printf("\nEnter the Account Number: ");
        scanf("%d",&account_number);
        printf("Enter the Deposit Amount: ");
        scanf("%f",&amount);
        for(i=0;i<n;i++){
          if(bank[i].account_no==account_number){
            bank[i].balance+=amount;
            printf("\nAmount Deposited Successfully!\nNew Account Balance: %.2f\n",bank[i].balance);
            break;
          }
        }
        if(i==n){
          printf("\nInvalid Account Number!\n");
        }
        break;
        
      case 3:
        printf("\nEnter the Account Number: ");
        scanf("%d",&account_number);
        printf("Enter the Withdrawal Amount: ");
        scanf("%f",&amount);
        for(i=0;i<n;i++){
          if(bank[i].account_no==account_number){
            if(amount>bank[i].balance){
              printf("\nInsufficient Account Balance!\n");
              break;
            }
            bank[i].balance-=amount;
            printf("\nAmount Withdrawn Successfully!\nNew Account Balance: %.2f\n",bank[i].balance);
            break;
          }
        }
        if(i==n){
          printf("\nInvalid Account Number!\n");
        }
        break;
        
      case 4:
        printf("\nThank You for Banking with Us!\n");
        exit(0);
        
      default:
        printf("\nInvalid Choice!\n");
        break;
    }
  }
  
  return 0;
}