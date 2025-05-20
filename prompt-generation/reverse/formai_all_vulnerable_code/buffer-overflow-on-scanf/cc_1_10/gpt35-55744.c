//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <string.h>

struct Room {
  char name[50];
  int floor;
  int roomNumber;
  int beds;
  double price;
  char available[10];
};

// Declare function prototypes
void addRoom(struct Room rooms[], int *numberOfRooms);
void removeRoom(struct Room rooms[], int *numberOfRooms);
void displayRooms(struct Room rooms[], int *numberOfRooms);
void searchRooms(struct Room rooms[], int *numberOfRooms, char *available);
void bookRoom(struct Room rooms[], int *numberOfRooms);
void checkoutRoom(struct Room rooms[], int *numberOfRooms);

int main() {
  struct Room rooms[50];
  int numberOfRooms = 0;
  int option = 0;
  char available[10];
  
  do {
    printf("\nWelcome to C Hotel Management System\n");
    printf("1. Add Room\n");
    printf("2. Remove Room\n");
    printf("3. Display Rooms\n");
    printf("4. Search Rooms\n");
    printf("5. Book Room\n");
    printf("6. Checkout Room\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        addRoom(rooms, &numberOfRooms);
        break;
      case 2:
        removeRoom(rooms, &numberOfRooms);
        break;
      case 3:
        displayRooms(rooms, &numberOfRooms);
        break;
      case 4:
        printf("\nEnter 'Yes' for available rooms or 'No' for occupied rooms: ");
        scanf("%s", &available);
        searchRooms(rooms, &numberOfRooms, available);
        break;
      case 5:
        bookRoom(rooms, &numberOfRooms);
        break;
      case 6:
        checkoutRoom(rooms, &numberOfRooms);
        break;
      case 7:
        printf("\nThank you for using C Hotel Management System.\n");
        break;
      default:
        printf("\nInvalid Option! Please choose again.\n");
        break;
    }
  } while(option != 7);

  return 0;
}

// Function to add room in the rooms array
void addRoom(struct Room rooms[], int *numberOfRooms) {
  printf("\nEnter room details:\n");
  printf("Name: ");
  scanf("%s", rooms[*numberOfRooms].name);
  printf("Floor: ");
  scanf("%d", &rooms[*numberOfRooms].floor);
  printf("Room Number: ");
  scanf("%d", &rooms[*numberOfRooms].roomNumber);
  printf("Beds: ");
  scanf("%d", &rooms[*numberOfRooms].beds);
  printf("Price per Day: ");
  scanf("%lf", &rooms[*numberOfRooms].price);
  printf("Availability(Yes/No): ");
  scanf("%s", rooms[*numberOfRooms].available);

  (*numberOfRooms)++;
}

// Function to remove room from the rooms array
void removeRoom(struct Room rooms[], int *numberOfRooms) {
  int roomNumber;
  printf("\nEnter the room number to be removed: ");
  scanf("%d", &roomNumber);

  for(int i = 0; i < *numberOfRooms; i++) {
    if(rooms[i].roomNumber == roomNumber) {
      for(int j = i; j < *numberOfRooms-1; j++) {
        rooms[j] = rooms[j+1];
      }
      (*numberOfRooms)--;
      printf("\nRoom with Room Number %d removed successfully.\n", roomNumber);
      return;
    }
  }

  printf("\nRoom with Room Number %d not found.\n", roomNumber);
}

// Function to display all the rooms in the rooms array
void displayRooms(struct Room rooms[], int *numberOfRooms) {
  printf("\nAll Rooms:\n");
  printf("S.No.\tRoom Name\tFloor\tRoom Number\tBeds\tPrice per Day\tAvailability\n");
  for(int i = 0; i < *numberOfRooms; i++) {
    printf("%d\t%s\t\t%d\t%d\t\t%d\t$%.2lf\t\t%s\n", i+1, rooms[i].name, rooms[i].floor, rooms[i].roomNumber, rooms[i].beds, rooms[i].price, rooms[i].available);
  }
}

// Function to search rooms based on availability
void searchRooms(struct Room rooms[], int *numberOfRooms, char *available) {
  int count = 0;
  printf("\nSearch Results:\n");
  printf("S.No.\tRoom Name\tFloor\tRoom Number\tBeds\tPrice per Day\tAvailability\n");
  for(int i = 0; i < *numberOfRooms; i++) {
    if(strcmp(rooms[i].available, available) == 0) {
      printf("%d\t%s\t\t%d\t%d\t\t%d\t$%.2lf\t\t%s\n", count+1, rooms[i].name, rooms[i].floor, rooms[i].roomNumber, rooms[i].beds, rooms[i].price, rooms[i].available);
      count++;
    }
  }
  if(count == 0) {
    printf("\nNo %s rooms available.\n", available);
  } else {
    printf("\n%d %s rooms available.\n", count, available);
  }
}

// Function to book a room
void bookRoom(struct Room rooms[], int *numberOfRooms) {
  int roomNumber;
  printf("\nEnter the room number to be booked: ");
  scanf("%d", &roomNumber);

  for(int i = 0; i < *numberOfRooms; i++) {
    if(rooms[i].roomNumber == roomNumber) {
      if(strcmp(rooms[i].available, "Yes") == 0) {
        strcpy(rooms[i].available, "No");
        printf("\nRoom with Room Number %d booked successfully.\n", roomNumber);
        return;
      } else {
        printf("\nRoom with Room Number %d is already booked.\n", roomNumber);
        return;
      }
    }
  }

  printf("\nRoom with Room Number %d not found.\n", roomNumber);
}

// Function to checkout a room
void checkoutRoom(struct Room rooms[], int *numberOfRooms) {
  int roomNumber;
  printf("\nEnter the room number to be checked out: ");
  scanf("%d", &roomNumber);

  for(int i = 0; i < *numberOfRooms; i++) {
    if(rooms[i].roomNumber == roomNumber) {
      if(strcmp(rooms[i].available, "No") == 0) {
        strcpy(rooms[i].available, "Yes");
        printf("\nRoom with Room Number %d checked out successfully.\n", roomNumber);
        return;
      } else {
        printf("\nRoom with Room Number %d is already available.\n", roomNumber);
        return;
      }
    }
  }

  printf("\nRoom with Room Number %d not found.\n", roomNumber);
}