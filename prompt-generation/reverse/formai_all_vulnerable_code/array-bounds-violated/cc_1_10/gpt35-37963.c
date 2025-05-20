//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20
#define MAX_NOTES_LENGTH 100

struct Appointment {
  char name[MAX_NAME_LENGTH];
  char date[MAX_DATE_LENGTH];
  char time[MAX_TIME_LENGTH];
  char notes[MAX_NOTES_LENGTH];
};

struct Appointment appointmentList[MAX_APPOINTMENTS];
int currentAppointmentIndex = 0;

void addAppointment() {
  if (currentAppointmentIndex >= MAX_APPOINTMENTS) {
    printf("Cannot add appointment. Maximum reached.\n");
    return;
  }

  struct Appointment appointment;

  printf("Enter appointment name: ");
  fgets(appointment.name, MAX_NAME_LENGTH, stdin);
  appointment.name[strlen(appointment.name) - 1] = '\0';

  printf("Enter appointment date (YYYY-MM-DD): ");
  fgets(appointment.date, MAX_DATE_LENGTH, stdin);
  appointment.date[strlen(appointment.date) - 1] = '\0';

  printf("Enter appointment time (HH:MM AM/PM): ");
  fgets(appointment.time, MAX_TIME_LENGTH, stdin);
  appointment.time[strlen(appointment.time) - 1] = '\0';

  printf("Enter appointment notes: ");
  fgets(appointment.notes, MAX_NOTES_LENGTH, stdin);
  appointment.notes[strlen(appointment.notes) - 1] = '\0';

  appointmentList[currentAppointmentIndex++] = appointment;

  printf("Appointment added successfully.\n");
}

void displayAppointmentList() {
  printf("Appointment List\n");
  printf("---------------\n");

  for (int i = 0; i < currentAppointmentIndex; i++) {
    printf("Name: %s\n", appointmentList[i].name);
    printf("Date: %s\n", appointmentList[i].date);
    printf("Time: %s\n", appointmentList[i].time);
    printf("Notes: %s\n", appointmentList[i].notes);
    printf("---------------\n");
  }
}

void searchAppointments() {
  char searchTerm[MAX_NAME_LENGTH];

  printf("Enter a search term: ");
  fgets(searchTerm, MAX_NAME_LENGTH, stdin);
  searchTerm[strlen(searchTerm) - 1] = '\0';

  printf("Search Results\n");
  printf("--------------\n");

  for (int i = 0; i < currentAppointmentIndex; i++) {
    if (strstr(appointmentList[i].name, searchTerm) != NULL ||
        strstr(appointmentList[i].date, searchTerm) != NULL ||
        strstr(appointmentList[i].time, searchTerm) != NULL ||
        strstr(appointmentList[i].notes, searchTerm) != NULL) {
      printf("Name: %s\n", appointmentList[i].name);
      printf("Date: %s\n", appointmentList[i].date);
      printf("Time: %s\n", appointmentList[i].time);
      printf("Notes: %s\n", appointmentList[i].notes);
      printf("---------------\n");
    }
  }
}

void clearInputBuffer() {
  int c;

  while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
  int choice;

  printf("Appointment Scheduler\n");
  printf("----------------------\n");

  do {
    printf("MENU\n");
    printf("1. Add an Appointment\n");
    printf("2. Display Appointment List\n");
    printf("3. Search Appointments\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid choice. Please enter a number.\n");
      clearInputBuffer();
      continue;
    }

    switch (choice) {
      case 1:
        addAppointment();
        break;
      case 2:
        displayAppointmentList();
        break;
      case 3:
        searchAppointments();
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }

  } while (choice != 4);

  return 0;
}