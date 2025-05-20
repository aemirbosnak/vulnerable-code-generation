//FormAI DATASET v1.0 Category: Robot movement control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to control the movement of the robot
void *robotMovement(void *arg) {
  while(1) {
    printf("Robot is moving forward...\n");
    sleep(1);
    printf("Robot is turning left...\n");
    sleep(1);
    printf("Robot is moving forward...\n");
    sleep(1);
    printf("Robot is turning right...\n");
    sleep(1);
  }
  return NULL;
}

// Function to control the stop and start of the robot
void *robotControl(void *arg) {
  char control;
  while(1) {
    printf("Enter 's' to stop the robot or 'c' to continue moving: \n");
    scanf("%c", &control);
    if(control == 's') {
      printf("Robot has been stopped.\n");
      // stop robotMovement thread
    } else if(control == 'c') {
      printf("Robot is continuing its movement.\n");
      // start robotMovement thread if it was stopped
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }
  return NULL;
}

int main(void) {
  // Creating thread objects
  pthread_t threadRobotMovement, threadRobotControl;

  // Creating threads
  pthread_create(&threadRobotMovement, NULL, &robotMovement, NULL);
  pthread_create(&threadRobotControl, NULL, &robotControl, NULL);

  // Waiting for threads to join
  pthread_join(threadRobotMovement, NULL);
  pthread_join(threadRobotControl, NULL);

  return 0;
}