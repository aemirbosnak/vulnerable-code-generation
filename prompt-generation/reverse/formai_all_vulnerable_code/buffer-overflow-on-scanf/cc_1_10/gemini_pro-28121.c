//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_EXITS 4

typedef struct {
    char* name;
    char* description;
    int exits[MAX_EXITS];
} Room;

Room rooms[MAX_ROOMS];
int numRooms = 0;

void addRoom(char* name, char* description, int* exits) {
    rooms[numRooms].name = strdup(name);
    rooms[numRooms].description = strdup(description);
    for (int i = 0; i < MAX_EXITS; i++) {
        rooms[numRooms].exits[i] = exits[i];
    }
    numRooms++;
}

void printRoom(int roomIndex) {
    printf("%s\n", rooms[roomIndex].name);
    printf("%s\n", rooms[roomIndex].description);
    printf("Exits:\n");
    for (int i = 0; i < MAX_EXITS; i++) {
        if (rooms[roomIndex].exits[i] != -1) {
            printf("  %d. %s\n", i + 1, rooms[rooms[roomIndex].exits[i]].name);
        }
    }
}

int main() {
    int currentRoom = 0;
    while (1) {
        printRoom(currentRoom);
        printf("Which direction do you want to go? (1-4, or 0 to quit)\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        if (choice < 1 || choice > MAX_EXITS || rooms[currentRoom].exits[choice - 1] == -1) {
            printf("Invalid choice.\n");
        } else {
            currentRoom = rooms[currentRoom].exits[choice - 1];
        }
    }
    return 0;
}