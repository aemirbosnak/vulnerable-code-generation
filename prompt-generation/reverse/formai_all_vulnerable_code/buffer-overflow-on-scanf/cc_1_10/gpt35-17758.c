//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
  char name[50];
  char date[20];
  char time[10];
  int duration;
  char location[100];
} Appointment;

typedef struct Node {
  Appointment data;
  struct Node* next;
} Node;

Node* head = NULL;

void display(Appointment appt) {
  printf("Appointment with %s on %s at %s for %d minutes at %s\n", appt.name, appt.date, appt.time, appt.duration, appt.location);
}

void displayAll() {
  if (head == NULL) {
    printf("No appointments scheduled yet!\n");
    return;
  }
  Node* current = head;
  while (current != NULL) {
    display(current->data);
    current = current->next;
  }
}

void addAppointment() {
  Appointment appt;
  printf("Enter Client Name: ");
  scanf("%s", appt.name);
  printf("Enter Date in dd/mm/yyyy format: ");
  scanf("%s", appt.date);
  printf("Enter Time in hh:mm format: ");
  scanf("%s", appt.time);
  printf("Enter Duration in minutes: ");
  scanf("%d", &appt.duration);
  printf("Enter Location: ");
  scanf("%s", appt.location);

  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->data = appt;
  new_node->next = head;
  head = new_node;

  printf("Appointment Scheduled Successfully!\n");
}

void deleteAppointment() {
  if (head == NULL) {
    printf("No appointments scheduled yet!\n");
    return;
  }

  char name[50];
  printf("Enter Client Name to Delete Appointment: ");
  scanf("%s", name);

  Node* previous = NULL;
  Node* current = head;

  while (current != NULL) {
    if (strcmp(current->data.name, name) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      printf("Appointment Deleted Successfully!\n");
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Appointment not found for Client: %s\n", name);
}

int main() {
  int choice;

  printf("***** Welcome to Appointment Scheduler *****\n");

  do {
    printf("\nSelect an Option:\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View All Appointments\n");
    printf("3. Delete an Appointment\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addAppointment();
        break;
      case 2:
        displayAll();
        break;
      case 3:
        deleteAppointment();
        break;
      case 4:
        printf("Thank you for using Appointment Scheduler!\n");
        break;
      default:
        printf("Invalid Choice! Please try again...\n");
    }
  } while (choice != 4);

  return 0;
}