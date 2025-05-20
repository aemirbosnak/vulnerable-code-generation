//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 1000

int main() {
    // Initialize the game
    printf("Welcome to the Rogue-like Game with Procedural Generation!\n");
    printf("Enter the number of rooms to generate: ");
    int num_rooms = 0;
    scanf("%d", &num_rooms);
    if (num_rooms <= MAX_ROOMS) {
        // Generate the rooms
        srand(time(NULL));
        int room_size = (rand() % (WIDTH - 5)) + 5;
        int num_rooms_generated = 0;
        int room_x = 0;
        int room_y = 0;
        while (num_rooms_generated < num_rooms) {
            int room_size_x = (rand() % (room_size - 5)) + 5;
            int room_size_y = (rand() % (room_size - 5)) + 5;
            int room_x_end = (room_x + room_size_x) > WIDTH? WIDTH : room_x + room_size_x;
            int room_y_end = (room_y + room_size_y) > HEIGHT? HEIGHT : room_y + room_size_y;
            for (int i = room_x; i < room_x_end; i++) {
                for (int j = room_y; j < room_y_end; j++) {
                    printf("X");
                }
                printf("\n");
            }
            num_rooms_generated++;
            room_x = (rand() % (WIDTH - 5)) + 5;
            room_y = (rand() % (HEIGHT - 5)) + 5;
        }
        printf("Rooms generated!\n");
    } else {
        printf("Too many rooms requested. Maximum number of rooms is %d.\n", MAX_ROOMS);
    }

    // Play the game
    printf("To move, enter a direction (N, S, E, W). To exit, enter 'q'.\n");
    char direction;
    while (1) {
        printf("Enter a direction: ");
        scanf(" %c", &direction);
        if (direction == 'q') {
            break;
        }
        switch (direction) {
            case 'N':
                printf("You are going north!\n");
                break;
            case 'S':
                printf("You are going south!\n");
                break;
            case 'E':
                printf("You are going east!\n");
                break;
            case 'W':
                printf("You are going west!\n");
                break;
            default:
                printf("Invalid direction entered.\n");
                break;
        }
    }

    return 0;
}