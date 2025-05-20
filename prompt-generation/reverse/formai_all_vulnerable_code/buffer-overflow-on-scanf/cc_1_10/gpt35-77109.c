//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>

// function to print the game title
void printTitle() {
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("  The Adventure of the Lost Island  \n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

// function to print the game over message
void printGameOver() {
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("            GAME OVER!              \n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main() {
  int choice;

  // introduction message
  printf("Welcome to The Adventure of the Lost Island!\n");

  // print the game title
  printTitle();

  // print the game objective
  printf("Objective: You are stranded on a lost island. Your goal is to find a way back home.\n");

  // prompt the user to make a choice
  printf("Enter 1 to start the adventure: ");
  scanf("%d", &choice);

  // validate the user's input
  if (choice != 1) {
    printf("Invalid choice. The adventure cannot start.\n");
    printGameOver();
    return 1;
  }

  // begin the adventure
  printTitle();
  printf("You wake up on the beach of a lost island. The sun is shining above you. You feel thirsty and hungry. \n");

  // prompt the user for their next move
  printf("What will you do?\n");
  printf("1. Search for food and water.\n");
  printf("2. Explore the island.\n");
  printf("3. Stay on the beach and wait for rescue.\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You decide to search for food and water. You find a coconut tree and a stream. You drink water from the stream and eat the coconut.\n");
      break;
    case 2:
      printf("You explore the island and find an abandoned hut. You enter the hut and find a map and a compass. You realize that the island is uninhabited and the only way to leave is by building a raft. You decide to search for materials to build a raft.\n");
      break;
    case 3:
      printf("You decide to stay on the beach and wait for rescue. However, after a few days, you realize that no one is coming to rescue you. You must find a way to leave the island on your own.\n");
      break;
    default:
      printf("Invalid choice. The adventure cannot continue.\n");
      printGameOver();
      return 1;
  }

  // continue the adventure
  printf("You continue your search for materials to build a raft. You find some wood and vines. You use the map and compass to find a good spot to build the raft.\n");

  // prompt the user for their next move
  printf("What will you do next?\n");
  printf("1. Build the raft.\n");
  printf("2. Look for more materials.\n");
  printf("3. Rest for a while.\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You build the raft using the wood and vines you collected. It takes you several days to complete the raft. Finally, you set sail and head towards the open sea. After a few days, you are rescued by a passing ship. You are finally going home.\n");
      break;
    case 2:
      printf("You continue to search for more materials. You spend several days searching but find nothing useful. You begin to feel discouraged and decide to rest.\n");
      break;
    case 3:
      printf("You rest for a while and regain your strength. You then resume your search for materials.\n");
      break;
    default:
      printf("Invalid choice. The adventure cannot continue.\n");
      printGameOver();
      return 1;
  }

  // continue the adventure
  printf("You finally have enough materials to build the raft. You spend several days building the raft. Finally, the raft is complete.\n");

  // prompt the user for their next move
  printf("What will you do next?\n");
  printf("1. Set sail immediately.\n");
  printf("2. Wait for a better weather condition.\n");
  printf("3. Check the raft for any defects.\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You set sail immediately. However, the weather condition was not good. The raft capsizes, and you are stranded on the island once again. The adventure ends here.\n");
      printGameOver();
      return 1;
    case 2:
      printf("You decide to wait for a better weather condition. After a few days, the weather condition improves, and you set sail. Finally, you are rescued by a passing ship. You are finally going home.\n");
      break;
    case 3:
      printf("You check the raft for any defects and fix any issues found. Finally, the raft is ready to set sail.\n");
      break;
    default:
      printf("Invalid choice. The adventure cannot continue.\n");
      printGameOver();
      return 1;
  }

  // continue the adventure
  printf("You set sail using the raft. After several days, you finally see a passing ship. You wave your hands and shout for help. The ship eventually sees you and sends a rescue team. Finally, you are rescued, and you are going home.\n");

  // print game over message and exit
  printGameOver();
  return 0;
}