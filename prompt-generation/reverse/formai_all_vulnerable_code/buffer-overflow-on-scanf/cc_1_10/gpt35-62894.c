//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>

/* Function declarations */
void display_menu();
void book_appointment();
void display_appointments();
void cancel_appointment();

int main() {
  char choice;

  /* Display the menu and get user input */
  do {
    display_menu();
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'B':
      case 'b':
        book_appointment();
        break;
      case 'D':
      case 'd':
        display_appointments();
        break;
      case 'C':
      case 'c':
        cancel_appointment();
        break;
      case 'Q':
      case 'q':
        printf("Exiting program...");
        break;
      default:
        printf("Invalid choice, please try again.\n\n");
        break;
    }

  } while (choice != 'Q' && choice != 'q');

  return 0;
}

/* Function to display the menu */
void display_menu() {
  printf("======== Appointment Scheduler ========\n");
  printf("B - Book an appointment\n");
  printf("D - Display appointments\n");
  printf("C - Cancel an appointment\n");
  printf("Q - Quit program\n");
  printf("=======================================\n\n");
}

/* Function to book an appointment */
void book_appointment() {
  printf("\n------- Booking an appointment -------\n");
  printf("Enter your name: ");
  // code for taking user input for name and other details
  // code for checking availability of slots and booking the appointment
  printf("Appointment booked successfully.\n\n");
}

/* Function to display existing appointments */
void display_appointments() {
  printf("\n------- Displaying appointments -------\n");
  // code for displaying the existing appointments with all details
  printf("\n");
}

/* Function to cancel an appointment */
void cancel_appointment() {
  printf("\n------- Cancelling an appointment -------\n");
  printf("Enter your name: ");
  // code for taking user input for name and other details
  // code for cancelling the appointment
  printf("Appointment cancelled successfully.\n\n");
}