//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int room = 1; // Start in Room 1
  char input[50]; // Used to get user input
  int playing = 1; // 1 if still playing, 0 if game over

  printf("Welcome to Adventure Game!\n");

  while(playing){

    // Print room description
    if(room == 1){
      printf("You are in a dark room. You can see a door to the north.\n");
    }
    else if(room == 2){
      printf("You find yourself in a room with a table and a chair. There is an envelope on the table.\n");
    }
    else{
      printf("You are in a room with a giant spider! The door behind you is locked.\n");
    }

    // Get user input
    printf("What do you do? ");
    fgets(input, 50, stdin);

    // Remove newline character
    input[strlen(input)-1] = '\0';

    // Respond to user input
    if(strcasecmp(input, "north")==0 && room==1){
      room = 2;
      printf("You go north and enter a new room.\n");
    }
    else if(strcasecmp(input, "open envelope")==0 && room==2){
      printf("Inside the envelope is a key!\n");
    }
    else if(strcasecmp(input, "take key")==0 && room==2){
      printf("You take the key.\n");
    }
    else if(strcasecmp(input, "use key")==0 && room==3){
      printf("You use the key to unlock the door and escape the spider!\n");
      printf("Congratulations! You have completed Adventure Game.\n");
      playing = 0; // End game
    }
    else{
      printf("I don't understand.\n");
    }

  }

  return 0;
}