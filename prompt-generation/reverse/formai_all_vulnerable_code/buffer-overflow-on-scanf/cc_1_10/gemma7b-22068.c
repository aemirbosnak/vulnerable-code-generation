//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

struct Ghost {
  char name[20];
  int room_number;
  int presence;
  float fear_factor;
  struct Ghost *next;
};

void add_ghost(struct Ghost **head) {
  struct Ghost *new_ghost = (struct Ghost *)malloc(sizeof(struct Ghost));
  new_ghost->next = NULL;

  printf("Enter the name of the ghost: ");
  scanf("%s", new_ghost->name);

  printf("Enter the room number where the ghost resides: ");
  scanf("%d", &new_ghost->room_number);

  printf("Enter the presence of the ghost (0/1): ");
  scanf("%d", &new_ghost->presence);

  printf("Enter the fear factor of the ghost (0-10): ");
  scanf("%f", &new_ghost->fear_factor);

  if (*head == NULL) {
    *head = new_ghost;
  } else {
    (*head)->next = new_ghost;
  }
}

void display_ghosts(struct Ghost *head) {
  printf("List of ghosts:\n");
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Room number: %d\n", head->room_number);
    printf("Presence: %d\n", head->presence);
    printf("Fear factor: %.2f\n", head->fear_factor);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Ghost *head = NULL;

  // Add some ghosts
  add_ghost(&head);
  add_ghost(&head);
  add_ghost(&head);

  // Display the ghosts
  display_ghosts(head);

  // Interact with the ghosts
  // ...

  return 0;
}