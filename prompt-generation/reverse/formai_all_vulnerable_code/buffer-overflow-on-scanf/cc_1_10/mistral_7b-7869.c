//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15

struct room {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int isOccupied;
};

struct hotel {
    struct room rooms[MAX_ROOMS];
};

void printRooms(struct hotel* hotel);
void bookRoom(struct hotel* hotel, char name[], char phone[]);

int main() {
    struct hotel hotel;
    int choice;

    memset(hotel.rooms, 0, sizeof(hotel.rooms));

    do {
        printf("\nHotel Management System\n");
        printf("1. Book Room\n");
        printf("2. Print Rooms\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
                bookRoom(&hotel, name, phone);
                break;
            }
            case 2: {
                printRooms(&hotel);
                break;
            }
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}

void printRooms(struct hotel* hotel) {
    int i;

    printf("\nCurrent Room Status:\n");
    for(i = 0; i < MAX_ROOMS; i++) {
        if(!hotel->rooms[i].isOccupied) {
            printf("\nRoom %d: Available", i+1);
        } else {
            printf("\nRoom %d: Occupied by %s (%s)", i+1, hotel->rooms[i].name, hotel->rooms[i].phone);
        }
    }
}

void bookRoom(struct hotel* hotel, char name[], char phone[]) {
    int i;

    for(i = 0; i < MAX_ROOMS; i++) {
        if(!hotel->rooms[i].isOccupied) {
            strcpy(hotel->rooms[i].name, name);
            strcpy(hotel->rooms[i].phone, phone);
            hotel->rooms[i].isOccupied = 1;
            printf("\nRoom %d booked for %s (%s)", i+1, name, phone);
            break;
        }
    }

    if(i == MAX_ROOMS) {
        printf("\nSorry, all rooms are occupied!\n");
    }
}