//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int room = 1; //start in room 1
  int key = 0; //player starts without the key
  int puzzle_choice = 0; //initialize user input for puzzle choice
  int math_choice = 0; //initialize user input for math puzzle choice
  int puzzle_correct = 0; //initialize puzzle correct flag
  char play_again = 'Y'; //initialize play again variable

  //seed random generator
  srand(time(NULL));

  while (play_again == 'Y') { //main game loop
    printf("You are in room %d.\n", room);

    //room 1
    if (room == 1) {
      printf("There is a math puzzle on the wall.\n");
      printf("What is the square root of 144?\n");
      scanf("%d", &math_choice);
      if (math_choice == 12) { //correct answer
        printf("Well done! The door to room 2 is unlocked.\n");
        key = 1;
        puzzle_correct = 1;
      }
      else { //incorrect answer
        printf("Sorry, that's incorrect. Try again.\n");
        puzzle_correct = 0;
      }
    }

    //room 2
    else if (room == 2) {
      printf("You are in a room with a locked door.\n");
      printf("There is a riddle on the wall:\n");
      printf("What has a head, a tail, is brown, and has no legs?\n");
      char riddle_answer[20];
      scanf("%s", riddle_answer);
      if (strcmp(riddle_answer, "penny") == 0) { //correct answer
        printf("Well done! The key to room 3 is yours.\n");
        key = 1;
      }
      else { //incorrect answer
        printf("Sorry, that's incorrect. Try again.\n");
      }
    }

    //room 3
    else if (room == 3) {
      printf("You are in a room with a locked chest.\n");
      printf("There is a word problem on the wall:\n");
      printf("If 3 people can paint a house in 4 hours,");
      printf("how long would it take 5 people to paint the same house?\n");
      scanf("%d", &puzzle_choice);
      if (puzzle_choice == 2) { //correct answer
        printf("Well done! The key to room 4 is yours.\n");
        key = 1;
        puzzle_correct = 1;
      }
      else { //incorrect answer
        printf("Sorry, that's incorrect. Try again.\n");
        puzzle_correct = 0;
      }
    }

    //room 4
    else if (room == 4) {
      printf("You are in a room with a locked safe.\n");
      if (key == 1) { //if player has the key
        printf("You use the key to unlock the safe.\n");
        printf("Inside, you find a note with a code written on it.\n");
        int code = rand() % 10000;
        printf("The code is a %d-digit number.\n", (int)(log10(code)+1));
        scanf("%d", &puzzle_choice);
        if (puzzle_choice == code) { //correct answer
          printf("Congratulations! You've solved all the puzzles and escaped the room!\n");
          puzzle_correct = 1;
        }
        else { //incorrect answer
          printf("Sorry, that's incorrect. Try again.\n");
          puzzle_correct = 0;
        }
      }
      else { //if player doesn't have the key
        printf("You need a key to unlock the safe.\n");
      }
    }

    if (puzzle_correct == 1) { //if current puzzle was solved correctly
      room++; //move to next room
      key = 0; //reset key flag
    }

    //ask if player wants to play again
    printf("Do you want to play again? (Y/N)\n");
    scanf(" %c", &play_again);
    play_again = toupper(play_again); //convert to uppercase
  }

  return 0;
}