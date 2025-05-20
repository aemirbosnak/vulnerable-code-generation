//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int health = 100; // Player health
int credits = 0; // Player credits
int weapon = 0; // Is player armed?

void intro() {
  printf("Welcome to the year 2050.\n");
  printf("You are a space traveler in search of a new home.\n");
  printf("Your journey has led you to the planet Zorgon.\n");
  printf("Upon arrival, you find that the planet's population is in danger.\n");
  printf("It's up to you to save them and find a new home for yourself.\n\n");
}

void command_list() {
  printf("Commands:\n");
  printf("  look - Look around your surroundings.\n");
  printf("  move - Move to a different location on the planet.\n");
  printf("  talk - Talk to a local inhabitant.\n");
  printf("  inspect - Inspect an object or a person.\n");
  printf("  buy - Buy weapons or equipment.\n");
  printf("  status - Check your current health, credits, and weapons.\n");
  printf("  help - Show this command list.\n");
  printf("  quit - Quit the game.\n");
}

void status() {
  printf("Current Health: %d\n", health);
  printf("Current Credits: %d\n", credits);
  if (weapon) {
    printf("Weapon: Laser Gun\n");
  } else {
    printf("Weapon: None\n");
  }
}

void look_around() {
  printf("You look around and see a desolate landscape.\n");
  printf("The sky is a dark red and the air is thick with smog.\n");
  printf("You notice a large, looming structure in the distance.\n");
  printf("It seems to be emitting a strange energy.\n\n");
}

void talk(char* person) {
  if (strcmp(person, "local inhabitant") == 0) {
    printf("You approach a local inhabitant and ask for information.\n");
    printf("They tell you that the energy emitting from the structure is from a powerful alien artifact.\n");
    printf("It's causing the planet's resources to deplete rapidly, and the inhabitants are in danger.\n");
    printf("They also mention that a group of rebels are planning to steal the artifact and use it for their own gain.\n");
    printf("They warn you to be careful and stay out of trouble.\n\n");
  } else {
    printf("You cannot talk to %s.\n\n", person);
  }
}

void inspect(char* object) {
  if (strcmp(object, "structure") == 0) {
    printf("You inspect the structure and notice that it's heavily guarded.\n");
    printf("There's no way you can get close to it without being detected.\n\n");
  } else if (strcmp(object, "local inhabitant") == 0) {
    printf("You inspect the local inhabitant and notice that they are visibly scared.\n");
    printf("The situation on the planet must be dire for them to be this way.\n\n");
  } else {
    printf("You cannot inspect %s.\n\n", object);
  }
}

void move(char* direction) {
  if (strcmp(direction, "north") == 0) {
    printf("You head north and come across a small shop.\n");
    printf("There's a weapons dealer inside.\n\n");
  } else if (strcmp(direction, "south") == 0) {
    printf("You head south and find yourself in a dark alleyway.\n");
    printf("You hear footsteps behind you.\n");
    printf("You quickly turn around and come face to face with a rebel.\n");
    printf("They demand that you hand over your credits.\n");
    if (weapon) {
      printf("You pull out your laser gun and aim at the rebel.\n");
      printf("They quickly run away in fear.\n");
    } else {
      printf("You do not have a weapon to defend yourself.\n");
      printf("The rebel takes your credits and runs away.\n");
      credits -= 50;
      health -= 10;
    }
  } else {
    printf("You cannot move in that direction.\n\n");
  }
}

void buy(char* item) {
  if (strcmp(item, "laser gun") == 0) {
    if (credits >= 100) {
      printf("You purchase a laser gun.\n");
      weapon = 1;
      credits -= 100;
    } else {
      printf("You do not have enough credits to buy a laser gun.\n");
    }
  } else {
    printf("You cannot buy %s.\n", item);
  }
}

int main() {
  char command[100];
  char argument[100];
  intro();
  command_list();
  while (1) {
    printf("> ");
    scanf("%s", command);
    if (strcmp(command, "quit") == 0) {
      printf("Goodbye!\n");
      break;
    } else if (strcmp(command, "help") == 0) {
      command_list();
    } else if (strcmp(command, "status") == 0) {
      status();
    } else if (strcmp(command, "look") == 0) {
      look_around();
    } else if (strcmp(command, "talk") == 0) {
      scanf("%s", argument);
      talk(argument);
    } else if (strcmp(command, "inspect") == 0) {
      scanf("%s", argument);
      inspect(argument);
    } else if (strcmp(command, "move") == 0) {
      scanf("%s", argument);
      move(argument);
    } else if (strcmp(command, "buy") == 0) {
      scanf("%s", argument);
      buy(argument);
    } else {
      printf("Invalid command. Type 'help' for a list of available commands.\n\n");
    }
  }
  return 0;
}