//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    char customerName[30];
    int daysStayed;
    int roomType; // 0 for standard, 1 for deluxe, 2 for suite
    int paymentStatus; // 0 for unpaid, 1 for paid
};

void printRoom(struct Room r) {
    printf("Room Number: %d\n", r.roomNumber);
    printf("Customer Name: %s\n", r.customerName);
    printf("Days Stayed: %d\n", r.daysStayed);
    printf("Room Type: %s\n", r.roomType == 0 ? "Standard" : r.roomType == 1 ? "Deluxe" : "Suite");
    printf("Payment Status: %s\n", r.paymentStatus == 0 ? "Unpaid": "Paid");
}

int main() {
    struct Room rooms[10];
    int option, roomNumber, i, found;
    char temp[30];
    do {
        printf("1. Add new booking\n");
        printf("2. View booking information\n");
        printf("3. Update booking information\n");
        printf("4. Delete booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                for(i = 0; i < 10; i++) {
                    if(rooms[i].roomNumber == 0) {
                        printf("Enter room number: ");
                        scanf("%d", &rooms[i].roomNumber);
                        printf("Enter customer name: ");
                        scanf("%s", &rooms[i].customerName);
                        printf("Enter days stayed: ");
                        scanf("%d", &rooms[i].daysStayed);
                        printf("Enter room type (0 for Standard, 1 for Deluxe, 2 for Suite):");
                        scanf("%d", &rooms[i].roomType);
                        rooms[i].paymentStatus = 0;
                        printf("Booking added successfully!\n");
                        break;
                    }
                }
                if(i == 10) {
                    printf("All rooms are booked!\n");
                }
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                found = 0;
                for(i = 0; i < 10; i++) {
                    if(rooms[i].roomNumber == roomNumber) {
                        printRoom(rooms[i]);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Room not found!\n");
                }
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                found = 0;
                for(i = 0; i < 10; i++) {
                    if(rooms[i].roomNumber == roomNumber) {
                        printf("Enter new customer name (or press enter to keep old name): \n");
                        fgets(temp, 30, stdin);
                        if(temp[0] != '\n' || temp[0] != '\r\n') {
                            strcpy(rooms[i].customerName, temp);
                        }
                        printf("Enter new days stayed (or press 0 to keep old value): \n");
                        scanf("%d", &rooms[i].daysStayed);
                        printf("Enter new room type (or press 3 to keep old value): ");
                        scanf("%d", &rooms[i].roomType);
                        rooms[i].paymentStatus = 0;
                        printf("Booking updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Room not found!\n");
                }
                break;
            case 4:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                found = 0;
                for(i = 0; i < 10; i++) {
                    if(rooms[i].roomNumber == roomNumber) {
                        rooms[i].roomNumber = 0;
                        printf("Booking deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Room not found!\n");
                }
                break;
            case 5:
                printf("Exiting Hotel Management System...\n");
                break;
            default:
                printf("Invalid option selected!\n");
        }
    } while(option != 5);
    return 0;
}