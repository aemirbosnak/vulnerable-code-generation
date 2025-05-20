//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  printf("Welcome to the Happy Haunted House Simulator!\n\n");

  int score = 0;
  int room = 1; // starting room
  
  while (room != 9) { // exit condition for winning the game
    printf("You are in Room %d.\n", room);
    printf("Choose a direction to move in (1-North, 2-South, 3-East, 4-West): ");
    int direction;
    scanf("%d", &direction);

    int rand_num = rand() % 3 + 1; // random number for spooky events
    switch (direction) {
      case 1:
        printf("You move North and ");
        if (rand_num == 1) {
          printf("find a friendly ghost! They give you a candy. ");
          score++;
        } else if (rand_num == 2) {
          printf("find a spooky skeleton. But don't worry, it's just a prop. ");
        } else {
          printf("hear a mysterious noise, but it's probably just the wind. ");
        }
        printf("Your score is now %d.\n", score);
        room++; // move to next room
        break;
      case 2:
        printf("You move South and ");
        if (rand_num == 1) {
          printf("see a room full of balloons! You pop some and feel better. ");
          score++;
        } else if (rand_num == 2) {
          printf("get scared by a fake spider. ");
        } else {
          printf("smell something delicious. It must be coming from the kitchen. ");
        }
        printf("Your score is now %d.\n", score);
        room++; // move to next room
        break;
      case 3:
        printf("You move East and ");
        if (rand_num == 1) {
          printf("find a magic wand! You wave it around and feel powerful. ");
          score++;
        } else if (rand_num == 2) {
          printf("find an old diary with spooky stories inside. ");
        } else {
          printf("find a postcard from someone who visited this house before. They had a great time. ");
        }
        printf("Your score is now %d.\n", score);
        room++; // move to next room
        break;
      case 4:
        printf("You move West and ");
        if (rand_num == 1) {
          printf("meet a friendly witch! They offer you a potion for good luck. ");
          score++;
        } else if (rand_num == 2) {
          printf("trip on a hidden step, but thankfully recover quickly. ");
        } else {
          printf("see a family portrait on the wall. They look like they were a happy bunch. ");
        }
        printf("Your score is now %d.\n", score);
        room++; // move to next room
        break;
      default:
        printf("Invalid input. Please choose a direction between 1-4.\n");
        break;
    }
  }

  printf("\nCongratulations, you've made it to the end of the Happy Haunted House! Your final score is %d.\n", score);

  return 0;
}