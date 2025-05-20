//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the structure of a room
typedef struct {
    char name[50];
    int is_haunted;
    int has_treasure;
} Room;

// Define the structure of the haunted house
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} HauntedHouse;

// Function to initialize the haunted house with random rooms
void init_haunted_house(HauntedHouse *house) {
    srand(time(NULL));
    house->num_rooms = rand() % MAX_ROOMS + 1;
    for (int i = 0; i < house->num_rooms; i++) {
        house->rooms[i].is_haunted = rand() % 2;
        house->rooms[i].has_treasure = rand() % 2;
        sprintf(house->rooms[i].name, "Room %d", i + 1);
    }
}

// Function to print the details of a room
void print_room(Room room) {
    printf("Name: %s\n", room.name);
    if (room.is_haunted) {
        printf("This room is haunted!\n");
    } else {
        printf("This room is not haunted.\n");
    }
    if (room.has_treasure) {
        printf("There is treasure in this room!\n");
    } else {
        printf("There is no treasure in this room.\n");
    }
}

// Function to explore the haunted house
void explore_haunted_house(HauntedHouse house) {
    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore a room\n");
        printf("2. Leave the haunted house\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int room_num;
            printf("Enter the number of the room you want to explore: ");
            scanf("%d", &room_num);

            if (room_num >= 1 && room_num <= house.num_rooms) {
                print_room(house.rooms[room_num - 1]);
            } else {
                printf("Invalid room number.\n");
            }
        } else if (choice == 2) {
            printf("You leave the haunted house.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    } while (1);
}

int main() {
    HauntedHouse house;
    init_haunted_house(&house);
    explore_haunted_house(house);
    return 0;
}