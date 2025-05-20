//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    char room_number[10];
    char room_type[20];
    int available;
    float rate;
} Room;

// Define a function to search for a room
Room* search_room(char* room_number) {
    // Allocate memory for the room structure
    Room* room = (Room*)malloc(sizeof(Room));

    // Open the room database
    FILE* file = fopen("rooms.txt", "r");

    // Read the room information from the database
    fscanf(file, "%s %s %d %f\n", room->room_number, room->room_type, &room->available, &room->rate);

    // Close the room database
    fclose(file);

    // Return the room structure
    return room;
}

// Define a function to book a room
void book_room(Room* room) {
    // Update the room availability
    room->available = 0;

    // Save the room information to the database
    FILE* file = fopen("rooms.txt", "w");

    fprintf(file, "%s %s %d %f\n", room->room_number, room->room_type, room->available, room->rate);

    fclose(file);
}

int main() {
    // Create a room structure
    Room* room = (Room*)malloc(sizeof(Room));

    // Search for a room
    room = search_room("101");

    // Book a room
    book_room(room);

    // Print the room information
    printf("Room number: %s\n", room->room_number);
    printf("Room type: %s\n", room->room_type);
    printf("Available: %d\n", room->available);
    printf("Rate: %.2f\n", room->rate);

    return 0;
}