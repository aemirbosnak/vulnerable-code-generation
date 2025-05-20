//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_EVENTS 3

// Structures for the haunted house
typedef struct {
    char *description;
    char *eventMessages[MAX_EVENTS];
    int eventChance[MAX_EVENTS];
} Room;

typedef struct {
    char *name;
    Room rooms[MAX_ROOMS];
} HauntedHouse;

// Function to initialize a haunted house
void initializeHauntedHouse(HauntedHouse *house) {
    house->name = "Eerie Manor";

    house->rooms[0] = (Room){"The Entrance Hall", 
        {"A shadow flickers past your vision.", 
         "You hear the distant sound of chains.", 
         "The air grows colder."}, 
        {30, 20, 50}};
    
    house->rooms[1] = (Room){"The Library", 
        {"Books fly off the shelves before your eyes.", 
         "A whisper echoes in your ear.", 
         "The lights flicker ominously."}, 
        {40, 30, 10}};
    
    house->rooms[2] = (Room){"The Attic", 
        {"A child’s laughter sends chills down your spine.", 
         "You feel an icy breath on your neck.", 
         "The floor creaks treacherously."}, 
        {35, 45, 20}};
    
    house->rooms[3] = (Room){"The Kitchen", 
        {"An unseen force slams the cupboard doors.", 
         "You smell something rotten.", 
         "A ghostly figure appears and vanishes."}, 
        {50, 20, 30}};
    
    house->rooms[4] = (Room){"The Basement", 
        {"You are engulfed in darkness.", 
         "An eerie moan reverberates around you.", 
         "Suddenly, you feel something brush past you."}, 
        {70, 10, 20}};
}

// Function to get room description
void getRoomDescription(int roomIndex, HauntedHouse *house) {
    printf("You are now in: %s\n", house->rooms[roomIndex].description);
}

// Function to trigger events based on chance
void triggerEvents(int roomIndex, HauntedHouse *house) {
    srand(time(NULL));
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (rand() % 100 < house->rooms[roomIndex].eventChance[i]) {
            printf("Event: %s\n", house->rooms[roomIndex].eventMessages[i]);
        }
    }
}

// Main function
int main() {
    HauntedHouse house;
    initializeHauntedHouse(&house);
    
    int roomIndex = 0;
    char continueChoice;
    
    printf("Welcome to the %s!\n", house.name);
    
    do {
        getRoomDescription(roomIndex, &house);
        triggerEvents(roomIndex, &house);
        
        // Room navigation
        if (roomIndex < MAX_ROOMS - 1) {
            printf("You can move to the next room. (Y/N): ");
        } else {
            printf("You are at the last room. (Y/N): ");
        }

        scanf(" %c", &continueChoice);
        if (continueChoice == 'Y' || continueChoice == 'y') {
            roomIndex++;
        }
        
    } while (roomIndex < MAX_ROOMS && (continueChoice == 'Y' || continueChoice == 'y'));
    
    printf("Thank you for exploring %s! We hope you enjoyed the thrills!\n", house.name);
    return 0;
}