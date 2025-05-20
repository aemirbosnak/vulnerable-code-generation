//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define LOVE 100

int main() {
  char name[MAX_LENGTH];
  int age;
  int love_count = 0;

  printf("Hello, my dear! Please tell me your name and age.\n");
  fgets(name, MAX_LENGTH, stdin);
  sscanf(name, "%d", &age);

  if (age < 18 || age > 100) {
    printf("Oh my! It seems you are not within the age range of 18 to 100. "
           "Perhaps you are a timeless beauty or a young adventurer? "
           "Let us proceed with the love calculation, my dear.\n");
  } else {
    love_count = calculate_love(age);
  }

  if (love_count > LOVE) {
    printf("You are a love god/goddess! You have %d love points. "
           "Let us see... shall we calculate your love level again?\n",
           love_count);
  } else {
    printf("You are a love novice, my dear. You have %d love points. "
           "Fear not, for love is a journey and not a destination. "
           "Shall we calculate your love level again?\n", love_count);
  }

  return 0;
}

int calculate_love(int age) {
  int love = 0;

  if (age > 18 && age < 30) {
    love = 50;
  } else if (age > 30 && age < 50) {
    love = 75;
  } else if (age > 50 && age < 70) {
    love = 100;
  } else {
    love = 50;
  }

  return love;
}