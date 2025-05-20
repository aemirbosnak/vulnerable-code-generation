//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include<stdio.h>
#include<string.h>

// defining the capacity of the system to store data
#define MAX 100

// structure for holding information of each hotel room
struct Room{
    int roomNumber;
    char roomType[20];
    float roomPrice;
    char bookedBy[30];
    char bookedFrom[12];
    char bookedTo[12];
}rooms[MAX];

// declaring global variables for counting the number of rooms and bookings
int totalRooms = 0;
int totalBookings = 0;

// function to print main menu
void printMenu(){
    printf("    HOTEL MANAGEMENT SYSTEM\n");
    printf("------------------------------\n");
    printf("1. Add Room\n");
    printf("2. Show All Rooms\n");
    printf("3. Find Room\n");
    printf("4. Book Room\n");
    printf("5. Show All Bookings\n");
    printf("6. Exit\n");
}

// function to add a room to the system
void addRoom(){
    if(totalRooms >= MAX){
        printf("System Capacity Full!\n");
        return;
    }
    printf("Enter Room Number: ");
    scanf("%d",&rooms[totalRooms].roomNumber);
    printf("Enter Room Type: ");
    scanf("%s",rooms[totalRooms].roomType);
    printf("Enter Room Price: ");
    scanf("%f",&rooms[totalRooms].roomPrice);
    printf("Room added successfully!\n");
    totalRooms++;
}

// function to print details of all rooms
void showAllRooms(){
    if(totalRooms == 0){
        printf("No Rooms Found!\n");
        return;
    }
    for(int i=0;i<totalRooms;i++){
        printf("Room Number: %d\n",rooms[i].roomNumber);
        printf("Room Type: %s\n",rooms[i].roomType);
        printf("Room Price: %.2f\n",rooms[i].roomPrice);
        printf("\n");
    }
}

// function to find a room by room number
void findRoom(){
    int roomNumber;
    printf("Enter Room Number to Find: ");
    scanf("%d",&roomNumber);
    for(int i=0;i<totalRooms;i++){
        if(rooms[i].roomNumber == roomNumber){
            printf("Room Found!\n");
            printf("Room Number: %d\n",rooms[i].roomNumber);
            printf("Room Type: %s\n",rooms[i].roomType);
            printf("Room Price: %.2f\n",rooms[i].roomPrice);
            printf("\n");
            return;
        }
    }
    printf("Room Not Found!\n");
}

// function to book a room
void bookRoom(){
    int roomNumber;
    printf("Enter Room Number to Book: ");
    scanf("%d",&roomNumber);
    for(int i=0;i<totalRooms;i++){
        if(rooms[i].roomNumber == roomNumber){
            if(strlen(rooms[i].bookedBy)>0){
                printf("Room Already Booked!\n");
                return;
            }
            printf("Enter Booking Name: ");
            scanf("%s",rooms[i].bookedBy);
            printf("Enter Booking From (dd/mm/yyyy): ");
            scanf("%s",rooms[i].bookedFrom);
            printf("Enter Booking To (dd/mm/yyyy): ");
            scanf("%s",rooms[i].bookedTo);
            printf("Room Booked Successfully!\n");
            totalBookings++;
            return;
        }
    }
    printf("Room Not Found!\n");
}

// function to print details of all bookings
void showAllBookings(){
    if(totalBookings == 0){
        printf("No Bookings Found!\n");
        return;
    }
    printf("BOOKINGS\n");
    printf("------------------------------\n");
    for(int i=0;i<totalRooms;i++){
        if(strlen(rooms[i].bookedBy)>0){
            printf("Room Number: %d\n",rooms[i].roomNumber);
            printf("Booked By: %s\n",rooms[i].bookedBy);
            printf("Booked From: %s\n",rooms[i].bookedFrom);
            printf("Booked To: %s\n",rooms[i].bookedTo);
            printf("\n");
        }
    }
}

int main(){
    int choice;
    while(1){
        printMenu();
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addRoom();
                break;
            case 2:
                showAllRooms();
                break;
            case 3:
                findRoom();
                break;
            case 4:
                bookRoom();
                break;
            case 5:
                showAllBookings();
                break;
            case 6:
                printf("Exiting Program...");
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}