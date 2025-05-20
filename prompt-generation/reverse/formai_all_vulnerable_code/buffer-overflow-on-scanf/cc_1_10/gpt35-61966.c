//FormAI DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* Definition of the hotel structure */
typedef struct {
   int roomNumber;
   char guestName[30];
   int guestID;
   char checkInDate[20];
   char checkOutDate[20];
} Hotel;

/* Function prototype to display menu */
void displayMenu();

int main() {
   int numRooms, choice;
   printf("Welcome to C Hotel Management system!\n");

   /* Get the number of rooms in the hotel */
   printf("Enter number of rooms in the hotel: ");
   scanf("%d", &numRooms);

   /* Dynamically allocate memory for the hotel */
   Hotel *hotel = (Hotel *) malloc(sizeof(Hotel) * numRooms);

   /* Initialize the hotel */
   for (int i = 0; i < numRooms; i++) {
      hotel[i].roomNumber = i + 1;
      hotel[i].guestName[0] = '\0';
      hotel[i].guestID = 0;
      hotel[i].checkInDate[0] = '\0';
      hotel[i].checkOutDate[0] = '\0';
   }

   /* Display the menu and take user's choice */
   do {
      displayMenu();
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         /* Display all rooms in the hotel */
         case 1: {
            printf("\nRoom\tGuest Name\tGuest ID\tCheck-In Date\tCheck-Out Date\n");
            for (int i = 0; i < numRooms; i++) {
               printf("%d\t%s\t\t%d\t\t%s\t\t%s\n", hotel[i].roomNumber, hotel[i].guestName, hotel[i].guestID, hotel[i].checkInDate, hotel[i].checkOutDate);
            }
            break;
         }

         /* Check-in a guest to a room */
         case 2: {
            int roomNum;
            char guestName[30];
            int guestID;
            char checkInDate[20];
            char checkOutDate[20];

            printf("\nEnter room number: ");
            scanf("%d", &roomNum);

            /* Check if room number is valid */
            if (roomNum < 1 || roomNum > numRooms) {
               printf("\nInvalid room number.");
               break;
            }

            /* Check if room is vacant */
            if (hotel[roomNum - 1].guestName[0] != '\0') {
               printf("\nRoom is already occupied.");
               break;
            }

            printf("\nEnter guest name: ");
            scanf(" %[^\n]s", guestName);

            printf("Enter guest ID: ");
            scanf("%d", &guestID);

            printf("Enter check-in date (dd/mm/yyyy): ");
            scanf(" %[^\n]s", checkInDate);

            printf("Enter check-out date (dd/mm/yyyy): ");
            scanf(" %[^\n]s", checkOutDate);

            /* Update the hotel */
            hotel[roomNum - 1].guestName[0] = '\0';
            strcat(hotel[roomNum - 1].guestName, guestName);
            hotel[roomNum - 1].guestID = guestID;
            hotel[roomNum - 1].checkInDate[0] = '\0';
            strcat(hotel[roomNum - 1].checkInDate, checkInDate);
            hotel[roomNum - 1].checkOutDate[0] = '\0';
            strcat(hotel[roomNum - 1].checkOutDate, checkOutDate);

            printf("\nCheck-in successful.");
            break;
         }

         /* Check-out a guest from a room */
         case 3: {
            int roomNum;

            printf("\nEnter room number: ");
            scanf("%d", &roomNum);

            /* Check if room number is valid */
            if (roomNum < 1 || roomNum > numRooms) {
               printf("\nInvalid room number.");
               break;
            }

            /* Check if room is occupied */
            if (hotel[roomNum - 1].guestName[0] == '\0') {
               printf("\nRoom is already vacant.");
               break;
            }

            /* Update the hotel */
            hotel[roomNum - 1].guestName[0] = '\0';
            hotel[roomNum - 1].guestID = 0;
            hotel[roomNum - 1].checkInDate[0] = '\0';
            hotel[roomNum - 1].checkOutDate[0] = '\0';

            printf("\nCheck-out successful.");
            break;
         }

         /* Terminate the program */
         case 4: {
            printf("\nThank you for using C Hotel Management system!");
            break;
         }

         /* Handle invalid choice */
         default: {
            printf("\nInvalid choice. Please select again.\n");
            break;
         }
      }

      printf("\n");
   } while (choice != 4);

   /* Free the dynamically allocated memory */
   free(hotel);

   return 0;
}

/* Function to display menu */
void displayMenu() {
   printf("\n1 - Display all rooms");
   printf("\n2 - Check-in guest to a room");
   printf("\n3 - Check-out guest from a room");
   printf("\n4 - Exit");
}