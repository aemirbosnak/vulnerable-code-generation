//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to represent an appointment
typedef struct {
  char name[50];
  int day;
  int month;
  int year;
  int hour;
  int minute;
} Appointment;

// Function to sort appointments by date
int compare_appointments(const void *a, const void *b) {
  Appointment *app1 = (Appointment *)a;
  Appointment *app2 = (Appointment *)b;
  if (app1->year < app2->year) return -1;
  else if (app1->year > app2->year) return 1;
  else if (app1->month < app2->month) return -1;
  else if (app1->month > app2->month) return 1;
  else if (app1->day < app2->day) return -1;
  else if (app1->day > app2->day) return 1;
  else if (app1->hour < app2->hour) return -1;
  else if (app1->hour > app2->hour) return 1;
  else if (app1->minute < app2->minute) return -1;
  else if (app1->minute > app2->minute) return 1;
  else return 0;
}

// Function to print appointment schedule
void print_appointment_schedule(Appointment *appointments, int num_appointments) {
  printf("Appointment Schedule:\n");
  for (int i = 0; i < num_appointments; i++) {
    printf("%s: %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
  }
}

int main() {
  // Create an array of appointments
  Appointment appointments[10];
  int num_appointments = 0;

  // Prompt user for input
  printf("Enter appointments (name, day, month, year, hour, minute):\n");
  char input[50];
  while (scanf("%s %d %d %d %d %d", appointments[num_appointments].name, &appointments[num_appointments].day, &appointments[num_appointments].month, &appointments[num_appointments].year, &appointments[num_appointments].hour, &appointments[num_appointments].minute) == 6) {
    num_appointments++;
  }

  // Sort appointments by date
  qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

  // Print appointment schedule
  print_appointment_schedule(appointments, num_appointments);

  return 0;
}