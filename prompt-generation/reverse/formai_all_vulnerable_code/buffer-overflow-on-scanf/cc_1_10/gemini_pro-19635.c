//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 25

typedef struct appointment {
  char name[MAX_NAME_LENGTH];
  int day;
  int month;
  int year;
  int hour;
  int minute;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
  if (num_appointments == MAX_APPOINTMENTS) {
    printf("Sorry, no more appointments can be added.\n");
    return;
  }

  printf("Enter the appointment details:\n");
  printf("Name: ");
  scanf("%s", appointments[num_appointments].name);
  printf("Day: ");
  scanf("%d", &appointments[num_appointments].day);
  printf("Month: ");
  scanf("%d", &appointments[num_appointments].month);
  printf("Year: ");
  scanf("%d", &appointments[num_appointments].year);
  printf("Hour: ");
  scanf("%d", &appointments[num_appointments].hour);
  printf("Minute: ");
  scanf("%d", &appointments[num_appointments].minute);

  num_appointments++;
}

void print_appointments() {
  if (num_appointments == 0) {
    printf("No appointments to display.\n");
    return;
  }

  printf("Appointments:\n");
  for (int i = 0; i < num_appointments; i++) {
    printf("%s: %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
  }
}

void search_appointments() {
  char name[MAX_NAME_LENGTH];

  printf("Enter the name to search for: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      printf("Appointment found:\n");
      printf("%s: %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("No appointments found for the given name.\n");
  }
}

void delete_appointment() {
  char name[MAX_NAME_LENGTH];

  printf("Enter the name of the appointment to delete: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      for (int j = i; j < num_appointments - 1; j++) {
        appointments[j] = appointments[j + 1];
      }
      num_appointments--;
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("No appointments found for the given name.\n");
  }
}

int main() {
  int choice;

  do {
    printf("Appointment Scheduler\n");
    printf("1. Add appointment\n");
    printf("2. Print appointments\n");
    printf("3. Search appointments\n");
    printf("4. Delete appointment\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_appointment();
        break;
      case 2:
        print_appointments();
        break;
      case 3:
        search_appointments();
        break;
      case 4:
        delete_appointment();
        break;
      case 5:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);

  return 0;
}