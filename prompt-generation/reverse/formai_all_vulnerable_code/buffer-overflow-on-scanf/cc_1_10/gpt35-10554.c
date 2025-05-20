//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int account_number;
  float balance;
} account;

void createAccount(account *ptr) {
  printf("\nEnter Name: ");
  scanf("%s", ptr->name);
  printf("Enter Account Number: ");
  scanf("%d", &ptr->account_number);
  printf("Enter Balance: ");
  scanf("%f", &ptr->balance);
}

void displayAccount(account obj) {
  printf("\nName: %s", obj.name);
  printf("\nAccount Number: %d", obj.account_number);
  printf("\nBalance: %.2f", obj.balance);
}

void modifyAccount(account *ptr) {
  printf("\nEnter New Name: ");
  scanf("%s", ptr->name);
  printf("Enter New Account Number: ");
  scanf("%d", &ptr->account_number);
  printf("Enter New Balance: ");
  scanf("%f", &ptr->balance);
}

void deleteAccount(account *ptr) {
  ptr->account_number = -1;
  ptr->balance = 0.0;
}

int main() {
  int i, choice, numAccounts = 3;

  account accounts[3] = {
    {"John Smith", 123456, 5000.00},
    {"Lisa Patel", 789012, 8000.00},
    {"Michael Chen", 345678, 10000.00}
  };

  while(1) {
    printf("\n1. Create New Account\n2. Display Account\n3. Modify Account\n4. Delete Account\n5. Exit");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nCreating New Account...");
        if(numAccounts < 50) {
          createAccount(&accounts[numAccounts]);
          numAccounts++;
        }
        else
          printf("\nNo More Accounts Can Be Created.");
        break;
      case 2:
        printf("\n---DISPLAY---\n");
        for(i=0; i<numAccounts; i++)
          displayAccount(accounts[i]);
        printf("\n-------------");
        break;
      case 3:
        printf("\nModifying an Existing Account...");
        printf("\nEnter Account Number: ");
        int accountNumber;
        scanf("%d", &accountNumber);
        for(i=0; i<numAccounts; i++) {
          if(accounts[i].account_number == accountNumber)
            modifyAccount(&accounts[i]);
        }
        break;
      case 4:
        printf("\nDeleting an Existing Account...");
        printf("\nEnter Account Number: ");
        int accNum;
        scanf("%d", &accNum);
        for(i=0; i<numAccounts; i++) {
          if(accounts[i].account_number == accNum)
            deleteAccount(&accounts[i]);
        }
        break;
      case 5:
        exit(0);
    }
  }

  return 0;
}