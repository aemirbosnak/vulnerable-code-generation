//Code Llama-13B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
/*
 * Haunted House Simulator
 *
 * This program simulates a haunted house, where the user can enter the number of rooms and the number of ghosts in each room.
 * The program will then generate a random layout of the house and display the ghosts in each room.
 * The user can then interact with the ghosts by answering questions to earn points.
 * The user's score will be displayed at the end of the simulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures to represent a room and a ghost
typedef struct {
    int number_of_ghosts;
    int ghosts[10];
} Room;

typedef struct {
    int x;
    int y;
    int ghost_id;
} Ghost;

// Function to generate a random layout of the house
void generate_layout(Room* rooms, int number_of_rooms) {
    srand(time(NULL));
    for (int i = 0; i < number_of_rooms; i++) {
        rooms[i].number_of_ghosts = rand() % 10;
        for (int j = 0; j < rooms[i].number_of_ghosts; j++) {
            rooms[i].ghosts[j] = rand() % 10;
        }
    }
}

// Function to display the ghosts in each room
void display_ghosts(Room* rooms, int number_of_rooms) {
    for (int i = 0; i < number_of_rooms; i++) {
        printf("Room %d:\n", i + 1);
        for (int j = 0; j < rooms[i].number_of_ghosts; j++) {
            printf("  Ghost %d: %d\n", j + 1, rooms[i].ghosts[j]);
        }
    }
}

// Function to interact with the ghosts
void interact_with_ghosts(Room* rooms, int number_of_rooms) {
    int score = 0;
    for (int i = 0; i < number_of_rooms; i++) {
        for (int j = 0; j < rooms[i].number_of_ghosts; j++) {
            printf("Room %d, Ghost %d: ", i + 1, j + 1);
            int answer = 0;
            scanf("%d", &answer);
            if (answer == rooms[i].ghosts[j]) {
                score++;
            }
        }
    }
    printf("Your score is: %d\n", score);
}

int main() {
    int number_of_rooms = 0;
    printf("Enter the number of rooms: ");
    scanf("%d", &number_of_rooms);
    Room* rooms = malloc(number_of_rooms * sizeof(Room));
    generate_layout(rooms, number_of_rooms);
    display_ghosts(rooms, number_of_rooms);
    interact_with_ghosts(rooms, number_of_rooms);
    free(rooms);
    return 0;
}