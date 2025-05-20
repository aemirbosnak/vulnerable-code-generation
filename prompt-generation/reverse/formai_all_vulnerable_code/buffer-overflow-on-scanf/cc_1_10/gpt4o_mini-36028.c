//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_OPTIONS 3
#define MAX_SCENES 5

void display_welcome() {
    printf("****************************************\n");
    printf(" WELCOME TO THE SHERLOCK HOLMES ADVENTURE!\n");
    printf("****************************************\n\n");
}

void display_scene(int scene) {
    switch (scene) {
        case 1:
            printf("You are in Baker Street, Sherlock's residence.\n");
            printf("You find a mysterious letter on the table.\n");
            printf("What would you like to do?\n");
            printf("1) Open the letter\n");
            printf("2) Leave the room\n");
            printf("3) Examine the room\n");
            break;
        case 2:
            printf("You've opened the letter. It reads: 'Meet me at the old church'.\n");
            printf("What would you like to do?\n");
            printf("1) Go to the church\n");
            printf("2) Investigate more in the room\n");
            printf("3) Call Dr. Watson\n");
            break;
        case 3:
            printf("You are now at the old church. It's dark and eerie.\n");
            printf("You hear a noise from behind the altar.\n");
            printf("What would you like to do?\n");
            printf("1) Investigate the noise\n");
            printf("2) Leave the church\n");
            printf("3) Light a candle\n");
            break;
        case 4:
            printf("You investigated the noise and found a hidden passage!\n");
            printf("What would you like to do?\n");
            printf("1) Enter the passage\n");
            printf("2) Go back to the main church\n");
            printf("3) Call for help\n");
            break;
        case 5:
            printf("Congratulations! You solved the mystery and saved the day!\n");
            printf("Do you want to play again? (yes/no)\n");
            break;
        default:
            printf("Invalid scene!\n");
            break;
    }
}

int get_choice() {
    int choice;
    printf("\nChoose an option (1-%d): ", MAX_OPTIONS);
    scanf("%d", &choice);
    return choice;
}

int main() {
    display_welcome();

    int current_scene = 1;
    char play_again[4];
    
    while (1) {
        display_scene(current_scene);

        if (current_scene == 5) {
            scanf("%s", play_again);
            if (strcasecmp(play_again, "yes") == 0) {
                current_scene = 1;
            } else {
                break;
            }
            continue;
        }

        int choice = get_choice();

        switch (current_scene) {
            case 1:
                if (choice == 1) {
                    current_scene = 2;  // Open the letter
                } else if (choice == 2) {
                    current_scene = 5;  // End game
                } else {
                    current_scene = 5;  // End game
                }
                break;
            case 2:
                if (choice == 1) {
                    current_scene = 3;  // Go to church
                } else if (choice == 2) {
                    current_scene = 1;  // Go back to the room
                } else {
                    current_scene = 5;  // End game
                }
                break;
            case 3:
                if (choice == 1) {
                    current_scene = 4;  // Investigate noise
                } else if (choice == 2) {
                    current_scene = 5;  // End game
                } else {
                    current_scene = 5;  // End game
                }
                break;
            case 4:
                if (choice == 1) {
                    current_scene = 5;  // You found the hidden passage!
                } else if (choice == 2) {
                    current_scene = 3;  // Go back to church
                } else {
                    current_scene = 5;  // End game
                }
                break;
            default:
                printf("An unexpected error occurred!\n");
                return 1;
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}