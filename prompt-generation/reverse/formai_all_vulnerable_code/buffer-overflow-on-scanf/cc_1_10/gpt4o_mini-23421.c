//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHOICES 3
#define MAX_ROOM_DESC 256

const char* rooms[] = {
    "the gloomy foyer, where shadows dance upon the walls",
    "the dimly lit library, replete with ancient tomes and whispers",
    "the eerie dining hall, adorned with cobwebs and a long forgotten feast",
    "the haunted attic, filled with dust and forgotten memories",
    "the mysterious cellar, echoing with the sound of dripping water",
};

const char* interactions[][MAX_CHOICES] = {
    {"Inspect the portraits", "Open the dusty cabinet", "Flee to the gardens"},
    {"Read a book", "Listen carefully for whispers", "Leave quickly"},
    {"Examine the table", "Discover a hidden passage", "Ignore and leave"},
    {"Search for lost items", "Find a way out", "Retreat in terror"},
    {"Look for treasure", "Search for a hidden exit", "Sit in despair"},
};

const char* endings[] = {
    "You felt the chill of sorrow as you discovered the truth. Forever remain haunted.",
    "A ghostly figure shimmered before you, revealing hidden secrets and lost love.",
    "In your desperate flight, you awakened the spirits of the house and too, became one with them.",
};

void printRoomDescription(int roomIndex) {
    printf("You enter %s.\n", rooms[roomIndex]);
    printf("What shall you do, brave wanderer of shadows?\n");
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%d: %s\n", i+1, interactions[roomIndex][i]);
    }
}

int main() {
    int currentRoom = 0;
    int choice;
    srand(time(NULL));

    printf("In fair Verona, where we lay our scene, the haunted mansion stands tall.\n");
    printf("As you approach, a sense of foreboding envelops you like a shroud.\n");

    while (currentRoom < sizeof(rooms) / sizeof(rooms[0])) {
        printRoomDescription(currentRoom);
        
        printf("Enter your choice (1-%d): ", MAX_CHOICES);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > MAX_CHOICES) {
            printf("Alas, thou hath waned in resolve! A ghost shall choose for thee.\n");
            choice = (rand() % MAX_CHOICES) + 1;
        } else {
            printf("Thou hast chosen: %s.\n", interactions[currentRoom][choice - 1]);
        }

        if (strcmp(interactions[currentRoom][choice - 1], "Flee to the gardens") == 0) {
            printf("Hark! Thou retreatest from the spirits, but they follow with sorrow.\n");
            break;
        } else if (strcmp(interactions[currentRoom][choice - 1], "Discover a hidden passage") == 0) {
            printf("A secret door unveils itself, leading you deeper into the heart of the mansion.\n");
            currentRoom++;
        } else if (strcmp(interactions[currentRoom][choice - 1], "Search for lost items") == 0) {
            printf("Thine heart cries for the lost; a treasure awaits, but a shadow looms.\n");
            break;
        } else {
            printf("Of thy undertakings, none linger, and the specters grow restless.\n");
            currentRoom++;
        }
    }
    
    printf("As the fates would weave it, thou hast met thy end. ");
    printf("%s\n", endings[rand() % (sizeof(endings) / sizeof(endings[0]))]);

    return 0;
}