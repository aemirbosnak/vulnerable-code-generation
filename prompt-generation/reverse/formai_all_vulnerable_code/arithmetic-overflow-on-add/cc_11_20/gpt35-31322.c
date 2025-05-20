//FormAI DATASET v1.0 Category: Funny ; Style: brave
#include <stdio.h>

int main()
{
  printf("Welcome to the Brave Warrior's Quest!\n");
  printf("Your mission is to defeat the enemy army and save your people!\n\n");

  int warriors = 20;
  int enemy_warriors = 25;
  int gold = 50;
  int victory = 0;

  printf("You have %d warriors and %d gold coins.\n", warriors, gold);
  printf("The enemy has %d warriors.\n\n", enemy_warriors);

  printf("What would you like to do?\n\n");
  printf("1. Attack the enemy\n");
  printf("2. Hire more warriors\n");
  printf("3. Buy weapons\n");

  int choice;
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("You choose to attack the enemy!\n");
      printf("You charge into battle with your %d brave warriors.\n", warriors);

      while(warriors > 0 && enemy_warriors > 0) {
        int your_attack = warriors * 2;
        int enemy_attack = enemy_warriors * 3;

        printf("You attack the enemy with %d damage.\n", your_attack);
        printf("The enemy counter-attacks with %d damage.\n", enemy_attack);

        warriors -= enemy_attack / 4;
        enemy_warriors -= your_attack / 2;

        printf("You have %d warriors left.\n", warriors);
        printf("The enemy has %d warriors left.\n\n", enemy_warriors);
      }

      if(warriors > 0 && enemy_warriors <= 0) {
        printf("You have defeated the enemy!!!!\n");
        victory = 1;
      } else {
        printf("Your warriors have been defeated... You lose.\n");
      }

      break;

    case 2:
      printf("You choose to hire more warriors!\n");
      printf("Hiring new warriors costs 10 gold coins each.\n");

      int new_warriors;
      printf("How many warriors would you like to hire?\n");
      scanf("%d", &new_warriors);

      if(gold >= new_warriors * 10) {
        warriors += new_warriors;
        gold -= new_warriors * 10;

        printf("You have %d warriors and %d gold coins left.\n", warriors, gold);
      } else {
        printf("You don't have enough gold to hire that many warriors.\n");
      }

      break;

    case 3:
      printf("You choose to buy weapons!\n");
      printf("Each weapon costs 5 gold coins.\n");

      int new_weapons;
      printf("How many weapons would you like to buy?\n");
      scanf("%d", &new_weapons);

      if(gold >= new_weapons * 5) {
        warriors += new_weapons * 2;
        gold -= new_weapons * 5;

        printf("Your warriors are now equipped with %d new weapons!\n", new_weapons);
        printf("You have %d warriors and %d gold coins left.\n", warriors, gold);
      } else {
        printf("You don't have enough gold to buy that many weapons.\n");
      }

      break;
  }

  if(victory) {
    printf("\n\nCONGRATULATIONS! You have saved your people and earned your place in history as a brave warrior!\n");
  } else {
    printf("\n\nBetter luck next time, warrior.\n");
  }

  return 0;
}