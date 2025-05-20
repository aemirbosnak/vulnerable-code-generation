//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct hotel_room {
    int room_number;
    int beds;
    int price;
} hotel_room;

typedef struct hotel_management_system {
    int num_rooms;
    hotel_room rooms[100];
} hotel_management_system;

int main() {
    hotel_management_system hms;
    int choice;
    int room_number, beds, price;

    // Initialize the hotel management system
    hms.num_rooms = 0;

    // Loop until the user chooses to quit
    do {
        printf("1. Add Room\n");
        printf("2. Remove Room\n");
        printf("3. Display Room Information\n");
        printf("4. Display Room Availability\n");
        printf("5. Update Room Price\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Room
                printf("Enter room number: ");
                scanf("%d", &room_number);
                printf("Enter number of beds: ");
                scanf("%d", &beds);
                printf("Enter price: ");
                scanf("%d", &price);
                hms.rooms[hms.num_rooms].room_number = room_number;
                hms.rooms[hms.num_rooms].beds = beds;
                hms.rooms[hms.num_rooms].price = price;
                hms.num_rooms++;
                break;
            case 2: // Remove Room
                printf("Enter room number to remove: ");
                scanf("%d", &room_number);
                for (int i = 0; i < hms.num_rooms; i++) {
                    if (hms.rooms[i].room_number == room_number) {
                        for (int j = i; j < hms.num_rooms - 1; j++) {
                            hms.rooms[j] = hms.rooms[j + 1];
                        }
                        hms.num_rooms--;
                        break;
                    }
                }
                break;
            case 3: // Display Room Information
                printf("Room Number\tBeds\tPrice\n");
                for (int i = 0; i < hms.num_rooms; i++) {
                    printf("%d\t%d\t%d\n", hms.rooms[i].room_number, hms.rooms[i].beds, hms.rooms[i].price);
                }
                break;
            case 4: // Display Room Availability
                printf("Room Number\tAvailable\n");
                for (int i = 0; i < hms.num_rooms; i++) {
                    if (hms.rooms[i].beds > 0) {
                        printf("%d\tYes\n", hms.rooms[i].room_number);
                    }
                }
                break;
            case 5: // Update Room Price
                printf("Enter room number to update price: ");
                scanf("%d", &room_number);
                printf("Enter new price: ");
                scanf("%d", &price);
                for (int i = 0; i < hms.num_rooms; i++) {
                    if (hms.rooms[i].room_number == room_number) {
                        hms.rooms[i].price = price;
                        break;
                    }
                }
                break;
            case 6: // Exit
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice!= 6);

    return 0;
}