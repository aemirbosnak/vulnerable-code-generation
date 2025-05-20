//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int health = 100;
int gold = 0;
char name[20];

void print_status()
{
  printf("\nPlayer Status:\n");
  printf("-----------------------\n");
  printf("Name: %s\n", name);
  printf("Gold: %d\n", gold);
  printf("Health: %d\n", health);
  printf("-----------------------\n");
}

int main()
{
  srand(time(NULL));
  printf("\nWelcome to the Medieval Adventure Game!\n");
  printf("Please enter your name: ");
  scanf("%s", &name);
  printf("\nWelcome, %s!\n", name);
  printf("Are you ready to embark on an adventure through the medieval world?\n");
  printf("You start off with 100 health and 0 gold.\n");

  printf("\nYou find yourself at the town square. You see a sign that says 'Adventurers Wanted!'\n");

  int choice;
  printf("\nWhat do you want to do?\n");
  printf("1. Sign up for adventure\n");
  printf("2. Explore the town\n");
  scanf("%d", &choice);

  while (choice != 1 && choice != 2)
  {
    printf("Invalid choice, please try again\n");
    scanf("%d", &choice);
  }

  if (choice == 1)
  {
    printf("\nYou head to the adventurer's guild to sign up for the quest.\n");
    printf("You meet the guild master who tells you about the quest.\n");
    printf("He tells you that there is a dragon terrorizing the nearby town. Your job is to defeat the dragon and save the town.\n");
    printf("He also tells you that you will be rewarded with 500 gold coins for completing the quest.\n");

    printf("\nAre you ready to embark on the quest?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &choice);

    while (choice != 1 && choice != 2)
    {
      printf("Invalid choice, please try again\n");
      scanf("%d", &choice);
    }

    if (choice == 1)
    {
      printf("\nYou set off on your adventure towards the town where the dragon is located.\n");

      // Random encounter
      int encounter = rand() % 3 + 1;
      if (encounter == 1)
      {
        printf("\nYou encounter a bandit on your way to the town.\n");
        printf("He demands you give him all your gold or he will attack you.\n");

        printf("\nWhat do you want to do?\n");
        printf("1. Give him your gold\n");
        printf("2. Refuse and fight him\n");
        scanf("%d", &choice);

        while (choice != 1 && choice != 2)
        {
          printf("Invalid choice, please try again\n");
          scanf("%d", &choice);
        }

        if (choice == 1)
        {
          printf("\nYou hand over all your gold to the bandit and he flees.\n");
          gold = 0;
        }
        else
        {
          printf("\nYou prepare to fight the bandit.\n");
          printf("You win the battle and find a potion on the bandit's body that restores 50 health.\n");
          health += 50;
        }
      }

      printf("\nYou arrive at the town and see the dragon roosting on top of a tower.\n");
      printf("You prepare to fight the dragon.\n");

      // Dragon battle
      int dragon_hp = 100;
      while (dragon_hp > 0 && health > 0)
      {
        int damage = rand() % 10 + 1;
        printf("\nYou attack the dragon and deal %d damage.\n", damage);
        dragon_hp -= damage;

        if (dragon_hp <= 0)
        {
          printf("\nYou have defeated the dragon!\n");
          printf("You receive 500 gold coins.\n");
          gold += 500;
        }
        else
        {
          damage = rand() % 20 + 1;
          printf("\nThe dragon attacks you and deals %d damage.\n", damage);
          health -= damage;
        }
      }
    }
    else
    {
      printf("\nYou decide not to embark on the quest and return to exploring the town.\n");
    }
  }
  else
  {
    printf("\nYou explore the town and find a merchant.\n");
    printf("The merchant has some items for sale.\n");

    while (choice != 4)
    {
      printf("\nWhat do you want to buy?\n");
      printf("1. Health potion (30 gold)\n");
      printf("2. Sword (100 gold)\n");
      printf("3. Armor (200 gold)\n");
      printf("4. Return to town square\n");
      scanf("%d", &choice);

      switch (choice)
      {
        case 1:
          if (gold >= 30)
          {
            health += 30;
            gold -= 30;
            printf("\nYou purchase a health potion and restore 30 health.\n");
          }
          else
          {
            printf("\nYou don't have enough gold to buy a health potion.\n");
          }
          break;
        case 2:
          if (gold >= 100)
          {
            gold -= 100;
            printf("\nYou purchase a sword.\n");
          }
          else
          {
            printf("\nYou don't have enough gold to buy a sword.\n");
          }
          break;
        case 3:
          if (gold >= 200)
          {
            gold -= 200;
            printf("\nYou purchase armor.\n");
          }
          else
          {
            printf("\nYou don't have enough gold to buy armor.\n");
          }
          break;
        case 4:
          printf("\nYou return to the town square.\n");
          break;
        default:
          printf("\nInvalid choice, please try again\n");
      }
    }
  }

  printf("\nThank you for playing the Medieval Adventure Game!\n");
  print_status();

  return 0;
}