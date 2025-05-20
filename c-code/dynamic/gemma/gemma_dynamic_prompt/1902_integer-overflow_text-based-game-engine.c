#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  int score = 0;
  int level = 1;
  int health = 100;

  printf("Welcome to the Text-Based Game Engine!\n");

  while (health > 0 && level <= 10)
  {
    printf("Current score: %d\n", score);
    printf("Current level: %d\n", level);
    printf("Health: %d%\n", health);

    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        score++;
        level++;
        break;
      case 2:
        health--;
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  printf("Game over! Your final score is: %d\n", score);

  return 0;
}
