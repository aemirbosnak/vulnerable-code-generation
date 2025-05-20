//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50
#define MAX_GUESTS 2

typedef struct {
    char name[MAX_NAME_LENGTH][MAX_NAME_LENGTH];
    int room_number;
    int guests[MAX_GUESTS];
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void print_menu() {
    printf("1. Reserve Room\n");
    printf("2. Check-in Guest\n");
    printf("3. Check-out Guest\n");
    printf("4. List All Guests\n");
    printf("5. Quit\n");
}

void reserve_room(int room_number) {
    if (num_rooms >= MAX_ROOMS) {
        printf("Sorry, no more rooms available.\n");
        return;
    }

    rooms[num_rooms].room_number = room_number;
    num_rooms++;
}

void check_in(int room_number, char name[MAX_NAME_LENGTH]) {
    int i;

    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].guests[0] != -1 && rooms[i].guests[1] != -1) {
                printf("Sorry, that room is already occupied.\n");
                return;
            }

            strcpy(rooms[i].name[0], name);
            rooms[i].guests[0] = 1;
            return;
        }
    }

    printf("Sorry, that room number does not exist.\n");
}

void check_out(int room_number, char name[MAX_NAME_LENGTH]) {
    int i;

    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            int j;

            for (j = 0; j < MAX_GUESTS; j++) {
                if (strcmp(rooms[i].name[j], name) == 0) {
                    rooms[i].guests[j] = -1;
                    return;
                }
            }

            printf("Sorry, that name does not match any guest in that room.\n");
            return;
        }
    }

    printf("Sorry, that room number does not exist.\n");
}

void list_all_guests() {
    int i, j;

    for (i = 0; i < num_rooms; i++) {
        printf("Room %d: ", rooms[i].room_number);

        for (j = 0; j < MAX_GUESTS; j++) {
            if (rooms[i].guests[j] != -1) {
                printf("%s ", rooms[i].name[j]);
            }
        }

        printf("\n");
    }
}

int main() {
    char command[10];
    int room_number, i;
    char name[MAX_NAME_LENGTH];

    while (1) {
        print_menu();
        scanf("%s", command);

        switch (command[0]) {
        case '1':
            scanf("%d", &room_number);
            reserve_room(room_number);
            break;
        case '2':
            scanf("%d", &room_number);
            scanf("%s", name);
            check_in(room_number, name);
            break;
        case '3':
            scanf("%d", &room_number);
            scanf("%s", name);
            check_out(room_number, name);
            break;
        case '4':
            list_all_guests();
            break;
        case '5':
            exit(0);
        default:
            printf("Invalid command.\n");
        }
    }

    return 0;
}