//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room;
    float movement_speed;
    int is_active;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].room = -1;
        ghosts[i].movement_speed = 0.0f;
        ghosts[i].is_active = 0;
    }
}

void scare(int room) {
    for (int i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room == room && ghosts[i].is_active) {
            printf("Suddenly, you hear a rustle behind you... \n");
            printf("A cold wind blows through the halls... \n");
            printf("You feel a presence lurking nearby... \n");
            break;
        }
    }
}

void main() {
    initializeGhosts();

    int room_num = rand() % 5 + 1;
    printf("You wake up in a dark and lonely house... \n");
    printf("The only sound is your breathing and the clock ticking... \n");

    while (1) {
        printf("Enter a command (move, search, quit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "move") == 0) {
            int direction = rand() % 4;
            switch (direction) {
                case 0:
                    printf("You move north... \n");
                    room_num++;
                    break;
                case 1:
                    printf("You move south... \n");
                    room_num--;
                    break;
                case 2:
                    printf("You move east... \n");
                    room_num++;
                    break;
                case 3:
                    printf("You move west... \n");
                    room_num--;
                    break;
            }

            if (room_num > 5) {
                room_num = 5;
            } else if (room_num < 1) {
                room_num = 1;
            }

            scare(room_num);
        } else if (strcmp(command, "search") == 0) {
            printf("You search for clues... \n");
            // Implement searching logic
        } else if (strcmp(command, "quit") == 0) {
            printf("You escape the haunted house... \n");
            break;
        } else {
            printf("Invalid command... \n");
        }
    }
}