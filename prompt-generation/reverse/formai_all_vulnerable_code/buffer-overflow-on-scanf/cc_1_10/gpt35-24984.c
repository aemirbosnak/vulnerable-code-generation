//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void takeOff();
void land();
void moveForward(int speed);
void moveBackward(int speed);
void moveLeft(int speed);
void moveRight(int speed);
void ascend(int altitude);
void descend(int altitude);
void rotateLeft(int angle);
void rotateRight(int angle);

int main() {
  int choice, speed, altitude, angle;

  while(1) {
    // display menu options
    printf("DRONE REMOTE CONTROL\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Ascend\n");
    printf("8. Descend\n");
    printf("9. Rotate Left\n");
    printf("10. Rotate Right\n");
    printf("11. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        takeOff();
        break;
      case 2:
        land();
        break;
      case 3:
        printf("Enter speed (in km/h): ");
        scanf("%d", &speed);
        moveForward(speed);
        break;
      case 4:
        printf("Enter speed (in km/h): ");
        scanf("%d", &speed);
        moveBackward(speed);
        break;
      case 5:
        printf("Enter speed (in km/h): ");
        scanf("%d", &speed);
        moveLeft(speed);
        break;
      case 6:
        printf("Enter speed (in km/h): ");
        scanf("%d", &speed);
        moveRight(speed);
        break;
      case 7:
        printf("Enter altitude (in meters): ");
        scanf("%d", &altitude);
        ascend(altitude);
        break;
      case 8:
        printf("Enter altitude (in meters): ");
        scanf("%d", &altitude);
        descend(altitude);
        break;
      case 9:
        printf("Enter angle (in degrees): ");
        scanf("%d", &angle);
        rotateLeft(angle);
        break;
      case 10:
        printf("Enter angle (in degrees): ");
        scanf("%d", &angle);
        rotateRight(angle);
        break;
      case 11:
        printf("Program terminated.\n");
        exit(0);
        break;
      default:
        printf("Invalid choice. Please select again.\n");
    }
  }
  return 0;
}

// function to take off the drone
void takeOff() {
  printf("Drone is now taking off...\n");
}

// function to land the drone
void land() {
  printf("Drone is now landing...\n");
}

// function to move the drone forward
void moveForward(int speed) {
  printf("Drone is moving forward with a speed of %d km/h...\n", speed);
}

// function to move the drone backward
void moveBackward(int speed) {
  printf("Drone is moving backward with a speed of %d km/h...\n", speed);
}

// function to move the drone left
void moveLeft(int speed) {
  printf("Drone is moving left with a speed of %d km/h...\n", speed);
}

// function to move the drone right
void moveRight(int speed) {
  printf("Drone is moving right with a speed of %d km/h...\n", speed);
}

// function to ascend the drone
void ascend(int altitude) {
  printf("Drone is ascending to an altitude of %d meters...\n", altitude);
}

// function to descend the drone
void descend(int altitude) {
  printf("Drone is descending to an altitude of %d meters...\n", altitude);
}

// function to rotate the drone left
void rotateLeft(int angle) {
  printf("Drone is rotating left with an angle of %d degrees...\n", angle);
}

// function to rotate the drone right
void rotateRight(int angle) {
  printf("Drone is rotating right with an angle of %d degrees...\n", angle);
}