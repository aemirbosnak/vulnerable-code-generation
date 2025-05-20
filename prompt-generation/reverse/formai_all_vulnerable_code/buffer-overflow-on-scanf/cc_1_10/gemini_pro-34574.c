//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    int time;
    int duration;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_welcome_message() {
  printf("Welcome to the Awesome Appointment Scheduler!\n");
  printf("You can use this program to manage your appointments.\n");
  printf("Let's get started!\n\n");
}

void print_menu() {
  printf("Please select an option:\n");
  printf("1. Add an appointment\n");
  printf("2. List appointments\n");
  printf("3. Delete an appointment\n");
  printf("4. Quit\n");
}

int get_int_input() {
  int input;
  scanf("%d", &input);
  return input;
}

char* get_string_input() {
  char* input = malloc(MAX_NAME_LENGTH * sizeof(char));
  scanf("%s", input);
  return input;
}

bool is_time_available(int time, int duration) {
  for (int i = 0; i < num_appointments; i++) {
    if (appointments[i].time == time) {
      return false;
    } else if (appointments[i].time < time && appointments[i].time + appointments[i].duration > time) {
      return false;
    } else if (appointments[i].time > time && appointments[i].time < time + duration) {
      return false;
    }
  }
  return true;
}

void add_appointment() {
  char* name = get_string_input();
  int time = get_int_input();
  int duration = get_int_input();

  if (is_time_available(time, duration)) {
    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].time = time;
    appointments[num_appointments].duration = duration;
    num_appointments++;
    printf("Appointment added successfully!\n");
  } else {
    printf("Sorry, that time is not available.\n");
  }
}

void list_appointments() {
  if (num_appointments == 0) {
    printf("No appointments scheduled.\n");
  } else {
    printf("Here are your appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
      printf("%s (%d - %d)\n", appointments[i].name, appointments[i].time, appointments[i].time + appointments[i].duration);
    }
  }
}

void delete_appointment() {
  int index = get_int_input();
  if (index < 0 || index >= num_appointments) {
    printf("Invalid index.\n");
  } else {
    for (int i = index; i < num_appointments - 1; i++) {
      appointments[i] = appointments[i + 1];
    }
    num_appointments--;
    printf("Appointment deleted successfully!\n");
  }
}

int main() {
  print_welcome_message();
  int choice;
  do {
    print_menu();
    choice = get_int_input();
    switch (choice) {
      case 1:
        add_appointment();
        break;
      case 2:
        list_appointments();
        break;
      case 3:
        delete_appointment();
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 4);
  return 0;
}