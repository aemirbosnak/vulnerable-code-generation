//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");

    srand(time(NULL)); //set seed for random number generation

    int room = 1; //start in room 1
    int random;

    while(room != 0) { //while not in the exit room
        switch(room) {
            case 1:
                printf("\nYou enter a dark, musty room with a single flickering candle.\n");
                printf("Do you:\n");
                printf("1. Approach the candle?\n");
                printf("2. Look for another exit?\n");
                scanf("%d", &random);
                if(random == 1) {
                    printf("You approach the candle, but as soon as you blow it out,\na cold wind fills the room and whispers in your ear.\n");
                    printf("You quickly run for the door.\n");
                    room++;
                } else if(random == 2) {
                    printf("You search the room and find a hidden door behind a bookshelf.\n");
                    printf("You go through the door and enter another room.\n");
                    room = 3;
                } else {
                    printf("Invalid option. Try again.\n");
                }
                break;
            case 2:
                printf("\nYou enter a room with a ghostly apparition floating in the air.\n");
                printf("Do you:\n");
                printf("1. Run away quickly?\n");
                printf("2. Try to communicate with the ghost?\n");
                scanf("%d", &random);
                if(random == 1) {
                    printf("You run as fast as you can, but the ghost follows you.\n");
                    printf("You're trapped in a circle of ghosts, and they start to close in on you.\n");
                    printf("GAME OVER.\n");
                    room = 0;
                } else if(random == 2) {
                    printf("You try to communicate with the ghost, but it doesn't respond.\n");
                    printf("You notice a cold breeze and see a message written in frost on the window.\n");
                    printf("\"GET OUT\"\n");
                    room--;
                } else {
                    printf("Invalid option. Try again.\n");
                }
                break;
            case 3:
                printf("\nYou enter a room with a large chest in the center.\n");
                printf("Do you:\n");
                printf("1. Open the chest?\n");
                printf("2. Look for another exit?\n");
                scanf("%d", &random);
                if(random == 1) {
                    printf("You open the chest and find a treasure trove of gold and jewels!\n");
                    printf("But as soon as you touch the treasure, the room starts to shake and the walls close in.\n");
                    printf("You barely escape with your life, but the treasure is lost.\n");
                    room=2;
                } else if(random == 2) {
                    printf("You look for another exit and find a staircase leading down.\n");
                    printf("You cautiously descend the stairs.\n");
                    room++;
                } else {
                    printf("Invalid option. Try again.\n");
                }
                break;
            case 4:
                printf("\nYou enter a dank, musty basement with cobwebs covering every surface.\n");
                printf("Do you:\n");
                printf("1. Explore the basement?\n");
                printf("2. Look for a way out?\n");
                scanf("%d", &random);
                if(random == 1) {
                    printf("You explore the basement and find an old diary.\n");
                    printf("The diary tells the story of the previous owner of the house.\n");
                    printf("It mentions a secret passage behind the bookshelf in the first room.\n");
                    room = 1; //go back to first room
                } else if(random == 2) {
                    printf("You look for a way out and find a door at the far end of the room.\n");
                    printf("You go through the door and find yourself outside the house.\n");
                    printf("CONGRATULATIONS! You made it out alive.\n");
                    room = 0; //exit the loop
                } else {
                    printf("Invalid option. Try again.\n");
                }
                break;
            default:
                printf("\nERROR.\n");
                break;
        }
    }
    return 0;
}