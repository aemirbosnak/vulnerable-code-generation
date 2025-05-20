//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[50];
  char room_number[10];
  int status;
  struct Guest* next;
} Guest;

Guest* insert_guest(Guest* head) {
  Guest* new_guest = malloc(sizeof(Guest));
  new_guest->status = 0;

  printf("Enter guest name: ");
  scanf("%s", new_guest->name);

  printf("Enter room number: ");
  scanf("%s", new_guest->room_number);

  new_guest->next = head;
  head = new_guest;

  return head;
}

void check_guest(Guest* head) {
  char name[50];

  printf("Enter guest name: ");
  scanf("%s", name);

  Guest* current_guest = head;
  while (current_guest) {
    if (strcmp(current_guest->name, name) == 0) {
      printf("Guest status: %d\n", current_guest->status);
      break;
    }
    current_guest = current_guest->next;
  }

  if (current_guest == NULL) {
    printf("Guest not found.\n");
  }
}

int main() {
  Guest* head = NULL;

  while (1) {
    printf("Please select an option:\n");
    printf("1. Insert guest\n");
    printf("2. Check guest\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        head = insert_guest(head);
        break;
      case 2:
        check_guest(head);
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}