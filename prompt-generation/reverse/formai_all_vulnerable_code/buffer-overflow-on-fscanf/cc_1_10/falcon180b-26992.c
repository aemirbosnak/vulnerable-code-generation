//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100

struct booking {
    int guest_id;
    int room_id;
    char check_in_date[10];
    char check_out_date[10];
    char status;
};

struct guest {
    int id;
    char name[50];
    char address[100];
    char phone[15];
};

struct room {
    int id;
    char type[20];
    int price;
    char status;
};

int main() {
    int num_guests = 0, num_rooms = 0, num_bookings = 0;
    struct guest guests[MAX_GUESTS];
    struct room rooms[MAX_ROOMS];
    struct booking bookings[MAX_BOOKINGS];

    FILE *fp_guest, *fp_room, *fp_booking;

    fp_guest = fopen("guests.txt", "r");
    if (fp_guest == NULL) {
        printf("Error: unable to open guests file.\n");
        exit(1);
    }

    while (fscanf(fp_guest, "%d %s %s %s", &guests[num_guests].id, guests[num_guests].name, guests[num_guests].address, guests[num_guests].phone)!= EOF) {
        num_guests++;
    }

    fclose(fp_guest);

    fp_room = fopen("rooms.txt", "r");
    if (fp_room == NULL) {
        printf("Error: unable to open rooms file.\n");
        exit(1);
    }

    while (fscanf(fp_room, "%d %s %d %s", &rooms[num_rooms].id, rooms[num_rooms].type, &rooms[num_rooms].price, rooms[num_rooms].status)!= EOF) {
        num_rooms++;
    }

    fclose(fp_room);

    fp_booking = fopen("bookings.txt", "r");
    if (fp_booking == NULL) {
        printf("Error: unable to open bookings file.\n");
        exit(1);
    }

    while (fscanf(fp_booking, "%d %d %s %s %c", &bookings[num_bookings].guest_id, &bookings[num_bookings].room_id, bookings[num_bookings].check_in_date, bookings[num_bookings].check_out_date, bookings[num_bookings].status)!= EOF) {
        num_bookings++;
    }

    fclose(fp_booking);

    return 0;
}