//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NAME_LEN 30
#define MAX_ROOM_DESCRIPTION_LEN 100
#define MAX_ROOM_EXIT_LEN 10

// Define the number of rooms
#define NUM_ROOMS 4

// Define the number of exits for each room
#define ROOM_1_EXITS 2
#define ROOM_2_EXITS 1
#define ROOM_3_EXITS 1
#define ROOM_4_EXITS 1

// Define the exits for each room
char room_1_exits[ROOM_1_EXITS][MAX_ROOM_EXIT_LEN] = {"North", "South"};
char room_2_exits[ROOM_2_EXITS][MAX_ROOM_EXIT_LEN] = {"West"};
char room_3_exits[ROOM_3_EXITS][MAX_ROOM_EXIT_LEN] = {"East"};
char room_4_exits[ROOM_4_EXITS][MAX_ROOM_EXIT_LEN] = {"North"};

// Define the room names
char room_1_name[MAX_ROOM_NAME_LEN] = "Room 1";
char room_2_name[MAX_ROOM_NAME_LEN] = "Room 2";
char room_3_name[MAX_ROOM_NAME_LEN] = "Room 3";
char room_4_name[MAX_ROOM_NAME_LEN] = "Room 4";

// Define the room descriptions
char room_1_description[MAX_ROOM_DESCRIPTION_LEN] = "You are in a dark room with two exits: north and south.";
char room_2_description[MAX_ROOM_DESCRIPTION_LEN] = "You are in a small room with a single exit: west.";
char room_3_description[MAX_ROOM_DESCRIPTION_LEN] = "You are in a room with a single exit: east.";
char room_4_description[MAX_ROOM_DESCRIPTION_LEN] = "You are in a room with a single exit: north.";

// Define the current room
int current_room = 0;

// Define the main function
int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in Room %d\n", current_room);
    printf("%s\n", room_1_description);
    printf("%s\n", room_1_name);
    
    // Prompt the user for their choice
    printf("What do you want to do? (North, South, East, West, Quit)\n");
    char choice[MAX_ROOM_EXIT_LEN];
    scanf("%s", choice);
    
    // Check the user's choice
    if (strcmp(choice, "Quit") == 0) {
        return 0;
    } else if (strcmp(choice, "North") == 0) {
        if (strcmp(room_1_exits[0], room_2_name) == 0) {
            printf("%s\n", room_2_description);
            printf("%s\n", room_2_name);
            current_room = 2;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(choice, "South") == 0) {
        if (strcmp(room_1_exits[1], room_1_name) == 0) {
            printf("%s\n", room_1_description);
            printf("%s\n", room_1_name);
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(choice, "East") == 0) {
        if (strcmp(room_3_exits[0], room_3_name) == 0) {
            printf("%s\n", room_3_description);
            printf("%s\n", room_3_name);
            current_room = 3;
        } else {
            printf("You cannot go that way.\n");
        }
    } else if (strcmp(choice, "West") == 0) {
        if (strcmp(room_2_exits[0], room_2_name) == 0) {
            printf("%s\n", room_2_description);
            printf("%s\n", room_2_name);
            current_room = 2;
        } else {
            printf("You cannot go that way.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}