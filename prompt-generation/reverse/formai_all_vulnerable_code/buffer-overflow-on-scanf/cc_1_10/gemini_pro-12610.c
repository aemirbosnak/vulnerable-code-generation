//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 100

typedef struct Appointment {
  char name[50];
  char date[20];
  char time[20];
  char location[50];
  char description[100];
} Appointment;

void printAppointment(Appointment appointment) {
  printf("Name: %s\n", appointment.name);
  printf("Date: %s\n", appointment.date);
  printf("Time: %s\n", appointment.time);
  printf("Location: %s\n", appointment.location);
  printf("Description: %s\n", appointment.description);
  printf("\n");
}

int main() {
  Appointment appointments[MAX_APPOINTMENTS];
  int numAppointments = 0;

  char input[100];
  while (strcmp(input, "quit") != 0) {
    printf("Enter a command (add, list, or quit): ");
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
      Appointment newAppointment;
      printf("Enter your name: ");
      scanf("%s", newAppointment.name);
      printf("Enter the date: ");
      scanf("%s", newAppointment.date);
      printf("Enter the time: ");
      scanf("%s", newAppointment.time);
      printf("Enter the location: ");
      scanf("%s", newAppointment.location);
      printf("Enter a description: ");
      scanf(" %[^\n]%*c", newAppointment.description);

      appointments[numAppointments] = newAppointment;
      numAppointments++;
    } else if (strcmp(input, "list") == 0) {
      for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
      }
    } else if (strcmp(input, "quit") != 0) {
      printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}