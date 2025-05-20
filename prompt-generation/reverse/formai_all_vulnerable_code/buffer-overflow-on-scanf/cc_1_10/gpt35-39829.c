//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 1000
#define MAX_ROOM_TYPE 4
#define MAX_NIGHTS 10

struct Room {
   int roomNumber;
   char roomType[20];
   int nights;
   float rate;
   float totalCost;
};

void displayHeader() {
   printf("***************************************************\n");
   printf("*                                                 *\n");
   printf("*        HOTEL MANAGEMENT SYSTEM (C VERSION)      *\n");
   printf("*                                                 *\n");
   printf("***************************************************\n");
}

void displayMenu() {
   printf("\nPlease select from the following options:\n");
   printf("1. Check-in\n");
   printf("2. Check-out\n");
   printf("3. View Room Status\n");
   printf("4. View Room Revenue\n");
   printf("5. Exit\n");
   printf("Choice: ");
}

void displayRoomTypes() {
   printf("\nRoom Type List:\n");
   printf("1. Single\n");
   printf("2. Double\n");
   printf("3. Twin\n");
   printf("4. Suite\n");
}

int main() {
   displayHeader();

   char roomTypes[MAX_ROOM_TYPE][20] = {"Single", "Double", "Twin", "Suite"};
   float roomPrices[MAX_ROOM_TYPE] = {50.00, 70.00, 80.00, 120.00};

   int roomCount = 0;
   struct Room rooms[MAX_ROOMS];

   int choice = -1;
   while (choice != 5) {
      displayMenu();

      scanf("%d", &choice);

      if (choice == 1) { // check-in
         int roomNumber, roomTypeIndex, nights;
         printf("\nEnter room number (integer only): ");
         scanf("%d", &roomNumber);

         displayRoomTypes();
         printf("\nEnter room type code (integer only): ");
         scanf("%d", &roomTypeIndex);

         printf("\nEnter number of nights to stay (1 - %d): ", MAX_NIGHTS);
         scanf("%d", &nights);

         if (roomTypeIndex < 1 || roomTypeIndex > MAX_ROOM_TYPE) {
            printf("\nInvalid room type code. Please try again.\n");
         } else if (roomCount >= MAX_ROOMS) {
            printf("\nHotel is fully booked. Please try again later.\n");
         } else {
            struct Room room;
            room.roomNumber = roomNumber;
            strcpy(room.roomType, roomTypes[roomTypeIndex-1]);
            room.nights = nights;
            room.rate = roomPrices[roomTypeIndex-1];
            room.totalCost = room.nights * room.rate;

            rooms[roomCount] = room;
            roomCount++;

            printf("\nCheck-in successful.\n");
         }
      } else if (choice == 2) { // check-out
         if (roomCount == 0) {
            printf("\nNo rooms are occupied.\n");
         } else {
            int roomNumber;
            printf("\nEnter room number to check-out: ");
            scanf("%d", &roomNumber);

            int roomIndex = -1;
            for (int i = 0; i < roomCount; i++) {
               if (rooms[i].roomNumber == roomNumber) {
                  roomIndex = i;
                  break;
               }
            }

            if (roomIndex == -1) {
               printf("\nRoom number not found or is not occupied.\n");
            } else {
               printf("\nRoom number: %d\n", rooms[roomIndex].roomNumber);
               printf("Room type: %s\n", rooms[roomIndex].roomType);
               printf("Number of nights: %d\n", rooms[roomIndex].nights);
               printf("Rate per night: $%.2f\n", rooms[roomIndex].rate);
               printf("Total cost: $%.2f\n", rooms[roomIndex].totalCost);

               for (int i = roomIndex; i < roomCount-1; i++) {
                  rooms[i] = rooms[i+1];
               }
               roomCount--;

               printf("\nCheck-out successful.\n");
            }
         }
      } else if (choice == 3) { // view room status
         if (roomCount == 0) {
            printf("\nNo rooms are occupied.\n");
         } else {
            printf("\nRoom Status List:\n");
            printf("%-10s%-15s%-10s%-10s%s\n", "Room No.", "Room Type", "Nights", "Rate", "Total Cost");
            for (int i = 0; i < roomCount; i++) {
               printf("%-10d%-15s%-10d$%-10.2f$%.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].nights, rooms[i].rate, rooms[i].totalCost);
            }
         }
      } else if (choice == 4) { // view room revenue
         if (roomCount == 0) {
            printf("\nNo revenue available.\n");
         } else {
            float totalRevenue = 0.0;
            for (int i = 0; i < roomCount; i++) {
               totalRevenue += rooms[i].totalCost;
            }
            printf("\nTotal room revenue: $%.2f\n", totalRevenue);
         }
      } else if (choice == 5) { // exit
         printf("\nThank you for using Hotel Management System!\n");
      } else {
         printf("\nInvalid choice. Please try again.\n");
      }
   }

   return 0;
}