//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_NAME 20

struct hotel_room {
    int room_no;
    char name[MAX_NAME];
    char status[20];
    int price;
};

struct hotel_room hotel_rooms[MAX_ROOMS];

void add_room(int room_no, char *name, char *status, int price) {
    if (room_no < 1 || room_no > MAX_ROOMS) {
        printf("Invalid room number\n");
        return;
    }
    if (strlen(name) > MAX_NAME) {
        printf("Room name too long\n");
        return;
    }
    if (strlen(status) > 20) {
        printf("Room status too long\n");
        return;
    }
    if (price < 0) {
        printf("Invalid price\n");
        return;
    }
    strcpy(hotel_rooms[room_no].name, name);
    strcpy(hotel_rooms[room_no].status, status);
    hotel_rooms[room_no].price = price;
}

void print_rooms() {
    printf("Room No. | Name | Status | Price\n");
    for (int i = 1; i <= MAX_ROOMS; i++) {
        if (hotel_rooms[i].room_no!= 0) {
            printf("%3d | %-20s | %-20s | $%d\n", i, hotel_rooms[i].name, hotel_rooms[i].status, hotel_rooms[i].price);
        }
    }
}

int main() {
    int choice, room_no, price;
    char name[MAX_NAME], status[20];

    do {
        printf("Welcome to the Future Hotel Management System\n");
        printf("1. Add a new room\n");
        printf("2. Print all rooms\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter room number: ");
            scanf("%d", &room_no);
            printf("Enter room name: ");
            scanf("%s", name);
            printf("Enter room status: ");
            scanf("%s", status);
            printf("Enter room price: ");
            scanf("%d", &price);
            add_room(room_no, name, status, price);
            break;
        case 2:
            print_rooms();
            break;
        case 3:
            printf("Thank you for using the Future Hotel Management System\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice!= 3);

    return 0;
}