//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 100

// Appointment structure
typedef struct {
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESCRIPTION_LENGTH];
  time_t start_time;
  time_t end_time;
} Appointment;

// Function to get a time from the user
time_t get_time(char *prompt) {
  time_t time;
  struct tm tm;

  printf("%s", prompt);
  scanf("%d-%d-%d %d:%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min);

  time = mktime(&tm);
  return time;
}

// Function to create an appointment
Appointment create_appointment() {
  Appointment appointment;

  printf("Enter the appointment name: ");
  scanf("%s", appointment.name);

  printf("Enter the appointment description: ");
  scanf("%s", appointment.description);

  appointment.start_time = get_time("Enter the start time (YYYY-MM-DD HH:MM): ");
  appointment.end_time = get_time("Enter the end time (YYYY-MM-DD HH:MM): ");

  return appointment;
}

// Function to print an appointment
void print_appointment(Appointment appointment) {
  printf("Name: %s\n", appointment.name);
  printf("Description: %s\n", appointment.description);
  printf("Start time: %s", ctime(&appointment.start_time));
  printf("End time: %s", ctime(&appointment.end_time));
}

// Function to compare two appointments
int compare_appointments(const void *a, const void *b) {
  Appointment *appointment1 = (Appointment *)a;
  Appointment *appointment2 = (Appointment *)b;

  return appointment1->start_time - appointment2->start_time;
}

// Function to schedule an appointment
void schedule_appointment(Appointment *appointments, int *num_appointments) {
  if (*num_appointments >= MAX_APPOINTMENTS) {
    printf("Error: No more appointments can be scheduled.\n");
    return;
  }

  appointments[*num_appointments] = create_appointment();
  (*num_appointments)++;

  qsort(appointments, *num_appointments, sizeof(Appointment), compare_appointments);
}

// Function to print all appointments
void print_all_appointments(Appointment *appointments, int num_appointments) {
  for (int i = 0; i < num_appointments; i++) {
    print_appointment(appointments[i]);
    printf("\n");
  }
}

// Function to find an appointment by name
int find_appointment_by_name(Appointment *appointments, int num_appointments, char *name) {
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      return i;
    }
  }

  return -1;
}

// Function to cancel an appointment
void cancel_appointment(Appointment *appointments, int *num_appointments, char *name) {
  int index = find_appointment_by_name(appointments, *num_appointments, name);

  if (index == -1) {
    printf("Error: No appointment found with that name.\n");
    return;
  }

  for (int i = index; i < *num_appointments - 1; i++) {
    appointments[i] = appointments[i + 1];
  }

  (*num_appointments)--;
}

// Main function
int main() {
  // Initialize the array of appointments
  Appointment appointments[MAX_APPOINTMENTS];
  int num_appointments = 0;

  // Create a new appointment
  schedule_appointment(appointments, &num_appointments);

  // Print all appointments
  print_all_appointments(appointments, num_appointments);

  // Find an appointment by name
  char name[MAX_NAME_LENGTH];
  printf("Enter the name of the appointment you want to find: ");
  scanf("%s", name);
  int index = find_appointment_by_name(appointments, num_appointments, name);

  if (index == -1) {
    printf("Error: No appointment found with that name.\n");
  } else {
    printf("Found appointment:\n");
    print_appointment(appointments[index]);
    printf("\n");
  }

  // Cancel an appointment
  printf("Enter the name of the appointment you want to cancel: ");
  scanf("%s", name);
  cancel_appointment(appointments, &num_appointments, name);

  // Print all appointments
  print_all_appointments(appointments, num_appointments);

  return 0;
}