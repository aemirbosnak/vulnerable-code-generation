//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to print introduction message
void intro() {
   printf("Welcome to Ada's Text-Based Adventure Game!\n\n");
   printf("In this game, you will be taking on the role of Ada Lovelace, the first computer programmer in history.\n");
   printf("You will need to use your programming skills to navigate through various challenges and obstacles to reach your goal.\n\n");
}

// function to print instructions
void instructions() {
   printf("To play, enter one of the following commands at each prompt:\n\n");
   printf("- 'look' to inspect your surroundings\n");
   printf("- 'go' to move to a different location\n");
   printf("- 'code' to use your programming skills to solve a problem\n");
   printf("- 'help' to display this message again\n\n");
}

// function to randomly generate a number
int randomNum(int min, int max) {
   srand(time(NULL));
   return (rand() % (max - min + 1)) + min;
}

// function to play the game
void playGame() {
   int location = 0;
   char input[20];

   printf("You find yourself in a dark room. What do you do?\n");
   strcpy(input, " ");
  
   while (strcmp(input, "exit") != 0) {
      printf("\n> "); // prompt for user input
      scanf("%s", input); // read user input
      
      if (strcmp(input, "help") == 0) {
         instructions(); // print instructions if user enters 'help'
      }
      else if (strcmp(input, "look") == 0) {
         switch (location) {
            case 0: // room 1
               printf("You are in a dark room. You can barely see anything, but you can hear the sound of dripping water.\n");
               break;
            case 1: // room 2
               printf("You are in a room filled with cobwebs. The air is thick and musty, making it hard to breathe.\n");
               break;
            case 2: // room 3
               printf("You are in a room with a large chest in the center. It looks like it hasn't been opened in years.\n");
               break;
            case 3: // room 4
               printf("You are outside in a forest. The trees tower high above you, casting a cool shadow on the ground.\n");
               break;
            default:
               printf("Invalid location.\n");
         }
      }
      else if (strcmp(input, "go") == 0) {
         switch (location) {
            case 0: // room 1
               printf("You see an opening to your left. Do you go through it?\n");
               printf("> ");
               scanf("%s", input); // read user input
               if (strcmp(input, "yes") == 0) {
                  location = 1;
                  printf("You have entered room 2.\n");
               }
               break;
            case 1: // room 2
               printf("You see a path leading north and another leading west. Which do you take?\n");
               printf("> ");
               scanf("%s", input); // read user input
               if (strcmp(input, "north") == 0) {
                  location = 2;
                  printf("You have entered room 3.\n");
               }
               else if (strcmp(input, "west") == 0) {
                  location = 3;
                  printf("You have entered room 4.\n");
               }
               break;
            case 2: // room 3
               printf("You see a staircase leading down. Do you go down it?\n");
               printf("> ");
               scanf("%s", input); // read user input
               if (strcmp(input, "yes") == 0) {
                  location = 0;
                  printf("You have entered room 1.\n");
               }
               break;
            case 3: // room 4
               printf("You see a clearing to your southeast. Do you go to it?\n");
               printf("> ");
               scanf("%s", input); // read user input
               if (strcmp(input, "yes") == 0) {
                  location = 2;
                  printf("You have entered room 3.\n");
               }
               break;
            default:
               printf("Invalid location.\n");
         }
      }
      else if (strcmp(input, "code") == 0) {
         int num1 = randomNum(1, 10);
         int num2 = randomNum(1, 10);
         int answer;
         
         printf("What is %d + %d?\n", num1, num2);
         printf("> ");
         scanf("%d", &answer); // read user input
         
         if (answer == num1 + num2) {
            printf("Congratulations! You have solved the problem and gained 10 points.\n");
         }
         else {
            printf("Sorry, that is incorrect. Please try again.\n");
         }
      }
      else if (strcmp(input, "exit") != 0) {
         printf("Invalid command. Type 'help' for a list of commands.\n");
      }
   }
}

int main() {
   intro(); // print introduction message
   instructions(); // print instructions
   playGame(); // play the game
   
   return 0;
}