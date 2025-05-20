//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

bool isConnected() {
  // check if remote control is connected to drone
  return true;
}

void takeOff() {
  printf("Drone taking off\n");
}

void land() {
  printf("Drone landing\n");
}

void moveForward(int distance) {
  printf("Drone moving forward by %d meters\n", distance);
}

void moveBackward(int distance) {
  printf("Drone moving backward by %d meters\n", distance);
}

void moveLeft(int distance) {
  printf("Drone moving left by %d meters\n", distance);
}

void moveRight(int distance) {
  printf("Drone moving right by %d meters\n", distance);
}

void rotate(int degrees) {
  printf("Drone rotating by %d degrees\n", degrees);
}

int main() {
  if(!isConnected()) {
    printf("Drone remote control is not connected\n");
    return 1;
  }

  printf("Welcome to Drone Remote Control\n");

  int option, distance, degrees;
  while(true) {
    printf("\nPlease select an option:\n");
    printf("1. Take off\n");
    printf("2. Land\n");
    printf("3. Move forward\n");
    printf("4. Move backward\n");
    printf("5. Move left\n");
    printf("6. Move right\n");
    printf("7. Rotate\n");
    printf("8. Exit\n");

    scanf("%d", &option);

    switch(option) {
      case 1:
        takeOff();
        break;
      case 2:
        land();
        break;
      case 3:
        printf("Enter distance to move forward: ");
        scanf("%d", &distance);
        moveForward(distance);
        break;
      case 4:
        printf("Enter distance to move backward: ");
        scanf("%d", &distance);
        moveBackward(distance);
        break;
      case 5:
        printf("Enter distance to move left: ");
        scanf("%d", &distance);
        moveLeft(distance);
        break;
      case 6:
        printf("Enter distance to move right: ");
        scanf("%d", &distance);
        moveRight(distance);
        break;
      case 7:
        printf("Enter degrees to rotate: ");
        scanf("%d", &degrees);
        rotate(degrees);
        break;
      case 8:
        printf("Exiting Drone Remote Control\n");
        return 0;
      default:
        printf("Invalid option, please select a valid option from 1 to 8\n");
    }
  }

  return 0;
}