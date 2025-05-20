//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define ROAD_LENGTH 1000

typedef struct car {
  int position;
  int direction;
  int speed;
  int lane;
  struct car* next;
} car;

car* create_car() {
  car* new_car = (car*)malloc(sizeof(car));
  new_car->position = 0;
  new_car->direction = 1;
  new_car->speed = 5;
  new_car->lane = 1;
  new_car->next = NULL;
  return new_car;
}

void move_car(car* car) {
  switch (car->direction) {
    case 1:
      car->position++;
      break;
    case -1:
      car->position--;
      break;
  }

  switch (car->lane) {
    case 1:
      car->position++;
      break;
    case 2:
      car->position += 2;
      break;
    case 3:
      car->position += 3;
      break;
  }
}

void simulate_traffic(car* head) {
  time_t start_time = time(NULL);
  while (time(NULL) - start_time < 60) {
    move_car(head);
    head = head->next;
  }
}

int main() {
  car* head = create_car();
  head->next = create_car();
  head->next->next = create_car();
  head->next->next->next = create_car();
  head->next->next->next->next = create_car();

  simulate_traffic(head);

  return 0;
}