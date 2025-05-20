//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char command[50];
   printf("Welcome to Curious System Administrator!\n");

   while(1) {
      printf("Enter a command (type 'help' for a list of commands): ");
      scanf("%s", command);

      if(strcmp(command, "help") == 0) {
         printf("Current available commands:\n");
         printf("\t1. ls\n");
         printf("\t2. cat\n");
         printf("\t3. chmod\n");
         printf("\t4. mkdir\n");
         printf("\t5. rm\n");
         printf("\t6. whoami\n");
         printf("\t7. passwd\n");
         printf("\t8. ps\n");
         printf("\t9. top\n");
         printf("\t10. exit\n");

      } else if(strcmp(command, "ls") == 0) {
         printf("Current contents of directory:\n");
         system("ls");

      } else if(strcmp(command, "cat") == 0) {
         char filename[50];
         printf("Enter filename to read: ");
         scanf("%s", filename);
         char cmd[500] = "cat ";
         strcat(cmd, filename);
         system(cmd);

      } else if(strcmp(command, "chmod") == 0) {
         char mode[10];
         char filename[50];
         printf("Enter filename to change permissions: ");
         scanf("%s", filename);
         printf("Enter new permissions mode (e.g. 755): ");
         scanf("%s", mode);
         char cmd[500] = "chmod ";
         strcat(cmd, mode);
         strcat(cmd, " ");
         strcat(cmd, filename);
         system(cmd);

      } else if(strcmp(command, "mkdir") == 0) {
         char dirname[50];
         printf("Enter directory name to create: ");
         scanf("%s", dirname);
         char cmd[500] = "mkdir ";
         strcat(cmd, dirname);
         system(cmd);

      } else if(strcmp(command, "rm") == 0) {
         char filename[50];
         printf("Enter filename to delete: ");
         scanf("%s", filename);
         char cmd[500] = "rm ";
         strcat(cmd, filename);
         system(cmd);

      } else if(strcmp(command, "whoami") == 0) {
         system("whoami");

      } else if(strcmp(command, "passwd") == 0) {
         system("passwd");

      } else if(strcmp(command, "ps") == 0) {
         system("ps");

      } else if(strcmp(command, "top") == 0) {
         system("top");

      } else if(strcmp(command, "exit") == 0) {
         printf("Goodbye!\n");
         return 0;

      } else {
         printf("Invalid command, please try again.\n");
      }
   }
}