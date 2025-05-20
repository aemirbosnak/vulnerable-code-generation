//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a unique appointment ID
int generateID() {
  srand(time(NULL));
  int id = rand() % 10000 + 1;
  return id;
}

int main() {
  printf("Welcome to the Dentist Appointment Scheduler!\n\n");

  // Array to hold appointment times
  char times[8][20] = {"9:00 AM", "10:00 AM", "11:00 AM", "12:00 PM", "1:00 PM", "2:00 PM", "3:00 PM", "4:00 PM"};

  // Appointment structure
  struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[20];
  };

  // Array to hold all appointments
  struct Appointment appointments[50];
  int numAppointments = 0;

  // Menu
  int choice;
  do {
    printf("MENU:\n");
    printf("1. Schedule a new appointment\n");
    printf("2. View all appointments\n");
    printf("3. Remove an appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
      case 1:
        // Schedule a new appointment
        printf("Scheduling a new appointment...\n");
        struct Appointment newAppointment;
        newAppointment.id = generateID();
        printf("Enter your name: ");
        scanf("%s", newAppointment.name);
        printf("Enter the date (MM/DD/YYYY): ");
        scanf("%s", newAppointment.date);

        // Select an available time slot
        int timeSlot;
        do {
          printf("Available time slots:\n");
          for (int i = 0; i < 8; i++) {
            printf("%d. %s\n", i+1, times[i]);
          }
          printf("Enter the time slot number (1-8): ");
          scanf("%d", &timeSlot);
        } while (timeSlot < 1 || timeSlot > 8);

        strcpy(newAppointment.time, times[timeSlot - 1]);

        // Add appointment to appointments array
        appointments[numAppointments] = newAppointment;
        numAppointments++;
        printf("\nAppointment scheduled successfully!\n\n");
        break;
      case 2:
        // View all appointments
        printf("Viewing all appointments...\n\n");
        if (numAppointments == 0) {
          printf("No appointments scheduled.\n\n");
        } else {
          for (int i = 0; i < numAppointments; i++) {
            printf("Appointment ID: %d\n", appointments[i].id);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("-------------------\n");
          }
        }
        break;
      case 3:
        // Remove an appointment
        printf("Removing an appointment...\n\n");
        int removeID;
        printf("Enter the appointment ID: ");
        scanf("%d", &removeID);
        int removeIndex = -1;
        for (int i = 0; i < numAppointments; i++) {
          if (appointments[i].id == removeID) {
            removeIndex = i;
            break;
          }
        }
        if (removeIndex == -1) {
          printf("Invalid appointment ID.\n\n");
        } else {
          for (int i = removeIndex; i < numAppointments - 1; i++) {
            appointments[i] = appointments[i+1];
          }
          numAppointments--;
          printf("Appointment removed successfully!\n\n");
        }
        break;
      case 4:
        // Exit the program
        printf("Exiting program. Goodbye!\n\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n\n");
    }
  } while (choice != 4);

  return 0;
}