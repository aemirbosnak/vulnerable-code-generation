//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  printf("Welcome to the Fantasy Adventure Game!\n");
  printf("Please enter your character name: ");
  fgets(input, 100, stdin);
  strtok(input, "\n"); // remove newline character from input
  printf("\nWelcome, %s! You are about to embark on a dangerous journey through the mystical land of Eldrid.\n", input);
  printf("You find yourself standing at the mouth of a cave. You have no memory of how you got here.\n");
  printf("What do you do?\n");
  printf("1. Enter the cave.\n");
  printf("2. Look for another way out.\n");
  
  int choice;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nYou boldly enter the cave, ready for whatever dangers may lie ahead.\n");
      printf("After walking for what seems like hours, you come across a fork in the path.\n");
      printf("Do you go left or right?\n");
      printf("1. Left.\n");
      printf("2. Right.\n");

      int choice2;
      scanf("%d", &choice2);

      if (choice2 == 1) {
        printf("\nYou take the left path. As you continue down the dark and winding tunnel, you begin to hear strange noises.\n");
        printf("Suddenly, you hear a loud growl from up ahead, and a large shape emerges from the shadows.\n");
        printf("It's a giant troll, and it's coming straight for you!\n");
        printf("You have no choice but to draw your weapon and fight.\n");
        printf("\n***Battle begins***\n");
        // code for battle sequence here
      } else if (choice2 == 2) {
        printf("\nYou take the right path and walk for a bit, finding nothing of interest.\n");
        printf("Just when you start to wonder if you made the wrong choice, you come across a large room.\n");
        printf("In the center of the room is a treasure chest!\n");
        printf("You cautiously approach the chest, careful to avoid any traps that may be present.\n");
        printf("You open the chest and find an ancient map, detailing the location of a powerful artifact!\n");
        printf("You decide to explore the rest of the cave and see what other secrets it may hold.\n");
        // code for exploring the rest of the cave here
      } else {
        printf("\nInvalid choice! You stand at the fork in the path, unsure of where to go.\n");
      }
      break;

    case 2:
      printf("\nYou decide to look for another way out of the cave. You walk for a while, searching for a way out.\n");
      printf("Eventually, you come across a hidden door, concealed by vines and moss.\n");
      printf("You remove the vines and push open the door, revealing an ancient temple.\n");
      printf("The temple is full of treasure, but also traps and guardians.\n");
      printf("Do you dare to explore the temple?\n");
      printf("1. Yes!\n");
      printf("2. No, I'd rather leave while I still can.\n");

      int choice3;
      scanf("%d", &choice3);

      if (choice3 == 1) {
        printf("\nYou bravely enter the temple, ready for whatever challenges may come your way.\n");
        printf("You face deadly traps and ancient guardians, but finally, you find the artifact you were searching for.\n");
        printf("With the artifact in your possession, you are able to make your way out of the temple and back to safety.\n");
        // code for obtaining the artifact and escaping the temple here
      } else if (choice3 == 2) {
        printf("\nYou decide that the temple is too dangerous and choose to leave while you still can.\n");
        printf("You make your way out of the cave and back to civilization.\n");
      } else {
        printf("\nInvalid choice! You stand at the hidden door, unsure of what to do.\n");
      }
      break;

    default:
      printf("\nInvalid choice! You stand at the mouth of the cave, unsure of what to do.\n");
      break;
  }

  printf("\nThanks for playing the Fantasy Adventure Game!\n");
  return 0;
}