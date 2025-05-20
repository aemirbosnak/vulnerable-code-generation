//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[50];
    int roomNum;
    char roomType[10];
    int numGuests;
    float price;
} h[50];

int main() {
    int i, j, choice, numRooms, roomChoice, numGuests;
    char hotelName[50];

    printf("Welcome to the C Hotel Management System!\n\n");
    printf("How many hotels would you like to manage? ");
    scanf("%d", &numRooms);

    for(i = 0; i < numRooms; i++) {
        printf("\n\nEnter hotel name: ");
        scanf("%s", h[i].name);
        printf("Enter total number of rooms available in %s: ", h[i].name);
        scanf("%d", &h[i].roomNum);

        for(j = 0; j < h[i].roomNum; j++) {
            printf("\nRoom %d\n", j+1);
            printf("Enter room type (single, double or suite): ");
            scanf("%s", h[i].roomType);
            printf("Enter price per night for %s: ", h[i].roomType);
            scanf("%f", &h[i].price);
            h[i].numGuests = 0;

            while(h[i].numGuests == 0) {
                printf("How many guests can stay in this room? (1/2): ");
                scanf("%d", &h[i].numGuests);

                if(h[i].numGuests < 1 || h[i].numGuests > 2) {
                    printf("Invalid input. Please enter 1 or 2.\n");
                    h[i].numGuests = 0;
                }
            }
        }
    }

    while(1) {
        printf("\n\nWhat would you like to do?\n");
        printf("1. Check room availability\n");
        printf("2. Book a room\n");
        printf("3. Exit\n\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n\nEnter hotel name: ");
                scanf("%s", hotelName);
                printf("Enter room type (single, double or suite): ");
                scanf("%s", &h[i].roomType);

                for(i = 0; i < numRooms; i++) {
                    if(strcmp(hotelName, h[i].name) == 0) {
                        for(j = 0; j < h[i].roomNum; j++) {
                            if(strcmp(h[i].roomType, h[i].roomType) == 0 && h[i].numGuests != 2) {
                                printf("Room %d available for %s per night for %.2f\n", j+1, h[i].roomType, h[i].price);
                            }
                        }
                    }
                }

                break;
            case 2:
                printf("\n\nEnter hotel name: ");
                scanf("%s", hotelName);
                printf("Enter room type (single, double or suite): ");
                scanf("%s", &h[i].roomType);

                for(i = 0; i < numRooms; i++) {
                    if(strcmp(hotelName, h[i].name) == 0) {
                        for(j = 0; j < h[i].roomNum; j++) {
                            if(strcmp(h[i].roomType, h[i].roomType) == 0 && h[i].numGuests != 2) {
                                printf("Room %d available for %s per night for %.2f\n", j+1, h[i].roomType, h[i].price);
                                printf("How many guests will be staying in the room? ");
                                scanf("%d", &numGuests);

                                if(numGuests == h[i].numGuests) {
                                    printf("Enjoy your stay!\n");
                                    h[i].numGuests = 2;
                                } else {
                                    printf("Sorry, that room is not suitable for %d guests.\n", numGuests);
                                }
                            }
                        }
                    }
                }

                break;
            case 3:
                printf("\n\nThank you for using the C Hotel Management System. Goodbye!\n");
                exit(0);
            default:
                printf("\n\nInvalid choice. Please enter 1, 2 or 3.\n");
        }
    }

    return 0;
}