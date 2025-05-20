//FormAI DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

   int choice, flag = 0;
   char username[20], password[20];
   float balance = 0;

   while(1){
      printf("\nWelcome to YOUR BANK!");

      // Authentication Loop
      while(1){
        printf("\n\nPlease enter your username to proceed: ");
        scanf("%s", &username);
        printf("\nPlease enter your password to proceed: ");
        scanf("%s", &password);

        if(strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0){
           printf("\nLogin successful!\n");
           flag = 1;
           break;
        }
        else{
           printf("\nInvalid credentials. Please try again.\n");
        }
      }

      if(flag == 1){
         printf("\nWhat would you like to do today?\n");
         printf("\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n");
         printf("\nEnter your choice: ");
         scanf("%d", &choice);

         switch(choice){
            case 1:
               printf("\nYour current balance is: %.2f", balance);
               break;

            case 2:
               printf("\nEnter the amount you would like to deposit: ");
               float deposit;
               scanf("%f", &deposit);
               balance += deposit;
               printf("\nTransaction successful! Your new balance is: %.2f", balance);
               break;

            case 3:
               printf("\nEnter the amount you would like to withdraw: ");
               float withdraw;
               scanf("%f", &withdraw);
               if(withdraw > balance){
                  printf("\nInsufficient funds. Transaction failed.\n");
               }
               else{
                  balance -= withdraw;
                  printf("\nTransaction successful! Your new balance is: %.2f", balance);
               }
               break;

            case 4:
               printf("\nThank you for using YOUR BANK. Goodbye!");
               exit(0);
               
            default:
               printf("\nInvalid choice. Please try again.");
         }
      }
   }

   return 0;
}