//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the weather grid
#define GRID_SIZE 10

// Define the different weather conditions
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define THUNDERSTORM 3

// Define the weather grid
int weather_grid[GRID_SIZE][GRID_SIZE];

// Initialize the weather grid with random weather conditions
void init_weather_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            weather_grid[i][j] = rand() % 4;
        }
    }
}

// Print the weather grid
void print_weather_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            switch (weather_grid[i][j]) {
                case SUNNY:
                    printf(".");
                    break;
                case CLOUDY:
                    printf("O");
                    break;
                case RAINY:
                    printf("*");
                    break;
                case THUNDERSTORM:
                    printf("X");
                    break;
            }
        }
        printf("\n");
    }
}

// Update the weather grid based on the current weather conditions
void update_weather_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            switch (weather_grid[i][j]) {
                case SUNNY:
                    // Do nothing
                    break;
                case CLOUDY:
                    if (rand() % 2 == 0) {
                        weather_grid[i][j] = RAINY;
                    }
                    break;
                case RAINY:
                    if (rand() % 2 == 0) {
                        weather_grid[i][j] = THUNDERSTORM;
                    } else {
                        weather_grid[i][j] = CLOUDY;
                    }
                    break;
                case THUNDERSTORM:
                    if (rand() % 2 == 0) {
                        weather_grid[i][j] = RAINY;
                    } else {
                        weather_grid[i][j] = CLOUDY;
                    }
                    break;
            }
        }
    }
}

// Simulate the weather for a given number of days
void simulate_weather(int days) {
    srand(time(NULL));
    init_weather_grid();
    for (int i = 0; i < days; i++) {
        print_weather_grid();
        update_weather_grid();
    }
}

int main() {
    int days;
    printf("Enter the number of days to simulate the weather: ");
    scanf("%d", &days);
    simulate_weather(days);
    return 0;
}