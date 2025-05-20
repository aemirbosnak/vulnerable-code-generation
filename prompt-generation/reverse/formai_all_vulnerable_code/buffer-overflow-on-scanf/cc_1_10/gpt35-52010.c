//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char name[20];
  int age, year, month, day;
  int fortune, love, tragedy;

  printf("Welcome to the Fortune Teller, my friend.\n");
  printf("I am the great Romeo, and I can see your future.\n");

  printf("First, may I know your name? ");
  scanf("%s", name);
  printf("Nice to meet you, %s.\n", name);

  printf("Now, how old are you? ");
  scanf("%d", &age);
  printf("You are still young, %d years old.\n", age);

  printf("What is your birthdate?\n");
  printf("Year: ");
  scanf("%d", &year);
  printf("Month (1-12): ");
  scanf("%d", &month);
  printf("Day: ");
  scanf("%d", &day);
  printf("Ah, you were born on %d/%d/%d.\n", month, day, year);

  // calculate the fortune, love, and tragedy level
  srand(time(NULL));
  fortune = rand() % 101;
  love = rand() % 101;
  tragedy = rand() % 101;

  printf("\nThank you for your inputs, %s.\n", name);
  printf("Now I will predict your future...\n");

  printf("Your fortune level is %d%%.\n", fortune);
  if (fortune > 50) {
    printf("You will have a bright future, my friend.\n");
  } else {
    printf("You should be careful, danger is lurking around you.\n");
  }

  printf("Your love level is %d%%.\n", love);
  if (love > 50) {
    printf("You will find true love, %s.\n", name);
  } else {
    printf("You are destined to be alone, my dear.\n");
  }

  printf("Your tragedy level is %d%%.\n", tragedy);
  if (tragedy > 50) {
    printf("You will face great sorrow in your life, my friend.\n");
  } else {
    printf("You will live a peaceful life, free from tragedies.\n");
  }

  printf("\nThank you for visiting the Fortune Teller, %s.\n", name);
  printf("May fate be kind to you.\n");

  return 0;
}