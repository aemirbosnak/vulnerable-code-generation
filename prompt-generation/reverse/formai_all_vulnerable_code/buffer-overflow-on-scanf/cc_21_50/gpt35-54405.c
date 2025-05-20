//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for hotel guests
struct Guest {
    char name[50];
    int age;
    char address[100];
    int room_number;
    int days_staying;
};

// Define a struct for hotel rooms
struct Room {
    int room_number;
    int price_per_day;
    int max_occupancy;
};

// Main function
int main() {
    int choice;
    int guest_count = 0;
    int room_count = 0;
    struct Guest guests[50]; // Maximum of 50 guests
    struct Room rooms[20]; // Maximum of 20 rooms

    printf("Welcome to the C Hotel Management System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a guest\n");
        printf("2. Add a room\n");
        printf("3. Check in a guest\n");
        printf("4. Check out a guest\n");
        printf("5. List all guests\n");
        printf("6. List all rooms\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // Add a guest
            case 1:
                printf("\nEnter guest name: ");
                scanf("%s", guests[guest_count].name);
                printf("Enter guest age: ");
                scanf("%d", &guests[guest_count].age);
                printf("Enter guest address: ");
                scanf("%s", guests[guest_count].address);
                guest_count++;
                printf("\nGuest added successfully!\n");
                break;

                // Add a room
            case 2:
                printf("\nEnter room number: ");
                scanf("%d", &rooms[room_count].room_number);
                printf("Enter price per day: ");
                scanf("%d", &rooms[room_count].price_per_day);
                printf("Enter max occupancy: ");
                scanf("%d", &rooms[room_count].max_occupancy);
                room_count++;
                printf("\nRoom added successfully!\n");
                break;

                // Check in a guest
            case 3: {
                int found = 0;
                int room_number;
                printf("\nEnter room number: ");
                scanf("%d", &room_number);
                for (int i = 0; i < guest_count; i++) {
                    if (guests[i].room_number == room_number) {
                        printf("Guest already checked in to this room!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    int found_room = 0;
                    for (int i = 0; i < room_count; i++) {
                        if (rooms[i].room_number == room_number) {
                            if (rooms[i].max_occupancy == 0) {
                                printf("Room is already occupied!\n");
                                found_room = 1;
                                break;
                            } else {
                                guests[guest_count].room_number = room_number;
                                printf("\nEnter number of days staying: ");
                                scanf("%d", &guests[guest_count].days_staying);
                                rooms[i].max_occupancy--;
                                guest_count++;
                                printf("\nGuest checked in successfully!\n");
                                found_room = 1;
                                break;
                            }
                        }
                    }
                    if (!found_room) {
                        printf("Room not found!\n");
                    }
                }
                break;
            }

                // Check out a guest
            case 4: {
                int found = 0;
                int room_number;
                printf("\nEnter room number: ");
                scanf("%d", &room_number);
                for (int i = 0; i < guest_count; i++) {
                    if (guests[i].room_number == room_number) {
                        for (int j = i; j < guest_count - 1; j++) {
                            guests[j] = guests[j + 1];
                        }
                        guest_count--;
                        for (int j = 0; j < room_count; j++) {
                            if (rooms[j].room_number == room_number) {
                                rooms[j].max_occupancy++;
                                break;
                            }
                        }
                        printf("\nGuest checked out successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Guest not found!\n");
                }
                break;
            }

                // List all guests
            case 5:
                printf("\nAll guests:\n");
                for (int i = 0; i < guest_count; i++) {
                    printf("---------------------------\n");
                    printf("Name: %s\n", guests[i].name);
                    printf("Age: %d\n", guests[i].age);
                    printf("Address: %s\n", guests[i].address);
                    printf("Room number: %d\n", guests[i].room_number);
                    printf("Days staying: %d\n", guests[i].days_staying);
                    printf("---------------------------\n");
                }
                break;

                // List all rooms
            case 6:
                printf("\nAll rooms:\n");
                for (int i = 0; i < room_count; i++) {
                    printf("---------------------------\n");
                    printf("Room number: %d\n", rooms[i].room_number);
                    printf("Price per day: %d\n", rooms[i].price_per_day);
                    printf("Max occupancy: %d\n", rooms[i].max_occupancy);
                    printf("---------------------------\n");
                }
                break;

                // Quit the program
            case 7:
                printf("\nExiting program...");
                exit(0);

                // Invalid choice
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}