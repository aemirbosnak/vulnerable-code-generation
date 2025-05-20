//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void welcomeMessage();
void addRoom(char* roomName, int price);
void deleteRoom(char* roomName);
void printRooms();
void searchRoom(char* roomName);
void updateRoom(char* roomName, int price);

int main() {
    welcomeMessage();
    int choice;
    do {
        printf("1. Add Room\n2. Delete Room\n3. Print Rooms\n4. Search Room\n5. Update Room\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom("Deluxe Suite", 200);
                break;
            case 2:
                deleteRoom("Deluxe Suite");
                break;
            case 3:
                printRooms();
                break;
            case 4:
                searchRoom("Deluxe Suite");
                break;
            case 5:
                updateRoom("Deluxe Suite", 250);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}

void welcomeMessage() {
    printf("Welcome to the C Hotel Management System!\n");
}

void addRoom(char* roomName, int price) {
    printf("Room '%s' added successfully. Price: $%.2f\n", roomName, price);
}

void deleteRoom(char* roomName) {
    printf("Room '%s' deleted successfully.\n", roomName);
}

void printRooms() {
    printf("Available Rooms:\n");
    printf("1. Deluxe Suite\n");
    printf("2. Executive Suite\n");
    printf("3. Standard Room\n");
}

void searchRoom(char* roomName) {
    if (strcmp(roomName, "Deluxe Suite") == 0) {
        printf("Room '%s' found. Price: $%.2f\n", roomName, 250);
    } else if (strcmp(roomName, "Executive Suite") == 0) {
        printf("Room '%s' found. Price: $%.2f\n", roomName, 300);
    } else if (strcmp(roomName, "Standard Room") == 0) {
        printf("Room '%s' found. Price: $%.2f\n", roomName, 150);
    } else {
        printf("Room '%s' not found.\n", roomName);
    }
}

void updateRoom(char* roomName, int price) {
    if (strcmp(roomName, "Deluxe Suite") == 0) {
        printf("Room '%s' price updated successfully. New price: $%.2f\n", roomName, price);
    } else if (strcmp(roomName, "Executive Suite") == 0) {
        printf("Room '%s' price updated successfully. New price: $%.2f\n", roomName, price);
    } else if (strcmp(roomName, "Standard Room") == 0) {
        printf("Room '%s' price updated successfully. New price: $%.2f\n", roomName, price);
    } else {
        printf("Room '%s' not found.\n", roomName);
    }
}