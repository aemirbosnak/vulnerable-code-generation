//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_ROOMS 5

// Function prototypes
void enter_room1();
void enter_room2();
void enter_room3();
void enter_room4();
void enter_room5();

void display_intro();
void choose_room();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    display_intro();
    choose_room();

    return 0;
}

void display_intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Prepare yourself for a terrifying adventure...\n");
    sleep(2);
    printf("You will explore different rooms within the haunted house.\n");
    sleep(2);
    printf("Let's see what awaits you!\n");
    sleep(1);
}

void choose_room() {
    int room_number = rand() % NUM_ROOMS + 1;

    switch(room_number) {
        case 1:
            enter_room1();
            break;
        case 2:
            enter_room2();
            break;
        case 3:
            enter_room3();
            break;
        case 4:
            enter_room4();
            break;
        case 5:
            enter_room5();
            break;
        default:
            printf("Error: Invalid room number.\n");
            break;
    }
}

void enter_room1() {
    printf("You have entered the Library of Shadows.\n");
    sleep(1);
    printf("Books line the walls, whispering secrets long forgotten...\n");
    sleep(2);
    printf("A ghost suddenly appears, asking for the title of its favorite book.\n");
    sleep(2);
    printf("What will you do? (1. Answer. 2. Run)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You bravely answered, and the ghost thanks you!\n");
    } else {
        printf("You ran away screaming!\n");
    }
}

void enter_room2() {
    printf("You have entered the Kitchen of Horrors.\n");
    sleep(1);
    printf("The smell of rotten food fills your nostrils...\n");
    sleep(2);
    printf("Suddenly, a talking rat offers you a dish: 'Will you try my stew?'\n");
    sleep(2);
    printf("What will you choose? (1. Try it. 2. Decline)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You tried the stew and it was delicious! The rat invites you for dinner.\n");
    } else {
        printf("You declined and the rat curses you!\n");
    }
}

void enter_room3() {
    printf("You have entered the Basement of Screams.\n");
    sleep(1);
    printf("It's dark and damp, with echoes surrounding you...\n");
    sleep(2);
    printf("A creepy figure approaches and asks for your name.\n");
    sleep(2);
    printf("What will you do? (1. Tell it. 2. Stay Silent)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You told it your name. It tells you its dark secret!\n");
    } else {
        printf("You stayed silent and the figure disappeared into the shadows.\n");
    }
}

void enter_room4() {
    printf("You have entered the Room of Mirrors.\n");
    sleep(1);
    printf("Your reflection starts talking back at you...\n");
    sleep(2);
    printf("It offers to show you your greatest fear.\n");
    sleep(2);
    printf("What will you choose? (1. See it. 2. Refuse)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You confronted your fear and emerged stronger!\n");
    } else {
        printf("You refused, and the reflection shattered, leaving you alone.\n");
    }
}

void enter_room5() {
    printf("You have entered the Attic of Whispers.\n");
    sleep(1);
    printf("The air is thick with the voices of past inhabitants...\n");
    sleep(2);
    printf("A friendly ghost offers you advice on how to escape!\n");
    sleep(2);
    printf("What will you do? (1. Listen. 2. Ignore)\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You listened and learned invaluable secrets to escape the house!\n");
    } else {
        printf("You ignored it and got lost in the attic forever...\n");
    }
}