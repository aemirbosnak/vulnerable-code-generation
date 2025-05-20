//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int roomNum;
  char roomType[20];
  int numBeds;
  float rate;
  int occupied;
} Room;

typedef struct {
  int guestID;
  char guestName[30];
  int numOfGuests;
  int numNights;
  int roomNum;
  float bill;
} Reservation;

Reservation reservations[20];
Room rooms[20];

void addRoom() {
  int i;
  for (i = 0; i < 20; i++) {
    if (rooms[i].roomNum == 0) {
      printf("Enter Room Number: ");
      scanf("%d", &rooms[i].roomNum);
      printf("Enter Room Type: ");
      scanf("%s", rooms[i].roomType);
      printf("Enter Number of Beds: ");
      scanf("%d", &rooms[i].numBeds);
      printf("Enter Room Rate: ");
      scanf("%f", &rooms[i].rate);
      rooms[i].occupied = 0;
      break;
    }
  }
}

void displayRooms() {
  int i;
  printf("Room Number\tRoom Type\tNumber of Beds\tRate\tOccupied\n");
  for (i = 0; i < 20; i++) {
    if (rooms[i].roomNum != 0) {
      printf("%d\t%s\t%d\t%f\t%d\n", rooms[i].roomNum, rooms[i].roomType, rooms[i].numBeds, rooms[i].rate, rooms[i].occupied);
      }
  }
}

void addReservation() {
  int i;
  for (i = 0; i < 20; i++) {
    if (reservations[i].guestID == 0) {
      printf("Enter Guest ID: ");
      scanf("%d", &reservations[i].guestID);
      printf("Enter Guest Name: ");
      scanf("%s", reservations[i].guestName);
      printf("Enter Number of Guests: ");
      scanf("%d", &reservations[i].numOfGuests);
      printf("Enter Number of Nights: ");
      scanf("%d", &reservations[i].numNights);
      printf("Enter Room Number: ");
      scanf("%d", &reservations[i].roomNum);
      int j;
      for (j = 0; j < 20; j++) {
        if (rooms[j].roomNum == reservations[i].roomNum) {
          rooms[j].occupied = 1;
          break;
        }
      }
      reservations[i].bill = reservations[i].numNights * rooms[j].rate;
      break;
    }
  }
}

void displayReservations() {
  int i;
  printf("Guest ID\tGuest Name\tNumber of Guests\tNumber of Nights\tRoom Number\tBill\n");
  for (i = 0; i < 20; i++) {
    if (reservations[i].guestID != 0) {
      printf("%d\t%s\t%d\t%d\t%d\t%f\n", reservations[i].guestID, reservations[i].guestName, reservations[i].numOfGuests, reservations[i].numNights, reservations[i].roomNum, reservations[i].bill);
    }
  }
}

void deleteReservation(int guestID) {
  int i;
  for (i = 0; i < 20; i++) {
    if (reservations[i].guestID == guestID) {
      reservations[i].guestID = 0;
      rooms[reservations[i].roomNum - 1].occupied = 0;
      break;
    }
  }
}

int main() {
  int choice;
  int guestID;
  while (1) {
    printf("1. Add Room\n");
    printf("2. Display Rooms\n");
    printf("3. Add Reservation\n");
    printf("4. Display Reservations\n");
    printf("5. Delete Reservation\n");
    printf("6. Exit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addRoom();
        break;
      case 2:
        displayRooms();
        break;
      case 3:
        addReservation();
        break;
      case 4:
        displayReservations();
        break;
      case 5:
        printf("Enter Guest ID: ");
        scanf("%d", &guestID);
        deleteReservation(guestID);
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid Choice\n");
    }
  }
  return 0;
}