//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  time_t start_time;
  time_t end_time;
} appointment_t;

int main() {
  // Array of appointments
  appointment_t appointments[100];

  // Index of the next available appointment
  int next_appointment = 0;

  // Main loop
  while (1) {
    // Display the main menu
    printf("Welcome to the Appointment Scheduler!\n");
    printf("1. Schedule an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Quit\n");

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Switch on the user's choice
    switch (choice) {
      case 1:
        // Schedule an appointment
        printf("Enter your name: ");
        char *name = malloc(100);
        scanf("%s", name);

        printf("Enter your email: ");
        char *email = malloc(100);
        scanf("%s", email);

        printf("Enter your phone number: ");
        char *phone = malloc(100);
        scanf("%s", phone);

        printf("Enter the start time of your appointment (in the format YYYY-MM-DD HH:MM): ");
        char *start_time_str = malloc(100);
        scanf("%s", start_time_str);

        struct tm start_time;
        strptime(start_time_str, "%Y-%m-%d %H:%M", &start_time);

        printf("Enter the end time of your appointment (in the format YYYY-MM-DD HH:MM): ");
        char *end_time_str = malloc(100);
        scanf("%s", end_time_str);

        struct tm end_time;
        strptime(end_time_str, "%Y-%m-%d %H:%M", &end_time);

        // Create a new appointment
        appointment_t appointment;
        appointment.name = name;
        appointment.email = email;
        appointment.phone = phone;
        appointment.start_time = mktime(&start_time);
        appointment.end_time = mktime(&end_time);

        // Add the new appointment to the array
        appointments[next_appointment] = appointment;
        next_appointment++;

        printf("Your appointment has been scheduled.\n");

        break;
      case 2:
        // View all appointments
        printf("All appointments:\n");
        for (int i = 0; i < next_appointment; i++) {
          appointment_t appointment = appointments[i];
          printf("Appointment %d:\n", i + 1);
          printf("Name: %s\n", appointment.name);
          printf("Email: %s\n", appointment.email);
          printf("Phone: %s\n", appointment.phone);
          printf("Start time: %s\n", asctime(gmtime(&appointment.start_time)));
          printf("End time: %s\n", asctime(gmtime(&appointment.end_time)));
        }

        break;
      case 3:
        // Quit
        printf("Goodbye!");
        return 0;
    }
  }

  return 0;
}