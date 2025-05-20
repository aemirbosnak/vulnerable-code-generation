//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator
  
  int room = 1; // Starting room
  int ghostEncounter = 0; // Counter for ghost encounters
  int hasKey = 0; // Flag for whether the user has found the key
  int foundFlashlight = 0; // Flag for whether the user has found the flashlight
  int foundHammer = 0; // Flag for whether the user has found the hammer
  
  printf("Welcome to the Haunted House Simulator!\n\n");
  printf("You find yourself standing in front of an old, decrepit mansion. The wind howls around you and the moon casts eerie shadows on the building.\n\n");
  printf("Press Enter to enter the house...\n\n");
  getchar(); // Wait for user to press Enter
  
  // Game loop
  while (1) {
    printf("You are in room %d.\n\n", room);
    
    // Check for key
    if (room == 2 && hasKey == 0) {
      printf("You see a key sitting on a table.\n\n");
    }
    
    // Check for flashlight
    if (room == 3 && foundFlashlight == 0) {
      printf("You see a flashlight on the ground.\n\n");
    }
    
    // Check for hammer
    if (room == 5 && foundHammer == 0) {
      printf("You see a hammer leaning against the wall.\n\n");
    }
    
    // Ghost encounter
    if (rand() % 5 == 0) {
      printf("A ghost appears in front of you!\n\n");
      ghostEncounter++;
      
      if (ghostEncounter == 3) {
        printf("That's it, you've had enough. You turn and run for the exit, never looking back.\n\n");
        printf("GAME OVER. You encountered 3 ghosts.\n");
        break; // End game
      }
    }
    
    // Prompt user for action
    printf("What do you want to do?\n");
    printf("(1) Go forward\n");
    printf("(2) Go back\n");
    printf("(3) Look around\n");
    printf("(4) Use item\n\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
      case 1: // Go forward
        if (room == 7) { // Final room
          printf("Congratulations, you made it to the end of the haunted house!\n");
          printf("You encountered %d ghosts during your journey.\n", ghostEncounter);
          printf("Thanks for playing!\n");
          return 0; // End game
        }
        else {
          room++;
        }
        break;
        
      case 2: // Go back
        if (room == 1) { // Can't go back from starting room
          printf("You can't go back from here.\n\n");
        }
        else {
          room--;
        }
        break;
        
      case 3: // Look around
        switch (room) {
          case 1: // Starting room
            printf("You see a coat rack and a mirror.\n\n");
            break;
            
          case 2: // Dining room
            printf("You see a long dining table with cobwebs covering the chairs.\n\n");
            break;
            
          case 3: // Living room
            printf("You see a fireplace with some embers still glowing, casting flickering shadows on the walls.\n\n");
            break;
            
          case 4: // Kitchen
            printf("You see pots and pans hanging from the ceiling, and a small stove in the corner.\n\n");
            break;
            
          case 5: // Study
            printf("You see a bookshelf filled with dusty old books, and a desk covered in papers.\n\n");
            break;
            
          case 6: // Attic
            printf("You see old trunks piled high and cobwebs hanging from the rafters.\n\n");
            break;
            
          case 7: // Exit
            printf("You see a door with a rusty lock.\n\n");
            break;
        }
        break;
        
      case 4: // Use item
        switch (room) {
          case 2: // Dining room
            if (hasKey == 0) { // Key has not been found yet
              printf("You found a key!\n\n");
              hasKey = 1;
            }
            else {
              printf("You've already taken everything of value from this room.\n\n");
            }
            break;
            
          case 3: // Living room
            if (foundFlashlight == 0) { // Flashlight has not been found yet
              printf("You found a flashlight!\n\n");
              foundFlashlight = 1;
            }
            else {
              printf("You've already taken everything of value from this room.\n\n");
            }
            break;
            
          case 5: // Study
            if (foundHammer == 0) { // Hammer has not been found yet
              printf("You found a hammer!\n\n");
              foundHammer = 1;
            }
            else {
              printf("You've already taken everything of value from this room.\n\n");
            }
            break;
            
          default:
            printf("There's nothing to use here.\n\n");
            break;
        }
        break;
        
      default:
        printf("Please enter a valid choice.\n\n");
        break;
    }
  }
  
  return 0;
}