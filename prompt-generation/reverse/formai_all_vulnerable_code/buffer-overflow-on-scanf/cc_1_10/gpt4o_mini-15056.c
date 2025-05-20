//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 50

void display_intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a dark and eerie house.\n");
    printf("Will you dare to enter and explore its mysteries?\n");
}

void enter_room(int room) {
    switch(room) {
        case 1:
            printf("You enter the living room. It's dark and you can hear a faint whisper...\n");
            break;
        case 2:
            printf("You find yourself in the kitchen. There are strange sounds coming from the fridge...\n");
            break;
        case 3:
            printf("You step into the basement. The air is thick and cold, and you feel a presence watching you...\n");
            break;
        case 4:
            printf("You approached the attic. Old toys and furniture are scattered everywhere.\n");
            break;
        case 5:
            printf("You accidentally stepped into a secret passage. It leads to a hidden crypt!\n");
            break;
        default:
            printf("You are lost in an endless maze of haunted rooms...\n");
            break;
    }
}

int get_random_event() {
    return rand() % 5 + 1;
}

void encounter_event() {
    int event = get_random_event();
    switch(event) {
        case 1:
            printf("A ghost suddenly appears! Do you want to run (r) or confront it (c)? ");
            break;
        case 2:
            printf("A creepy doll starts to move on its own! Do you want to investigate (i) or flee (f)? ");
            break;
        case 3:
            printf("You hear laughter echoing through the hall. Do you want to follow the sound (f) or hide (h)? ");
            break;
        case 4:
            printf("The lights flicker and go out. Do you want to feel your way through (f) or stay still (s)? ");
            break;
        case 5:
            printf("You find a cursed object! Do you want to touch it (t) or leave it alone (l)? ");
            break;
    }
}

void make_choice(char choice) {
    switch(choice) {
        case 'r':
            printf("You ran away and escaped the ghost!\n");
            break;
        case 'c':
            printf("You confronted the ghost and it vanished into thin air!\n");
            break;
        case 'i':
            printf("You investigated the doll and it turned into a harmless toy.\n");
            break;
        case 'f':
            printf("You decided to flee, but you tripped and fell!\n");
            break;
        case 'h':
            printf("You hid in a corner and the laughter faded away.\n");
            break;
        case 's':
            printf("You stood still and the lights returned. You're safe for now.\n");
            break;
        case 't':
            printf("You touched the cursed object and it turned into a treasure!\n");
            break;
        case 'l':
            printf("You wisely left it alone. It may have been cursed!\n");
            break;
        default:
            printf("That's not a valid choice! The haunted house consumes you...\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    char choice;
    int room;

    display_intro();
    
    while (1) {
        printf("\nChoose a room to enter (1-5) or 0 to exit: ");
        scanf("%d", &room);

        if (room == 0) {
            printf("You decided to leave the haunted house. Good choice!\n");
            break;
        }

        enter_room(room);
        encounter_event();

        // Read player's choice
        scanf(" %c", &choice);
        make_choice(choice);

        printf("\nWould you like to continue exploring? (y/n): ");
        char continue_choice;
        scanf(" %c", &continue_choice);
        if (continue_choice == 'n') {
            printf("You chose to leave the haunted house. Till next time!\n");
            break;
        }
    }

    return 0;
}