//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a room
typedef struct {
    char room_number[10];
    int available;
    int price;
} Room;

// Define a struct for a hotel
typedef struct {
    char hotel_name[50];
    int number_of_rooms;
    Room rooms[50];
} Hotel;

// Function to initialize a hotel
void initialize_hotel(Hotel *hotel, char hotel_name[]) {
    strcpy(hotel->hotel_name, hotel_name);
    hotel->number_of_rooms = 0;
    for (int i = 0; i < 50; i++) {
        hotel->rooms[i].available = 1;
        hotel->rooms[i].price = 0;
    }
}

// Function to check availability of a room
int check_availability(Hotel *hotel, char room_number[]) {
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(hotel->rooms[i].room_number, room_number) == 0 && hotel->rooms[i].available == 1) {
            hotel->rooms[i].available = 0;
            return 1;
        }
    }
    return 0;
}

// Function to book a room
void book_room(Hotel *hotel, char room_number[], int price) {
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(hotel->rooms[i].room_number, room_number) == 0 && hotel->rooms[i].available == 1) {
            hotel->rooms[i].available = 0;
            hotel->rooms[i].price = price;
            return;
        }
    }
    printf("Room not available.\n");
}

// Function to cancel a reservation
void cancel_reservation(Hotel *hotel, char room_number[]) {
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(hotel->rooms[i].room_number, room_number) == 0 && hotel->rooms[i].available == 1) {
            hotel->rooms[i].available = 1;
            return;
        }
    }
    printf("Room not reserved.\n");
}

// Function to display room details
void display_room(Hotel *hotel, char room_number[]) {
    int i;
    for (i = 0; i < 50; i++) {
        if (strcmp(hotel->rooms[i].room_number, room_number) == 0 && hotel->rooms[i].available == 1) {
            printf("Room %s is available and costs $%d.\n", hotel->rooms[i].room_number, hotel->rooms[i].price);
            return;
        }
    }
    printf("Room not available.\n");
}

// Main function
int main() {
    char hotel_name[50];
    printf("Enter the name of the hotel: ");
    scanf("%s", hotel_name);

    Hotel hotel;
    initialize_hotel(&hotel, hotel_name);

    char room_number[10];
    char command[50];
    do {
        printf("1. Check availability\n2. Book a room\n3. Cancel reservation\n4. Display room details\n5. Exit\n");
        printf("Enter your command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter room number: ");
                scanf("%s", room_number);
                if (check_availability(&hotel, room_number) == 1) {
                    printf("Room is available.\n");
                } else {
                    printf("Room is not available.\n");
                }
                break;
            case '2':
                printf("Enter room number: ");
                scanf("%s", room_number);
                printf("Enter price: ");
                scanf("%d", &hotel.rooms[0].price);
                book_room(&hotel, room_number, hotel.rooms[0].price);
                break;
            case '3':
                printf("Enter room number: ");
                scanf("%s", room_number);
                cancel_reservation(&hotel, room_number);
                break;
            case '4':
                printf("Enter room number: ");
                scanf("%s", room_number);
                display_room(&hotel, room_number);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid command.\n");
        }
    } while (command[0]!= '5');

    return 0;
}