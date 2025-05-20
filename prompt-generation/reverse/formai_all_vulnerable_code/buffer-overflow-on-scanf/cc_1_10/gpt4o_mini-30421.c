//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DESC 256

void display_intro();
void choose_path();
void cave_entrance();
void tunnel();
void treasure_room();
void monster_encounter();
void surprise_event();

int main() {
    srand(time(NULL));
    display_intro();
    choose_path();
    return 0;
}

void display_intro() {
    printf("Welcome to the 'Surprise Cave Adventure'!\n");
    printf("You find yourself trapped in a dark, eerie cave.\n");
    printf("Your goal is to navigate through the cave and find your way out.\n");
    printf("Be careful! Surprises await at every turn!\n\n");
}

void choose_path() {
    int choice;
    printf("You are at the cave entrance. You can either:\n");
    printf("1. Enter the cave\n");
    printf("2. Turn back and leave\n");
    printf("Choose an option (1 or 2): ");
    
    scanf("%d", &choice);

    if (choice == 1) {
        cave_entrance();
    } else {
        printf("You have chosen to leave. The adventure ends here.\n");
        exit(0);
    }
}

void cave_entrance() {
    int choice;
    printf("\nYou have stepped into the cave. It's dark and damp.\n");
    printf("You see two paths in front of you:\n");
    printf("1. A narrow tunnel\n");
    printf("2. A wide passage\n");
    printf("Choose a path (1 or 2): ");
    
    scanf("%d", &choice);

    if (choice == 1) {
        tunnel();
    } else if (choice == 2) {
        treasure_room();
    } else {
        printf("Invalid choice. The cave collapses, and you are trapped forever!\n");
        exit(0);
    }
}

void tunnel() {
    printf("\nYou crawl through the narrow tunnel.\n");
    surprise_event();
    printf("After a long struggle, you finally reach an open space.\n");
    printf("But wait! There's a monster here!\n");
    monster_encounter();
}

void treasure_room() {
    printf("\nYou walk into a bright room filled with treasures!\n");
    surprise_event();
    printf("While collecting gold, you trigger a trap, and the room starts collapsing!\n");
    printf("You must escape swiftly!\n");
    monster_encounter();
}

void monster_encounter() {
    int choice;
    printf("What will you do?\n");
    printf("1. Fight the monster\n");
    printf("2. Run away\n");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You bravely confront the monster!\n");
        printf("After a fierce battle, you defeat the beast and find a path out!\n");
        printf("Congratulations, you've escaped the cave!\n");
    } else if (choice == 2) {
        printf("You choose to run away!\n");
        printf("Unfortunately, the monster catches you, and you meet a grim fate.\n");
        exit(0);
    } else {
        printf("Invalid choice. The monster gets you!\n");
        exit(0);
    }
}

void surprise_event() {
    int event = rand() % 3;
    switch (event) {
        case 0:
            printf("Surprise! You found a magical lamp!\n");
            printf("Rubbing it might give you a helpful genie...\n");
            break;
        case 1:
            printf("Surprise! A swarm of bats flies overhead, startling you!\n");
            printf("You lose your balance but manage to hold on!\n");
            break;
        case 2:
            printf("Surprise! You discover a hidden cache of provisions!\n");
            printf("You gain extra strength for your journey ahead!\n");
            break;
        default:
            break;
    }
}