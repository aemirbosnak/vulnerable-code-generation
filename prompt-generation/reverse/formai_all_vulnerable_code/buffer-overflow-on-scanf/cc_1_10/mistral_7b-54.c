//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room structure definition
typedef struct {
    int room_number;
    char status;
    float price_per_night;
} Room;

// Hotel structure definition
typedef struct {
    int num_rooms;
    Room rooms[100];
} Hotel;

// Function prototypes
void initialize_hotel(Hotel *hotel);
void display_rooms(Hotel hotel);
void book_room(Hotel *hotel, int room_number);

int main() {
    Hotel my_hotel;
    int choice, room_number;

    initialize_hotel(&my_hotel);

    while (1) {
        printf("\n**** Welcome to our Hotel Management System ****\n");
        printf("\n1. Display Available Rooms\n");
        printf("\n2. Book a Room\n");
        printf("\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_rooms(my_hotel);
                break;
            case 2:
                printf("Enter the room number you'd like to book: ");
                scanf("%d", &room_number);
                book_room(&my_hotel, room_number);
                break;
            case 3:
                printf("Thank you for using our Hotel Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Initialize hotel function
void initialize_hotel(Hotel *hotel) {
    int i;

    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &hotel->num_rooms);

    for (i = 0; i < hotel->num_rooms; i++) {
        hotel->rooms[i].room_number = i + 1;
        hotel->rooms[i].status = 'V'; // Available
        hotel->rooms[i].price_per_night = 50.0;
    }
}

// Display rooms function
void display_rooms(Hotel hotel) {
    int i;

    printf("\n**** Available Rooms ****\n");

    for (i = 0; i < hotel.num_rooms; i++) {
        if (hotel.rooms[i].status == 'V') {
            printf("\nRoom %d: Available - $%.2f per night", hotel.rooms[i].room_number, hotel.rooms[i].price_per_night);
        }
    }
}

// Book room function
void book_room(Hotel *hotel, int room_number) {
    int i;

    for (i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].room_number == room_number && hotel->rooms[i].status == 'V') {
            hotel->rooms[i].status = 'B'; // Booked
            printf("\nRoom %d has been booked successfully.\n", room_number);
            break;
        }
    }

    if (i == hotel->num_rooms) {
        printf("\nRoom %d is not available.\n", room_number);
    }
}