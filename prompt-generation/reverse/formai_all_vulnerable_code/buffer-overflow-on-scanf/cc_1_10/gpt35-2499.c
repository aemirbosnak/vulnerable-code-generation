//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to store guest information
struct guest {
  char name[50];
  int roomNum;
  int numDays;
  float roomRate;
};

//Function to add a new guest to the system
void addGuest(struct guest *guestList, int *numGuests) {
  printf("Enter guest name: ");
  fgets(guestList[*numGuests].name, 50, stdin);
  printf("Enter room number: ");
  scanf("%d", &guestList[*numGuests].roomNum);
  printf("Enter number of days: ");
  scanf("%d", &guestList[*numGuests].numDays);
  printf("Enter room rate: ");
  scanf("%f", &guestList[*numGuests].roomRate);
  getchar(); //Clear input buffer
  (*numGuests)++; //Increment number of guests
  printf("Guest added to system!\n");
}

//Function to display all guests in the system
void displayGuests(struct guest *guestList, int numGuests) {
  printf("Guest List\n");
  printf("----------\n");
  for (int i=0; i<numGuests; i++) {
    printf("Name: %s", guestList[i].name);
    printf("Room Number: %d\n", guestList[i].roomNum);
    printf("Number of Days: %d\n", guestList[i].numDays);
    printf("Room Rate: $%.2f per day\n", guestList[i].roomRate);
    printf("\n");
  }
}

//Function to calculate total revenue
float calculateRevenue(struct guest *guestList, int numGuests) {
  float totalRevenue = 0.0;
  for (int i=0; i<numGuests; i++) {
    totalRevenue += (guestList[i].numDays * guestList[i].roomRate);
  }
  return totalRevenue;
}

//Main function to run the program
int main() {
  printf("Welcome to the C Hotel Management System!\n\n");
  
  int numGuests = 0; //Initialize counter for number of guests added
  struct guest guestList[100]; //Initialize array to store guests
  
  while (1) {
    printf("What would you like to do?\n");
    printf("1. Add a new guest\n");
    printf("2. Display guest list\n");
    printf("3. Calculate total revenue\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    getchar(); //Clear input buffer
    
    switch(choice) {
      case 1:
        addGuest(guestList, &numGuests);
        break;
      case 2:
        displayGuests(guestList, numGuests);
        break;
      case 3:
        printf("Total revenue: $%.2f\n", calculateRevenue(guestList, numGuests));
        break;
      case 4:
        printf("Thank you for using the C Hotel Management System!\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
  
  return 0;
}