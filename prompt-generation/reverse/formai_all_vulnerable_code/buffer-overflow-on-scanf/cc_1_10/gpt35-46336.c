//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of hotel name and description
#define MAX_NAME 50
#define MAX_DESC 100

// Define structure for hotel
typedef struct {
    char name[MAX_NAME];
    char desc[MAX_DESC];
    int stars;
    int numRooms;
    float roomPrice;
    int numBookings;
} Hotel;

// Function to get user input for a new hotel
void inputHotelInfo(Hotel *hotel) {
    printf("Enter hotel name: ");
    fgets(hotel->name, MAX_NAME, stdin);
    printf("Enter hotel description: ");
    fgets(hotel->desc, MAX_DESC, stdin);
    printf("Enter number of stars (1-5): ");
    scanf("%d", &hotel->stars);
    printf("Enter number of rooms: ");
    scanf("%d", &hotel->numRooms);
    printf("Enter room price per night: ");
    scanf("%f", &hotel->roomPrice);
    hotel->numBookings = 0;
}

// Function to display a hotel's information
void displayHotelInfo(Hotel hotel) {
    printf("Hotel name: %s", hotel.name);
    printf("Description: %s", hotel.desc);
    printf("Stars: %d\n", hotel.stars);
    printf("Number of rooms: %d\n", hotel.numRooms);
    printf("Room price per night: %.2f\n", hotel.roomPrice);
    printf("Number of bookings: %d\n\n", hotel.numBookings);
}

// Function to book a room at a hotel
void bookRoom(Hotel *hotel) {
    if (hotel->numRooms > 0) {
        hotel->numRooms--;
        hotel->numBookings++;
        printf("Room booked successfully!\n\n");
    }
    else {
        printf("Sorry, there are no available rooms.\n\n");
    }
}

int main() {
    int choice, numHotels=0;
    Hotel hotels[10]; // Array of 10 hotels (maximum)

    // Main menu loop
    while (1) {
        printf("Select an option:\n");
        printf("1. Add a new hotel\n");
        printf("2. View hotel information\n");
        printf("3. Book a room\n");
        printf("4. Exit\n\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                inputHotelInfo(&hotels[numHotels]);
                numHotels++;
                break;
            case 2:
                if (numHotels == 0) {
                    printf("No hotels to display.\n\n");
                }
                else {
                    int i;
                    for (i=0; i<numHotels; i++) {
                        printf("Hotel %d:\n", i+1);
                        displayHotelInfo(hotels[i]);
                    }
                }
                break;
            case 3:
                if (numHotels == 0) {
                    printf("No hotels to book rooms at.\n\n");
                }
                else {
                    int i, hotelNum;
                    for (i=0; i<numHotels; i++) {
                        printf("Hotel %d:\n", i+1);
                        displayHotelInfo(hotels[i]);
                    }
                    printf("Enter hotel number to book a room at: ");
                    scanf("%d", &hotelNum);
                    if (hotelNum >= 1 && hotelNum <= numHotels) {
                        bookRoom(&hotels[hotelNum-1]);
                    }
                    else {
                        printf("Invalid hotel number.\n\n");
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }

    return 0;
}