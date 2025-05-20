//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
  char date[20];
  char time[20];
  char name[50];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

bool is_available(char* date, char* time) {
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
      return false;
    }
  }
  return true;
}

void schedule_appointment() {
  if (num_appointments >= MAX_APPOINTMENTS) {
    printf("Sorry, all appointment slots are full.\n");
    return;
  }

  char date[20];
  char time[20];
  char name[50];

  printf("Enter appointment date: ");
  scanf("%s", date);

  printf("Enter appointment time: ");
  scanf("%s", time);

  if (!is_available(date, time)) {
    printf("Sorry, that time slot is already taken.\n");
    return;
  }

  printf("Enter patient name: ");
  scanf("%s", name);

  strcpy(appointments[num_appointments].date, date);
  strcpy(appointments[num_appointments].time, time);
  strcpy(appointments[num_appointments].name, name);

  num_appointments++;
  printf("Appointment scheduled for %s at %s, with %s.\n", date, time, name);
}

void list_appointments() {
  if (num_appointments == 0) {
    printf("There are no appointments scheduled.\n");
    return;
  }

  printf("Appointments:\n");
  printf("Date\t\tTime\t\tName\n");

  for (int i = 0; i < num_appointments; i++) {
    printf("%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name);
  }
}

int main() {
  while (true) {
    printf("\n1. Schedule appointment\n2. List appointments\n3. Exit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        schedule_appointment();
        break;
      case 2:
        list_appointments();
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice. Try again.\n");
    }
  }
}