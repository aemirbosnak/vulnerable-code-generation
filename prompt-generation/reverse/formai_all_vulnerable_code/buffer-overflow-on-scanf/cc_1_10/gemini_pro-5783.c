//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appt {
  char name[32];
  int day;
  int month;
  int year;
  int time;  // in minutes since midnight
  int duration;  // in minutes
};

struct Appt* create_appt(char*, int, int, int, int, int);
void print_appt(struct Appt*);
void free_appt(struct Appt*);

int main() {
  struct Appt* appts[100];
  int num_appts = 0;

  while (1) {
    printf("Enter command (a/p/q): ");
    char cmd;
    scanf(" %c", &cmd);

    if (cmd == 'a') {
      // add an appointment
      char name[32];
      int day, month, year, time, duration;
      printf("Enter name: ");
      scanf(" %s", name);
      printf("Enter day: ");
      scanf(" %d", &day);
      printf("Enter month: ");
      scanf(" %d", &month);
      printf("Enter year: ");
      scanf(" %d", &year);
      printf("Enter time (in minutes since midnight): ");
      scanf(" %d", &time);
      printf("Enter duration (in minutes): ");
      scanf(" %d", &duration);

      appts[num_appts++] = create_appt(name, day, month, year, time, duration);
    } else if (cmd == 'p') {
      // print all appointments
      for (int i = 0; i < num_appts; i++) {
        print_appt(appts[i]);
        printf("\n");
      }
    } else if (cmd == 'q') {
      // quit
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  // free all appointments
  for (int i = 0; i < num_appts; i++) {
    free_appt(appts[i]);
  }

  return 0;
}

struct Appt* create_appt(char* name, int day, int month, int year, int time, int duration) {
  struct Appt* appt = malloc(sizeof(struct Appt));
  strcpy(appt->name, name);
  appt->day = day;
  appt->month = month;
  appt->year = year;
  appt->time = time;
  appt->duration = duration;
  return appt;
}

void print_appt(struct Appt* appt) {
  printf("%s: %d/%d/%d, %d:%02d, %d minutes",
         appt->name, appt->day, appt->month, appt->year,
         appt->time / 60, appt->time % 60, appt->duration);
}

void free_appt(struct Appt* appt) {
  free(appt);
}