//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
   char execute[100];
   char option[10];
   int choice;

   printf("Welcome to the Grateful System Administration!\n");
   printf("What can I help you with today?\n");
   printf("1. Show running processes\n");
   printf("2. Check system information\n");
   printf("3. View memory usage\n");
   printf("4. View disk usage\n");
   printf("5. Restart system\n");
   printf("6. Exit\n");

   do {
      printf("Enter your choice (1-6): ");
      scanf("%d",&choice);

      switch(choice) {
         case 1:
            strcpy(option, "-e");
            break;
         case 2:
            strcpy(option, "-h");
            break;
         case 3:
            strcpy(option, "-m");
            break;
         case 4:
            strcpy(option, "-d");
            break;
         case 5:
            printf("Restarting system...\n");
            sleep(2);
            printf("System successfully restarted!\n");
            exit(0);
         case 6:
            printf("Thanks for using Grateful System Administration!\n");
            exit(0);
         default:
            printf("Invalid choice. Please try again.\n");
            continue;
      }

      sprintf(execute, "sudo %s %s", "systemctl", option);
      
      printf("Executing command: %s\n", execute);
      printf("---------------------------------\n");

      FILE *f = popen(execute, "r");
      char buffer[1000];

      while(fgets(buffer, sizeof(buffer), f) != NULL) {
         printf("%s",buffer);
      }

      printf("---------------------------------\n");

      pclose(f);

   } while(1);

   return 0;
}