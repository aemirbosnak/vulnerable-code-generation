//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void add_password();
void view_passwords();
void delete_password();

struct password {
   char website[50];
   char username[50];
   char password[50];
};

int num_of_passwords = 0;
struct password passwords[100];

int main() {
   menu();
   return 0;
}

void menu() {
   int choice;
   printf("Password Manager\n");
   printf("----------------\n");
   printf("1. Add Password\n");
   printf("2. View Passwords\n");
   printf("3. Delete Password\n");
   printf("4. Exit\n");
   printf("Enter choice: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         add_password();
         break;
      case 2:
         view_passwords();
         break;
      case 3:
         delete_password();
         break;
      case 4:
         exit(0);
      default:
         printf("Invalid Choice!\n");
         menu();
   }
}

void add_password() {
   struct password p;
   printf("Enter website: ");
   scanf("%s", p.website);
   printf("Enter username: ");
   scanf("%s", p.username);
   printf("Enter password: ");
   scanf("%s", p.password);
   passwords[num_of_passwords++] = p;
   printf("Password added successfully!\n");
   menu();
}

void view_passwords() {
   if (num_of_passwords == 0) {
      printf("No Passwords Found!\n");
      menu();
   } else {
      printf("|%-20s|%-20s|%-20s|\n", "Website", "Username", "Password");
      printf("|--------------------|--------------------|--------------------|\n");
      int i;
      for (i = 0; i < num_of_passwords; i++) {
         struct password p = passwords[i];
         printf("|%-20s|%-20s|%-20s|\n", p.website, p.username, p.password);
      }
      menu();
   }
}

void delete_password() {
   if (num_of_passwords == 0) {
      printf("No Passwords Found!\n");
      menu();
   } else {
      int i;
      char website[50];
      printf("Enter website of password to be deleted: ");
      scanf("%s", website);
      for (i = 0; i < num_of_passwords; i++) {
         struct password p = passwords[i];
         if (strcmp(p.website, website) == 0) {
            int j;
            for (j = i; j < num_of_passwords - 1; j++)
               passwords[j] = passwords[j+1];
            num_of_passwords--;
            printf("Password deleted successfully!\n");
            menu();
         }
      }
      printf("Website not found!\n");
      menu();
   }
}