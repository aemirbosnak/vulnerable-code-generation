//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
  char name[50];
  char date[20];
  char time[20];
  char description[200];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
  if (num_appointments >= MAX_APPOINTMENTS) {
    printf("Sorry, your schedule is full!\n");
    return;
  }

  printf("What is your name?\n");
  scanf("%s", appointments[num_appointments].name);

  printf("What is the date of your appointment?\n");
  scanf("%s", appointments[num_appointments].date);

  printf("What is the time of your appointment?\n");
  scanf("%s", appointments[num_appointments].time);

  printf("What is a brief description of your appointment?\n");
  scanf(" %[^\n]", appointments[num_appointments].description); // Read the rest of the line

  num_appointments++;

  printf("Your appointment has been added!\n");
}

void view_appointments() {
  if (num_appointments == 0) {
    printf("You don't have any appointments yet!\n");
    return;
  }

  printf("Here are your appointments:\n");

  for (int i = 0; i < num_appointments; i++) {
    printf("%s, %s, %s, %s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
  }
}

void delete_appointment() {
  if (num_appointments == 0) {
    printf("You don't have any appointments to delete!\n");
    return;
  }

  printf("What is the name of the person you want to delete an appointment for?\n");
  char name[50];
  scanf("%s", name);

  printf("What is the date of the appointment you want to delete?\n");
  char date[20];
  scanf("%s", date);

  printf("What is the time of the appointment you want to delete?\n");
  char time[20];
  scanf("%s", time);

  int index = -1;
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].name, name) == 0 && strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("No appointment found with that information.\n");
    return;
  }

  for (int i = index; i < num_appointments - 1; i++) {
    appointments[i] = appointments[i + 1];
  }

  num_appointments--;

  printf("Appointment deleted!\n");
}

int main() {
  int choice;

  do {
    printf("What would you like to do?\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_appointment();
        break;
      case 2:
        view_appointments();
        break;
      case 3:
        delete_appointment();
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);

  return 0;
}