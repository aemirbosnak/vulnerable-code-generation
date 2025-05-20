//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>

// Define a struct for storing appointment information
struct appointment {
  char date[20];
  char time[10];
  char description[100];
};

// Define an array of appointments that can hold up to 10 appointments
struct appointment appointments[10];

// Define a global variable for keeping track of the number of appointments
int num_appointments = 0;

// Function for adding a new appointment
void add_appointment() {
  printf("Enter date of appointment (MM/DD/YYYY): ");
  scanf("%s", appointments[num_appointments].date);
  printf("Enter time of appointment (HH:MM): ");
  scanf("%s", appointments[num_appointments].time);
  printf("Enter description of appointment: ");
  scanf("%s", appointments[num_appointments].description);
  
  printf("Appointment has been added.\n");
  num_appointments++;
}

// Function for removing an appointment
void remove_appointment() {
  int index;
  
  printf("Enter index of appointment to remove: ");
  scanf("%d", &index);
  
  if (index >= num_appointments) {
    printf("Invalid index.\n");
  }
  else {
    for (int i = index; i < num_appointments - 1; i++) {
      appointments[i] = appointments[i+1];
    }
    num_appointments--;
    printf("Appointment has been removed.\n");
  }
}

// Function for displaying all appointments
void display_appointments() {
  if (num_appointments == 0) {
    printf("No appointments to display.\n");
    return;
  }
  
  printf("Appointments:\n");
  for (int i = 0; i < num_appointments; i++) {
    printf("%d. %s at %s: %s\n", i, appointments[i].date, appointments[i].time, appointments[i].description);
  }
}

int main() {
  int option;
  
  do {
    printf("\nAppointment Scheduler\n");
    printf("1. Add appointment\n");
    printf("2. Remove appointment\n");
    printf("3. Display all appointments\n");
    printf("4. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        add_appointment();
        break;
      case 2:
        remove_appointment();
        break;
      case 3:
        display_appointments();
        break;
      case 4:
        printf("Exiting program.\n");
        break;
      default:
        printf("Invalid option.\n");
    }
    
  } while (option != 4);
  
  return 0;
}