//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct spaceship {
  char name[MAX_NAME_LENGTH];
  int crew_size;
  double fuel_capacity;
  double current_fuel;
  double speed;
} spaceship;

void initialize_spaceship(spaceship *ship) {
  ship->name[0] = '\0';
  ship->crew_size = 0;
  ship->fuel_capacity = 0.0;
  ship->current_fuel = 0.0;
  ship->speed = 0.0;
}

int main() {
  spaceship my_ship;
  initialize_spaceship(&my_ship);

  // Name your spaceship
  printf("Enter the name of your spaceship: ");
  scanf("%s", my_ship.name);

  // Crew size
  printf("Enter the number of crew members: ");
  scanf("%d", &my_ship.crew_size);

  // Fuel capacity
  printf("Enter the fuel capacity of your spaceship: ");
  scanf("%lf", &my_ship.fuel_capacity);

  // Current fuel
  printf("Enter the current fuel level: ");
  scanf("%lf", &my_ship.current_fuel);

  // Speed
  printf("Enter the speed of your spaceship: ");
  scanf("%lf", &my_ship.speed);

  // Print your spaceship information
  printf("Here is your spaceship information:\n");
  printf("Name: %s\n", my_ship.name);
  printf("Crew size: %d\n", my_ship.crew_size);
  printf("Fuel capacity: %.2lf\n", my_ship.fuel_capacity);
  printf("Current fuel: %.2lf\n", my_ship.current_fuel);
  printf("Speed: %.2lf\n", my_ship.speed);

  return 0;
}