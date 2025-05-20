//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
  // Let's get the party started! 🎉
  printf("Welcome to the craziest party ever! 🎉\n");

  // Ask for the guest's name 👋
  printf("What's your name, my dear? ");
  char name[MAX_NAME_LENGTH];
  scanf("%19s", name);
  printf("Ah, I see you're a %s! 😄\n", name);

  // Ask for the guest's age 🎂
  printf("Hey, how old are you? ");
  int age;
  scanf("%d", &age);
  if (age > MAX_AGE) {
    printf("Whoa, you're a young whippersnapper! 😅\n");
  } else if (age < 0) {
    printf("Uh, I think you might be a time traveler? 🕰️\n");
  } else {
    printf("Happy birthday, my dear! 🎂\n");
  }

  // Let's play a game 🎮
  printf("Let's play a game of 'Guess the Number'! 🎮\n");
  int guess = 0;
  int num = 10;
  do {
    printf("Guess the number: ");
    scanf("%d", &guess);
    if (guess > num) {
      printf("Too high! 😳\n");
    } else if (guess < num) {
      printf("Too low! 😠\n");
    } else {
      printf("You got it right! 🎉\n");
      break;
    }
  } while (guess != num);

  // Time to say goodbye 👋
  printf("It was a blast having you here! 🎉\n");
  return 0;
}