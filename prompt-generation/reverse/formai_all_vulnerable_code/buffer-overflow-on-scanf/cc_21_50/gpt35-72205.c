//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Introduction and user prompt
    printf("Welcome to Retro Adventure!\n");
    printf("You find yourself in a dark room with two doors.\n");
    printf("Which door will you choose?\n");
    printf("Enter '1' for the left door or '2' for the right door: ");

    // User input and door choice
    int door_choice;
    scanf("%d", &door_choice);

    // Left door scenario
    if (door_choice == 1) {
        printf("\nYou open the left door and find yourself in a forest.\n");
        printf("Do you want to:\n '1' Follow the path to the right\n '2' Follow the path to the left\n '3' Explore a random direction\n");
        printf("Enter your choice: ");

        int forest_choice;
        scanf("%d", &forest_choice);

        // Right path in forest scenario
        if (forest_choice == 1) {
            printf("\nYou follow the path to the right and come across a small village.\n");
            printf("Do you want to:\n '1' Enter the village\n '2' Continue on your adventure\n");
            printf("Enter your choice: ");

            int village_choice;
            scanf("%d", &village_choice);

            // Entering village scenario
            if (village_choice == 1) {
                printf("\nYou enter the village and meet the mayor.\n");
                printf("The mayor thanks you for coming and offers you a reward for your bravery.\n");
                printf("You have completed the Retro Adventure!\n");

            // Continuing on adventure scenario
            } else if (village_choice == 2) {
                printf("\nYou continue on your adventure and find yourself at a river.\n");
                printf("Do you want to:\n '1' Try to cross the river\n '2' Follow the riverbank\n '3' Explore a random direction\n");
                printf("Enter your choice: ");

                int river_choice;
                scanf("%d", &river_choice);

                // Trying to cross the river scenario
                if (river_choice == 1) {
                    printf("\nYou try to cross the river, but the current is too strong.\n");
                    printf("You have drowned.\n");
                    printf("GAME OVER\n");

                // Following the riverbank scenario
                } else if (river_choice == 2) {
                    printf("\nYou follow the riverbank and come across a hidden cave.\n");
                    printf("Do you want to:\n '1' Enter the cave\n '2' Continue on your adventure\n");
                    printf("Enter your choice: ");

                    int cave_choice;
                    scanf("%d", &cave_choice);

                    // Entering the cave scenario
                    if (cave_choice == 1) {
                        printf("\nYou enter the cave and find a treasure chest.\n");
                        printf("You have completed the Retro Adventure!\n");

                    // Continuing on adventure scenario
                    } else if (cave_choice == 2) {
                        printf("\nYou continue on your adventure and come across a dragon.\n");
                        printf("You have no weapons and cannot defeat the dragon.\n");
                        printf("You have died.\n");
                        printf("GAME OVER\n");
                    }

                // Exploring a random direction scenario
                } else if (river_choice == 3) {
                    printf("\nYou explore a random direction and come across a group of bandits.\n");
                    printf("The bandits rob you and leave you for dead.\n");
                    printf("GAME OVER\n");
                }

            }

        // Left path in forest scenario
        } else if (forest_choice == 2) {
            printf("\nYou follow the path to the left and find an abandoned house.\n"); 
            printf("Do you want to:\n '1' Enter the house\n '2' Continue on your adventure\n");
            printf("Enter your choice: ");

            int house_choice;
            scanf("%d", &house_choice);

            // Entering the house scenario
            if (house_choice == 1) {
                printf("\nYou enter the house and find an old journal.\n");
                printf("The journal reveals a treasure location deep in the mountains.\n");
                printf("You have completed the Retro Adventure!\n");

            // Continuing on adventure scenario
            } else if (house_choice == 2) {
                printf("\nYou continue on your adventure and come across a pack of wolves.\n");
                printf("You have no weapons and cannot defend yourself.\n");
                printf("You have been eaten alive.\n");
                printf("GAME OVER\n");
            }

        // Random direction scenario
        } else if (forest_choice == 3) {
            printf("\nYou explore a random direction and come across a group of goblins.\n");
            printf("The goblins capture you and enslave you.\n");
            printf("GAME OVER\n");
        }

    // Right door scenario
    } else if (door_choice == 2) {
        printf("\nYou open the right door and find yourself in a castle.\n");
        printf("Do you want to:\n '1' Explore the castle\n '2' Look for a way to escape\n");
        printf("Enter your choice: ");

        int castle_choice;
        scanf("%d", &castle_choice);

        // Exploring the castle scenario
        if (castle_choice == 1) {
            printf("\nYou explore the castle and find a hidden room.\n");
            printf("Inside the room, you find an old map.\n");
            printf("The map leads to a treasure location in a nearby swamp.\n");
            printf("You have completed the Retro Adventure!\n");

        // Looking for a way to escape scenario
        } else if (castle_choice == 2) {
            printf("\nYou look for a way to escape and find a secret tunnel.\n");
            printf("The tunnel leads to a forest.\n");
            printf("Do you want to:\n '1' Follow the path to the right\n '2' Follow the path to the left\n '3' Explore a random direction\n");
            printf("Enter your choice: ");

            int tunnel_choice;
            scanf("%d", &tunnel_choice);

            // Right path in forest scenario
            if (tunnel_choice == 1) {
                printf("\nYou follow the path to the right and come across a small town.\n");
                printf("Do you want to:\n '1' Enter the town\n '2' Continue on your adventure\n");
                printf("Enter your choice: ");

                int town_choice;
                scanf("%d", &town_choice);

                // Entering the town scenario
                if (town_choice == 1) {
                    printf("\nYou enter the town and find a friendly blacksmith.\n");
                    printf("The blacksmith offers to make you a weapon.\n");
                    printf("You have completed the Retro Adventure!\n");

                // Continuing on adventure scenario
                } else if (town_choice == 2) {
                    printf("\nYou continue on your adventure and find yourself at a river.\n");
                    printf("Do you want to:\n '1' Try to cross the river\n '2' Follow the riverbank\n '3' Explore a random direction\n");
                    printf("Enter your choice: ");

                    int river_choice;
                    scanf("%d", &river_choice);

                    // Trying to cross the river scenario
                    if (river_choice == 1) {
                        printf("\nYou try to cross the river, but the current is too strong.\n");
                        printf("You have drowned.\n");
                        printf("GAME OVER\n");

                    // Following the riverbank scenario
                    } else if (river_choice == 2) {
                        printf("\nYou follow the riverbank and come across a hidden cave.\n");
                        printf("Do you want to:\n '1' Enter the cave\n '2' Continue on your adventure\n");
                        printf("Enter your choice: ");

                        int cave_choice;
                        scanf("%d", &cave_choice);

                        // Entering the cave scenario
                        if (cave_choice == 1) {
                            printf("\nYou enter the cave and find a treasure chest.\n");
                            printf("You have completed the Retro Adventure!\n");

                        // Continuing on adventure scenario
                        } else if (cave_choice == 2) {
                            printf("\nYou continue on your adventure and come across a dragon.\n");
                            printf("You have no weapons and cannot defeat the dragon.\n");
                            printf("You have died.\n");
                            printf("GAME OVER\n");
                        }

                    // Exploring a random direction scenario
                    } else if (river_choice == 3) {
                        printf("\nYou explore a random direction and come across a group of bandits.\n");
                        printf("The bandits rob you and leave you for dead.\n");
                        printf("GAME OVER\n");
                    }

                }

            // Left path in forest scenario
            } else if (tunnel_choice == 2) {
                printf("\nYou follow the path to the left and find an abandoned house.\n");
                printf("Do you want to:\n '1' Enter the house\n '2' Continue on your adventure\n");
                printf("Enter your choice: ");

                int house_choice;
                scanf("%d", &house_choice);

                // Entering the house scenario
                if (house_choice == 1) {
                    printf("\nYou enter the house and find an old journal.\n");
                    printf("The journal reveals a treasure location deep in the mountains.\n");
                    printf("You have completed the Retro Adventure!\n");

                // Continuing on adventure scenario
                } else if (house_choice == 2) {
                    printf("\nYou continue on your adventure and come across a pack of wolves.\n");
                    printf("You have no weapons and cannot defend yourself.\n");
                    printf("You have been eaten alive.\n");
                    printf("GAME OVER\n");
                }

            // Random direction scenario
            } else if (tunnel_choice == 3) {
                printf("\nYou explore a random direction and come across a group of goblins.\n");
                printf("The goblins capture you and enslave you.\n");
                printf("GAME OVER\n");
            }

        }

    }

    return 0;
}