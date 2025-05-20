//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_ENCOUNTERS 3

typedef struct {
    char name[50];
    char description[200];
    char encounter[MAX_ENCOUNTERS][100];
} Room;

void initializeRooms(Room rooms[]) {
    // Room 1
    snprintf(rooms[0].name, sizeof(rooms[0].name), "The Dark Hallway");
    snprintf(rooms[0].description, sizeof(rooms[0].description), 
             "A long hallway with flickering lights. You feel a chill run down your spine.");
    snprintf(rooms[0].encounter[0], sizeof(rooms[0].encounter[0]), 
             "A ghost appears and whispers your name!");
    snprintf(rooms[0].encounter[1], sizeof(rooms[0].encounter[1]), 
             "You hear footsteps behind you, but no one is there.");
    snprintf(rooms[0].encounter[2], sizeof(rooms[0].encounter[2]), 
             "A door suddenly slams shut, trapping you!");

    // Room 2
    snprintf(rooms[1].name, sizeof(rooms[1].name), "The Abandoned Kitchen");
    snprintf(rooms[1].description, sizeof(rooms[1].description), 
             "Old pots and pans lie scattered on the floor. A rotten smell fills the air.");
    snprintf(rooms[1].encounter[0], sizeof(rooms[1].encounter[0]), 
             "You see a shadowy figure cooking an unseen meal.");
    snprintf(rooms[1].encounter[1], sizeof(rooms[1].encounter[1]), 
             "The refrigerator door creaks open by itself, revealing a dark void.");
    snprintf(rooms[1].encounter[2], sizeof(rooms[1].encounter[2]), 
             "A knife flies off the counter and narrowly misses you!");

    // Room 3
    snprintf(rooms[2].name, sizeof(rooms[2].name), "The Creepy Attic");
    snprintf(rooms[2].description, sizeof(rooms[2].description), 
             "Cobwebs fill every corner. You can hear the scurrying of unseen creatures.");
    snprintf(rooms[2].encounter[0], sizeof(rooms[2].encounter[0]), 
             "A pair of glowing eyes peer at you from the shadows.");
    snprintf(rooms[2].encounter[1], sizeof(rooms[2].encounter[1]), 
             "Old toys begin to move on their own, playing with a non-existent child.");
    snprintf(rooms[2].encounter[2], sizeof(rooms[2].encounter[2]), 
             "You suddenly feel an icy breath on your neck!");

    // Room 4
    snprintf(rooms[3].name, sizeof(rooms[3].name), "The Mysterious Basement");
    snprintf(rooms[3].description, sizeof(rooms[3].description), 
             "It's dark and damp. The air feels heavy and oppressive.");
    snprintf(rooms[3].encounter[0], sizeof(rooms[3].encounter[0]), 
             "You hear a distant crying, but there's no one in sight.");
    snprintf(rooms[3].encounter[1], sizeof(rooms[3].encounter[1]), 
             "A ghostly hand reaches out from the shadows towards you.");
    snprintf(rooms[3].encounter[2], sizeof(rooms[3].encounter[2]), 
             "Suddenly, the walls begin to close in on you!");

    // Room 5
    snprintf(rooms[4].name, sizeof(rooms[4].name), "The Haunted Library");
    snprintf(rooms[4].description, sizeof(rooms[4].description), 
             "Bookshelves tower overhead. Whispers of secrets float in the air.");
    snprintf(rooms[4].encounter[0], sizeof(rooms[4].encounter[0]), 
             "A book falls off the shelf, opening to a page about ghostly rituals.");
    snprintf(rooms[4].encounter[1], sizeof(rooms[4].encounter[1]), 
             "The lights flicker and you see a phantom librarian staring at you.");
    snprintf(rooms[4].encounter[2], sizeof(rooms[4].encounter[2]), 
             "The books begin to whisper your name in unison!");
}

void exploreRoom(Room room) {
    printf("\nYou have entered: %s\n", room.name);
    printf("%s\n", room.description);
    printf("What will you do?\n");
    printf("1. Investigate\n");
    printf("2. Leave the room\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        int encounterIndex = rand() % MAX_ENCOUNTERS;
        printf("Encounter: %s\n", room.encounter[encounterIndex]);
    } else {
        printf("You decide to leave the room...\n");
    }
}

int main() {
    srand(time(NULL));
    
    Room rooms[MAX_ROOMS];
    initializeRooms(rooms);
    
    int continueExploring = 1;
    
    while (continueExploring) {
        printf("\nWelcome to the Haunted House Simulator!\n");
        printf("You have %d rooms to explore:\n", MAX_ROOMS);
        for (int i = 0; i < MAX_ROOMS; i++) {
            printf("%d. %s\n", i + 1, rooms[i].name);
        }
        
        int roomChoice;
        printf("Which room would you like to explore? (1-%d): ", MAX_ROOMS);
        scanf("%d", &roomChoice);
        
        if (roomChoice < 1 || roomChoice > MAX_ROOMS) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        exploreRoom(rooms[roomChoice - 1]);

        printf("\nWould you like to explore another room? (1 for Yes, 0 for No): ");
        scanf("%d", &continueExploring);
    }

    printf("Thanks for playing the Haunted House Simulator!\n");
    
    return 0;
}