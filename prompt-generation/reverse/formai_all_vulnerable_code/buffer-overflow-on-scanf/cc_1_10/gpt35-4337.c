//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void displayCastle();
void startGame();
int rollDice();
void displayCastleStatus(int castleHealth, int enemyHealth);
void playerTurn(int *playerGold, int *castleHealth, int *playerArmy, int *numEnemiesDefeated);
void enemyTurn(int *enemyHealth, int playerArmy);
void endGame(int castleHealth, int numEnemiesDefeated);

int main()
{
  // Seed random number generator
  srand(time(NULL));

  // Display castle ASCII art
  displayCastle();

  // Start the game
  startGame();

  return 0;
}

void displayCastle()
{
  printf("        /\\   /\\   \n");
  printf("       /__\\ /__\\  \n");
  printf("      |  O | O  | \n");
  printf("      |___o|o___| \n");
  printf("     /|_|_|_|_|_|\\ \n");
  printf("    /_/_________\\_\\ \n");
}

void startGame()
{
  printf("Welcome to Medieval Siege!\n");
  printf("You are the ruler of a castle under attack by enemy forces.\n");
  printf("You must defend your castle and defeat all enemy units that attack you.\n\n");

  // Initialize game variables
  int playerGold = 100;
  int castleHealth = 100;
  int playerArmy = 20;
  int numEnemiesDefeated = 0;

  // Game loop
  while (castleHealth > 0 && numEnemiesDefeated < 5)
  {
    // Display castle and game status
    displayCastle();
    displayCastleStatus(castleHealth, numEnemiesDefeated);

    // Player turn
    playerTurn(&playerGold, &castleHealth, &playerArmy, &numEnemiesDefeated);

    // Enemy turn
    int enemyHealth = rollDice() * 10;
    enemyTurn(&enemyHealth, playerArmy);

    // Check if enemy was defeated
    if (enemyHealth <= 0)
    {
      printf("You defeated the enemy unit!\n");
      playerGold += rollDice() * 10;
      numEnemiesDefeated++;
    }

    // Check if player lost
    if (castleHealth <= 0)
    {
      printf("Your castle has been destroyed. Game over!\n");
      exit(0);
    }
  }

  // End game and display score
  endGame(castleHealth, numEnemiesDefeated);
}

int rollDice()
{
  return rand() % 6 + 1;
}

void displayCastleStatus(int castleHealth, int numEnemiesDefeated)
{
  printf("Castle health: %d\n", castleHealth);
  printf("Enemies defeated: %d/5\n\n", numEnemiesDefeated);
}

void playerTurn(int *playerGold, int *castleHealth, int *playerArmy, int *numEnemiesDefeated)
{
  printf("It's your turn!\n");
  printf("Gold: %d | Army size: %d\n", *playerGold, *playerArmy);

  // Menu
  int choice;
  do
  {
    printf("\n1. Recruit soldiers (10 gold)\n");
    printf("2. Repair castle (10 gold)\n");
    printf("3. Do nothing\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
  } while (choice < 1 || choice > 3);

  // Perform action
  switch (choice)
  {
    case 1:
      if (*playerGold >= 10)
      {
        (*playerGold) -= 10;
        (*playerArmy) += rollDice();
        printf("You recruited new soldiers to your army!\n");
      }
      else
      {
        printf("Not enough gold to recruit soldiers.\n");
      }
      break;

    case 2:
      if (*playerGold >= 10)
      {
        (*playerGold) -= 10;
        (*castleHealth) += rollDice() * 10;
        if (*castleHealth > 100)
        {
          *castleHealth = 100;
        }
        printf("You repaired the castle!\n");
      }
      else
      {
        printf("Not enough gold to repair castle.\n");
      }
      break;

    case 3:
      printf("You decided to do nothing...\n");
      break;
  }
}

void enemyTurn(int *enemyHealth, int playerArmy)
{
  printf("Enemy attacks!\n");

  // Calculate enemy damage
  int enemyDamage = rollDice() * 5;

  // If player has army, subtract army health instead of castle health
  if (playerArmy > 0)
  {
    playerArmy -= enemyDamage;
    if (playerArmy < 0)
    {
      playerArmy = 0;
    }
    printf("The enemy unit attacked your army for %d damage!\n", enemyDamage);
  }
  else
  {
    (*enemyHealth) -= enemyDamage;
    printf("The enemy unit attacked your castle for %d damage!\n", enemyDamage);
  }
}

void endGame(int castleHealth, int numEnemiesDefeated)
{
  printf("Congratulations, you have defended your castle and defeated all enemy units!\n");
  printf("Your final score: %d\n", castleHealth + numEnemiesDefeated * 100);
}