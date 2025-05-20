//FormAI DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing guest information
typedef struct {
    char name[50];
    int roomNum;
    int numNights;
    float billAmount;
} Guest;

// Prototype functions
void checkIn(Guest *guests, int *numGuests);
void checkOut(Guest *guests, int *numGuests);
void displayGuests(Guest *guests, int numGuests);
float calculateBill(int roomNum, int numNights);

int main() {
    int option, numGuests = 0;
    Guest guests[100];

    printf("Welcome to C Hotel Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Check in\n");
        printf("2. Check out\n");
        printf("3. Display guests\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                checkIn(guests, &numGuests);
                break;
            case 2:
                checkOut(guests, &numGuests);
                break;
            case 3:
                displayGuests(guests, numGuests);
                break;
            case 4:
                printf("Thank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    } while(1);

    return 0;
}

void checkIn(Guest *guests, int *numGuests) {
    char name[50];
    int roomNum, numNights;

    if(*numGuests == 100) {
        printf("Hotel is full!\n");
        return;
    }

    printf("Enter guest name: ");
    scanf("%s", name);
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    printf("Enter number of nights: ");
    scanf("%d", &numNights);

    guests[*numGuests].roomNum = roomNum;
    guests[*numGuests].numNights = numNights;
    guests[*numGuests].billAmount = calculateBill(roomNum, numNights);
    strcpy(guests[*numGuests].name, name);
    (*numGuests)++;

    printf("Check in successful!\n");
}

void checkOut(Guest *guests, int *numGuests) {
    int roomNum, found = 0;

    printf("Enter room number: ");
    scanf("%d", &roomNum);

    for(int i = 0; i < *numGuests; i++) {
        if(guests[i].roomNum == roomNum) {
            printf("Guest %s with room number %d stayed for %d nights and has to pay $%.2f.\n", 
                guests[i].name, guests[i].roomNum, guests[i].numNights, guests[i].billAmount);
            guests[i] = guests[(*numGuests) - 1];
            (*numGuests)--;
            found = 1;
            printf("Check out successful!\n");
            break;
        }
    }

    if(found == 0) {
        printf("Guest not found!\n");
    }
}

void displayGuests(Guest *guests, int numGuests) {
    if(numGuests == 0) {
        printf("No guests checked in!\n");
        return;
    }

    printf("Current Guests:\n");
    printf("Name\tRoom Number\tNumber of Nights\tBill Amount\n");
    for(int i = 0; i < numGuests; i++) {
        printf("%s\t%d\t\t%d\t\t$%.2f\n", guests[i].name, guests[i].roomNum, 
            guests[i].numNights, guests[i].billAmount);
    }
}

float calculateBill(int roomNum, int numNights) {
    float rate;

    switch(roomNum) {
        case 101:
        case 102:
        case 103:
            rate = 100.0;
            break;
        case 201:
        case 202:
        case 203:
            rate = 150.0;
            break;
        case 301:
        case 302:
        case 303:
            rate = 200.0;
            break;
        default:
            rate = 0.0;
            break;
    }

    return rate * numNights;
}