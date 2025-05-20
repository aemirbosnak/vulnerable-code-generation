//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>

int main() {
  // Greeting 
  printf("Welcome to the Text-Based Adventure Game!\n");
  printf("Are you ready to start your adventure?\n");

  // Player name input
  char name[20];
  printf("What's your name, adventurer?\n");
  scanf("%s", name);
  printf("Nice to meet you, %s! Let's begin the adventure.\n", name);

  // Game Introduction
  printf("You find yourself standing in a dark and creepy forest.\n");
  printf("As you look around, you see two paths to choose from.\n");
  printf("One path leads to a castle and the other leads to an old ruin.\n");
  printf("Which path do you choose? ('1' for castle, '2' for ruin)\n");

  // User input of castle or ruin
  int choice;
  scanf("%d", &choice);

  if(choice == 1) {
    // path to the castle
    printf("You choose the path to the castle.\n");
    printf("As you approach the castle, you see a drawbridge leading inside.\n");
    printf("But guarded by a fierce dragon!\n");
    printf("What do you do?\n");
    printf("1. Fight the dragon\n");
    printf("2. Sneak past the dragon\n");
    printf("3. Try to befriend the dragon\n");

    // User input of fighting, sneaking or befriending dragon
    scanf("%d", &choice);

    if(choice == 1) {
      // fight the dragon
      printf("You are brave, %s! You engage the dragon in battle.\n", name);
      printf("The fight is intense, but you finally slay the mighty dragon!\n");
      printf("As you enter the castle, you find the treasure and become the richest adventurer in the land. Congratulations on your victory!\n");
    } else if(choice == 2) {
      // sneak past the dragon
      printf("You try to sneak past the dragon, but its sharp senses detect you.\n");
      printf("The dragon is angry and chases you down.\n");
      printf("You try to run away, but the dragon catches up to you and eats you! Game over.\n");
    } else {
      // befriend the dragon
      printf("You try to befriend the dragon by offering it some gold coins.\n");
      printf("The dragon seems to like you and allows you to pass.\n");
      printf("As you enter the castle, you find the treasure and become the richest adventurer in the land. Congratulations on your victory!\n");
    }
  } else {
    // path to the ruin
    printf("You choose the path to the old ruin.\n");
    printf("As you explore the ruin, you notice a trap door in the floor.\n");
    printf("Do you investigate the trap door? ('1' for yes, '2' for no)\n");

    // User input of investigating trap door or not
    scanf("%d", &choice);

    if(choice == 1) {
      // investigate the trap door
      printf("You open the trap door and descend into a dark dungeon.\n");
      printf("As you explore the dungeon, you encounter a giant spider!\n");
      printf("What do you do?\n");
      printf("1. Fight the spider\n");
      printf("2. Use magic to defeat the spider\n");
      printf("3. Run away\n");

      // User input of fighting, using magic or running away from spider
      scanf("%d", &choice);

      if(choice == 1) {
        // fight the spider
        printf("You engage the giant spider in battle.\n");
        printf("The spider is strong, but you finally manage to defeat it!\n");
        printf("As you search the dungeon, you find a magical gem that grants you the power of fire. Congratulations on your victory!\n");
      } else if(choice == 2) {
        // use magic to defeat the spider
        printf("You use your new found magic power to defeat the giant spider.\n");
        printf("As you search the dungeon, you find a magical gem that grants you the power of fire. Congratulations on your victory!\n");
      } else {
        // run away
        printf("You try to run away, but the giant spider catches up to you.\n");
        printf("You engage in a fight, but the spider is too strong and kills you. Game over.\n");
      }
    } else {
      // do not investigate the trap door
      printf("You decide not to investigate the trap door and continue exploring the ruins.\n");
      printf("As you walk around, you suddenly fall into a pit trap!\n");
      printf("You are trapped and eventually die of starvation. Game over.\n");
    }
  }

  printf("Thank you for playing the Text-Based Adventure Game, %s!\n", name);

  return 0;
}