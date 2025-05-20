//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to clear the screen
void clear() {
    system("cls");
}

// Function to wait for a given amount of time
void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

// Function to simulate a random chance event
bool chance(double probability) {
    double random_number = (double)rand() / RAND_MAX;
    return probability >= random_number;
}

// Function to print a message with a delay effect
void print_with_delay(char* message, int delay) {
    for (int i = 0; message[i] != '\0'; i++) {
        printf("%c", message[i]);
        fflush(stdout);
        wait(delay);
    }
}

int main() {
    srand(time(NULL));  // seed the random number generator with the current time
    
    // Introduction
    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("You are stranded in a creepy old mansion.\n");
    printf("Your goal is to find a way out alive.\n\n");

    // Game loop
    bool has_key = false;
    bool has_flashlight = false;
    bool is_alive = true;

    while (is_alive) {
        clear();
        printf("You are in a dark room.\n");
        printf("You can see a door on the other side of the room.\n\n");

        // Actions
        printf("What do you want to do?\n");
        printf("1. Look around the room.\n");
        printf("2. Try the door.\n");
        printf("3. Quit the game.\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                clear();
                printf("You look around the room and find:\n");
                if (!has_key && chance(0.5)) {
                    printf("- A rusty key.\n");
                    has_key = true;
                }
                if (!has_flashlight && chance(0.3)) {
                    printf("- A flashlight with low batteries.\n");
                    has_flashlight = true;
                }
                if (!has_key && !has_flashlight) {
                    printf("- Nothing useful.\n");
                }
                printf("\nPress any key to continue...");
                fflush(stdin);
                getchar();
                break;
            }
            case 2: {
                clear();
                if (has_key) {
                    printf("You use the key to open the door.\n");
                    printf("You escape from the haunted house and win the game!\n");
                    is_alive = false;
                } else if (has_flashlight) {
                    printf("You use the flashlight to navigate through the dark room.\n");
                    printf("However, you stumble upon a trap and die.\n");
                    is_alive = false;
                } else {
                    printf("You try to open the door but it's locked.\n");
                    printf("You hear a creepy noise and feel something touching you.\n");
                    printf("You die a horrible death.\n");
                    is_alive = false;
                }
                printf("\nPress any key to exit the game...");
                fflush(stdin);
                getchar();
                break;
            }
            case 3: {
                is_alive = false;
                break;
            }
            default: {
                printf("Invalid choice.\n");
                printf("Press any key to try again...");
                fflush(stdin);
                getchar();
                break;
            }
        }
    }

    printf("\nThanks for playing!\n");
    return 0;
}