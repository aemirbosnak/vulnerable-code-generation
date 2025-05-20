//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

/* Cyberlog Analysis Example Program */

int main() {

   int access_level;
   char username[50], log[100];
   
   printf("Enter your username: ");
   scanf("%s", username);
   
   printf("Enter your access level (1 - 3): ");
   scanf("%d", &access_level);
   
   if (access_level == 1) {
       printf("Welcome, %s. Accessing logs...\n", username);
       
       printf("Loading log for user: %s\n", username);
       printf("--------------------------------------------------\n");
       printf("| ID  |    Timestamp    |       Action        |\n");
       printf("--------------------------------------------------\n");
       
       // Example log entries for access level 1
       printf("| 001 | 10:00:00 01/01 |     Login           |\n");
       printf("| 002 | 10:10:00 01/01 |    Data Access      |\n");
       printf("| 003 | 10:30:00 01/01 |   Password Change   |\n");
       printf("--------------------------------------------------\n");
       
   } else if (access_level == 2) {
       printf("Welcome, %s. Accessing logs...\n", username);
       
       printf("Loading log for user: %s\n", username);
       printf("--------------------------------------------------\n");
       printf("| ID  |    Timestamp    |       Action        |\n");
       printf("--------------------------------------------------\n");
       
       // Example log entries for access level 2
       printf("| 004 | 11:00:00 01/01 |     Login           |\n");
       printf("| 005 | 11:30:00 01/01 |    Data Access      |\n");
       printf("| 006 | 12:00:00 01/01 |   File Download     |\n");
       printf("--------------------------------------------------\n");
       
   } else if (access_level == 3) {
       printf("Welcome, %s. Accessing logs...\n", username);
       
       printf("Loading log for user: %s\n", username);
       printf("--------------------------------------------------\n");
       printf("| ID  |    Timestamp    |       Action        |\n");
       printf("--------------------------------------------------\n");
       
       // Example log entries for access level 3
       printf("| 007 | 13:00:00 01/01 |     Login           |\n");
       printf("| 008 | 14:00:00 01/01 |    Data Access      |\n");
       printf("| 009 | 15:00:00 01/01 |   System Shutdown   |\n");
       printf("--------------------------------------------------\n");
       
   } else {
       printf("Access denied. Invalid access level.\n");
   }
   
   return 0;
}