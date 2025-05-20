//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: energetic
// Welcome to the C Hotel Management System, a sanctuary for the weary and a haven for the discerning.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our hotel's luxurious amenities.
typedef struct {
    int room_number;
    char room_type[20];
    int capacity;
    float price_per_night;
    int is_occupied;
} Room;

// Initialize our grand hotel with an array of rooms fit for royalty.
Room rooms[] = {
    {101, "Single", 1, 50.0, 0},
    {102, "Double", 2, 75.0, 0},
    {103, "Suite", 4, 150.0, 0},
    {104, "Penthouse", 6, 250.0, 0},
    {105, "Presidential Suite", 8, 500.0, 0}
};

// Let's define the maximum number of rooms our hotel can accommodate.
#define NUM_ROOMS 5

// Declare our trusty receptionists, always ready to assist our valued guests.
typedef struct {
    char name[20];
    int employee_id;
} Receptionist;

// Meet our friendly receptionists, eager to serve with a smile.
Receptionist receptionists[] = {
    {"Alice", 1},
    {"Bob", 2}
};

// Let's keep track of the number of receptionists we have.
#define NUM_RECEPTIONISTS 2

// A warm welcome to our guests! Let's check them in with ease.
void check_in(Room *room, Receptionist *receptionist) {
    printf("Welcome, esteemed guest! Please provide your details:\n");
    room->is_occupied = 1;
    printf("Room number: %d\n", room->room_number);
    printf("Guest name: ");
    scanf("%s", room->room_type);
    printf("Number of guests: ");
    scanf("%d", &room->capacity);
    printf("Check-in date: ");
    scanf("%s", room->price_per_night);
    printf("Check-out date: ");
    scanf("%s", room->is_occupied);
    printf("\n");

    printf("Welcome aboard, %s! Receptionist %s is here to assist you during your stay.\n", room->room_type, receptionist->name);
}

// Time for our guests to bid farewell. Let's check them out efficiently.
void check_out(Room *room) {
    printf("Thank you for choosing our hotel, %s! We hope you had a memorable stay.\n", room->room_type);
    room->is_occupied = 0;
    printf("Room %d is now vacant and ready for our next guests.\n", room->room_number);
}

// Let's display our hotel's grandeur to our potential guests.
void display_rooms() {
    printf("Behold, our exquisite chambers:\n");
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d: %s, capacity: %d, price per night: $%.2f\n",
               rooms[i].room_number, rooms[i].room_type, rooms[i].capacity, rooms[i].price_per_night);
    }
}

// Empower our guests with the ability to make reservations at their convenience.
void make_reservation(Room *room) {
    printf("Planning your dream getaway? Let us help you secure your room:\n");
    printf("Room number: ");
    scanf("%d", &room->room_number);
    printf("Check-in date: ");
    scanf("%s", room->price_per_night);
    printf("Check-out date: ");
    scanf("%s", room->is_occupied);
    printf("Reservation confirmed! We eagerly await your arrival.\n");
}

// A grand finale to our hotel management symphony.
int main() {
    // Let the show begin! Welcome our guests with open arms.
    printf("Step into the lap of luxury, dear guests! Welcome to our grand hotel.\n");

    // Display our hotel's opulent offerings to entice our discerning clientele.
    display_rooms();

    // Empower our guests with the ability to check in and out with ease.
    int choice;
    do {
        printf("At your service, dear guest! How may we assist you today?\n");
        printf("1. Check in\n");
        printf("2. Check out\n");
        printf("3. Make a reservation\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_in(&rooms[0], &receptionists[0]);
                break;
            case 2:
                check_out(&rooms[0]);
                break;
            case 3:
                make_reservation(&rooms[0]);
                break;
            case 4:
                printf("Thank you for choosing our hotel! We bid you farewell and hope to welcome you back soon.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option from the menu.\n");
        }
    } while (choice != 4);

    // As the curtains fall, let's bid farewell to our guests and leave them with lasting memories.
    printf("Thank you for staying with us! We strive to make every moment a treasured experience for our valued guests.\n");
    return 0;
}