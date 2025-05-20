//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_APPOINTMENTS 100

typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  time_t start_time;
  time_t end_time;
} Appointment;

void print_appointment(const Appointment *appointment) {
  printf("%s: %s - %s\n", appointment->name, ctime(&appointment->start_time), ctime(&appointment->end_time));
}

void print_appointments(const Appointment *appointments, size_t count) {
  for (size_t i = 0; i < count; i++) {
    print_appointment(&appointments[i]);
  }
}

void add_appointment(Appointment *appointments, size_t *count, const char *name, time_t start_time, time_t end_time) {
  if (*count == MAX_APPOINTMENTS) {
    printf("Error: No more appointments can be added.\n");
    return;
  }

  strcpy(appointments[*count].name, name);
  appointments[*count].start_time = start_time;
  appointments[*count].end_time = end_time;
  (*count)++;
}

void remove_appointment(Appointment *appointments, size_t *count, const char *name) {
  for (size_t i = 0; i < *count; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      for (size_t j = i + 1; j < *count; j++) {
        appointments[j - 1] = appointments[j];
      }
      (*count)--;
      break;
    }
  }
}

bool is_overlapping(const Appointment *appointment1, const Appointment *appointment2) {
  return (appointment1->start_time <= appointment2->start_time && appointment1->end_time >= appointment2->start_time) ||
         (appointment2->start_time <= appointment1->start_time && appointment2->end_time >= appointment1->start_time);
}

void find_overlapping_appointments(const Appointment *appointments, size_t count, Appointment *overlapping_appointments, size_t *overlapping_count) {
  *overlapping_count = 0;

  for (size_t i = 0; i < count; i++) {
    for (size_t j = i + 1; j < count; j++) {
      if (is_overlapping(&appointments[i], &appointments[j])) {
        overlapping_appointments[*overlapping_count] = appointments[i];
        (*overlapping_count)++;
        overlapping_appointments[*overlapping_count] = appointments[j];
        (*overlapping_count)++;
      }
    }
  }
}

int main() {
  Appointment appointments[MAX_APPOINTMENTS];
  size_t count = 0;

  // Add some appointments to the list.
  add_appointment(appointments, &count, "John Doe", time(NULL), time(NULL) + 3600);
  add_appointment(appointments, &count, "Jane Doe", time(NULL) + 1800, time(NULL) + 2700);
  add_appointment(appointments, &count, "John Smith", time(NULL) + 3600, time(NULL) + 4200);

  // Print the appointments.
  printf("Appointments:\n");
  print_appointments(appointments, count);

  // Find the overlapping appointments.
  Appointment overlapping_appointments[MAX_APPOINTMENTS];
  size_t overlapping_count = 0;
  find_overlapping_appointments(appointments, count, overlapping_appointments, &overlapping_count);

  // Print the overlapping appointments.
  printf("\nOverlapping appointments:\n");
  print_appointments(overlapping_appointments, overlapping_count);

  return 0;
}