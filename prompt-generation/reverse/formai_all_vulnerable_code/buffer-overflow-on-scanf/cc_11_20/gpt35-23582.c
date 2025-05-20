//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // declare variables
   int room, door, choice;
   char answer;

   // seed the random number generator
   srand(time(NULL));

   // print introduction
   printf("Welcome to the Haunted House Simulator!\n\n");
   printf("You find yourself in a dark, abandoned house.\n");
   printf("Your goal is to escape alive, but be warned -\n");
   printf("the house is haunted by malevolent spirits.\n\n");

   // game loop
   do {
      // choose a random starting room
      room = rand() % 5 + 1;

      // print current room and prompt for action
      printf("You are in room %d. What do you do?\n", room);
      printf("1. Open a door\n");
      printf("2. Search the room\n");
      printf("3. Quit\n");
      scanf("%d", &choice);

      // handle user input
      switch (choice) {
         case 1:
            // choose a random door to open
            door = rand() % 3 + 1;
            printf("You open door %d...\n", door);

            // determine outcome of door based on room and door number
            if (room == 1 && door == 2) {
               printf("A ghostly apparition appears and scares you back into the room.\n");
            } else if (room == 2 && door == 3) {
               printf("You open the door and find a key that unlocks the exit!\n");
               printf("Congratulations, you've escaped the haunted house!\n");
               printf("Would you like to play again? (y/n)\n");
               scanf(" %c", &answer);
            } else if (room == 3 && door == 2) {
               printf("Rats! You stumbled into a swarm of angry vermin and they attacked you.\n");
               printf("Game over. Would you like to play again? (y/n)\n");
               scanf(" %c", &answer);
            } else if (room == 4 && door == 1) {
               printf("You open the door to reveal a hidden passage. It leads to a room filled with treasure!\n");
               printf("You may have escaped the haunted house, but you're still rich in spirit.\n");
               printf("Would you like to play again? (y/n)\n");
               scanf(" %c", &answer);
            } else if (room == 5 && door == 3) {
               printf("You open the door and find yourself face to face with a malevolent spirit!\n");
               printf("It attacks you and you perish in the haunted house.\n");
               printf("Game over. Would you like to play again? (y/n)\n");
               scanf(" %c", &answer);
            } else {
               printf("Nothing interesting happens.\n");
            }
            break;

         case 2:
            // search the room for clues
            printf("You search the room and find nothing of interest.\n");
            break;

         case 3:
            // quit the game
            printf("Goodbye! Thanks for playing.\n");
            exit(1);

         default:
            // invalid input
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
      }

   } while (answer != 'n');

   return 0;
}