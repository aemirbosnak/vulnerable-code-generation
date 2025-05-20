//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Romeo and Juliet characters
typedef struct {
  char *name;
  int x;
  int y;
} Character;

// Define the GPS navigation system
typedef struct {
  int width;
  int height;
  Character *romeo;
  Character *juliet;
} GPS;

// Create a new GPS navigation system
GPS *gps_new(int width, int height) {
  GPS *gps = malloc(sizeof(GPS));
  gps->width = width;
  gps->height = height;
  gps->romeo = malloc(sizeof(Character));
  gps->romeo->name = "Romeo";
  gps->romeo->x = 0;
  gps->romeo->y = 0;
  gps->juliet = malloc(sizeof(Character));
  gps->juliet->name = "Juliet";
  gps->juliet->x = width - 1;
  gps->juliet->y = height - 1;
  return gps;
}

// Free the GPS navigation system
void gps_free(GPS *gps) {
  free(gps->romeo);
  free(gps->juliet);
  free(gps);
}

// Update the position of a character
void character_update(Character *character, int dx, int dy) {
  character->x += dx;
  character->y += dy;
}

// Check if two characters have collided
int character_collided(Character *a, Character *b) {
  return a->x == b->x && a->y == b->y;
}

// Print the GPS navigation system
void gps_print(GPS *gps) {
  for (int y = 0; y < gps->height; y++) {
    for (int x = 0; x < gps->width; x++) {
      if (character_collided(gps->romeo, gps->juliet)) {
        printf("X");
      } else if (gps->romeo->x == x && gps->romeo->y == y) {
        printf("R");
      } else if (gps->juliet->x == x && gps->juliet->y == y) {
        printf("J");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new GPS navigation system
  int width, height;
  printf("Enter the GPS width: ");
  scanf("%d", &width);
  printf("Enter the GPS height: ");
  scanf("%d", &height);
  GPS *gps = gps_new(width, height);

  // Seed the random number generator
  srand(time(NULL));

  // Main game loop
  while (!character_collided(gps->romeo, gps->juliet)) {
    // Update the position of Romeo and Juliet
    character_update(gps->romeo, rand() % 3 - 1, rand() % 3 - 1);
    character_update(gps->juliet, rand() % 3 - 1, rand() % 3 - 1);

    // Print the GPS navigation system
    gps_print(gps);
  }

  // Romeo and Juliet have collided!
  printf("Romeo and Juliet have collided!\n");

  // Free the GPS navigation system
  gps_free(gps);

  return 0;
}