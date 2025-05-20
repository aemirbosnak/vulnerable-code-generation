//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
  // Let's start with a friendly greeting! 😊
  printf("Hello, world! 🌎\n");

  // Now, let's ask the user for their name. 🤔
  printf("What's your name, my dear? 👦🏼👩🏻\n");
  char name[MAX_NAME_LENGTH];
  scanf("%19s", name);

  // Oops, it looks like the user entered more than 20 characters! 😱
  if (strlen(name) > MAX_NAME_LENGTH) {
    printf("Whoa, slow down there! 😅 Your name is too long, my friend. 😞\n");
    return 1;
  }

  // Next, let's ask the user for their age. 🤔
  printf("How old are you, my young %s? 🎉\n", name);
  int age;
  scanf("%d", &age);

  // Oh no, it looks like the user entered a negative age! 😱
  if (age < 0) {
    printf("Uh-oh, that's not a valid age! 😳 You must be at least 0 years old. 😅\n");
    return 1;
  }

  // Now, let's do some calculations! 🤔
  int years_old = age;
  int hours_old = years_old * 365 * 24;
  int seconds_old = hours_old * 3600;

  // Oops, it looks like the user entered a really big age! 😱
  if (hours_old > MAX_AGE) {
    printf("Whoa, that's a loooong time! 😳 You must be at least %d years old. 😅\n", MAX_AGE);
    return 1;
  }

  // Finally, let's print out some fun facts! 🤓
  printf("You are %d years old.\n", years_old);
  printf("You are %d hours old.\n", hours_old);
  printf("You are %d seconds old.\n", seconds_old);

  return 0;
}