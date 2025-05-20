#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 3
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int description;
} Room;

Room rooms[MAX_ROOMS] = {
    {"Hall", 1},
    {"Kitchen", 2},
    {"Bedroom", 3}
};

void print_room_description(int room_id) {
    switch (room_id) {
        case 1:
            printf("You are in the Hall. There is a door to the Kitchen.\n");
            break;
        case 2:
            printf("You are in the Kitchen. There is a door to the Bedroom.\n");
            break;
        case 3:
            printf("You are in the Bedroom. You win!\n");
            break;
        default:
            printf("Unknown room.\n");
            break;
    }
}

int main() {
    int current_room = 1;
    char input[100];

    while (1) {
        print_room_description(current_room);
        printf("Enter your command: ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "go ", 3) == 0) {
            int next_room;
            sscanf(input + 3, "%d", &next_room);
            if (next_room >= 1 && next_room <= MAX_ROOMS) {
                current_room = next_room;
            } else {
                printf("Invalid room number.\n");
            }
        } else if (strcmp(input, "exit\n") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
