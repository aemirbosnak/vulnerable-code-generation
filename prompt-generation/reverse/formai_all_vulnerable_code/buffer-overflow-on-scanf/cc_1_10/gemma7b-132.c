//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

struct Ghost {
  char name[20];
  int age;
  float haunt_rating;
  int room_number;
  struct Ghost *next;
};

typedef struct Ghost Ghost;

void add_ghost(Ghost **head) {
  Ghost *new_ghost = malloc(sizeof(Ghost));
  new_ghost->next = NULL;

  printf("Enter the name of the ghost: ");
  scanf("%s", new_ghost->name);

  printf("Enter the age of the ghost: ");
  scanf("%d", &new_ghost->age);

  printf("Enter the haunt rating of the ghost (0-10): ");
  scanf("%f", &new_ghost->haunt_rating);

  printf("Enter the room number where the ghost resides: ");
  scanf("%d", &new_ghost->room_number);

  if (*head == NULL) {
    *head = new_ghost;
  } else {
    (*head)->next = new_ghost;
  }
}

void display_ghosts(Ghost *head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Haunt Rating: %.2f\n", head->haunt_rating);
    printf("Room Number: %d\n", head->room_number);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Ghost *head = NULL;

  // Add some ghosts
  add_ghost(&head);
  add_ghost(&head);
  add_ghost(&head);

  // Display the ghosts
  display_ghosts(head);

  return 0;
}