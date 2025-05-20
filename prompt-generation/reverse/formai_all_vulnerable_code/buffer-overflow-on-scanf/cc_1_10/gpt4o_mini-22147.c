//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DARKNESS 5
#define MAX_ROOMS 3

typedef struct {
    char *description;
    int darknessLevel;
    int hasGhost;
} Room;

Room rooms[MAX_ROOMS];

void initializeRooms() {
    rooms[0].description = "You enter a dimly lit hallway, the air here is thick with dust and an unsettling silence looms.";
    rooms[0].darknessLevel = 2;
    rooms[0].hasGhost = 1;

    rooms[1].description = "The room is filled with cobwebs, and the shadows seem to dance menacingly at the edges of your vision.";
    rooms[1].darknessLevel = 4;
    rooms[1].hasGhost = 0;

    rooms[2].description = "You find yourself in an eerie library, the tomes whisper secrets that are better left unheard.";
    rooms[2].darknessLevel = 3;
    rooms[2].hasGhost = 1;
}

void displayRoom(int roomIndex) {
    printf("\n--- Room %d ---\n", roomIndex + 1);
    printf("%s\n", rooms[roomIndex].description);
    printf("Darkness Level: %d\n", rooms[roomIndex].darknessLevel);
    if (rooms[roomIndex].hasGhost) {
        printf("A ghost is lurking in this room! Beware...\n");
    }
}

char* getUserChoice() {
    char *choice = (char *)malloc(10 * sizeof(char));
    printf("Would you like to (explore/exit)? ");
    scanf("%s", choice);
    return choice;
}

int main() {
    int currentRoom = 0;
    char *userChoice = NULL;

    printf("Welcome to the Haunted House Simulator!\n");
    sleep(1);
    initializeRooms();

    while (1) {
        displayRoom(currentRoom);
        
        userChoice = getUserChoice();
        
        if (strcmp(userChoice, "explore") == 0) {
            if (currentRoom < MAX_ROOMS - 1) {
                currentRoom++;
                printf("You bravely move to the next room...\n");
            } else {
                printf("There's no more rooms to explore! You're back at the beginning.\n");
                currentRoom = 0;
            }
        }
        else if (strcmp(userChoice, "exit") == 0) {
            printf("You have exited the haunted house. Your adventure ends here. Goodbye!\n");
            free(userChoice);
            break;
        } 
        else {
            printf("Invalid choice! Try again!\n");
        }
        
        free(userChoice);
        sleep(1);
    }
    
    return 0;
}