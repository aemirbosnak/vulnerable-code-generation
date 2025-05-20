//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_APPOINTMENTS 10

struct Appointment {
  char name[MAX_NAME_LENGTH];
  int day;
  int time; // 0-24 hour format
};

typedef struct Appointment Appointment;

// Helper function to get user input
void get_input(char *prompt, char *input, int max_length) {
  printf("%s", prompt);
  fgets(input, max_length, stdin);
  
  // Remove newline character from input
  input[strcspn(input, "\n")] = 0;
}

// Helper function to check if two appointments overlap
bool is_overlap(Appointment *a1, Appointment *a2) {
  return a1->day == a2->day && a1->time == a2->time;
}

// Function to check if a given appointment is available
bool is_available(Appointment *appointments, int count, Appointment *new_appointment) {
  for (int i = 0; i < count; i++) {
    if (is_overlap(&appointments[i], new_appointment)) {
      return false;
    }
  }
  return true;
}

// Function to add a new appointment
void add_appointment(Appointment *appointments, int *count) {
  Appointment new_appointment;
  get_input("Enter name: ", new_appointment.name, MAX_NAME_LENGTH);
  printf("Enter day of the month (1-31): ");
  scanf("%d", &new_appointment.day);
  printf("Enter time in 24-hour format (0-23): ");
  scanf("%d", &new_appointment.time);
  getchar(); // To consume the newline character left behind by scanf
  
  if (is_available(appointments, *count, &new_appointment)) {
    if (*count < MAX_APPOINTMENTS) {
      appointments[*count] = new_appointment;
      (*count)++;
      printf("Appointment added successfully!\n");
    } else {
      printf("Maximum appointment limit reached!\n");
    }
  } else {
    printf("This time slot is already taken. Please choose a different time.\n");
  }
}

// Function to cancel an existing appointment
void cancel_appointment(Appointment *appointments, int *count) {
  char name[MAX_NAME_LENGTH];
  printf("Enter the name on the appointment to be cancelled: ");
  fgets(name, MAX_NAME_LENGTH, stdin);
  name[strcspn(name, "\n")] = 0;
  
  bool found = false;
  
  // Loop through the existing appointments to find the matching one
  for (int i = 0; i < *count; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      found = true;
      // Shift all the appointments after this one by one position to the left
      for (int j = i; j < *count - 1; j++) {
        appointments[j] = appointments[j+1];
      }
      (*count)--;
      printf("Appointment cancelled successfully!\n");
      break;
    }
  }
  
  if (!found) {
    printf("No appointment found with name %s\n", name);
  }
}

// Function to print all the existing appointments
void print_appointments(Appointment *appointments, int count) {
  printf("Appointments:\n");
  for (int i = 0; i < count; i++) {
    printf("%s: Day %d, Time %d\n", appointments[i].name, appointments[i].day, appointments[i].time);
  }
}

int main() {
  Appointment appointments[MAX_APPOINTMENTS];
  int appointment_count = 0;
  
  while (true) {
    printf("\n");
    printf("Appointment Scheduler\n");
    printf("=====================\n");
    printf("1. Add appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View appointments\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // To consume the newline character left behind by scanf
    
    switch (choice) {
      case 1:
        add_appointment(appointments, &appointment_count);
        break;
      
      case 2:
        cancel_appointment(appointments, &appointment_count);
        break;
        
      case 3:
        print_appointments(appointments, appointment_count);
        break;
        
      case 4:
        exit(0);
        break;
        
      default:
        printf("Invalid choice!\n");
    }
  }
  
  return 0;
}