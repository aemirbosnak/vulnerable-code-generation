//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[20];
  int room_num;
  struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  printf("Enter your name: ");
  scanf("%s", new_guest->name);
  printf("Enter your room number: ");
  scanf("%d", &new_guest->room_num);
  new_guest->next = head;
  return new_guest;
}

void print_guests(Guest* head) {
  Guest* current = head;
  while (current) {
    printf("Name: %s, Room Number: %d\n", current->name, current->room_num);
    current = current->next;
  }
}

int main() {
  Guest* head = NULL;
  char command[20];

  printf("Welcome to the C Hotel Management System!\n");
  printf("Please enter a command: ");
  scanf("%s", command);

  while (strcmp(command, "exit") != 0) {
    if (strcmp(command, "insert") == 0) {
      insert_guest(head);
    } else if (strcmp(command, "print") == 0) {
      print_guests(head);
    } else {
      printf("Invalid command.\n");
    }

    printf("Please enter a command: ");
    scanf("%s", command);
  }

  printf("Thank you for using the C Hotel Management System!\n");
  return 0;
}