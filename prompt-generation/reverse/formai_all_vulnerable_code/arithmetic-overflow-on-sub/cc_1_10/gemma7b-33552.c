//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct car {
  int lane;
  int position;
  int speed;
  struct car* next;
} car;

car* create_car(int lane, int position, int speed) {
  car* new_car = malloc(sizeof(struct car));
  new_car->lane = lane;
  new_car->position = position;
  new_car->speed = speed;
  new_car->next = NULL;

  return new_car;
}

void simulate_traffic(car* head) {
  time_t start_time = time(NULL);

  while (time(NULL) - start_time < 10) {
    for (car* current_car = head; current_car; current_car = current_car->next) {
      current_car->position++;

      if (current_car->position >= MAX_LANE) {
        current_car->position = 0;
      }

      sleep(0.1);
    }
  }

  free(head);
}

int main() {
  car* head = create_car(1, 0, 5);
  head = create_car(2, 1, 3);
  head = create_car(0, 2, 2);

  simulate_traffic(head);

  return 0;
}