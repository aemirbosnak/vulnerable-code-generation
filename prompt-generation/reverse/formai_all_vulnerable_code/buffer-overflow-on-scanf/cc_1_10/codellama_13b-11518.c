//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100

typedef struct {
    int room_id;
    int guest_count;
    char guest_names[MAX_GUESTS][30];
} Room;

typedef struct {
    int room_id;
    char room_type[20];
    int capacity;
    int occupied;
} RoomType;

RoomType room_types[MAX_ROOMS] = {
    {1, "Single", 1, 0},
    {2, "Double", 2, 0},
    {3, "Triple", 3, 0},
    {4, "Suite", 4, 0}
};

Room rooms[MAX_ROOMS];

int main() {
    int i, j;
    int choice;
    int room_id;
    char guest_name[30];

    printf("Welcome to our hotel management system!\n");

    while (1) {
        printf("1. Check Availability\n");
        printf("2. Book a Room\n");
        printf("3. Check-in a Guest\n");
        printf("4. Check-out a Guest\n");
        printf("5. View Guest List\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room type: ");
                scanf("%s", &room_types[i].room_type);
                printf("Enter room capacity: ");
                scanf("%d", &room_types[i].capacity);
                break;
            case 2:
                printf("Enter room type: ");
                scanf("%s", &room_types[i].room_type);
                printf("Enter room capacity: ");
                scanf("%d", &room_types[i].capacity);
                break;
            case 3:
                printf("Enter room ID: ");
                scanf("%d", &room_id);
                printf("Enter guest name: ");
                scanf("%s", &guest_name);
                break;
            case 4:
                printf("Enter room ID: ");
                scanf("%d", &room_id);
                break;
            case 5:
                printf("Enter room ID: ");
                scanf("%d", &room_id);
                break;
            case 6:
                return 0;
        }
    }

    return 0;
}