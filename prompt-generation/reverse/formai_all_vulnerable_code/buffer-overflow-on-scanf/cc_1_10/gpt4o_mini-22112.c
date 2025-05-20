//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct {
    char *name;
    char *description;
} Room;

typedef struct {
    char *name;
    char *fearFactor;
} Monster;

Room rooms[MAX_ROOMS];
Monster monsters[MAX_MONSTERS];

void initializeRooms() {
    rooms[0].name = "Library of Shadows";
    rooms[0].description = "A dimly lit library filled with dusty old books and eerie shadows.";
    
    rooms[1].name = "Hall of Whispers";
    rooms[1].description = "A long hall where you hear faint whispers echoing off the walls.";
    
    rooms[2].name = "Creepy Kitchen";
    rooms[2].description = "An abandoned kitchen where the smell of rotting food lingers.";
    
    rooms[3].name = "Basement of Despair";
    rooms[3].description = "A dark basement that feels colder the deeper you go.";
    
    rooms[4].name = "Attic of Secrets";
    rooms[4].description = "An attic filled with forgotten items and a mysterious presence.";
    
    rooms[5].name = "The Haunted Bathroom";
    rooms[5].description = "A bathroom with flickering lights and a sense of dread in the air.";
    
    rooms[6].name = "Phantom Garden";
    rooms[6].description = "An overgrown garden where ghostly apparitions appear under the moonlight.";
    
    rooms[7].name = "Cellar of Echoes";
    rooms[7].description = "A dark cellar where you can hear the echoes of past occupants.";
    
    rooms[8].name = "Crypt of the Forgotten";
    rooms[8].description = "A small crypt filled with inscriptions of those long gone.";
    
    rooms[9].name = "Room of Relics";
    rooms[9].description = "A room filled with ancient relics, each holding its own story.";
}

void initializeMonsters() {
    monsters[0].name = "The Phantom";
    monsters[0].fearFactor = "Very High";
    
    monsters[1].name = "Wailing Spirit";
    monsters[1].fearFactor = "High";
    
    monsters[2].name = "Creepy Doll";
    monsters[2].fearFactor = "Moderate";
    
    monsters[3].name = "Vengeful Ghost";
    monsters[3].fearFactor = "High";
    
    monsters[4].name = "Zombie Butler";
    monsters[4].fearFactor = "Low";
}

void enterRoom(int roomIndex) {
    if (roomIndex < 0 || roomIndex >= MAX_ROOMS) {
        printf("Invalid room!\n");
        return;
    }

    printf("You have entered: %s\n", rooms[roomIndex].name);
    printf("%s\n", rooms[roomIndex].description);
    
    // Let's make things spooky by introducing a random monster
    int randomMonster = rand() % MAX_MONSTERS;
    printf("A %s appears! Fear factor: %s\n", monsters[randomMonster].name, monsters[randomMonster].fearFactor);
    
    // Random events in the room
    int event = rand() % 2;
    if (event == 0) {
        printf("You feel a chill run down your spine.\n");
    } else {
        printf("You hear a loud banging noise nearby.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    initializeRooms();
    initializeMonsters();

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Choose a room to enter (0-%d):\n", MAX_ROOMS - 1);
    
    int choice;
    scanf("%d", &choice);

    enterRoom(choice);
    
    printf("Do you dare to explore more? (1 for yes, 0 for no): ");
    int choiceToContinue;
    scanf("%d", &choiceToContinue);
    
    while (choiceToContinue != 0) {
        printf("Choose another room to enter (0-%d):\n", MAX_ROOMS - 1);
        scanf("%d", &choice);
        enterRoom(choice);
        
        printf("Do you dare to explore more? (1 for yes, 0 for no): ");
        scanf("%d", &choiceToContinue);
    }

    printf("You have left the haunted house. Thanks for playing!\n");
    return 0;
}