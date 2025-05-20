//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>

int main() {
   //Displays game title and options
   printf("Welcome to The Lost Temple of Zolthar!\n");
   printf("1. Start New Game\n");
   printf("2. Load Previous Game\n");

   int option;
   scanf("%d", &option);

   if (option == 1) {
      //Starts a new game
      printf("You are an adventurer seeking the lost temple of Zolthar.");
      printf("After traveling for weeks, you finally find the temple hidden deep in a jungle.");
      printf("As you enter the temple, the door behind you shuts tight.");
      printf("You hear a voice that says 'Welcome adventurer, to the lost temple of Zolthar.'\n");
      printf("The voice then disappears and the room goes pitch black.\n");
      printf("You must find your way through the temple and find the treasure of Zolthar.\n");
      printf("You can move in four directions using the following commands:\n");
      printf("n - move North\n");
      printf("s - move South\n");
      printf("e - move East\n");
      printf("w - move West\n");
     
      //Starts the game loop
      int gameOver = 0;
      while (!gameOver) {
         printf("\nWhat do you want to do next?\n");
         char input;
         scanf(" %c", &input);

         //Handles input from user
         switch(input) {
            case 'n':
               printf("You move north.\n");
               break;
            case 's':
               printf("You move south.\n");
               break;
            case 'e':
               printf("You move east.\n");
               break;
            case 'w':
               printf("You move west.\n");
               break;
            default:
               printf("Invalid input. Try again.\n");
         }

         //Checks if game is over
         if (gameOver) {
            printf("You have found the treasure of Zolthar! Congratulations!\n");
         }
      }
   } else if (option == 2) {
      //Loads a previous game
      printf("Loading previous game...\n");
   } else {
      //Displays error message
      printf("Invalid option selected. Exiting game...\n");
   }

   return 0;
}