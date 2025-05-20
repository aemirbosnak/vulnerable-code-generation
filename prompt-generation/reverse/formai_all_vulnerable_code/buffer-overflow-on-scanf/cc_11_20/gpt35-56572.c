//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the Surrealist Adventure Game!\n");
    printf("------------------------------------------\n");
    printf("You find yourself in a strange world with no memory of how you got here.\n");
    printf("As you look around, you see a donut floating in mid-air and a tree with eyes.\n");
    printf("What would you like to do?\n");
    printf("1. Try to eat the donut\n");
    printf("2. Talk to the tree\n");
    printf("3. Look for a way out\n");
    printf("4. Do a dance\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You try to take a bite of the donut, but as soon as your teeth touch it, it disappears.\n");
            break;
        case 2:
            printf("As you approach the tree, it starts speaking to you in a language you don't understand.\n");
            printf("However, you somehow manage to communicate with it using interpretive dance.\n");
            printf("The tree tells you that you need to find the key to escape this world.\n");
            break;
        case 3:
            printf("You start walking aimlessly, hoping to find a way out.\n");
            printf("However, the landscape keeps changing and you keep going in circles.\n");
            printf("Suddenly, you come across a door in the middle of nowhere.\n");
            printf("What would you like to do?\n");
            printf("1. Try to open the door\n");
            printf("2. Knock on the door\n");

            int doorChoice;
            scanf("%d", &doorChoice);

            if (doorChoice == 1) {
                printf("The door opens and you step through it, only to find yourself back at the beginning of your journey.\n");
            } else if (doorChoice == 2) {
                printf("As you knock on the door, it disappears and you fall through a hole.\n");
                printf("You wake up in a room full of mirrors.\n");
                printf("What would you like to do?\n");
                printf("1. Look at yourself in the mirrors\n");
                printf("2. Try to break the mirrors\n");

                int mirrorChoice;
                scanf("%d", &mirrorChoice);

                if (mirrorChoice == 1) {
                    printf("As you look at yourself in the mirrors, your reflection starts speaking to you.\n");
                    printf("It tells you that you are not who you think you are and that your memories are false.\n");
                } else if (mirrorChoice == 2) {
                    printf("As you try to break the mirrors, your hand goes through one of them.\n");
                    printf("You realize that the mirrors are actually portals to different dimensions.\n");
                    printf("Which portal would you like to enter?\n");
                    printf("1. The Upside-Down\n");
                    printf("2. The Land of the Giant Snails\n");

                    int portalChoice;
                    scanf("%d", &portalChoice);

                    if (portalChoice == 1) {
                        printf("As you enter the Upside-Down, you hear a voice calling out to you.\n");
                        printf("You follow the voice and find an astronaut stranded on a foreign planet.\n");
                        printf("He tells you that the only way to escape this world is to build a spaceship.\n");
                    } else if (portalChoice == 2) {
                        printf("As you enter the Land of the Giant Snails, you are chased by a giant snail.\n");
                        printf("You manage to escape by jumping into a lake, only to find out that the lake is made of lava.\n");
                        printf("You wake up back at the beginning of your journey, realizing that it was all a dream.\n");
                    } else {
                        printf("Sorry, that is not a valid choice.");
                    }
                } else {
                    printf("Sorry, that is not a valid choice.");
                }
            } else {
                printf("Sorry, that is not a valid choice.");
            }
            break;
        case 4:
            printf("You start doing a dance and suddenly the ground starts shaking.\n");
            printf("As you continue to dance, a giant disco ball descends from the sky and starts playing music.\n");
            printf("You dance your way out of this world and wake up back in your bed.\n");
            break;
        default:
            printf("Sorry, that is not a valid choice.");
            break;
    }

    return 0;
}