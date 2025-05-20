//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_ROOMS 10
#define MAX_GUEST_NAME_LENGTH 20

typedef struct Guest {
  char name[MAX_GUEST_NAME_LENGTH];
  int room_number;
  struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  new_guest->next = NULL;

  // Get the guest's name and room number
  printf("Enter guest name: ");
  scanf("%s", new_guest->name);

  printf("Enter guest room number: ");
  scanf("%d", &new_guest->room_number);

  // If the head of the list is NULL, make it the new head
  if (head == NULL) {
    head = new_guest;
  } else {
    // Traverse the list until the last guest is reached
    Guest* current_guest = head;
    while (current_guest->next != NULL) {
      current_guest = current_guest->next;
    }

    // Insert the new guest at the end of the list
    current_guest->next = new_guest;
  }

  return head;
}

void print_guests(Guest* head) {
  // Traverse the list of guests
  Guest* current_guest = head;
  while (current_guest) {
    // Print the guest's name and room number
    printf("Name: %s, Room Number: %d\n", current_guest->name, current_guest->room_number);
    current_guest = current_guest->next;
  }
}

int main() {
  Guest* head = NULL;

  // Insert some guests
  head = insert_guest(head);
  insert_guest(head);
  insert_guest(head);

  // Print the guests
  print_guests(head);

  return 0;
}