//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define MAX_ROOM_SIZE 10

int room_size[ROOMS];
char room_name[ROOMS][MAX_ROOM_SIZE];

void generate_rooms() {
    srand(time(NULL));
    for (int i = 0; i < ROOMS; i++) {
        room_size[i] = rand() % MAX_ROOM_SIZE + 1;
        for (int j = 0; j < room_size[i]; j++) {
            room_name[i][j] = rand() % 26 + 'a';
        }
        room_name[i][room_size[i]] = '\0';
    }
}

void print_room(int room_number) {
    printf("Room %d: ", room_number);
    for (int i = 0; i < room_size[room_number]; i++) {
        printf("%c", room_name[room_number][i]);
    }
    printf("\n");
}

int main() {
    generate_rooms();
    int current_room = 0;

    while (1) {
        system("clear");
        printf("You are in room %d.\n", current_room);
        print_room(current_room);

        char choice;
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (current_room < ROOMS - 1) {
                    current_room++;
                } else {
                    printf("You reached the end of the haunted house.\n");
                    return 0;
                }
                break;
            case '2':
                if (current_room > 0) {
                    current_room--;
                } else {
                    printf("You reached the beginning of the haunted house.\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}