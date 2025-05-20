//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare and initialize variables
    int player_health = 100;
    int player_gold = 0;
    int player_strength = 10;

    // Define the rooms and their descriptions
    char* room1 = "You find yourself in a dark and musty cave. The only light comes from the torch on the wall. A large boulder blocks the entrance.";
    char* room2 = "You enter a dimly lit room with a wooden door in the middle. There are several traps on the ground.";
    char* room3 = "You find yourself in a large, open chamber with a stone statue in the center. The statue has a sword stuck in its side.";
    char* room4 = "You enter a room filled with treasure chests. You can see gold coins, jewels, and a magical amulet.";

    // Prompt the player to choose a room
    printf("Which room would you like to explore?\n");
    printf("1. Dark and musty cave\n");
    printf("2. Dimly lit room with wooden door\n");
    printf("3. Large open chamber with stone statue\n");
    printf("4. Room filled with treasure chests\n");
    int choice;
    scanf("%d", &choice);

    // Choose a random room for the player to explore
    if (choice == 1) {
        printf("%s\n", room1);
    } else if (choice == 2) {
        printf("%s\n", room2);
    } else if (choice == 3) {
        printf("%s\n", room3);
    } else if (choice == 4) {
        printf("%s\n", room4);
    } else {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    // Check for player interaction
    printf("What do you do?\n");
    char action[100];
    scanf("%s", action);

    if (strcmp(action, "explore") == 0) {
        printf("You explore the room and find a hidden passage.\n");
        printf("You enter the passage and find yourself in a room filled with traps.\n");
        printf("You must choose wisely to avoid them and make it to the end.\n");
    } else if (strcmp(action, "fight") == 0) {
        printf("You challenge the statue to a fight.\n");
        printf("The statue comes alive and attacks you.\n");
        printf("You have %d hit points left.\n", player_health);
    } else if (strcmp(action, "open") == 0) {
        printf("You try to open the treasure chests.\n");
        printf("Unfortunately, they are locked.\n");
    } else {
        printf("Invalid action. Please try again.\n");
    }

    printf("What do you do next?\n");
    scanf("%s", action);

    if (strcmp(action, "explore") == 0) {
        printf("You explore the room and find a hidden passage.\n");
        printf("You enter the passage and find yourself in a room filled with traps.\n");
        printf("You must choose wisely to avoid them and make it to the end.\n");
    } else if (strcmp(action, "fight") == 0) {
        printf("You challenge the statue to a fight.\n");
        printf("The statue comes alive and attacks you.\n");
        printf("You have %d hit points left.\n", player_health);
    } else if (strcmp(action, "open") == 0) {
        printf("You try to open the treasure chests.\n");
        printf("Unfortunately, they are locked.\n");
    } else {
        printf("Invalid action. Please try again.\n");
    }

    printf("What do you do next?\n");
    scanf("%s", action);

    // End game loop
    return 0;
}