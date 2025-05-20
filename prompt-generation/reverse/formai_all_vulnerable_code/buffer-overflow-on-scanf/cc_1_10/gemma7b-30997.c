//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
  char name[20];
  int day;
  int month;
  int year;
} Appointment;

int main() {
  Appointment appointments[MAX_APPOINTMENTS];
  int numAppointments = 0;

  // Create a loop to add appointments
  while (1) {
    // Get the appointment name, day, month, and year
    printf("Enter the appointment name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter the appointment day (1-31): ");
    scanf("%d", &appointments[numAppointments].day);

    printf("Enter the appointment month (1-12): ");
    scanf("%d", &appointments[numAppointments].month);

    printf("Enter the appointment year: ");
    scanf("%d", &appointments[numAppointments].year);

    // Increment the number of appointments
    numAppointments++;

    // Check if the user wants to add another appointment
    printf("Do you want to add another appointment? (Y/N): ");
    char answer;
    scanf(" %c", &answer);

    // If the user does not want to add another appointment, break out of the loop
    if (answer == 'N') {
      break;
    }
  }

  // Print the appointments
  printf("Your appointments:\n");
  for (int i = 0; i < numAppointments; i++) {
    printf("%s on %d/%d/%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year);
  }

  return 0;
}