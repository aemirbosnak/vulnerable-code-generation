//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Welcome message
void welcome() {
  printf("\n====================================================\n");
  printf("Welcome to the Wasteland Fitness Tracker 3000!\n");
  printf("====================================================\n\n");
}

// Get user input
void get_input(char *name, int *age, int *weight) {
  printf("Enter your name, scavenger: ");
  scanf("%s", name);
  printf("Enter your age, survivor: ");
  scanf("%d", age);
  printf("Enter your weight, raider: ");
  scanf("%d", weight);
}

// Calculate daily calorie expenditure
int calculate_calories(int age, int weight) {
  // Formula: BMR = 66.47 + (13.75 * weight in kg) + (5.003 * height in cm) - (6.755 * age in years)
  return 66.47 + (13.75 * weight) + (5.003 * 170) - (6.755 * age);
}

// Generate random encounter
void encounter() {
  // Array of possible encounters
  char *encounters[] = {
    "A pack of vicious ghouls",
    "A group of armed raiders",
    "A horde of mutated rats",
    "A lone survivor in distress",
    "A cache of supplies"
  };

  // Generate a random encounter
  int encounter_index = rand() % 5;
  printf("\n%s\n", encounters[encounter_index]);

  // Handle encounter
  switch (encounter_index) {
    case 0: // Ghouls
      printf("You fend off the ghouls with your trusty crowbar.\n");
      break;
    case 1: // Raiders
      printf("You negotiate with the raiders and avoid a bloody confrontation.\n");
      break;
    case 2: // Rats
      printf("You exterminate the rats with your makeshift flamethrower.\n");
      break;
    case 3: // Survivor
      printf("You help the survivor and gain a new ally.\n");
      break;
    case 4: // Supplies
      printf("You scavenge the supplies and replenish your resources.\n");
      break;
  }
}

// Display fitness metrics
void display_metrics(char *name, int age, int weight, int calories) {
  printf("\n====================================================\n");
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
  printf("Weight: %d kg\n", weight);
  printf("Daily Calorie Expenditure: %d\n", calories);
  printf("====================================================\n\n");
}

// Main loop
int main() {
  // Seed random number generator
  srand(time(NULL));

  // Welcome message
  welcome();

  // Get user input
  char name[50];
  int age, weight;
  get_input(name, &age, &weight);

  // Calculate daily calorie expenditure
  int calories = calculate_calories(age, weight);

  // Display fitness metrics
  display_metrics(name, age, weight, calories);

  // Random encounter
  encounter();

  return 0;
}