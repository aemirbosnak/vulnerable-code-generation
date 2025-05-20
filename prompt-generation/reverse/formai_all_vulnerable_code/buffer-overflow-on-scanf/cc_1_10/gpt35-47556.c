//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 20
#define PASSWORD_LENGTH 20

/* Account structure to hold account information */
struct account {
   char website[50];
   char username[50];
   char password[20];
};

/* Function prototypes */
void add_account(struct account accounts[], int *count);
void display_accounts(struct account accounts[], int count);
void encrypt_password(char *password);
void decrypt_password(char *password);

/* Main function */
int main(void) {
   struct account accounts[MAX_ACCOUNTS];
   int count = 0;
   int choice;

   do {
      printf("Password Manager\n");
      printf("----------------\n");
      printf("1. Add account\n");
      printf("2. Display accounts\n");
      printf("3. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            add_account(accounts, &count);
            break;
         case 2:
            display_accounts(accounts, count);
            break;
         case 3:
            printf("Exiting program...\n");
            break;
         default:
            printf("Invalid choice. Please try again.\n");
      }

      printf("\n");

   } while (choice != 3);

   return 0;
}

/* Function to add an account */
void add_account(struct account accounts[], int *count) {
   struct account new_account;

   printf("\nAdd Account\n");
   printf("-----------\n");

   printf("Website: ");
   scanf("%s", new_account.website);
   printf("Username: ");
   scanf("%s", new_account.username);
   printf("Password: ");
   scanf("%s", new_account.password);

   encrypt_password(new_account.password);

   accounts[*count] = new_account;
   *count += 1;

   printf("Account added successfully!\n");
}

/* Function to display all accounts */
void display_accounts(struct account accounts[], int count) {
   if (count == 0) {
      printf("No accounts found.\n");
      return;
   }

   printf("\nAll Accounts\n");
   printf("------------\n");

   for (int i = 0; i < count; i++) {
      printf("Website: %s\n", accounts[i].website);
      printf("Username: %s\n", accounts[i].username);
      decrypt_password(accounts[i].password);  // Decrypt the password before displaying
      printf("Password: %s\n\n", accounts[i].password);
   }
}

/* Function to encrypt password */
void encrypt_password(char *password) {
   int length = strlen(password);

   for (int i = 0; i < length; i++) {
      password[i] = (password[i] + 3) % 127;  // Encrypt by adding 3 to ASCII code of each character
   }
}

/* Function to decrypt password */
void decrypt_password(char *password) {
   int length = strlen(password);

   for (int i = 0; i < length; i++) {
      password[i] = (password[i] - 3 + 127) % 127;  // Decrypt by subtracting 3 from ASCII code of each character
   }
}