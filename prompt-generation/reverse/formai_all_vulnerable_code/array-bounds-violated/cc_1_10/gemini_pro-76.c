//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 10

// The map of the world
char world[WIDTH][HEIGHT];

// The position of the car
int car_x, car_y;

// The direction the car is facing
int car_dir;

// Initialize the world
void init_world() {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      world[i][j] = '.';
    }
  }
}

// Place the car in the world
void place_car() {
  car_x = WIDTH / 2;
  car_y = HEIGHT / 2;
  car_dir = 0;
  world[car_x][car_y] = 'C';
}

// Print the world
void print_world() {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      printf("%c", world[i][j]);
    }
    printf("\n");
  }
}

// Move the car forward
void move_forward() {
  switch (car_dir) {
    case 0:
      car_y--;
      break;
    case 1:
      car_x++;
      break;
    case 2:
      car_y++;
      break;
    case 3:
      car_x--;
      break;
  }

  // Wrap around the edges of the world
  if (car_x < 0) {
    car_x = WIDTH - 1;
  } else if (car_x >= WIDTH) {
    car_x = 0;
  }
  if (car_y < 0) {
    car_y = HEIGHT - 1;
  } else if (car_y >= HEIGHT) {
    car_y = 0;
  }

  // Update the world
  world[car_x][car_y] = 'C';
  world[car_x - 1][car_y] = '.';
  world[car_x + 1][car_y] = '.';
  world[car_x][car_y - 1] = '.';
  world[car_x][car_y + 1] = '.';
}

// Turn the car left
void turn_left() {
  car_dir = (car_dir + 1) % 4;
}

// Turn the car right
void turn_right() {
  car_dir = (car_dir - 1) % 4;
}

// Get a random direction
int get_random_direction() {
  return rand() % 4;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the world
  init_world();

  // Place the car in the world
  place_car();

  // Main game loop
  while (1) {
    // Get a random direction
    int direction = get_random_direction();

    // Move the car in the specified direction
    switch (direction) {
      case 0:
        move_forward();
        break;
      case 1:
        turn_left();
        break;
      case 2:
        turn_right();
        break;
      case 3:
        move_forward();
        turn_left();
        break;
    }

    // Print the world
    print_world();

    // Sleep for a bit
    usleep(100000);
  }

  return 0;
}