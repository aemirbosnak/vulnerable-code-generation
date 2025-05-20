//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
  char name[20];
  int age;
  char gender;
  double height, weight;

  // Name Validation
  printf("Enter your name: ");
  scanf("%s", name);
  for (int i = 0; name[i] != '\0'; i++) {
    if (!isalpha(name[i])) {
      printf("Error: Name should contain only letters.\n");
      exit(0);
    }
  }

  // Age Validation
  printf("Enter your age: ");
  scanf("%d", &age);
  if (age < 0 || age > 120) {
    printf("Error: Invalid age.\n");
    exit(0);
  }

  // Gender Validation
  printf("Enter your gender (M/F): ");
  scanf("%c", &gender);
  gender = toupper(gender);
  if (gender != 'M' && gender != 'F') {
    printf("Error: Invalid gender.\n");
    exit(0);
  }

  // Height Validation
  printf("Enter your height (in meters): ");
  scanf("%lf", &height);
  if (height < 0.5 || height > 3.0) {
    printf("Error: Invalid height.\n");
    exit(0);
  }

  // Weight Validation
  printf("Enter your weight (in kilograms): ");
  scanf("%lf", &weight);
  if (weight < 10 || weight > 300) {
    printf("Error: Invalid weight.\n");
    exit(0);
  }

  // Output
  printf("\nName: %s\n", name);
  printf("Age: %d\n", age);
  printf("Gender: %c\n", gender);
  printf("Height: %.2lf meters\n", height);
  printf("Weight: %.2lf kilograms\n", weight);

  return 0;
}