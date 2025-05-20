//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
/*
 * hotel.c
 * A simple hotel management system written in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20
#define MAX_NAME_LENGTH 20

typedef struct {
    int room_number;
    char name[MAX_NAME_LENGTH];
    char room_type[MAX_NAME_LENGTH];
    int check_in_date;
    int check_out_date;
} Guest;

int main() {
    int guest_count = 0;
    Guest guests[MAX_GUESTS];

    printf("Welcome to the hotel management system!\n");
    printf("Please enter the number of guests: ");
    scanf("%d", &guest_count);

    for (int i = 0; i < guest_count; i++) {
        printf("Guest %d: ", i + 1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Room type: ");
        scanf("%s", guests[i].room_type);
        printf("Check-in date: ");
        scanf("%d", &guests[i].check_in_date);
        printf("Check-out date: ");
        scanf("%d", &guests[i].check_out_date);
    }

    int room_count = 0;
    int rooms[MAX_ROOMS];

    for (int i = 0; i < guest_count; i++) {
        if (strcmp(guests[i].room_type, "single") == 0) {
            rooms[room_count] = 1;
            room_count++;
        } else if (strcmp(guests[i].room_type, "double") == 0) {
            rooms[room_count] = 2;
            room_count++;
        } else if (strcmp(guests[i].room_type, "suite") == 0) {
            rooms[room_count] = 3;
            room_count++;
        }
    }

    int total_rooms = 0;
    for (int i = 0; i < room_count; i++) {
        total_rooms += rooms[i];
    }

    printf("Total rooms: %d\n", total_rooms);

    return 0;
}