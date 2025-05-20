//FormAI DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include<stdio.h>
#include<string.h>

// Structure for storing Reservation Details
struct Reservation {
    char name[50];
    char room_type[20];
    int num_guests;
    int num_nights;
    float cost;
};

// Structure for storing Room Details
struct Room {
    char room_type[20];
    int num_available;
    float cost_per_night;
};

// Function to display Room Details
void display_rooms(struct Room rooms[], int num_rooms) {
    printf("\n--------------------------------------------------------\n");
    printf("| %-15s | %-15s | %-15s |\n", "Room Type", "Available Rooms", "Cost per Night");
    printf("--------------------------------------------------------\n");
    for(int i=0; i<num_rooms; i++) {
        printf("| %-15s | %-15d | %-15.2f |\n", rooms[i].room_type, rooms[i].num_available, rooms[i].cost_per_night);
    }
    printf("--------------------------------------------------------\n");
}

// Function to make Reservation
void make_reservation(struct Room rooms[], int num_rooms, struct Reservation reservations[], int *num_reservations) {
    char room_type[20];
    int num_guests, num_nights, room_index=-1;
    float cost;
    struct Reservation reservation;
    printf("\nEnter your name: ");
    scanf("%s", reservation.name);
    printf("\nEnter number of guests: ");
    scanf("%d", &reservation.num_guests);
    printf("\nEnter number of nights: ");
    scanf("%d", &reservation.num_nights);
    printf("\nEnter room type (Standard/Deluxe/Suite): ");
    scanf("%s", room_type);
    for(int i=0; i<num_rooms; i++) {
        if(strcmp(rooms[i].room_type, room_type) == 0 && rooms[i].num_available > 0) {
            room_index = i;
            rooms[i].num_available--;
            cost = reservations[*num_reservations].num_nights * rooms[i].cost_per_night;
            break;
        }
    }
    if(room_index == -1) {
        printf("\nSorry, %s rooms are not available.\n", room_type);
    } else {
        reservation.cost = cost;
        strcpy(reservation.room_type, room_type);
        reservations[*num_reservations] = reservation;
        (*num_reservations)++;
        printf("\nYour reservation has been successfully made.\n");
    }
}

// Function to display Reservation Details
void display_reservations(struct Reservation reservations[], int num_reservations) {
    printf("\n------------------------------------------------------------------------\n");
    printf("| %-30s | %-20s | %-15s | %-10s |\n", "Name", "Room Type", "Number of Nights", "Cost");
    printf("------------------------------------------------------------------------\n");
    for(int i=0; i<num_reservations; i++) {
        printf("| %-30s | %-20s | %-15d | %-10.2f |\n", reservations[i].name, reservations[i].room_type, reservations[i].num_nights, reservations[i].cost);
    }
    printf("------------------------------------------------------------------------\n");
}

// Function to cancel Reservation
void cancel_reservation(struct Room rooms[], int num_rooms, struct Reservation reservations[], int *num_reservations) {
    char name[50];
    int reservation_index=-1;
    printf("\nEnter your name: ");
    scanf("%s", name);
    for(int i=0; i<*num_reservations; i++) {
        if(strcmp(reservations[i].name, name) == 0) {
            reservation_index = i;
            for(int j=0; j<num_rooms; j++) {
                if(strcmp(rooms[j].room_type, reservations[i].room_type) == 0) {
                    rooms[j].num_available++;
                    break;
                }
            }
            break;
        }
    }
    if(reservation_index == -1) {
        printf("\nSorry, no reservation found under %s.\n", name);
    } else {
        for(int i=reservation_index+1; i<*num_reservations; i++) {
            reservations[i-1] = reservations[i];
        }
        (*num_reservations)--;
        printf("\nYour reservation has been successfully cancelled.\n");
    }
}

// Function to display available options
void display_options() {
    printf("\n*************************************************************\n");
    printf("                            OPTIONS\n");
    printf("*************************************************************\n");
    printf("1. Display Available Rooms\n");
    printf("2. Make a Reservation\n");
    printf("3. Display Reservations\n");
    printf("4. Cancel a Reservation\n");
    printf("5. Exit\n");
}

int main() {
    int num_rooms = 3;
    int num_reservations = 0;
    struct Room rooms[3] = {{"Standard", 5, 1000.00}, {"Deluxe", 3, 1500.00}, {"Suite", 2, 2200.00}};
    struct Reservation reservations[10];

    printf("\n*************************************************************\n");
    printf("               C HOTEL MANAGEMENT SYSTEM\n");
    printf("*************************************************************\n");

    int option;
    do {
        display_options();
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                display_rooms(rooms, num_rooms);
                break;
            case 2:
                make_reservation(rooms, num_rooms, reservations, &num_reservations);
                break;
            case 3:
                display_reservations(reservations, num_reservations);
                break;
            case 4:
                cancel_reservation(rooms, num_rooms, reservations, &num_reservations);
                break;
            case 5:
                printf("\nThank you for using C Hotel Management System!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while(option != 5);
    return 0;
}