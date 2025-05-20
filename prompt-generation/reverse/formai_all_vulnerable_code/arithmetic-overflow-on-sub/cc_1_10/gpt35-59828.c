//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number within a specified range
int getRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

int main() {
  // Set the seed for the random number generator
  srand(time(NULL));

  // Welcome message
  printf("Welcome to the Automated Fortune Teller!\n\n");

  // Get the user's name
  char name[20];
  printf("What is your name? ");
  scanf("%s", name);

  // Get the user's birth year
  int birthYear;
  printf("What year were you born? ");
  scanf("%d", &birthYear);

  // Calculate the user's age
  int age = 2021 - birthYear;

  // Generate a random fortune number
  int fortuneNumber = getRandomNumber(1, 5);

  // Choose a fortune based on the random number
  char fortune[100];
  switch (fortuneNumber) {
    case 1:
      sprintf(fortune, "%s, you will soon receive unexpected wealth!", name);
      break;
    case 2:
      sprintf(fortune, "%s, you will meet your true love in the near future!", name);
      break;
    case 3:
      sprintf(fortune, "%s, you will travel to a far-off land and have a life-changing experience!", name);
      break;
    case 4:
      sprintf(fortune, "%s, you will be blessed with good health and long life!", name);
      break;
    case 5:
      sprintf(fortune, "%s, you will be successful in all of your endeavors!", name);
      break;
    default:
      sprintf(fortune, "Oops! Something went wrong. Try again later.");
      break;
  }

  // Display the user's fortune
  printf("\n%s's fortune:\n\n", name);
  printf("\"%s\"\n\n", fortune);

  // Display some additional information based on the user's age
  if (age < 18) {
    printf("You are under 18 years old. Please seek parental guidance before taking any major decisions.\n");
  } else if (age >= 18 && age < 30) {
    printf("You are in your prime. Now is the time to take risks and chase your dreams!\n");
  } else if (age >= 30 && age < 50) {
    printf("You have reached the peak of your career. Keep up the good work!\n");
  } else {
    printf("You have a wealth of experience and wisdom. Use it to guide those around you.\n");
  }

  return 0;
}