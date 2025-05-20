//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int count=0, choice, accno, accid=2000, amount, balance=0;
  char name[30];
  printf("**************************WELCOME TO THE BANK**************************\n");
  printf("\n");

  do{
    printf("1.Open New Account\n2.Deposit Amount\n3.Withdraw Amount\n4.Check Balance\n5.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch(choice){
      case 1:
        printf("\nEnter Name : ");
        scanf("%s",name);
        printf("\nEnter Initial Amount to Deposit : $");
        scanf("%d",&amount);
        balance += amount;
        accno = accid + count;
        printf("\nAccount Created Successfully. Your Account Number is : '%d'\n",accno);
        printf("Please keep this number safe for future reference.\n");
        printf("Your Current Balance is : $%d \n\n",balance);
        count++;
        break;

      case 2:
        printf("\nEnter Account Number : ");
        scanf("%d",&accno);
        printf("\nEnter Amount to Deposit : $");
        scanf("%d",&amount);
        balance += amount;
        printf("\nAmount Deposited Successfully.\nYour Current Balance is : $%d \n\n",balance);
        break;

      case 3:
        printf("\nEnter Account Number : ");
        scanf("%d",&accno);
        printf("\nEnter Amount to Withdraw : $");
        scanf("%d",&amount);
        if(amount>balance){
          printf("\nInsufficient Balance!\n\n");
          break;
        }
        balance -= amount;
        printf("\nAmount Withdrawn Successfully.\nYour Updated Balance is : $%d \n\n",balance);
        break;

      case 4:
        printf("\nEnter Account Number : ");
        scanf("%d",&accno);
        printf("\nYour Current Balance : $%d \n\n",balance);
        break;

      case 5:
        printf("\n\n************************* Thankyou for Visiting *************************\n\n");
        exit(0);

      default:
        printf("\n\nInvalid Choice. Please Try Again.\n\n");
    }

  }while(choice!=5);

  return 0;
}