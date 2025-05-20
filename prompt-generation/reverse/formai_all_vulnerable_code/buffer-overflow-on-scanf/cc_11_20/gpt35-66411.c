//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include <stdio.h>

int main() {
  printf("Hello, I am a happy C program and I will help you calculate your happiness level today!\n");

  int happyScore = 0;
  char answer[10];

  printf("\nDo you feel grateful today (yes/no)? ");
  scanf("%s", answer);
  if (answer[0] == 'y' || answer[0] == 'Y') {
    printf("Hooray, that's great! You get 10 happiness points!\n");
    happyScore += 10;
  } else {
    printf("Oh no, that's too bad. But don't worry, things will get better. No happiness points added.\n");
  }

  printf("\nDid you get enough sleep last night (yes/no)? ");
  scanf("%s", answer);
  if (answer[0] == 'y' || answer[0] == 'Y') {
    printf("Awesome, well-rested people are happy people. You get 5 happiness points!\n");
    happyScore += 5;
  } else {
    printf("Uh oh, get some sleep tonight! No happiness points added.\n");
  }

  printf("\nDid you eat a healthy breakfast this morning (yes/no)? ");
  scanf("%s", answer);
  if (answer[0] == 'y' || answer[0] == 'Y') {
    printf("Great choice, fueling your body with nutritious food gives you energy. You get 7 happiness points!\n");
    happyScore += 7;
  } else {
    printf("Oops, try to make a healthy meal next time! No happiness points added.\n");
  }

  printf("\nDid you do something fun today (yes/no)? ");
  scanf("%s", answer);
  if (answer[0] == 'y' || answer[0] == 'Y') {
    printf("Yay, fun should always be a part of your day. You get 8 happiness points!\n");
    happyScore += 8;
  } else {
    printf("That's too bad, but don't worry, you can always plan something fun for the future. No happiness points added.\n");
  }

  printf("\nDid you exercise today (yes/no)? ");
  scanf("%s", answer);
  if (answer[0] == 'y' || answer[0] == 'Y') {
    printf("Wow, you're killing it! Exercise releases endorphins and makes you happy. You get 9 happiness points!\n");
    happyScore += 9;
  } else {
    printf("It's okay, just make sure to get some movement in your day. No happiness points added.\n");
  }

  printf("\nYour happiness level today is %d out of 39 possible points. Keep doing the things that make you happy!\n", happyScore);

  return 0;
}