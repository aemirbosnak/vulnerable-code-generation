//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of appointments in the schedule
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
typedef struct appointment {
  char name[50];
  char description[100];
  time_t start_time;
  time_t end_time;
} appointment_t;

// Define the structure of the appointment schedule
typedef struct appointment_schedule {
  appointment_t appointments[MAX_APPOINTMENTS];
  int num_appointments;
} appointment_schedule_t;

// Create a new appointment schedule
appointment_schedule_t* create_appointment_schedule() {
  appointment_schedule_t* schedule = malloc(sizeof(appointment_schedule_t));
  if (schedule == NULL) {
    return NULL;
  }
  schedule->num_appointments = 0;
  return schedule;
}

// Add an appointment to the schedule
int add_appointment(appointment_schedule_t* schedule, appointment_t* appointment) {
  if (schedule->num_appointments >= MAX_APPOINTMENTS) {
    return -1;
  }
  schedule->appointments[schedule->num_appointments++] = *appointment;
  return 0;
}

// Print the schedule
void print_schedule(appointment_schedule_t* schedule) {
  for (int i = 0; i < schedule->num_appointments; i++) {
    appointment_t* appointment = &schedule->appointments[i];
    printf("%s - %s\n", appointment->name, appointment->description);
    printf("%s - %s\n", ctime(&appointment->start_time), ctime(&appointment->end_time));
    printf("\n");
  }
}

// Free the memory allocated for the schedule
void free_schedule(appointment_schedule_t* schedule) {
  free(schedule);
}

// Main function
int main() {
  // Create a new appointment schedule
  appointment_schedule_t* schedule = create_appointment_schedule();

  // Add some appointments to the schedule
  appointment_t appointment1 = {
    "John Doe",
    "Meeting with the boss",
    time(NULL) + 3600, // Start time is 1 hour from now
    time(NULL) + 7200  // End time is 2 hours from now
  };
  add_appointment(schedule, &appointment1);

  appointment_t appointment2 = {
    "Jane Doe",
    "Doctor's appointment",
    time(NULL) + 10800, // Start time is 3 hours from now
    time(NULL) + 14400  // End time is 4 hours from now
  };
  add_appointment(schedule, &appointment2);

  // Print the schedule
  print_schedule(schedule);

  // Free the memory allocated for the schedule
  free_schedule(schedule);

  return 0;
}