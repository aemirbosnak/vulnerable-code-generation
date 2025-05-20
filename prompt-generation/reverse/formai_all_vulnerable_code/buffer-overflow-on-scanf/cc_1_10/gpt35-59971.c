//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define hotel struct
struct hotel {
   char name[50];
   int roomId;
   char roomType[20];
   double roomRate;
   int roomStatus; // 0 for available, 1 for occupied
};

// Define function prototypes
void displayAvailableRooms();
void displayOccupiedRooms();
void bookRoom();
void checkoutRoom();
void displayTotalRevenue();

// Initialize global variables
struct hotel rooms[10];
double totalRevenue = 0.0;

int main() {
   // Initialize hotel rooms
   strcpy(rooms[0].name, "Room 101");
   rooms[0].roomId = 101;
   strcpy(rooms[0].roomType, "Single");
   rooms[0].roomRate = 50.0;
   rooms[0].roomStatus = 0;

   strcpy(rooms[1].name, "Room 102");
   rooms[1].roomId = 102;
   strcpy(rooms[1].roomType, "Single");
   rooms[1].roomRate = 50.0;
   rooms[1].roomStatus = 0;

   strcpy(rooms[2].name, "Room 201");
   rooms[2].roomId = 201;
   strcpy(rooms[2].roomType, "Double");
   rooms[2].roomRate = 75.0;
   rooms[2].roomStatus = 0;

   // Initialize menu variables
   int choice;
   int repeat = 1;

   // Start main loop
   while (repeat == 1) {
      // Display menu options
      printf("\n------------------------");
      printf("\n      Hotel System       ");
      printf("\n------------------------");
      printf("\n1. Display available rooms");
      printf("\n2. Display occupied rooms ");
      printf("\n3. Book a room            ");
      printf("\n4. Checkout a room        ");
      printf("\n5. Display total revenue  ");
      printf("\n6. Exit system            ");
      printf("\n------------------------");

      // Get user input for menu choice
      printf("\nEnter your choice (1-6): ");
      scanf("%d", &choice);

      // Call appropriate function based on user choice
      switch (choice) {
         case 1:
            displayAvailableRooms();
            break;
         case 2:
            displayOccupiedRooms();
            break;
         case 3:
            bookRoom();
            break;
         case 4:
            checkoutRoom();
            break;
         case 5:
            displayTotalRevenue();
            break;
         case 6:
            repeat = 0;
            printf("\nExiting system...");
            break;
         default:
            printf("\nInvalid choice. Try again.");
            break;
      }
   }

   return 0;
}

// Function to display available rooms
void displayAvailableRooms() {
   printf("\nAvailable rooms:");
   for (int i = 0; i < 3; i++) {
      if (rooms[i].roomStatus == 0) {
         printf("\n%s (%s) - $%.2f per night", 
                rooms[i].name, rooms[i].roomType, rooms[i].roomRate);
      }
   }
}

// Function to display occupied rooms
void displayOccupiedRooms() {
   printf("\nOccupied rooms:");
   for (int i = 0; i < 3; i++) {
      if (rooms[i].roomStatus == 1) {
         printf("\n%s (%s) - $%.2f per night", 
                rooms[i].name, rooms[i].roomType, rooms[i].roomRate);
      }
   }
}

// Function to book a room
void bookRoom() {
   // Get user input for room number and number of nights to stay
   int roomNumber, nights;
   printf("\nEnter room number to book: ");
   scanf("%d", &roomNumber);
   printf("Enter number of nights to stay: ");
   scanf("%d", &nights);

   // Search for room and update its status and revenue
   for (int i = 0; i < 3; i++) {
      if (rooms[i].roomId == roomNumber && rooms[i].roomStatus == 0) {
         rooms[i].roomStatus = 1;
         double cost = rooms[i].roomRate * nights;
         totalRevenue += cost;
         printf("\nSuccessfully booked %s (%s) for %d night(s) at $%.2f per night. Total cost: $%.2f", 
                rooms[i].name, rooms[i].roomType, nights, rooms[i].roomRate, cost);
         return;
      }
   }
   // If room not found or already occupied, print error message
   printf("\nRoom not found or already occupied. Try again.");
}

// Function to checkout a room
void checkoutRoom() {
   // Get user input for room number and number of nights to stay
   int roomNumber, nights;
   printf("\nEnter room number to checkout: ");
   scanf("%d", &roomNumber);
   printf("Enter number of nights stayed: ");
   scanf("%d", &nights);

   // Search for room and update its status
   for (int i = 0; i < 3; i++) {
      if (rooms[i].roomId == roomNumber && rooms[i].roomStatus == 1) {
         rooms[i].roomStatus = 0;
         printf("\nSuccessfully checked out %s (%s) after %d night(s).", 
                rooms[i].name, rooms[i].roomType, nights);
         return;
      }
   }
   // If room not found or not occupied, print error message
   printf("\nRoom not found or not occupied. Try again.");
}

// Function to display total revenue
void displayTotalRevenue() {
   printf("\nTotal revenue: $%.2f", totalRevenue);
}