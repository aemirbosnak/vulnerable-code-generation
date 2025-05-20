//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert temperature from Celsius to Fahrenheit
float c_to_f(float temp_c) {
  return (temp_c * 9.0 / 5.0) + 32.0;
}

// Function to convert temperature from Fahrenheit to Celsius
float f_to_c(float temp_f) {
  return (temp_f - 32.0) * 5.0 / 9.0;
}

// Function to convert length from meters to feet
float m_to_ft(float length_m) {
  return length_m * 3.28084;
}

// Function to convert length from feet to meters
float ft_to_m(float length_ft) {
  return length_ft / 3.28084;
}

// Function to convert weight from kilograms to pounds
float kg_to_lb(float weight_kg) {
  return weight_kg * 2.20462;
}

// Function to convert weight from pounds to kilograms
float lb_to_kg(float weight_lb) {
  return weight_lb / 2.20462;
}

int main() {
  // Variables to store user input
  float temp_c, temp_f, length_m, length_ft, weight_kg, weight_lb;

  // Print welcome message
  printf("Welcome to the Unit Converter!\n");

  // Ask user for input and convert temperature from Celsius to Fahrenheit
  printf("Enter a temperature in Celsius: ");
  scanf("%f", &temp_c);
  temp_f = c_to_f(temp_c);
  printf("The temperature in Fahrenheit is: %f\n", temp_f);

  // Ask user for input and convert length from meters to feet
  printf("Enter a length in meters: ");
  scanf("%f", &length_m);
  length_ft = m_to_ft(length_m);
  printf("The length in feet is: %f\n", length_ft);

  // Ask user for input and convert weight from kilograms to pounds
  printf("Enter a weight in kilograms: ");
  scanf("%f", &weight_kg);
  weight_lb = kg_to_lb(weight_kg);
  printf("The weight in pounds is: %f\n", weight_lb);

  return 0;
}