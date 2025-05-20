//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   char playerName[20];
   char response[50];
 
   printf("Welcome to the Adventure Game! Please enter your name: ");
   scanf("%s", playerName);
 
   printf("\n\nWelcome %s, to start the adventure, type 'start'!\n", playerName);
   scanf("%s", response);
 
   if (strcmp(response, "start") == 0)
   {
       printf("\n\nGreat! Let's get started!\n");
       printf("\nYou find yourself in a dark room with a door on the left and right. Which do you choose?\n");
       printf("Type 'left' or 'right': ");
       scanf("%s", response);
 
       if (strcmp(response, "left") == 0)
       {
           printf("\n\nYou open the door and see a treasure chest in front of you. How fortunate!\n");
           printf("Type 'open' to open the chest, or 'leave' to leave it alone: ");
           scanf("%s", response);
 
           if (strcmp(response, "open") == 0)
           {
               printf("\n\nAs you open the chest, a bright light engulfs you! You have caught the attention of the dragon!\n");
               printf("Type 'fight' to fight the dragon, or 'run' to escape: ");
               scanf("%s", response);
 
               if (strcmp(response, "fight") == 0)
               {
                   printf("\n\nYou bravely fight the dragon and emerge victorious! Congratulations, you have won the game!\n");
               } 
               else if (strcmp(response, "run") == 0)
               {
                   printf("\n\nYou run out of the room and escape the dragon unharmed. However, you have lost the game.\n");
               } 
               else
               {
                   printf("\n\nInvalid response. You didn't fight or run. The dragon ate you! Game over!\n");
               }
           } 
           else if (strcmp(response, "leave") == 0)
           {
               printf("\n\nYou leave the chest alone and continue on your adventure. You find a door ahead of you. Type 'open' to see what's inside: ");
               scanf("%s", response);
 
               if (strcmp(response, "open") == 0)
               {
                   printf("\n\nInside the room, you discover a secret passage leading to a garden. Congratulations, you have won the game!\n");
               } 
               else
               {
                   printf("\n\nInvalid response. You didn't open the door. The passage closed and you are stuck! Game Over!\n");
               }
           } 
           else
           {
               printf("\n\nInvalid response. You didn't open or leave the chest. The dragon ate you! Game over!\n");
           }
       } 
       else if (strcmp(response, "right") == 0)
       {
           printf("\n\nYou open the door on the right and find yourself on a balcony. Congratulations, you have won the game!\n");
       } 
       else
       {
           printf("\n\nInvalid response. You didn't choose left or right. You are stuck in the dark room forever! Game over!\n");
       }
   } 
   else
   {
       printf("\n\nInvalid response. You didn't start the game. Better luck next time.\n");
   }
 
   return 0;
}