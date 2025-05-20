//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SHIP_HEALTH 100
#define ALIEN_HEALTH 50

void printIntro();
void printGameOver();
void printWin();
void playGame();

int main()
{
  srand(time(0));
  printIntro();
  playGame();
  return 0;
}

void printIntro()
{
  printf("Welcome to the Procedural Space Adventure!\n");
  printf("You are the captain of a spaceship on a mission to explore the unknown corners of the galaxy.\n");
  printf("As you travel through space, you encounter strange new worlds, alien creatures, and perilous dangers.\n");
  printf("Your mission is to survive and complete your exploration of the galaxy.\n");
  printf("Good luck, Captain!\n\n");
}

void printGameOver()
{
  printf("\n\n");
  printf(" ___          _        ___                       _      \n");
  printf("| _ )  ___  | |_     / __|   ___    __      __ (_)  ___ \n");
  printf("| _ \\ / -_) |  _|   | (__   / _ \\   \\ \\ /\\ / / | | / -_)\n");
  printf("|___/ \\___|  \\__|    \\___|  \\___/    \\_\\_\\ \\_/  |_| \\___|\n");
  printf("\n\n");
  printf("Game Over, Captain!\n");
}

void printWin()
{
  printf("\n\n");
  printf(" __  __        __     _ _      ___                       _  \n");
  printf("|  \\/  |___ __/  \\ __| (_)__  | _ )  ___  __ _ _ _    __| |\n");
  printf("| |\\/| / -_) \\ / () / _` / _ \\ | _ \\ / _ \\/ _` | ' \\  / _` |\n");
  printf("|_|  |_\\___/_\\_\\\\__/\\__,_/_//_/ |___/ \\___/\\__,_|_||_| \\__,_|\n");
  printf("\n\n");
  printf("Congratulations, Captain!\n");
  printf("You have successfully explored the galaxy and discovered all of its mysteries.\n");
  printf("You are a true hero of space!\n");
}

void playGame()
{
  int shipHealth = SHIP_HEALTH;
  int alienHealth = ALIEN_HEALTH;
  char choice[10];
  
  printf("You are now in space, on your way to a distant planet.\n");
  
  while(shipHealth > 0)
  {
    printf("\n\nYou encounter an alien ship!\n");
    
    while(alienHealth > 0)
    {
      printf("\nYour ship health: %d\n", shipHealth);
      printf("Alien ship health: %d\n\n", alienHealth);
      printf("What will you do? [attack/run]\n");
      scanf("%s", choice);
      
      if(strcmp(choice, "attack") == 0)
      {
        int damage = rand() % 10 + 1;
        printf("You attack the alien ship and deal %d damage!\n", damage);
        alienHealth -= damage;
        
        if(alienHealth <= 0)
        {
          printf("You have defeated the alien ship!\n");
          break;
        }
        
        damage = rand() % 10 + 1;
        printf("The alien ship attacks you and deals %d damage!\n", damage);
        shipHealth -= damage;
        
        if(shipHealth <= 0)
        {
          printf("Your ship has been destroyed by the alien ship!\n");
          printGameOver();
          return;
        }
      }
      
      else if(strcmp(choice, "run") == 0)
      {
        if(rand() % 2 == 0)
        {
          printf("You successfully escape from the alien ship!\n");
          break;
        }
        else
        {
          printf("You try to escape, but the alien ship catches up to you!\n");
          int damage = rand() % 10 + 1;
          printf("The alien ship attacks you and deals %d damage!\n", damage);
          shipHealth -= damage;
        
          if(shipHealth <= 0)
          {
            printf("Your ship has been destroyed by the alien ship!\n");
            printGameOver();
            return;
          }
        }
      }
    }
    
    alienHealth = ALIEN_HEALTH;
  }
  
  printWin();
}