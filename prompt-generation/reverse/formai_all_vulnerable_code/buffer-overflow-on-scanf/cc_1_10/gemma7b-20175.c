//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct Floor {
  int floor_number;
  struct Floor* next;
} Floor;

void insert_floor(Floor** head, int floor_number) {
  Floor* new_floor = malloc(sizeof(Floor));
  new_floor->floor_number = floor_number;
  new_floor->next = NULL;

  if (*head == NULL) {
    *head = new_floor;
  } else {
    (*head)->next = new_floor;
  }
}

void simulate_elevator(Floor* head) {
  int current_floor = 1;
  int target_floor = 0;

  printf("Current floor: %d\n", current_floor);

  printf("Enter target floor: ");
  scanf("%d", &target_floor);

  while (current_floor != target_floor) {
    int next_floor = current_floor + 1;

    if (next_floor > MAX_FLOORS) {
      next_floor = MAX_FLOORS;
    }

    printf("Moving to floor %d... ", next_floor);
    current_floor = next_floor;

    sleep(1);
  }

  printf("Reached floor %d.\n", target_floor);
}

int main() {
  Floor* head = NULL;

  insert_floor(&head, 1);
  insert_floor(&head, 2);
  insert_floor(&head, 3);
  insert_floor(&head, 4);
  insert_floor(&head, 5);

  simulate_elevator(head);

  return 0;
}