//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {
  char name[50];
  int age;
  float height;
  bool valid_input = false;

  while (!valid_input) {
    printf("Please enter your name: ");
    fgets(name, 50, stdin);
    
    // Remove newline character from input
    name[strcspn(name, "\n")] = 0;

    // Check if name contains only letters
    for (int i = 0; i < strlen(name); i++) {
      if (!isalpha(name[i])) {
        printf("Invalid name. Please try again.\n");
        valid_input = false;
        break;
      }
      valid_input = true;
    }
  }

  valid_input = false;

  while (!valid_input) {
    printf("Please enter your age: ");
    int status = scanf("%d", &age);

    if (status != 1 || age < 0 || age > 120) {
      printf("Invalid age. Age should be between 0 and 120.\n");
    } else {
      valid_input = true;
    }

    // Clear input buffer
    while (getchar() != '\n') {
      continue;
    }
  }

  valid_input = false;

  while (!valid_input) {
    printf("Please enter your height in meters: ");
    int status = scanf("%f", &height);

    if (status != 1 || height < 0 || height > 3) {
      printf("Invalid height. Height should be between 0 and 3 meters.\n");
    } else {
      valid_input = true;
    }

    // Clear input buffer
    while (getchar() != '\n') {
      continue;
    }
  }

  printf("Thank you for submitting your information!\n");
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
  printf("Height: %.2f meters\n", height);

  return 0;
}