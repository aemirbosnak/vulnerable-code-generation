//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

// Appointment struct
typedef struct appointment {
  char *name;
  time_t start, end;
} appointment;

// Global array of appointments
appointment appointments[MAX_APPOINTMENTS];

// Function to add an appointment
void add_appointment(char *name, time_t start, time_t end) {
  // Find the first available slot
  int i;
  for (i = 0; i < MAX_APPOINTMENTS; i++) {
    if (appointments[i].name == NULL) {
      // Found an available slot
      break;
    }
  }

  // If no available slots, error out
  if (i == MAX_APPOINTMENTS) {
    printf("Error: No more appointments can be added.\n");
    return;
  }

  // Add the appointment to the array
  appointments[i].name = strdup(name);
  appointments[i].start = start;
  appointments[i].end = end;
}

// Function to remove an appointment
void remove_appointment(char *name) {
  // Find the appointment with the given name
  int i;
  for (i = 0; i < MAX_APPOINTMENTS; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      // Found the appointment
      break;
    }
  }

  // If the appointment was not found, error out
  if (i == MAX_APPOINTMENTS) {
    printf("Error: No appointment with the given name was found.\n");
    return;
  }

  // Remove the appointment from the array
  free(appointments[i].name);
  appointments[i].name = NULL;
  appointments[i].start = 0;
  appointments[i].end = 0;
}

// Function to print the appointments
void print_appointments() {
  // Print the header
  printf("Appointments:\n");

  // Print each appointment
  int i;
  for (i = 0; i < MAX_APPOINTMENTS; i++) {
    if (appointments[i].name != NULL) {
      printf("  * %s (from %s to %s)\n", appointments[i].name, ctime(&appointments[i].start), ctime(&appointments[i].end));
    }
  }
}

// Main function
int main() {
  // Add some appointments
  add_appointment("John Doe", time(NULL), time(NULL) + 3600);
  add_appointment("Jane Doe", time(NULL) + 3600, time(NULL) + 7200);
  add_appointment("Bill Smith", time(NULL) + 7200, time(NULL) + 10800);

  // Print the appointments
  print_appointments();

  // Remove an appointment
  remove_appointment("Jane Doe");

  // Print the appointments again
  print_appointments();

  return 0;
}