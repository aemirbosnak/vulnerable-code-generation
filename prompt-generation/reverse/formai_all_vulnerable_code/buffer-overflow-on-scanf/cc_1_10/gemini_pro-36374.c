//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
  char name[50];
  char description[200];
  time_t start_time;
  time_t end_time;
} appointment_t;

// Create an array of appointments
appointment_t appointments[MAX_APPOINTMENTS];

// Initialize the number of appointments to 0
int num_appointments = 0;

// Function to create a new appointment
void create_appointment() {
  // Get the appointment details from the user
  printf("Enter the appointment name: ");
  scanf("%s", appointments[num_appointments].name);

  printf("Enter the appointment description: ");
  scanf("%s", appointments[num_appointments].description);

  printf("Enter the appointment start time (YYYY-MM-DD HH:MM): ");
  scanf("%s", &appointments[num_appointments].start_time);

  printf("Enter the appointment end time (YYYY-MM-DD HH:MM): ");
  scanf("%s", &appointments[num_appointments].end_time);

  // Increment the number of appointments
  num_appointments++;
}

// Function to view all appointments
void view_appointments() {
  // Print the header
  printf("%-20s %-20s %-20s %-20s\n", "Name", "Description", "Start Time", "End Time");

  // Print the appointments
  for (int i = 0; i < num_appointments; i++) {
    printf("%-20s %-20s %-20s %-20s\n", 
      appointments[i].name, 
      appointments[i].description, 
      ctime(&appointments[i].start_time), 
      ctime(&appointments[i].end_time)
    );
  }
}

// Function to edit an appointment
void edit_appointment() {
  // Get the appointment index from the user
  int index;
  printf("Enter the index of the appointment to edit: ");
  scanf("%d", &index);

  // Get the new appointment details from the user
  printf("Enter the new appointment name: ");
  scanf("%s", appointments[index].name);

  printf("Enter the new appointment description: ");
  scanf("%s", appointments[index].description);

  printf("Enter the new appointment start time (YYYY-MM-DD HH:MM): ");
  scanf("%s", &appointments[index].start_time);

  printf("Enter the new appointment end time (YYYY-MM-DD HH:MM): ");
  scanf("%s", &appointments[index].end_time);
}

// Function to delete an appointment
void delete_appointment() {
  // Get the appointment index from the user
  int index;
  printf("Enter the index of the appointment to delete: ");
  scanf("%d", &index);

  // Shift the appointments after the index to the left
  for (int i = index; i < num_appointments - 1; i++) {
    appointments[i] = appointments[i + 1];
  }

  // Decrement the number of appointments
  num_appointments--;
}

// Function to find an appointment by name
void find_appointment() {
  // Get the appointment name from the user
  char name[50];
  printf("Enter the name of the appointment to find: ");
  scanf("%s", name);

  // Find the appointment
  int index = -1;
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // Print the appointment
  if (index != -1) {
    printf("%-20s %-20s %-20s %-20s\n", 
      appointments[index].name, 
      appointments[index].description, 
      ctime(&appointments[index].start_time), 
      ctime(&appointments[index].end_time)
    );
  } else {
    printf("Appointment not found.\n");
  }
}

// Function to get the user's choice
int get_choice() {
  int choice;
  printf("\n1. Create appointment\n");
  printf("2. View appointments\n");
  printf("3. Edit appointment\n");
  printf("4. Delete appointment\n");
  printf("5. Find appointment\n");
  printf("0. Quit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Create some sample appointments
  for (int i = 0; i < 10; i++) {
    create_appointment();
  }

  // Loop until the user quits
  int choice;
  do {
    choice = get_choice();

    switch (choice) {
      case 1:
        create_appointment();
        break;
      case 2:
        view_appointments();
        break;
      case 3:
        edit_appointment();
        break;
      case 4:
        delete_appointment();
        break;
      case 5:
        find_appointment();
        break;
    }
  } while (choice != 0);

  return 0;
}