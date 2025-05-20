//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct appointment { 
   char date[15];
   char time[10];
   char name[30];
};

int main() {
   int choice, count;
   struct appointment apt[100];

   while (1) {
      printf("Enter 1 to schedule an appointment\n");
      printf("Enter 2 to view all appointments\n");
      printf("Enter 3 to cancel an appointment\n");
      printf("Enter 4 to exit\n");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("Enter date of appointment (mm/dd/yyyy): ");
            scanf("%s", &apt[count].date);
            printf("Enter time of appointment (hh:mm am/pm): ");
            scanf("%s", &apt[count].time);
            printf("Enter name of appointment: ");
            scanf("%s", &apt[count].name);
            printf("Appointment scheduled!\n");
            count++;
            break;

         case 2:
            if (count == 0) {
               printf("No appointments scheduled.\n");
            } else {
               printf("Scheduled Appointments:\n");
               for (int i = 0; i < count; i++) {
                  printf("Date: %s\n", apt[i].date);
                  printf("Time: %s\n", apt[i].time);
                  printf("Name: %s\n", apt[i].name);
                  printf("-----------------------\n");
               }
            }
            break;

         case 3:
            if (count == 0) {
               printf("No appointments scheduled.\n");
            } else {
               char cancel_date[15], cancel_time[10], cancel_name[30];
               printf("Enter date of appointment to cancel (mm/dd/yyyy): ");
               scanf("%s", &cancel_date);
               printf("Enter time of appointment to cancel (hh:mm am/pm): ");
               scanf("%s", &cancel_time);
               printf("Enter name of appointment to cancel: ");
               scanf("%s", &cancel_name);

               for (int i = 0; i < count; i++) {
                  if (strcmp(apt[i].date, cancel_date) == 0 &&
                      strcmp(apt[i].time, cancel_time) == 0 &&
                      strcmp(apt[i].name, cancel_name) == 0) {
                        printf("Appointment removed!\n");
                        for (int j = i; j < count - 1; j++) {
                           apt[j] = apt[j+1];
                        }
                        count--;
                        break;
                  }
               }
            }
            break;

         case 4:
            printf("Exiting Appointment Scheduler.\n");
            exit(0);

         default:
            printf("Invalid input. Please try again.\n");
            break;
      }      
   }
   return 0;
}