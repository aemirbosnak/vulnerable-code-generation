//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
  char *name;
  char *description;
  time_t start_time;
  time_t end_time;
} appointment_t;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
  appointment_t *appointments[MAX_APPOINTMENTS];
  int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler
appointment_scheduler_t *create_appointment_scheduler() {
  appointment_scheduler_t *scheduler = malloc(sizeof(appointment_scheduler_t));
  scheduler->num_appointments = 0;
  return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(appointment_scheduler_t *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->name);
    free(scheduler->appointments[i]->description);
    free(scheduler->appointments[i]);
  }
  free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler_t *scheduler, appointment_t *appointment) {
  scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler_t *scheduler, int index) {
  for (int i = index; i < scheduler->num_appointments - 1; i++) {
    scheduler->appointments[i] = scheduler->appointments[i + 1];
  }
  scheduler->num_appointments--;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler_t *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    printf("%s: %s (%s - %s)\n",
      scheduler->appointments[i]->name,
      scheduler->appointments[i]->description,
      ctime(&scheduler->appointments[i]->start_time),
      ctime(&scheduler->appointments[i]->end_time));
  }
}

// Main function
int main() {
  // Create an appointment scheduler
  appointment_scheduler_t *scheduler = create_appointment_scheduler();

  // Add some appointments to the scheduler
  appointment_t *appointment1 = malloc(sizeof(appointment_t));
  appointment1->name = "Appointment 1";
  appointment1->description = "This is the first appointment";
  appointment1->start_time = time(NULL) + 3600; // 1 hour from now
  appointment1->end_time = time(NULL) + 7200; // 2 hours from now
  add_appointment(scheduler, appointment1);

  appointment_t *appointment2 = malloc(sizeof(appointment_t));
  appointment2->name = "Appointment 2";
  appointment2->description = "This is the second appointment";
  appointment2->start_time = time(NULL) + 10800; // 3 hours from now
  appointment2->end_time = time(NULL) + 14400; // 4 hours from now
  add_appointment(scheduler, appointment2);

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Remove the first appointment from the scheduler
  remove_appointment(scheduler, 0);

  // Print the appointments in the scheduler
  print_appointments(scheduler);

  // Destroy the appointment scheduler
  destroy_appointment_scheduler(scheduler);

  return 0;
}