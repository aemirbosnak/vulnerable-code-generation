//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ROOMS 3

typedef struct {
    char name[50];
    int scare_level;
    void (*func)(void);
} Room;

void room1(void) {
    printf("You entered Room 1: The Creaking Room\n");
    printf("The floor creaks under your feet as you enter. Suddenly, you hear a loud bang!\n");
    printf("You jump in fear, but there's nothing there. You take a deep breath and continue.\n");
}

void room2(void) {
    printf("You entered Room 2: The Doll Room\n");
    printf("The room is filled with antique dolls that seem to watch you with their lifeless eyes. Suddenly, you hear a soft 'Hello' from behind you.\n");
    printf("You turn around, but there's nothing there. You start to feel uneasy and leave the room quickly.\n");
}

void room3(void) {
    printf("You entered Room 3: The Dark Room\n");
    printf("The room is pitch black. You can't see a thing. Suddenly, you hear a low growl from the darkness.\n");
    printf("You try to leave, but your legs won't move. You're trapped in the darkness. Just when you think you can't take it anymore, a hand touches your shoulder.\n");
    printf("You scream and run out of the room, your heart pounding in your chest.\n");
}

void haunted_house(int current_room) {
    Room rooms[NUM_ROOMS] = {{"The Creaking Room", 5, room1}, {"The Doll Room", 7, room2}, {"The Dark Room", 10, room3}};
    int input;

    while (1) {
        printf("Current Room: %s\n", rooms[current_room].name);
        printf("Press 1 to enter the next room, or 0 to exit the haunted house\n");
        scanf("%d", &input);

        if (input == 1) {
            current_room = (current_room + 1) % NUM_ROOMS;
            rooms[current_room].func();
        } else {
            printf("Exiting haunted house...\n");
            break;
        }
    }
}

int main() {
    int current_room = 0;

    haunted_house(current_room);

    return 0;
}