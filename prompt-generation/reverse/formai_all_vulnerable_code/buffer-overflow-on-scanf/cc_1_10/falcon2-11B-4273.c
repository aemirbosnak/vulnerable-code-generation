//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50

typedef struct {
    char name[50];
    int price;
    int availability;
} Room;

typedef struct {
    char name[50];
    int room_count;
    Room rooms[MAX_ROOMS];
} Hotel;

int main() {
    Hotel hotel;
    char name[50];

    printf("Welcome to the C Hotel Management System!\n");
    printf("Please enter the name of the hotel:\n");
    scanf("%s", name);
    strcpy(hotel.name, name);
    printf("Hotel name entered: %s\n", hotel.name);

    printf("Please enter the number of rooms:\n");
    scanf("%d", &hotel.room_count);
    printf("Number of rooms entered: %d\n", hotel.room_count);

    for (int i = 0; i < hotel.room_count; i++) {
        printf("Please enter the name of room %d:\n", i + 1);
        scanf("%s", hotel.rooms[i].name);
        printf("Name of room %d entered: %s\n", i + 1, hotel.rooms[i].name);

        printf("Please enter the price of room %d:\n", i + 1);
        scanf("%d", &hotel.rooms[i].price);
        printf("Price of room %d entered: %d\n", i + 1, hotel.rooms[i].price);

        printf("Please enter the availability of room %d (1-10):\n", i + 1);
        scanf("%d", &hotel.rooms[i].availability);
        printf("Availability of room %d entered: %d\n", i + 1, hotel.rooms[i].availability);
    }

    printf("Hotel information:\n");
    printf("Name: %s\n", hotel.name);
    printf("Number of rooms: %d\n", hotel.room_count);

    for (int i = 0; i < hotel.room_count; i++) {
        printf("Room %d:\n", i + 1);
        printf("Name: %s\n", hotel.rooms[i].name);
        printf("Price: %d\n", hotel.rooms[i].price);
        printf("Availability: %d\n", hotel.rooms[i].availability);
    }

    return 0;
}