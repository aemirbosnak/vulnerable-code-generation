//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//function prototypes
void showIntro();
void startGame();
void showInstructions();
int room1();
int room2();
int room3();
int room4();
int room5();
int room6();
int room7();
int room8();
void gameOver();

int main() {
   //seed random number generator
   srand(time(NULL));
   showIntro();
   startGame();   
   return 0;
}

void showIntro() {
   printf("\n\tWelcome to the Paranoid Adventure Game!");
   printf("\n\t****************************************");
   printf("\n\n\tYou are a secret agent on a mission to stop a group of terrorists from detonating a nuclear bomb.");
   printf("\n\tBut beware, they have rigged various rooms with traps and surveillance.");
}

void startGame() {
   int choice;
   
   printf("\n\n\tPress 1 to start the game");
   printf("\n\tPress 2 to view instructions\n");
   scanf("%d", &choice);
   
   switch(choice) {
      case 1:
        room1();
        break;
        
      case 2:
        showInstructions();
        startGame();
        break;
         
      default:
        printf("\n\tInvalid choice, please try again.");
        startGame();
   }
}

void showInstructions() {
   printf("\n\tInstructions:");
   printf("\n\t*************************************************************");
   printf("\n\n\tYou will be presented with different rooms. Each room has a specific task that you must complete in order to get to the next room.");
   printf("\n\tHowever, there might be hidden booby traps and surveillance systems. You must be careful not to trigger them or you will lose the game.");
   printf("\n\tGood luck!\n");
}

int room1() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the first room.");
   printf("\n\tYou see a safe and a computer.");
   printf("\n\n\tPress 1 to crack the safe.");
   printf("\n\tPress 2 to hack the computer.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      printf("\n\tYou successfully cracked the safe and obtained a keycard.");
      printf("\n\tYou move on to the next room.");
      room2();
   }
   else if(choice == 2) {
      if(randomNum < 6) {
         printf("\n\tYou triggered a surveillance system and have been captured by the terrorists.");
         gameOver();
      }
      else {
         printf("\n\tYou successfully hacked the computer and obtained a keycard.");
         printf("\n\tYou move on to the next room.");
         room2();
      }
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room1();
   }
   return 0;
}

int room2() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the second room.");
   printf("\n\tYou see a keypad and a security camera.");
   printf("\n\n\tPress 1 to enter the key code.");
   printf("\n\tPress 2 to destroy the security camera.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      if(randomNum < 4) {
         printf("\n\tYou entered the wrong key code and triggered a bomb.");
         gameOver();
      }
      else {
         printf("\n\tYou successfully entered the correct key code and door opened.");
         printf("\n\tYou move on to the next room.");
         room3();
      }
   }
   else if(choice == 2) {
      if(randomNum < 7) {
         printf("\n\tYou triggered a booby trap and have been killed.");
         gameOver();
      }
      else {
         printf("\n\tYou successfully destroyed the security camera and opened the door.");
         printf("\n\tYou move on to the next room.");
         room3();
      }
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room2();
   }
   return 0;
}

int room3() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the third room.");
   printf("\n\tYou see two doors, one marked 'exit' and the other marked 'death'.");
   printf("\n\n\tPress 1 to choose the exit door.");
   printf("\n\tPress 2 to choose the death door.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      printf("\n\tYou have chosen the correct door and escaped the building.");
      printf("\n\tCongratulations! You have won the game.");
   }
   else if(choice == 2) {
      if(randomNum < 5) {
         printf("\n\tYou have chosen the death door and have been killed.");
         gameOver();
      }
      else {
         printf("\n\tYou have chosen the death door and have found a secret passage.");
         printf("\n\tYou move on to the next room.");
         room4();
      }
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room3();
   }
   return 0;
}

int room4() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the fourth room.");
   printf("\n\tYou see a table with a book and a phone.");
   printf("\n\n\tPress 1 to read the book.");
   printf("\n\tPress 2 to answer the phone.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      printf("\n\tYou read the book and found a clue.");
      printf("\n\tYou move on to the next room.");
      room5();
   }
   else if(choice == 2) {
      if(randomNum < 3) {
         printf("\n\tYou triggered a bomb and have been killed.");
         gameOver();
      }
      else {
         printf("\n\tYou answered the phone and found a clue.");
         printf("\n\tYou move on to the next room.");
         room5();
      }
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room4();
   }
   return 0;
}

int room5() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the fifth room.");
   printf("\n\tYou see a laser security system and a door with a keyhole.");
   printf("\n\n\tPress 1 to disable the laser security system.");
   printf("\n\tPress 2 to use the key to open the door.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      if(randomNum < 5) {
         printf("\n\tYou triggered the laser security system and have been killed.");
         gameOver();
      }
      else {
         printf("\n\tYou successfully disabled the laser security system and opened the door.");
         printf("\n\tYou move on to the next room.");
         room6();
      }
   }
   else if(choice == 2) {
      printf("\n\tYou need a keycard to open this locked door.");
      printf("\n\tYou move back to the previous room.");
      room4();
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room5();
   }
   return 0;
}

int room6() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the sixth room.");
   printf("\n\tYou see a pool of acid and ladder.");
   printf("\n\n\tPress 1 to cross the acid pool.");
   printf("\n\tPress 2 to climb the ladder.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      if(randomNum < 4) {
         printf("\n\tYou sank in the acid pool and have been killed.");
         gameOver();
      }
      else {
         printf("\n\tYou successfully crossed the acid pool and the door opened.");
         printf("\n\tYou move on to the next room.");
         room7();
      }
   }
   else if(choice == 2) {
      printf("\n\tYou need to find a way to unlock the door on the other side of the acid pool.");
      printf("\n\tYou move back to the previous room.");
      room5();
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room6();
   }
   return 0;
}

int room7() {
   int choice;
   int randomNum = (rand() % 10) + 1;
   
   printf("\n\n\tYou have entered the seventh room.");
   printf("\n\tYou see a pressure plate and a button.");
   printf("\n\n\tPress 1 to step on the pressure plate.");
   printf("\n\tPress 2 to press the button.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      if(randomNum < 7) {
         printf("\n\tYou triggered a booby trap and have been killed.");
         gameOver();
      }
      else {
         printf("\n\tYou stepped on the pressure plate and door opened.");
         printf("\n\tYou move on to the next room.");
         room8();
      }
   }
   else if(choice == 2) {
      printf("\n\tYou need to find a way to unlock the door controlled by the button.");
      printf("\n\tYou move back to the previous room.");
      room6();
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room7();
   }
   return 0;
}

int room8() {
   int choice;
   
   printf("\n\n\tYou have entered the final room.");
   printf("\n\tYou see the nuclear bomb and the timer ticking away.");
   printf("\n\n\tPress 1 to disarm the bomb.");
   printf("\n\tPress 2 to run away.\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      printf("\n\tYou successfully disarmed the bomb and saved the world!");
      printf("\n\tCongratulations! You have won the game.");
   }
   else if(choice == 2) {
      printf("\n\tYou ran away, but the bomb exploded and destroyed the world.");
      gameOver();
   }
   else {
      printf("\n\tInvalid choice, please try again.");
      room8();
   }
   return 0;
}

void gameOver() {
   printf("\n\t------------------------------------");
   printf("\n\t|              Game over           |");
   printf("\n\t------------------------------------");
   printf("\n\tSorry, you have lost the game.");
   printf("\n\tPlease try again.\n");
   startGame();
}