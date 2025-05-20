//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[30];
    int acc_no;
    float bal;
};

int main() {
    char ch;
    int i, n, acc, found = 0;
    float amt;
    struct account *customers;
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    customers = (struct account*)malloc(n * sizeof(struct account));

    for(i = 0; i < n; i++) {
        printf("\nEnter name of customer %d: ", i+1);
        scanf("%s", (customers+i)->name);
        printf("Enter account number of customer %d: ", i+1);
        scanf("%d", &(customers+i)->acc_no);
        printf("Enter balance of customer %d: ", i+1);
        scanf("%f", &(customers+i)->bal);
    }

    while(1) {
        printf("\n\n");
        printf("Menu: \n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Print record\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &ch);

        switch(ch) {
            case '1': printf("\nEnter account number: ");
                      scanf("%d", &acc);
                      found = 0;
                      for(i = 0; i < n; i++) {
                          if((customers+i)->acc_no == acc) {
                              found = 1;
                              printf("Enter amount to deposit: ");
                              scanf("%f", &amt);
                              (customers+i)->bal += amt;
                              printf("\nDeposit Successful!\n");
                              break;
                          }
                      }
                      if(!found) {
                          printf("\nAccount not found!\n");
                      }
                      break;

            case '2': printf("\nEnter account number: ");
                      scanf("%d", &acc);
                      found = 0;
                      for(i = 0; i < n; i++) {
                          if((customers+i)->acc_no == acc) {
                              found = 1;
                              printf("Enter amount to withdraw: ");
                              scanf("%f", &amt);
                              if(amt > (customers+i)->bal) {
                                  printf("\nInsufficient balance!\n");
                              } else {
                                  (customers+i)->bal -= amt;
                                  printf("\nWithdrawal Successful!\n");
                              }
                              break;
                          }
                      }
                      if(!found) {
                          printf("\nAccount not found!\n");
                      }
                      break;

            case '3': printf("\n\nCustomer Record:\n");
                      printf("Name\t Account no.\t Balance\n");
                      for(i = 0; i < n; i++) {
                          printf("%s\t %d\t\t %.2f\n", (customers+i)->name, (customers+i)->acc_no, (customers+i)->bal);
                      }
                      break;

            case '4': printf("\nExiting program...\n");
                      exit(0);
                      break;

            default: printf("\nInvalid choice!\n");
                     break;
        }
    }

    free(customers);
    return 0;
}