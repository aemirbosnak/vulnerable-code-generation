//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print the welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of a creaky old house.\n");
    printf("It looks like it's been abandoned for years.\n");
    printf("You're not sure why you're here, but you can feel a chill in the air.\n");
    printf("Do you dare to enter? (y/n)\n");

    // Get the user's input
    char input;
    scanf("%c", &input);

    if (input == 'y') {
        // The user wants to enter the house
        printf("You take a deep breath and push open the door.\n");

        // Generate a random number to determine what happens next
        int random = rand() % 3;

        switch (random) {
            case 0:
                // The user finds a dark hallway
                printf("You step into a dark hallway and your eyes slowly adjust to the dim light.\n");
                printf("As you take a step forward, you hear a strange noise coming from behind you.\n");
                printf("Do you turn around to investigate? (y/n)\n");

                // Get the user's input
                scanf(" %c", &input);

                if (input == 'y') {
                    // The user turns around and sees a ghost
                    printf("You turn around and see a ghostly figure hovering behind you.\n");
                    printf("You scream and run out of the house as fast as you can.\n");
                } else {
                    // The user decides to keep moving forward and encounters a locked door
                    printf("You decide to keep moving forward and come to a locked door.\n");
                    printf("You try the handle, but it won't budge.\n");
                    printf("Suddenly, you hear footsteps coming from behind you.\n");
                    printf("Do you hide or face your fear? (h/f)\n");

                    // Get the user's input
                    scanf(" %c", &input);

                    if (input == 'h') {
                        // The user hides and the footsteps pass
                        printf("You quickly duck behind a nearby piece of furniture as the footsteps get closer.\n");
                        printf("You hold your breath and wait as they pass by.\n");
                        printf("Once you're sure it's safe, you continue to explore the house.\n");
                    } else {
                        // The user faces their fear and encounters a poltergeist
                        printf("You decide to face your fear and turn to face the footsteps.\n");
                        printf("As you do, a bookcase suddenly flies off the wall and narrowly misses you.\n");
                        printf("You realize that the house is haunted by a poltergeist and run out of the house as fast as you can.\n");
                    }
                }
                break;

            case 1:
                // The user finds a room with a ouija board
                printf("You step into a room and see a ouija board sitting on a table.\n");
                printf("The board seems to be calling to you, inviting you to use it.\n");
                printf("Do you use the ouija board? (y/n)\n");

                // Get the user's input
                scanf(" %c", &input);

                if (input == 'y') {
                    // The user uses the ouija board and summons a demon
                    printf("You place your hands on the ouija board and close your eyes.\n");
                    printf("As you ask a question, the board begins to move on its own.\n");
                    printf("Suddenly, the room grows cold and you feel a presence in the room with you.\n");
                    printf("You open your eyes and see a demon standing in front of you.\n");
                    printf("You scream and run out of the house as fast as you can.\n");
                } else {
                    // The user decides not to use the ouija board and encounters a trapped spirit
                    printf("You decide not to use the ouija board and continue to explore the house.\n");
                    printf("As you walk down the hallway, you hear a faint whisper.\n");
                    printf("You follow the sound and find a trapped spirit.\n");
                    printf("The spirit thanks you for freeing it and disappears.\n");
                }
                break;

            case 2:
                // The user finds a room with a creepy doll
                printf("You step into a room and see a creepy doll sitting on a chair.\n");
                printf("The doll seems to be staring directly at you, its eyes following your every move.\n");
                printf("Do you approach the doll? (y/n)\n");

                // Get the user's input
                scanf(" %c", &input);

                if (input == 'y') {
                    // The user approaches the doll and it comes to life
                    printf("You cautiously approach the doll and reach out to touch it.\n");
                    printf("As your fingers make contact with the doll, it comes to life.\n");
                    printf("The doll cackles and begins to chase you around the room.\n");
                    printf("You manage to escape and run out of the house as fast as you can.\n");
                } else {
                    // The user decides not to approach the doll and finds a secret passage
                    printf("You decide not to approach the doll and continue to explore the room.\n");
                    printf("As you move a piece of furniture, you discover a hidden door.\n");
                    printf("You open the door and find a secret passage.\n");
                    printf("You follow the passage to the end and find a treasure chest.\n");
                    printf("You open the chest and find a key.\n");
                    printf("You leave the house with the key and wonder what it might unlock.\n");
                }
                break;
        }
    } else {
        // The user doesn't want to enter the house
        printf("You decide not to enter the house and leave, wondering what might have been inside.\n");
    }

    return 0;
}