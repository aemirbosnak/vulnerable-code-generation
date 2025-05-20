//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void moveForward(){
  printf("Moving Forward\n");
}

void moveBackward(){
  printf("Moving Backward\n");
}

void turnLeft(){
  printf("Turning Left\n");
}

void turnRight(){
  printf("Turning Right\n");
}

void stop(){
  printf("Stopping\n");
}

void wait(int seconds){
  sleep(seconds);
}

int main(){
  printf("Remote Control Vehicle Simulator\n");

  while(1){
    char input;
    printf("Enter Command (F for Forward, B for Backward, L for Left, R for Right, S for Stop): ");
    scanf("%c", &input);

    switch(input){
      case 'F':
      case 'f':
        moveForward();
        break;
      case 'B':
      case 'b':
        moveBackward();
        break;
      case 'L':
      case 'l':
        turnLeft();
        break;
      case 'R':
      case 'r':
        turnRight();
        break;
      case 'S':
      case 's':
        stop();
        break;
      default:
        printf("Invalid Command\n");
    }

    wait(1); //wait for 1 second before asking for new command
    fflush(stdin); //clear input buffer
  }

  return 0;
}