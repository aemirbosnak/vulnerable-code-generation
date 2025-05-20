//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
struct Appointment {
  char name[50];
  char date[10];
  char time[10];
  char duration[5];
};

// Function to add a new appointment
void addAppointment(struct Appointment *appointments, int *numAppointments) {
  // Prompt the user for the appointment details
  printf("Enter the appointment name: ");
  scanf("%s", appointments[*numAppointments].name);
  printf("Enter the appointment date (MM/DD/YYYY): ");
  scanf("%s", appointments[*numAppointments].date);
  printf("Enter the appointment time (HH:MM): ");
  scanf("%s", appointments[*numAppointments].time);
  printf("Enter the appointment duration (in hours): ");
  scanf("%s", appointments[*numAppointments].duration);

  // Increment the number of appointments
  (*numAppointments)++;
}

// Function to display all appointments
void displayAppointments(struct Appointment *appointments, int numAppointments) {
  // Loop through all appointments and display them
  for (int i = 0; i < numAppointments; i++) {
    printf("Appointment %d:\n", i + 1);
    printf("Name: %s\n", appointments[i].name);
    printf("Date: %s\n", appointments[i].date);
    printf("Time: %s\n", appointments[i].time);
    printf("Duration: %s\n", appointments[i].duration);
    printf("\n");
  }
}

// Function to find an appointment by name
int findAppointment(struct Appointment *appointments, int numAppointments, char *name) {
  // Loop through all appointments and find the one with the matching name
  for (int i = 0; i < numAppointments; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Function to remove an appointment by name
void removeAppointment(struct Appointment *appointments, int *numAppointments, char *name) {
  // Find the appointment to remove
  int index = findAppointment(appointments, *numAppointments, name);
  if (index == -1) {
    printf("Appointment not found.\n");
    return;
  }

  // Remove the appointment
  for (int i = index; i < *numAppointments - 1; i++) {
    appointments[i] = appointments[i + 1];
  }
  (*numAppointments)--;
}

int main() {
  // Initialize the appointments array and number of appointments
  struct Appointment appointments[100];
  int numAppointments = 0;

  // Add some appointments
  addAppointment(appointments, &numAppointments);
  addAppointment(appointments, &numAppointments);
  addAppointment(appointments, &numAppointments);

  // Display all appointments
  displayAppointments(appointments, numAppointments);

  // Find an appointment by name
  char name[50];
  printf("Enter the appointment name to find: ");
  scanf("%s", name);
  int index = findAppointment(appointments, numAppointments, name);
  if (index == -1) {
    printf("Appointment not found.\n");
  } else {
    printf("Appointment found at index %d.\n", index);
  }

  // Remove an appointment by name
  char name2[50];
  printf("Enter the appointment name to remove: ");
  scanf("%s", name2);
  removeAppointment(appointments, &numAppointments, name2);

  // Display all appointments again
  displayAppointments(appointments, numAppointments);

  return 0;
}