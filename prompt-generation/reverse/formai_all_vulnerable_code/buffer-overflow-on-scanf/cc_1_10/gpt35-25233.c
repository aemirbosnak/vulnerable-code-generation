//FormAI DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <string.h>

// Define constants for max room capacity and max number of guests
#define MAX_CAPACITY 100
#define MAX_GUESTS 5000

// Define a struct for a Room
struct Room {
    int number;
    char type[20];
    int capacity;
    float price;
    int guests[MAX_GUESTS];
    int num_guests;
    int availability;
};

// Define a struct for a Guest
struct Guest {
    char name[50];
    char phone[20];
    char email[50];
    int room_number;
};

// Declare functions
void add_guest(struct Guest guests[], int num_guests, int room_number);
void remove_guest(struct Guest guests[], int num_guests, int room_number);
void display_guest_details(struct Guest guests[], int num_guests, int room_number);
void display_all_guests(struct Guest guests[], int num_guests);
void display_room_details(struct Room rooms[], int num_rooms, int room_number);
void display_all_rooms(struct Room rooms[], int num_rooms);
void book_room(struct Room rooms[], int num_rooms);
void checkout_room(struct Room rooms[], int num_rooms);

int main() {
    // Create an array of rooms
    struct Room rooms[MAX_CAPACITY];
    int num_rooms = 0;
    
    // Create an array of guests
    struct Guest guests[MAX_GUESTS];
    int num_guests = 0;
    
    // Display menu options
    int choice;
    do {
        printf("\n");
        printf("1. Add room\n");
        printf("2. Add guest\n");
        printf("3. Remove guest\n");
        printf("4. Display guest details\n");
        printf("5. Display all guests\n");
        printf("6. Display room details\n");
        printf("7. Display all rooms\n");
        printf("8. Book a room\n");
        printf("9. Checkout a room\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Perform action based on user's choice
        switch (choice) {
            case 1: // Add room
                if (num_rooms >= MAX_CAPACITY) {
                    printf("Maximum room capacity reached!\n");
                } else {
                    struct Room new_room;
                    printf("Enter room number: ");
                    scanf("%d", &new_room.number);
                    printf("Enter room type: ");
                    scanf("%s", new_room.type);
                    printf("Enter room capacity: ");
                    scanf("%d", &new_room.capacity);
                    printf("Enter room price: ");
                    scanf("%f", &new_room.price);
                    new_room.num_guests = 0;
                    new_room.availability = 1;
                    rooms[num_rooms] = new_room;
                    num_rooms++;
                    printf("Room added successfully!\n");
                }
                break;
            case 2: // Add guest
                if (num_guests >= MAX_GUESTS) {
                    printf("Maximum number of guests reached!\n");
                } else {
                    int room_number;
                    printf("Enter room number: ");
                    scanf("%d", &room_number);
                    add_guest(guests, num_guests, room_number);
                    num_guests++;
                }
                break;
            case 3: // Remove guest
                if (num_guests == 0) {
                    printf("There are no guests to remove!\n");
                } else {
                    int room_number;
                    printf("Enter room number: ");
                    scanf("%d", &room_number);
                    remove_guest(guests, num_guests, room_number);
                    num_guests--;
                }
                break;
            case 4: // Display guest details
                if (num_guests == 0) {
                    printf("There are no guests to display!\n");
                } else {
                    int room_number;
                    printf("Enter room number: ");
                    scanf("%d", &room_number);
                    display_guest_details(guests, num_guests, room_number);
                }
                break;
            case 5: // Display all guests
                if (num_guests == 0) {
                    printf("There are no guests to display!\n");
                } else {
                    display_all_guests(guests, num_guests);
                }
                break;
            case 6: // Display room details
                if (num_rooms == 0) {
                    printf("There are no rooms to display!\n");
                } else {
                    int room_number;
                    printf("Enter room number: ");
                    scanf("%d", &room_number);
                    display_room_details(rooms, num_rooms, room_number);
                }
                break;
            case 7: // Display all rooms
                if (num_rooms == 0) {
                    printf("There are no rooms to display!\n");
                } else {
                    display_all_rooms(rooms, num_rooms);
                }
                break;
            case 8: // Book a room
                if (num_rooms == 0) {
                    printf("There are no rooms to book!\n");
                } else {
                    book_room(rooms, num_rooms);
                }
                break;
            case 9: // Checkout a room
                if (num_rooms == 0) {
                    printf("There are no rooms to checkout!\n");
                } else {
                    checkout_room(rooms, num_rooms);
                }
                break;
            case 0: // Exit
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}

// Add a guest to a room
void add_guest(struct Guest guests[], int num_guests, int room_number) {
    int i;
    for (i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("Room already booked!\n");
            return;
        }
    }
    for (i = 0; i < MAX_CAPACITY; i++) {
        if (guests[i].room_number == 0) {
            struct Guest new_guest;
            printf("Enter guest name: ");
            scanf("%s", new_guest.name);
            printf("Enter guest phone: ");
            scanf("%s", new_guest.phone);
            printf("Enter guest email: ");
            scanf("%s", new_guest.email);
            new_guest.room_number = room_number;
            guests[i] = new_guest;
            printf("Guest added successfully!\n");
            return;
        }
    }
    printf("Maximum number of guests reached!\n");
}

// Remove a guest from a room
void remove_guest(struct Guest guests[], int num_guests, int room_number) {
    int i;
    for (i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            guests[i].room_number = 0;
            printf("Guest removed successfully!\n");
            return;
        }
    }
    printf("No guest found with that room number!\n");
}

// Display details of a guest in a room
void display_guest_details(struct Guest guests[], int num_guests, int room_number) {
    int i;
    for (i = 0; i < num_guests; i++) {
        if (guests[i].room_number == room_number) {
            printf("Guest name: %s\n", guests[i].name);
            printf("Guest phone: %s\n", guests[i].phone);
            printf("Guest email: %s\n", guests[i].email);
            return;
        }
    }
    printf("No guest found with that room number!\n");
}

// Display details of all guests in the hotel
void display_all_guests(struct Guest guests[], int num_guests) {
    int i;
    for (i = 0; i < num_guests; i++) {
        printf("Guest name: %s\n", guests[i].name);
        printf("Guest phone: %s\n", guests[i].phone);
        printf("Guest email: %s\n", guests[i].email);
        printf("Guest room number: %d\n", guests[i].room_number);
    }
}

// Display details of a room
void display_room_details(struct Room rooms[], int num_rooms, int room_number) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].number == room_number) {
            printf("Room number: %d\n", rooms[i].number);
            printf("Room type: %s\n", rooms[i].type);
            printf("Room capacity: %d\n", rooms[i].capacity);
            printf("Room price: %.2f\n", rooms[i].price);
            printf("Room availability: %d\n", rooms[i].availability);
            printf("Guests in room: ");
            int j;
            for (j = 0; j < rooms[i].num_guests; j++) {
                printf("%d ", rooms[i].guests[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("No room found with that number!\n");
}

// Display details of all rooms in the hotel
void display_all_rooms(struct Room rooms[], int num_rooms) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        printf("Room number: %d\n", rooms[i].number);
        printf("Room type: %s\n", rooms[i].type);
        printf("Room capacity: %d\n", rooms[i].capacity);
        printf("Room price: %.2f\n", rooms[i].price);
        printf("Room availability: %d\n", rooms[i].availability);
        printf("Guests in room: ");
        int j;
        for (j = 0; j < rooms[i].num_guests; j++) {
            printf("%d ", rooms[i].guests[j]);
        }
        printf("\n");
    }
}

// Book a room for a guest
void book_room(struct Room rooms[], int num_rooms) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].availability == 1) {
            int room_number = rooms[i].number;
            printf("Enter guest name: ");
            char guest_name[50];
            scanf("%s", guest_name);
            printf("Enter guest phone: ");
            char guest_phone[20];
            scanf("%s", guest_phone);
            printf("Enter guest email: ");
            char guest_email[50];
            scanf("%s", guest_email);
            struct Guest new_guest = {guest_name, guest_phone, guest_email, room_number};
            rooms[i].guests[0] = room_number;
            rooms[i].num_guests = 1;
            rooms[i].availability = 0;
            printf("Room booked successfully!\n");
            return;
        }
    }
    printf("All rooms are currently booked!\n");
}

// Checkout a room and remove the guest
void checkout_room(struct Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter room number: ");
    scanf("%d", &room_number);
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].number == room_number) {
            rooms[i].num_guests = 0;
            rooms[i].availability = 1;
            printf("Guest checkout successful!\n");
            return;
        }
    }
    printf("No room found with that number!\n");
}