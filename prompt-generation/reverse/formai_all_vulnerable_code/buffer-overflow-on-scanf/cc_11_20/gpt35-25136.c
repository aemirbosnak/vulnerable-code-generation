//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Welcome to the Sherlock Holmes Hotel Management System!\n\n");
    int numRooms = 10;
    char rooms[10][30] = {"221B Baker Street", "The Reichenbach Fall Room", "The Hound of the Baskervilles Room", "The Blue Carbuncle Room", "The Adventure of the Speckled Band Room", "The Final Problem Room", "The Empty House Room", "The Dancing Men Room", "The Sign of Four Room", "The Valley of Fear Room"};
    float prices[10] = {100.0, 90.0, 75.0, 120.0, 80.0, 115.0, 95.0, 110.0, 85.0, 100.0};
    char occupancy[10] = "Available";
    while(1){
        printf("Enter 1 to display all rooms.\n");
        printf("Enter 2 to check availability of a room.\n");
        printf("Enter 3 to check-in to a room.\n");
        printf("Enter 4 to check-out of a room.\n");
        printf("Enter 5 to exit.\n\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Room #\tRoom Name\t\tPrice\t\tOccupancy\n");
                for(int i=0;i<numRooms;i++){
                    printf("%d\t%s\t$%.2f\t%s\n", i+1, rooms[i], prices[i], occupancy[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Enter room number to check availability (1-10): ");
                int roomNum;
                scanf("%d", &roomNum);
                if(roomNum < 1 || roomNum > 10){
                    printf("Invalid room number entered.\n\n");
                    break;
                }
                if(strcmp(occupancy[roomNum-1], "Available") == 0){
                    printf("The %s is available!\n\n", rooms[roomNum-1]);
                }
                else{
                    printf("Sorry, the %s is currently occupied.\n\n", rooms[roomNum-1]);
                }
                break;
            case 3:
                printf("Enter room number to check-in (1-10): ");
                int checkInRoomNum;
                scanf("%d", &checkInRoomNum);
                if(checkInRoomNum < 1 || checkInRoomNum > 10){
                    printf("Invalid room number entered.\n\n");
                    break;
                }
                if(strcmp(occupancy[checkInRoomNum-1], "Available") == 0){
                    printf("Enter guest name: ");
                    char guestName[30];
                    scanf("%s", guestName);
                    occupancy[checkInRoomNum-1] = guestName;
                    printf("Guest checked into %s successfully.\n\n", rooms[checkInRoomNum-1]);
                }
                else{
                    printf("Sorry, the %s is currently occupied.\n\n", rooms[checkInRoomNum-1]);
                }
                break;
            case 4:
                printf("Enter room number to check-out (1-10): ");
                int checkOutRoomNum;
                scanf("%d", &checkOutRoomNum);
                if(checkOutRoomNum < 1 || checkOutRoomNum > 10){
                    printf("Invalid room number entered.\n\n");
                    break;
                }
                if(strcmp(occupancy[checkOutRoomNum-1], "Available") != 0){
                    printf("%s has checked out of %s.\n", occupancy[checkOutRoomNum-1], rooms[checkOutRoomNum-1]);
                    occupancy[checkOutRoomNum-1] = "Available";
                }
                else{
                    printf("Sorry, the %s is currently unoccupied.\n\n", rooms[checkOutRoomNum-1]);
                }
                break;
            case 5:
                printf("Thank you for using the Sherlock Holmes Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid choice entered. Try again.\n\n");
        }
    }
    return 0;
}