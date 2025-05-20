//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayIntro(); // function declaration for displaying intro
void enterRoom(); // function declaration for entering into a room 
void fightEnemy(); // function declaration for enemy fight 
void gameOver();  // function declaration for game over 

int main()
{
   displayIntro();
   enterRoom();
   return 0;
}

void displayIntro()
{
   printf("Welcome to the Dungeon Adventure Game!\n");
   printf("You have just entered into a dungeon filled with monsters and treasure.\n");
   printf("Your task is to make it through the dungeon and come out with as much treasure as possible.\n");
   printf("Be careful, as there are dangerous monsters lurking in every room.\n");
   printf("Good luck!\n\n");
}

void enterRoom()
{
   printf("You enter into the first room.\n");
   printf("You see a treasure chest on one side of the room and a door on the other.\n");
   printf("What would you like to do? (type 'open chest' or 'go door'): ");
   char action[20];
   scanf("%s", action);
   if(strcmp(action, "open chest") == 0)
   {
      printf("You open the chest and find a sword!\n");
      fightEnemy();
   }
   else
   {
      printf("You go through the door and enter the next room.\n");
      printf("You see an enemy in front of you. Get ready for a fight!\n");
      fightEnemy();
   }
}

void fightEnemy()
{
   int enemyHealth = 100;
   int playerHealth = 100;
   while(enemyHealth > 0 && playerHealth > 0)
   {
      printf("Your health: %d\n", playerHealth);
      printf("Enemy health: %d\n", enemyHealth);
      printf("What would you like to do? (type 'attack' or 'run'): ");
      char action[20];
      scanf("%s", action);
      
      if(strcmp(action, "attack") == 0)
      {
         int damage = rand() % 20 + 1;
         enemyHealth -= damage;
         printf("You hit the enemy for %d damage!\n", damage);
         damage = rand() % 20 + 1;
         playerHealth -= damage;
         printf("The enemy hits you for %d damage!\n", damage);
      }
      else
      {
         printf("You run away from the enemy.\n");
         gameOver();
      }
   }
   if(enemyHealth <= 0)
   {
      printf("You have defeated the enemy!\n");
      printf("You have gained 50 gold.\n");
      gameOver();
   }
   else
   {
      printf("The enemy has defeated you.\n");
      gameOver();
   }
}

void gameOver()
{
   printf("Game over.\n");
   printf("Thanks for playing!\n");
}