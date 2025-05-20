//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
  char name[50];
  char date[20];
  char time[20];
} appointment;

// Initialize the array of appointments
appointment appointments[MAX_APPOINTMENTS];

// The main function
int main() {
  // Declare the variables
  int choice, i, count = 0;
  char input[50];

  // Display the menu
  do {
    printf("\nAppointment Scheduler\n");
    printf("--------------------\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice) {
      case 1:
        // Add an appointment
        if (count < MAX_APPOINTMENTS) {
          printf("Enter the name of the person: ");
          scanf("%s", appointments[count].name);
          printf("Enter the date of the appointment (dd/mm/yyyy): ");
          scanf("%s", appointments[count].date);
          printf("Enter the time of the appointment (hh:mm): ");
          scanf("%s", appointments[count].time);
          count++;
          printf("Appointment added successfully.\n");
        } else {
          printf("Sorry, the appointment list is full.\n");
        }
        break;
      case 2:
        // View appointments
        if (count == 0) {
          printf("Sorry, there are no appointments to view.\n");
        } else {
          printf("Appointments:\n");
          for (i = 0; i < count; i++) {
            printf("%d. %s - %s - %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
          }
        }
        break;
      case 3:
        // Delete an appointment
        printf("Enter the number of the appointment you want to delete: ");
        scanf("%d", &i);
        i--;
        if (i >= 0 && i < count) {
          for (i; i < count; i++) {
            appointments[i] = appointments[i + 1];
          }
          count--;
          printf("Appointment deleted successfully.\n");
        } else {
          printf("Sorry, the appointment number is invalid.\n");
        }
        break;
      case 4:
        // Exit the program
        printf("Exiting the program.\n");
        break;
      default:
        // Invalid choice
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }
  } while (choice != 4);

  return 0;
}