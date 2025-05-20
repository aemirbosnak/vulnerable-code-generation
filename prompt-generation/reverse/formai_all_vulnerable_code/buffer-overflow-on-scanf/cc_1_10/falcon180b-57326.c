//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int choice;

  printf("Welcome to the Shape Shifting Adventure!\n");
  printf("You are a shape shifter with the ability to transform into any object.\n");
  printf("Guide me through this adventure.\n");

  int health = 100;
  int score = 0;

  while(health > 0) {
    system("clear");
    printf("You are in a dark forest. What do you want to do?\n");
    printf("1. Transform into a bird and fly away.\n");
    printf("2. Transform into a rabbit and hop around.\n");
    printf("3. Transform into a tree and blend in.\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("You transform into a bird and fly away.\n");
        score++;
        break;
      case 2:
        printf("You transform into a rabbit and hop around.\n");
        score++;
        break;
      case 3:
        printf("You transform into a tree and blend in.\n");
        score++;
        break;
      default:
        printf("Invalid choice. Lose 10 health points.\n");
        health -= 10;
    }

    if(score >= 3) {
      printf("Congratulations! You have completed the adventure with a score of %d.\n", score);
      return 0;
    }
  }

  printf("Game Over. Your score is %d.\n", score);
  return 0;
}