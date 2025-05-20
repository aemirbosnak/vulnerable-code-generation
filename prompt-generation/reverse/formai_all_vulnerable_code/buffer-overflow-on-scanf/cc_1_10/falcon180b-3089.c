//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

// Game data
char *room_description[] = {
    "You are in a small room with a locked door.",
    "You are in a dark hallway with two doors.",
    "You are in a large room with a treasure chest."
};

int room_exits[] = {
    1, // North
    0, // South
    2, // East
    0  // West
};

int num_rooms = 3;
int player_room = 0;

void *game_loop(void *arg) {
    char input[100];
    while (true) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "move") == 0) {
            char direction;
            scanf(" %c", &direction);
            int new_room = player_room;
            switch (direction) {
                case 'n':
                    new_room += 1;
                    break;
                case's':
                    new_room -= 1;
                    break;
                case 'e':
                    new_room += num_rooms;
                    break;
                case 'w':
                    new_room -= num_rooms;
                    break;
            }
            if (new_room >= 0 && new_room < num_rooms) {
                player_room = new_room;
                printf("You moved to room %d.\n", player_room);
                printf("%s\n", room_description[player_room]);
            } else {
                printf("Invalid move.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, game_loop, NULL);
    while (true) {
        sleep(1);
    }
    return 0;
}