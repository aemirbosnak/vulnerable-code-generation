//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>

int main() {
  printf("Welcome to The Magical Forest Adventure!\n");
  printf("You find yourself in a mystical forest with a dimly lit path ahead.\n");
  printf("Would you like to go left or right? Type L for left or R for right.\n");

  char choice;
  scanf("%c", &choice);

  if (choice == 'L') {
    printf("You venture left down the path and come across a glowing flower.\n");
    printf("As you pick the flower, you feel yourself being lifted up into the air.\n");
    printf("You are now being whisked away to a new land.\n");
    printf("You have been teleported to the land of dragons!\n");
    printf("There's an angry dragon in front of you. He looks like he's going to attack. Type F to fight or R to run.\n");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'F') {
      printf("You successfully defeated the dragon! You are a true warrior.\n");
      printf("You have earned a new sword and moved on to the next level.\n");
    } else if (choice == 'R') {
      printf("You failed to defeat the dragon and ran back to the forest.\n");
      printf("You quickly realize that you left the glowing flower behind and cannot return to the land of dragons.\n");
    } else {
      printf("I am sorry, that is not a valid choice. Please try again.\n");
      return 0;
    }
  } else if (choice == 'R') {
    printf("You venture right down the path and come across a lost child.\n");
    printf("The child looks scared and lost. Will you help the child? Type Y for Yes or N for No.\n");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'Y') {
      printf("You successfully guide the child back to their home. You feel good knowing that you helped someone in need.\n");
      printf("You have earned a new power and moved on to the next level.\n");
    } else if (choice == 'N') {
      printf("You choose to ignore the child and continue on your path.\n");
      printf("As you walk away, you regret your decision and feel guilty for not helping the child.\n");
    } else {
      printf("I am sorry, that is not a valid choice. Please try again.\n");
      return 0;
    }
  } else {
    printf("I am sorry, that is not a valid choice. Please try again.\n");
    return 0;
  }

  printf("Congratulations! You have completed The Magical Forest Adventure.\n");
  printf("Thank you for playing!\n");

  return 0;
}