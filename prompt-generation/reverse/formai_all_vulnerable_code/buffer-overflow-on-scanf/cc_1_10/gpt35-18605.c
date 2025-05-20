//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>

struct account {
   char name[50];
   int acc_number;
   float balance;
} acc[1000];

int count = 0;

void create_account() {
   printf("Enter your name: ");
   scanf("%s", &acc[count].name);
   printf("Enter account number: ");
   scanf("%d", &acc[count].acc_number);
   printf("Enter initial balance: ");
   scanf("%f", &acc[count].balance);
   printf("Account created successfully.\n");
   count++;
}

void deposit() {
   int acc_number, i;
   float amount;

   printf("Enter account number: ");
   scanf("%d", &acc_number);

   for (i = 0; i < count; i++) {
      if (acc[i].acc_number == acc_number) {
         printf("Enter amount you want to deposit: ");
         scanf("%f", &amount);
         acc[i].balance += amount;
         printf("Deposit successful.\n");
         return;
      }
   }

   printf("Invalid account number.\n");
}

void withdraw() {
   int acc_number, i;
   float amount;

   printf("Enter account number: ");
   scanf("%d", &acc_number);

   for (i = 0; i < count; i++) {
      if (acc[i].acc_number == acc_number) {
         printf("Enter amount you want to withdraw: ");
         scanf("%f", &amount);

         if (amount > acc[i].balance) {
            printf("Insufficient balance.\n");
            return;
         }

         acc[i].balance -= amount;
         printf("Withdrawal successful.\n");
         return;
      }
   }

   printf("Invalid account number.\n");
}

void check_balance() {
   int acc_number, i;

   printf("Enter account number: ");
   scanf("%d", &acc_number);

   for (i = 0; i < count; i++) {
      if (acc[i].acc_number == acc_number) {
         printf("Your account balance is %.2f.\n", acc[i].balance);
         return;
      }
   }

   printf("Invalid account number.\n");
}

int main() {
   int choice;

   while (1) {
      printf("1. Create account\n");
      printf("2. Deposit money\n");
      printf("3. Withdraw money\n");
      printf("4. Check balance\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            create_account();
            break;
         case 2:
            deposit();
            break;
         case 3:
            withdraw();
            break;
         case 4:
            check_balance();
            break;
         case 5:
            printf("Exiting program.\n");
            return 0;
         default:
            printf("Invalid choice.\n");
      }
   }
}