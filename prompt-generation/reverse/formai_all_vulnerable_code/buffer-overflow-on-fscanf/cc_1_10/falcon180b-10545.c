//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100

struct room {
    int number;
    char type[30];
    int price;
    int status;
};

struct guest {
    char name[50];
    char id[20];
    int age;
    char phone[15];
};

struct booking {
    int guest_id;
    int room_number;
    int checkin_date;
    int checkout_date;
    int total_price;
};

int main() {
    FILE *file;
    struct room rooms[MAX_ROOMS];
    int num_rooms = 0;
    struct guest guests[MAX_GUESTS];
    int num_guests = 0;
    struct booking bookings[MAX_BOOKINGS];
    int num_bookings = 0;

    file = fopen("rooms.txt", "r");
    if (file == NULL) {
        printf("Error: rooms.txt not found.\n");
        exit(1);
    }

    while (fscanf(file, "%d %s %d %d\n", &rooms[num_rooms].number, rooms[num_rooms].type, &rooms[num_rooms].price, &rooms[num_rooms].status)!= EOF) {
        num_rooms++;
    }

    fclose(file);

    file = fopen("guests.txt", "r");
    if (file == NULL) {
        printf("Error: guests.txt not found.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s %d %s\n", guests[num_guests].name, guests[num_guests].id, &guests[num_guests].age, guests[num_guests].phone)!= EOF) {
        num_guests++;
    }

    fclose(file);

    file = fopen("bookings.txt", "r");
    if (file == NULL) {
        printf("Error: bookings.txt not found.\n");
        exit(1);
    }

    while (fscanf(file, "%d %d %d %d %d\n", &bookings[num_bookings].guest_id, &bookings[num_bookings].room_number, &bookings[num_bookings].checkin_date, &bookings[num_bookings].checkout_date, &bookings[num_bookings].total_price)!= EOF) {
        num_bookings++;
    }

    fclose(file);

    // TODO: implement hotel management system logic

    return 0;
}