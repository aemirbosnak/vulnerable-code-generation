//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 150

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Character;

typedef struct {
    char description[MAX_MESSAGE_LENGTH];
    Character ghost;
} Room;

// Function to display the current room
void displayRoom(Room *room) {
    printf("\nYou enter a room that feels cold and foreboding...\n");
    printf("Description: %s\n", room->description);
    printf("A ghostly figure appears: %s\n", room->ghost.name);
    printf("\"%s\"\n", room->ghost.message);
}

// Function to simulate interaction with the ghost
void interactWithGhost(Character *ghost) {
    char choice[MAX_NAME_LENGTH];
    printf("\nDo you dare to respond to the ghost? (yes/no): ");
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0) {
        printf("You gather your courage and respond...\n");
        printf("\"I shall not fear your specter, dear ghost!\"\n");
        printf("The ghost listens, surprised by your bravery!\n");
    } else {
        printf("You turn away, but the ghost's wails haunt your ears...\n");
    }
}

// Main function
int main() {
    Room hauntedHouse[MAX_ROOMS] = {
        {
            "A dimly lit chamber adorned with cobwebs and shadows.",
            {"Juliet's Ghost", "Alas, how the night clings to my sorrow!"}
        },
        {
            "A creaking hallway with eerie portraits that seem to follow you.",
            {"Romeo's Shade", "Oh, wretched fate that keeps us apart!"}
        },
        {
            "An ancient library filled with dusty tomes and flickering candles.",
            {"The Librarian Specter", "Knowledge is but a whisper lost to time."}
        },
        {
            "A dilapidated ballroom where the echoes of dancing once thrived.",
            {"A Forgotten Dancer", "Dance with me, lost soul, ere we fade into dusk."}
        },
        {
            "A secret garden where roses wilt but memories linger.",
            {"The Gardener's Spirit", "Love shall bloom beyond the grave."}
        }
    };

    char playerName[MAX_NAME_LENGTH];
    printf("Enter your name, brave soul: ");
    scanf("%s", playerName);

    printf("\nWelcome, %s, to the Haunted House of Star-Crossed Spirits.\n", playerName);
    
    for (int i = 0; i < MAX_ROOMS; i++) {
        displayRoom(&hauntedHouse[i]);
        interactWithGhost(&hauntedHouse[i].ghost);
        printf("\nPress enter to move to the next room...");
        getchar(); // Consume leftover newline
        getchar(); // Wait for next input
    }

    printf("\nAlas, you have traversed the haunted house and faced its ghosts.\n");
    printf("May the spirits of love and loss guide you through the night.\n");
    return 0;
}