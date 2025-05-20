//FormAI DATASET v1.0 Category: Hotel Management System ; Style: lively
#include <stdio.h>

// struct for holding guest information
struct Guest {
    char name[50];
    int roomNum;
    char checkInDate[11];
    char checkOutDate[11];
    int numNights;
    float totalPrice;
};

// function to calculate total price based on number of nights and room rate
float calculatePrice(int numNights, float roomRate) {
    return numNights * roomRate;
}

int main() {
    // initialize array of max 50 guests
    struct Guest guestList[50];
    int numGuests = 0;
    char menuChoice;

    // loop until user chooses to exit
    do {
        printf("\nWelcome to C Hotel Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Check in a new guest\n");
        printf("2. Check out a guest\n");
        printf("3. Print guest list\n");
        printf("4. Exit program\n");

        scanf(" %c", &menuChoice);

        switch (menuChoice) {
            case '1': {
                // check in new guest
                printf("\nCheck in new guest:\n");

                // take guest information input from user
                struct Guest newGuest;
                printf("Name: ");
                scanf(" %[^\n]", newGuest.name);
                printf("Room number: ");
                scanf("%d", &newGuest.roomNum);
                printf("Check in date (MM/DD/YYYY): ");
                scanf(" %s", newGuest.checkInDate);
                printf("Check out date (MM/DD/YYYY): ");
                scanf(" %s", newGuest.checkOutDate);
                printf("Number of nights: ");
                scanf("%d", &newGuest.numNights);

                // calculate total price
                float roomRate = 100.0;      // room rate of $100 per night
                newGuest.totalPrice = calculatePrice(newGuest.numNights, roomRate);

                // add guest to list and increment number of guests
                guestList[numGuests] = newGuest;
                numGuests++;

                printf("\n%s has been checked in!\n", newGuest.name);
                break;
            }
            case '2': {
                // check out guest
                printf("\nCheck out guest:\n");

                // take room number input from user
                int roomNum;
                printf("Room number: ");
                scanf("%d", &roomNum);

                // find guest with matching room number and remove from list
                for (int i = 0; i < numGuests; i++) {
                    if (guestList[i].roomNum == roomNum) {
                        printf("\n%s has checked out. Total price: $%.2f\n", guestList[i].name, guestList[i].totalPrice);

                        for (int j = i; j < numGuests - 1; j++) {
                            guestList[j] = guestList[j + 1];
                        }

                        numGuests--;
                        break;
                    }
                }

                break;
            }
            case '3': {
                // print guest list
                printf("\nGuest list:\n");

                for (int i = 0; i < numGuests; i++) {
                    printf("%s | Room %d | %s - %s | %d night(s) | $%.2f\n", guestList[i].name, guestList[i].roomNum, guestList[i].checkInDate, guestList[i].checkOutDate, guestList[i].numNights, guestList[i].totalPrice);
                }

                break;
            }
            case '4': {
                // exit program
                printf("\nGoodbye!\n");
                break;
            }
            default: {
                printf("\nPlease choose a valid option.\n");
                break;
            }
        }
    } while (menuChoice != '4');

    return 0;
}