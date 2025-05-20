//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
  char *name;
  char *description;
  time_t start_time;
  time_t end_time;
} Appointment;

typedef struct AppointmentScheduler {
  Appointment *appointments[MAX_APPOINTMENTS];
  int num_appointments;
} AppointmentScheduler;

AppointmentScheduler *create_appointment_scheduler() {
  AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
  scheduler->num_appointments = 0;
  return scheduler;
}

void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    free(scheduler->appointments[i]->name);
    free(scheduler->appointments[i]->description);
    free(scheduler->appointments[i]);
  }
  free(scheduler);
}

Appointment *create_appointment(char *name, char *description, time_t start_time,
                                 time_t end_time) {
  Appointment *appointment = malloc(sizeof(Appointment));
  appointment->name = strdup(name);
  appointment->description = strdup(description);
  appointment->start_time = start_time;
  appointment->end_time = end_time;
  return appointment;
}

void destroy_appointment(Appointment *appointment) {
  free(appointment->name);
  free(appointment->description);
  free(appointment);
}

bool schedule_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
  if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
    return false;
  }

  for (int i = 0; i < scheduler->num_appointments; i++) {
    if (appointment->start_time < scheduler->appointments[i]->end_time &&
        appointment->end_time > scheduler->appointments[i]->start_time) {
      return false;
    }
  }

  scheduler->appointments[scheduler->num_appointments++] = appointment;
  return true;
}

void print_appointment(Appointment *appointment) {
  printf("%s: %s\n", appointment->name, appointment->description);
  printf("Start time: %s\n", ctime(&appointment->start_time));
  printf("End time: %s\n\n", ctime(&appointment->end_time));
}

void print_appointment_scheduler(AppointmentScheduler *scheduler) {
  for (int i = 0; i < scheduler->num_appointments; i++) {
    print_appointment(scheduler->appointments[i]);
  }
}

int main() {
  AppointmentScheduler *scheduler = create_appointment_scheduler();
  Appointment *appointment1 =
      create_appointment("Doctor's appointment", "Annual checkup", time(NULL),
                           time(NULL) + 3600);
  Appointment *appointment2 =
      create_appointment("Meeting with boss", "Discuss project status",
                           time(NULL) + 3600, time(NULL) + 7200);
  Appointment *appointment3 = create_appointment(
      "Lunch with friend", "Catch up on life", time(NULL) + 7200, time(NULL) + 10800);
  schedule_appointment(scheduler, appointment1);
  schedule_appointment(scheduler, appointment2);
  schedule_appointment(scheduler, appointment3);

  print_appointment_scheduler(scheduler);
  destroy_appointment(appointment1);
  destroy_appointment(appointment2);
  destroy_appointment(appointment3);
  destroy_appointment_scheduler(scheduler);
  return 0;
}