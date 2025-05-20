//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>

int main() {
  char playerName[20];
  int questChoice;
  int gold = 0;
  int goblinsKilled = 0;
  int trollsKilled = 0;
  
  printf("Welcome to the Dungeon Crawler Adventure Game!\n");
  printf("Please enter your name: ");
  scanf("%s", playerName);
  
  printf("\nWelcome %s! You are about to embark on a journey filled with danger, mystery, and treasure!\n\n", playerName);
  printf("You find yourself at the entrance of a dark and ominous dungeon. You can hear strange noises coming from within. What do you want to do?\n");
  printf("1. Enter the dungeon\n");
  printf("2. Run away\n");
  printf("\nEnter your choice (1 or 2): ");
  scanf("%d", &questChoice);
  
  switch (questChoice) {
    case 1:
      printf("\nYou enter the dungeon. It's dark and dusty, but you can make out a path ahead of you.\n");
      printf("As you walk down the path, you encounter a pack of goblins!\n");
      printf("What do you do?\n");
      printf("1. Fight\n");
      printf("2. Flee\n");
      printf("\nEnter your choice (1 or 2): ");
      scanf("%d", &questChoice);
      
      if (questChoice == 1) {
        printf("\nYou draw your sword and prepare to fight the goblins!\n");
        printf("After a fierce battle, you emerge victorious and find a bag of gold!\n");
        gold += 10;
        goblinsKilled += 3;
        printf("You now have %d gold and have killed %d goblins!\n", gold, goblinsKilled);
        printf("You continue down the path and encounter a bridge. At the other side of the bridge is a troll!\n");
        printf("What do you do?\n");
        printf("1. Fight\n");
        printf("2. Flee\n");
        printf("\nEnter your choice (1 or 2): ");
        scanf("%d", &questChoice);
        
        if (questChoice == 1) {
          printf("\nYou draw your sword and prepare to fight the troll!\n");
          printf("After a long and grueling battle, you emerge victorious and find a chest filled with treasure!\n");
          gold += 50;
          trollsKilled += 1;
          printf("You now have %d gold and have killed %d goblins and %d trolls!\n", gold, goblinsKilled, trollsKilled);
          printf("Congratulations! You have completed the quest!\n");
        } else {
          printf("\nYou flee from the troll and exit the dungeon. Better luck next time!\n");
        }
        
      } else {
        printf("\nYou flee from the goblins and exit the dungeon. Better luck next time!\n");
      }
      
      break;
    case 2:
      printf("\nYou run away from the dungeon and decide to turn in for the day.\n");
      printf("Maybe you'll have better luck tomorrow!\n");
      break;
    default:
      printf("\nInvalid choice. Please choose 1 or 2.\n");
      break;
  }
  
  return 0;
}