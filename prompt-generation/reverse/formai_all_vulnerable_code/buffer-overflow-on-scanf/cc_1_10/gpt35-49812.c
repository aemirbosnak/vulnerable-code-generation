//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
  int miliseconds = 1000 * seconds;

  clock_t start_time = clock();

  while (clock() < start_time + miliseconds) {
    continue;
  }
}

int main() {
  srand(time(NULL));

  int playerHealth = 100;
  int enemyHealth = 50;

  printf("\nWelcome to the Haunted House Simulator!\n");
  printf("You are the last survivor of your group of friends. \nYou heard a rumor of a treasure located in the basement of the Haunted House.\n");

  delay(3);

  printf("\nThe Haunted House is old and creeky. The door moans as it opens.\n");
  printf("You are in the entryway. You see a dusty room ahead of you and an old staircase leading up to the second floor.\n");

  int choice;
  printf("\nWhat do you want to do? (1:Go to the room, 2:Go upstairs): ");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("\nYou enter a room filled with spiderwebs. You see a chest in the corner with a keyhole. You need to find the key.\n");

    int randomKey = rand() % 10 + 1;
    int playerKey = 0;

    while (playerKey == 0) {
      int guess;

      printf("\nGuess where the key is (1-10): ");
      scanf("%d", &guess);

      if (guess == randomKey) {
        printf("\nCongratulations! You have found the key!\n");
        playerKey = 1;
      } else {
        playerHealth -= 5;
        printf("\nYou take damage from the spider bites. Your health is now %d.\n", playerHealth);
      }

      if (playerHealth <= 0) {
        printf("\nYou died from the spider bites. Game Over.\n");
        exit(0);
      }
    }

    printf("\nYou use the key to open the chest. You find a sword and a health potion.\n");
    printf("You equip the sword, and drink the potion. Your health is now 100.\n");
    playerHealth = 100;

    delay(3);

    printf("\nYou continue through the Haunted House. You hear a noise coming from upstairs.\n");
    printf("You climb the stairs to investigate.\n");

    delay(3);

    printf("\nYou enter a dark room. You can hear breathing but cannot see who or what it is.\n");
    printf("Suddenly, a monster appears in front of you! It is a powerful vampire with razor-sharp teeth.\n");
    printf("You draw your sword and prepare for a fight!\n");

    delay(3);

    while (playerHealth > 0 && enemyHealth > 0) {
      int playerAttack = rand() % 20 + 1;
      int enemyAttack = rand() % 15 + 1;

      printf("\nPlayer Health: %d Enemy Health: %d\n", playerHealth, enemyHealth);
      printf("What move do you want to make? (1:Attack, 2:Defend): ");
      scanf("%d", &choice);

      if (choice == 1) {
        printf("\nYou attack the vampire with your sword. You deal %d damage.\n", playerAttack);
        enemyHealth -= playerAttack;
      } else {
        printf("\nYou defend against the vampire's attack.\n");
      }

      if (enemyHealth <= 0) {
        printf("\nCongratulations! You have defeated the vampire! You have won the game!\n");
        exit(0);
      }

      printf("\nThe vampire attacks you with his sharp teeth. He deals %d damage.\n", enemyAttack);
      playerHealth -= enemyAttack;

      if (playerHealth <= 0) {
        printf("\nThe vampire has bitten and drained you! You have lost the game!\n");
        exit(0);
      }
    }

  } else {
    printf("\nYou climb the stairs to the second floor. You see a dusty door at the end of the hall.\n");
    printf("You walk towards it, and it creaks open.\n");

    delay(3);

    printf("\nYou enter a room filled with cobwebs. You find a health potion and drink it, restoring your health to 100.\n");

    playerHealth = 100;

    delay(3);

    printf("\nYou continue through the Haunted House. You hear a noise coming from upstairs.\n");
    printf("You climb the stairs to investigate.\n");

    delay(3);

    printf("\nYou enter a dark room. You can hear breathing but cannot see who or what it is.\n");
    printf("Suddenly, a monster appears in front of you! It is a powerful vampire with razor-sharp teeth.\n");
    printf("You draw your sword and prepare for a fight!\n");

    delay(3);

    while (playerHealth > 0 && enemyHealth > 0) {
      int playerAttack = rand() % 20 + 1;
      int enemyAttack = rand() % 15 + 1;

      printf("\nPlayer Health: %d Enemy Health: %d\n", playerHealth, enemyHealth);
      printf("What move do you want to make? (1:Attack, 2:Defend): ");
      scanf("%d", &choice);

      if (choice == 1) {
        printf("\nYou attack the vampire with your sword. You deal %d damage.\n", playerAttack);
        enemyHealth -= playerAttack;
      } else {
        printf("\nYou defend against the vampire's attack.\n");
      }

      if (enemyHealth <= 0) {
        printf("\nCongratulations! You have defeated the vampire! You have won the game!\n");
        exit(0);
      }

      printf("\nThe vampire attacks you with his sharp teeth. He deals %d damage.\n", enemyAttack);
      playerHealth -= enemyAttack;

      if (playerHealth <= 0) {
        printf("\nThe vampire has bitten and drained you! You have lost the game!\n");
        exit(0);
      }
    }
  }

  return 0;
}