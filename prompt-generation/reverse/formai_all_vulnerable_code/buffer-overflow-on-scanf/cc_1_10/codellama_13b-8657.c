//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
/*
 * A unique C Appointment Scheduler example program in an intelligent style.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold appointment details
struct Appointment {
  char name[100];
  char email[100];
  char phone[10];
  int date;
  int time;
};

// Function to display appointment details
void display_appointment(struct Appointment appointment) {
  printf("Name: %s\n", appointment.name);
  printf("Email: %s\n", appointment.email);
  printf("Phone: %s\n", appointment.phone);
  printf("Date: %d\n", appointment.date);
  printf("Time: %d\n", appointment.time);
}

// Function to add an appointment
void add_appointment(struct Appointment *appointments, int *size) {
  struct Appointment appointment;
  printf("Enter name: ");
  scanf("%s", appointment.name);
  printf("Enter email: ");
  scanf("%s", appointment.email);
  printf("Enter phone: ");
  scanf("%s", appointment.phone);
  printf("Enter date: ");
  scanf("%d", &appointment.date);
  printf("Enter time: ");
  scanf("%d", &appointment.time);

  appointments[*size] = appointment;
  *size += 1;
}

// Function to delete an appointment
void delete_appointment(struct Appointment *appointments, int *size) {
  int index;
  printf("Enter index: ");
  scanf("%d", &index);

  if (index < 0 || index >= *size) {
    printf("Invalid index\n");
    return;
  }

  appointments[index] = appointments[*size - 1];
  *size -= 1;
}

// Function to search for an appointment
void search_appointment(struct Appointment *appointments, int size) {
  char name[100];
  printf("Enter name: ");
  scanf("%s", name);

  for (int i = 0; i < size; i++) {
    if (strcmp(name, appointments[i].name) == 0) {
      display_appointment(appointments[i]);
      return;
    }
  }

  printf("No appointment found\n");
}

int main() {
  struct Appointment appointments[100];
  int size = 0;

  int option;
  do {
    printf("Enter option:\n");
    printf("1. Add appointment\n");
    printf("2. Delete appointment\n");
    printf("3. Search appointment\n");
    printf("4. Display all appointments\n");
    printf("5. Exit\n");
    scanf("%d", &option);

    switch (option) {
    case 1:
      add_appointment(appointments, &size);
      break;
    case 2:
      delete_appointment(appointments, &size);
      break;
    case 3:
      search_appointment(appointments, size);
      break;
    case 4:
      for (int i = 0; i < size; i++) {
        display_appointment(appointments[i]);
      }
      break;
    case 5:
      break;
    default:
      printf("Invalid option\n");
    }
  } while (option != 5);

  return 0;
}