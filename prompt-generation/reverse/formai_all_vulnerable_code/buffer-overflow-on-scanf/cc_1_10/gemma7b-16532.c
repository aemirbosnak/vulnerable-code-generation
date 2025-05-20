//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  int day;
  int month;
  int year;
  struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, int day, int month, int year) {
  Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
  strcpy(newAppointment->name, name);
  newAppointment->day = day;
  newAppointment->month = month;
  newAppointment->year = year;
  newAppointment->next = NULL;
  return newAppointment;
}

int main() {
  Appointment* head = NULL;
  char name[MAX_NAME_LENGTH];
  int day, month, year;

  printf("Welcome to the Surprising Appointment Scheduler!\n");

  while (1) {
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the day of your appointment (1-31): ");
    scanf("%d", &day);

    printf("Enter the month of your appointment (1-12): ");
    scanf("%d", &month);

    printf("Enter the year of your appointment (2023-2024): ");
    scanf("%d", &year);

    Appointment* newAppointment = createAppointment(name, day, month, year);
    if (head == NULL) {
      head = newAppointment;
    } else {
      newAppointment->next = head;
      head = newAppointment;
    }

    printf("Your appointment has been scheduled.\n");

    if (strcmp(name, "Exit") == 0) {
      break;
    }
  }

  printf("Thank you for using the Surprising Appointment Scheduler!\n");

  return 0;
}