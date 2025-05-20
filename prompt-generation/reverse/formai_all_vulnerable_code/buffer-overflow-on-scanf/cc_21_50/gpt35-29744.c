//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  //Initializing variables
  int batteryLevel = 100;
  int flyingTime = 0;
  int altitude = 0;
  int direction = 0;
  int speed = 0;
  char flightStatus[20] = "Landed";
  
  //Display welcome message
  printf("Welcome to C Drone Remote Control!\n\n");
  
  //Looping the program until the user chooses to exit
  while(1) {
    //Display menu
    printf("Options:\n");
    printf("1) Takeoff\n");
    printf("2) Ascend\n");
    printf("3) Descend\n");
    printf("4) Turn left\n");
    printf("5) Turn right\n");
    printf("6) Move forward\n");
    printf("7) Move backward\n");
    printf("8) Increase speed\n");
    printf("9) Decrease speed\n");
    printf("10) Land\n");
    printf("11) Exit\n\n");
    
    //Get user input
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    //Perform action based on user input
    switch(choice) {
      case 1:
        //Takeoff
        if(strcmp(flightStatus, "Landed") == 0) {
          printf("Drone has taken off.\n\n");
          strcpy(flightStatus, "In air");
        } else {
          printf("Drone is already in air.\n\n");
        }
        break;
      
      case 2:
        //Ascend
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter altitude (in meters): ");
          scanf("%d", &altitude);
          flyingTime += altitude / 10; //Calculate flying time based on altitude
          batteryLevel -= altitude / 10; //Reduce battery level based on flying time
          printf("Drone is ascending to %d meters.\n\n", altitude);
        } else {
          printf("Cannot ascend, drone is on the ground.\n\n");
        }
        break;
      
      case 3:
        //Descend
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter altitude (in meters): ");
          scanf("%d", &altitude);
          flyingTime += altitude / 10; //Calculate flying time based on altitude
          batteryLevel -= altitude / 10; //Reduce battery level based on flying time
          printf("Drone is descending to %d meters.\n\n", altitude);
        } else {
          printf("Cannot descend, drone is on the ground.\n\n");
        }
        break;
        
      case 4:
        //Turn left
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter direction (in degrees): ");
          scanf("%d", &direction);
          printf("Drone is turning left to %d degrees.\n\n", direction);
        } else {
          printf("Cannot turn left, drone is on the ground.\n\n");
        }
        break;
      
      case 5:
        //Turn right
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter direction (in degrees): ");
          scanf("%d", &direction);
          printf("Drone is turning right to %d degrees.\n\n", direction);
        } else {
          printf("Cannot turn right, drone is on the ground.\n\n");
        }
        break;
      
      case 6:
        //Move forward
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter speed (in meters per second): ");
          scanf("%d", &speed);
          printf("Drone is moving forward at %d meters per second.\n\n", speed);
        } else {
          printf("Cannot move forward, drone is on the ground.\n\n");
        }
        break;
      
      case 7:
        //Move backward
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter speed (in meters per second): ");
          scanf("%d", &speed);
          printf("Drone is moving backward at %d meters per second.\n\n", speed);
        } else {
          printf("Cannot move backward, drone is on the ground.\n\n");
        }
        break;
      
      case 8:
        //Increase speed
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter speed (in meters per second): ");
          scanf("%d", &speed);
          printf("Drone speed increased to %d meters per second.\n\n", speed);
        } else {
          printf("Cannot increase speed, drone is on the ground.\n\n");
        }
        break;
      
      case 9:
        //Decrease speed
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Enter speed (in meters per second): ");
          scanf("%d", &speed);
          printf("Drone speed decreased to %d meters per second.\n\n", speed);
        } else {
          printf("Cannot decrease speed, drone is on the ground.\n\n");
        }
        break;
      
      case 10:
        //Land
        if(strcmp(flightStatus, "In air") == 0) {
          printf("Drone has landed.\n\n");
          strcpy(flightStatus, "Landed");
        } else {
          printf("Drone is already on the ground.\n\n");
        }
        break;
      
      case 11:
        //Exit
        printf("Exiting program...\n\n");
        exit(0);
        break;
        
      default:
        //Invalid choice
        printf("Invalid choice, please try again.\n\n");
        break;
    }
    
    //Display current drone status
    printf("Drone Status:\n");
    printf("Battery Level: %d%%\n", batteryLevel);
    printf("Flying Time: %d seconds\n", flyingTime);
    printf("Altitude: %d meters\n", altitude);
    printf("Direction: %d degrees\n", direction);
    printf("Speed: %d meters per second\n", speed);
    printf("Flight Status: %s\n\n", flightStatus);
  }
  
  return 0;
}