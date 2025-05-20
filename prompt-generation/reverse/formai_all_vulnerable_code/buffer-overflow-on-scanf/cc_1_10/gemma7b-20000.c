//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[20];
  int room_number;
  struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head, char* name, int room_number) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->next = NULL;

  if (head == NULL) {
    head = new_guest;
  } else {
    head->next = new_guest;
  }

  return head;
}

Guest* find_guest(Guest* head, char* name) {
  Guest* current_guest = head;

  while (current_guest) {
    if (strcmp(current_guest->name, name) == 0) {
      return current_guest;
    }
    current_guest = current_guest->next;
  }

  return NULL;
}

void check_in(Guest* head) {
  char name[20];
  int room_number;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your room number: ");
  scanf("%d", &room_number);

  insert_guest(head, name, room_number);

  printf("Welcome to the hotel, %s! Please enjoy your stay.", name);
}

void check_out(Guest* head) {
  char name[20];

  printf("Enter your name: ");
  scanf("%s", name);

  Guest* guest = find_guest(head, name);

  if (guest) {
    printf("Thank you for your stay, %s.", guest->name);
    free(guest);
  } else {
    printf("Guest not found.");
  }
}

int main() {
  Guest* head = NULL;

  while (1) {
    int choice;

    printf("1. Check in\n");
    printf("2. Check out\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        check_in(head);
        break;
      case 2:
        check_out(head);
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("\n");
  }

  return 0;
}