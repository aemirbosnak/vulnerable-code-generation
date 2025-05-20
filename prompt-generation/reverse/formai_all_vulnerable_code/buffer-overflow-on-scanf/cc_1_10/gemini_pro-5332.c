//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int age;
  int height;
  int weight;
  int steps;
  int calories;
} Person;

int main() {
  Person person;
  person.name = "Sir Reginald";
  person.age = 25;
  person.height = 60;
  person.weight = 180;
  person.steps = 0;
  person.calories = 0;

  while (1) {
    int choice;
    printf("\nWhat wouldst thou like to do? (1) Walk, (2) Eat, (3) Sleep, or (4) Quit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("How many steps wouldst thou like to walk?\n");
        int steps;
        scanf("%d", &steps);
        person.steps += steps;
        person.calories += steps * 0.05;
        break;
      case 2:
        printf("What wouldst thou like to eat?\n");
        char food[100];
        scanf("%s", food);
        person.calories += 100;
        break;
      case 3:
        printf("Thou hast slumbered for 8 hours. Thy body is refreshed.\n");
        person.calories -= 500;
        break;
      case 4:
        printf("Farewell, %s. May thy journey be filled with health and strength.\n", person.name);
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %d\n", person.height);
    printf("Weight: %d\n", person.weight);
    printf("Steps: %d\n", person.steps);
    printf("Calories: %d\n", person.calories);
  }

  return 0;
}