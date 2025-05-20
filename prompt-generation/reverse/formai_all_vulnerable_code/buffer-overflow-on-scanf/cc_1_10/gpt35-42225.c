//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You find yourself in a dark hallway...\n");
  printf("What do you want to do?\n");
  printf("1. Walk forward\n");
  printf("2. Turn back\n");
  
  int choice;
  scanf("%d", &choice);
  
  if(choice == 1) {
    printf("You walk forward, but suddenly the floor disappears beneath you!\n");
    printf("You fall through a trapdoor into a room filled with cobwebs.\n");
    printf("What do you want to do?\n");
    printf("1. Look around\n");
    printf("2. Try to climb out\n");
    
    scanf("%d", &choice);
    
    if(choice == 1) {
      printf("As you look around, you notice a dusty bookshelf in the corner.\n");
      printf("You walk over to it and see a book with the title 'Dark Magic Spells'.\n");
      printf("Do you want to read it?\n");
      printf("1. Yes\n");
      printf("2. No\n");
      
      scanf("%d", &choice);
      
      if(choice == 1) {
        printf("As you start to read the book, you feel a cold breeze.\n");
        printf("Suddenly, a ghostly figure appears in front of you!\n");
        printf("You try to run, but tripped over a piece of furniture that was not there before.\n");
        printf("You scream, and everything goes black...\n");
      }
      else {
        printf("You walk away from the bookshelf, and suddenly a ghostly figure appears in front of you!\n");
        printf("You try to run, but tripped over a piece of furniture that was not there before.\n");
        printf("You scream, and everything goes black...\n");
      }
    }
    else {
      printf("You try to climb out, but the walls are too smooth to grip.\n");
      printf("You hear a low growling and strange whispers coming from the darkness...\n");
      printf("Suddenly, a ghostly figure appears in front of you!\n");
      printf("You try to run, but tripped over a piece of furniture that was not there before.\n");
      printf("You scream, and everything goes black...\n");
    }
  }
  else {
    printf("You turn back, but the door slams shut behind you!\n");
    printf("You are trapped in the hallway.\n");
    printf("What do you want to do?\n");
    printf("1. Look for another exit\n");
    printf("2. Try to break the door open\n");
    
    scanf("%d", &choice);
    
    if(choice == 1) {
      printf("You walk down the hallway, but notice that the wallpaper is peeling off the walls.\n");
      printf("Suddenly, the walls seem to move and close in on you!\n");
      printf("You try to run, but the hallway gets longer and longer...\n");
      printf("You scream, and everything goes black...\n");
    }
    else {
      printf("You try to break the door open, but it won't budge.\n");
      printf("You hear a low growling and strange whispers coming from the darkness...\n");
      printf("Suddenly, a ghostly figure appears in front of you!\n");
      printf("You try to run, but tripped over a piece of furniture that was not there before.\n");
      printf("You scream, and everything goes black...\n");
    }
  }
  
  printf("GAME OVER\n");
  return 0;
}