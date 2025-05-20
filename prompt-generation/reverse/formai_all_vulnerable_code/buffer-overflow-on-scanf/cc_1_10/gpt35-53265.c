//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <string.h>

int main()
{
   char playerName[30], choice[10];
   int health = 100, score = 0;
   
   printf("Welcome to the Text-Based Adventure Game!\n\n");
   printf("Please enter your name: ");
   scanf("%s", playerName);
   printf("\nHello %s, let's get started!\n\n", playerName);
   
   printf("You wake up in a dark room with no memory of how you got here.\n");
   printf("You notice that your head hurts and you have a deep cut on your arm.\n");
   printf("You try to stand up and realize that your legs are weak and shaky.\n");
   printf("Suddenly, you hear a loud noise coming from the door.\n");
   printf("What do you want to do?\n");
   printf("- Enter 'run' to run away.\n");
   printf("- Enter 'fight' to fight the attacker.\n");
   printf("- Enter 'hide' to hide behind a nearby object.\n");
   printf("Your choice: ");
   scanf("%s", choice);
   
   if (strcmp(choice, "run") == 0)
   {
       printf("\nYou attempt to run away but your legs give out and you fall to the ground.\n");
       printf("The attacker catches up to you and you lose 25 health points.\n");
       health -= 25;
   }
   else if (strcmp(choice, "fight") == 0)
   {
       printf("\nYou gather all your strength and prepare to fight the attacker.\n");
       printf("You land a few punches and manage to knock the attacker unconscious.\n");
       printf("You gain 10 score points for your victory.\n");
       score += 10;
   }
   else if (strcmp(choice, "hide") == 0)
   {
       printf("\nYou quickly hide behind a nearby object.\n");
       printf("The attacker looks around but can't find you.\n");
   }
   else
   {
       printf("\nInvalid choice. Please enter a valid choice.\n");
   }
   
   printf("\nYour current stats:\n");
   printf("- Health: %d \n", health);
   printf("- Score: %d \n", score);
   
   printf("\nYou see a door at the end of the room.\n");
   printf("What do you want to do?\n");
   printf("- Enter 'open' to open the door.\n");
   printf("- Enter 'explore' to explore the room.\n");
   printf("- Enter 'rest' to rest and regain some health.\n");
   printf("Your choice: ");
   scanf("%s", choice);
   
   if (strcmp(choice, "open") == 0)
   {
       printf("\nYou cautiously approach the door and open it slowly.\n");
       printf("You see a long hallway with several doors on either side.\n");
       printf("You hear faint whispers coming from one of the doors.\n");
   }
   else if (strcmp(choice, "explore") == 0)
   {
       printf("\nYou search the room and find a medkit.\n");
       printf("You regain 25 health points.\n");
       health += 25;
   }
   else if (strcmp(choice, "rest") == 0)
   {
       printf("\nYou take a rest and regain 10 health points.\n");
       health += 10;
   }
   else
   {
       printf("\nInvalid choice. Please enter a valid choice.\n");
   }
   
   printf("\nYour current stats:\n");
   printf("- Health: %d \n", health);
   printf("- Score: %d \n", score);
   
   printf("\nYou continue down the hallway and come across a locked door.\n");
   printf("What do you want to do?\n");
   printf("- Enter 'break' to try and break the door open.\n");
   printf("- Enter 'search' to search for a key.\n");
   printf("- Enter 'bypass' to try and bypass the lock.\n");
   
   printf("Your choice: ");
   scanf("%s", choice);
   
   if (strcmp(choice, "break") == 0)
   {
       printf("\nYou try to break open the door, but it's too sturdy.\n");
       printf("The noise attracts some enemies and you're forced to fight.\n");
       printf("You lose 30 health points and gain 15 score points.\n");
       health -= 30;
       score += 15;
   }
   else if (strcmp(choice, "search") == 0)
   {
       printf("\nYou search the hallway and find a key in one of the rooms.\n");
       printf("You use the key to unlock the door and move on.\n");
       printf("You gain 20 score points for your resourcefulness.\n");
       score += 20;
   }
   else if (strcmp(choice, "bypass") == 0)
   {
       printf("\nYou attempt to bypass the lock but are unsuccessful.\n");
       printf("You need to find a key to unlock the door.\n");
   }
   else
   {
       printf("\nInvalid choice. Please enter a valid choice.\n");
   }
   
   printf("\nYour final stats:\n");
   printf("- Health: %d \n", health);
   printf("- Score: %d \n", score);
   
   printf("\nCongratulations on completing the game, %s!\n", playerName);
   printf("Thank you for playing!\n");
   
   return 0;
}