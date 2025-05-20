//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

// Appointment structure definition
typedef struct {
  int day;
  int month;
  int year;
  char time[6];
  char patient_name[30];
} Appointment;

// Function prototypes
void addAppointment(Appointment appointmentList[], int* numAppointments);
void displayAppointments(Appointment appointmentList[], int numAppointments);

int main() {
  // Declare variables
  Appointment appointmentList[MAX_APPOINTMENTS];
  int numAppointments = 0;
  char choice = ' ';

  // Loop to display menu until user exits
  while (choice != 'q') {
    // Display menu options
    printf("\nAppointment Scheduler\n");
    printf("a - Add Appointment\n");
    printf("d - Display Appointments\n");
    printf("q - Quit\n");
    printf("Enter choice: ");

    // Get user choice
    scanf(" %c", &choice);

    // Process user choice
    switch (choice) {
      case 'a':
        addAppointment(appointmentList, &numAppointments);
        break;
      case 'd':
        displayAppointments(appointmentList, numAppointments);
        break;
      case 'q':
        printf("Exiting program. Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please enter a, d, or q.\n");
        break;
    }
  }

  return 0;
}

void addAppointment(Appointment appointmentList[], int* numAppointments) {
  // Check if there is room for new appointment
  if (*numAppointments == MAX_APPOINTMENTS) {
    printf("Appointment list is full. Cannot add more appointments.\n");
    return;
  }

  // Get appointment details from user
  Appointment newAppointment;
  printf("\nEnter appointment details:\n");
  printf("Date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &newAppointment.month, &newAppointment.day, &newAppointment.year);
  printf("Time (hh:mm): ");
  scanf("%s", newAppointment.time);
  printf("Patient name: ");
  scanf(" %[^\n]", newAppointment.patient_name);

  // Add new appointment to list
  appointmentList[*numAppointments] = newAppointment;
  (*numAppointments)++;

  printf("Appointment added.\n");
}

void displayAppointments(Appointment appointmentList[], int numAppointments) {
  // Check if there are appointments to display
  if (numAppointments == 0) {
    printf("No appointments to display.\n");
    return;
  }

  // Display all appointments in the list
  printf("\nAppointments:\n");
  printf("Date\t\tTime\t\tPatient Name\n");
  for (int i = 0; i < numAppointments; i++) {
    printf("%d/%d/%d\t%s\t\t%s\n", appointmentList[i].month, appointmentList[i].day, appointmentList[i].year, appointmentList[i].time, appointmentList[i].patient_name);
  }
}