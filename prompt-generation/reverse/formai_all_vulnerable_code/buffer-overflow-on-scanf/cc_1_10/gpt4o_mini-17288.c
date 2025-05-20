//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction() {
    printf("Welcome to the Mind-Bending Adventure!\n");
    printf("You find yourself standing in a void, surrounded by swirling colors.\n");
    printf("In front of you, there are three doors marked A, B, and C.\n");
    printf("Choose a door to begin your journey...\n");
}

void doorA() {
    printf("You open door A and step inside.\n");
    printf("You are in a room full of mirrors, each reflecting a different version of yourself.\n");
    printf("Do you want to:\n");
    printf("1. Approach the mirror on the left\n");
    printf("2. Approach the mirror in the center\n");
    printf("3. Approach the mirror on the right\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You see a version of yourself without a shadow. It smiles at you.\n");
            printf("You feel a strange connection...\n");
            break;
        case 2:
            printf("The mirror shows you a future where you've accomplished your greatest fears.\n");
            printf("Do you dare to step through?\n");
            break;
        case 3:
            printf("The mirror is cracked and you can hear whispers.\n");
            printf("You feel compelled to listen closer...\n");
            break;
        default:
            printf("You hesitate and the mirrors shatter, leaving you in darkness.\n");
            break;
    }
}

void doorB() {
    printf("You open door B and find yourself in a library.\n");
    printf("Books float in the air, pulsing with light.\n");
    printf("Do you wish to:\n");
    printf("1. Read a book on the left shelf\n");
    printf("2. Read a book on the right shelf\n");
    printf("3. Try to grab a floating book\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The book tells you the secrets of time travel!\n");
            printf("You can now travel back to any moment in your life...\n");
            break;
        case 2:
            printf("Reading this book reveals hidden truths about the universe.\n");
            printf("Knowledge comes at a cost; you feel a year of your life slip away.\n");
            break;
        case 3:
            printf("You grab a book and it opens a portal to another world!\n");
            printf("You are sucked into a realm filled with bizarre creatures...\n");
            break;
        default:
            printf("The library implodes, and you are left falling through reality.\n");
            break;
    }
}

void doorC() {
    printf("You open door C and are met by a vast ocean of clouds.\n");
    printf("You see a ship sailing made of stars.\n");
    printf("Will you:\n");
    printf("1. Board the ship\n");
    printf("2. Dive into the clouds\n");
    printf("3. Build a castle out of the clouds\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The ship takes you to the Sky Kingdom, where songs of the stars echo.\n");
            printf("You learn to speak with celestial beings.\n");
            break;
        case 2:
            printf("Diving into the clouds transports you into your subconscious.\n");
            printf("You must face your inner demons...\n");
            break;
        case 3:
            printf("You create a magnificent castle, but it draws the attention of a storm.\n");
            printf("You must defend your creation!\n");
            break;
        default:
            printf("The clouds swirl and you are lost in a tornado of thoughts.\n");
            break;
    }
}

int main() {
    introduction();

    char door[2];
    
    while (1) {
        printf("Which door do you choose (A, B, C)? ");
        scanf("%1s", door);
        
        if (strcmp(door, "A") == 0) {
            doorA();
        } else if (strcmp(door, "B") == 0) {
            doorB();
        } else if (strcmp(door, "C") == 0) {
            doorC();
        } else {
            printf("That's not a valid door. Please choose A, B, or C.\n");
        }
        
        printf("Do you want to choose another door? (y/n): ");
        char again;
        scanf(" %c", &again);
        if (again != 'y') break;
    }

    printf("Thank you for playing! Your mind will never be the same.\n");
    return 0;
}