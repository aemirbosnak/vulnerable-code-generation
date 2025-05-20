//FormAI DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Banking Record System

struct customer{
  char name[50];
  int account_no;
  float balance;
};

void createAccount(struct customer *c){
  printf("Enter customer name: ");
  scanf("%s", c->name);
  printf("Enter account number: ");
  scanf("%d", &c->account_no);
  printf("Enter initial deposit: ");
  scanf("%f", &c->balance);
  printf("\nAccount created successfully!\n\n");
}

void showAccount(struct customer c){
  printf("Name: %s\n", c.name);
  printf("Account number: %d\n", c.account_no);
  printf("Balance: $%.2f\n\n", c.balance);
}

void deposit(struct customer *c){
  float amount;
  printf("Enter amount to deposit: ");
  scanf("%f", &amount);
  c->balance += amount;
  printf("Deposit successful!\n\n");
}

void withdraw(struct customer *c){
  float amount;
  printf("Enter amount to withdraw: ");
  scanf("%f", &amount);
  if(amount > c->balance){
    printf("Insufficient funds!\n\n");
  }else{
    c->balance -= amount;
    printf("Withdrawal successful!\n\n");
  }
}

int main(){
  int option, count = 0;
  struct customer *customers = malloc(10*sizeof(struct customer)); // create space for 10 customers

  while(1){
    printf("1. Create Account\n");
    printf("2. Show Account Details\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option){
      case 1:
        createAccount(&customers[count]);
        count++;
        break;
      case 2:
        if(count == 0){
          printf("No accounts exist!\n\n");
        }else{
          int accNo, i;
          printf("Enter account number: ");
          scanf("%d", &accNo);
          for(i=0;i<count;i++){
            if(customers[i].account_no == accNo){
              showAccount(customers[i]);
              break;
            }
          }
          if(i == count){
            printf("Account not found!\n\n");
          }
        }
        break;
      case 3:
        if(count == 0){
          printf("No accounts exist!\n\n");
        }else{
          int accNo, i;
          printf("Enter account number: ");
          scanf("%d", &accNo);
          for(i=0;i<count;i++){
            if(customers[i].account_no == accNo){
              deposit(&customers[i]);
              break;
            }
          }
          if(i == count){
            printf("Account not found!\n\n");
          }
        }
        break;
      case 4:
        if(count == 0){
          printf("No accounts exist!\n\n");
        }else{
          int accNo, i;
          printf("Enter account number: ");
          scanf("%d", &accNo);
          for(i=0;i<count;i++){
            if(customers[i].account_no == accNo){
              withdraw(&customers[i]);
              break;
            }
          }
          if(i == count){
            printf("Account not found!\n\n");
          }
        }
        break;
      case 5:
        printf("Thank you for using our Banking Record System!\n");
        free(customers); // free the allocated space
        exit(0); // exit the program
      default:
        printf("Invalid option!\n\n");
    }
  }
  return 0;
}