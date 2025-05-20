//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
/*
 * Appointment Scheduler Example Program
 *
 * This program allows users to schedule appointments for a day.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment structure
struct appointment {
  char name[20];
  int day;
  int month;
  int year;
  int hour;
  int minute;
  int second;
};

// Function to add an appointment
void addAppointment(struct appointment *appt) {
  printf("Enter the appointment name: ");
  scanf("%s", appt->name);
  printf("Enter the appointment day: ");
  scanf("%d", &appt->day);
  printf("Enter the appointment month: ");
  scanf("%d", &appt->month);
  printf("Enter the appointment year: ");
  scanf("%d", &appt->year);
  printf("Enter the appointment hour: ");
  scanf("%d", &appt->hour);
  printf("Enter the appointment minute: ");
  scanf("%d", &appt->minute);
  printf("Enter the appointment second: ");
  scanf("%d", &appt->second);
}

// Function to display all appointments
void displayAppointments(struct appointment *appts, int numAppts) {
  int i;
  for (i = 0; i < numAppts; i++) {
    printf("Appointment %d:\n", i + 1);
    printf("  Name: %s\n", appts[i].name);
    printf("  Day: %d\n", appts[i].day);
    printf("  Month: %d\n", appts[i].month);
    printf("  Year: %d\n", appts[i].year);
    printf("  Hour: %d\n", appts[i].hour);
    printf("  Minute: %d\n", appts[i].minute);
    printf("  Second: %d\n", appts[i].second);
    printf("\n");
  }
}

int main() {
  struct appointment appts[10];
  int numAppts = 0;
  int choice;

  do {
    printf("1. Add an appointment\n");
    printf("2. Display all appointments\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addAppointment(&appts[numAppts]);
        numAppts++;
        break;
      case 2:
        displayAppointments(appts, numAppts);
        break;
      case 3:
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 3);

  return 0;
}