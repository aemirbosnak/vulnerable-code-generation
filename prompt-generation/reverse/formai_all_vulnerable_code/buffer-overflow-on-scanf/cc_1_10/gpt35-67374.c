//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Appointment {
  char name[50];
  char date[20];
  char time[10];
};

void addAppointment(struct Appointment appts[], int* count);
void removeAppointment(struct Appointment appts[], int* count);
void displayAppointments(struct Appointment appts[], int count);
bool isValidDate(char* date);
bool isValidTime(char* time);

int main() {
  struct Appointment appts[100];
  int count = 0;
  char choice;
  do {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Choose an option:\n");
    printf("a) Add Appointment\n");
    printf("b) Remove Appointment\n");
    printf("c) Display Appointments\n");
    printf("q) Quit\n");

    scanf(" %c", &choice);
    switch(choice) {
      case 'a': addAppointment(appts, &count); break;
      case 'b': removeAppointment(appts, &count); break;
      case 'c': displayAppointments(appts, count); break;
      case 'q': printf("Goodbye!\n"); break;
      default: printf("Invalid choice, try again.\n");
    }
  } while (choice != 'q');
  return 0;
}

// Adds a new appointment to the array
void addAppointment(struct Appointment appts[], int* count) {
  if (*count >= 100) {
    printf("Error, array is full.\n");
    return;
  }

  struct Appointment newAppt;

  // Read in the appointment details
  printf("Enter name: ");
  scanf(" %[^\n]s", newAppt.name);

  printf("Enter date (yyyy-mm-dd): ");
  scanf(" %s", newAppt.date);

  if(!isValidDate(newAppt.date)) {
    printf("Error, date format is invalid.\n");
    return;
  }

  printf("Enter time (hh:mm): ");
  scanf(" %s", newAppt.time);

  if(!isValidTime(newAppt.time)) {
    printf("Error, time format is invalid.\n");
    return;
  }

  // Add the new appointment to the array
  appts[*count] = newAppt;
  (*count)++;
  printf("Appointment added successfully!\n");
}

// Removes an appointment from the array
void removeAppointment(struct Appointment appts[], int* count) {
  if(*count <= 0) {
    printf("There are no appointments to remove.\n");
    return;
  }

  char removeName[50];

  // Read in the name of the appointment to remove
  printf("Enter name: ");
  scanf(" %[^\n]s", removeName);

  // Remove the appointment from the array
  for(int i = 0; i < *count; i++) {
    if(strcmp(appts[i].name, removeName) == 0) {
      // Shift all the appointments after the removed one down one index
      for(int j = i; j < *count - 1; j++) {
        appts[j] = appts[j+1];
      }
      (*count)--;
      printf("Appointment removed successfully!\n");
      return;
    }
  }

  printf("Error, appointment not found.\n");
}

// Displays all appointments in the array
void displayAppointments(struct Appointment appts[], int count) {
  if(count <= 0) {
    printf("There are no appointments to display.\n");
    return;
  }

  printf("All Appointments:\n");
  for(int i = 0; i < count; i++) {
    struct Appointment curAppt = appts[i];
    printf("%d) %s on %s at %s\n", i+1, curAppt.name, curAppt.date, curAppt.time);
  }
}

// Validates that a date is in the format yyyy-mm-dd
bool isValidDate(char* date) {
  if(strlen(date) != 10) {
    return false;
  }

  int year, month, day;
  if(sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
    return false;
  }

  if(year < 1900 || year > 2100) {
    return false;
  }

  if(month < 1 || month > 12) {
    return false;
  }

  if(day < 1 || day > 31) {
    return false;
  }

  return true;
}

// Validates that a time is in the format hh:mm
bool isValidTime(char* time) {
  if(strlen(time) != 5) {
    return false;
  }

  int hours, minutes;
  if(sscanf(time, "%d:%d", &hours, &minutes) != 2) {
    return false;
  }

  if(hours < 0 || hours > 23) {
    return false;
  }

  if(minutes < 0 || minutes > 59) {
    return false;
  }

  return true; 
}