//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTEL 100

// Creating a hotel struct
struct hotel {
    char name[50];
    int rooms;
    int guests[MAX_HOTEL];
    int occupiedRooms;
};

// Function prototypes
void addHotel(struct hotel *h);
void removeHotel(struct hotel *h);
void displayHotels(struct hotel *h);
void addGuest(struct hotel *h);
void removeGuest(struct hotel *h);
void displayGuests(struct hotel *h);

int main() {
    struct hotel hotels[MAX_HOTEL];
    int choice;
    int i, j, k;
    int numHotels = 0;
    
    printf("Welcome to the Hotel Management System!\n");
    
    // Displaying menu options
    while(1) {
        printf("\nMenu Options:\n");
        printf("1. Add Hotel\n");
        printf("2. Remove Hotel\n");
        printf("3. Display Hotels\n");
        printf("4. Add Guest to Hotel\n");
        printf("5. Remove Guest from Hotel\n");
        printf("6. Display Guests in Hotel\n");
        printf("7. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Adding a hotel
                addHotel(&hotels[numHotels]);
                numHotels++;
                break;
            case 2:
                // Removing a hotel
                removeHotel(hotels);
                numHotels--;
                break;
            case 3:
                // Displaying all hotels
                displayHotels(hotels);
                break;
            case 4:
                // Adding a guest to a hotel
                addGuest(hotels);
                break;
            case 5:
                // Removing a guest from a hotel
                removeGuest(hotels);
                break;
            case 6:
                // Displaying all guests in a hotel
                displayGuests(hotels);
                break;
            case 7:
                // Exiting the program
                printf("Thank you for using the Hotel Management System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void addHotel(struct hotel *h) {
    // Adding a hotel
    printf("Enter the hotel name: ");
    scanf("%s", h->name);
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &h->rooms);
    h->occupiedRooms = 0;
    printf("Hotel successfully added!\n");
}

void removeHotel(struct hotel *h) {
    char name[50];
    int index = -1;
    
    // Removing a hotel
    printf("Enter the hotel name: ");
    scanf("%s", name);
    
    // Finding the index of the hotel
    for(int i = 0; i < MAX_HOTEL; i++) {
        if(strcmp(h[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    // Shifting all elements after the index by one
    if(index != -1) {
        for(int i = index; i < MAX_HOTEL - 1; i++) {
            h[i] = h[i + 1];
        }
        printf("Hotel successfully removed!\n");
    } else {
        printf("Hotel not found. Please try again.\n");
    }
}

void displayHotels(struct hotel *h) {
    // Displaying all hotels
    printf("List of all hotels:\n");
    for(int i = 0; i < MAX_HOTEL; i++) {
        if(strlen(h[i].name) != 0) {
            printf("Hotel Name: %s\n", h[i].name);
            printf("Number of Rooms: %d\n", h[i].rooms);
            printf("Number of Occupied Rooms: %d\n", h[i].occupiedRooms);
            printf("\n");
        }
    }
}

void addGuest(struct hotel *h) {
    char name[50];
    int index = -1;
    
    // Adding a guest to a hotel
    printf("Enter the hotel name: ");
    scanf("%s", name);
    
    // Finding the index of the hotel
    for(int i = 0; i < MAX_HOTEL; i++) {
        if(strcmp(h[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if(index != -1) {
        if(h[index].occupiedRooms < h[index].rooms) {
            printf("Enter the guest ID: ");
            scanf("%d", &h[index].guests[h[index].occupiedRooms]);
            h[index].occupiedRooms++;
            printf("Guest successfully added to hotel!\n");
        } else {
            printf("The hotel is fully occupied. Please try another hotel.\n");
        }
    } else {
        printf("Hotel not found. Please try again.\n");
    }
}

void removeGuest(struct hotel *h) {
    char name[50];
    int guestID, index = -1;
    
    // Removing a guest from a hotel
    printf("Enter the hotel name: ");
    scanf("%s", name);
    
    // Finding the index of the hotel
    for(int i = 0; i < MAX_HOTEL; i++) {
        if(strcmp(h[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if(index != -1) {
        if(h[index].occupiedRooms > 0) {
            printf("Enter the guest ID: ");
            scanf("%d", &guestID);
            for(int i = 0; i < h[index].occupiedRooms; i++) {
                if(h[index].guests[i] == guestID) {
                    for(int j = i; j < MAX_HOTEL - 1; j++) {
                        h[index].guests[j] = h[index].guests[j + 1];
                    }
                    h[index].occupiedRooms--;
                    printf("Guest successfully removed from hotel!\n");
                    return;
                }
            }
            printf("Guest not found in hotel. Please try again.\n");
        } else {
            printf("There are no guests in the hotel. Please try another hotel.\n");
        }
    } else {
        printf("Hotel not found. Please try again.\n");
    }
}

void displayGuests(struct hotel *h) {
    char name[50];
    int index = -1;
    
    // Displaying all guests in a hotel
    printf("Enter the hotel name: ");
    scanf("%s", name);
    
    // Finding the index of the hotel
    for(int i = 0; i < MAX_HOTEL; i++) {
        if(strcmp(h[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if(index != -1) {
        printf("Guests in hotel %s:\n", h[index].name);
        for(int i = 0; i < h[index].occupiedRooms; i++) {
            printf("Guest ID: %d\n", h[index].guests[i]);
        }
    } else {
        printf("Hotel not found. Please try again.\n");
    }
}