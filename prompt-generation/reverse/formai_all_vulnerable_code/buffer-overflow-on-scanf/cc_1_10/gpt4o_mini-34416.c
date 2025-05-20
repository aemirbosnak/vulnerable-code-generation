//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void introduction() {
    printf("Welcome to the Haunted House Adventure!\n");
    printf("You will explore a spooky house, make choices, and face mysterious events.\n");
    printf("Can you make it out alive? Let's find out!\n\n");
}

void exploreRoom(int room) {
    switch (room) {
        case 1:
            printf("You enter the living room. It's dark and eerie.\n");
            printf("In the corner, you see a flickering candle.\n");
            printf("Do you want to (1) take the candle or (2) leave the room? ");
            break;
        case 2:
            printf("You enter the kitchen. The fridge is slightly ajar.\n");
            printf("You hear a strange noise coming from inside.\n");
            printf("Do you want to (1) investigate the fridge or (2) leave the room? ");
            break;
        case 3:
            printf("You enter the attic. It's filled with cobwebs and old furniture.\n");
            printf("You see a strange glowing box.\n");
            printf("Do you want to (1) open the box or (2) leave the room? ");
            break;
        case 4:
            printf("You enter the basement. It's cold and damp.\n");
            printf("You spot an old journal on the floor.\n");
            printf("Do you want to (1) read the journal or (2) leave the room? ");
            break;
        default:
            printf("You stumble around in the dark...\n");
            break;
    }
}

void gameOver() {
    printf("What a shame! You've met an untimely end in the haunted house...\n");
    printf("THE END\n");
}

void victory() {
    printf("Congratulations! You've found the secret passage and escaped the haunted house!\n");
    printf("You live to tell the tale...\nTHE END\n");
}

int main() {
    srand(time(NULL));
    int choice, room, outcome;

    introduction();

    room = 1; // Start in the living room

    while (1) {
        exploreRoom(room);
        scanf("%d", &choice);

        // Determine outcome based on the room and choice
        switch (room) {
            case 1:
                if (choice == 1) {
                    printf("You take the candle, and it lights up the room.\n");
                    room = 2; // Go to the kitchen
                } else {
                    printf("You leave the room, feeling uneasy...\n");
                    room = 3; // Go to the attic
                }
                break;
            case 2:
                if (choice == 1) {
                    printf("You open the fridge and a ghost jumps out!\n");
                    gameOver();
                    return 0; // End the game
                } else {
                    printf("You leave the kitchen.\n");
                    room = 4; // Go to the basement
                }
                break;
            case 3:
                if (choice == 1) {
                    printf("You open the box and a monster appears!\n");
                    gameOver();
                    return 0; // End the game
                } else {
                    printf("You quickly leave the attic.<br>\n");
                    room = 4; // Go to the basement
                }
                break;
            case 4:
                if (choice == 1) {
                    printf("The journal is filled with dark secrets about the house.\n");
                    outcome = rand() % 2; // Random outcome
                    if (outcome == 0) {
                        printf("You awaken the spirits trapped in the house!\n");
                        gameOver();
                        return 0; // End the game
                    } else {
                        victory();
                        return 0; // End the game
                    }
                } else {
                    printf("You leave the basement, trying to contain your fear.\n");
                    room = 1; // Back to living room
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}