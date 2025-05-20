//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clear_screen() {
    printf("\033[H\033[J");
}

void display_intro() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    printf("You are on a quest to find the hidden treasure deep within the forest.\n");
    printf("Be wary of the challenges and make wise choices.\n\n");
}

void display_map() {
    printf("Map of the forest:\n");
    printf("1. Path to the left\n");
    printf("2. Path to the right\n");
    printf("3. Path straight ahead\n");
    printf("4. Climb the tree\n");
    printf("5. Exit the Forest (not recommended)\n\n");
}

int choose_path() {
    int choice;
    printf("Choose your path (1-5): ");
    scanf("%d", &choice);
    return choice;
}

void encounter_wildlife() {
    int action;
    printf("You encounter a wild animal!\n");
    printf("1. Run away\n");
    printf("2. Try to scare it away\n");
    printf("3. Observe it quietly\n");
    printf("Choose your action: ");
    scanf("%d", &action);

    if (action == 1) {
        printf("You escaped safely!\n");
    } else if (action == 2) {
        printf("The animal feels threatened and runs away.\n");
    } else if (action == 3) {
        printf("You learned something new about wildlife.\n");
    } else {
        printf("Invalid action!\n");
    }
}

void find_treasure() {
    printf("Congratulations! You found the hidden treasure!\n");
    printf("You now possess a bag full of gold and jewels!\n");
    exit(0);
}

void explore_forest() {
    srand(time(NULL));
    int choice;
    while(1) {
        display_map();
        choice = choose_path();

        switch(choice) {
            case 1:
                printf("You took the path to the left.\n");
                if (rand() % 2) {
                    printf("You find a hidden cave filled with treasures!\n");
                    find_treasure();
                } else {
                    encounter_wildlife();
                }
                break;
            
            case 2:
                printf("You took the path to the right.\n");
                if (rand() % 2) {
                    printf("You stumble upon a wise old man who offers you advice.\n");
                } else {
                    printf("You encounter a challenging puzzle to solve.\n");
                }
                break;
            
            case 3:
                printf("You went straight ahead.\n");
                if (rand() % 2) {
                    printf("You find a mysterious tree, it's glowing!\n");
                    printf("You feel a magical energy flowing through you.\n");
                } else {
                    printf("You walked into a swamp! Watch your step.\n");
                }
                break;

            case 4:
                printf("You decided to climb the tree.\n");
                if (rand() % 2) {
                    printf("From high above, you see a clear path to the treasure!\n");
                    find_treasure();
                } else {
                    printf("You got stuck in the branches! Climb down carefully.\n");
                }
                break;

            case 5:
                printf("You chose to exit the forest...\n");
                printf("You may have escaped, but you left the treasure behind!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please choose a valid path (1-5).\n");
        }
    }
}

int main() {
    clear_screen();
    display_intro();
    explore_forest();
    return 0;
}