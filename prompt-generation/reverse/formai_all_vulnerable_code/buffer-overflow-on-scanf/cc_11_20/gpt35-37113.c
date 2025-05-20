//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Hotel Management System\n");
    printf("We are excited to have you here!\n");

    int numRooms = 10; // initialize number of rooms to 10
    int occupiedRooms = 0; // initialize number of occupied rooms to 0
    int vacantRooms = numRooms - occupiedRooms; // calculate number of vacant rooms
    float roomRate = 90.00; // declare room rate
    float totalIncome = 0.00; // initialize total income to 0

    while(1) // infinite loop to keep the program running
    {
        printf("\n[1] Check In\n");
        printf("[2] Check Out\n");
        printf("[3] Display Room Information\n");
        printf("[4] Exit\n");
        printf("Please select an option: ");

        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(occupiedRooms == numRooms) // if all rooms are occupied
                {
                    printf("\nSorry, all of our rooms are currently occupied.\n");
                }
                else
                {
                    printf("\nEnter room number: ");
                    int roomNum;
                    scanf("%d", &roomNum);

                    if(roomNum > numRooms || roomNum < 1) // if room number is invalid
                    {
                        printf("\nInvalid room number.\n");
                    }
                    else if(roomNum <= occupiedRooms) // if room is already occupied
                    {
                        printf("\nRoom is already occupied.\n");
                    }
                    else
                    {
                        occupiedRooms++;
                        vacantRooms--;
                        printf("\nRoom %d has been checked in.\n", roomNum);
                    }
                }
                break;
            
            case 2:
                printf("\nEnter room number: ");
                int roomNum;
                scanf("%d", &roomNum);

                if(roomNum > numRooms || roomNum < 1) // if room number is invalid
                {
                    printf("\nInvalid room number.\n");
                }
                else if(roomNum > occupiedRooms) // if room is not occupied
                {
                    printf("\nRoom is not occupied.\n");
                }
                else
                {
                    occupiedRooms--;
                    vacantRooms++;
                    float roomCost = roomRate * 1.1; // add 10% VAT to the room rate
                    totalIncome += roomCost; // add room cost to total income
                    printf("\nRoom %d has been checked out. Room cost: %.2f\n", roomNum, roomCost);
                }
                break;
            
            case 3:
                printf("\nNumber of vacant rooms: %d\n", vacantRooms);
                printf("Number of occupied rooms: %d\n", occupiedRooms);
                printf("Total income: %.2f\n", totalIncome);
                break;
            
            case 4:
                printf("\nThank you for using the C Hotel Management System!\n");
                exit(0); // exit the program
            
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}