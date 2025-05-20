//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
// Welcome to the C Hotel Management System!

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    // Declare some variables to be used throughout the program
    char hotelName[50], address[100], phoneNo[20];
    int choice, numRooms, roomNumber, roomType, daysStayed, numGuests, totalCost, paidAmount, change;
    float roomRate;

    // Display the welcome message and prompt the user for input 
    printf("==================\n");
    printf("C HOTEL MANAGEMENT SYSTEM\n");
    printf("==================\n\n");

    printf("Enter Hotel Name: ");
    fgets(hotelName, 50, stdin);

    printf("Enter Hotel Address: ");
    fgets(address, 100, stdin);

    printf("Enter Phone Number: ");
    fgets(phoneNo, 20, stdin);

    printf("Enter Number of Rooms: ");
    scanf("%d", &numRooms);

    // Allocate memory for the room status array
    int* roomStatus = (int*)malloc(numRooms * sizeof(int));

    // Initialize room status to 0, indicating that all rooms are available
    for(int i = 0; i < numRooms; i++)
    {
        roomStatus[i] = 0;
    }

    // Display the menu and prompt the user for input
    do
    {
        printf("\n------------------\n");
        printf("C HOTEL MANAGEMENT SYSTEM\n");
        printf("------------------\n");

        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Display Room Status\n");
        printf("4. Exit\n\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Check In
                printf("\nEnter Room Number: ");
                scanf("%d", &roomNumber);

                if(roomNumber <= 0 || roomNumber > numRooms)
                {
                    printf("\nInvalid Room Number!\n");
                    break;
                }

                if(roomStatus[roomNumber-1] == 1)
                {
                    printf("\nRoom Occupied!\n");
                    break;
                }

                printf("Enter Room Type(1: Standard, 2: Deluxe, 3: Suite): ");
                scanf("%d", &roomType);

                if(roomType < 1 || roomType > 3)
                {
                    printf("\nInvalid Room Type!\n");
                    break;
                }

                printf("Enter Room Rate: ");
                scanf("%f", &roomRate);

                printf("Enter Number of Guests: ");
                scanf("%d", &numGuests);

                printf("Enter Days Stayed: ");
                scanf("%d", &daysStayed);

                totalCost = roomRate * daysStayed;

                printf("\nTotal Cost: %d\n", totalCost);

                printf("Enter Paid Amount: ");
                scanf("%d", &paidAmount);

                if(paidAmount < totalCost)
                {
                    printf("\nInsufficient Amount!\n");
                    break;
                }

                change = paidAmount - totalCost;

                printf("\nChange: %d\n", change);
                printf("\nCheck In Successful!\n\n");

                // Set room status to occupied
                roomStatus[roomNumber-1] = 1;

                break;

            case 2:
                // Check Out
                printf("\nEnter Room Number: "); 
                scanf("%d", &roomNumber);

                if(roomNumber <= 0 || roomNumber > numRooms)
                {
                    printf("\nInvalid Room Number!\n");
                    break;
                }

                if(roomStatus[roomNumber-1] == 0)
                {
                    printf("\nRoom Unoccupied!\n");
                    break;
                }

                printf("Enter Days Stayed: ");
                scanf("%d", &daysStayed);

                totalCost = roomRate * daysStayed;

                printf("\nTotal Cost: %d\n", totalCost);

                printf("Enter Paid Amount: ");
                scanf("%d", &paidAmount);

                if(paidAmount < totalCost)
                {
                    printf("\nInsufficient Amount!\n");
                    break;
                }

                change = paidAmount - totalCost;

                printf("\nChange: %d\n", change);
                printf("\nCheck Out Successful!\n\n");

                // Set room status to available
                roomStatus[roomNumber-1] = 0;

                break;

            case 3:
                // Display Room Status
                printf("\n=====================\n");
                printf("ROOM STATUS\n");
                printf("=====================\n\n");

                for(int i = 0; i < numRooms; i++)
                {
                    printf("Room %d: ", i+1);

                    if(roomStatus[i] == 0)
                        printf("Available\n");
                    else
                        printf("Occupied\n");
                }

                break;

            case 4:
                // Exit
                printf("\nThank You for using C Hotel Management System!\n\n");
                free(roomStatus);
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}