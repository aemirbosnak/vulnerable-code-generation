//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
// Temperature Monitor Example Program

#include <stdio.h>
#include <stdlib.h>

// Structure to store temperature reading
typedef struct {
  float temperature;
  char unit;
} Temperature;

// Function to read temperature from user
Temperature read_temperature() {
  Temperature temp;
  printf("Enter temperature: ");
  scanf("%f", &temp.temperature);
  printf("Enter unit (C or F): ");
  scanf(" %c", &temp.unit);
  return temp;
}

// Function to convert temperature from Celsius to Fahrenheit
float convert_celsius_to_fahrenheit(float temperature) {
  return (temperature * 1.8) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float convert_fahrenheit_to_celsius(float temperature) {
  return (temperature - 32) / 1.8;
}

// Function to display temperature
void display_temperature(Temperature temp) {
  if (temp.unit == 'C') {
    printf("Temperature in Celsius: %.2f\n", temp.temperature);
  } else if (temp.unit == 'F') {
    printf("Temperature in Fahrenheit: %.2f\n", convert_celsius_to_fahrenheit(temp.temperature));
  } else {
    printf("Invalid unit\n");
  }
}

// Function to update temperature
void update_temperature(Temperature *temp) {
  Temperature new_temp = read_temperature();
  if (new_temp.unit == 'C') {
    temp->temperature = new_temp.temperature;
    temp->unit = 'C';
  } else if (new_temp.unit == 'F') {
    temp->temperature = convert_fahrenheit_to_celsius(new_temp.temperature);
    temp->unit = 'C';
  } else {
    printf("Invalid unit\n");
  }
}

int main() {
  Temperature temp;
  temp.temperature = 0;
  temp.unit = 'C';

  while (1) {
    display_temperature(temp);
    update_temperature(&temp);
  }

  return 0;
}