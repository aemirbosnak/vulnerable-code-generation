//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int hours;
  int minutes;
} Time;

typedef struct {
  char name[50];
  Time time;
} Appointment;

int main() {
  Appointment appointments[10];
  int appointmentCount = 0;

  while (1) {
    printf("What would you like to do? (add, view, or exit)\n");
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
      if (appointmentCount == 10) {
        printf("Sorry, you can't add any more appointments. Please remove one first.\n");
      } else {
        Appointment newAppointment;
        printf("What is the name of the appointment?\n");
        scanf("%s", newAppointment.name);

        printf("What time is the appointment? (hh:mm)\n");
        scanf("%d:%d", &newAppointment.time.hours, &newAppointment.time.minutes);

        appointments[appointmentCount] = newAppointment;
        appointmentCount++;

        printf("Appointment added!\n");
      }
    } else if (strcmp(input, "view") == 0) {
      printf("Your appointments:\n");

      for (int i = 0; i < appointmentCount; i++) {
        printf("%s at %02d:%02d\n", appointments[i].name, appointments[i].time.hours, appointments[i].time.minutes);
      }
    } else if (strcmp(input, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("Sorry, I didn't understand that.\n");
    }
  }

  return 0;
}