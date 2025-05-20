//FormAI DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct roomDetails {
    char roomNo[10];
    int occupancy;
    float price;
};

int main() {
    struct roomDetails rooms[5]; // Assuming there are 5 rooms in our hotel
    int i = 0, choice, numberOfDays;
    float totalBill = 0.0;

    while (1) {
        printf("\n\n---------Welcome to Hotel Taj---------\n\n");
        printf("1. Book a room\n");
        printf("2. Checkout\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (i >= 5) {
                    printf("\nSorry, all rooms are currently occupied!\n");
                    break;
                }

                printf("\nEnter room number (example: R101): ");
                scanf("%s", rooms[i].roomNo);

                printf("Enter number of occupants: ");
                scanf("%d", &rooms[i].occupancy);

                printf("Enter price for per day: ");
                scanf("%f", &rooms[i].price);

                printf("\nRoom booked successfully!\n\n");

                i++;
                break;
            }
            case 2: {
                char roomNo[10];
                printf("\nEnter room number you want to checkout (example: R101): ");
                scanf("%s", roomNo);

                int foundIndex = -1;

                for (int j = 0; j < i; j++) {
                    if (strcmp(rooms[j].roomNo, roomNo) == 0) {
                        foundIndex = j;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    printf("\nSorry, there is no booking for this room number!\n\n");
                    break;
                }

                printf("Enter number of days stayed: ");
                scanf("%d", &numberOfDays);

                float bill = numberOfDays * rooms[foundIndex].price;
                printf("\nYour bill is %.2f\n\n", bill);

                totalBill += bill;

                // Shift all the other bookings left by one index
                for (int j = foundIndex; j < i - 1; j++) {
                    rooms[j] = rooms[j+1];
                }

                i--;

                break;
            }
            case 3: {
                printf("\nTotal revenue generated is %.2f\n\n", totalBill);
                exit(1);
            }
            default: {
                printf("\nInvalid choice, please try again!\n\n");
                break;
            }
        }
    }
    
    return 0;
}