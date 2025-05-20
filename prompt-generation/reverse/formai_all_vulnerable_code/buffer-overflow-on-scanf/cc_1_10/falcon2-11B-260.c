//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROOM 10

struct room {
    char name[20];
    int x;
    int y;
};

struct player {
    char name[20];
    int x;
    int y;
};

struct inventory {
    char name[20];
    int count;
};

int player_x = 0;
int player_y = 0;

struct player player;
struct inventory inventory[10];
struct room rooms[MAX_ROOM];

void* player_thread(void* arg) {
    int i;
    int choice;
    int direction;

    while (1) {
        printf("You are in a dark room.\n");
        printf("You see two doors in front of you.\n");
        printf("Which door do you enter? 1 or 2: ");
        scanf("%d", &choice);

        if (choice == 1) {
            player_x += 1;
            printf("You entered the door on the left.\n");
            printf("You find yourself in a long hallway.\n");
            printf("There is a door at the end of the hall.\n");
            printf("Do you enter the door? (y/n): ");
            scanf("%s", &choice);
            if (choice == "y") {
                printf("You enter the door.\n");
                printf("You are now in a new room!\n");
            } else if (choice == "n") {
                printf("You choose not to enter the door.\n");
                printf("You hear a strange noise coming from the door.\n");
                printf("Do you want to investigate the noise? (y/n): ");
                scanf("%s", &choice);
                if (choice == "y") {
                    printf("You open the door and find yourself in a new room.\n");
                } else if (choice == "n") {
                    printf("You decide not to investigate the noise.\n");
                }
            } else {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }
        } else if (choice == 2) {
            player_x -= 1;
            printf("You entered the door on the right.\n");
            printf("You find yourself in a long hallway.\n");
            printf("There is a door at the end of the hall.\n");
            printf("Do you enter the door? (y/n): ");
            scanf("%s", &choice);
            if (choice == "y") {
                printf("You enter the door.\n");
                printf("You are now in a new room!\n");
            } else if (choice == "n") {
                printf("You choose not to enter the door.\n");
                printf("You hear a strange noise coming from the door.\n");
                printf("Do you want to investigate the noise? (y/n): ");
                scanf("%s", &choice);
                if (choice == "y") {
                    printf("You open the door and find yourself in a new room.\n");
                } else if (choice == "n") {
                    printf("You decide not to investigate the noise.\n");
                }
            } else {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }
        } else {
            printf("Invalid input. Please enter 1 or 2.\n");
        }

        printf("Do you want to move? (y/n): ");
        scanf("%s", &choice);
        if (choice == "y") {
            printf("You move to the next room.\n");
            printf("You are now in a new room!\n");
        } else if (choice == "n") {
            printf("You decide to stay in the current room.\n");
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

void* room_thread(void* arg) {
    int i;
    int choice;

    while (1) {
        printf("You are in a dark room.\n");
        printf("You see a door in front of you.\n");
        printf("Do you open the door? (y/n): ");
        scanf("%s", &choice);
        if (choice == "y") {
            printf("You open the door.\n");
            printf("You are now in a new room!\n");
        } else if (choice == "n") {
            printf("You choose not to open the door.\n");
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

int main() {
    pthread_t player_thread_id;
    pthread_t room_thread_id;

    pthread_create(&player_thread_id, NULL, player_thread, NULL);
    pthread_create(&room_thread_id, NULL, room_thread, NULL);

    pthread_join(player_thread_id, NULL);
    pthread_join(room_thread_id, NULL);

    return 0;
}