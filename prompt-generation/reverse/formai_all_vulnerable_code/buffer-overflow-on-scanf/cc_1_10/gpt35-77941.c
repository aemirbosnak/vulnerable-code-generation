//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void choosePath(int currRoom);

int main(){
    srand(time(NULL)); // Seed for random number generator
    printf("You are the captain of a space ship and have landed on an unknown planet.\n");
    printf("You step out of the ship and find yourself in a room with three portals leading to different paths.\n");
    choosePath(1); // Start with Room 1
    return 0; // End of the program
}

void choosePath(int currRoom){
    int choice;
    if(currRoom == 1){
        printf("\nYou are in Room 1. Which path do you choose?\n");
        printf("1. Path to the left\n");
        printf("2. Path straight ahead\n");
        printf("3. Path to the right\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nYou enter a dark room with a strange device in the center.\n");
                printf("Do you want to activate the device?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("\nYou feel yourself transported to another dimension.\n");
                    printf("You encounter an alien race that speaks in a language you don't understand.\n");
                    printf("They seem to be friendly and offer you a device that can control gravity.\n");
                    printf("Do you accept the device?\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    scanf("%d", &choice);
                    if(choice == 1){
                        printf("\nYou acquire the control device and return to your ship.\n");
                        printf("Where do you want to go next?\n");
                        printf("1. Path straight ahead\n");
                        printf("2. Path to the right\n");
                        scanf("%d", &choice);
                        choosePath(choice+1); // Proceed to corresponding room
                    }
                    else{
                        printf("\nThe aliens seem disappointed that you refused their offer.\n");
                        printf("They send you back to your own dimension.\n");
                        printf("You find yourself in a room with two portals.\n");
                        choosePath(2);
                    }
                }
                else{
                    printf("\nYou decide not to activate the device and return to Room 1.\n");
                    choosePath(currRoom); // Stay in the same room
                }
                break;
            case 2:
                printf("\nYou enter a room with multiple doors, each leading to different dimensions.\n");
                printf("Choose a door to enter:\n");
                printf("1. Door A\n");
                printf("2. Door B\n");
                printf("3. Door C\n");
                scanf("%d", &choice);
                printf("\nYou enter Door %c and find yourself in a new dimension.\n", 'A'+choice-1);
                printf("Where do you want to go next?\n");
                printf("1. Path to the left\n");
                printf("2. Path to the right\n");
                scanf("%d", &choice);
                choosePath(choice+1); // Proceed to corresponding room
                break;
            case 3:
                printf("\nYou enter a room with a giant puzzle that seems to unlock a hidden treasure.\n");
                printf("Do you want to try and solve the puzzle?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("\nYou spend several hours solving the puzzle and finally unlock the treasure.\n");
                    printf("You find a piece of advanced technology that enhances your ship's weapons system.\n");
                    printf("Where do you want to go next?\n");
                    printf("1. Path straight ahead\n");
                    printf("2. Path to the left\n");
                    scanf("%d", &choice);
                    choosePath(choice+1); // Proceed to corresponding room
                }
                else{
                    printf("\nYou decide not to try the puzzle and return to Room 1.\n");
                    choosePath(currRoom); // Stay in the same room
                }
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                choosePath(currRoom); // Stay in the same room
                break;
        }
    }
    else if(currRoom == 2){
        printf("\nYou are in Room 2. Which path do you choose?\n");
        printf("1. Path to the left\n");
        printf("2. Path to the right\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nYou enter a room filled with strange creatures that resemble giant spiders.\n");
                printf("Do you want to fight them?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("\nYou draw your weapon and engage the creatures in combat.\n");
                    if(rand()%2 == 0){
                        printf("You emerge victorious, having defeated the creatures.\n");
                        printf("Where do you want to go next?\n");
                        printf("1. Path to the right\n");
                        printf("2. Return to Room 1\n");
                        scanf("%d", &choice);
                        choosePath(choice+1); // Proceed to corresponding room
                    }
                    else{
                        printf("The creatures overwhelm you and you perish.\n");
                        printf("Game Over\n");
                        exit(0); // End the program
                    }
                }
                else{
                    printf("\nYou decide not to fight and return to Room 2.\n");
                    choosePath(currRoom); // Stay in the same room
                }
                break;
            case 2:
                printf("\nYou enter a room with a strange object that seems to be emitting a powerful energy.\n");
                printf("Do you want to investigate?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("\nYou approach the object and feel a rush of energy flow through you.\n");
                    printf("You gain the ability to warp space-time and manipulate reality itself.\n");
                    printf("Where do you want to go next?\n");
                    printf("1. Path to the right\n");
                    printf("2. Return to Room 1\n");
                    scanf("%d", &choice);
                    choosePath(choice+1); // Proceed to corresponding room
                }
                else{
                    printf("\nYou decide not to investigate and return to Room 2.\n");
                    choosePath(currRoom); // Stay in the same room
                }
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                choosePath(currRoom); // Stay in the same room
                break;
        }
    }
    else if(currRoom == 3){
        printf("\nYou are in Room 3. Which path do you choose?\n");
        printf("1. Path straight ahead\n");
        printf("2. Return to Room 1\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nYou enter a room with a massive black hole at the center.\n");
                printf("Do you want to explore the black hole?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);
                if(choice == 1){
                    printf("\nYou enter the black hole and find yourself in a parallel dimension.\n");
                    printf("You witness the destruction of entire galaxies and the birth of new ones.\n");
                    printf("You acquire a deep understanding of the universe.\n");
                    printf("Where do you want to go next?\n");
                    printf("1. Return to Room 3\n");
                    printf("2. Return to Room 1\n");
                    scanf("%d", &choice);
                    choosePath(choice+1); // Proceed to corresponding room
                }
                else{
                    printf("\nYou decide not to explore the black hole and return to Room 3.\n");
                    choosePath(currRoom); // Stay in the same room
                }
                break;
            case 2:
                printf("\nYou return to Room 1.\n");
                choosePath(1); // Go back to Room 1
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                choosePath(currRoom); // Stay in the same room
                break;
        }
    }
    else{
        printf("\nInvalid room number. Please try again.\n");
        choosePath(currRoom-3); // Go back to Room 1
    }
}