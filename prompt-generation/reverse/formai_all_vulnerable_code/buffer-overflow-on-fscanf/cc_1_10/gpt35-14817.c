//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int roomNumber;
   char guestName[50];
   char checkInDate[15];
   char checkOutDate[15];
   int roomType; // 1 for Single, 2 for Double, 3 for Suite
   int breakfastIncluded; // 0 for No, 1 for Yes
   int occupied; // 0 for No, 1 for Yes
} Room;

// Function Prototypes
void displayMenu(Room rooms[], int numRooms);
int checkRoomAvailability(Room rooms[], int roomNum);
void bookRoom(Room *room);
void editBooking(Room rooms[]);
void cancelBooking(Room rooms[]);
void displayBookedRooms(Room rooms[]);
void saveToFile(Room rooms[], int numRooms);
void readFromFile(Room *rooms);
void displayRoom(Room room);

int main() {
   char option;
   int i;
   int numRooms = 3; // Set to the number of rooms in hotel
   Room hotelRooms[numRooms];
    
   // Load data from file
   readFromFile(hotelRooms);
    
   do {
      displayMenu(hotelRooms, numRooms);
      
      // Get option from user
      printf("\nEnter option: ");
      scanf(" %c", &option);
      
      switch(option) {
         case '1':
            printf("\nBooking Details\n");
            printf("------------------\n");
            bookRoom(hotelRooms);
            // Save data to file after booking
            saveToFile(hotelRooms, numRooms);
            break;
            
         case '2':
            printf("\nEdit Booking\n");
            printf("------------------\n");
            editBooking(hotelRooms);
            // Save data to file after editing
            saveToFile(hotelRooms, numRooms);
            break;
            
         case '3':
            printf("\nCancel Booking\n");
            printf("------------------\n");
            cancelBooking(hotelRooms);
            // Save data to file after cancelling
            saveToFile(hotelRooms, numRooms);
            break;
            
         case '4':
            displayBookedRooms(hotelRooms);
            break;
            
         case '5':
            printf("\nExiting Hotel Management System...\n");
            // Save data to file before exit
            saveToFile(hotelRooms, numRooms);
            break;
            
         default:
            printf("\nInvalid option. Try again.\n");
            break;
      }
      printf("\nPress Enter to continue...");
      getchar();
      getchar();
      system("clear"); // Clear console for next menu display
      
   } while (option != '5');
   
   return 0;
}

void displayMenu(Room rooms[], int numRooms) {
   int availableRooms = 0, bookedRooms = 0;
   int i;
   for (i = 0; i < numRooms; i++) {
      if (rooms[i].occupied == 1) {
         bookedRooms++;
      } else {
         availableRooms++;
      }
   }
   printf("Hotel Management System\n");
   printf("-------------------------\n\n");
   printf("Number of Rooms Available: %d\n", availableRooms);
   printf("Number of Rooms Booked: %d\n", bookedRooms);
   printf("-------------------------\n");
   printf("1. Book Room\n");
   printf("2. Edit Booking\n");
   printf("3. Cancel Booking\n");
   printf("4. Display Booked Rooms\n");
   printf("5. Exit\n\n");
}

int checkRoomAvailability(Room rooms[], int roomNum) {
   int i;
   for (i = 0; i < sizeof(rooms); i++) {
      if (rooms[i].roomNumber == roomNum && rooms[i].occupied == 0) {
         return 1; // Room is available
      }
   }
   return 0; // Room is not available or does not exist
}

void bookRoom(Room *room) {
   int roomNum, validRoom = 0, roomType, breakfastIncluded;
   char guestName[50], checkInDate[15], checkOutDate[15];
   
   // Get user input for booking details
   printf("Enter Room Number: ");
   scanf("%d", &roomNum);
   if (checkRoomAvailability(room, roomNum) == 1) {
      validRoom = 1;
   } else {
      validRoom = 0;
      printf("\nRoom is not available or does not exist. Booking failed.\n");
      return;
   }
   printf("Enter Guest Name: ");
   scanf("%s", guestName);
   printf("Enter Check-in Date (dd/mm/yyyy): ");
   scanf("%s", checkInDate);
   printf("Enter Check-out Date (dd/mm/yyyy): ");
   scanf("%s", checkOutDate);
   printf("Enter Room Type (1 for Single, 2 for Double, 3 for Suite): ");
   scanf("%d", &roomType);
   printf("Is Breakfast Included? (0 for No, 1 for Yes): ");
   scanf("%d", &breakfastIncluded);
   
   // Store booking details in room object
   room[roomNum-1].roomNumber = roomNum;
   strcpy(room[roomNum-1].guestName, guestName);
   strcpy(room[roomNum-1].checkInDate, checkInDate);
   strcpy(room[roomNum-1].checkOutDate, checkOutDate);
   room[roomNum-1].roomType = roomType;
   room[roomNum-1].breakfastIncluded = breakfastIncluded;
   room[roomNum-1].occupied = 1;
   
   // Display booking details
   printf("\nBooking Successful\n");
   printf("---------------------\n");
   displayRoom(room[roomNum-1]);
}

