//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50

typedef struct appointment {
  char name[MAX_NAME_LENGTH];
  int day;
  int month;
  int year;
} Appointment;

int get_choice();
void display_menu();
int read_int();
void read_string(char *str, int maxChars);
void add_appointment(Appointment *appointments, int *num_appointments);
void display_appointments(Appointment *appointments, int num_appointments);
void delete_appointment(Appointment *appointments, int *num_appointments);

int main() {
  Appointment appointments[MAX_APPOINTMENTS];
  int num_appointments = 0;
  int choice = 0;

  do {
    display_menu();
    choice = get_choice();

    switch (choice) {
      case 1:
        add_appointment(appointments, &num_appointments);
        break;
      case 2:
        display_appointments(appointments, num_appointments);
        break;
      case 3:
        delete_appointment(appointments, &num_appointments);
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }

    printf("\n");
  } while (choice != 4);

  return 0;
}

int get_choice() {
  printf("Enter your choice: ");
  return read_int();
}

void display_menu() {
  printf("Appointment Scheduler Menu\n");
  printf("----------------------------\n");
  printf("1) Add Appointment\n");
  printf("2) Display Appointments\n");
  printf("3) Delete Appointment\n");
  printf("4) Exit Program\n");
}

int read_int() {
  int num;
  scanf("%d", &num);
  return num;
}

void read_string(char *str, int maxChars) {
  char ch;
  int i = 0;

  while ((ch = getchar()) != '\n' && i < maxChars - 1) {
    str[i] = ch;
    i++;
  }

  str[i] = '\0';
}

void add_appointment(Appointment *appointments, int *num_appointments) {
  if (*num_appointments == MAX_APPOINTMENTS) {
    printf("Sorry, the appointment scheduler is full.\n");
    return;
  }

  printf("Enter the appointment name: ");
  read_string(appointments[*num_appointments].name, MAX_NAME_LENGTH);

  printf("Enter the appointment date (in format DD MM YYYY): ");
  scanf("%d %d %d", &appointments[*num_appointments].day, &appointments[*num_appointments].month, &appointments[*num_appointments].year);

  (*num_appointments)++;
}

void display_appointments(Appointment *appointments, int num_appointments) {
  if (num_appointments == 0) {
    printf("No appointments.\n");
    return;
  }

  for (int i = 0; i < num_appointments; i++) {
    printf("%d) %s - %d/%d/%d\n", i+1, appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year);
  }
}

void delete_appointment(Appointment *appointments, int *num_appointments) {
  int choice;

  display_appointments(appointments, *num_appointments);

  if (*num_appointments == 0) {
    printf("No appointments to delete.\n");
    return;
  }

  printf("Which appointment would you like to delete? (enter 0 to cancel): ");
  choice = read_int();

  if (choice == 0) {
    printf("Delete operation canceled.\n");
    return;
  }

  if (choice < 1 || choice > *num_appointments) {
    printf("Invalid choice.\n");
    return;
  }

  for (int i = choice - 1; i < *num_appointments - 1; i++) {
    strcpy(appointments[i].name, appointments[i+1].name);
    appointments[i].day = appointments[i+1].day;
    appointments[i].month = appointments[i+1].month;
    appointments[i].year = appointments[i+1].year;
  }

  (*num_appointments)--;
  printf("Appointment deleted.\n");
}