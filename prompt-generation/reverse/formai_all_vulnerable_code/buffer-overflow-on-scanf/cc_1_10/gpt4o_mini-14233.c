//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

void welcomeMessage(char *name1, char *name2) {
    printf("Welcome, %s and %s, to the Haunted Love House!\n", name1, name2);
    printf("Prepare yourselves for an adventure that weaves romance with mystery...\n\n");
}

void ghostEncounter() {
    printf("You encounter a whimsical ghost who whispers secrets of love!\n");
    printf("It wants to know: What do you value more in your relationship?\n");
    printf("1. Trust\n2. Laughter\n3. Passion\nChoose wisely: ");
}

void trustResponse() {
    printf("The ghost nods approvingly and conjures a beautiful heart-shaped glowing locket.\n");
    printf("It grants you the power of unwavering trust in one another!\n\n");
}

void laughterResponse() {
    printf("The ghost laughs heartily and fills the room with echoes of joy and laughter.\n");
    printf("You feel lighter, your bond growing stronger with every chuckle!\n\n");
}

void passionResponse() {
    printf("The ghost dances around you, igniting sparks of passion with each twirl.\n");
    printf("You both feel an overwhelming surge of love and desire!\n\n");
}

void eerieChoice() {
    printf("You stand at a fork in the hallway, illuminated by flickering candles.\n");
    printf("Do you wish to proceed towards the:\n");
    printf("1. The Library of Lost Love Letters\n2. The Chamber of Echoing Heartbeats\nChoose: ");
}

void libraryScene() {
    printf("In the library, you find shelves filled with love letters from centuries past.\n");
    printf("You select a letter and read it aloud. It speaks of a love that endured through time.\n");
    printf("You feel inspired by the words and decide to write your own love letters to each other.\n\n");
}

void chamberScene() {
    printf("In this chamber, you can hear the heartbeats of lovers that once roamed these halls.\n");
    printf("As you listen closely, you realize your heartbeats sync perfectly together.\n");
    printf("It's a beautiful moment where silence speaks louder than words.\n\n");
}

void finalChoice() {
    printf("As your adventure nears its end, the ghost remains, smiling.\n");
    printf("It offers you a final choice: Do you take a road of:\n");
    printf("1. Eternal Memories\n2. Unwritten Futures\nChoose: ");
}

void memoriesResponse() {
    printf("You choose to cherish the memories, and the ghost presents you with a photo album.\n");
    printf("The album is filled with magical snapshots of your time together in the haunted house.\n");
    printf("With each page turned, your love grows richer and deeper.\n");
}

void futuresResponse() {
    printf("You opt for unwritten futures, bringing a sense of adventure and excitement.\n");
    printf("The ghost gifts you a quill and a blank book to write your own love story.\n");
    printf("Together, you create a narrative filled with dreams of what is yet to come.\n");
}

int main() {
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];
    int choice;

    // Random seed
    srand(time(0));

    // Collect names
    printf("Enter the name of the first lover: ");
    fgets(name1, MAX_NAME_LENGTH, stdin);
    strtok(name1, "\n"); // Remove newline character

    printf("Enter the name of the second lover: ");
    fgets(name2, MAX_NAME_LENGTH, stdin);
    strtok(name2, "\n"); // Remove newline character

    welcomeMessage(name1, name2);

    ghostEncounter();
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            trustResponse();
            break;
        case 2:
            laughterResponse();
            break;
        case 3:
            passionResponse();
            break;
        default:
            printf("Invalid choice, your love is now lost in the shadows!\n");
            return 1;
    }

    eerieChoice();
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            libraryScene();
            break;
        case 2:
            chamberScene();
            break;
        default:
            printf("Your indecision leads to an eternal silence...\n");
            return 1;
    }

    finalChoice();
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            memoriesResponse();
            break;
        case 2:
            futuresResponse();
            break;
        default:
            printf("You have strayed into darkness...\n");
            return 1;
    }

    printf("Thank you for visiting the Haunted Love House. Your love story will continue!\n");
    return 0;
}