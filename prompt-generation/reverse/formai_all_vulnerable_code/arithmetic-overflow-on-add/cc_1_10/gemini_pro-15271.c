//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A few helpful constants
#define SUSPECT_COUNT 7
#define WEAPON_COUNT 6

// The names of our suspects
char *suspects[SUSPECT_COUNT] = {
  "Sherlock Holmes",
  "Dr. Watson",
  "Professor Moriarty",
  "Irene Adler",
  "Inspector Lestrade",
  "Mrs. Hudson",
  "Mycroft Holmes"
};

// The names of the weapons
char *weapons[WEAPON_COUNT] = {
  "Pistol",
  "Knife",
  "Poison",
  "Bludgeon",
  "Candlestick",
  "Rope"
};

// A 2D array to store the clues
int clues[SUSPECT_COUNT][WEAPON_COUNT];

// A function to initialize the clues array
void initializeClues() {
  for (int i = 0; i < SUSPECT_COUNT; i++) {
    for (int j = 0; j < WEAPON_COUNT; j++) {
      clues[i][j] = 0;
    }
  }
}

// A function to print the clues array
void printClues() {
  printf("Clues:\n");
  for (int i = 0; i < SUSPECT_COUNT; i++) {
    printf("%s:", suspects[i]);
    for (int j = 0; j < WEAPON_COUNT; j++) {
      printf(" %d", clues[i][j]);
    }
    printf("\n");
  }
}

// A function to find the suspect with the most clues
int findMostClues() {
  int maxClues = 0;
  int suspectIndex = -1;
  for (int i = 0; i < SUSPECT_COUNT; i++) {
    int totalClues = 0;
    for (int j = 0; j < WEAPON_COUNT; j++) {
      totalClues += clues[i][j];
    }
    if (totalClues > maxClues) {
      maxClues = totalClues;
      suspectIndex = i;
    }
  }
  return suspectIndex;
}

// A function to find the weapon with the most clues
int findMostCluesWeapon() {
  int maxClues = 0;
  int weaponIndex = -1;
  for (int j = 0; j < WEAPON_COUNT; j++) {
    int totalClues = 0;
    for (int i = 0; i < SUSPECT_COUNT; i++) {
      totalClues += clues[i][j];
    }
    if (totalClues > maxClues) {
      maxClues = totalClues;
      weaponIndex = j;
    }
  }
  return weaponIndex;
}

int main() {
  // Initialize the clues array
  initializeClues();

  // Get the clues from the user
  printf("Enter the clues (0 for no clue, 1 for a clue):\n");
  for (int i = 0; i < SUSPECT_COUNT; i++) {
    printf("%s:", suspects[i]);
    for (int j = 0; j < WEAPON_COUNT; j++) {
      scanf("%d", &clues[i][j]);
    }
  }

  // Print the clues array
  printClues();

  // Find the suspect with the most clues
  int suspectIndex = findMostClues();

  // Find the weapon with the most clues
  int weaponIndex = findMostCluesWeapon();

  // Print the solution
  printf("The most likely suspect is %s.\n", suspects[suspectIndex]);
  printf("The most likely weapon is %s.\n", weapons[weaponIndex]);

  return 0;
}