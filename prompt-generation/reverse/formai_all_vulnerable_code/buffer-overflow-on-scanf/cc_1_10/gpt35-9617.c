//FormAI DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the data of each hotel guest
typedef struct GuestData {
  char name[30];
  int age;
  char gender;
  char address[50];
  char roomType[20];
  int numOfDays;
  int roomNum;
  float totalCost;
} GuestData;

// Function to display the menu
void displayMenu() {
  printf("Welcome to C Hotel Management System\n");
  printf("1. Check-in a guest\n");
  printf("2. Check-out a guest\n");
  printf("3. View guest list\n");
  printf("4. Search for a guest\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

// Function to add a new guest to the database
void checkIn(GuestData *guests, int *numOfGuests) {
  printf("Enter guest name: ");
  scanf("%s", guests[*numOfGuests].name);
  printf("Enter guest age: ");
  scanf("%d", &guests[*numOfGuests].age);
  printf("Enter guest gender (M/F/O): ");
  scanf(" %c", &guests[*numOfGuests].gender);
  printf("Enter guest address: ");
  scanf("%s", guests[*numOfGuests].address);
  printf("Enter room type (Single/Double/Suite): ");
  scanf("%s", guests[*numOfGuests].roomType);
  printf("Enter number of days of stay: ");
  scanf("%d", &guests[*numOfGuests].numOfDays);
  printf("Enter room number: ");
  scanf("%d", &guests[*numOfGuests].roomNum);
  guests[*numOfGuests].totalCost = 0;
  if (strcmp(guests[*numOfGuests].roomType, "Single") == 0) {
    guests[*numOfGuests].totalCost += 50 * guests[*numOfGuests].numOfDays;
  } else if (strcmp(guests[*numOfGuests].roomType, "Double") == 0) {
    guests[*numOfGuests].totalCost += 80 * guests[*numOfGuests].numOfDays;
  } else if (strcmp(guests[*numOfGuests].roomType, "Suite") == 0) {
    guests[*numOfGuests].totalCost += 120 * guests[*numOfGuests].numOfDays;
  }
  printf("Check-in successful. Guest ID is %d\n", *numOfGuests + 1);
  *numOfGuests += 1;
}

// Function to update the total cost for a guest
void updateCost(GuestData *guests, int guestID) {
  int numOfDays = guests[guestID].numOfDays;
  if (strcmp(guests[guestID].roomType, "Single") == 0) {
    guests[guestID].totalCost += 50 * numOfDays;
  } else if (strcmp(guests[guestID].roomType, "Double") == 0) {
    guests[guestID].totalCost += 80 * numOfDays;
  } else if (strcmp(guests[guestID].roomType, "Suite") == 0) {
    guests[guestID].totalCost += 120 * numOfDays;
  }
}

// Function to check-out a guest and calculate the total cost
void checkOut(GuestData *guests, int *numOfGuests) {
  int guestID;
  printf("Enter guest ID: ");
  scanf("%d", &guestID);
  if (guestID <= 0 || guestID > *numOfGuests) {
    printf("Invalid guest ID\n");
    return;
  }
  updateCost(guests, guestID - 1);
  printf("Check-out successful\n");
  printf("Guest name: %s\n", guests[guestID - 1].name);
  printf("Guest age: %d\n", guests[guestID - 1].age);
  printf("Guest gender: %c\n", guests[guestID - 1].gender);
  printf("Guest address: %s\n", guests[guestID - 1].address);
  printf("Room type: %s\n", guests[guestID - 1].roomType);
  printf("Number of days of stay: %d\n", guests[guestID - 1].numOfDays);
  printf("Room number: %d\n", guests[guestID - 1].roomNum);
  printf("Total cost: $%.2f\n", guests[guestID - 1].totalCost);
  // Remove the guest from the database and shift remaining guests up
  for (int i = guestID - 1; i < *numOfGuests - 1; i++) {
    guests[i] = guests[i + 1];
  }
  *numOfGuests -= 1;
}

// Function to display the list of all guests
void viewGuestList(GuestData *guests, int numOfGuests) {
  printf("Guest List\n");
  printf("ID\tName\tAge\tGender\tAddress\t\tRoom Type\tDays\tRoom Number\tTotal Cost\n");
  for (int i = 0; i < numOfGuests; i++) {
    printf("%d\t", i + 1);
    printf("%s\t", guests[i].name);
    printf("%d\t", guests[i].age);
    printf("%c\t", guests[i].gender);
    printf("%s\t", guests[i].address);
    printf("%s\t", guests[i].roomType);
    printf("%d\t", guests[i].numOfDays);
    printf("%d\t\t", guests[i].roomNum);
    printf("$%.2f\n", guests[i].totalCost);
  }
}

// Function to search for a guest by name
void searchGuest(GuestData *guests, int numOfGuests) {
  char guestName[30];
  printf("Enter guest name: ");
  scanf("%s", guestName);
  int found = 0;
  for (int i = 0; i < numOfGuests; i++) {
    if (strcmp(guests[i].name, guestName) == 0) {
      printf("Guest found\n");
      printf("ID: %d\n", i + 1);
      printf("Name: %s\n", guests[i].name);
      printf("Age: %d\n", guests[i].age);
      printf("Gender: %c\n", guests[i].gender);
      printf("Address: %s\n", guests[i].address);
      printf("Room Type: %s\n", guests[i].roomType);
      printf("Number of days of stay: %d\n", guests[i].numOfDays);
      printf("Room Number: %d\n", guests[i].roomNum);
      printf("Total Cost: $%.2f\n", guests[i].totalCost);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Guest not found\n");
  }
}

int main() {
  GuestData guests[20];
  int numOfGuests = 0;
  int choice;
  do {
    displayMenu();
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        checkIn(guests, &numOfGuests);
        break;
      case 2:
        checkOut(guests, &numOfGuests);
        break;
      case 3:
        viewGuestList(guests, numOfGuests);
        break;
      case 4:
        searchGuest(guests, numOfGuests);
        break;
      case 5:
        printf("Exiting...");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 5);
  return 0;
}