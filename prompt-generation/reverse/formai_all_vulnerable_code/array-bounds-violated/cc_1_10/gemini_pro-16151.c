//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the weather types
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define SNOWY 3

// Define the number of weather types
#define NUM_WEATHER_TYPES 4

// Define the size of the weather grid
#define GRID_SIZE 10

// Create a weather grid
int weather_grid[GRID_SIZE][GRID_SIZE];

// Initialize the weather grid
void init_weather_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      // Set the weather at each grid point to a random value
      weather_grid[i][j] = rand() % NUM_WEATHER_TYPES;
    }
  }
}

// Update the weather grid
void update_weather_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      // Get the current weather at the grid point
      int current_weather = weather_grid[i][j];

      // Get the weather at the neighboring grid points
      int north_weather = weather_grid[i - 1][j];
      int south_weather = weather_grid[i + 1][j];
      int east_weather = weather_grid[i][j + 1];
      int west_weather = weather_grid[i][j - 1];

      // Update the current weather based on the neighboring weather
      if (current_weather == SUNNY) {
        if (north_weather == CLOUDY || south_weather == CLOUDY || east_weather == CLOUDY || west_weather == CLOUDY) {
          current_weather = CLOUDY;
        }
      } else if (current_weather == CLOUDY) {
        if (north_weather == RAINY || south_weather == RAINY || east_weather == RAINY || west_weather == RAINY) {
          current_weather = RAINY;
        }
      } else if (current_weather == RAINY) {
        if (north_weather == SNOWY || south_weather == SNOWY || east_weather == SNOWY || west_weather == SNOWY) {
          current_weather = SNOWY;
        }
      }

      // Set the updated weather at the grid point
      weather_grid[i][j] = current_weather;
    }
  }
}

// Print the weather grid
void print_weather_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      // Get the weather at the grid point
      int weather = weather_grid[i][j];

      // Print the weather
      switch (weather) {
        case SUNNY:
          printf("☀️");
          break;
        case CLOUDY:
          printf("☁️");
          break;
        case RAINY:
          printf("🌧️");
          break;
        case SNOWY:
          printf("🌨️");
          break;
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the weather grid
  init_weather_grid();

  // Update the weather grid
  update_weather_grid();

  // Print the weather grid
  print_weather_grid();

  return 0;
}