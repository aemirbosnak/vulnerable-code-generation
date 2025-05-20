//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
  char name[50];
  char date[50];
  char time[50];
  char reason[50];
};

int main()
{
  struct Appointment appointments[MAX_APPOINTMENTS];
  int numAppointments = 0;

  // Create a menu of options
  printf("Welcome to the Love Connection Appointment Scheduler!\n");
  printf("Please select an option:\n");
  printf("1. Make an Appointment\n");
  printf("2. View Appointments\n");
  printf("3. Cancel an Appointment\n");
  printf("4. Exit\n");

  // Get the user's input
  int choice = getchar();

  // Process the user's input
  switch (choice)
  {
    case 1:
      // Get the user's name, date, time, and reason
      printf("Enter your name: ");
      scanf("%s", appointments[numAppointments].name);

      printf("Enter the date of your appointment: ");
      scanf("%s", appointments[numAppointments].date);

      printf("Enter the time of your appointment: ");
      scanf("%s", appointments[numAppointments].time);

      printf("Enter the reason for your appointment: ");
      scanf("%s", appointments[numAppointments].reason);

      // Increment the number of appointments
      numAppointments++;
      break;

    case 2:
      // Print the appointments
      for (int i = 0; i < numAppointments; i++)
      {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Reason: %s\n", appointments[i].reason);
        printf("\n");
      }
      break;

    case 3:
      // Get the user's name
      printf("Enter your name: ");
      scanf("%s", appointments[numAppointments - 1].name);

      // Cancel the appointment
      numAppointments--;
      break;

    case 4:
      // Exit the program
      exit(0);
  }

  // Print a goodbye message
  printf("Thank you for using the Love Connection Appointment Scheduler!\n");

  return 0;
}