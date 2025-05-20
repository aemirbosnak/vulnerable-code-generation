//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare structs
struct guest {
    char name[50];
    int age;
    char address[50];
    char checkin_date[20];
    char checkout_date[20];
};

struct room {
    int room_number;
    char type[10];
    float price;
    int status; // 0 = vacant, 1 = occupied
    struct guest occupant;
};

// Declare global variables
int num_rooms;
struct room *rooms;

// Function prototypes
void initialize_rooms();
void print_menu();
void display_rooms();
void reserve_room();
void cancel_reservation();
void checkout();

int main() {
    int choice;

    // Get number of rooms from user
    printf("Enter number of rooms in hotel: ");
    scanf("%d", &num_rooms);

    // Allocate memory for rooms array
    rooms = (struct room*) malloc(num_rooms * sizeof(struct room));

    // Initialize rooms
    initialize_rooms();

    do {
        // Display menu
        print_menu();

        // Get user choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_rooms();
                break;
            case 2:
                reserve_room();
                break;
            case 3:
                cancel_reservation();
                break;
            case 4:
                checkout();
                break;
        }
    } while(choice != 5);

    free(rooms);
    return 0;
}

void initialize_rooms() {
    int i;

    for(i = 0; i < num_rooms; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].type, "Single");
        rooms[i].price = 50.0;
        rooms[i].status = 0;
    }
}

void print_menu() {
    printf("\n1. Display rooms\n");
    printf("2. Reserve room\n");
    printf("3. Cancel reservation\n");
    printf("4. Check out\n");
    printf("5. Quit\n");
}

void display_rooms() {
    int i;

    printf("\nRoom Number\tType\t\tPrice\t\tStatus\n");
    for(i = 0; i < num_rooms; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t", rooms[i].room_number, rooms[i].type, rooms[i].price);

        if(rooms[i].status == 0) {
            printf("Vacant\n");
        } else {
            printf("Occupied by %s\n", rooms[i].occupant.name);
        }
    }
}

void reserve_room() {
    int room_number, i;
    char name[50], address[50], checkin_date[20], checkout_date[20];
    int age;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    if(rooms[room_number - 1].status == 0) { // If room is vacant
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter address: ");
        scanf("%s", address);
        printf("Enter check-in date (dd/mm/yyyy): ");
        scanf("%s", checkin_date);
        printf("Enter check-out date (dd/mm/yyyy): ");
        scanf("%s", checkout_date);

        // Set guest details
        strcpy(rooms[room_number - 1].occupant.name, name);
        rooms[room_number - 1].occupant.age = age;
        strcpy(rooms[room_number - 1].occupant.address, address);
        strcpy(rooms[room_number - 1].occupant.checkin_date, checkin_date);
        strcpy(rooms[room_number - 1].occupant.checkout_date, checkout_date);

        // Set room status to occupied
        rooms[room_number - 1].status = 1;

        printf("Room reserved successfully!\n");
    } else { // If room is occupied
        printf("Room is already occupied!\n");
    }
}

void cancel_reservation() {
    int room_number;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    if(rooms[room_number - 1].status == 1) { // If room is occupied
        // Clear guest details
        strcpy(rooms[room_number - 1].occupant.name, "");
        rooms[room_number - 1].occupant.age = 0;
        strcpy(rooms[room_number - 1].occupant.address, "");
        strcpy(rooms[room_number - 1].occupant.checkin_date, "");
        strcpy(rooms[room_number - 1].occupant.checkout_date, "");

        // Set room status to vacant
        rooms[room_number - 1].status = 0;

        printf("Reservation cancelled successfully!\n");
    } else { // If room is vacant
        printf("Room is already vacant!\n");
    }
}

void checkout() {
    int room_number, i;
    float total_amount = 0;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    if(rooms[room_number - 1].status == 1) { // If room is occupied
        // Calculate total amount
        total_amount = (float) (atoi(rooms[room_number - 1].occupant.checkout_date) - atoi(rooms[room_number - 1].occupant.checkin_date)) * rooms[room_number - 1].price;

        // Clear guest details
        strcpy(rooms[room_number - 1].occupant.name, "");
        rooms[room_number - 1].occupant.age = 0;
        strcpy(rooms[room_number - 1].occupant.address, "");
        strcpy(rooms[room_number - 1].occupant.checkin_date, "");
        strcpy(rooms[room_number - 1].occupant.checkout_date, "");

        // Set room status to vacant
        rooms[room_number - 1].status = 0;

        printf("Check-out successful!\n");
        printf("Total amount: %.2f\n", total_amount);
    } else { // If room is vacant
        printf("Room is already vacant!\n");
    }
}