//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
/*
 * C Appointment Scheduler Example Program
 *
 * This program schedules appointments for a doctor's office.
 * It allows users to input the start and end times for each appointment,
 * and it will automatically assign a schedule that minimizes
 * conflicts between appointments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TIME 24

// Structure to represent an appointment
typedef struct {
  int start_time;
  int end_time;
} Appointment;

// Function to find the next available time slot
int find_next_time_slot(int current_time, int duration, Appointment *appointments, int num_appointments) {
  int i, j;
  for (i = current_time; i < MAX_TIME; i++) {
    for (j = 0; j < num_appointments; j++) {
      if (i >= appointments[j].start_time && i < appointments[j].end_time) {
        break;
      }
    }
    if (j == num_appointments) {
      return i;
    }
  }
  return -1;
}

// Function to schedule appointments
void schedule_appointments(Appointment *appointments, int num_appointments) {
  int i, j, current_time, next_time_slot;
  for (i = 0; i < num_appointments; i++) {
    current_time = appointments[i].start_time;
    next_time_slot = find_next_time_slot(current_time, appointments[i].end_time - current_time, appointments, i);
    if (next_time_slot == -1) {
      printf("Cannot schedule appointment %d\n", i);
      return;
    }
    appointments[i].start_time = next_time_slot;
    appointments[i].end_time = next_time_slot + (appointments[i].end_time - appointments[i].start_time);
  }
}

int main() {
  int num_appointments, i;
  Appointment appointments[MAX_APPOINTMENTS];

  // Input the number of appointments
  printf("Enter the number of appointments: ");
  scanf("%d", &num_appointments);

  // Input the start and end times for each appointment
  for (i = 0; i < num_appointments; i++) {
    printf("Enter the start and end times for appointment %d: ", i + 1);
    scanf("%d %d", &appointments[i].start_time, &appointments[i].end_time);
  }

  // Schedule the appointments
  schedule_appointments(appointments, num_appointments);

  // Print the scheduled appointments
  for (i = 0; i < num_appointments; i++) {
    printf("Appointment %d: %d - %d\n", i + 1, appointments[i].start_time, appointments[i].end_time);
  }

  return 0;
}