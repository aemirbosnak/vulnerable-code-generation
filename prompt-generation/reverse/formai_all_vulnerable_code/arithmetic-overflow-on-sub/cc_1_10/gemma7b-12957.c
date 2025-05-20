//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 100

typedef struct Car {
  int position;
  int direction;
  int speed;
  struct Car* next;
} Car;

Car* createCar(int position, int direction, int speed) {
  Car* car = (Car*)malloc(sizeof(Car));
  car->position = position;
  car->direction = direction;
  car->speed = speed;
  car->next = NULL;
  return car;
}

void simulateTrafficFlow(Car* cars) {
  time_t t = time(NULL);
  int i = 0;
  while (time(NULL) - t < 10) {
    for (Car* car = cars; car; car = car->next) {
      switch (car->direction) {
        case 0:
          car->position++;
          break;
        case 1:
          car->position--;
          break;
        case 2:
          car->position++;
          break;
        case 3:
          car->position--;
          break;
      }

      if (car->position >= ROAD_LENGTH) {
        car->position = 0;
      } else if (car->position < 0) {
        car->position = ROAD_LENGTH - 1;
      }
    }

    sleep(1);
  }
}

int main() {
  Car* head = createCar(0, 0, 5);
  head->next = createCar(20, 1, 3);
  head->next->next = createCar(40, 2, 4);

  simulateTrafficFlow(head);

  return 0;
}