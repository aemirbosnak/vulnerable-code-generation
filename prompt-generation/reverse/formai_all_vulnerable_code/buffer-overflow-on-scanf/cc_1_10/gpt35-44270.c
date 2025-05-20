//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 5

// Struct to store appointment details
typedef struct {
  char* date;
  char* time;
  char* patientName;
} Appointment;

// Array to hold appointments
Appointment appointments[MAX_APPOINTMENTS];

// Function to add an appointment
void addAppointment() {
  // Check if there is space for a new appointment
  int emptySlot = -1;
  for (int i = 0; i < MAX_APPOINTMENTS; i++) {
    if (appointments[i].date == NULL) {
      emptySlot = i;
      break;
    }
  }

  if (emptySlot == -1) {
    printf("Appointment slots are already full.\n");
    return;
  }

  // Get user input for appointment details
  printf("Enter date (dd/mm/yyyy): ");
  char* date = (char*)malloc(11 * sizeof(char)); // Allocate memory for date string
  scanf("%s", date);

  printf("Enter time (hh:mm): ");
  char* time = (char*)malloc(6 * sizeof(char)); // Allocate memory for time string
  scanf("%s", time);

  printf("Enter patient name: ");
  char* patientName = (char*)malloc(50 * sizeof(char)); // Allocate memory for patient name string
  scanf("%s", patientName);

  // Create new appointment and add to array
  Appointment newAppointment = {date, time, patientName};
  appointments[emptySlot] = newAppointment;
  printf("Appointment added successfully.\n");
}

// Function to view appointments for a given date
void viewAppointments() {
  // Get user input for date
  printf("Enter date to view (dd/mm/yyyy): ");
  char* date = (char*)malloc(11 * sizeof(char)); // Allocate memory for date string
  scanf("%s", date);

  // Find and print appointments for given date
  int appointmentCount = 0;
  for (int i = 0; i < MAX_APPOINTMENTS; i++) {
    if (appointments[i].date != NULL && strcmp(appointments[i].date, date) == 0) {
      printf("Date: %s, Time: %s, Patient Name: %s\n", appointments[i].date, appointments[i].time, appointments[i].patientName);
      appointmentCount++;
    }
  }

  if (appointmentCount == 0) {
    printf("No appointments found for this date.\n");
  }
}

// Main function to show menu and handle user input
int main() {
  int option;

  do {
    // Show menu
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
    printf("Enter option number: ");
    scanf("%d", &option);

    // Handle user input
    switch (option) {
      case 1:
        addAppointment();
        break;

      case 2:
        viewAppointments();
        break;

      case 3:
        printf("Exiting...\n");
        return 0;

      default:
        printf("Invalid option.\n");
        break;
    }
  } while (1);
}