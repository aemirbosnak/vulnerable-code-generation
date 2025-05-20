//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int answer;
  int attempts;
  int guess;
  int lower, upper;
  char name[25];

  srand(time(NULL));

  lower = rand() % 50;
  upper = rand() % 50 + 50;

  printf("Welcome to the Random Math Problem Generator\n");
  printf("What is your name?\n");
  scanf("%s", name);
  printf("Hello %s\n", name);

  printf("Can you solve this equation for x:\n");

  int c1 = rand() % 20 + 1;
  int c2 = rand() % 20 + 1;

  printf("%dx + %d = %dx\n", c1, c2, c1 + c2);

  answer = c2 * -1;

  attempts = 0;

  do {
    printf("What is your guess for x, %s?\n", name);
    scanf("%d", &guess);

    attempts++;

    if (guess == answer){
      printf("Excellent work, %s!\n", name);
      printf("You solved the problem in %d attempts.\n", attempts);
      break;
    }
    else{
      printf("Sorry, %d is not correct. ");
      if (guess < answer){
        printf("The correct x value is higher\n");
      }
      else{
        printf("The correct x value is lower\n");
      }
    }
  } while (guess != answer);

  return 0;
}