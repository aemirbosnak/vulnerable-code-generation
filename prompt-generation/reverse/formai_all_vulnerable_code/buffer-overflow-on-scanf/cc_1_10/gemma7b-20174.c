//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
  char name[50];
  int room_number;
  char status;
  struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
  Guest* newGuest = (Guest*)malloc(sizeof(Guest));
  printf("Enter your name: ");
  scanf("%s", newGuest->name);
  printf("Enter your room number: ");
  scanf("%d", &newGuest->room_number);
  newGuest->status = 'O';
  newGuest->next = NULL;

  if (head == NULL) {
    head = newGuest;
  } else {
    head->next = newGuest;
  }

  return head;
}

void checkIn(Guest* head) {
  printf("Enter your name: ");
  char name[50];
  scanf("%s", name);

  Guest* currentGuest = head;

  while (currentGuest) {
    if (strcmp(currentGuest->name, name) == 0) {
      printf("Welcome, %s! You are in room %d.", currentGuest->name, currentGuest->room_number);
      currentGuest->status = 'C';
      break;
    }
    currentGuest = currentGuest->next;
  }

  if (currentGuest == NULL) {
    printf("No guest found with that name.");
  }
}

void checkOut(Guest* head) {
  printf("Enter your name: ");
  char name[50];
  scanf("%s", name);

  Guest* currentGuest = head;

  while (currentGuest) {
    if (strcmp(currentGuest->name, name) == 0) {
      printf("Goodbye, %s. We hope you enjoyed your stay.", currentGuest->name);
      currentGuest->status = 'O';
      break;
    }
    currentGuest = currentGuest->next;
  }

  if (currentGuest == NULL) {
    printf("No guest found with that name.");
  }
}

int main() {
  Guest* head = NULL;

  while (1) {
    printf("Enter '1' to insert a guest, '2' to check in, '3' to check out, or '4' to exit: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        head = insertGuest(head);
        break;
      case 2:
        checkOut(head);
        break;
      case 3:
        checkOut(head);
        break;
      case 4:
        exit(0);
    }
  }

  return 0;
}