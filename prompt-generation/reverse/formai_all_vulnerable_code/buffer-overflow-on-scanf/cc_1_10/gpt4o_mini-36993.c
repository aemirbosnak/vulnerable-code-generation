//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_ROOMS 5
#define MAX_CHAIRS 3

typedef struct {
    int id;
    const char *description;
    const char *hauntingEvent;
} Room;

typedef struct {
    const char *name;
    int scareLevel;
} Chair;

Room rooms[MAX_ROOMS];
Chair chairs[MAX_CHAIRS];

void initializeRooms() {
    rooms[0] = (Room){0, "A dimly lit hallway with peeling wallpaper.", "A ghost whispers your name."};
    rooms[1] = (Room){1, "An old library filled with dusty books.", "Books start to fall off the shelves."};
    rooms[2] = (Room){2, "A dilapidated kitchen with abandoned dishes.", "The oven door swings open by itself."};
    rooms[3] = (Room){3, "A musty cellar with cobwebs everywhere.", "A chill runs down your spine."};
    rooms[4] = (Room){4, "The attics filled with forgotten toys.", "Toys begin to giggle ominously."};
}

void initializeChairs() {
    chairs[0] = (Chair){"Wooden Chair", 1};
    chairs[1] = (Chair){"Rocking Chair", 2};
    chairs[2] = (Chair){"Throne of Bones", 3};
}

void createHaunting(int roomId) {
    printf("%s\n", rooms[roomId].description);
    printf("Suddenly... %s\n", rooms[roomId].hauntingEvent);
    sleep(2);
}

void encounterChair(int scareLevel) {
    printf("You see a %s in the room. ", chairs[scareLevel].name);
    printf("It seems oddly inviting...\n");
    sleep(2);
    printf("You sit down cautiously...\n");
    sleep(2);
    if (scareLevel == 2) {
        printf("The chair begins rocking on its own!\n");
    } else if (scareLevel == 1) {
        printf("A dark shadow creeps closer!\n");
    } else {
        printf("You feel the weight of countless eyes upon you!\n");
    }
    sleep(3);
}

void playGame() {
    int roomId, chairChoice;

    srand(time(NULL));
    roomId = rand() % MAX_ROOMS;

    createHaunting(roomId);
    
    printf("\nWhat will you do next? Choose a chair to sit on (0 for Wooden Chair, 1 for Rocking Chair, 2 for Throne of Bones): ");
    scanf("%d", &chairChoice);

    if (chairChoice < 0 || chairChoice >= MAX_CHAIRS) {
        printf("Invalid choice! You flee back into the dark!\n");
        return;
    }

    encounterChair(chairChoice);
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    initializeRooms();
    initializeChairs();
    
    char playAgain;

    do {
        playGame();
        printf("\nDo you dare to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! May the spirits watch over you...\n");
    return 0;
}