//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a struct to represent our RC car
typedef struct {
  int speed;
  int direction;
  int x;
  int y;
} RC_Car;

// Initialize the RC car with default values
RC_Car car = {
  .speed = 0,
  .direction = 0,
  .x = 0,
  .y = 0
};

// Display the welcome message
void welcome() {
  printf("Welcome to the Super-Duper RC Car Simulation!\n");
  printf(" Buckle up and get ready for an adrenaline-pumping ride!\n");
}

// Display the controls
void displayControls() {
  printf("Controls:\n");
  printf(" - Accelerate/Decelerate: +/- keys\n");
  printf(" - Turn Left/Right: <, > keys\n");
  printf(" - Exit: q key\n");
}

// Accelerate/Decelerate the car
void adjustSpeed(char key) {
  if (key == '+') {
    car.speed += 1;
  } else if (key == '-') {
    car.speed -= 1;
  }
  // Clamp speed to a reasonable range
  car.speed = fmax(car.speed, 0);
  car.speed = fmin(car.speed, 10);
}

// Turn the car
void turnCar(char key) {
  if (key == '<') {
    car.direction -= 1;
  } else if (key == '>') {
    car.direction += 1;
  }
  // Wrap direction around to 0-3
  car.direction %= 4;
}

// Move the car
void moveCar() {
  int delta_x = 0, delta_y = 0;
  switch (car.direction) {
    case 0: // North
      delta_y = 1;
      break;
    case 1: // East
      delta_x = 1;
      break;
    case 2: // South
      delta_y = -1;
      break;
    case 3: // West
      delta_x = -1;
      break;
  }
  car.x += car.speed * delta_x;
  car.y += car.speed * delta_y;
}

// Display the current state of the car
void displayCar() {
  printf("Current State:\n");
  printf(" - Speed: %d km/h\n", car.speed);
  printf(" - Direction: %d (0: North, 1: East, 2: South, 3: West)\n", car.direction);
  printf(" - Position: (%d, %d)\n", car.x, car.y);
}

// Main function - the heart of our simulation
int main() {
  // Set random seed for generating random obstacles
  srand(time(NULL));
  
  // Display welcome message and controls
  welcome();
  displayControls();

  // Run the simulation until the user exits
  char input;
  do {
    // Get user input
    printf("\nCommand: ");
    scanf(" %c", &input);

    // Process user input
    switch (input) {
      case '+':
      case '-':
        adjustSpeed(input);
        break;
      case '<':
      case '>':
        turnCar(input);
        break;
      case 'q':
        break;
      default:
        printf("Invalid command. Try again!\n");
        break;
    }

    // Move the car
    moveCar();

    // Display the current state of the car
    displayCar();

  } while (input != 'q');

  // Say goodbye and exit
  printf("\nThanks for playing! See you next time!\n");
  return 0;
}