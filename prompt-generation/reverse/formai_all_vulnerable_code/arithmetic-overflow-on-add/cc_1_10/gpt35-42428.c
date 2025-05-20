//FormAI DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 100

typedef struct {
   char name[50];
   char address[100];
   char phone[15];
   char email[50];
   char creditCard[20];
} Guest;

typedef struct {
   char code[10];
   char type[25];
   double price;
   bool isAvailable;
} Room;

void getInput(char* prompt, char* buffer, int size) {
   printf("%s: ", prompt);
   fgets(buffer, size, stdin);
   if (buffer[strlen(buffer)-1] == '\n') {
      buffer[strlen(buffer)-1] = '\0';
   }
}

void clearScreen() {
   system("clear");
}

int main() {
   int option = 0;
   int numRooms;
   Room rooms[MAX_ROOMS];
   Guest guests[MAX_ROOMS];

   do {
      clearScreen();
      printf("-----------------------------\n");
      printf("Hotel Management System\n");
      printf("-----------------------------\n");
      printf("1. Check In\n");
      printf("2. Check Out\n");
      printf("3. View Room Status\n");
      printf("4. Exit\n");
      printf("Enter your choice (1-4): ");
      scanf("%d", &option);
      getchar(); // consume \n character

      switch(option) {
         case 1: {
            clearScreen();
            printf("-----------------------------\n");
            printf("Check In\n");
            printf("-----------------------------\n");

            if (numRooms == MAX_ROOMS) {
               printf("Error: No rooms available.\n");
               getchar();
               break;
            }

            Room newRoom;
            getInput("Enter room code (XXNNN):", newRoom.code, sizeof(newRoom.code));
            getInput("Enter room type (single/double/suite):", newRoom.type, sizeof(newRoom.type));
            printf("Enter room price: ");
            scanf("%lf", &newRoom.price);
            newRoom.isAvailable = true;

            rooms[numRooms++] = newRoom;

            Guest newGuest;
            getInput("Enter guest name:", newGuest.name, sizeof(newGuest.name));
            getInput("Enter address:", newGuest.address, sizeof(newGuest.address));
            getInput("Enter phone number:", newGuest.phone, sizeof(newGuest.phone));
            getInput("Enter email address:", newGuest.email, sizeof(newGuest.email));
            getInput("Enter credit card number:", newGuest.creditCard, sizeof(newGuest.creditCard));

            int roomIndex = -1;
            for (int i = 0; i < numRooms; i++) {
               if (strcmp(rooms[i].code, newRoom.code) == 0) {
                  roomIndex = i;
                  break;
               }
            }
            if (roomIndex != -1) {
               rooms[roomIndex].isAvailable = false;
               guests[roomIndex] = newGuest;
               printf("Guest %s checked in to room %s\n", newGuest.name, newRoom.code);
            }
            getchar();
            break;
         }
         case 2: {
            clearScreen();
            printf("-----------------------------\n");
            printf("Check Out\n");
            printf("-----------------------------\n");

            if (numRooms == 0) {
               printf("Error: No rooms checked in.\n");
               getchar();
               break;
            }

            char roomCode[10];
            getInput("Enter room code:", roomCode, sizeof(roomCode));

            bool roomFound = false;
            for (int i = 0; i < numRooms; i++) {
               if (strcmp(rooms[i].code, roomCode) == 0) {
                  roomFound = true;
                     
                  printf("Room %s checked out.\n", roomCode);
                  printf("Guest name: %s\n", guests[i].name);
                  printf("Room type: %s\n", rooms[i].type);
                  printf("Room price: %.2f\n", rooms[i].price);
                  printf("Credit card number: %s\n", guests[i].creditCard);
                  printf("Thank you for staying with us, %s.\n", guests[i].name);

                  for (int j = i; j < numRooms-1; j++) {
                     rooms[j] = rooms[j+1];
                     guests[j] = guests[j+1];
                  }
                  numRooms--;
                  break;
               }
            }
            if (!roomFound) {
               printf("Error: Room not found.\n");         
            }
            getchar();
            break;
         }
         case 3: {
            clearScreen();
            printf("-----------------------------\n");
            printf("View Room Status\n");
            printf("-----------------------------\n");
            printf("Room Code\t\tType\tPrice\tAvailability\n");
            printf("-----------------------------------------------------\n");
            for (int i = 0; i < numRooms; i++) {
               printf("%s\t\t%s\t%.2f\t%s\n", rooms[i].code, rooms[i].type, rooms[i].price, rooms[i].isAvailable ? "Available" : "Occupied");
            }
            getchar();
            break;
         }
         case 4: {
            printf("Exiting...\n");
            break;
         }
         default: {
            printf("Invalid option.\n");
            getchar();
         }
      }
   } while(option != 4);

   return 0;
}