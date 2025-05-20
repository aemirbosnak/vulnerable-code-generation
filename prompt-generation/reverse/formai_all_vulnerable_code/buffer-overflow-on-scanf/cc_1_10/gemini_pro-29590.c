//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Declare a structure to hold the temperature data
typedef struct {
  float temperature;
  char unit;
} Temperature;

// Declare a function to print the temperature data
void printTemperature(Temperature temperature) {
  printf("The temperature is %.2f %c\n", temperature.temperature, temperature.unit);
}

// Declare a function to get the temperature data from the user
Temperature getTemperature() {
  Temperature temperature;
  printf("Enter the temperature: ");
  scanf("%f %c", &temperature.temperature, &temperature.unit);
  return temperature;
}

// Declare a function to convert the temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// Declare a function to convert the temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Declare a function to check if the temperature is within the safe range
int isSafeTemperature(Temperature temperature) {
  if (temperature.unit == 'C') {
    return temperature.temperature >= 10 && temperature.temperature <= 30;
  } else if (temperature.unit == 'F') {
    return temperature.temperature >= 50 && temperature.temperature <= 86;
  } else {
    return 0;
  }
}

// Declare a function to monitor the temperature
void monitorTemperature() {
  Temperature temperature = getTemperature();
  if (isSafeTemperature(temperature)) {
    printTemperature(temperature);
    printf("The temperature is safe.\n");
  } else {
    printf("The temperature is not safe.\n");
  }
}

// Declare a function to main
int main() {
  monitorTemperature();
  return 0;
}