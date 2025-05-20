//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
// Time Travel Simulator
// Created by a mad scientist

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator with current time

  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("You are about to embark on a journey through time.\n");
  printf("You will be randomly transported to different eras in history.\n");
  printf("Are you ready? Press ENTER to begin!\n");
  getchar(); // wait for user to press ENTER

  while (1) { // repeat forever until user chooses to exit
    int year = rand() % 2001; // generate random year between 0 and 2000
    printf("\nTransporting to year %d...\n", year);

    if (year >= 2000) {
      printf("You have arrived in the future!\n");
    } else if (year >= 1900) {
      printf("You have arrived in the 20th century.\n");
      if (year >= 1960) {
        printf("You are now in the age of rock and roll!\n");
      }
    } else if (year >= 1800) {
      printf("You have arrived in the 19th century.\n");
    } else if (year >= 1600) {
      printf("You have arrived in the 17th century.\n");
    } else if (year >= 1400) {
      printf("You have arrived in the 15th century.\n");
    } else if (year >= 1200) {
      printf("You have arrived in the 13th century.\n");
    } else {
      printf("You have arrived in ancient times!\n");
    }

    printf("\nWhat would you like to do?\n");
    printf("1. Stay and explore this era\n");
    printf("2. Travel to a different year\n");
    printf("3. Exit the Time Travel Simulator\n");

    int choice;
    scanf("%d", &choice); // get user input

    if (choice == 1) {
      printf("You have chosen to explore this era.\n");
      // add code for exploring the era
    } else if (choice == 2) {
      printf("You have chosen to travel to a different year.\n");
    } else if (choice == 3) {
      printf("Thank you for using the Time Travel Simulator!\n");
      return 0;
    } else {
      printf("Invalid choice. Please try again.\n");
    }
  }
}