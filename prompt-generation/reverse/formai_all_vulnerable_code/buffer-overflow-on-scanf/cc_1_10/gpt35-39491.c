//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
/* Welcome to the Cryptic Hotel Management System */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int rooms[50] = {0}; // Initialize all rooms to empty
    int option, roomNum, days, charge;
    char name[50];

    printf("Welcome to the Cryptic Hotel Management System\n");

    while (1) {
        printf("\nAvailable Options:\n");
        printf("1. Check-In\n");
        printf("2. Check-Out\n");
        printf("3. View Room Status\n"); 
        printf("4. Exit\n");
        printf("Enter your option: ");
        
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nCheck-In\n");

                printf("Enter your name: ");
                scanf("%s", name);

                printf("Enter room number: ");
                scanf("%d", &roomNum);

                if (rooms[roomNum-1] != 0) {
                    printf("Room is already occupied\n");
                    break;
                }

                printf("Enter number of days: ");
                scanf("%d", &days);

                charge = 100 * days; // Calculate room charge

                printf("Check-In Successful!\n");
                printf("Name: %s\n", name);
                printf("Room Number: %d\n", roomNum);
                printf("Number of Days: %d\n", days);
                printf("Room Charge: %d\n", charge);

                rooms[roomNum-1] = 1; // Set room as occupied
                break;

            case 2:
                printf("\nCheck-Out\n");

                printf("Enter room number: ");
                scanf("%d", &roomNum);

                if (rooms[roomNum-1] == 0) {
                    printf("Room is already empty\n");
                    break;
                }

                printf("Check-Out Successful!\n");
                printf("Room Number: %d\n", roomNum);

                rooms[roomNum-1] = 0; // Set room as empty
                break;

            case 3:
                printf("\nRoom Status\n");

                for (int i = 0; i < 50; i++) {
                    if (rooms[i] == 0) {
                        printf("Room %d: Empty\n", i+1);
                    } else {
                        printf("Room %d: Occupied\n", i+1);
                    }
                }

                break;

            case 4:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}