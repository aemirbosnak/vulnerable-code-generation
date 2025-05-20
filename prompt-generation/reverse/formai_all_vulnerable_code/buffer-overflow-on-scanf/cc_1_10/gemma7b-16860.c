//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
  char name[20];
  char time[20];
  char date[20];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

int main() {
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  time_t t_now;
  struct tm *tm_now;

  t_now = time(NULL);
  tm_now = localtime(t_now);

  for (i = 0; i < MAX_APPOINTMENTS; i++) {
    appointments[i].name[0] = '\0';
    appointments[i].time[0] = '\0';
    appointments[i].date[0] = '\0';
  }

  printf("Greetings, traveler, and welcome to the surrealist C Appointment Scheduler!\n");

  printf("Please choose an option:\n");
  printf("1. Schedule an appointment\n");
  printf("2. View appointments\n");
  printf("3. Delete an appointment\n");

  scanf(" ", &n);

  switch (n) {
    case 1:
      printf("Enter your name: ");
      scanf("%s", appointments[i].name);

      printf("Enter the time of your appointment (HH:MM): ");
      scanf("%s", appointments[i].time);

      printf("Enter the date of your appointment (DD/MM/YY): ");
      scanf("%s", appointments[i].date);

      printf("Your appointment has been scheduled.\n");
      break;

    case 2:
      printf("Here is a list of your appointments:\n");

      for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] != '\0') {
          printf("Name: %s, Time: %s, Date: %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
        }
      }
      break;

    case 3:
      printf("Enter the name of the appointment you want to delete: ");
      scanf("%s", appointments[i].name);

      for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(appointments[i].name, appointments[i].name) == 0) {
          appointments[i].name[0] = '\0';
          appointments[i].time[0] = '\0';
          appointments[i].date[0] = '\0';
        }
      }

      printf("Your appointment has been deleted.\n");
      break;
  }

  return 0;
}