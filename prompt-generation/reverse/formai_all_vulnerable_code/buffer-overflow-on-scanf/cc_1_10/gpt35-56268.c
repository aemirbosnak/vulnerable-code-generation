//FormAI DATASET v1.0 Category: Robot movement control ; Style: excited
#include <stdio.h>

int main() {

  printf("Welcome to the Robot Movement Control Program!\n");
  printf("Are you ready to see your robot in action? (Y/N)\n");

  char answer;
  scanf("%c", &answer);

  if(answer == 'Y') {

    printf("Let's do this!\n");
    printf("Please enter the number of moves you want your robot to make:\n");

    int numOfMoves;
    scanf("%d", &numOfMoves);

    // Movement control loop
    for(int i=0; i<numOfMoves; i++) {
      printf("Move %d: ", (i+1));

      // Randomly select a move
      int move = rand() % 4 + 1;

      switch(move) {
        case 1:
          printf("Robot moves forward.\n");
          break;
        case 2:
          printf("Robot moves backward.\n");
          break;
        case 3:
          printf("Robot turns left.\n");
          break;
        case 4:
          printf("Robot turns right.\n");
          break;
        default:
          printf("Unexpected error occurred.\n");
          break;
      }
    }

    printf("Mission complete! Your robot has successfully executed %d moves.\n", numOfMoves);
    printf("Thank you for using our program. Have a great day!\n");

    return 0;
  }
  else if(answer == 'N') {
    printf("Okay, we will meet again when you are ready.\n");
  }
  else {
    printf("Invalid input. Please try again.\n");
  }

  return 0;
}