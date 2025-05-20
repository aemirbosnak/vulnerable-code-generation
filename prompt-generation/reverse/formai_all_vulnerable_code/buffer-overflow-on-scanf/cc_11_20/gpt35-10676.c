//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int food = 10;
  int water = 5;
  int ammo = 50;
  int zombies = 10;
  int survivors = 5;
  int day = 1;
  int choice;

  printf("Welcome to the post-apocalyptic world!\n\n");
  printf("You are a survivor of the zombie apocalypse. Your goal is to survive as long as possible.\n\n");

  while (survivors > 0) {
    printf("Day %d\n", day);
    printf("Food: %d\n", food);
    printf("Water: %d\n", water);
    printf("Ammo: %d\n", ammo);
    printf("Zombies: %d\n", zombies);
    printf("Survivors: %d\n\n", survivors);

    printf("What do you want to do?\n");
    printf("1. Search for food\n");
    printf("2. Search for water\n");
    printf("3. Search for ammo\n");
    printf("4. Fight zombies\n");
    printf("5. Wait\n");
    printf("6. Quit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
      case 1:
        food += rand() % 6;
        printf("You found some food.\n");
        break;
      case 2:
        water += rand() % 6;
        printf("You found some water.\n");
        break;
      case 3:
        ammo += rand() % 21;
        printf("You found some ammo.\n");
        break;
      case 4:
        if (ammo > 0) {
          int shots = rand() % 11;
          zombies -= shots;
          ammo -= shots;
          printf("You killed %d zombies.\n", shots);
        } else {
          printf("You don't have any ammo left.\n");
        }
        break;
      case 5:
        printf("You waited for a day.\n");
        break;
      case 6:
        printf("Thanks for playing. Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
        break;
    }

    food -= survivors;
    water -= survivors * 2;
    zombies += rand() % 11;

    if (food < 0) {
      food = 0;
      survivors--;
      printf("You lost one survivor due to starvation.\n");
    }

    if (water < 0) {
      water = 0;
      survivors--;
      printf("You lost one survivor due to dehydration.\n");
    }

    if (zombies > survivors * 10) {
      printf("Game over. The zombies have overrun your safe house.\n");
      return 0;
    }

    day++;
  }

  printf("Congratulations! You survived for %d days!\n", day - 1);

  return 0;
}