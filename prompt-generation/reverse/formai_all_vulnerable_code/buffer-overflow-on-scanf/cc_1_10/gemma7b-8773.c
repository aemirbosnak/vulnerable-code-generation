//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
} Appointment;

Appointment appointments[MAX_Appointments];

int main() {
  int i = 0;
  int numAppointments = 0;

  // Initialize the appointments array
  for (i = 0; i < MAX_Appointments; i++) {
    appointments[i].name[0] = '\0';
    appointments[i].date[0] = '\0';
    appointments[i].time[0] = '\0';
  }

  // Get the number of appointments from the user
  printf("Enter the number of appointments you want to make: ");
  scanf("%d", &numAppointments);

  // Create the appointments
  for (i = 0; i < numAppointments; i++) {
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[i].name);

    printf("Enter the date of the appointment: ");
    scanf("%s", appointments[i].date);

    printf("Enter the time of the appointment: ");
    scanf("%s", appointments[i].time);
  }

  // Print the appointments
  printf("Here is your list of appointments:\n");
  for (i = 0; i < numAppointments; i++) {
    printf("Name: %s\n", appointments[i].name);
    printf("Date: %s\n", appointments[i].date);
    printf("Time: %s\n", appointments[i].time);
    printf("\n");
  }

  return 0;
}