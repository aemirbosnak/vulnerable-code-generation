//FormAI DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "Admin123"

int main()
{
   char password[20];
   char command[100];

   printf("Enter password to access system administration: ");
   scanf("%s", password);

   if (strcmp(password, PASSWORD) != 0) {
      printf("Access denied.\n");
      exit(0);
   }

   printf("-----------------------------------------------\n");
   printf("Welcome to the System Administration Program\n");
   printf("-----------------------------------------------\n");

   while(1) {
      printf("Enter a command or 'exit' to quit: ");
      scanf("%s", command);

      if (strcmp(command, "exit") == 0) {
         break;
      }

      /* Add more commands here */

      if (strcmp(command, "reboot") == 0) {
         printf("Rebooting system...\n");
         system("reboot");
      } else if (strcmp(command, "shutdown") == 0) {
         printf("Shutting down system...\n");
         system("shutdown");
      } else if (strcmp(command, "listdir") == 0) {
         printf("Listing directory...\n");
         system("ls -l");
      } else {
         printf("Unknown command '%s'\n", command);
      }
   }

   printf("-----------------------------------------------\n");
   printf("Exiting System Administration Program\n");
   printf("-----------------------------------------------\n");

   return 0;
}