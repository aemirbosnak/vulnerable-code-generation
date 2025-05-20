//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
   int roomNumber;
   int reserved;
   char guestName[20];
   float rate;
};

typedef struct room Room;

Room createRoom(int roomNumber, float rate) {
   Room r;
   r.roomNumber = roomNumber;
   r.reserved = 0;
   strcpy(r.guestName, "");
   r.rate = rate;
   return r;
}

void display(Room* rooms, int numRooms) {
   printf("***** Room Status *****\n");
   for(int i = 0; i < numRooms; i++) {
      if(rooms[i].reserved == 0) {
         printf("Room %d: Available\n", rooms[i].roomNumber);
      } else {
         printf("Room %d: Reserved for %s\n", rooms[i].roomNumber, rooms[i].guestName);
      }
   }
   printf("\n");
}

void reserve(int roomNumber, char* guestName, Room* rooms, int numRooms) {
   for(int i = 0; i < numRooms; i++) {
      if(rooms[i].roomNumber == roomNumber) {
         rooms[i].reserved = 1;
         strcpy(rooms[i].guestName, guestName);
         printf("Reservation successful!\n");
         return;
      }
   }
   printf("Invalid room number!\n");
}

int main() {
   int numRooms = 5;
   float rate = 99.99;
   Room rooms[numRooms];
   for(int i = 0; i < numRooms; i++) {
      rooms[i] = createRoom(i+1, rate);
   }
   
   int choice = 0;
   while(choice != 3) {
      printf("1. Display room status\n");
      printf("2. Reserve a room\n");
      printf("3. Quit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1: display(rooms, numRooms);
            break;
         case 2: {
            int roomNumber;
            char guestName[20];
            printf("Enter the room number you want to reserve: ");
            scanf("%d", &roomNumber);
            printf("Enter your name: ");
            scanf("%s", guestName);
            reserve(roomNumber, guestName, rooms, numRooms);
            break;
         }
         case 3: printf("Goodbye!\n");
            break;
         default: printf("Invalid choice!\n");
      }
   }
   
   return 0;
}