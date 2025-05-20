//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(0));

  printf("Welcome to the Time Travel Simulator!\n\n");

  // Ask for user's name
  printf("What is your name?\n");
  char name[50];
  scanf("%s", name);
  printf("\n");

  // Ask for user's desired year
  printf("Which year would you like to travel to, %s? Enter a year between 1900 and 2100.\n", name);
  int year;
  scanf("%d", &year);
  printf("\n");

  // Make sure user entered a valid year
  if (year < 1900 || year > 2100) {
    printf("Sorry %s, that year is not within the range.\n", name);
    return 0;
  }

  // Determine the difference in years between current year and desired year
  int currentYear = 2021;
  int difference = year - currentYear;

  // Determine if user is traveling to the future or the past
  if (difference > 0) {
    printf("%s, you are traveling %d years into the future!\n", name, difference);
  } else {
    printf("%s, you are traveling %d years into the past!\n", name, -difference);
  }

  // Generate a random event for the time travel trip
  int event = rand() % 5; // 0 - 4
  switch (event) {
    case 0:
      printf("\nWhile you were time traveling, you accidentally went too far and ended up in the year 3021. You were shocked to see that all humans now have robotic bodies. ");
      break;
    case 1:
      printf("\nYou traveled to the year 1950 and were amazed to see how much simpler things were back then. People didn't rely on the internet for everything and life seemed to be more relaxed. ");
      break;
    case 2:
      printf("\nYou traveled to the year 2100 and were surprised to see that everything was underwater. Apparently, global warming got to the planet faster than everyone thought.  ");
      break;
    case 3:
      printf("\nYou traveled to an alternate universe where dinosaurs never went extinct. You were chased by a pack of velociraptors but thankfully you had your time travel device on you.  ");
      break;
    case 4:
      printf("\nYou traveled to the year 2030 and were shocked to see that aliens had landed on the planet. Everyone was freaking out but the aliens seemed friendly and just wanted to say hi.  ");
      break;
  }

  // Display a closing message
  printf("\nThat was quite the time travel adventure, %s. Thank you for choosing the Time Travel Simulator!\n", name);

  return 0;
}