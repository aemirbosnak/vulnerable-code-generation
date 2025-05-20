//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include <stdio.h>

// Avast! Fair Montague, wherefore art thou Montague?
// Deny thy father and refuse thy name,
// Or, if thou wilt not, be but sworn my love,
// And I'll no longer be a Capulet.

// 'Tis but thy name that is my enemy;
// Thou art thyself, though not a Montague.
// What's Montague? It is nor hand, nor foot,
// Nor arm, nor face, nor any other part
// Belonging to a man. O, be some other name!

float celsius_to_fahrenheit(float celsius) {
  // 'Tis but thy form that is my foe.
  float fahrenheit = (celsius * 9 / 5) + 32;
  // My name, dear saint, is hateful to myself
  // Because it is an enemy to thee.
  return fahrenheit;
}

float fahrenheit_to_celsius(float fahrenheit) {
  // 'Tis but thy form that is my foe.
  float celsius = (fahrenheit - 32) * 5 / 9;
  // My name, dear saint, is hateful to myself
  // Because it is an enemy to thee.
  return celsius;
}

int main(void) {
  // Romeo, Romeo! Wherefore art thou Romeo?
  float temperature;

  // If thou art wedded, then take my vow,
  // I'll not importune thee, but depart.
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &temperature);

  // Convert the temperature to Fahrenheit.
  float fahrenheit = celsius_to_fahrenheit(temperature);

  // Print the temperature in Fahrenheit.
  printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);

  // Convert the temperature to Celsius.
  float celsius = fahrenheit_to_celsius(fahrenheit);

  // Print the temperature in Celsius.
  printf("The temperature in Celsius is: %.2f\n", celsius);

  // But soft! What light through yonder window breaks?
  // It is the east, and Juliet is the sun.
  return 0;
}