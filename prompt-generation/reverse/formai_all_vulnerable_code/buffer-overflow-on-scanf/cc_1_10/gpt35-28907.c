//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROOM_COUNT 6
#define GHOST_ROOM_INDEX 3

void printRooms(int currentRoom, bool visitedRooms[]);
int move(char direction, int currentRoom, bool visitedRooms[]);
bool isGameOver(int currentRoom, int steps);
void printGameOver(int currentRoom, int steps);

int main() {
    bool visitedRooms[ROOM_COUNT] = {false};
    int currentRoom = 0;
    int steps = 0;
    char direction;

    printf("Welcome to the Haunted House Simulator!\n\n");
    printRooms(currentRoom, visitedRooms);

    do {
        printf("Enter your move (n, s, e, w): ");
        scanf(" %c", &direction);
        printf("\n");

        int nextRoom = move(direction, currentRoom, visitedRooms);
        if (nextRoom == -1) {
            printf("Invalid move.\n");
        } else {
            currentRoom = nextRoom;
            steps++;
            printRooms(currentRoom, visitedRooms);
        }
    } while (!isGameOver(currentRoom, steps));

    printGameOver(currentRoom, steps);

    return 0;
}

void printRooms(int currentRoom, bool visitedRooms[]) {
    system("clear");
    printf("Haunted House Simulator\n\n");
    printf("You are in room #%d.\n", currentRoom + 1);

    if (visitedRooms[GHOST_ROOM_INDEX]) {
        printf("There is a ghost in this room!\n");
    }

    printf("\n");

    printf("        |    %c----%c\n", visitedRooms[1] ? ' ' : 'x', visitedRooms[2] ? ' ' : 'x');
    printf("        |    |\n");
    printf("        |    %c\n", visitedRooms[3] ? ' ' : 'x');
    printf("        |    |\n");
    printf("        %c----%c    %c----%c\n", visitedRooms[0] ? ' ' : 'x', visitedRooms[4] ? ' ' : 'x', visitedRooms[5] ? ' ' : 'x', visitedRooms[6] ? ' ' : 'x');
    printf("        |         |\n");
    printf("        |         %c\n", visitedRooms[7] ? ' ' : 'x');
    printf("        |         |\n");
    printf("        %c----%c----%c\n\n", visitedRooms[8] ? ' ' : 'x', visitedRooms[9] ? ' ' : 'x', visitedRooms[10] ? ' ' : 'x');
}

int move(char direction, int currentRoom, bool visitedRooms[]) {
    int nextRoom = currentRoom;
    switch (direction) {
        case 'n':
            if (currentRoom >= 2 && currentRoom < 5) {
                nextRoom = currentRoom - 2;
            }
            break;
        case 's':
            if (currentRoom < 3) {
                nextRoom = currentRoom + 2;
            }
            break;
        case 'e':
            if (currentRoom % 2 == 0 && currentRoom < 10) {
                nextRoom = currentRoom + 1;
            }
            break;
        case 'w':
            if (currentRoom % 2 == 1 && currentRoom > 0) {
                nextRoom = currentRoom - 1;
            }
            break;
        default:
            return -1;
    }

    visitedRooms[currentRoom] = true;

    if (nextRoom == GHOST_ROOM_INDEX) {
        printf("You have encountered a ghost in room #%d!\n", GHOST_ROOM_INDEX + 1);
        srand(time(NULL));
        bool ghostChase = (bool)(rand() % 2);
        if (ghostChase) {
            printf("The ghost is chasing you!\n");
            int newPos = rand() % ROOM_COUNT;
            while (newPos == GHOST_ROOM_INDEX || newPos == currentRoom) {
                newPos = rand() % ROOM_COUNT;
            }
            printf("You are now in room #%d\n", newPos + 1);
            return newPos;
        } else {
            printf("The ghost has left you alone. You may continue.\n");
        }
    }

    return nextRoom;
}

bool isGameOver(int currentRoom, int steps) {
    if (currentRoom == GHOST_ROOM_INDEX || steps >= 30) {
        return true;
    }
    return false;
}

void printGameOver(int currentRoom, int steps) {
    system("clear");
    printf("Haunted House Simulator\n\n");
    if (currentRoom == GHOST_ROOM_INDEX) {
        printf("Game over! The ghost caught you!\n");
    } else {
        printf("Game over! You made it out alive!\n");
    }
    printf("You took %d steps.\n\n", steps);
}