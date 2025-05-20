#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  float cm, m, km, inches, feet, miles;
  int choice;

  printf("Enter your choice:\n");
  printf("1. Convert cm to m\n");
  printf("2. Convert m to km\n");
  printf("3. Convert inches to feet\n");
  printf("4. Convert feet to miles\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the number of centimeters:");
      scanf("%f", &cm);
      m = cm * 0.01f;
      printf("The number of meters is: %.2f", m);
      break;
    case 2:
      printf("Enter the number of meters:");
      scanf("%f", &m);
      km = m * 1000.0f;
      printf("The number of kilometers is: %.2f", km);
      break;
    case 3:
      printf("Enter the number of inches:");
      scanf("%f", &inches);
      feet = inches * 0.08333f;
      printf("The number of feet is: %.2f", feet);
      break;
    case 4:
      printf("Enter the number of feet:");
      scanf("%f", &feet);
      miles = feet * 0.005488f;
      printf("The number of miles is: %.2f", miles);
      break;
    default:
      printf("Invalid choice");
  }

  return 0;
}
