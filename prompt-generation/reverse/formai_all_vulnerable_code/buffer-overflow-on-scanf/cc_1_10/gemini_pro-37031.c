//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
  char name[50];
  char date[11];
  char time[6];
  char reason[100];
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *date, char *time, char *reason) {
  strcpy(appointments[num_appointments].name, name);
  strcpy(appointments[num_appointments].date, date);
  strcpy(appointments[num_appointments].time, time);
  strcpy(appointments[num_appointments].reason, reason);
  num_appointments++;
}

void print_appointment(appointment_t *appointment) {
  printf("%s, %s, %s, %s\n", appointment->name, appointment->date, appointment->time, appointment->reason);
}

void print_all_appointments() {
  for (int i = 0; i < num_appointments; i++) {
    print_appointment(&appointments[i]);
  }
}

void find_appointment_by_name(char *name) {
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].name, name) == 0) {
      print_appointment(&appointments[i]);
    }
  }
}

void find_appointment_by_date(char *date) {
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].date, date) == 0) {
      print_appointment(&appointments[i]);
    }
  }
}

void find_appointment_by_time(char *time) {
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].time, time) == 0) {
      print_appointment(&appointments[i]);
    }
  }
}

void find_appointment_by_reason(char *reason) {
  for (int i = 0; i < num_appointments; i++) {
    if (strcmp(appointments[i].reason, reason) == 0) {
      print_appointment(&appointments[i]);
    }
  }
}

int main() {
  add_appointment("John Doe", "2023-03-08", "10:00", "Meeting");
  add_appointment("Jane Smith", "2023-03-09", "11:00", "Interview");
  add_appointment("John Doe", "2023-03-10", "12:00", "Lunch");
  add_appointment("Jane Smith", "2023-03-11", "13:00", "Coffee");

  print_all_appointments();

  printf("\nFind appointment by name: ");
  char name[50];
  scanf("%s", name);
  find_appointment_by_name(name);

  printf("\nFind appointment by date: ");
  char date[11];
  scanf("%s", date);
  find_appointment_by_date(date);

  printf("\nFind appointment by time: ");
  char time[6];
  scanf("%s", time);
  find_appointment_by_time(time);

  printf("\nFind appointment by reason: ");
  char reason[100];
  scanf("%s", reason);
  find_appointment_by_reason(reason);

  return 0;
}