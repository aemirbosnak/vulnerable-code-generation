//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[50];
  int room_no;
  int days_stayed;
  struct Guest *next;
} Guest;

Guest *insertGuest(Guest *head) {
  Guest *newGuest = (Guest *)malloc(sizeof(Guest));
  printf("Enter name: ");
  scanf("%s", newGuest->name);
  printf("Enter room number: ");
  scanf("%d", &newGuest->room_no);
  printf("Enter number of days stayed: ");
  scanf("%d", &newGuest->days_stayed);
  newGuest->next = NULL;

  if (head == NULL) {
    head = newGuest;
  } else {
    Guest *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newGuest;
  }

  return head;
}

void printGuests(Guest *head) {
  Guest *temp = head;
  printf("Guests:\n");
  while (temp) {
    printf("%s, room %d, days stayed %d\n", temp->name, temp->room_no, temp->days_stayed);
    temp = temp->next;
  }
}

int main() {
  Guest *head = NULL;
  char choice;

  while (1) {
    printf("Enter 'i' to insert a guest, 'p' to print guests, or 'q' to quit: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'i':
        head = insertGuest(head);
        break;
      case 'p':
        printGuests(head);
        break;
      case 'q':
        exit(0);
    }
  }

  return 0;
}