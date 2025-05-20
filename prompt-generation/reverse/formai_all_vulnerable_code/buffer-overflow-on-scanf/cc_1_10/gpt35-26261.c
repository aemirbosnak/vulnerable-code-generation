//FormAI DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    char address[100];
    char phone[20];
    int room_num;
    int nights;
    float bill;
};

struct room {
    int num;
    int beds;
    float price;
    int occupied;
};

void display_menu() {
    printf("\n\nCharming Hotel Management System\n\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. Room Occupancy\n");
    printf("4. Exit\n\n");
    printf("Please enter your choice (1-4): ");
}

void check_in(struct room *rooms, int num_rooms, struct guest *guests, int num_guests) {
    printf("\nEnter guest details:\n\n");
    printf("Name: ");
    scanf(" %[^\n]", guests[num_guests].name);
    printf("Address: ");
    scanf(" %[^\n]", guests[num_guests].address);
    printf("Phone: ");
    scanf(" %[^\n]", guests[num_guests].phone);

    for (int i = 0; i < num_rooms; i++) {
        if (!rooms[i].occupied) {
            printf("\nAvailable room(s):\n\n");
            printf("Room Number: %d\n", rooms[i].num);
            printf("Number of beds: %d\n", rooms[i].beds);
            printf("Price per night: %.2f\n", rooms[i].price);
        }
    }

    printf("\nEnter room number: ");
    scanf("%d", &guests[num_guests].room_num);
    printf("Enter number of nights: ");
    scanf("%d", &guests[num_guests].nights);

    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].num == guests[num_guests].room_num) {
            rooms[i].occupied = 1;
            rooms[i].price = guests[num_guests].nights * rooms[i].price;
            guests[num_guests].bill = rooms[i].price;
            break;
        }
    }

    printf("\nCheck-In Successful!\n\n");
}

void check_out(struct room *rooms, int num_rooms, struct guest *guests, int num_guests) {
    int found = 0;
    int room_num;

    printf("\nEnter room number: ");
    scanf("%d", &room_num);

    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_num == room_num) {
            printf("\nGuest details:\n\n");
            printf("Name: %s\n", guests[i].name);
            printf("Address: %s\n", guests[i].address);
            printf("Phone: %s\n", guests[i].phone);
            printf("Room Number: %d\n", guests[i].room_num);
            printf("Number of nights: %d\n", guests[i].nights);
            printf("Bill: %.2f\n\n", guests[i].bill);

            guests[i].room_num = 0;
            guests[i].nights = 0;
            guests[i].bill = 0;

            for (int j = 0; j < num_rooms; j++) {
                if (rooms[j].num == room_num) {
                    rooms[j].occupied = 0;
                    rooms[j].price = 0;
                    break;
                }
            }

            printf("Check-Out Successful!\n\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nInvalid room number or guest not found!\n\n");
    }
}

void room_occupancy(struct room *rooms, int num_rooms) {
    int total_rooms = 0;
    int occupied_rooms = 0;

    for (int i = 0; i < num_rooms; i++) {
        total_rooms++;
        if (rooms[i].occupied) {
            occupied_rooms++;
        }
    }

    printf("\nTotal Rooms: %d\n", total_rooms);
    printf("Occupied Rooms: %d\n", occupied_rooms);
    printf("Vacant Rooms: %d\n\n", total_rooms - occupied_rooms);
}

int main() {
    struct room rooms[10] = { {101, 2, 50.00, 0}, {102, 1, 25.00, 0}, {103, 1, 25.00, 0}, {104, 2, 50.00, 0},
                              {105, 1, 25.00, 0}, {106, 2, 50.00, 0}, {107, 1, 25.00, 0}, {108, 2, 50.00, 0},
                              {109, 1, 25.00, 0}, {110, 2, 50.00, 0} };
    struct guest guests[10];
    int num_rooms = 10;
    int num_guests = 0;
    int choice;

    printf("\nWelcome to Charming Hotel!\n\n");

    do {
        display_menu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_guests >= num_rooms) {
                    printf("\nAll rooms are occupied!\n\n");
                } else {
                    check_in(rooms, num_rooms, guests, num_guests);
                    num_guests++;
                }
                break;
            case 2:
                check_out(rooms, num_rooms, guests, num_guests);
                break;
            case 3:
                room_occupancy(rooms, num_rooms);
                break;
            case 4:
                printf("\nThank you for choosing Charming Hotel!\n\n");
                break;
            default:
                printf("\nInvalid Choice!\n\n");
                break;
        }

    } while (choice != 4);

    return 0;
}