//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: irregular
// Bank Record System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Account structure
typedef struct Account {
    int account_number;
    char name[50];
    double balance;
} Account;

// Function to create a new account
Account *create_account(int account_number, char *name, double balance) {
    Account *new_account = malloc(sizeof(Account));
    new_account->account_number = account_number;
    strcpy(new_account->name, name);
    new_account->balance = balance;
    return new_account;
}

// Function to deposit money into an account
void deposit_money(Account *account, double amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw_money(Account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to print the details of an account
void print_account_details(Account *account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %lf\n", account->balance);
}

// Main function
int main() {

    // Create a new account
  /*  Account *account1 = create_account(12345, "John Doe", 1000.0);

    // Deposit money into the account
    deposit_money(account1, 500.0);

    // Withdraw money from the account
    withdraw_money(account1, 300.0);

    // Print the details of the account
    print_account_details(account1); */
  int i=0,a,b,c,account_n,ch,flag=0;
  struct bank
  {
   char name[20];
   char ac_type[20];
   int ac_no;
   long int mob_no;
   float balance;
   };
   struct bank b1[20];
   printf("1)Create the account\n2)deposit money\n3)withdraw money\n4)display the account details\n5)exit\n");
   while(ch!=5)
   {
    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:
     printf("enter your name\n");
     scanf("%s",b1[i].name);
     printf("enter ur account type\n");
     scanf("%s",b1[i].ac_type);
     printf("enter ur account number\n");
     b1[i].ac_no=rand();
     printf("enter ur mobile no\n");
     scanf("%ld",&b1[i].mob_no);
     printf("enter how much balance u want to maintain\n");
     scanf("%f",&b1[i].balance);
     i++;
     break;
    case 2:
     printf("enter ur acc no\n");
     scanf("%d",&account_n);
     for(a=0;a<i;a++)
     {
      if(b1[a].ac_no==account_n)
      {
       flag=1;
       printf("enter how much amount u want to deposit\n");
       scanf("%d",&c);
       b1[a].balance=b1[a].balance+c;
       printf("ur new balance is\n%f\n",b1[a].balance);
      }
     }
     if(flag==0)
     {
      printf("account number not found\n");
     }
     break;
    case 3:
     printf("enter ur acc no\n");
     scanf("%d",&account_n);
     for(a=0;a<i;a++)
     {
      if(b1[a].ac_no==account_n)
      {
       flag=1;
       printf("enter how much amount u want to withdraw\n");
       scanf("%d",&c);
       if(c<=b1[a].balance)
       {
        b1[a].balance=b1[a].balance-c;
        printf("ur new balance is\n%f\n",b1[a].balance);
       }
       else
       {
        printf("insufficient balance\n");
       }
      }
     }
     if(flag==0)
     {
      printf("account number not found\n");
     }
     break;
    case 4:
     printf("enter ur acc no\n");
     scanf("%d",&account_n);
     for(a=0;a<i;a++)
     {
      if(b1[a].ac_no==account_n)
      {
       flag=1;
       printf("name:%s\n",b1[a].name);
       printf("ac_type:%s\n",b1[a].ac_type);
       printf("ac_no:%d\n",b1[a].ac_no);
       printf("mob_no:%ld\n",b1[a].mob_no);
       printf("balance:%f\n",b1[a].balance);
      }
     }
     if(flag==0)
     {
      printf("account number not found\n");
     }
     break;
    case 5:
     exit(0);
     break;
     default:
     printf("invalid choice\n");
    }
   }
    return 0;
}