//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ROOMS 100
#define MAX_CLIENTS 100
#define MAX_NAMES 50

typedef struct {
    int room_no;
    int price;
    int occupied;
    char name[MAX_NAMES];
} Room;

int main() {
    int num_rooms = 0;
    int num_clients = 0;
    int num_names = 0;
    Room rooms[MAX_ROOMS];

    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    printf("Enter the number of clients: ");
    scanf("%d", &num_clients);

    printf("Enter the number of names: ");
    scanf("%d", &num_names);

    for (int i = 0; i < num_rooms; i++) {
        printf("Enter room number %d: ", i + 1);
        scanf("%d", &rooms[i].room_no);
        printf("Enter price: ");
        scanf("%d", &rooms[i].price);
        printf("Enter occupied: ");
        scanf("%d", &rooms[i].occupied);
        printf("Enter name: ");
        scanf("%s", rooms[i].name);
    }

    printf("\n");

    for (int i = 0; i < num_clients; i++) {
        printf("Enter client number %d: ", i + 1);
        scanf("%d", &rooms[i].room_no);
        printf("Enter name: ");
        scanf("%s", rooms[i].name);
    }

    printf("\n");

    for (int i = 0; i < num_names; i++) {
        printf("Enter name: ");
        scanf("%s", rooms[i].name);
    }

    printf("\n");

    for (int i = 0; i < num_rooms; i++) {
        printf("Room %d: %s @ $%d\n", i + 1, rooms[i].name, rooms[i].price);
    }

    for (int i = 0; i < num_clients; i++) {
        printf("Client %d: %s @ Room %d\n", i + 1, rooms[i].name, rooms[i].room_no);
    }

    for (int i = 0; i < num_names; i++) {
        printf("Name: %s\n", rooms[i].name);
    }

    return 0;
}