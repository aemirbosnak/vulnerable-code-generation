//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
  char name[50];
  char date[20];
  char time[20];
  struct Appointment* next;
};

void schedule_appointment(struct Appointment** head) {
  struct Appointment* new_appointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  printf("Enter your name: ");
  scanf("%s", new_appointment->name);
  printf("Enter the date (dd/mm/yyyy): ");
  scanf("%s", new_appointment->date);
  printf("Enter the time (hh:mm): ");
  scanf("%s", new_appointment->time);

  new_appointment->next = NULL;

  if (*head == NULL) {
    *head = new_appointment;
  } else {
    (*head)->next = new_appointment;
  }
}

void list_appointments(struct Appointment* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Date: %s\n", head->date);
    printf("Time: %s\n", head->time);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Appointment* head = NULL;

  char command;

  printf("Enter 's' to schedule an appointment, 'l' to list appointments, or 'q' to quit: ");
  scanf("%c", &command);

  switch (command) {
    case 's':
      schedule_appointment(&head);
      break;
    case 'l':
      list_appointments(head);
      break;
    case 'q':
      exit(0);
  }

  return 0;
}