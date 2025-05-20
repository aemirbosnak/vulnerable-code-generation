//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void main()
{
  int choice, player_health = 100, enemy_health = 100;
  char name[20];
  printf("Welcome, traveler! Please enter your name: ");
  scanf("%s", name);

  // Create a loop to continue the game until one of the characters' health reaches 0
  while (player_health > 0 && enemy_health > 0)
  {
    // Display the current health of both characters
    printf("Your health: %d\n", player_health);
    printf("Enemy's health: %d\n", enemy_health);

    // Prompt the player to choose an action
    printf("What do you want to do? (1) Attack, (2) Defend, (3) Use potion\n");
    scanf("%d", &choice);

    // Determine the outcome of the player's action
    switch (choice)
    {
      case 1:
        enemy_health -= 10;
        printf("You attacked the enemy. The enemy's health has decreased to %d.\n", enemy_health);
        break;
      case 2:
        player_health += 20;
        printf("You defended yourself. Your health has increased to %d.\n", player_health);
        break;
      case 3:
        player_health += 30;
        printf("You used a potion. Your health has increased to %d.\n", player_health);
        break;
      default:
        printf("Invalid input. Please try again.\n");
    }

    // Check if the player has won or lost
    if (enemy_health <= 0)
    {
      printf("Congratulations, %s! You have defeated the enemy.\n", name);
      break;
    }
    else if (player_health <= 0)
    {
      printf("Sorry, %s. You have been defeated.\n", name);
      break;
    }
  }

  // End of the game
  return;
}