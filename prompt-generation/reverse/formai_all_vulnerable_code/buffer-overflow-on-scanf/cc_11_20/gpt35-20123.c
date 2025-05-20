//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
  char name[50];
  int account_number;
  float balance;
};

int main() {
  int option, num_customers = 0, i, account_num, found = 0;
  float deposit_amt, withdraw_amt;
  char cust_name[50];

  struct customer customers[100];

  while(1) {
    printf("\nWelcome to the Bank Record System.");
    printf("\n1. Add Customer");
    printf("\n2. Search Customer by Account Number");
    printf("\n3. Deposit Money");
    printf("\n4. Withdraw Money");
    printf("\n5. Display All Records");
    printf("\n6. Exit");

    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("\nAdding a new customer.");
        printf("\nEnter customer name: ");
        scanf("%s", customers[num_customers].name);
        printf("\nEnter account number: ");
        scanf("%d", &customers[num_customers].account_number);
        printf("\nEnter initial balance: ");
        scanf("%f", &customers[num_customers].balance);
        num_customers++;
        break;

      case 2:
        printf("\nSearching for a customer by account number.");
        printf("\nEnter account number: ");
        scanf("%d", &account_num);

        for(i = 0; i < num_customers; i++) {
          if(customers[i].account_number == account_num) {
            printf("\nCustomer Found.\nName: %s\nAccount Number: %d\nBalance: %.2f", customers[i].name, customers[i].account_number, customers[i].balance);
            found = 1;
            break;
          }
        }

        if(found == 0) {
          printf("\nCustomer not found with account number %d", account_num);
        }

        found = 0;
        break;

      case 3:
        printf("\nDepositing money into a customer's account.");
        printf("\nEnter account number: ");
        scanf("%d", &account_num);

        for(i = 0; i < num_customers; i++) {
          if(customers[i].account_number == account_num) {
            printf("\nCustomer Found.\nName: %s\nAccount Number: %d\nBalance: %.2f", customers[i].name, customers[i].account_number, customers[i].balance);
            printf("\nEnter amount to deposit: ");
            scanf("%f", &deposit_amt);
            customers[i].balance += deposit_amt;
            printf("\nDeposit Successful.\nUpdated Balance: %.2f", customers[i].balance);
            found = 1;
            break;
          }
        }

        if(found == 0) {
          printf("\nCustomer not found with account number %d", account_num);
        }

        found = 0;
        break;

      case 4:
        printf("\nWithdrawing money from a customer's account.");
        printf("\nEnter account number: ");
        scanf("%d", &account_num);

        for(i = 0; i < num_customers; i++) {
          if(customers[i].account_number == account_num) {
            printf("\nCustomer Found.\nName: %s\nAccount Number: %d\nBalance: %.2f", customers[i].name, customers[i].account_number, customers[i].balance);
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &withdraw_amt);

            if(withdraw_amt > customers[i].balance) {
              printf("\nWithdrawal amount exceeds balance. Withdrawal cancelled.");
            } else {
              customers[i].balance -= withdraw_amt;
              printf("\nWithdrawal Successful.\nUpdated Balance: %.2f", customers[i].balance);
            }
            found = 1;
            break;
          }
        }

        if(found == 0) {
          printf("\nCustomer not found with account number %d", account_num);
        }

        found = 0;
        break;

      case 5:
        printf("\nDisplaying all customer records.");
        for(i = 0; i < num_customers; i++) {
          printf("\nCustomer Name: %s\nAccount Number: %d\nBalance: %.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
        }
        break;

      case 6:
        printf("\nExiting program. Goodbye!");
        exit(0);

      default:
        printf("\nInvalid input. Please enter a number from 1-6.");
        break;
    }
  }

  return 0;
}