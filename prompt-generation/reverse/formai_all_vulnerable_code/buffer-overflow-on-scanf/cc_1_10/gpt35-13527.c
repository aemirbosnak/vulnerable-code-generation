//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>

int main() {
  int score = 0;
  printf("Welcome to the magical world of unicorns!\n");
  printf("What is your name, adventurer?\n");
  char name[20];
  scanf("%s", name);
  printf("Greetings, %s! Let's begin our journey!\n\n", name);

  printf("You are walking through a forest when you come across a mysterious creature...\n");
  printf("It's a unicorn! And it seems friendly...\n");
  printf("The unicorn speaks to you:\n");
  printf("\"Hello, adventurer! I'm in a bit of a pickle. I've lost my magical horn and I can't find it anywhere. Can you help me?\"\n\n");

  printf("You agree to help the unicorn and set off into the forest.\n");
  printf("After a while of searching, you come across a clearing.\n");
  printf("You notice a glint on the ground. Could it be the unicorn's horn?\n");
  printf("You approach the glint and see a pile of treasure. Could there be a trap?\n\n");

  int choice1;
  printf("Do you:\n");
  printf("1) Take the treasure\n");
  printf("2) Leave the treasure and keep looking for the horn\n");
  scanf("%d", &choice1);

  if (choice1 == 1) {
    printf("\nAs you approach the treasure, a group of trolls ambush you!\n");
    printf("You try to fight them off, but their numbers are too great.\n");
    printf("You lose the horn and the treasure. Game over, %s!\n", name);
    return 0;
  } else if (choice1 == 2) {
    printf("\nYou leave the treasure behind and keep searching for the unicorn's horn.\n");
    printf("After a while, you come across a beautiful meadow.\n");
    printf("You see the horn resting on a tree stump in the center of the meadow.\n");
    printf("You make your way towards the horn, but suddenly...\n");

    int choice2;
    printf("Do you:\n");
    printf("1) Run towards the horn\n");
    printf("2) Look around for danger\n");
    scanf("%d", &choice2);

    if (choice2 == 1) {
      printf("\nYou run towards the horn, but a group of trolls ambush you!\n");
      printf("You try to fight them off, but their numbers are too great.\n");
      printf("You lose the horn and the trolls take you captive. Game over, %s!\n", name);
      return 0;
    } else if (choice2 == 2) {
      printf("\nYou look around for danger and see a group of trolls hiding in the bushes.\n");
      printf("You devise a plan to distract the trolls so you can grab the horn.\n");
      printf("You make your way towards the horn, keeping an eye on the trolls.\n");
      printf("You grab the horn and run as fast as you can!\n\n");

      printf("You make it back to the unicorn and return the horn.\n");
      printf("\"Thank you so much, %s! You're a true hero!\", says the unicorn.\n", name);
      printf("You gain 100 points!\n\n");
      score += 100;

      printf("Suddenly, a portal opens up and sucks you in!\n\n");
      printf("You find yourself in a strange laboratory.\n");
      printf("There's a scientist in the room with you.\n");
      printf("The scientist speaks to you:\n");
      printf("\"Welcome, adventurer! I've been expecting you.\"\n");
      printf("\"I need your help. I've been working on a new invention, but it's missing a key component.\"\n");
      printf("\"I need a piece of a rare crystal that can only be found in the caves of Mount Doom.\"\n");
      printf("\"Will you help me retrieve the crystal?\"\n\n");

      int choice3;
      printf("Do you:\n");
      printf("1) Agree to help the scientist\n");
      printf("2) Refuse to help the scientist\n");
      scanf("%d", &choice3);

      if (choice3 == 1) {
        printf("\nYou agree to help the scientist and set off on your next quest.\n");
        printf("Good luck, %s!\n", name);
      } else if (choice3 == 2) {
        printf("\nYou refuse to help the scientist and decide to go home instead.\n");
        printf("Thanks for playing, %s! Your final score is %d.\n", name, score);
        return 0;
      }
    }
  }

  return 0;
}