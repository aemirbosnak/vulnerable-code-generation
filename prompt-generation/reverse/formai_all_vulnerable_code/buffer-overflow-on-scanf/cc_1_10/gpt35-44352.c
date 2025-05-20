//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice, health = 100, treasure = 0, aliens = 0;
  char name[20];

  srand(time(NULL));

  printf("*** WELCOME ABOARD THE SHIP ***\n");
  printf("What is your name? ");
  scanf("%s", name);

  printf("\n\nCaptain %s, your mission is to explore the depths of the universe and discover new worlds. You'll face challenges along the way, but I trust you'll succeed.\n\n", name);

  while(health > 0) {
    printf("*****************************************\n");
    printf("You are currently at 10,000 light years away from the Earth. You have %d health and %d treasures. What would you like to do?\n", health, treasure);
    printf("1. Explore the planet\n");
    printf("2. Fight aliens\n");
    printf("3. Find treasure\n");
    printf("4. Exit the ship\n");
    printf("*****************************************\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("You spend the next few hours exploring the planet. You discover an abundance of unique plant-life, but nothing of significant value.\n");
        break;
      case 2:
        aliens = rand() % 10;

        printf("You encounter %d aliens and prepare to fight.\n", aliens);

        if(aliens > 5) {
          printf("You were defeated by the aliens! Game over.\n");
          exit(0);
        }
        else {
          health -= (aliens * 10);
          treasure += (aliens * 5);

          printf("You defeated the aliens and earned %d treasures. However, you lost %d health points in the process.\n", (aliens * 5), (aliens * 10));
        }
        break;
      case 3:
        treasure += rand() % 50 + 10;
        printf("You discover a hidden treasure on the planet! You add %d treasures to your collection.\n", treasure);
        break;
      case 4:
        printf("You exit the ship and float into the abyss of space. You were never seen or heard from again. Game over.\n");
        exit(0);
      default:
        printf("Invalid choice. Choose again.\n");
        continue;
    }

    health -= 10;

    if(health <= 0) {
      printf("You have no remaining health. Game over.\n");
      exit(0);
    }
  }

  printf("Congratulations! You completed your mission and returned back to Earth with %d treasures.\n", treasure);

  return 0;
}