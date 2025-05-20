//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
  char name[50];
  char date[10];
  char time[5];
  char description[100];
};

int main() {
  int choice, num_appointments = 0, i;
  struct appointment *appointments = NULL;
  
  while(1) {
    printf("FUTURISTIC APPOINTMENT SCHEDULER\n");
    printf("Select an option:\n");
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        if(num_appointments == 0) {
          appointments = (struct appointment*) malloc(sizeof(struct appointment));
        } else {
          appointments = (struct appointment*) realloc(appointments, (num_appointments + 1) * sizeof(struct appointment));
        }
        printf("Enter name: ");
        scanf("%s", appointments[num_appointments].name);
        printf("Enter date (in the format MM/DD/YYYY): ");
        scanf("%s", appointments[num_appointments].date);
        printf("Enter time (in the 24-hour format HH:MM): ");
        scanf("%s", appointments[num_appointments].time);
        printf("Enter description: ");
        scanf("%s", appointments[num_appointments].description);
        printf("Appointment scheduled successfully!\n");
        num_appointments++;
        break;
      case 2:
        if(num_appointments == 0) {
          printf("You have no scheduled appointments.\n");
          break;
        }
        printf("SCHEDULED APPOINTMENTS\n");
        printf("-------------------------------------------------\n");
        printf("| %-5s | %-15s | %-8s | %-20s |\n", "ID", "Name", "Time", "Description");
        printf("-------------------------------------------------\n");
        for(i = 0; i < num_appointments; i++) {
          printf("| %-5d | %-15s | %-8s | %-20s |\n", i+1, appointments[i].name, appointments[i].time, appointments[i].description);
        }
        printf("-------------------------------------------------\n");
        break;
      case 3:
        if(num_appointments == 0) {
          printf("You have no scheduled appointments to cancel.\n");
          break;
        }
        printf("Enter the ID of the appointment you want to cancel: ");
        scanf("%d", &i);
        if(i <= 0 || i > num_appointments) {
          printf("Invalid appointment ID.\n");
          break;
        }
        for(; i < num_appointments; i++) {
          strcpy(appointments[i-1].name, appointments[i].name);
          strcpy(appointments[i-1].date, appointments[i].date);
          strcpy(appointments[i-1].time, appointments[i].time);
          strcpy(appointments[i-1].description, appointments[i].description);
        }
        num_appointments--;
        appointments = (struct appointment*) realloc(appointments, num_appointments * sizeof(struct appointment));
        printf("Appointment cancelled successfully!\n");
        break;
      case 4:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  }
  return 0;
}