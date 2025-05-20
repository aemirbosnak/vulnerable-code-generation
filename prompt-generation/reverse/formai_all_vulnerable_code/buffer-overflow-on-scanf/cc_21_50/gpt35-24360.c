//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator
  
  char response;
  int steps = 0;
  int room = 0;
  
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are standing outside a creepy house.\n");
  printf("Would you like to go inside? (y/n) ");
  scanf(" %c", &response);
  
  if (response == 'n') {
    printf("Ok, see you later!\n");
    return 0; // End program
  }
  
  printf("\nYou enter the house...\n");
  
  while (room != 10) {
    int chance = rand() % 100; // Generate a random number between 0-99
    
    if (room == 0) {
      printf("You are in a dark hallway...\n");
      printf("You see a door to your left and a door to your right.\n");
      printf("Which door do you choose? (l/r) ");
      scanf(" %c", &response);
      
      if (response == 'l') {
        printf("\nYou open the door and find a dusty old library.\n");
        room = 1;
      } else if (response == 'r') {
        printf("\nYou open the door and find a kitchen with rotting food on the table.\n");
        room = 2;
      } else {
        printf("That's not a valid response.\n");
        steps++; // Increment steps taken
        continue; // Start loop again
      }
    }
    
    if (room == 1) {
      printf("\nYou see a book with a strange symbol on the cover.\n");
      printf("Do you open it? (y/n) ");
      scanf(" %c", &response);
      
      if (response == 'y') {
        printf("\nYou open the book and a gust of wind blows out the candles.\n");
        room = 3;
      } else if (response == 'n') {
        printf("\nYou put the book back on the shelf and continue on your way.\n");
        room = 0;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    if (room == 2) {
      if (chance < 25) {
        printf("\nYou hear a loud noise coming from the basement.\n");
        room = 4;
      } else {
        printf("\nYou find a key hanging on the wall.\n");
        printf("Do you take it? (y/n) ");
        scanf(" %c", &response);
        
        if (response == 'y') {
          printf("\nYou take the key and continue on your way.\n");
          room = 0;
        } else if (response == 'n') {
          printf("\nYou leave the key and continue on your way.\n");
          room = 0;
        } else {
          printf("That's not a valid response.\n");
          steps++;
          continue;
        }
      }
    }
    
    if (room == 3) {
      if (chance < 50) {
        printf("\nYou hear a faint whisper coming from the pages of the book.\n");
        room = 5;
      } else {
        printf("\nYou continue through the library and find a staircase leading up.\n");
        room = 6;
      }
    }
    
    if (room == 4) {
      printf("\nYou descend the stairs to the basement...\n");
      printf("It's pitch dark.\n");
      printf("Do you have a light source? (y/n) ");
      scanf(" %c", &response);
      
      if (response == 'y') {
        printf("\nYou turn on your flashlight and see a ghostly figure in front of you!\n");
        room = 7;
      } else if (response == 'n') {
        printf("\nYou fumble in the dark and trip over a stair.\n");
        printf("You hear a creaking noise coming from the darkness.\n");
        room = 8;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    if (room == 5) {
      printf("\nThe whisper gets louder and you start to feel a cold breeze.\n");
      printf("Do you stay and investigate or run away? (s/r) ");
      scanf(" %c", &response);
      
      if (response == 's') {
        printf("\nYou investigate the source of the whisper and find a secret passage!\n");
        room = 9;
      } else if (response == 'r') {
        printf("\nYou run away as fast as you can, back to the hallway.\n");
        room = 0;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    if (room == 6) {
      printf("\nYou climb the stairs to the second floor...\n");
      printf("You see a shadowy figure at the end of the hallway.\n");
      printf("Do you approach it or turn back? (a/t) ");
      scanf(" %c", &response);
      
      if (response == 'a') {
        printf("\nAs you walk closer, the figure disappears into thin air!\n");
        room = 10;
      } else if (response == 't') {
        printf("\nYou turn back and descend the stairs to the hallway.\n");
        room = 0;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    if (room == 7) {
      printf("\nThe ghostly figure floats toward you...\n");
      printf("Do you run or face it head-on? (r/f) ");
      scanf(" %c", &response);
      
      if (response == 'r') {
        printf("\nYou turn and sprint up the stairs, back to the hallway.\n");
        room = 0;
      } else if (response == 'f') {
        printf("\nYou face the ghost head-on and it disappears!\n");
        printf("You find a skeleton key in its place.\n");
        room = 0;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    if (room == 8) {
      printf("\nThe creaking noise gets louder and you feel a cold breath on your neck.\n");
      printf("Do you stay and investigate or flee for your life? (s/f) ");
      scanf(" %c", &response);
      
      if (response == 's') {
        printf("\nYou turn around and come face to face with a dark figure!\n");
        printf("It lunges at you and you hear a piercing scream!\n");
        printf("You have died...\n");
        return 0; // End program
      } else if (response == 'f') {
        printf("\nYou run up the stairs as fast as you can!\n");
        room = 0;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    if (room == 9) {
      printf("\nYou crawl through the passage and find a hidden room!\n");
      printf("There is a chest in the middle of the room.\n");
      printf("Do you open it? (y/n) ");
      scanf(" %c", &response);
      
      if (response == 'y') {
        printf("\nYou open the chest and find a treasure trove!\n");
        printf("You win!\n");
        return 0; // End program
      } else if (response == 'n') {
        printf("\nYou leave the chest and crawl back through the passage.\n");
        room = 5;
      } else {
        printf("That's not a valid response.\n");
        steps++;
        continue;
      }
    }
    
    steps++; // Increment steps taken
    printf("\nYou are now in room %d.\n", room);
  }
  
  printf("\nYou have reached the end of the haunted house!\n");
  printf("It took you %d steps to get there.\n", steps);
  
  return 0; // End program
}