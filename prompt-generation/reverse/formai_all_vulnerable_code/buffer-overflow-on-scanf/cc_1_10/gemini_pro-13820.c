//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent an appointment
typedef struct appointment {
  char *description;
  int start_time;
  int end_time;
} appointment;

// Array of appointments
appointment appointments[100];

// Number of appointments
int num_appointments = 0;

// Function to add an appointment
void add_appointment(char *description, int start_time, int end_time) {
  // Check if the array is full
  if (num_appointments == 100) {
    printf("Error: The array is full.\n");
    return;
  }

  // Create a new appointment
  appointment new_appointment;
  new_appointment.description = strdup(description);  //c89
  new_appointment.start_time = start_time;
  new_appointment.end_time = end_time;

  // Add the new appointment to the array
  appointments[num_appointments] = new_appointment;
  num_appointments++;
}

// Function to print the appointments
void print_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    printf("%s (%d-%d)\n", appointments[i].description, appointments[i].start_time,
           appointments[i].end_time);
  }
}

// Function to find a free time slot
int find_free_time_slot(int start_time, int end_time) {
  // Iterate over the appointments
  for (int i = 0; i < num_appointments; i++) {
    // Check if the start time of the new appointment is before the end time of the existing appointment
    if (start_time < appointments[i].end_time) {
      // Check if the end time of the new appointment is after the start time of the existing appointment
      if (end_time > appointments[i].start_time) {
        // The time slot is not free
        return 0;
      }
    }
  }

  // The time slot is free
  return 1;
}

// Function to get user input
void get_user_input(char *description, int *start_time, int *end_time) {
  printf("Enter the description of the appointment: ");
  scanf("%s", description);

  printf("Enter the start time of the appointment (in hours): ");
  scanf("%d", start_time);

  printf("Enter the end time of the appointment (in hours): ");
  scanf("%d", end_time);
}

// Main function
int main() {
  // Get user input
  char description[100];
  int start_time;
  int end_time;
  get_user_input(description, &start_time, &end_time);

  // Check if the time slot is free
  int is_free = find_free_time_slot(start_time, end_time);

  // If the time slot is free, add the appointment
  if (is_free) {
    add_appointment(description, start_time, end_time);
    printf("Appointment added successfully.\n");
  } else {
    printf("Error: The time slot is not free.\n");
  }

  // Print the appointments
  print_appointments();

  return 0;
}