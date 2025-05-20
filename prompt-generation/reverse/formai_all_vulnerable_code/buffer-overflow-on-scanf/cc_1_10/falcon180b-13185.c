//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the haunted house and its rooms
void print_house(int num_rooms) {
    int i;
    printf("Haunted House:\n");
    for (i = 0; i < num_rooms; i++) {
        printf("Room %d: ", i + 1);
        if (i == 0) {
            printf("You are standing in the entrance hall.\n");
        } else if (i == num_rooms - 1) {
            printf("You have reached the end of the house.\n");
        } else {
            printf("There is a door to your left and a door to your right.\n");
        }
    }
}

// Function to randomly choose a room number
int choose_room(int num_rooms) {
    return rand() % num_rooms;
}

// Function to describe the room and its contents
void describe_room(int room_num, int num_rooms) {
    if (room_num == 0) {
        printf("You are standing in the entrance hall.\n");
    } else if (room_num == num_rooms - 1) {
        printf("You have reached the end of the house.\n");
    } else {
        printf("You are in room %d.\n", room_num + 1);
        printf("There is a door to your left and a door to your right.\n");
    }
}

// Function to move the player to the next room
void move_player(int *room_num, int num_rooms) {
    int next_room = choose_room(num_rooms);
    while (next_room == *room_num) {
        next_room = choose_room(num_rooms);
    }
    *room_num = next_room;
}

// Function to check if the player has reached the end of the house
int check_end(int room_num, int num_rooms) {
    return room_num == num_rooms - 1;
}

int main() {
    int num_rooms, room_num = 0;
    srand(time(NULL));
    printf("How many rooms does the haunted house have? ");
    scanf("%d", &num_rooms);

    // Print the haunted house and its rooms
    print_house(num_rooms);

    // Move the player through the house
    while (!check_end(room_num, num_rooms)) {
        describe_room(room_num, num_rooms);
        move_player(&room_num, num_rooms);
    }

    // Player has reached the end of the house
    printf("Congratulations! You have made it through the haunted house.\n");

    return 0;
}