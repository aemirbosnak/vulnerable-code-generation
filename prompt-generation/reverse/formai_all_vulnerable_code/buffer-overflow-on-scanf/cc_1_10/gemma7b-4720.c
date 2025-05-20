//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
  char name[50];
  char date[50];
  char time[50];
} Appointment;

Appointment appointments[MAX_Appointments];

void displayAppointments() {
  for (int i = 0; i < MAX_Appointments; i++) {
    if (appointments[i].name[0] != '\0') {
      printf("Name: %s\n", appointments[i].name);
      printf("Date: %s\n", appointments[i].date);
      printf("Time: %s\n", appointments[i].time);
      printf("\n");
    }
  }
}

void addAppointment() {
  Appointment newAppointment;

  printf("Enter your name: ");
  scanf("%s", newAppointment.name);

  printf("Enter the date: ");
  scanf("%s", newAppointment.date);

  printf("Enter the time: ");
  scanf("%s", newAppointment.time);

  for (int i = 0; i < MAX_Appointments; i++) {
    if (appointments[i].name[0] == '\0') {
      appointments[i] = newAppointment;
      break;
    }
  }

  printf("Appointment added successfully!\n");
}

int main() {
  int choice;

  printf("Welcome to the C Appointment Scheduler!\n");

  while (1) {
    printf("1. Display Appointments\n");
    printf("2. Add an Appointment\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        displayAppointments();
        break;
      case 2:
        addAppointment();
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("\n");
  }

  return 0;
}