//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char name[20];
  int choice1, choice2;
  
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("First, please enter your name: ");
  scanf("%s", name);
  
  printf("Okay, %s, let's get started. You find yourself standing at a fork in the road.\n");
  printf("Do you go left or right? (1 for left, 2 for right): ");
  scanf("%d", &choice1);
  
  if(choice1 == 1) {
    printf("You head down the left path and come across a river. Do you swim across or try to find a bridge? (1 for swim, 2 for bridge): ");
    scanf("%d", &choice2);
    if(choice2 == 1) {
      printf("You start to swim across the river, but quickly realize the current is too strong. You are swept away and never seen again. GAME OVER.\n");
      exit(0);
    } else if(choice2 == 2) {
      printf("After some searching, you find a rickety old bridge that looks like it could collapse at any moment. You carefully cross the bridge and continue on your journey.\n");
      printf("You come across a group of bandits. Do you try to fight them or run away? (1 for fight, 2 for run): ");
      scanf("%d", &choice2);
      if(choice2 == 1) {
        printf("You are no match for the bandits and are killed in the fight. GAME OVER.\n");
        exit(0);
      } else if(choice2 == 2) {
        printf("You manage to outrun the bandits and continue on your journey.\n");
        printf("You come across a castle. Do you try to enter or continue on your journey? (1 for enter, 2 for continue): ");
        scanf("%d", &choice2);
        if(choice2 == 1) {
          printf("You sneak into the castle, but are caught by the guards. You are thrown into the dungeon and left to rot. GAME OVER.\n");
          exit(0);
        } else if(choice2 == 2) {
          printf("You continue on your journey and eventually reach your destination. Congratulations, you have survived the Text-Based Adventure Game!\n");
          exit(0);
        } else {
          printf("Invalid input. GAME OVER.\n");
          exit(0);
        }
      } else {
        printf("Invalid input. GAME OVER.\n");
        exit(0);
      }
    } else {
      printf("Invalid input. GAME OVER.\n");
      exit(0);
    }
  } else if(choice1 == 2) {
    printf("You head down the right path and come across a cave. Do you enter the cave or continue on your journey? (1 for enter, 2 for continue): ");
    scanf("%d", &choice2);
    if(choice2 == 1) {
      printf("You enter the cave and come across a treasure chest. Do you open the chest or leave it alone? (1 for open, 2 for leave): ");
      scanf("%d", &choice2);
      if(choice2 == 1) {
        printf("As soon as you open the chest, a poison dart shoots out and kills you. GAME OVER.\n");
        exit(0);
      } else if(choice2 == 2) {
        printf("You leave the chest alone and continue on your journey.\n");
        printf("You come across a village. Do you stop to rest or continue on your journey? (1 for stop, 2 for continue): ");
        scanf("%d", &choice2);
        if(choice2 == 1) {
          printf("While in the village, you are mistaken for a thief and are thrown into jail. GAME OVER.\n");
          exit(0);
        } else if(choice2 == 2) {
          printf("You continue on your journey and eventually reach your destination. Congratulations, you have survived the Text-Based Adventure Game!\n");
          exit(0);
        } else {
          printf("Invalid input. GAME OVER.\n");
          exit(0);
        }
      } else {
        printf("Invalid input. GAME OVER.\n");
        exit(0);
      }
    } else if(choice2 == 2) {
      printf("You continue on your journey and eventually reach your destination. Congratulations, you have survived the Text-Based Adventure Game!\n");
      exit(0);
    } else {
      printf("Invalid input. GAME OVER.\n");
      exit(0);
    }
  } else {
    printf("Invalid input. GAME OVER.\n");
    exit(0);
  }
  
  return 0;
}