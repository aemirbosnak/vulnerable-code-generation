//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  printf("Welcome to the Land of Adventure! What is your name?\n");
  char name[20];
  scanf("%s", name);
  
  printf("\n\nHello %s! You find yourself on a dusty road, with no idea how you got here. Ahead lies a town, and behind you is a dense forest. Where would you like to go? (town/forest)\n", name);
  
  char choice[10];
  scanf("%s", choice);
  
  if (strcmp(choice, "town") == 0) {
    printf("\n\nYou enter the town, and immediately notice the hustle and bustle of the people. You ask around, and eventually make your way to the inn. The innkeeper looks at you quizzically. 'You look like you've seen a ghost', he says. 'I have no memory of how I got here', you reply. 'Well, there's a cursed castle not far from here. Maybe that has something to do with it'.\n");
    
    printf("\n\nDo you want to visit the castle? (yes/no)\n");
    char castleChoice[10];
    scanf("%s", castleChoice);
    
    if (strcmp(castleChoice, "yes") == 0) {
      int chance = rand() % 2;
      if (chance == 0) {
        printf("\n\nYou make your way to the castle, and as soon as you set foot inside, you feel an overwhelming sense of dread. You decide to turn back, and as soon as you leave the castle, you are hit with a bolt of lightning. You take 10 damage, and are sent flying back to the entrance of the castle.\n");
      }
      else {
        printf("\n\nYou make your way to the castle, and as soon as you set foot inside, you feel an overwhelming sense of power. You make your way through the castle, fighting off monsters and traps. Finally, you reach the throne room, where the ghost of the previous king awaits you. He tells you that he needs your help to be put to rest. Will you help him? (yes/no)\n");
        char ghostChoice[10];
        scanf("%s", ghostChoice);
        if (strcmp(ghostChoice, "yes") == 0) {
          printf("\n\nYou help the ghost of the previous king, and he rewards you with a powerful magic sword. You leave the castle feeling accomplished and stronger than ever before.\n");
        }
        else {
          printf("\n\nYou refuse to help the ghost of the previous king, and he curses you with bad luck for the rest of your life. You leave the castle feeling defeated and weak.\n");
        }
      }
    }
    else {
      printf("\n\nYou decide not to visit the castle, and instead spend the night in the inn. You wake up feeling refreshed, and continue your journey. Good luck, adventurer!\n");
    }
  }
  else {
    printf("\n\nYou decide to venture into the forest, hoping to find a way out. As you walk, you hear a rustling in the bushes. Do you investigate? (yes/no)\n");
    char forestChoice[10];
    scanf("%s", forestChoice);
    
    if (strcmp(forestChoice, "yes") == 0) {
      int chance = rand() % 2;
      if (chance == 0) {
        printf("\n\nYou investigate the bushes, and are immediately ambushed by a group of bandits. You fight bravely, but there are too many of them. You take 20 damage, and are left unconscious on the forest floor.\n");
      }
      else {
        printf("\n\nYou investigate the bushes, and find a valuable treasure! You take it with you on your journey, feeling lucky and accomplished.\n");
      }
    }
    else {
      printf("\n\nYou decide not to investigate the bushes, and continue your journey through the forest. You eventually come across a river, and choose to follow it. Good luck, adventurer!\n");
    }
  }
  
  return 0;
}