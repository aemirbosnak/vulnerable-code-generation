//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int choice = 0;
  printf("Welcome to the Text Adventure Game!\n");
  printf("You've woken up in a mysterious dungeon with no memory of how you got here.\n");
  printf("You see two doors in front of you. Will you choose door 1 or door 2?\n");
  scanf("%d", &choice);
  
  if (choice == 1) {
    printf("You open the door and find yourself in a room with a treasure chest.\n");
    printf("You carefully approach the chest and open it, revealing a pile of gold coins.\n");
    printf("As you reach for the coins, you hear a loud noise behind you. You turn around to see a dragon staring at you.\n");
    printf("You have two choices: fight the dragon or try to run away. What will you do?\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
      printf("You prepare to fight the dragon and pull out your sword. The dragon breathes fire at you, but you manage to dodge it.\n");
      printf("You swing your sword at the dragon and manage to catch it on its shoulder. The dragon roars in pain.\n");
      int chance = rand() % 2;
      if (chance == 0) {
        printf("You take advantage of the dragon's moment of weakness and land the finishing blow. Congratulations, you have defeated the dragon!\n");
      } else {
        printf("The dragon manages to push you away and breathe fire at you. You're no match for its power. Game over.\n");
      }
    } else {
      printf("You turn around and try to run away, but the dragon is too fast for you. It catches up to you and breathes fire at you. Game over.\n");
    }
    
  } else {
    printf("You open the door and find yourself in a dark hallway. You can barely see anything in front of you.\n");
    printf("As you start walking down the hallway, you hear footsteps approaching. What will you do?\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
      printf("You hide behind a nearby rock and wait for the footsteps to pass. After a few seconds, you realize it was just a rat.\n");
      printf("You continue down the hallway and eventually find a staircase leading up. Will you go up the stairs or continue down the hallway?\n");
      scanf("%d", &choice);
      if (choice == 1) {
        printf("You climb up the stairs and find yourself in a room with a map of the dungeon. It looks like the exit is just a few rooms away.\n");
        printf("You follow the map and eventually make your way out of the dungeon. Congratulations, you have escaped!\n");
      } else {
        printf("You continue down the hallway and eventually come face-to-face with a group of goblins. They attack you and you don't stand a chance. Game over.\n");
      }
    } else {
      printf("You continue down the hallway and come face-to-face with a group of goblins. They attack you and you don't stand a chance. Game over.\n");
    }
  }
  
  return 0;
}