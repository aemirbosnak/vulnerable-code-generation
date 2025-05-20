//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[20];
  char date[20];
  char time[20];
} Appointment;

void displayAppointments(Appointment appointments[]) {
  for (int i = 0; i < MAX_Appointments; i++) {
    if (appointments[i].name[0] != '\0') {
      printf("%s - %s - %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
  }
}

void addAppointment(Appointment appointments[]) {
  for (int i = 0; i < MAX_Appointments; i++) {
    if (appointments[i].name[0] == '\0') {
      printf("Enter your name: ");
      scanf("%s", appointments[i].name);

      printf("Enter the date (dd/mm/yyyy): ");
      scanf("%s", appointments[i].date);

      printf("Enter the time (hh:mm): ");
      scanf("%s", appointments[i].time);

      return;
    }
  }

  printf("Sorry, all appointments are full.\n");
}

int main() {
  Appointment appointments[MAX_Appointments];

  displayAppointments(appointments);

  addAppointment(appointments);

  displayAppointments(appointments);

  return 0;
}