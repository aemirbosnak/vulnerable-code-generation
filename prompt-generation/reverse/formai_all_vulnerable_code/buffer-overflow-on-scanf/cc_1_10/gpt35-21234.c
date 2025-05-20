//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to get a random number between min and max */
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time
    int choice; // User's choice
    int hasKey = 0; // Player starts without a key

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are standing in front of a haunted house. There is a sign that reads 'Enter at your own risk!'\n");
    printf("1. Enter the house\n");
    printf("2. Leave\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou step into the hallway. It is dark and cobwebby. You hear strange noises coming from different directions.\n");
        printf("You notice there are three doors in front of you labeled A, B, C\n\n");
        printf("1. Open door A\n");
        printf("2. Open door B\n");
        printf("3. Open door C\n");
        printf("4. Leave the house\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou enter a room filled with spiders and webs! You quickly leave the room.\n");
        }
        else if (choice == 2) {
            printf("\nYou enter a room filled with bats! You quickly leave the room.\n");
        }
        else if (choice == 3) {
            printf("\nYou enter a room filled with ghosts! You try to leave but the door slams shut behind you. You are trapped!\n");
            printf("You notice a key on the ground. Do you pick it up?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");

            scanf("%d", &choice);

            if (choice == 1) {
                hasKey = 1;
                printf("\nYou pick up the key. You can now use it to open doors.\n");
            }
            else if (choice == 2) {
                printf("\nYou leave the key and continue searching for a way out.\n");
            }
        }
        else if (choice == 4) {
            printf("\nYou become too scared and run out of the house!\n");
            return 0;
        }

        printf("\nThe hallway splits into two directions. You can hear faint whispers coming from the left.\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nYou follow the whispers and enter a room with a coffin in the middle. Suddenly, the lid opens and a vampire jumps out!\n");
            if (hasKey) {
                printf("You quickly use the key to unlock the door and escape.\n");
                return 0;
            }
            else {
                printf("You try to escape but the door is locked. You are trapped!\n");
                printf("The vampire bites you and you become a vampire too!\n");
                return 0;
            }
        }
        else if (choice == 2) {
            printf("\nYou follow the hallway and enter a room with an old mirror.\n");
            printf("You look into the mirror and see your own reflection.\n");
            printf("As you turn around to leave the room, your reflection stays in the mirror and starts to move on its own!\n");
            if (hasKey) {
                printf("You quickly use the key to unlock the door and escape.\n");
                return 0;
            }
            else {
                printf("You try to escape but the door is locked. You are trapped!\n");
                printf("Your reflection pulls you into the mirror. You are trapped inside forever!\n");
                return 0;
            }
        }
    }
    else if (choice == 2) {
        printf("\nYou decide not to enter the house. You leave but you can't get the image of the haunted house out of your mind.\n");
        return 0;
    }
    
    return 0;
}