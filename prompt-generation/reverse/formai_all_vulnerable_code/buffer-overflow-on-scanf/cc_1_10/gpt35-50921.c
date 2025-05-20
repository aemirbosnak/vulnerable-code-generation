//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int);

int main() {
    int playerChoice, ghostPosition = rand() % 10 + 1;
    srand(time(NULL));
 
    printf("\n\t\tWelcome to the Haunted House Simulator!\n\n");
    printf("You find yourself in a dimly lit room with two doors in front of you.\n");
    printf("What do you want to do? \n");
    printf("[1] Go through the left door \n[2] Go through the right door \n[3] Turn back and leave\n");
    scanf("%d", &playerChoice);

    if (playerChoice == 1 || playerChoice == 2) {
        // Player chooses a door
        printf("\nYou enter a dark hallway...\n");
        delay(2000);
        printf("You feel a chill run down your spine as you hear something breathing behind you...\n");
        delay(2000);
        printf("Suddenly, a ghost appears right in front of you!\n");
        delay(2000);
        printf("It moves towards you, levitating off the ground...\n");
        delay(2000);
        printf("What do you want to do? \n");
        printf("[1] Run away \n[2] Stand your ground \n");
        scanf("%d", &playerChoice);

        if (playerChoice == 1) {
            // Player runs away
            printf("\nYou turn around and sprint as fast as you can back to the room where you started...\n");
            delay(2000);
            printf("As you breathe heavily, you realize the ghost is now blocking your exit.\n");
            delay(2000);
            printf("You're trapped...\n");
            delay(2000);
            printf("GAME OVER.\n");
        } else {
            // Player stands their ground
            printf("\nYou stand your ground and face the ghost...\n");
            delay(2000);
            if (ghostPosition == playerChoice) {
                printf("You successfully exorcise the ghost with your bravery and it disappears.\n");
                delay(2000);
                printf("CONGRATULATIONS. You survived the Haunted House Simulator!\n");
            } else {
                printf("The ghost senses your fear and attacks!\n");
                delay(2000);
                printf("GAME OVER.\n");
            }
        }
    } else {
        // Player leaves
        printf("\nYou quickly turn around and exit the house...\n");
        delay(2000);
        printf("You take a deep breath of fresh air and feel relieved that you escaped the haunted house...\n");
        delay(2000);
        printf("Thanks for playing the Haunted House Simulator!\n");
    }

    return 0;
}

void delay(int milliseconds) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}