//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if user input matches with valid inputs
bool is_valid_input(char* input, char** valid_inputs, int num_inputs) {    
    for(int i=0; i<num_inputs; i++) {
        if(strcmp(input, valid_inputs[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char* name = (char*)malloc(sizeof(char) * 50);
    char** valid_inputs = (char**)malloc(sizeof(char*) * 3);
    for(int i=0; i<3; i++) {
        valid_inputs[i] = (char*)malloc(sizeof(char) * 10);
    }

    strcpy(valid_inputs[0], "yes");
    strcpy(valid_inputs[1], "no");
    strcpy(valid_inputs[2], "exit");

    printf("Welcome to Interoperable Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("\nHi %s, are you ready to play the game? (yes/no)\n", name);
    char* input = (char*)malloc(sizeof(char) * 10);
    scanf("%s", input);

    // If user inputs something else than "yes" or "no", ask again until valid input is given.
    while(!is_valid_input(input, valid_inputs, 2)) {
        printf("Sorry, invalid input. Please enter \"yes\" or \"no\"\n");
        scanf("%s", input);
    }

    // If user chooses to exit game
    if(strcmp(input, valid_inputs[2]) == 0) {
        printf("\nOkay %s, see you later!\n", name);
        exit(0); // Exit program
    }

    printf("\nGreat! Let's start the game!\n\n");

    printf("You are standing in front of a door. What would you like to do?\n");
    printf("1. Open the door\n");
    printf("2. Knock on the door\n");
    printf("3. Ignore the door and walk away\n");
    scanf("%s", input);

    while(!is_valid_input(input, valid_inputs, 3)) { // Validate user input
        printf("Sorry, invalid input. Please enter a number between 1-3.\n");
        scanf("%s", input);
    }

    // Scenario A: User opens the door
    if(strcmp(input, "1") == 0) {
        printf("\nYou open the door and walk in. You see a big room with a chest in the middle.\n");
        printf("What would you like to do?\n");
        printf("1. Approach the chest and open it.\n");
        printf("2. Look around the room before approaching the chest.\n");
        printf("3. Leave the room.\n");
        scanf("%s", input);

        while(!is_valid_input(input, valid_inputs, 3)) { // Validate user input
            printf("Sorry, invalid input. Please enter a number between 1-3.\n");
            scanf("%s", input);
        }

        // Sub-scenario 1: User opens the chest
        if(strcmp(input, "1") == 0) {
            printf("You open the chest and find a magical sword. Congratulations %s, you won the game!\n", name);
        }

        // Sub-scenario 2: User looks around the room
        else if(strcmp(input, "2") == 0) {
            printf("You look around the room and find a trapdoor hidden behind a bookcase.\n");
            printf("What would you like to do?\n");
            printf("1. Open the trapdoor.\n");
            printf("2. Leave the room.\n");
            scanf("%s", input);

            while(!is_valid_input(input, valid_inputs, 2)) { // Validate user input
                printf("Sorry, invalid input. Please enter a number between 1-2.\n");
                scanf("%s", input);
            }

            // Sub-sub-scenario 1: User opens the trapdoor
            if(strcmp(input, "1") == 0) {
                printf("You open the trapdoor and find a treasure chest inside. Congratulations %s, you won the game!\n", name);
            }

            // Sub-sub-scenario 2: User leaves the room
            else if(strcmp(input, "2") == 0) {
                printf("You leave the room and the game ends. Goodbye %s!\n", name);
            }
        }

        // Sub-scenario 3: User leaves the room
        else if(strcmp(input, "3") == 0) {
            printf("You leave the room and the game ends. Goodbye %s!\n", name);
        }
    }

    // Scenario B: User knocks on the door
    else if(strcmp(input, "2") == 0) {
        printf("\nYou knock on the door but nobody answers. What would you like to do now?\n");
        printf("1. Open the door.\n");
        printf("2. Knock again.\n");
        printf("3. Leave.\n");
        scanf("%s", input);

        while(!is_valid_input(input, valid_inputs, 3)) { // Validate user input
            printf("Sorry, invalid input. Please enter a number between 1-3.\n");
            scanf("%s", input);
        }

        // Sub-scenario 1: User opens the door
        if(strcmp(input, "1") == 0) {
            printf("You open the door and walk in. You see a room with three doors.\n");
            printf("What would you like to do?\n");
            printf("1. Open the left door.\n");
            printf("2. Open the middle door.\n");
            printf("3. Open the right door.\n");
            scanf("%s", input);

            while(!is_valid_input(input, valid_inputs, 3)) { // Validate user input
                printf("Sorry, invalid input. Please enter a number between 1-3.\n");
                scanf("%s", input);
            }

            // Sub-sub-scenario 1: User opens the left door
            if(strcmp(input, "1") == 0) {
                printf("You open the left door and find a dragon guarding a treasure. You get burned and lose the game. Better luck next time %s!\n", name);
            }

            // Sub-sub-scenario 2: User opens the middle door
            else if(strcmp(input, "2") == 0) {
                printf("You open the middle door and find a room with a chest in the middle. Congratulations %s, you won the game!\n", name);
            }

            // Sub-sub-scenario 3: User opens the right door
            else if(strcmp(input, "3") == 0) {
                printf("You open the right door and find a room with a bunch of skeletons. You get scared and leave the room. You lose the game. Better luck next time %s!\n", name);
            }
        }

        // Sub-scenario 2: User knocks again
        else if(strcmp(input, "2") == 0) {
            printf("You knock again but nobody answers. You decide to leave and the game ends. Goodbye %s!\n", name);
        }

        // Sub-scenario 3: User leaves
        else if(strcmp(input, "3") == 0) {
            printf("You leave and the game ends. Goodbye %s!\n", name);
        }
    }

    // Scenario C: User ignores the door
    else if(strcmp(input, "3") == 0) {
        printf("\nYou ignore the door and start walking away. Suddenly, you hear a loud noise behind you. What would you like to do?\n");
        printf("1. Turn around and run back towards the door.\n"); 
        printf("2. Continue walking away.\n");
        scanf("%s", input);

        while(!is_valid_input(input, valid_inputs, 2)) { // Validate user input
            printf("Sorry, invalid input. Please enter a number between 1-2.\n");
            scanf("%s", input);
        }

        // Sub-scenario 1: User turns around and runs back
        if(strcmp(input, "1") == 0) {
            printf("You turn around and run back towards the door but it's too late. A monster jumps out of the bushes and kills you. You lose the game. Better luck next time %s!\n", name);
        }

        // Sub-scenario 2: User continues walking away
        else if(strcmp(input, "2") == 0) {
            printf("You continue walking away and the game ends. Goodbye %s!\n", name);
        }
    }
    return 0;
}