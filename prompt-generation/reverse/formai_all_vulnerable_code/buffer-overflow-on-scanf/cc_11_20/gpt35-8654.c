//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // generate the random seed
    srand(time(0));
    
    // initialize the variables
    int room = 1;
    int scare_chance = 0;
    int scared = 0;
    int game_over = 0;

    while (!game_over) {
        // print the room description
        printf("\nYou are in room %d. ", room);

        // set the scare chance based on the room
        if (room == 1) {
            scare_chance = 20;
            printf("There is a strange feeling in the air.");
        } else if (room == 2) {
            scare_chance = 30;
            printf("You hear eerie music in the distance.");
        } else if (room == 3) {
            scare_chance = 40;
            printf("There are shadows moving in the corners of your eyes.");
        } else if (room == 4) {
            scare_chance = 50;
            printf("You smell the faint scent of death.");
        } else if (room == 5) {
            scare_chance = 70;
            printf("You see a figure standing in the center of the room.");
        } else if (room == 6) {
            scare_chance = 90;
            printf("You hear a bloodcurdling scream.");
        } else { // room == 7
            printf("You found the exit... or so you thought.");
            game_over = 1;
            break;
        }

        // determine if the player gets scared
        int roll = rand() % 100 + 1;
        if (roll <= scare_chance) {
            scared = 1;
            printf("\n\n\n You got scared! Game Over. \n\n\n");
            break;
        }

        // allow the player to move to another room
        int choice = 0;
        printf("\n\nWhich room do you want to go to? (1-7): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 7 && choice != room) {
            room = choice;
        } else {
            printf("\n Invalid choice. ");
        }        
    }

    // print the game over message
    if (scared) {
        printf("\n\n\nBetter luck next time!");
    } else {
        printf("\n\n\nCongratulations! You escaped the haunted house.");
    }

    return 0;
}