void editBooking(Room rooms[]) {
   int roomNum, validRoom = 0, index;
   char guestName[50], checkInDate[15], checkOutDate[15];
   int roomType, breakfastIncluded;
   int i;
   
   // Get user input for room number to edit
   printf("Enter Room Number to Edit: ");
   scanf("%d", &roomNum);
   
   // Check if room is valid and occupied
   for (i = 0; i < sizeof(rooms); i++) {
      if (rooms[i].roomNumber == roomNum && rooms[i].occupied == 1) {
         validRoom = 1;
         index = i;
         break;
      }
   }
   
   // If room is valid and occupied, proceed to edit booking details
   if (validRoom == 1) {
      printf("Enter New Guest Name: ");
      scanf("%s", guestName);
      printf("Enter New Check-in Date (dd/mm/yyyy): ");
      scanf("%s", checkInDate);
      printf("Enter New Check-out Date (dd/mm/yyyy): ");
      scanf("%s", checkOutDate);
      printf("Enter New Room Type (1 for Single, 2 for Double, 3 for Suite): ");
      scanf("%d", &roomType);
      printf("Is Breakfast Included? (0 for No, 1 for Yes): ");
      scanf("%d", &breakfastIncluded);
      
      // Update booking details in room object
      strcpy(rooms[index].guestName, guestName);
      strcpy(rooms[index].checkInDate, checkInDate);
      strcpy(rooms[index].checkOutDate, checkOutDate);
      rooms[index].roomType = roomType;
      rooms[index].breakfastIncluded = breakfastIncluded;
      
      // Display updated booking details
      printf("\nBooking Updated\n");
      printf("---------------------\n");
      displayRoom(rooms[index]);
   } else {
      printf("\nRoom is not valid or not occupied. Edit failed.\n");
   }
}

void cancelBooking(Room rooms[]) {
   int roomNum, validRoom = 0, index;
   int i;
   
   // Get user input for room number to cancel
   printf("Enter Room Number to Cancel: ");
   scanf("%d", &roomNum);
   
   // Check if room is valid and occupied
   for (i = 0; i < sizeof(rooms); i++) {
      if (rooms[i].roomNumber == roomNum && rooms[i].occupied == 1) {
         validRoom = 1;
         index = i;
         break;
      }
   }
   
   // If room is valid and occupied, proceed to cancel booking
   if (validRoom == 1) {
      // Remove booking details from room object
      rooms[index].roomNumber = 0;
      strcpy(rooms[index].guestName, "");
      strcpy(rooms[index].checkInDate, "");
      strcpy(rooms[index].checkOutDate, "");
      rooms[index].roomType = 0;
      rooms[index].breakfastIncluded = 0;
      rooms[index].occupied = 0;
      
      printf("\nBooking Cancelled\n");
   } else {
      printf("\nRoom is not valid or not occupied. Cancellation failed.\n");
   }
}

void displayBookedRooms(Room rooms[]) {
   int i;
   
   printf("\nBooked Rooms\n");
   printf("--------------------\n");
   for (i = 0; i < sizeof(rooms); i++) {
      if (rooms[i].occupied == 1) {
         displayRoom(rooms[i]);
      }
   }
}

void saveToFile(Room rooms[], int numRooms) {
   FILE *fp;
   int i;
   
   fp = fopen("hotel_data.txt", "w");
   
   for (i = 0; i < numRooms; i++) {
      fprintf(fp, "%d\n", rooms[i].roomNumber);
      fprintf(fp, "%s\n", rooms[i].guestName);
      fprintf(fp, "%s\n", rooms[i].checkInDate);
      fprintf(fp, "%s\n", rooms[i].checkOutDate);
      fprintf(fp, "%d\n", rooms[i].roomType);
      fprintf(fp, "%d\n", rooms[i].breakfastIncluded);
      fprintf(fp, "%d\n", rooms[i].occupied);
      fprintf(fp, "\n"); // Add new line after each booking data for readability
   }
   
   fclose(fp);
}

void readFromFile(Room *rooms) {
   FILE *fp;
   int i;
   
   fp = fopen("hotel_data.txt", "r");
   
   if (fp != NULL) {
      for (i = 0; i < sizeof(rooms); i++) {
         fscanf(fp, "%d", &rooms[i].roomNumber);
         fscanf(fp, "%s", rooms[i].guestName);
         fscanf(fp, "%s", rooms[i].checkInDate);
         fscanf(fp, "%s", rooms[i].checkOutDate);
         fscanf(fp, "%d", &rooms[i].roomType);
         fscanf(fp, "%d", &rooms[i].breakfastIncluded);
         fscanf(fp, "%d", &rooms[i].occupied);
      }
   }
   
   fclose(fp);
}

void displayRoom(Room room) {
   printf("Room Number: %d\n", room.roomNumber);
   printf("Guest Name: %s\n", room.guestName);
   printf("Check-in Date: %s\n", room.checkInDate);
   printf("Check-out Date: %s\n", room.checkOutDate);
   printf("Room Type: %d\n", room.roomType);
   printf("Breakfast Included: %s\n", room.breakfastIncluded == 1 ? "Yes" : "No");
   printf("--------------------\n");
}