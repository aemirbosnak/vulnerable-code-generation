//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_APPOINTMENTS 10

typedef struct {
  char name[MAX_NAME];
  int time;
  char location[MAX_NAME];
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
  if (num_appointments == MAX_APPOINTMENTS) {
    printf("No more appointments can be added.\n");
    return;
  }

  printf("Enter the name of the person you want to schedule an appointment for: ");
  scanf("%s", appointments[num_appointments].name);

  printf("Enter the time of the appointment (in hours): ");
  scanf("%d", &appointments[num_appointments].time);

  printf("Enter the location of the appointment: ");
  scanf("%s", appointments[num_appointments].location);

  num_appointments++;
}

void list_appointments() {
  if (num_appointments == 0) {
    printf("No appointments to list.\n");
    return;
  }

  for (int i = 0; i < num_appointments; i++) {
    printf("%s - %d - %s\n", appointments[i].name, appointments[i].time, appointments[i].location);
  }
}

int main() {
  int choice;

  do {
    printf("1. Add an appointment\n");
    printf("2. List appointments\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_appointment();
        break;
      case 2:
        list_appointments();
        break;
      case 3:
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 3);

  return 0;
}