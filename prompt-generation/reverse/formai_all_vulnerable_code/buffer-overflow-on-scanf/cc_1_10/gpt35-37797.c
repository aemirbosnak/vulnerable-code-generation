//FormAI DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROOMS 200
#define MAX_BOOKINGS 1000

typedef struct{
    int roomNumber;
    int floor;
    char roomType[20];
    float rent;
    int availability;
}Room;

typedef struct{
    int bookingId;
    char name[50];
    char contactNumber[20];
    char roomType[20];
    int roomNumber;
    int daysOfStay;
    float totalRent;
}Booking;

Room rooms[MAX_ROOMS];
Booking bookings[MAX_BOOKINGS];
int totalRooms = 0;
int totalBookings = 0;

void addRoom(){
    Room room;
    room.roomNumber = totalRooms + 1;
    printf("\nEnter Floor: ");
    scanf("%d",&room.floor);
    printf("Enter Room Type: ");
    scanf("%s",room.roomType);
    printf("Enter Rent per Day: ");
    scanf("%f",&room.rent);
    room.availability = 1;
    rooms[totalRooms] = room;
    totalRooms++;
    printf("\nRoom added successfully!\n");
}

void displayRooms(){
    printf("Room\tFloor\tType\t\tRent\tAvailability\n");
    for(int i=0; i<totalRooms; i++){
        printf("%d\t%d\t%s\t%.2f\t",rooms[i].roomNumber,rooms[i].floor,rooms[i].roomType,rooms[i].rent);
        if(rooms[i].availability == 1){
            printf("Available\n");
        }else{
            printf("Not Available\n");
        }
    }
}

int findRoomByType(char roomType[20]){
    for(int i=0; i<totalRooms; i++){
        if(strcmp(rooms[i].roomType,roomType) == 0 && rooms[i].availability == 1){
            return rooms[i].roomNumber;
        }
    }
    return -1;
}

void addBooking(){
    Booking booking;
    booking.bookingId = totalBookings + 1;
    printf("\nEnter Name: ");
    scanf("%s",booking.name);
    printf("Enter Contact Number: ");
    scanf("%s",booking.contactNumber);
    printf("Enter Room Type: ");
    scanf("%s",booking.roomType);
    int roomNumber = findRoomByType(booking.roomType);
    if(roomNumber == -1){
        printf("No %s room available!\n",booking.roomType);
    }else{
        printf("Room No. %d has been allotted to you\n",roomNumber);
        booking.roomNumber = roomNumber;
        printf("Enter Days of Stay: ");
        scanf("%d",&booking.daysOfStay);
        booking.totalRent = rooms[roomNumber-1].rent * booking.daysOfStay;
        bookings[totalBookings] = booking;
        rooms[roomNumber - 1].availability = 0;
        totalBookings++;
        printf("Booking completed successfully with Booking ID %d\n", booking.bookingId);
    }
}

void displayBookings(){
    printf("BID\tName\tContact\tType\tRoom No\tDays\tRent\n");
    for(int i=0; i<totalBookings; i++){
        printf("%d\t%s\t%s\t%s\t%d\t%d\t%.2f\n",bookings[i].bookingId,bookings[i].name,bookings[i].contactNumber,bookings[i].roomType,bookings[i].roomNumber,bookings[i].daysOfStay,bookings[i].totalRent);
    }
}

void checkout(){
    int bookingId;
    printf("Enter booking ID: ");
    scanf("%d",&bookingId);
    for(int i=0; i<totalBookings; i++){
        if(bookings[i].bookingId == bookingId){
            int roomNumber = bookings[i].roomNumber;
            rooms[roomNumber-1].availability = 1;
            printf("Checkout successful! Total Rent: %.2f\n",bookings[i].totalRent);
            for(int j=i; j<totalBookings-1; j++){
                bookings[j] = bookings[j+1];
            }
            totalBookings--;
            return;
        }
    }
    printf("Invalid booking ID!\n");
}

void displayMenu(){
    printf("\n------------Hotel Management System------------\n");
    printf("\n1. Add Room\n");
    printf("2. Display Rooms\n");
    printf("3. Add Booking\n");
    printf("4. Display Bookings\n");
    printf("5. Checkout\n");
    printf("6. Exit\n");
}

int main(){
    int choice;
    do{
        displayMenu();
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                addRoom();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                addBooking();
                break;
            case 4:
                displayBookings();
                break;
            case 5:
                checkout();
                break;
            case 6:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }
    }while(choice != 6);
    return 0;
}