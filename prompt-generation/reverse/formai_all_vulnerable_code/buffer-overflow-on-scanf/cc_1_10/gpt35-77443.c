//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomizer, player_choice, current_room = 1, points = 0;
    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You enter a post-apocalyptic mansion, dilapidated and shrouded in mist.\n");
    printf("Your objective is to find the exit, beware of the horrors that await.\n");

    do {
        printf("You are in Room %d, there are 3 doors in front of you. Which door will you choose?\n", current_room);
        printf("1 - Left door\n2 - Center door\n3 - Right door\n");
        printf("Enter your choice: ");
        scanf("%d", &player_choice);

        switch(player_choice) {
            case 1:
                printf("You open the left door and find a blood-stained room with a ghostly figure walking towards you.\n");
                randomizer = rand() % 4;

                if(randomizer == 0) {
                    printf("The ghost overwhelms you and you die a miserable death. GAME OVER.\n");
                    return 0;
                } else {
                    printf("You manage to fight off the ghost, barely escaping with your life. +50 points.\n");
                    points += 50;
                }

                current_room++;
                break;

            case 2:
                printf("You open the center door and find a laboratory with a mutated creature locked in a cage. The creature notices you and starts raging.\n");
                randomizer = rand() % 5;

                if(randomizer == 0) {
                    printf("The creature breaks free of its cage and devours you alive. GAME OVER.\n");
                    return 0;
                } else {
                    printf("You find a tranquilizer gun and manage to subdue the creature. +75 points.\n");
                    points += 75;
                }

                current_room++;
                break;

            case 3:
                printf("You open the right door and find a staircase leading down.\n");
                current_room += 2;
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(current_room <= 10);

    printf("You finally reach the exit and burst through the door, relieved to breathe fresh air again. Total score: %d\n", points);

    return 0;
}