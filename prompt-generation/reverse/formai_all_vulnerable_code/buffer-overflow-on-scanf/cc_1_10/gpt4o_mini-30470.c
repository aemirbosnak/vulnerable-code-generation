//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_intro();
void show_menu();
void explore_forest();
void enter_castle();
void visit_village();
void final_adventure();

int main() {
    print_intro();
    show_menu();
    return 0;
}

void print_intro() {
    printf("Welcome to the Inquisitive Adventure Game!\n");
    printf("In a land of mystery and intrigue, you find yourself at a crossroads.\n");
    printf("What will you do next? Choose wisely!\n\n");
}

void show_menu() {
    int choice;

    do {
        printf("You are standing at a crossroad. Where do you want to go?\n");
        printf("1. Explore the Forest\n");
        printf("2. Enter the Castle\n");
        printf("3. Visit the Village\n");
        printf("4. Exit Game\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explore_forest();
                break;
            case 2:
                enter_castle();
                break;
            case 3:
                visit_village();
                break;
            case 4:
                printf("Thank you for playing! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void explore_forest() {
    printf("\nYou venture into the mysterious forest.\n");
    printf("As you walk deeper, you hear rustling in the bushes.\n");
    printf("What do you want to do?\n");
    printf("1. Investigate the noise\n");
    printf("2. Continue walking\n");
    printf("3. Turn back\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You cautiously approach the bushes...\n");
        printf("A cute rabbit hops out and greets you!\n");
    } else if (choice == 2) {
        printf("You confidently continue walking and discover a hidden waterfall!\n");
    } else {
        printf("Feeling uneasy, you turn back and return to the crossroad.\n");
    }
}

void enter_castle() {
    printf("\nYou step into the grand, yet eerie castle.\n");
    printf("The halls echo with whispers of the past.\n");
    printf("What will you do?\n");
    printf("1. Visit the throne room\n");
    printf("2. Inspect the library\n");
    printf("3. Leave the castle\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You enter the throne room. It's dark and dusty.\n");
        printf("Suddenly, a ghost appears! It asks: 'What is your purpose?'\n");
        final_adventure();
    } else if (choice == 2) {
        printf("You find ancient tomes filled with lost knowledge.\n");
        printf("You uncover a spell that opens a portal to another world!\n");
    } else {
        printf("You decide to leave the castle and return to the crossroad.\n");
    }
}

void visit_village() {
    printf("\nYou arrive at a quaint village bustling with activity.\n");
    printf("The villagers greet you warmly.\n");
    printf("What do you wish to do?\n");
    printf("1. Talk to the blacksmith\n");
    printf("2. Visit the tavern\n");
    printf("3. Explore the market\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The blacksmith offers you a powerful sword! You feel a surge of strength!\n");
    } else if (choice == 2) {
        printf("You enjoy a hearty meal and gather information about the land.\n");
    } else {
        printf("You buy some supplies for your adventures ahead.\n");
    }
}

void final_adventure() {
    printf("1. Answer with bravery.\n");
    printf("2. Answer with cunning.\n");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You declare your need for adventure, and the ghost allows you to pass!\n");
    } else {
        printf("The ghost is impressed by your cleverness and reveals a hidden treasure!\n");
    }
}