//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("Welcome to our Remote Control Vehicle Simulation Program!\n");
  printf("Are you ready to control the RC car? Here we go!\n");
  
  //initialize variables
  int speed = 0;
  int direction = 0;
  int battery = 100;
  
  //generate a random number for the obstacle
  srand(time(NULL));
  int obstacle = rand()%2;
  
  //start the simulation
  while(battery > 0){
    printf("Current speed: %d\n", speed);
    printf("Current direction: %d\n", direction);
    printf("Current battery level: %d\n", battery);
    if(obstacle == 1){
      printf("Obstacle ahead! Turn left or right (0 for left, 1 for right): ");
      int choice;
      scanf("%d", &choice);
      if(choice == 0){
        printf("You turned left and avoided the obstacle!\n");
        direction -= 5;
      }
      else{
        printf("You turned right and avoided the obstacle!\n");
        direction += 5;
      }
      obstacle = 0;
    }
    else{
      printf("No obstacles detected. Enter the speed (1 to 10): ");
      scanf("%d", &speed);
      if(speed <= 0 || speed > 10){
        printf("Invalid speed. Please enter speed between 1 to 10.\n");
        continue;
      }
      printf("Enter the direction (from -10 to 10): ");
      scanf("%d", &direction);
      if(direction < -10 || direction > 10){
        printf("Invalid direction. Please enter direction between -10 to 10.\n");
        continue;
      }
    }
    battery--;
    printf("\n");
  }
  printf("Battery has run out. Simulation ends.\n");

  return 0;
}