//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 10

typedef struct Appointment {
   char date[20];
   char time[20];
   char description[50];
} Appointment;

typedef struct Scheduler {
   Appointment appts[MAX_APPTS];
   int count;
} Scheduler;

void displayAppointments(Scheduler *scheduler) {
   printf("\nList of scheduled appointments:\n");
   for(int i = 0; i < scheduler->count; i++) {
      printf("%d.\n", i+1);
      printf("Date: %s\n", scheduler->appts[i].date);
      printf("Time: %s\n", scheduler->appts[i].time);
      printf("Description: %s\n\n", scheduler->appts[i].description);
   }
}

int addAppointment(Scheduler *scheduler, char *date, char *time, char *description) {
   if(scheduler->count >= MAX_APPTS) {
      return 0;
   }
   strcpy(scheduler->appts[scheduler->count].date, date);
   strcpy(scheduler->appts[scheduler->count].time, time);
   strcpy(scheduler->appts[scheduler->count].description, description);
   scheduler->count++;
   return 1;
}

int deleteAppointment(Scheduler *scheduler, int index) {
   if(index < 0 || index >= scheduler->count) {
      return 0;
   }
   for(int i = index; i < scheduler->count-1; i++) {
      strcpy(scheduler->appts[i].date, scheduler->appts[i+1].date);
      strcpy(scheduler->appts[i].time, scheduler->appts[i+1].time);
      strcpy(scheduler->appts[i].description, scheduler->appts[i+1].description);
   }
   scheduler->count--;
   return 1;
}

int main() {
   Scheduler scheduler;
   scheduler.count = 0;

   printf("C Appointment Scheduler Program\n\n");

   while(1) {
      printf("Enter command (add/delete/display/exit): ");
      char command[10];
      scanf("%s", command);

      if(strcmp(command, "add") == 0) {
         char date[20];
         char time[20];
         char description[50];
         printf("Enter date (mm/dd/yyyy): ");
         scanf("%s", date);
         printf("Enter time (hh:mm): ");
         scanf("%s", time);
         printf("Enter appointment description: ");
         scanf(" %[^\n]", description);
         int result = addAppointment(&scheduler, date, time, description);
         if(result == 0) {
            printf("Appointment not added. Maximum number of appointments reached.\n");
         } else {
            printf("Appointment added.\n");
         }
      } else if(strcmp(command, "delete") == 0) {
         int index;
         printf("Enter appointment number to delete: ");
         scanf("%d", &index);
         int result = deleteAppointment(&scheduler, index-1);
         if(result == 0) {
            printf("Appointment not deleted. Invalid appointment number.\n");
         } else {
            printf("Appointment deleted.\n");
         }
      } else if(strcmp(command, "display") == 0) {
         if(scheduler.count == 0) {
            printf("No appointments scheduled.\n");
         } else {
            displayAppointments(&scheduler);
         }
      } else if(strcmp(command, "exit") == 0) {
         break;
      } else {
         printf("Invalid command. Please try again.\n");
      }

      printf("\n");
   }

   printf("Goodbye.\n");

   return EXIT_SUCCESS;
}