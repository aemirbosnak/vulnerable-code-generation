//FormAI DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guest {
    int roomNumber;
    char name[50];
    int daysStaying;
    int payment;
};

void bookRoom(int roomNumber, char name[], int daysStaying, int payment, struct Guest hotelGuests[]) {
    hotelGuests[roomNumber-1].roomNumber = roomNumber;
    strcpy(hotelGuests[roomNumber-1].name, name);
    hotelGuests[roomNumber-1].daysStaying = daysStaying;
    hotelGuests[roomNumber-1].payment = payment;
    printf("Room booked successfully!\n");
}

void displayGuest(int roomNumber, struct Guest hotelGuests[]) {
    printf("Room Number: %d\n", hotelGuests[roomNumber-1].roomNumber);
    printf("Guest Name: %s\n", hotelGuests[roomNumber-1].name);
    printf("Days Staying: %d\n", hotelGuests[roomNumber-1].daysStaying);
    printf("Payment: %d\n\n", hotelGuests[roomNumber-1].payment);
}

void displayAllGuests(struct Guest hotelGuests[]) {
    for(int i=0; i<30; i++) {
        if(hotelGuests[i].roomNumber != 0) {
            displayGuest(hotelGuests[i].roomNumber, hotelGuests);
        }
    }
}

void checkout(int roomNumber, struct Guest hotelGuests[]) {
    printf("----------Checkout Details----------\n");
    displayGuest(roomNumber, hotelGuests);
    printf("Total Payment: %d\n", hotelGuests[roomNumber-1].payment);
    printf("Room Number: %d is now available!\n", hotelGuests[roomNumber-1].roomNumber);
    memset(&hotelGuests[roomNumber-1], 0, sizeof(struct Guest));
}

int main() {
    struct Guest hotelGuests[30];
    int choice, roomNumber, daysStaying, payment;
    char name[50];
    while(1) {
        printf("----------C Hotel Management System----------\n");
        printf("1. Book a Room\n");
        printf("2. Display Guest Info\n");
        printf("3. Display All Guests\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Room Number: ");
                scanf("%d", &roomNumber);
                printf("Enter Guest Name: ");
                scanf("%s", name);
                printf("Enter number of days staying: ");
                scanf("%d", &daysStaying);
                printf("Enter payment amount: ");
                scanf("%d", &payment);
                bookRoom(roomNumber, name, daysStaying, payment, hotelGuests);
                break;

            case 2:
                printf("Enter Room Number: ");
                scanf("%d", &roomNumber);
                displayGuest(roomNumber, hotelGuests);
                break;

            case 3:
                displayAllGuests(hotelGuests);
                break;

            case 4:
                printf("Enter Room Number to checkout: ");
                scanf("%d", &roomNumber);
                checkout(roomNumber, hotelGuests);
                break;

            case 5:
                printf("Thank you for using C Hotel Management System!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}