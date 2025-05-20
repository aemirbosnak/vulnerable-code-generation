//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ROOM_NUMBER 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    char description[100];
    int scareLevel;
} Room;

Person romeo, juliet;
Room hauntedRooms[MAX_ROOM_NUMBER];

void printRoomDescription(Room room) {
    printf("\n%s\n", room.description);
}

void enterRoom(int roomNumber) {
    Room currentRoom = hauntedRooms[roomNumber];
    int romeoScareLevel = romeo.age > 25 ? 2 : 1;
    int julietScareLevel = juliet.age > 25 ? 2 : 1;

    int totalScareLevel = currentRoom.scareLevel + romeoScareLevel + julietScareLevel;

    printRoomDescription(currentRoom);

    if (totalScareLevel > 5) {
        printf("You both screamed and ran away from the haunted house.\n");
        exit(0);
    }
}

void setup() {
    strcpy(romeo.name, "Romeo Montague");
    romeo.age = 23;

    strcpy(juliet.name, "Juliet Capulet");
    juliet.age = 18;

    int i;
    for (i = 0; i < MAX_ROOM_NUMBER; i++) {
        sprintf(hauntedRooms[i].description, "Room %d: A %s%s room with %s and %s.\n", i + 1,
                i % 2 == 0 ? "creaking" : "whispering", i % 2 == 0 ? "doors" : "walls",
                i % 3 == 0 ? "echoing footsteps" : "flickering lanterns",
                i % 4 == 0 ? "ghostly whispers" : "strange odors");
        hauntedRooms[i].scareLevel = i % 5 == 0 ? 5 : 3;
    }
}

int main() {
    setup();

    int choice;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Romeo (%.2d years old) and Juliet (%.2d years old) have dared to enter the haunted house together.\n",
           romeo.age, juliet.age);

    while (1) {
        printf("\nPlease enter the number of the room you would like to enter (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Goodbye, Romeo and Juliet.\n");
            break;
        }

        enterRoom(choice - 1);
    }

    return 0;
}