//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200

struct room {
    int room_number;
    char room_type[20];
    int capacity;
    float price_per_night;
    int occupied;
};

struct guest {
    char name[30];
    int age;
    char address[100];
    char phone[15];
    char email[50];
    int room_num;
};

int num_rooms = 0;
int num_guests = 0;
struct room rooms[MAX_ROOMS];
struct guest guests[MAX_GUESTS];

void add_room() {
    if (num_rooms > MAX_ROOMS) {
        printf("Maximum number of rooms reached.\n");
        return;
    }
    struct room r;
    r.room_number = num_rooms + 1;
    printf("Enter room type: ");
    scanf("%s", r.room_type);
    printf("Enter capacity: ");
    scanf("%d", &r.capacity);
    printf("Enter price per night: ");
    scanf("%f", &r.price_per_night);
    r.occupied = 0;
    rooms[num_rooms] = r;
    num_rooms++;
    printf("Room added successfully!\n");
}

void display_room(struct room r) {
    printf("%d\t%s\t%d\t%.2f\t%s\n", r.room_number, r.room_type, r.capacity, r.price_per_night, r.occupied ? "Occupied" : "Available");
}

void display_rooms() {
    printf("Room Number\tRoom Type\tCapacity\tPrice per Night\tStatus\n");
    for (int i=0; i<num_rooms; i++) {
        display_room(rooms[i]);
    }
}

void book_room() {
    int room_num, guest_num;
    printf("Enter room number: ");
    scanf("%d", &room_num);
    for (int i=0; i<num_rooms; i++) {
        if (rooms[i].room_number == room_num) {
            if (rooms[i].occupied) {
                printf("Room is already occupied.\n");
                return;
            } else {
                rooms[i].occupied = 1;
                printf("Enter guest name: ");
                scanf("%s", guests[num_guests].name);
                printf("Enter guest age: ");
                scanf("%d", &guests[num_guests].age);
                printf("Enter guest address: ");
                scanf("%s", guests[num_guests].address);
                printf("Enter guest phone number: ");
                scanf("%s", guests[num_guests].phone);
                printf("Enter guest email: ");
                scanf("%s", guests[num_guests].email);
                guests[num_guests].room_num = room_num;
                guest_num = num_guests;
                num_guests++;
                printf("Room booked successfully!\n");
                break;
            }
        }
    }
}

void display_guest(struct guest g) {
    printf("%s\t%d\t%s\t%s\t%s\t%d\n", g.name, g.age, g.address, g.phone, g.email, g.room_num);
}

void display_guests() {
    printf("Name\tAge\tAddress\t\tPhone\t\t\tEmail\t\tRoom Number\n");
    for (int i=0; i<num_guests; i++) {
        display_guest(guests[i]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Welcome to the C Hotel Management System!\n");
        printf("1. Add a room\n");
        printf("2. Display all rooms\n");
        printf("3. Book a room\n");
        printf("4. Display all guests\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_room(); break;
            case 2: display_rooms(); break;
            case 3: book_room(); break;
            case 4: display_guests(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}