//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CONFIG_FILE "weather.conf"

// Weather data structure
typedef struct {
  float temperature;
  float humidity;
  float wind_speed;
  float wind_direction;
  float rainfall;
} weather_data;

// Weather simulation function
void simulate_weather(weather_data *weather, float time_step) {
  // Update temperature
  weather->temperature += (rand() % 10 - 5) * time_step;

  // Update humidity
  weather->humidity += (rand() % 10 - 5) * time_step;

  // Update wind speed
  weather->wind_speed += (rand() % 10 - 5) * time_step;

  // Update wind direction
  weather->wind_direction += (rand() % 360) * time_step;

  // Update rainfall
  weather->rainfall += (rand() % 10) * time_step;
}

// Print weather data
void print_weather(weather_data *weather) {
  printf("Temperature: %.1f degrees Celsius\n", weather->temperature);
  printf("Humidity: %.1f%%\n", weather->humidity);
  printf("Wind speed: %.1f m/s\n", weather->wind_speed);
  printf("Wind direction: %.1f degrees\n", weather->wind_direction);
  printf("Rainfall: %.1f mm\n", weather->rainfall);
}

// Load configuration from file
void load_config(char *filename, float *time_step, int *num_iterations) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening configuration file\n");
    exit(1);
  }
  fscanf(fp, "%f", time_step);
  fscanf(fp, "%d", num_iterations);
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  // Load configuration
  float time_step;
  int num_iterations;
  load_config(CONFIG_FILE, &time_step, &num_iterations);

  // Initialize weather data
  weather_data weather;
  weather.temperature = 20.0;
  weather.humidity = 50.0;
  weather.wind_speed = 5.0;
  weather.wind_direction = 0.0;
  weather.rainfall = 0.0;

  // Simulate weather
  for (int i = 0; i < num_iterations; i++) {
    simulate_weather(&weather, time_step);
    print_weather(&weather);
  }

  return 0;
}