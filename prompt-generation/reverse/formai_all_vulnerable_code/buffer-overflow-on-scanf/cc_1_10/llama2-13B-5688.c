//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
  // Let's get this party started! 🎉
  printf("Welcome to the craziest birthday party ever! 🎂\n");

  // Ask the user for their name, but with a twist! 😜
  printf("What's your name, my dear? 👩‍👧‍👦\n");
  char name[MAX_NAME_LEN];
  scanf("%19s", name);

  // Now, let's get the age... or should I say, the age-OL? 😜
  printf("Oh my gosh, you're how old? 🤯\n");
  int age;
  scanf("%d", &age);

  // Check if the age is valid... or not. 😜
  if (age < 0 || age > MAX_AGE) {
    printf("Uh-oh! You're not old enough... or too old! 😳\n");
    return 1;
  }

  // Let's get this party started! 🎉
  printf("Happy birthday, %s! 🎂\n", name);

  // But wait, there's more! 😜
  // Generate a funny message based on the user's age.
  switch (age) {
    case 18:
      printf("You're legal now! Party like it's 1999! 🎉\n");
      break;
    case 21:
      printf("You're old enough to drink... or not. 🍻😜\n");
      break;
    case 30:
      printf("You're officially an adult... or a really old kid. 😜\n");
      break;
    case 50:
      printf("Happy midlife crisis! 😳🎉\n");
      break;
    case 100:
      printf("You're older than the internet! 😲\n");
      break;
    default:
      printf("You're... um... special. 😜\n");
      break;
  }

  // And finally, let's end this party with a bang! 🎉
  printf("Thanks for partying with us! 🎉\n");

  return 0;
}