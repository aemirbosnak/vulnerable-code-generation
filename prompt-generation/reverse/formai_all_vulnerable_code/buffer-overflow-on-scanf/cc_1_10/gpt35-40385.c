//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Structure
struct appointment {
  char name[50];
  char date[20];
  char time[20];
} appointments[100];

int num_appointments = 0;

int main() {
  char input;

  printf("Welcome to the Verona Appointment Scheduler! \n");
  printf("Please choose an option:\n");

  while (input != 'q') {
    printf("\n");
    printf("a - Add an appointment\n");
    printf("d - Display all appointments\n");
    printf("q - Quit Scheduler\n");
    printf("Enter your choice: ");

    scanf(" %c", &input); // Read user input

    if (input == 'a') {
      printf("\n");
      printf("Enter name: ");
      scanf("%s", &appointments[num_appointments].name);

      printf("Enter date (mm/dd/yyyy): ");
      scanf("%s", &appointments[num_appointments].date);

      printf("Enter time (hh:mm AM/PM): ");
      scanf("%s", &appointments[num_appointments].time);

      printf("\n");
      printf("%s, your appointment on %s at %s has been added. \n", appointments[num_appointments].name,
             appointments[num_appointments].date, appointments[num_appointments].time);

      num_appointments++;
    } else if (input == 'd') {
      printf("\n");
      printf("All Appointments: \n");
      printf("Name\t     Date\t     Time\n");

      for (int i = 0; i < num_appointments; i++) {
        printf("%s\t     %s\t     %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
      }
    } else if (input == 'q') {
      printf("\n");
      printf("Farewell! May your appointments go better than Romeo and Juliet's love story. \n");
    } else {
      printf("\n");
      printf("Invalid input, try again. \n");
    }
  }

  return 0;
}