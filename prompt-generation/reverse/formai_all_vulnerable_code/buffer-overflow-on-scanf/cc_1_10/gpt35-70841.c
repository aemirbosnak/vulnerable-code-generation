//FormAI DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Defining the structure for room
struct Room {
    int room_no;
    char room_type[10];
    int occupancy;
    float price;
};

// Function to display room details
void displayRoom(struct Room r) {
    printf("\n\tRoom No.: %d\n\tRoom Type: %s\n\tOccupancy: %d\n\tPrice: %.2f", r.room_no, r.room_type, r.occupancy, r.price);
}

// Function to add a new room
void addRoom(struct Room r[], int *nptr) {
    printf("\nEnter the room details:");
    printf("\nRoom No.: ");
    scanf("%d", &r[*nptr].room_no);
    printf("Room Type (Single / Double): ");
    scanf("%s", r[*nptr].room_type);
    printf("Occupancy (1 / 2 people): ");
    scanf("%d", &r[*nptr].occupancy);
    printf("Price Per Night: ");
    scanf("%f", &r[*nptr].price);
    printf("\nRoom added successfully!");
    (*nptr)++; // Update the number of rooms
}

// Function to search for a room
void searchRoom(struct Room r[], int n) {
    int room_no, i, found=0;
    printf("\nEnter the room no. to search: ");
    scanf("%d", &room_no);
    for(i=0; i<n; i++) {
        if(r[i].room_no == room_no) {
            found = 1;
            displayRoom(r[i]);
            break;
        }
    }
    if(!found) {
        printf("\nRoom not found!");
    }
}

// Function to calculate total revenue
float calculateRevenue(struct Room r[], int n) {
    float total=0;
    int i;
    for(i=0; i<n; i++) {
        total += r[i].price;
    }
    return total;
}

// Main function
int main() {
    struct Room rooms[100]; // Maximum of 100 rooms can be added
    int n=0, choice;
    do {
        printf("\n\n\t\tC Hotel Management System");
        printf("\n\nMenu:");
        printf("\n1. Add Room");
        printf("\n2. Search Room");
        printf("\n3. Display All Rooms");
        printf("\n4. Calculate Total Revenue");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addRoom(rooms, &n);
                    break;
            case 2: searchRoom(rooms, n);
                    break;
            case 3: printf("\nRoom Details:");
                    for(int i=0; i<n; i++) {
                        displayRoom(rooms[i]);
                    }
                    break;
            case 4: printf("\nTotal Revenue: $%.2f", calculateRevenue(rooms, n));
                    break;
            case 5: printf("\nExiting...");
                    exit(0);
                    break;
            default: printf("\nInvalid choice!");
                    break;
        }
    } while(choice!=5);
    return 0;
}