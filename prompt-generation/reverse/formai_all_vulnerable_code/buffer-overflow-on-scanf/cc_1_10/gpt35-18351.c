//FormAI DATASET v1.0 Category: System event logger ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   FILE *fp;
   int choice, severity;
   time_t rawtime;
   struct tm * timeinfo;
   
   printf("Welcome to the C System Event Logger! \n\n");

   fp = fopen("system_log.txt", "w");
   
   if(fp == NULL) {
     printf("Error: Could not create log file.\n");
     exit(1);
   }

   printf("Please select the type of event: \n"
           "1. Informational \n"
           "2. Warning \n"
           "3. Error \n"
           "4. Critical \n");

   scanf("%d", &choice);

   printf("\n Please enter a brief description of the event : ");
   char description[100];
   scanf("%s", description);

   printf("\n Please enter severity of the event (0 to 10) : ");
   scanf("%d", &severity);

   time(&rawtime);
   timeinfo = localtime(&rawtime);

   fprintf(fp, "Type: ");
   
   switch(choice) {
      case 1 :
         fprintf(fp, "INFO\n");
         fprintf(fp, "Description: %s\n", description);
         fprintf(fp, "Severity: %d\n", severity);
         fprintf(fp, "Time of Event: %s", asctime(timeinfo));
         printf("\n Informational event logged successfully.\n\n");
         break;

      case 2 :
         fprintf(fp, "WARNING\n");
         fprintf(fp, "Description: %s\n", description);
         fprintf(fp, "Severity: %d\n", severity);
         fprintf(fp, "Time of Event: %s", asctime(timeinfo));
         printf("\n Warning event logged successfully.\n\n");
         break;

      case 3 :
         fprintf(fp, "ERROR\n");
         fprintf(fp, "Description: %s\n", description);
         fprintf(fp, "Severity: %d\n", severity);
         fprintf(fp, "Time of Event: %s", asctime(timeinfo));
         printf("\n Error event logged successfully.\n\n");
         break;

      case 4 :
         fprintf(fp, "CRITICAL\n");
         fprintf(fp, "Description: %s\n", description);
         fprintf(fp, "Severity: %d\n", severity);
         fprintf(fp, "Time of Event: %s", asctime(timeinfo));
         printf("\n Critical event logged successfully.\n\n");
         break;

      default:
         printf("\n Invalid choice.\n\n");
         exit(1);
   }

   fclose(fp);

   return 0;
}