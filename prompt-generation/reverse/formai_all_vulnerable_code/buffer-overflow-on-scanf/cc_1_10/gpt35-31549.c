//FormAI DATASET v1.0 Category: Hotel Management System ; Style: retro
#include <stdio.h>
#include <string.h>

// Define Structure for Hotel Guest
struct guest {
    int roomNumber;
    char guestName[50];
    int stayDuration;
    float billAmount;
};

// Define a Function to Print Guest Details
void printGuestDetails(struct guest g) {
    printf("Room Number: %d\n", g.roomNumber);
    printf("Guest Name: %s\n", g.guestName);
    printf("Stay Duration: %d Days\n", g.stayDuration);
    printf("Total Bill Amount: %.2f $\n", g.billAmount);
}

// Define a Function for Billing Calculation
float calculateBill(int duration) {
    float billAmount;
    if (duration < 3) {
        billAmount = duration * 50;
    } else if (duration < 7) {
        billAmount = 2 * 50 + (duration - 2) * 40;
    } else {
        billAmount = 2 * 50 + 4 * 40 + (duration - 6) * 30;
    }
    return billAmount;
}

int main() {
    // Define an Array of Guests
    struct guest guests[10];

    // Define a Counter Variable
    int i = 0;

    printf("Welcome to the Retro Hotel Management System!\n\n");

    // Loop for Adding Guests
    while (1) {
        printf("Enter Guest Room Number (0 to exit): ");
        scanf("%d", &guests[i].roomNumber);

        // Break Loop if Room Number is 0
        if (guests[i].roomNumber == 0) {
            break;
        }

        printf("Enter Guest Name: ");
        scanf("%s", guests[i].guestName);

        printf("Enter Stay Duration (in Days): ");
        scanf("%d", &guests[i].stayDuration);

        // Calculate Bill Amount
        guests[i].billAmount = calculateBill(guests[i].stayDuration);

        printf("Guest Details Added Successfully!\n\n");

        i++;
    }

    // Display Guest Details
    printf("\n--- Guest Details ---\n");
    for (int j=0; j<i; j++) {
        printf("\nGuest %d\n", j+1);
        printGuestDetails(guests[j]);
    }

    return 0;
}