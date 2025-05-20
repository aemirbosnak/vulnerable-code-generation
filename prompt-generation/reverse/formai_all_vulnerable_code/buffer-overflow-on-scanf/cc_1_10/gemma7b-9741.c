//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENT 10

struct appointment {
  char name[50];
  char date[50];
  char time[50];
  struct appointment* next;
};

void createAppointment(struct appointment** head) {
  struct appointment* newApp = (struct appointment*)malloc(sizeof(struct appointment));
  (*head) = newApp;

  printf("Enter your name: ");
  scanf("%s", newApp->name);

  printf("Enter the date: ");
  scanf("%s", newApp->date);

  printf("Enter the time: ");
  scanf("%s", newApp->time);

  newApp->next = NULL;
}

void displayAppointments(struct appointment* head) {
  while (head) {
    printf("%s, %s, %s\n", head->name, head->date, head->time);
    head = head->next;
  }
}

void findAppointment(struct appointment* head, char* name) {
  if (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Found appointment: %s, %s, %s\n", head->name, head->date, head->time);
    } else {
      findAppointment(head->next, name);
    }
  }
}

int main() {
  struct appointment* head = NULL;

  createAppointment(&head);
  createAppointment(&head);
  createAppointment(&head);

  displayAppointments(head);

  findAppointment(head, "John Doe");

  return 0;
}