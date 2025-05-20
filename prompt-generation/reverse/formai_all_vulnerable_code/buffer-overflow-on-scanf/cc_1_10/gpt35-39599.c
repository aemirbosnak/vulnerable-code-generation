//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int choices(void);
void forest(void);
void town(void);
void shop(void);
void quests(void);

int main() {
  printf("Welcome to the happy adventure game!\n");
  printf("You are a cheerful adventurer feeling brave and ready for anything!\n");

  int choice = choices();
  while (choice != 3) {
    switch (choice) {
      case 1:
        forest();
        break;
      case 2:
        town();
        break;
      default:
        printf("I didn't understand your choice. Try again.\n");
    }
    choice = choices();
  }

  printf("Thanks for playing! Goodbye!\n");
  return 0;
}

int choices(void) {
  int choice;
  printf("\nChoose your adventure:\n");
  printf("1. Explore the forest\n");
  printf("2. Visit the town\n");
  printf("3. Quit the game\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

void forest(void) {
  printf("\nYou are now in the happy forest! Look around and see what adventures you can find!\n");
  int randnum = rand() % 10;
  if (randnum == 0) {
    printf("Congratulations! You found a treasure chest!\n");
  } else if (randnum <= 2) {
    printf("You encountered a happy rabbit! It hops around you and then runs away.\n");
  } else if (randnum <= 4) {
    printf("You stumbled upon a babbling brook. You take a refreshing drink.\n");
  } else if (randnum <= 6) {
    printf("You found some beautiful wildflowers. You pick some for later.\n");
  } else {
    printf("You encounter a group of playful squirrels. They climb on your shoulder and then run away.\n");
  }
}

void town(void) {
  printf("\nYou have arrived at the happy town. Look around and see what adventures you can find!\n");
  int randnum = rand() % 10;
  if (randnum == 0) {
    shop();
  } else if (randnum <= 2) {
    quests();
  } else if (randnum <= 4) {
    printf("You encounter a group of happy children playing tag. You join in the game.\n");
  } else if (randnum <= 6) {
    printf("You find a happy bakery and smell the delicious treats. You buy a cake and eat it happily.\n");
  } else {
    printf("You encounter an old friend in the town square. You spend some time catching up.\n");
  }
}

void shop(void) {
  printf("Congratulations! You found a magical shop!\n");
  printf("Enter the number of the item you would like to buy:\n");
  printf("1. Magic wand - 50 gold coins\n");
  printf("2. Potion of healing - 25 gold coins\n");
  printf("3. Phoenix feather - 75 gold coins\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("You buy a magic wand! Good luck on your adventures!\n");
      break;
    case 2:
      printf("You buy a potion of healing! Don't forget to drink it when you need it!\n");
      break;
    case 3:
      printf("You buy a phoenix feather! This will surely come in handy!\n");
      break;
    default:
      printf("That item doesn't exist in the shop. Try again later.\n");
  }
}

void quests(void) {
  printf("Welcome to the happy quest board!\n");
  printf("Choose your quest:\n");
  printf("1. Rescue the happy princess from the tower.\n");
  printf("2. Find the lost puppy and return it to its happy owner.\n");
  printf("3. Gather the ingredients to make a magical cake.\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("You embark on a journey to rescue the happy princess from the tower. Good luck!\n");
      break;
    case 2:
      printf("You set off to find the lost puppy. Don't forget to bring it back to its happy owner!\n");
      break;
    case 3:
      printf("You gather all the ingredients to make the magical cake. This will be a delicious adventure!\n");
      break;
    default:
      printf("That quest doesn't exist on the board. Try again later.\n");
  }
}