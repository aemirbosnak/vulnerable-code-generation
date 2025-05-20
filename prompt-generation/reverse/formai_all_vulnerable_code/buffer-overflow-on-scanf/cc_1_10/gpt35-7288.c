//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>

int main() {

  printf("Welcome to my game!\n");
  
  // Introducing the game
  printf("In this game, you are a detective who has to solve a murder mystery.\n");
  
  // Asking for player name
  printf("What is your name, detective?\n");
  char player_name[50];
  scanf("%s", player_name);
  
  printf("Nice to meet you, %s. Let's begin the investigation.\n", player_name);
  
  // Setting up the game variables
  int clues_found = 0;
  int suspects_left = 3;
  int correct_suspect = 2;
  
  // Printing out the suspects
  printf("Here are the suspects:\n");
  printf("1. Mr. Green\n");
  printf("2. Ms. Scarlet\n");
  printf("3. Professor Plum\n");
  
  // Beginning the game loop
  while (suspects_left > 1) {
    
    // Asking the player for input
    printf("Which suspect would you like to investigate next?\n");
    int suspect_choice;
    scanf("%d", &suspect_choice);
    
    // Checking if the input is valid
    if (suspect_choice < 1 || suspect_choice > 3) {
      printf("Invalid input. Please choose a number between 1 and 3.\n");
      continue;
    }
    
    // Checking if the player has already investigated the suspect
    if (suspect_choice == correct_suspect) {
      printf("You have already found the correct suspect. Please investigate another suspect.\n");
      continue;
    }
    
    // Printing out the investigation results
    printf("You investigate %s...\n", (suspect_choice == 1) ? "Mr. Green" : (suspect_choice == 2) ? "Ms. Scarlet" : "Professor Plum");
    printf("You find a clue!\n");
    clues_found++;
    
    // Updating the suspects left
    suspects_left--;
  }
  
  // Checking if the player has won or lost
  if (clues_found >= 3) {
    printf("Congratulations, detective %s! You have found enough clues to solve the mystery and catch the killer!\n", player_name);
  } else {
    printf("Sorry, detective %s. You did not find enough clues to solve the mystery. The killer got away...\n", player_name);
  }
  
  return 0;
}