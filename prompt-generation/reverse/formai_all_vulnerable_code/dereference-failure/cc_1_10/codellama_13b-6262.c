//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
/*
 * Appointment Scheduler Example Program
 *
 * This program is an example of a simple appointment scheduler that allows users to schedule
 * appointments for a given day. The program uses a data structure to store the appointments
 * and provides a simple command-line interface for the user to interact with the program.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store appointment information
typedef struct {
  char* name;
  char* date;
  char* time;
  char* duration;
} Appointment;

// Function to create a new appointment
Appointment* createAppointment(char* name, char* date, char* time, char* duration) {
  Appointment* appointment = malloc(sizeof(Appointment));
  appointment->name = strdup(name);
  appointment->date = strdup(date);
  appointment->time = strdup(time);
  appointment->duration = strdup(duration);
  return appointment;
}

// Function to print an appointment
void printAppointment(Appointment* appointment) {
  printf("Name: %s\n", appointment->name);
  printf("Date: %s\n", appointment->date);
  printf("Time: %s\n", appointment->time);
  printf("Duration: %s\n", appointment->duration);
}

// Function to add an appointment to the list
void addAppointment(Appointment* appointment, Appointment** appointments, int* numAppointments) {
  *appointments = realloc(*appointments, (*numAppointments + 1) * sizeof(Appointment));
  (*appointments)[*numAppointments] = *appointment;
  *numAppointments += 1;
}

// Function to remove an appointment from the list
void removeAppointment(int index, Appointment** appointments, int* numAppointments) {
  if (index >= 0 && index < *numAppointments) {
    free((*appointments)[index].name);
    free((*appointments)[index].date);
    free((*appointments)[index].time);
    free((*appointments)[index].duration);
    memmove(*appointments + index, *appointments + index + 1, (*numAppointments - index - 1) * sizeof(Appointment));
    *numAppointments -= 1;
  }
}

// Function to display the appointments
void displayAppointments(Appointment* appointments, int numAppointments) {
  for (int i = 0; i < numAppointments; i++) {
    printAppointment(&appointments[i]);
  }
}

int main() {
  Appointment* appointments = NULL;
  int numAppointments = 0;

  // Add appointments
  addAppointment(createAppointment("John", "10/10/2022", "10:00 AM", "1 hour"), &appointments, &numAppointments);
  addAppointment(createAppointment("Jane", "10/10/2022", "11:00 AM", "2 hours"), &appointments, &numAppointments);
  addAppointment(createAppointment("Bob", "10/10/2022", "12:00 PM", "3 hours"), &appointments, &numAppointments);

  // Remove an appointment
  removeAppointment(0, &appointments, &numAppointments);

  // Display appointments
  displayAppointments(appointments, numAppointments);

  // Free memory
  for (int i = 0; i < numAppointments; i++) {
    free(appointments[i].name);
    free(appointments[i].date);
    free(appointments[i].time);
    free(appointments[i].duration);
  }
  free(appointments);

  return 0;
}