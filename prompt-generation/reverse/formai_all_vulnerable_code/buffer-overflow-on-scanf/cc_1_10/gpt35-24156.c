//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50
#define MAX_STAYS_PER_ROOM 365

// Define Structs
struct Stay {
    char customer_name[MAX_NAME_LENGTH];
    int days;
};

struct Room {
    int room_number;
    int stays_count;
    struct Stay stays[MAX_STAYS_PER_ROOM];
};

// Global Variables
struct Room hotel_rooms[MAX_ROOMS];
int num_rooms = 0;

// Function Prototypes
void add_room();
void add_stay();
void view_all_stays();
void view_room_stays();
int get_room_index(int room_number);

// Main Function
int main() {
    int user_choice;

    do {
        // Print Menu Options
        printf("Please choose an option:\n");
        printf("1. Add Room\n");
        printf("2. Add Stay\n");
        printf("3. View All Stays\n");
        printf("4. View Room Stays\n");
        printf("5. Exit\n");

        // Get User Choice
        scanf("%d", &user_choice);

        // Handle User Choice
        switch(user_choice) {
            case 1:
                add_room();
                break;
            case 2:
                add_stay();
                break;
            case 3:
                view_all_stays();
                break;
            case 4:
                view_room_stays();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice. Please Try Again.\n");
                break;
        }
    } while (user_choice != 5);

    return 0;
}

// Add Room Function
void add_room() {
    // Check if Max Rooms Already Reached
    if (num_rooms == MAX_ROOMS) {
        printf("Cannot Add Room - Max Rooms Reached\n");
        return;
    }

    // Get Room Number
    int room_number;
    printf("Enter Room Number: ");
    scanf("%d", &room_number);

    // Check if Room Already Exists
    if (get_room_index(room_number) != -1) {
        printf("Room Already Exists\n");
        return;
    }

    // Add Room
    hotel_rooms[num_rooms].room_number = room_number;
    hotel_rooms[num_rooms].stays_count = 0;
    num_rooms++;

    printf("Room Added Successfully\n");
}

// Add Stay Function
void add_stay() {
    // Get Room Number
    int room_number;
    printf("Enter Room Number: ");
    scanf("%d", &room_number);

    // Check if Room Exists
    int room_index = get_room_index(room_number);
    if (room_index == -1) {
        printf("Room Does Not Exist\n");
        return;
    }

    // Check if Room Has Max Stays
    if (hotel_rooms[room_index].stays_count == MAX_STAYS_PER_ROOM) {
        printf("Cannot Add Stay - Max Stays Reached\n");
        return;
    }

    // Get Customer Name
    char customer_name[MAX_NAME_LENGTH];
    printf("Enter Customer Name: ");
    scanf("%s", customer_name);

    // Get Days Staying
    int days;
    printf("Enter Days Staying: ");
    scanf("%d", &days);

    // Add Stay
    strcpy(hotel_rooms[room_index].stays[hotel_rooms[room_index].stays_count].customer_name, customer_name);
    hotel_rooms[room_index].stays[hotel_rooms[room_index].stays_count].days = days;
    hotel_rooms[room_index].stays_count++;

    printf("Stay Added Successfully\n");
}

// View All Stays Function
void view_all_stays() {
    // Print Table Header
    printf("%-15s %-15s %-15s\n", "Room Number", "Customer Name", "Days Staying");
    printf("--------------------------------------------------\n");

    // Print Stays
    for (int i = 0; i < num_rooms; i++) {
        for (int j = 0; j < hotel_rooms[i].stays_count; j++) {
            printf("%-15d %-15s %-15d\n", hotel_rooms[i].room_number, hotel_rooms[i].stays[j].customer_name, hotel_rooms[i].stays[j].days);
        }
    }
}

// View Room Stays Function
void view_room_stays() {
    // Get Room Number
    int room_number;
    printf("Enter Room Number: ");
    scanf("%d", &room_number);

    // Check if Room Exists
    int room_index = get_room_index(room_number);
    if (room_index == -1) {
        printf("Room Does Not Exist\n");
        return;
    }

    // Print Table Header
    printf("%-15s %-15s\n", "Customer Name", "Days Staying");
    printf("------------------------\n");

    // Print Room Stays
    for (int i = 0; i < hotel_rooms[room_index].stays_count; i++) {
        printf("%-15s %-15d\n", hotel_rooms[room_index].stays[i].customer_name, hotel_rooms[room_index].stays[i].days);
    }
}

// Get Room Index Function
int get_room_index(int room_number) {
    for (int i = 0; i < num_rooms; i++) {
        if (hotel_rooms[i].room_number == room_number) {
            return i;
        }
    }
    return -1;
}