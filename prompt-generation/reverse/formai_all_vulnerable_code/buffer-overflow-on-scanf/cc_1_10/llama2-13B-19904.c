//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>

// Define constants for the elements of love
#define LOVE 100
#define KISS 50
#define HUG 25
#define DATE 10

// Define variables for the story
int love = 0;
int kisses = 0;
int hugs = 0;
int dates = 0;

// Function to increase love
void increase_love() {
  love += LOVE;
  printf("Your love has grown by %d points!\n", LOVE);
}

// Function to give a kiss
void give_kiss() {
  kisses += KISS;
  printf("You shared a romantic kiss and gained %d points!\n", KISS);
}

// Function to give a hug
void give_hug() {
  hugs += HUG;
  printf("You embraced each other and gained %d points!\n", HUG);
}

// Function to go on a date
void go_on_date() {
  dates += DATE;
  printf("You went on a lovely date and gained %d points!\n", DATE);
}

// Main program
int main() {
  // Start with a blank slate
  love = 0;
  kisses = 0;
  hugs = 0;
  dates = 0;

  // Ask the user for their choice
  printf("Welcome to the world of love! Would you like to:\n");
  printf("1. Increase your love\n");
  printf("2. Give a kiss\n");
  printf("3. Give a hug\n");
  printf("4. Go on a date\n");
  int choice;
  scanf("%d", &choice);

  // Handle the user's choice
  switch (choice) {
    case 1:
      increase_love();
      break;
    case 2:
      give_kiss();
      break;
    case 3:
      give_hug();
      break;
    case 4:
      go_on_date();
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
  }

  // Print the final values
  printf("Your love is worth %d points\n", love);
  printf("You have given %d kisses\n", kisses);
  printf("You have given %d hugs\n", hugs);
  printf("You have gone on %d dates\n", dates);

  return 0;
}