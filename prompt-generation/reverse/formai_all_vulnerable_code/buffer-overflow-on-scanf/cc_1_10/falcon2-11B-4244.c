//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room;
    int days_staying;
    int check_in_time;
    int check_out_time;
} Guest;

typedef struct {
    int room_num;
    char room_type[10];
    int is_available;
} Room;

int main() {
    // Initialize guest and room arrays
    Guest guests[10];
    Room rooms[10];

    // Check-in guests
    for (int i = 0; i < 10; i++) {
        printf("Guest %d: ", i + 1);
        scanf("%s %d %d %d %d", guests[i].name, &guests[i].room, &guests[i].days_staying, &guests[i].check_in_time, &guests[i].check_out_time);
    }

    // Check-out guests
    for (int i = 0; i < 10; i++) {
        printf("Guest %d: ", i + 1);
        scanf("%s %d %d %d %d", guests[i].name, &guests[i].room, &guests[i].days_staying, &guests[i].check_in_time, &guests[i].check_out_time);
    }

    // Update room availability
    for (int i = 0; i < 10; i++) {
        printf("Room %d: ", i + 1);
        scanf("%d %s %d", &rooms[i].room_num, rooms[i].room_type, &rooms[i].is_available);
    }

    // Print guest and room information
    printf("Guests: ");
    for (int i = 0; i < 10; i++) {
        printf("%s %d %d %d %d\n", guests[i].name, guests[i].room, guests[i].days_staying, guests[i].check_in_time, guests[i].check_out_time);
    }
    printf("Rooms: ");
    for (int i = 0; i < 10; i++) {
        printf("%d %s %d\n", rooms[i].room_num, rooms[i].room_type, rooms[i].is_available);
    }

    return 0;
}