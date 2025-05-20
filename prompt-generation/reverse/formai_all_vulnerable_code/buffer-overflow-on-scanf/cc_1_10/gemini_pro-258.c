//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Room {
    int room_number;
    char room_type;
    float room_price;
    int is_occupied;
} Room;

typedef struct Guest {
    char name[50];
    char address[100];
    char phone_number[15];
    char email[50];
    int room_number;
    int check_in_date;
    int check_out_date;
} Guest;

Room rooms[100];
Guest guests[100];

int num_rooms = 0;
int num_guests = 0;

void add_room() {
    int room_number;
    char room_type;
    float room_price;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter room type (S/D/T): ");
    scanf(" %c", &room_type);

    printf("Enter room price: ");
    scanf("%f", &room_price);

    rooms[num_rooms].room_number = room_number;
    rooms[num_rooms].room_type = room_type;
    rooms[num_rooms].room_price = room_price;
    rooms[num_rooms].is_occupied = 0;

    num_rooms++;
}

void add_guest() {
    char name[50];
    char address[100];
    char phone_number[15];
    char email[50];
    int room_number;
    int check_in_date;
    int check_out_date;

    printf("Enter guest name: ");
    scanf(" %[^\n]", name);

    printf("Enter guest address: ");
    scanf(" %[^\n]", address);

    printf("Enter guest phone number: ");
    scanf(" %[^\n]", phone_number);

    printf("Enter guest email: ");
    scanf(" %[^\n]", email);

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter check-in date: ");
    scanf("%d", &check_in_date);

    printf("Enter check-out date: ");
    scanf("%d", &check_out_date);

    guests[num_guests].room_number = room_number;
    guests[num_guests].check_in_date = check_in_date;
    guests[num_guests].check_out_date = check_out_date;

    strcpy(guests[num_guests].name, name);
    strcpy(guests[num_guests].address, address);
    strcpy(guests[num_guests].phone_number, phone_number);
    strcpy(guests[num_guests].email, email);

    rooms[room_number - 1].is_occupied = 1;

    num_guests++;
}

void check_availability() {
    int room_type;
    int check_in_date;
    int check_out_date;

    printf("Enter room type (S/D/T): ");
    scanf(" %c", &room_type);

    printf("Enter check-in date: ");
    scanf("%d", &check_in_date);

    printf("Enter check-out date: ");
    scanf("%d", &check_out_date);

    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_type == room_type && rooms[i].is_occupied == 0) {
            printf("Room %d is available.\n", rooms[i].room_number);
        }
    }
}

void check_in_guest() {
    int room_number;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("Guest %s has checked in.\n", guests[i].name);
            rooms[room_number - 1].is_occupied = 1;
        }
    }
}

void check_out_guest() {
    int room_number;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("Guest %s has checked out.\n", guests[i].name);
            rooms[room_number - 1].is_occupied = 0;
        }
    }
}

void print_guest_details() {
    int room_number;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("Guest Name: %s\n", guests[i].name);
            printf("Guest Address: %s\n", guests[i].address);
            printf("Guest Phone Number: %s\n", guests[i].phone_number);
            printf("Guest Email: %s\n", guests[i].email);
            printf("Check-in Date: %d\n", guests[i].check_in_date);
            printf("Check-out Date: %d\n", guests[i].check_out_date);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Room\n");
        printf("2. Add Guest\n");
        printf("3. Check Availability\n");
        printf("4. Check In Guest\n");
        printf("5. Check Out Guest\n");
        printf("6. Print Guest Details\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                add_guest();
                break;
            case 3:
                check_availability();
                break;
            case 4:
                check_in_guest();
                break;
            case 5:
                check_out_guest();
                break;
            case 6:
                print_guest_details();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}