//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to add a new guest
void addGuest(char *name, char *email) {
    int guestID = getGuestID();
    if(guestID == -1) {
        printf("Error: No more room available.\n");
        return;
    }
    char *room = (char *)malloc(20);
    strcpy(room, "Room ");
    int roomNum = getRoomNumber();
    strcat(room, &roomNum);
    char *guestName = (char *)malloc(30);
    strcpy(guestName, name);
    char *guestEmail = (char *)malloc(30);
    strcpy(guestEmail, email);
    printf("Guest added. ID: %d, Room: %s, Name: %s, Email: %s\n", guestID, room, guestName, guestEmail);
    free(room);
    free(guestName);
    free(guestEmail);
}

// Function to remove a guest
void removeGuest(int guestID) {
    if(guestID == -1) {
        printf("Error: Guest not found.\n");
        return;
    }
    char *room = (char *)malloc(20);
    strcpy(room, "Room ");
    int roomNum = getRoomNumber();
    strcat(room, &roomNum);
    printf("Guest removed. Room: %s\n", room);
    free(room);
}

// Function to get guest ID
int getGuestID() {
    int guestID = rand() % 100;
    return guestID;
}

// Function to get room number
int getRoomNumber() {
    int roomNum = rand() % 10;
    return roomNum;
}

int main() {
    char *name = (char *)malloc(30);
    char *email = (char *)malloc(30);
    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter guest email: ");
    scanf("%s", email);
    addGuest(name, email);
    removeGuest(-1); // Remove a non-existent guest
    removeGuest(getGuestID()); // Remove an existing guest
    printf("Program finished.\n");
    return 0;
}