//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // Structures to store information about guests and rooms
    typedef struct {
        int id;
        char name[50];
        char email[50];
        char phone[50];
    } Guest;

    typedef struct {
        int id;
        char type[50];
        int capacity;
        int price;
    } Room;

    // Functions to manage guests and rooms
    void addGuest(Guest *guests, int *numGuests) {
        // Get input from user
        int id;
        char name[50];
        char email[50];
        char phone[50];
        printf("Enter guest's ID: ");
        scanf("%d", &id);
        printf("Enter guest's name: ");
        scanf("%s", name);
        printf("Enter guest's email: ");
        scanf("%s", email);
        printf("Enter guest's phone: ");
        scanf("%s", phone);

        // Add guest to array
        guests[*numGuests].id = id;
        strcpy(guests[*numGuests].name, name);
        strcpy(guests[*numGuests].email, email);
        strcpy(guests[*numGuests].phone, phone);
        *numGuests += 1;
    }

    void addRoom(Room *rooms, int *numRooms) {
        // Get input from user
        int id;
        char type[50];
        int capacity;
        int price;
        printf("Enter room's ID: ");
        scanf("%d", &id);
        printf("Enter room's type: ");
        scanf("%s", type);
        printf("Enter room's capacity: ");
        scanf("%d", &capacity);
        printf("Enter room's price: ");
        scanf("%d", &price);

        // Add room to array
        rooms[*numRooms].id = id;
        strcpy(rooms[*numRooms].type, type);
        rooms[*numRooms].capacity = capacity;
        rooms[*numRooms].price = price;
        *numRooms += 1;
    }

    void printGuest(Guest *guests, int numGuests) {
        // Print guest information
        printf("Guest Information:\n");
        for (int i = 0; i < numGuests; i++) {
            printf("ID: %d\n", guests[i].id);
            printf("Name: %s\n", guests[i].name);
            printf("Email: %s\n", guests[i].email);
            printf("Phone: %s\n", guests[i].phone);
            printf("\n");
        }
    }

    void printRoom(Room *rooms, int numRooms) {
        // Print room information
        printf("Room Information:\n");
        for (int i = 0; i < numRooms; i++) {
            printf("ID: %d\n", rooms[i].id);
            printf("Type: %s\n", rooms[i].type);
            printf("Capacity: %d\n", rooms[i].capacity);
            printf("Price: %d\n", rooms[i].price);
            printf("\n");
        }
    }

    int main() {
        // Declare arrays to store guests and rooms
        Guest guests[100];
        int numGuests = 0;
        Room rooms[100];
        int numRooms = 0;

        // Add guests and rooms
        addGuest(guests, &numGuests);
        addRoom(rooms, &numRooms);

        // Print guests and rooms
        printGuest(guests, numGuests);
        printRoom(rooms, numRooms);

        return 0;
    }