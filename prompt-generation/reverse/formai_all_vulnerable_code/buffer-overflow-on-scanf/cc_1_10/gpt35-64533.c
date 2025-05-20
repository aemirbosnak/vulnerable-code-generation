//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
  time_t start_time;
  time_t end_time;
  char name[MAX_NAME_LENGTH];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

int compare_appointments(const void* a, const void* b) {
  const Appointment* appt_a = (const Appointment*)a;
  const Appointment* appt_b = (const Appointment*)b;

  if (appt_a->start_time < appt_b->start_time) {
    return -1;
  } else if (appt_a->start_time > appt_b->start_time) {
    return 1;
  } else {
    return 0;
  }
}

void print_appointment(Appointment* appt) {
  char start_time_str[40];
  char end_time_str[40];
  strftime(start_time_str, sizeof(start_time_str), "%Y-%m-%d %H:%M", localtime(&appt->start_time));
  strftime(end_time_str, sizeof(end_time_str), "%Y-%m-%d %H:%M", localtime(&appt->end_time));
  printf("%s - %s: %s\n", start_time_str, end_time_str, appt->name);
}

void print_all_appointments() {
  printf("Your Appointments:\n");
  for (int i = 0; i < num_appointments; i++) {
    print_appointment(&appointments[i]);
  }
}

void add_appointment() {
  if (num_appointments == MAX_APPOINTMENTS) {
    printf("Sorry, You cannot create any more appointments today.\n");
  } else {
    printf("Please enter the name of the appointment: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);

    printf("Please enter the start time of the appointment in the format of YYYY-MM-DD HH:MM: ");
    char start_time_str[40];
    fgets(start_time_str, sizeof(start_time_str), stdin);
    struct tm start_time_tm;
    strptime(start_time_str, "%Y-%m-%d %H:%M", &start_time_tm);
    time_t start_time = mktime(&start_time_tm);

    printf("Please enter the duration of the appointment in minutes: ");
    int duration_minutes = 0;
    scanf("%d", &duration_minutes);
    getchar();
    time_t end_time = start_time + duration_minutes * 60;

    Appointment new_appointment = { start_time, end_time, "" };
    int n = sizeof(name) / sizeof(name[0]);
    if (n && name[n - 1] == '\n') {
      name[n - 1] = '\0'; // remove newline from input
    }
    strncpy(new_appointment.name, name, sizeof(new_appointment.name) - 1);
    new_appointment.name[sizeof(new_appointment.name) - 1] = '\0';

    appointments[num_appointments] = new_appointment;
    num_appointments++;

    printf("Your appointment has been added!\n");
  }
}

void delete_appointment() {
  if (num_appointments == 0) {
    printf("Sorry, You don't have any appointments to delete.\n");
  } else {
    printf("Please enter the start time of the appointment that you want to delete in the format of YYYY-MM-DD HH:MM: ");
    char start_time_str[40];
    fgets(start_time_str, sizeof(start_time_str), stdin);
    struct tm start_time_tm;
    strptime(start_time_str, "%Y-%m-%d %H:%M", &start_time_tm);
    time_t start_time = mktime(&start_time_tm);

    int index_to_delete = -1;
    for (int i = 0; i < num_appointments; i++) {
      if (appointments[i].start_time == start_time) {
        index_to_delete = i;
        break;
      }
    }

    if (index_to_delete == -1) {
      printf("Sorry, We could not find the appointment that you are looking for.\n");
    } else {
      for (int i = index_to_delete; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
      }
      num_appointments--;
      printf("Your appointment has been deleted!\n");
    }
  }
}

int main() {
  char user_input;

  while (1) {
    printf("\n");
    printf("Welcome to Your Appointment Scheduler!\n");
    printf("Please select an option below:\n");
    printf("1) View all appointments\n");
    printf("2) Add an appointment\n");
    printf("3) Delete an appointment\n");
    printf("4) Exit\n");

    user_input = getchar();
    getchar();

    if (user_input == '1') {
      if (num_appointments == 0) {
        printf("You do not have any appointments yet.\n");
      } else {
        qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);
        print_all_appointments();
      }
    } else if (user_input == '2') {
      add_appointment();
    } else if (user_input == '3') {
      delete_appointment();
    } else if (user_input == '4') {
      printf("Thank You for using Your Appointment Scheduler!\n");
      break;
    } else {
      printf("Invalid input.\n");
    }
  }

  return 0;
}