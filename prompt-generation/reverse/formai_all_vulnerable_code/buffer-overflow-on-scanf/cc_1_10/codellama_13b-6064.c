//Code Llama-13B DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to convert temperature from Celsius to Fahrenheit
float c_to_f(float temp_c) {
  return (temp_c * 9/5) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
float f_to_c(float temp_f) {
  return (temp_f - 32) * 5/9;
}

// Function to convert temperature from Kelvin to Celsius
float k_to_c(float temp_k) {
  return temp_k - 273.15;
}

// Function to convert temperature from Celsius to Kelvin
float c_to_k(float temp_c) {
  return temp_c + 273.15;
}

int main() {
  float temp_c, temp_f, temp_k;

  // Get temperature in Celsius from user input
  printf("Enter temperature in Celsius: ");
  scanf("%f", &temp_c);

  // Convert temperature from Celsius to Fahrenheit
  temp_f = c_to_f(temp_c);
  printf("Temperature in Fahrenheit: %.2f\n", temp_f);

  // Convert temperature from Celsius to Kelvin
  temp_k = c_to_k(temp_c);
  printf("Temperature in Kelvin: %.2f\n", temp_k);

  // Get temperature in Fahrenheit from user input
  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &temp_f);

  // Convert temperature from Fahrenheit to Celsius
  temp_c = f_to_c(temp_f);
  printf("Temperature in Celsius: %.2f\n", temp_c);

  // Convert temperature from Fahrenheit to Kelvin
  temp_k = f_to_c(temp_f) + 273.15;
  printf("Temperature in Kelvin: %.2f\n", temp_k);

  // Get temperature in Kelvin from user input
  printf("Enter temperature in Kelvin: ");
  scanf("%f", &temp_k);

  // Convert temperature from Kelvin to Celsius
  temp_c = k_to_c(temp_k);
  printf("Temperature in Celsius: %.2f\n", temp_c);

  // Convert temperature from Kelvin to Fahrenheit
  temp_f = k_to_c(temp_k) * 9/5 + 32;
  printf("Temperature in Fahrenheit: %.2f\n", temp_f);

  return 0;
}