//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <crypt.h>

#define MAX_NAME_LEN 20
#define MAX_PASSWORD_LEN 20

int main() {
  // Declare variables to store user input
  char name[MAX_NAME_LEN];
  char password[MAX_PASSWORD_LEN];
  int age;

  // Print a funny intro message
  printf("Welcome to the land of coders, where errors are just minor setbacks!\n");

  // Get the user's name
  printf("What's your name, my young Padawan? ");
  fgets(name, MAX_NAME_LEN, stdin);

  // Check if the name is too long
  if (strlen(name) > MAX_NAME_LEN) {
    printf("Whoa there, partner! Your name is too long. Try again, but this time, be brief.\n");
    return 1;
  }

  // Get the user's password
  printf("Now, for your password, I must warn you... \n");
  fgets(password, MAX_PASSWORD_LEN, stdin);

  // Check if the password is too short
  if (strlen(password) < 8) {
    printf("Uh-oh, your password is too short! Make it longer, or the ninjas will find you!\n");
    return 1;
  }

  // Check if the password is too long
  if (strlen(password) > MAX_PASSWORD_LEN) {
    printf("Whoa, slow down there, cowboy! Your password is too long. Try again, but this time, be brief.\n");
    return 1;
  }

  // Check if the user entered a valid age
  printf("Now, for your age... \n");
  scanf("%d", &age);

  // Check if the user entered a valid age
  if (age < 18 || age > 100) {
    printf("Uh-oh, you must be at least 18 or no more than 100 years old. Better luck next time, young Padawan!\n");
    return 1;
  }

  // Print a success message
  printf("You have successfully entered your name, password, and age! Now, go forth and code, young developer!\n");

  // Print a funny exit message
  printf("May the code be with you, always!\n");

  return 0;
}