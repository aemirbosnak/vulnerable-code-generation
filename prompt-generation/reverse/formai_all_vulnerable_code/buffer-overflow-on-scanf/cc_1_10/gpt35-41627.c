//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
  char date[11];
  char time[6];
  char location[20];
};

void addAppointment(struct appointment appointments[], int *count) {
  getchar();
  printf("Enter the date (dd/mm/yyyy): ");
  fgets(appointments[*count].date, 11, stdin);
  printf("Enter the time (hh:mm): ");
  fgets(appointments[*count].time, 6, stdin);
  printf("Enter the location: ");
  fgets(appointments[*count].location, 20, stdin);
  (*count)++;
}

void printAppointments(struct appointment appointments[], int count) {
  if (count == 0) {
    printf("No appointments scheduled.\n");
    return;
  }
  printf("Scheduled Appointments:\n");
  for (int i = 0; i < count; i++) {
    printf("%d. Date: %s Time: %s Location: %s", i+1, appointments[i].date, appointments[i].time, appointments[i].location);
  }
}

void removeAppointment(struct appointment appointments[], int *count) {
  if (*count == 0) {
    printf("No appointments scheduled.\n");
    return;
  }

  printf("Which appointment would you like to remove? ");
  int index;
  scanf("%d", &index);
  if (index < 1 || index > *count) {
    printf("Invalid appointment index.\n");
    return;
  }

  for (int i = index-1; i < *count-1; i++) {
    strcpy(appointments[i].date, appointments[i+1].date);
    strcpy(appointments[i].time, appointments[i+1].time);
    strcpy(appointments[i].location, appointments[i+1].location);
  }

  (*count)--;
  printf("Appointment removed.\n");
}

int main() {
  struct appointment appointments[10];
  int count = 0;

  while (1) {
    getchar();
    printf("\nAppointment Scheduler\n");
    printf("1. Schedule a new appointment\n");
    printf("2. Print scheduled appointments\n");
    printf("3. Remove an appointment\n");
    printf("4. Exit\n");

    char input[2];
    fgets(input, 2, stdin);

    switch (input[0]) {
      case '1': addAppointment(appointments, &count); break;
      case '2': printAppointments(appointments, count); break;
      case '3': removeAppointment(appointments, &count); break;
      case '4': return 0;
      default: printf("Invalid selection.\n");
    }
  }
}