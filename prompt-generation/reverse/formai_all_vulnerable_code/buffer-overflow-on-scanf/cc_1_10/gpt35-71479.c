//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int droneX = 0;
  int droneY = 0;
  
  printf("Welcome to the Surrealist Drone Remote Control!\n");
  printf("You are controlling a drone in a strange, surreal world...\n");
  
  while (1) {
    printf("--------------------\n");
    printf("Controls:\n");
    printf("w: move forward\n");
    printf("a: move left\n");
    printf("s: move backwards\n");
    printf("d: move right\n");
    printf("x: exit program\n");
    printf("--------------------\n");
    char input;
    scanf(" %c", &input);
    
    switch (input) {
      case 'w':
        printf("The drone moves forward, passing through a cloud made of spaghetti...\n");
        droneY++;
        break;
      case 'a':
        printf("The drone moves left, passing by a giant teapot that sings opera...\n");
        droneX--;
        break;
      case 's':
        printf("The drone moves backwards, dodging a rain of melted clocks and Salvador Dali's watches...\n");
        droneY--;
        break;
      case 'd':
        printf("The drone moves right, avoiding a swarm of bees flying backwards...\n");
        droneX++;
        break;
      case 'x':
        printf("Exiting program...\n");
        exit(0);
        break;
      default:
        printf("Invalid input.\n");
        break;
    }
    
    printf("Drone location: (%d, %d)\n", droneX, droneY);
    printf("You try to make sense of this world, but it remains elusive...\n");
  }
  
  return 0;
}