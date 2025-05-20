//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    int room = 1; // starting room
    int choice; // user's choice
    printf("Welcome to the Haunted Castle!\n\n");
    printf("You are a brave adventurer who has decided to explore this mysterious castle.\n");
    printf("Your goal is to find the treasure hidden somewhere inside the castle.\n");
    while (room != 0) { // loop until user reaches the end
        printf("\nYou are in room %d.\n", room);
        switch(room) { // display description of each room
            case 1:
                printf("The entrance hall is dimly lit and the air feels stale. You can hear whispers echoing through the space.\n");
                break;
            case 2:
                printf("You have entered the great hall. Tapestries hang on the walls depicting scenes of battle and victory.\n");
                break;
            case 3:
                printf("The dining hall is ornately decorated with a long, wooden table and chairs. There is a strange odor coming from the kitchen.\n");
                break;
            case 4:
                printf("The kitchen is deserted, but you can hear pots and pans clanging as if someone is cooking. You see a door leading to the servant's quarters.\n");
                break;
            case 5:
                printf("You have entered the servant's quarters. The room is musty and dark. You see a trapdoor on the ground.\n");
                break;
            case 6:
                printf("You have descended into the underground dungeon. Bones are scattered across the floor and you hear the moans of prisoners.\n");
                break;
            case 7:
                printf("You have entered the crypt. The air is thick with dust and the walls are adorned with cobwebs.\n");
                break;
            case 8:
                printf("You have entered the treasure room. You see chests overflowing with gold and jewels.\n");
                printf("Congratulations, you have found the treasure! You have completed your quest.\n");
                room = 0; // end loop
                break;
            default:
                printf("Error: Invalid room number.");
                return 1; // exit program if room is invalid
        }
        if (room != 0) { // prompt user if not at end of game
            printf("\nChoose your path:\n");
            if (room == 1) { // option for first room
                printf("1. Go north to the great hall.\n");
            }
            else {
                printf("1. Go back to the previous room.\n");
                printf("2. Go forward to the next room.\n");
            }
            printf("Enter 1 or 2: ");
            scanf("%d", &choice); // get user's choice
            if (choice == 1) {
                room--; // set room to previous room
            }
            else if (choice == 2) {
                room++; // set room to next room
            }
            else {
                printf("Invalid choice. Please enter 1 or 2.");
            }
        }
    }
    return 0;
}