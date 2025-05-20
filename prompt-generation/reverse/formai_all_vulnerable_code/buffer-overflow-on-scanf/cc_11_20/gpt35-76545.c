//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("---------------------------\n");
    printf("| Welcome to Haunted House |\n");
    printf("---------------------------\n\n");

    // Initialize random seed
    srand(time(NULL));

    // Initialize variables
    int room = 1;
    int has_key = 0;
    int ghost_appeared = 0;
    int is_alive = 1;

    // Game loop
    while(is_alive) {
        printf("You are in room %d", room);

        // Random chance of encountering a ghost
        if(rand() % 3 == 0 && !ghost_appeared) {
            printf("\n\nA ghost has appeared and killed you. Game over.\n");
            is_alive = 0;
            break;
        }

        // Prompt user for action
        printf("\nWhat would you like to do?\n1) Go to next room\n2) Search the room\n");
        if(has_key) {
            printf("3) Unlock the door\n");
        }

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                room++;
                break;
            case 2:
                if(room == 2 && !has_key) {
                    printf("Congratulations! You found the key!\n");
                    has_key = 1;
                } else if(room == 3) {
                    printf("You found a mysterious potion. Drink it?\n1) Yes\n2) No\n");
                    int drink_choice;
                    scanf("%d", &drink_choice);
                    if(drink_choice == 1) {
                        printf("You feel a strange sensation and suddenly vanish into thin air. Game over.\n");
                        is_alive = 0;
                        break;
                    }
                } else {
                    printf("You find nothing of interest.\n");
                }
                break;
            case 3:
                if(has_key && room == 4) {
                    printf("Congratulations! You have escaped the haunted house and won the game!\n");
                    is_alive = 0;
                    break;
                } else if(has_key) {
                    printf("There is no locked door in this room.\n");
                } else {
                    printf("You do not have the key.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}