//FormAI DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
  int id;
  char name[50];
  char address[100];
  char phone[12];
};

struct Room {
  int id;
  char type[25];
  float price;
  int occupied;
  struct Customer customer;
};

void displayMenu() {
  printf("\n============================================\n");
  printf("\t\tHotel Management System\n");
  printf("============================================\n");
  printf("1. Add Room\n");
  printf("2. View Room Details\n");
  printf("3. Book Room\n");
  printf("4. Check-Out Room\n");
  printf("5. Exit\n");
  printf("============================================\n");
}

int main() {
  int choice;
  int numOfRooms = 0;
  struct Room rooms[50];

  do {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Add Room
        printf("Enter Room Details:\n");
        printf("Room ID: ");
        scanf("%d", &rooms[numOfRooms].id);
        printf("Room Type: ");
        scanf("%s", rooms[numOfRooms].type);
        printf("Price: ");
        scanf("%f", &rooms[numOfRooms].price);
        rooms[numOfRooms].occupied = 0;
        numOfRooms++;

        printf("Room Added Successfully!\n");
        break;

      case 2:
        // View Room Details
        printf("Room Details:\n");
        for (int i = 0; i < numOfRooms; i++) {
          printf("Room ID: %d\n", rooms[i].id);
          printf("Room Type: %s\n", rooms[i].type);
          printf("Price: %.2f\n", rooms[i].price);
          if (rooms[i].occupied) {
            printf("Occupied by: %s\n", rooms[i].customer.name);
          } else {
            printf("Status: Vacant\n");
          }
          printf("\n");
        }
        break;

      case 3:
        // Book Room
        printf("Enter Customer Details:\n");
        printf("Customer ID: ");
        scanf("%d", &rooms[numOfRooms].customer.id);
        printf("Name: ");
        scanf("%s", rooms[numOfRooms].customer.name);
        printf("Address: ");
        scanf("%s", rooms[numOfRooms].customer.address);
        printf("Phone Number: ");
        scanf("%s", rooms[numOfRooms].customer.phone);

        printf("Enter Room ID to Book: ");
        int roomToBook;
        scanf("%d", &roomToBook);
        for (int i = 0; i < numOfRooms; i++) {
          if (rooms[i].id == roomToBook && !rooms[i].occupied) {
            rooms[i].occupied = 1;
            rooms[i].customer = rooms[numOfRooms].customer;
            numOfRooms++;
            printf("Room Booked Successfully!\n");
            break;
          } else if (rooms[i].id == roomToBook && rooms[i].occupied) {
            printf("Room is already occupied by %s!\n", rooms[i].customer.name);
            break;
          } else if (i == numOfRooms-1) {
            printf("Invalid Room ID!\n");
            break;
          }
        }
        break;

      case 4:
        // Check-Out Room
        printf("Enter Room ID to Check-Out: ");
        int roomToCheckout;
        scanf("%d", &roomToCheckout);
        for (int i = 0; i < numOfRooms; i++) {
          if (rooms[i].id == roomToCheckout && rooms[i].occupied) {
            rooms[i].occupied = 0;
            printf("Room Checked-Out Successfully!\n");
            break;
          } else if (rooms[i].id == roomToCheckout && !rooms[i].occupied) {
            printf("Room is already vacant!\n");
            break;
          } else if (i == numOfRooms-1) {
            printf("Invalid Room ID!\n");
            break;
          }
        }
        break;

      case 5:
        // Exit
        printf("Thank you for using Hotel Management System!\n");
        break;

      default:
        // Invalid Option
        printf("Invalid Option!\n");
        break;
    }
  } while (choice != 5);

  return 0;
}