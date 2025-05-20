//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#define MAX_ROOMS 100

struct guest {
    char name[MAX_NAME_LENGTH];
    int room_number;
};

struct room {
    int room_number;
    int guests;
    struct guest* guests_list;
};

struct hotel {
    int rooms;
    struct room* room_list;
};

void create_hotel(struct hotel* hotel, int rooms) {
    hotel->rooms = rooms;
    hotel->room_list = malloc(sizeof(struct room) * rooms);

    for (int i = 0; i < rooms; i++) {
        hotel->room_list[i].room_number = i + 1;
        hotel->room_list[i].guests = 0;
        hotel->room_list[i].guests_list = malloc(sizeof(struct guest) * 10);
    }
}

void add_guest(struct hotel* hotel, int room_number, char* name) {
    int i = room_number - 1;

    if (hotel->room_list[i].guests < 10) {
        strcpy(hotel->room_list[i].guests_list[hotel->room_list[i].guests].name, name);
        hotel->room_list[i].guests++;
    } else {
        printf("Room is full\n");
    }
}

void remove_guest(struct hotel* hotel, int room_number, char* name) {
    int i = room_number - 1;
    int j;

    for (j = 0; j < hotel->room_list[i].guests; j++) {
        if (strcmp(hotel->room_list[i].guests_list[j].name, name) == 0) {
            hotel->room_list[i].guests--;
            break;
        }
    }

    if (j == hotel->room_list[i].guests) {
        printf("Guest not found\n");
    }
}

void print_guests(struct hotel* hotel, int room_number) {
    int i = room_number - 1;

    printf("Guests in room %d: ", room_number);

    for (int j = 0; j < hotel->room_list[i].guests; j++) {
        printf("%s ", hotel->room_list[i].guests_list[j].name);
    }

    printf("\n");
}

int main() {
    struct hotel hotel;
    create_hotel(&hotel, 5);

    add_guest(&hotel, 1, "John");
    add_guest(&hotel, 1, "Jane");
    add_guest(&hotel, 1, "Jim");
    add_guest(&hotel, 2, "Bob");
    add_guest(&hotel, 2, "Alice");

    print_guests(&hotel, 1);
    print_guests(&hotel, 2);

    remove_guest(&hotel, 1, "Jim");
    remove_guest(&hotel, 2, "Bob");

    print_guests(&hotel, 1);
    print_guests(&hotel, 2);

    return 0;
}