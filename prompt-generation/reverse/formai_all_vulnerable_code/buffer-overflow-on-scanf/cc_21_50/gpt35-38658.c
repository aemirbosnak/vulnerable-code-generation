//FormAI DATASET v1.0 Category: Hotel Management System ; Style: grateful
// This program is a unique and amazing Hotel Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int age;
    char city[30];
    int room_number;
};

struct room {
    int room_number;
    int capacity;
    int availability;
    float price;
};

struct booking {
    char name[50];
    int room_number;
    int days;
    float total_price;
};

struct guest guests[100];
struct room rooms[50];
struct booking bookings[100];

int main() {
    int guest_count = 0;
    int room_count = 0;
    int booking_count = 0;
    int choice;

    while (1) {
        printf("\n\nWelcome to our Hotel Management System!\n");
        printf("\n1. Manage Guests");
        printf("\n2. Manage Rooms");
        printf("\n3. Book Room");
        printf("\n4. Check Out");
        printf("\n5. View Bookings");
        printf("\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: // Manage Guests Menu
                printf("\n\n1. Add a Guest");
                printf("\n2. Edit a Guest");
                printf("\n3. Delete a Guest");
                printf("\n4. View All Guests");
                printf("\n5. Exit\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: // Adding Guest
                        printf("\nEnter Guest Name: ");
                        scanf("%s", guests[guest_count].name);
                        printf("Enter Guest Age: ");
                        scanf("%d", &guests[guest_count].age);
                        printf("Enter Guest City: ");
                        scanf("%s", guests[guest_count].city);
                        printf("Guest added successfully!\n");
                        guest_count++;
                    break;

                    case 2: // Editing Guest
                        printf("\nEnter Guest Name: ");
                        scanf("%s", guests[guest_count].name);
                        for (int i = 0; i < guest_count; i++) {
                            if (strcmp(guests[i].name, guests[guest_count].name) == 0) {
                                printf("Enter New Name: ");
                                scanf("%s", guests[i].name);
                                printf("Enter New Age: ");
                                scanf("%d", &guests[i].age);
                                printf("Enter New City: ");
                                scanf("%s", guests[i].city);
                                printf("Guest edited successfully!\n");
                                break;
                            }
                        }
                    break;

                    case 3: // Deleting Guest
                        printf("\nEnter Guest Name: ");
                        scanf("%s", guests[guest_count].name);
                        for (int i = 0; i < guest_count; i++) {
                            if (strcmp(guests[i].name, guests[guest_count].name) == 0) {
                                memset(&guests[i], 0, sizeof(guests[i]));
                                printf("Guest deleted successfully!\n");
                                break;
                            }
                        }
                    break;

                    case 4: // Viewing All Guests
                        printf("\nAll Guests:\n");
                        for (int i = 0; i < guest_count; i++) {
                            printf("%d. Name: %s, Age: %d, City: %s\n", i+1, guests[i].name, guests[i].age, guests[i].city);
                        }
                    break;

                    case 5: // Exit Guests Menu
                        continue;
                    break;

                    default:
                        printf("\nInvalid choice! Please choose again.\n");
                    break;
                }

            break;

            case 2: // Manage Rooms Menu
                printf("\n\n1. Add a Room");
                printf("\n2. Edit a Room");
                printf("\n3. Delete a Room");
                printf("\n4. View All Rooms");
                printf("\n5. Exit\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: // Adding Room
                        printf("\nEnter Room Number: ");
                        scanf("%d", &rooms[room_count].room_number);
                        printf("Enter Room Capacity: ");
                        scanf("%d", &rooms[room_count].capacity);
                        printf("Enter Room Price: $");
                        scanf("%f", &rooms[room_count].price);
                        rooms[room_count].availability = 1;
                        printf("Room added successfully!\n");
                        room_count++;
                    break;

                    case 2: // Editing Room
                        printf("\nEnter Room Number: ");
                        scanf("%d", &rooms[room_count].room_number);
                        for (int i = 0; i < room_count; i++) {
                            if (rooms[i].room_number == rooms[room_count].room_number) {
                                printf("Enter New Room Number: ");
                                scanf("%d", &rooms[i].room_number);
                                printf("Enter New Room Capacity: ");
                                scanf("%d", &rooms[i].capacity);
                                printf("Enter New Room Price: $");
                                scanf("%f", &rooms[i].price);
                                printf("Room edited successfully!\n");
                                break;
                            }
                        }
                    break;

                    case 3: // Deleting Room
                        printf("\nEnter Room Number: ");
                        scanf("%d", &rooms[room_count].room_number);
                        for (int i = 0; i < room_count; i++) {
                            if (rooms[i].room_number == rooms[room_count].room_number) {
                                memset(&rooms[i], 0, sizeof(rooms[i]));
                                printf("Room deleted successfully!\n");
                                break;
                            }
                        }
                    break;

                    case 4: // Viewing All Rooms
                        printf("\nAll Rooms:\n");
                        for (int i = 0; i < room_count; i++) {
                            printf("%d. Room Number: %d, Capacity: %d, Price: $%.2f, Status: %s\n", i+1, rooms[i].room_number, rooms[i].capacity, rooms[i].price, rooms[i].availability == 1 ? "Available" : "Unavailable");
                        }
                    break;

                    case 5: // Exit Rooms Menu
                        continue;
                    break;

                    default:
                        printf("\nInvalid choice! Please choose again.\n");
                    break;
                }

            break;

            case 3: // Booking Room
                printf("\nEnter Guest Name: ");
                scanf("%s", bookings[booking_count].name);
                printf("Available Rooms:\n");
                for (int i = 0; i < room_count; i++) {
                    if (rooms[i].availability == 1) {
                        printf("%d. Room Number: %d, Capacity: %d, Price: $%.2f\n", i+1, rooms[i].room_number, rooms[i].capacity, rooms[i].price);
                    }
                }
                printf("Enter Room Number: ");
                scanf("%d", &bookings[booking_count].room_number);
                printf("Enter Number of Days to Stay: ");
                scanf("%d", &bookings[booking_count].days);
                for (int i = 0; i < room_count; i++) {
                    if (rooms[i].room_number == bookings[booking_count].room_number) {
                        rooms[i].availability = 0;
                        bookings[booking_count].total_price = rooms[i].price * bookings[booking_count].days;
                        printf("Room booked successfully!\n");
                        booking_count++;
                        break;
                    }
                }
            break;

            case 4: // Check Out
                printf("\nEnter Guest Name: ");
                scanf("%s", guests[guest_count].name);
                for (int i = 0; i < booking_count; i++) {
                    if (strcmp(bookings[i].name, guests[guest_count].name) == 0) {
                        for (int j = 0; j < room_count; j++) {
                            if (rooms[j].room_number == bookings[i].room_number) {
                                rooms[j].availability = 1;
                                memset(&bookings[i], 0, sizeof(bookings[i]));
                                printf("Guest checked out successfully!\n");
                                break;
                            }
                        }
                        break;
                    }
                }
            break;

            case 5: // View Bookings
                printf("\nAll Bookings:\n");
                for (int i = 0; i < booking_count; i++) {
                    printf("%d. Guest Name: %s, Room Number: %d, Days: %d, Total Price: $%.2f\n", i+1, bookings[i].name, bookings[i].room_number, bookings[i].days, bookings[i].total_price);
                }
            break;

            case 6: // Exit Program
                printf("\nThank you for using our Hotel Management System!\n");
                exit(0);
            break;

            default:
                printf("\nInvalid choice! Please choose again.\n");

        }
    }

    return 0;
}