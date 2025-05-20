//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char choice[20];
    char input[20];
    char *action;
    char *room;
    char *item;
    char *npc;
    int x = 0;

    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark, damp cave.\n");
    printf("There are three paths in front of you:\n");
    printf("1. To the left, where the ground is soft and squishy.\n");
    printf("2. To the right, where the ground is hard and rocky.\n");
    printf("3. Ahead, where the ground is slippery and steep.\n");
    printf("Which path do you take? ");
    gets(choice);
    if (choice[0] == '1') {
        printf("You take the left path.\n");
        printf("You step on something soft and squishy.\n");
        printf("Suddenly, you find yourself falling into a pit!\n");
        printf("You narrowly avoid hitting your head on a rock, but you still get a nasty bruise.\n");
        printf("You realize that the soft and squishy ground was actually a pile of squishy mushrooms!\n");
        printf("You climb out of the pit and continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    } else if (choice[0] == '2') {
        printf("You take the right path.\n");
        printf("You step on something hard and rocky.\n");
        printf("You slip on a rock and fall on your butt!\n");
        printf("You realize that the hard and rocky ground was actually a pile of slippery rocks!\n");
        printf("You get up and continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    } else if (choice[0] == '3') {
        printf("You take the ahead path.\n");
        printf("You step on something slippery and steep.\n");
        printf("You slip and fall down the steep slope!\n");
        printf("You land in a pile of smelly, slimy mud!\n");
        printf("You realize that the slippery and steep ground was actually a pile of slimy mud!\n");
        printf("You get up and continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    } else {
        printf("You stand there, confused and scared.\n");
        printf("You decide to take a step forward.\n");
        printf("Suddenly, you find yourself falling into a pit!\n");
        printf("You narrowly avoid hitting your head on a rock, but you still get a nasty bruise.\n");
        printf("You realize that the soft and squishy ground was actually a pile of squishy mushrooms!\n");
        printf("You climb out of the pit and continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    }

    printf("You continue on your adventure.\n");
    printf("You come across a giant dragon!\n");
    printf("The dragon roars and breathes fire at you!\n");
    printf("Do you fight or flee? ");
    gets(input);
    if (strcmp(input, "fight") == 0) {
        printf("You prepare to fight the dragon.\n");
        printf("The dragon charges at you!\n");
        printf("You swing your sword and hit the dragon!\n");
        printf("The dragon roars in pain and retreats.\n");
        printf("You have defeated the dragon!\n");
        printf("You continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    } else if (strcmp(input, "flee") == 0) {
        printf("You run away from the dragon!\n");
        printf("The dragon chases after you!\n");
        printf("You climb up a tree and hide in the branches.\n");
        printf("The dragon roars and breathes fire at the tree!\n");
        printf("You narrowly avoid getting burned and fall out of the tree.\n");
        printf("You realize that the dragon was actually a friendly dragon that was just playing with you!\n");
        printf("You apologize to the dragon and continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    } else {
        printf("You stand there, confused and scared.\n");
        printf("You decide to take a step forward.\n");
        printf("Suddenly, you find yourself falling into a pit!\n");
        printf("You narrowly avoid hitting your head on a rock, but you still get a nasty bruise.\n");
        printf("You realize that the soft and squishy ground was actually a pile of squishy mushrooms!\n");
        printf("You climb out of the pit and continue on your adventure.\n");
        printf("What do you do next? ");
        gets(input);
    }

    return 0;
}