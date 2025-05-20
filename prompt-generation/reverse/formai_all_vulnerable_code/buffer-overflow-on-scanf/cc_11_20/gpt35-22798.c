//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
   char name[20], gender[10], in_love_with[20], choice[10];
   int go_direction, wrong_choice, end_game = 0;

   printf("Welcome to the Adventure of Romeo and Juliet!\n");
   printf("What is your name?\n");
   scanf("%s", name);
   printf("Hello, %s! Are you male or female?\n", name);
   scanf("%s", gender);
   if (strcmp(gender, "male") == 0) {
       strcpy(in_love_with, "Juliet");
   } else {
       strcpy(in_love_with, "Romeo");
   }
   printf("You are %s, in love with %s.\n", name, in_love_with);
   printf("You find yourself in the streets of Verona, Italy.\n");
   printf("Do you want to go left or right? (Type 'left' or 'right'.)\n");
   scanf("%s", choice);
   if (strcmp(choice, "left") == 0) {
       go_direction = 1; // Left
   } else {
       go_direction = 2; // Right
   }

   while (!end_game) {
       switch (go_direction) {
           case 1:
               printf("You have chosen to go left.\n");
               printf("You see a group of Montague boys coming towards you.\n");
               printf("Do you 'fight' or 'run'? (Type 'fight' or 'run'.)\n");
               scanf("%s", choice);
               if (strcmp(choice, "fight") == 0) {
                   printf("You fought bravely, but unfortunately you were outnumbered.\n");
                   printf("The Montagues killed you.\n");
                   end_game = 1; // Game over
               } else {
                   printf("You managed to escape from the Montagues.\n");
                   printf("You look around and see a beautiful garden in front of you.\n");
                   printf("Do you want to enter the garden? (Type 'yes' or 'no'.)\n");
                   scanf("%s", choice);
                   if (strcmp(choice, "yes") == 0) {
                       printf("You entered the garden and saw %s standing there.\n", in_love_with);
                       printf("You approached %s and started talking to %s.\n", in_love_with, in_love_with);
                       printf("%s eventually falls in love with you.\n", in_love_with);
                       end_game = 1; // Game over
                   } else {
                       printf("You decided not to enter the garden.\n");
                       printf("You are walking away when suddenly a lightning strikes you.\n");
                       printf("You died on the spot.\n");
                       end_game = 1; // Game over
                   }
               }
               break;

           case 2:
               printf("You have chosen to go right.\n");
               printf("You see a group of Capulet girls coming towards you.\n");
               printf("Do you 'flirt' or 'ignore'? (Type 'flirt' or 'ignore'.)\n");
               scanf("%s", choice);
               if (strcmp(choice, "flirt") == 0) {
                   printf("You flirted with the girls, but it turns out they were already taken.\n");
                   printf("Their boyfriends, the Capulet brothers, saw you and attacked you.\n");
                   printf("You ran away, but not before you were injured.\n");
                   printf("You eventually died from your injuries.\n");
                   end_game = 1; // Game over
               } else {
                   printf("You ignored the girls and continued walking.\n");
                   printf("You see a staircase leading to a balcony in front of you.\n");
                   printf("Do you want to climb the staircase? (Type 'yes' or 'no'.)\n");
                   scanf("%s", choice);
                   if (strcmp(choice, "yes") == 0) {
                       printf("You climbed the staircase and saw %s standing on the balcony.\n", in_love_with);
                       printf("You called out to %s and started talking to %s.\n", in_love_with, in_love_with);
                       printf("%s eventually falls in love with you.\n", in_love_with);
                       end_game = 1; // Game over
                   } else {
                       printf("You decided not to climb the staircase.\n");
                       printf("You are walking away when suddenly a carriage hits you.\n");
                       printf("You died on the spot.\n");
                       end_game = 1; // Game over
                   }               
               }
               break;

           default:
               printf("You chose a wrong direction. Please choose again.\n");
               wrong_choice++;
               if (wrong_choice >= 3) {
                   printf("You have made too many wrong choices. Game over.\n");
                   end_game = 1; // Game over
               } else {
                   printf("Do you want to go left or right? (Type 'left' or 'right'.)\n");
                   scanf("%s", choice);
                   if (strcmp(choice, "left") == 0) {
                       go_direction = 1; // Left
                   } else {
                       go_direction = 2; // Right
                   }
               }
               break;
       }
   }

   return 0;
}