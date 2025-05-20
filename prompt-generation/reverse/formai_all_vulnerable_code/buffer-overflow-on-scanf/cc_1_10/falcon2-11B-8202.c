//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM 100
#define MAX_DIRECTION 4
#define MAX_STRING 100

// Global variables
int current_room = 0;
int current_direction = 0;
char* room_description[MAX_ROOM];
char* direction_description[MAX_DIRECTION];

// Function declarations
void print_room_description(int room_num);
void print_direction_description(int direction_num);
void move_to_room(int direction_num);
void print_menu();
void get_input();
void game_over();

// Function definitions
void print_room_description(int room_num) {
    printf("You are in room %d.\n", room_num);
    printf("Description:\n");
    printf("%s\n", room_description[room_num]);
}

void print_direction_description(int direction_num) {
    printf("You can go in the following directions:\n");
    printf("%s\n", direction_description[direction_num]);
}

void move_to_room(int direction_num) {
    switch (direction_num) {
        case 0:
            current_direction = 0;
            break;
        case 1:
            current_direction = 1;
            break;
        case 2:
            current_direction = 2;
            break;
        case 3:
            current_direction = 3;
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Print room description\n");
    printf("2. Print direction description\n");
    printf("3. Move to a new room\n");
    printf("4. Exit\n");
}

void get_input() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_room_description(current_room);
            break;
        case 2:
            print_direction_description(current_direction);
            break;
        case 3:
            move_to_room(current_direction);
            get_input();
            break;
        case 4:
            game_over();
            break;
        default:
            printf("Invalid choice.\n");
            get_input();
            break;
    }
}

void game_over() {
    printf("Game over.\n");
    exit(1);
}

int main() {
    int num_rooms;
    int num_directions;

    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    printf("Enter the number of directions: ");
    scanf("%d", &num_directions);

    room_description[0] = "You are in a dark room. There is a door to your left and a door to your right.";
    room_description[1] = "You are in a bright room. There is a door to your left and a door to your right.";
    room_description[2] = "You are in a room with a giant treasure chest. There is a door to your left and a door to your right.";
    room_description[3] = "You are in a room with a giant monster. There is a door to your left and a door to your right.";

    direction_description[0] = "Left";
    direction_description[1] = "Right";
    direction_description[2] = "Forward";
    direction_description[3] = "Backward";

    print_menu();
    get_input();

    return 0;
}