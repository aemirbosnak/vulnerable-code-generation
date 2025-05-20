//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
  // Declare variables to store user input
  char name[MAX_NAME_LEN];
  int age;

  // Print a happy message to start
  printf("Welcome to the Happy Birthday Program! 🎉\n");

  // Ask the user for their name
  printf("What's your name? 🤔\n");
  fgets(name, MAX_NAME_LEN, stdin);

  // Check if the user entered a valid name
  if (name[0] == '\0') {
    printf("Oops! 😔 You forgot to enter your name! 😔\n");
    return 1;
  }

  // Ask the user for their age
  printf("How old are you? 🤔\n");
  scanf("%d", &age);

  // Check if the user entered a valid age
  if (age < 0 || age > MAX_AGE) {
    printf("Oops! 😔 You entered an invalid age! 😔\n");
    return 1;
  }

  // Calculate the number of candles based on the user's age
  int candles = age;

  // Print a happy message based on the user's age
  switch (age) {
    case 18:
      printf("Happy 18th birthday! 🎂 You're finally legal! 😄\n");
      break;
    case 21:
      printf("Happy 21st birthday! 🎉 You're now old enough to drink! 🍻\n");
      break;
    case 30:
      printf("Happy 30th birthday! 🎊 You're now officially an adult! 😅\n");
      break;
    case 50:
      printf("Happy 50th birthday! 🎁 You're now halfway to retirement! 😅\n");
      break;
    default:
      printf("Happy birthday! 🎂 You're one year older and wiser! 😉\n");
      break;
  }

  // Print the number of candles on the birthday cake
  printf("You have %d candles on your birthday cake! 🎂\n", candles);

  // Print a happy message to end the program
  printf("Thanks for playing the Happy Birthday Program! 🎉\n");

  return 0;
}