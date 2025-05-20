//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed for random number generator
  int choice;

  printf("\nWelcome to the Kingdom of Adventure!\n");
  printf("You find yourself in the middle of a dense forest. You can hear faint music coming from the east and you can see a dim light to the west.\n");
  printf("What do you want to do?\n");
  printf("1. Head east towards the music\n");
  printf("2. Head west towards the light\n");
  printf("3. Stay where you are\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("\nYou head towards the music and reach a clearing. You see a group of elves dancing around a bonfire. They invite you to join them.\n");
      printf("What do you want to do?\n");
      printf("1. Join the elves\n");
      printf("2. Refuse their offer and continue on your journey\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      if(choice == 1) {
        int num = rand() % 5 + 1; // generate a random number between 1 and 5
        if(num == 1) {
          printf("\nThe elves welcome you with open arms and give you a magical sword.\n");
        } else if(num == 2) {
          printf("\nThe elves offer you food and drink. You feel rejuvenated.\n");
        } else if(num == 3) {
          printf("\nThe elves teach you a new spell.\n");
        } else if(num == 4) {
          printf("\nThe elves perform a healing ritual on you. Your wounds are healed.\n");
        } else {
          printf("\nThe elves warn you of danger ahead and give you a map.\n");
        }
      } else {
        printf("\nYou continue on your journey.\n");
      }
      break;
      
    case 2:
      printf("\nYou head towards the light and reach a cave. You can hear strange sounds coming from inside.\n");
      printf("What do you want to do?\n");
      printf("1. Enter the cave\n");
      printf("2. Go back the way you came\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      if(choice == 1) {
        int num = rand() % 5 + 1;
        if(num == 1) {
          printf("\nYou discover a treasure hoard in the cave.\n");
        } else if(num == 2) {
          printf("\nYou encounter a dragon in the cave. You must defeat it to continue on your journey.\n");
        } else if(num == 3) {
          printf("\nYou find a mysterious potion in the cave. You drink it and feel invigorated.\n");
        } else if(num == 4) {
          printf("\nYou find a key in the cave. You don't know what it unlocks yet.\n");
        } else {
          printf("\nThe cave leads to a secret underground city. You explore the city and find many treasures.\n");
        }
      } else {
        printf("\nYou continue on your journey.\n");  
      }
      break;
      
    case 3:
      printf("\nYou stay in the forest and rest.\n");
      printf("You feel refreshed and continue on your journey.\n");
      break;
      
    default:
      printf("\nInvalid choice.\n");
      break;
  }
  
  printf("\nThanks for playing!\n");
  
  return 0;
}