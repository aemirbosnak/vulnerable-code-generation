//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int choice, riddle_choice;
    char answer[20];
    srand(time(NULL));
    printf("\nWelcome to the Brave Adventure Game!\n");
    printf("You find yourself standing in front of a dark and mysterious castle.\n");
    printf("What would you like to do?\n");
    printf("Enter 1 to enter the castle, or enter 2 to leave: ");
    scanf("%d", &choice);
    if(choice == 2) {
        printf("You turn and leave, never looking back.\n");
        return 0;
    }
    printf("You cautiously approach the castle, and as you enter the doorway, a loud creak echoes throughout the halls.\n");
    printf("You hear a voice coming from a nearby room. It says, \"If you want to proceed, you must answer my riddle.\"\n");
    riddle_choice = rand() % 3 + 1;
    if(riddle_choice == 1) {
        printf("Riddle me this: What has a heart that doesn't beat?\n");
        scanf("%s", answer);
        if(strcmp(answer, "artichoke") == 0) {
            printf("You have answered correctly! You may proceed.\n");
        }
        else {
            printf("Wrong answer! You are trapped in the castle forever.\n");
            return 0;
        }
    }
    else if(riddle_choice == 2) {
        printf("Riddle me this: What has a face but cannot smile, and cries but never a tear?\n");
        scanf("%s", answer);
        if(strcmp(answer, "moon") == 0) {
            printf("You have answered correctly! You may proceed.\n");
        }
        else {
            printf("Wrong answer! You are trapped in the castle forever.\n");
            return 0;
        }
    }
    else {
        printf("Riddle me this: The more you take, the more you leave behind. What am I?\n");
        scanf("%s", answer);
        if(strcmp(answer, "footsteps") == 0) {
            printf("You have answered correctly! You may proceed.\n");
        }
        else {
            printf("Wrong answer! You are trapped in the castle forever.\n");
            return 0;
        }
    }
    printf("You continue on through the castle, and encounter a fierce dragon blocking your path.\n");
    printf("Quickly, you must choose what to do! Enter 1 to fight, enter 2 to use your charm: ");
    scanf("%d", &choice);
    if(choice == 2) {
        printf("You use your charm to convince the dragon to let you pass. It works!\n");
    }
    else {
        printf("You bravely fight the dragon, sword in hand. After a fierce battle, you emerge victorious!\n");
    }
    printf("As you continue deeper into the castle, you begin to hear whispers. You cautiously move forward, and realize that they are coming from a coven of witches.\n");
    printf("The witches are holding something they stole from the village nearby. You must choose what to do. Enter 1 to negotiate, enter 2 to fight: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("You negotiate with the witches, promising them something in return for the item they've stolen. They agree, and you take the item back with you.\n");
    }
    else {
        printf("You bravely fight the witches, spells flying everywhere. Finally, you emerge victorious, and take back the item they've stolen.\n");
    }
    printf("You are nearing the end of the castle, and you come face to face with a terrifying monster.\n");
    printf("You must answer one final riddle before you can defeat it. Riddle me this: What has a tongue but cannot speak, and a soul but cannot die?: ");
    scanf("%s", answer);
    if(strcmp(answer, "shoe") == 0) {
        printf("You have answered correctly! You are able to defeat the monster and leave the castle, your bravery shining like a beacon.\n");
    }
    else {
        printf("Wrong answer! The monster defeats you and you are trapped in the castle forever.\n");
        return 0;
    }
    return 0;
}