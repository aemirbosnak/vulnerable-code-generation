//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: creative
// Welcome to the Appointment Scheduler!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
typedef struct {
  char name[50];
  char date[20];
  char time[20];
  char location[50];
} Appointment;

// Define the array of appointments
static Appointment appointments[MAX_APPOINTMENTS];

// Define the current number of appointments
static int num_appointments = 0;

// Prompt the user for input
static void get_input(Appointment *appointment);

// Print the appointment
static void print_appointment(Appointment *appointment);

// Initialize the appointment scheduler
void init_scheduler() {
  // Initialize the array of appointments
  memset(appointments, 0, sizeof(appointments));

  // Initialize the current number of appointments
  num_appointments = 0;
}

// Add an appointment
void add_appointment() {
  // Get the input from the user
  Appointment appointment;
  get_input(&appointment);

  // Add the appointment to the array
  appointments[num_appointments++] = appointment;
}

// Print the list of appointments
void print_appointments() {
  // Print the header
  printf("Appointments:\n");

  // Loop through the array of appointments
  for (int i = 0; i < num_appointments; i++) {
    // Print the appointment
    print_appointment(&appointments[i]);
  }
}

// Get the input from the user
static void get_input(Appointment *appointment) {
  // Get the name of the appointment
  printf("Name: ");
  scanf("%s", appointment->name);

  // Get the date of the appointment
  printf("Date: ");
  scanf("%s", appointment->date);

  // Get the time of the appointment
  printf("Time: ");
  scanf("%s", appointment->time);

  // Get the location of the appointment
  printf("Location: ");
  scanf(" %[^\n]%*c", appointment->location); 
}

// Print the appointment
static void print_appointment(Appointment *appointment) {
  // Print the name of the appointment
  printf("Name: %s\n", appointment->name);

  // Print the date of the appointment
  printf("Date: %s\n", appointment->date);

  // Print the time of the appointment
  printf("Time: %s\n", appointment->time);

  // Print the location of the appointment
  printf("Location: %s\n", appointment->location);

  // Print a newline
  printf("\n");
}

// Main function
int main() {
  // Initialize the appointment scheduler
  init_scheduler();

  // Add some appointments
  add_appointment();
  add_appointment();
  add_appointment();

  // Print the list of appointments
  print_appointments();

  return 0;
}