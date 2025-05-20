//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the weather conditions
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define STORMY 3

// Define the temperature range
#define MIN_TEMP -20
#define MAX_TEMP 40

// Define the humidity range
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

// Define the wind speed range
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 100

// Generate a random weather condition
int get_weather_condition() {
  int weather_condition = rand() % 4;
  return weather_condition;
}

// Generate a random temperature
int get_temperature() {
  int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
  return temperature;
}

// Generate a random humidity
int get_humidity() {
  int humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
  return humidity;
}

// Generate a random wind speed
int get_wind_speed() {
  int wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
  return wind_speed;
}

// Print the weather conditions
void print_weather_conditions(int weather_condition, int temperature, int humidity, int wind_speed) {
  switch (weather_condition) {
    case SUNNY:
      printf("The weather is sunny.\n");
      break;
    case CLOUDY:
      printf("The weather is cloudy.\n");
      break;
    case RAINY:
      printf("The weather is rainy.\n");
      break;
    case STORMY:
      printf("The weather is stormy.\n");
      break;
  }

  printf("The temperature is %d degrees Celsius.\n", temperature);
  printf("The humidity is %d%%.\n", humidity);
  printf("The wind speed is %d kilometers per hour.\n", wind_speed);
}

// Simulate the weather for a given number of days
void simulate_weather(int num_days) {
  for (int i = 0; i < num_days; i++) {
    int weather_condition = get_weather_condition();
    int temperature = get_temperature();
    int humidity = get_humidity();
    int wind_speed = get_wind_speed();

    print_weather_conditions(weather_condition, temperature, humidity, wind_speed);
  }
}

int main() {
  srand(time(NULL));

  int num_days;
  printf("Enter the number of days to simulate the weather: ");
  scanf("%d", &num_days);

  simulate_weather(num_days);

  return 0;
}