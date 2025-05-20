//FormAI DATASET v1.0 Category: System administration ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
   int choice, count;
   char name[30], password[30];

   printf("Welcome to the System Administration Example Program!\n");
   printf("Please select an option:\n");
   printf("1. Create Account.\n");
   printf("2. Sign in.\n");

   scanf("%d", &choice);

   if(choice == 1) {
      printf("Please enter your name:\n");
      scanf("%s", name);
      printf("Please enter a password:\n");
      scanf("%s", password);
      printf("Account created successfully!\n");
   }
   else if(choice == 2) {
      printf("Please enter your name:\n");
      scanf("%s", name);
      printf("Please enter your password:\n");
      scanf("%s", password);

      if(strcmp(name, "admin") == 0 && strcmp(password, "password") == 0) {
         printf("Welcome %s!\n", name);
         printf("What would you like to do?\n");
         printf("1. View system status.\n");
         printf("2. Modify system settings.\n");
         printf("3. Shutdown system.\n");
         
         scanf("%d", &count);
         
         if(count == 1) {
            printf("System status is good.\n");
         } 
         else if(count == 2) {
            printf("System settings updated successfully!\n");
         }
         else if(count == 3) {
            printf("Shutting down system...\n");
         } 
         else {
            printf("Invalid input.\n");
         }
      }
      else {
         printf("Invalid name or password.\n");
      }
   }
   else {
      printf("Invalid input.\n");
   }

   return 0;
}