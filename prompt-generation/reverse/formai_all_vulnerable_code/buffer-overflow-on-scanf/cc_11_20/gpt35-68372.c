//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You play as the great detective, Sherlock Holmes,\n");
    printf("who has been called to investigate strange happenings in a local haunted house.\n\n");

    srand(time(NULL)); // Seed for random number generator

    int sanity = 100; // Starting sanity
    int num_rooms_explored = 0; // Keep track of how many rooms the player has visited
    int max_rooms = 5; // Maximum number of rooms to explore
    int ghost_encounter_chance = 25; // Percentage chance of encountering a ghost in a room
    int ghost_encounter_sanity_loss = 30; // Amount of sanity lost when encountering a ghost
    int max_sanity = 100; // Maximum sanity
    int min_sanity = 0; // Minimum sanity before game over
    int has_key = 0; // Whether or not the player has found the key to escape the haunted house

    while (sanity > min_sanity && num_rooms_explored < max_rooms && !has_key) {
        printf("You are in a new room. There are several doors leading out of this room.\n");
        printf("Which door would you like to go through?\n\n");

        int num_doors = rand() % 3 + 2; // Random number of doors between 2 and 4
        for (int i = 1; i <= num_doors; i++) {
            printf("Door %d\n", i);
        }

        int chosen_door;
        printf("\nEnter the number of the door you would like to go through:");
        scanf("%d", &chosen_door);

        if (chosen_door < 1 || chosen_door > num_doors) { // Invalid input
            printf("You walk into a wall and lose some sanity...\n");
            sanity -= 10;
        }
        else { // Valid input
            printf("You walk through Door %d...\n", chosen_door);

            int ghost_encounter_roll = rand() % 100 + 1;
            if (ghost_encounter_roll <= ghost_encounter_chance) { // Ghost encounter!
                printf("You encounter a ghost!\n");
                printf("You lose %d sanity...\n", ghost_encounter_sanity_loss);
                sanity -= ghost_encounter_sanity_loss;
            }
            else { // No ghost encounter
                printf("Phew, no ghosts in this room...\n");
            }

            if (sanity <= min_sanity) { // Sanity has reached the minimum threshold for game over
                printf("You have lost all your sanity and gone insane! Game over...\n");
                break;
            }

            num_rooms_explored++;

            int key_roll = rand() % 2; // 50-50 chance of finding the key in a room
            if (key_roll == 1 && !has_key) { // Key found!
                printf("You find a key in this room!\n");
                has_key = 1;
            }

            printf("Your sanity level is: %d out of %d\n", sanity, max_sanity);
        }
    }

    if (num_rooms_explored == max_rooms) { // Player successfully explored all the rooms
        printf("You have explored all the rooms and found no ghostly evidence. Case closed!\n");
    }
    else if (has_key) { // Player found the key and can escape the haunted house
        printf("You have found the key and escaped the haunted house!\n");
        printf("Congratulations, Sherlock Holmes! You have solved the case.\n");
    }

    return 0;
}