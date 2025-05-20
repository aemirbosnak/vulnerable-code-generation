//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
/*
 * Appointment Scheduler
 *
 * This program allows users to schedule appointments for a specific date and time.
 * It also allows users to view and modify their scheduled appointments.
 *
 * Usage:
 * 1. Compile the program with `gcc -o scheduler scheduler.c`
 * 2. Run the program with `./scheduler`
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct appointment {
  char name[100];
  char description[100];
  time_t date;
} appointment;

int main() {
  appointment appointments[MAX_APPOINTMENTS];
  int num_appointments = 0;

  printf("Appointment Scheduler\n");
  printf("--------------------\n");

  while (1) {
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Modify a scheduled appointment\n");
    printf("4. Exit\n");
    printf("Enter a command: ");

    int command;
    scanf("%d", &command);

    switch (command) {
      case 1:
        if (num_appointments >= MAX_APPOINTMENTS) {
          printf("Maximum number of appointments reached.\n");
          break;
        }

        printf("Enter appointment name: ");
        scanf("%s", appointments[num_appointments].name);

        printf("Enter appointment description: ");
        scanf("%s", appointments[num_appointments].description);

        printf("Enter appointment date (YYYY-MM-DD): ");
        scanf("%s", appointments[num_appointments].date);

        num_appointments++;
        break;

      case 2:
        for (int i = 0; i < num_appointments; i++) {
          printf("%s: %s\n", appointments[i].name, appointments[i].description);
        }
        break;

      case 3:
        printf("Enter appointment index to modify: ");
        int index;
        scanf("%d", &index);

        if (index < 0 || index >= num_appointments) {
          printf("Invalid appointment index.\n");
          break;
        }

        printf("Enter new appointment name: ");
        scanf("%s", appointments[index].name);

        printf("Enter new appointment description: ");
        scanf("%s", appointments[index].description);

        printf("Enter new appointment date (YYYY-MM-DD): ");
        scanf("%s", appointments[index].date);
        break;

      case 4:
        return 0;
        break;

      default:
        printf("Invalid command.\n");
        break;
    }
  }

  return 0;
}