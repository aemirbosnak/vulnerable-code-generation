//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void print_intro() {
    printf("Welcome to the Enchanted Forest Adventure!\n");
    printf("You find yourself at the edge of a dark and mysterious forest.\n");
    printf("Your goal is to find the magical treasure hidden deep inside.\n\n");
}

void print_options() {
    printf("Options:\n");
    printf("1. Go deeper into the forest\n");
    printf("2. Climb a tree to get a better view\n");
    printf("3. Set up a camp and rest\n");
    printf("4. Exit the game\n");
}

int choose_option() {
    int choice;
    printf("What would you like to do? (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void go_deeper() {
    printf("You bravely venture deeper into the forest.\n");
    printf("The trees grow taller, and the air thickens with mystery.\n");
    
    // Random event for going deeper
    int event = rand() % 3;
    if (event == 0) {
        printf("You stumble upon a sparkling stream.\n");
        printf("The water is crystal clear and inviting.\n");
    } else if (event == 1) {
        printf("A wild wolf appears! You must quickly decide what to do!\n");
    } else {
        printf("You find a hidden path that leads you closer to your goal!\n");
    }
}

void climb_tree() {
    printf("You climb a sturdy tree and gain an impressive view of the forest.\n");
    printf("You can see the outline of a mountain in the distance.\n");
    int sight = rand() % 2;
    if (sight == 0) {
        printf("You spot something shiny at the base of the mountain!\n");
    } else {
        printf("You see a group of cave entrances nearby.\n");
    }
}

void setup_camp() {
    printf("You decide to set up camp and take a rest.\n");
    printf("As night falls, you hear mysterious sounds around you.\n");
    int spooky_event = rand() % 2;
    if (spooky_event == 0) {
        printf("A friendly owl lands nearby and offers you wisdom.\n");
    } else {
        printf("You hear rustling in the bushes, but nothing appears.\n");
    }
}

void exit_game() {
    printf("You decide to leave the adventure behind. Perhaps another day!\n");
    exit(0);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    print_intro();
    
    while (1) {
        print_options();
        int choice = choose_option();
        
        switch (choice) {
            case 1:
                go_deeper();
                break;
            case 2:
                climb_tree();
                break;
            case 3:
                setup_camp();
                break;
            case 4:
                exit_game();
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 4.\n");
        }
        printf("\n");
    }
    
    return 0;
}