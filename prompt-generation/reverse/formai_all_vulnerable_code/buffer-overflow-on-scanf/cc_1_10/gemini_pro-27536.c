//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h> // For printf, scanf
#include <stdlib.h> // For malloc, free
#include <time.h> // For time

// A type to represent a weather simulation cell
typedef struct {
    double temperature; // in Celsius
    double humidity; // 0 to 1
    double windSpeed; // in meters per second
} WeatherCell;

// Generate a random weather cell
WeatherCell generateWeatherCell() {
    WeatherCell cell;
    cell.temperature = (double)(rand() % 40) - 20; // -20 to 20 degrees Celsius
    cell.humidity = (double)(rand() % 101) / 100; // 0 to 1
    cell.windSpeed = (double)(rand() % 20) / 2; // 0 to 10 meters per second
    return cell;
}

// Print a weather cell
void printWeatherCell(WeatherCell cell) {
    printf("Temperature: %.1f degrees Celsius\n", cell.temperature);
    printf("Humidity: %.2f\n", cell.humidity);
    printf("Wind speed: %.1f meters per second\n", cell.windSpeed);
    printf("\n");
}

// Simulate the weather for a given number of days
void simulateWeather(int numDays) {
    // Create a 10x10 grid of weather cells
    WeatherCell **grid = malloc(10 * sizeof(WeatherCell *));
    for (int i = 0; i < 10; i++) {
        grid[i] = malloc(10 * sizeof(WeatherCell));
    }

    // Initialize the grid with random weather cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = generateWeatherCell();
        }
    }

    // Simulate the weather for the given number of days
    for (int day = 0; day < numDays; day++) {
        // Update each weather cell based on its neighbors
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                WeatherCell cell = grid[i][j];

                // Calculate the average temperature of the neighboring cells
                double avgTemp = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (i + k >= 0 && i + k < 10 && j + l >= 0 && j + l < 10) {
                            avgTemp += grid[i + k][j + l].temperature;
                        }
                    }
                }
                avgTemp /= 9;

                // Update the cell's temperature based on the average temperature
                cell.temperature = 0.9 * cell.temperature + 0.1 * avgTemp;

                // Calculate the average humidity of the neighboring cells
                double avgHumidity = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (i + k >= 0 && i + k < 10 && j + l >= 0 && j + l < 10) {
                            avgHumidity += grid[i + k][j + l].humidity;
                        }
                    }
                }
                avgHumidity /= 9;

                // Update the cell's humidity based on the average humidity
                cell.humidity = 0.9 * cell.humidity + 0.1 * avgHumidity;

                // Calculate the average wind speed of the neighboring cells
                double avgWindSpeed = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (i + k >= 0 && i + k < 10 && j + l >= 0 && j + l < 10) {
                            avgWindSpeed += grid[i + k][j + l].windSpeed;
                        }
                    }
                }
                avgWindSpeed /= 9;

                // Update the cell's wind speed based on the average wind speed
                cell.windSpeed = 0.9 * cell.windSpeed + 0.1 * avgWindSpeed;

                // Update the cell in the grid
                grid[i][j] = cell;
            }
        }

        // Print the weather for the current day
        printf("Day %d:\n", day + 1);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printWeatherCell(grid[i][j]);
            }
        }
        printf("\n");
    }

    // Free the grid
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of days to simulate from the user
    int numDays;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &numDays);

    // Simulate the weather for the given number of days
    simulateWeather(numDays);

    return 0;
}