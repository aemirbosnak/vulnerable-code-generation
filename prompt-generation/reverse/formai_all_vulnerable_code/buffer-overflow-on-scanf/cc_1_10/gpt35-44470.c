//FormAI DATASET v1.0 Category: Banking Record System ; Style: romantic
#include<stdio.h>
#include<string.h>

typedef struct{
   char name[50];
   int accountNumber;
   double balance;
   char address[100];
   char mobileNumber[15];
} Record;

int main() {

   Record myRecord;
   int option;

   printf("Hello my love, I am your personal banking record system.\n");
   printf("What would you like to do today?\n");
   printf("1. Add a new record.\n2. View an existing record.\n3. Exit the program.\n");
   printf("Please enter your choice: ");
   scanf("%d", &option);

   while(option != 3) {
   
      switch(option) {
         case 1 :
            printf("Please enter the account holder's name: ");
            scanf("%s", myRecord.name);
            printf("Please enter the account number: ");
            scanf("%d", &myRecord.accountNumber);
            printf("Please enter the account balance: ");
            scanf("%lf", &myRecord.balance);
            printf("Please enter the address: ");
            scanf("%s", myRecord.address);
            printf("Please enter the mobile number: ");
            scanf("%s", myRecord.mobileNumber);
            printf("Your record has been added successfully. \n");
            break;

         case 2 :
            printf("Please enter the account number: ");
            scanf("%d", &myRecord.accountNumber);
            if(myRecord.accountNumber == 0) {
               printf("Sorry my love, you entered an invalid account number. \n");
            } else {
               printf("----------Banking Record-----------\n");
               printf("Name: %s\n", myRecord.name);
               printf("Account number: %d\n", myRecord.accountNumber);
               printf("Account balance: %lf\n", myRecord.balance);
               printf("Address: %s\n", myRecord.address);
               printf("Mobile number: %s\n", myRecord.mobileNumber);
               printf("------------------------------------\n");
            }
            break;

         default :
            printf("Sorry my love, I cannot understand your choice. Please try again. \n");
      } 

      printf("What would you like to do next?\n");
      printf("1. Add a new record.\n2. View an existing record.\n3. Exit the program.\n");
      printf("Please enter your choice: ");
      scanf("%d", &option);

   }

   printf("Thank you for using me my love. Have a great day!\n");

   return 0;
}