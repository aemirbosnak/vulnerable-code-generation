//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void menu();
void prologue();
void act_one();
void act_two();

int main(){

  char input[50];
  
  prologue();
  menu();

  while(1){
    scanf("%s", input);
    if(strcmp(input, "help") == 0){
      menu();
    }
    else if(strcmp(input, "begin") == 0){
      act_one();
      act_two();
      printf("\nCongratulations, you have successfully completed the game!\n");
      break;
    }
    else{
      printf("Invalid command, please type 'help' for available options.\n");
    }
  }

  return 0;
}

void menu(){
  printf("----------Adventures of the Curious Cat---------\n");
  printf("Commands: \n");
  printf("'help' - display available options.\n");
  printf("'begin' - embark on your adventure.\n");
  printf("-----------------------------------------------\n");
}

void prologue(){
  printf("Hello there curious cat!\n");
  printf("Welcome to the Adventures of the Curious Cat game!\n");
  printf("In this game you will navigate through various obstacles and solve puzzles to complete your quest.\n");
  printf("Are you ready to embark on the adventure?\n");
}

void act_one(){
  char input[50];
  printf("\nAct 1 - The Missing Fish\n");
  printf("You awaken to find your favorite fish has gone missing from its bowl!\n");
  printf("You must find a way to locate your fish, but first you must get out of the house.\n");
  printf("Look around the room and find the key to unlock the door.\n");
  
  while(1){
    scanf("%s", input);
    if(strstr(input, "look") != NULL){
      printf("You look around and notice the key sitting on the table.\n");
    }
    else if(strstr(input, "take") != NULL || strstr(input, "grab") != NULL || strstr(input, "pick") != NULL){
      printf("You pick up the key and insert it into the door lock.\n");
      break;
    }
    else{
      printf("Invalid command, please try again.\n");
    }
  }
}

void act_two(){
  char input[50];
  printf("\nAct 2 - The Mysterious Forest\n");
  printf("You enter the forest outside your house and are immediately surrounded by tall trees and thick fog.\n");
  printf("You must find your way through the forest to the lake where your fish is located.\n");
  printf("Navigate through the forest by typing 'forward', 'left', 'right', or 'back'.\n");

  int direction = 0;
  int lake_found = 0;

  while(!lake_found){
    scanf("%s", input);
    if(strstr(input, "forward") != NULL){
      direction++;
      printf("You move forward.\n");
    }
    else if(strstr(input, "right") != NULL){
      direction++;
      direction++;
      printf("You turn right and move forward.\n");
    }
    else if(strstr(input, "left") != NULL){
      direction--;
      direction--;
      printf("You turn left and move forward.\n");
    }
    else if(strstr(input, "back") != NULL){
      direction--;
      printf("You turn around and move back.\n");
    }
    else{
      printf("Invalid command, please try again.\n");
    }

    if(direction == 5){
      printf("You made it to the lake and find your fish swimming happily!\n");
      printf("Congratulations, you completed your adventure!\n");
      lake_found = 1;
    }
  }
}