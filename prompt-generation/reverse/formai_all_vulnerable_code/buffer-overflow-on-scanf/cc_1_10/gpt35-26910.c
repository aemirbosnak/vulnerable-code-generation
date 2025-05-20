//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define global variables
char playerName[50];
int playerHealth = 100;
int playerAttack = 10;
int goldAmount = 0;

// Function to display game introduction
void displayIntro() {
  printf("\n\nWelcome to The Adventures of %s\n", playerName);
  printf("You have been summoned to save the world from impending doom.\n");
  printf("Are you ready to embark on a journey of a lifetime?\n\n");
}

// Function to display player stats
void displayPlayerStats() {
  printf("\nPLAYER STATS:\n");
  printf("Player Name: %s\n", playerName);
  printf("Player Health: %d\n", playerHealth);
  printf("Player Attack Power: %d\n", playerAttack);
  printf("Gold Amount: %d\n\n", goldAmount);
}

// Function to start game
void startGame() {
  char choice;

  printf("You are standing in the middle of a dark and creepy forest.\n");
  printf("You have no idea how you got here but you know you have a mission to save the world.\n");
  printf("There are two paths in front of you. Which one do you take? (left/right)\n");

  do {
    scanf(" %c", &choice);
    choice = tolower(choice);

    if (choice == 'left') {
      printf("\nYou have chosen the left path.\n");
      printf("You come across a sickly looking old man.\n");
      printf("He offers to sell you a potion that will boost your attack power.\n");
      printf("Do you buy the potion? (yes/no)\n");

      scanf(" %c", &choice);
      choice = tolower(choice);

      if (choice == 'yes') {
        if (goldAmount < 50) {
          printf("\nYou don't have enough gold to buy the potion.\n");
        } else {
          printf("\nYou bought the potion and your attack power has increased.\n");
          playerAttack += 10;
          goldAmount -= 50;
        }
      } else if (choice == 'no') {
        printf("\nYou decide not to buy the potion and continue on your journey.\n");
      } else {
        printf("\nInvalid choice, please choose yes or no.\n");
      }

      printf("\nYou come across a river. Do you swim across or try to find a bridge? (swim/bridge)\n");

      scanf(" %c", &choice);
      choice = tolower(choice);

      if (choice == 'swim') {
        printf("\nYou try to swim across but the current is too strong and you get swept away.\n");
        printf("You lose health points and have to continue your journey with less health.\n");
        playerHealth -= 20;
      } else if (choice == 'bridge') {
        printf("\nYou find a rickety old bridge and attempt to cross it.\n");
        printf("The bridge collapses beneath you but you manage to grab onto a nearby branch and pull yourself up.\n");
      } else {
        printf("\nInvalid choice, please choose swim or bridge.\n");
      }

      printf("\nYou see a signpost pointing to two different directions. One says 'Castle', the other says 'Cave'. Which way do you go? (castle/cave)\n");

      scanf(" %c", &choice);
      choice = tolower(choice);

      if (choice == 'castle') {
        printf("\nYou make your way to the castle but it is heavily guarded and you are quickly spotted.\n");
        printf("You have to fight off the guards and make a run for it.\n");
        playerHealth -= 30;
      } else if (choice == 'cave') {
        printf("\nYou make your way to the cave and find a treasure chest.\n");
        printf("Inside the chest, you find a large amount of gold.\n");
        goldAmount += 100;
      } else {
        printf("\nInvalid choice, please choose castle or cave.\n");
      }
    } else if (choice == 'right') {
      printf("\nYou have chosen the right path.\n");
      printf("You come across a group of bandits.\n");
      printf("Do you fight them or try to sneak past them? (fight/sneak)\n");

      scanf(" %c", &choice);
      choice = tolower(choice);

      if (choice == 'fight') {
        printf("\nYou draw your weapon and prepare to fight the bandits.\n");
        int banditsHealth = 50;
        int banditsAttack = 5;

        while (playerHealth > 0 && banditsHealth > 0) {
          printf("\nPLAYER:\n");
          printf("Player Health: %d\n", playerHealth);
          printf("Player Attack Power: %d\n", playerAttack);
          printf("----------------\n");
          printf("BANDITS:\n");
          printf("Bandits Health: %d\n", banditsHealth);
          printf("Bandits Attack Power: %d\n", banditsAttack);
          printf("----------------\n");

          char action;
          printf("\nWhat do you do? (attack/run)\n");
          scanf(" %c", &action);
          action = tolower(action);

          if (action == 'a') {
            banditsHealth -= playerAttack;
            printf("\nYou hit the bandits for %d damage.\n", playerAttack);
          } else if (action == 'r') {
            printf("\nYou try to run away but the bandits catch you and beat you up.\n");
            printf("You lose health points and have to continue your journey with less health.\n");
            playerHealth -= 20;
            break;
          } else {
            printf("\nInvalid choice, please choose attack or run.\n");
          }

          if (banditsHealth > 0) {
            playerHealth -= banditsAttack;
            printf("\nThe bandits hit you for %d damage.\n", banditsAttack);
          }
        }

        if (playerHealth > 0) {
          printf("\nYou defeated the bandits and continue on your journey.\n");
          goldAmount += 50;
        } else {
          printf("\nYou have been defeated by the bandits.\n");
        }
      } else if (choice == 'sneak') {
        printf("\nYou try to sneak past the bandits but they spot you and chase after you.\n");
        printf("You manage to outrun them but not without losing some health points.\n");
        playerHealth -= 10;
      } else {
        printf("\nInvalid choice, please choose fight or sneak.\n");
      }

      printf("\nYou come across a village that is being attacked by a dragon.\n");
      printf("The villagers offer you a reward for slaying the dragon. Do you accept the quest? (yes/no)\n");

      scanf(" %c", &choice);
      choice = tolower(choice);

      if (choice == 'yes') {
        printf("\nYou accept the quest and set out to slay the dragon.\n");
        printf("The fight is long and hard but you manage to defeat the dragon and save the village.\n");
        goldAmount += 500;
      } else if (choice == 'no') {
        printf("\nYou decide not to accept the quest and continue on your journey.\n");
      } else {
        printf("\nInvalid choice, please choose yes or no.\n");
      }

      printf("\nYou see a signpost pointing to two different directions. One says 'Castle', the other says 'Cave'. Which way do you go? (castle/cave)\n");

      scanf(" %c", &choice);
      choice = tolower(choice);

      if (choice == 'castle') {
        printf("\nYou make your way to the castle but it is heavily guarded and you are quickly spotted.\n");
        printf("You have to fight off the guards and make a run for it.\n");
        playerHealth -= 30;
      } else if (choice == 'cave') {
        printf("\nYou make your way to the cave and find a treasure chest.\n");
        printf("Inside the chest, you find a large amount of gold.\n");
        goldAmount += 100;
      } else {
        printf("\nInvalid choice, please choose castle or cave.\n");
      }
    } else {
      printf("\nInvalid choice, please choose left or right.\n");
    }
  } while (choice != 'left' && choice != 'right');

  printf("\nYou have completed your journey with the following stats:\n");
  displayPlayerStats();
}

// Main function
int main() {
  printf("Welcome adventurer! What is your name? (max 50 characters)\n");

  fgets(playerName, sizeof(playerName), stdin);
  playerName[strcspn(playerName, "\n")] = '\0';
  
  displayIntro();
  displayPlayerStats();
  startGame();

  return 0;
}