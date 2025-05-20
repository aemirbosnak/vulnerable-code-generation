//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  //Initialization
  char name[20];
  int health = 100;
  int gold = 0;
  int choice;
  //Seed random number generator
  srand(time(NULL));
  printf("*** WELCOME TO THE ADVENTURES OF %s! ***\n", name);
  printf("What is your name, adventurer?\n");
  scanf("%s", name);
  printf("Greetings, %s! Your journey begins now.\n\n", name);
  while (health > 0) {
    printf("You have %d health and %d gold.\n", health, gold);
    printf("What would you like to do, adventurer?\n");
    printf("1. Explore the forest\n");
    printf("2. Visit the town\n");
    printf("3. Exit the game\n");
    scanf("%d", &choice);
    printf("\n");
    switch (choice) {
      case 1:
        //Explore the forest
        printf("You enter the forest and find a magic mushroom. Do you want to eat it?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);
        if (choice == 1) {
          //Random chance to get hurt
          int random_number = rand() % 4 + 1;
          if (random_number == 1) {
            printf("Oops! The mushroom was poisonous. You lose 10 health.\n");
            health -= 10;
          } else {
            printf("Yum! The mushroom heals you by 10 health.\n");
            health += 10;
          }
        } else {
          printf("You decide not to eat the mushroom.\n");
        }
        break;
      case 2:
        //Visit the town
        printf("You enter the town and meet the village elder. He offers you a quest.\n");
        printf("Do you accept?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);
        if (choice == 1) {
          //Random chance to get gold
          int random_number = rand() % 20 + 1;
          printf("You have to retrieve a stolen treasure chest from the bandit hideout.\n");
          printf("The elder gives you a map and a sword to help you on your quest.\n");
          if (random_number <= 10) {
            printf("You successfully retrieve the treasure chest and earn 50 gold.\n");
            gold += 50;
          } else {
            //Random chance to get hurt
            int random_number2 = rand() % 2 + 1;
            if (random_number2 == 1) {
              printf("The bandits catch you and you lose 20 health.\n");
              health -= 20;
            } else {
              printf("You accidentally fall into a trap and lose 10 health.\n");
              health -= 10;
            }
          }
        } else {
          printf("You decline the quest and leave the town.\n");
        }
        break;
      case 3:
        //Exit the game
        printf("Thanks for playing, %s! You earned %d gold.\n", name, gold);
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
  printf("Game over, %s! You have no more health and have earned %d gold.\n", name, gold);
  return 0;
}