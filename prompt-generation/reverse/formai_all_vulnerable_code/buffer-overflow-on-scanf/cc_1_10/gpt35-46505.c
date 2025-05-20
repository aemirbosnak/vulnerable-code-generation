//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold information of guests
struct Guest {
    int id;
    char name[100];
    char address[200];
    char phone[20];
    char email[50];
    int roomNumber;
    int daysOfStay;
    int totalCost;
};

// Function to display the menu to the user
void displayMenu() {
    printf("\n==============================\n");
    printf("C Hotel Management System\n");
    printf("==============================\n");
    printf("1. Add Guest\n");
    printf("2. Show Guest Details\n");
    printf("3. Delete Guest\n");
    printf("4. Check Out\n");
    printf("5. Exit\n");
    printf("==============================\n");
}

// Function to calculate the total cost of stay for a guest
void calculateCost(struct Guest *guest) {
    int roomCost = 100; // cost per day for a room
    guest->totalCost = roomCost * guest->daysOfStay;
}

int main() {
    int choice;
    int idCounter = 1; // to keep track of guest ids
    int numGuests = 0; // to keep track of number of guests
    struct Guest guests[100]; // array to hold guest information
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // add guest
                printf("\nAdding Guest\n");
                struct Guest newGuest;
                
                // set guest id
                newGuest.id = idCounter;
                idCounter++;
                
                // get guest info from user
                printf("Enter Guest Name: ");
                scanf("%s", newGuest.name);
                printf("Enter Guest Address: ");
                scanf("%s", newGuest.address);
                printf("Enter Guest Phone: ");
                scanf("%s", newGuest.phone);
                printf("Enter Guest Email: ");
                scanf("%s", newGuest.email);
                printf("Enter Room Number: ");
                scanf("%d", &newGuest.roomNumber);
                printf("Enter Days of Stay: ");
                scanf("%d", &newGuest.daysOfStay);
                
                // calculate total cost
                calculateCost(&newGuest);
                
                // add guest to array
                guests[numGuests] = newGuest;
                numGuests++;
                
                printf("Guest Added Successfully!\n");
                break;
            
            case 2: // show guest details
                printf("\nGuest Details\n");
                int guestId;
                printf("Enter Guest Id: ");
                scanf("%d", &guestId);
                
                int guestFound = 0;
                for(int i = 0; i < numGuests; i++) {
                    if(guests[i].id == guestId) {
                        printf("Name: %s\n", guests[i].name);
                        printf("Address: %s\n", guests[i].address);
                        printf("Phone: %s\n", guests[i].phone);
                        printf("Email: %s\n", guests[i].email);
                        printf("Room Number: %d\n", guests[i].roomNumber);
                        printf("Days of Stay: %d\n", guests[i].daysOfStay);
                        printf("Total Cost: $%d\n", guests[i].totalCost);
                        guestFound = 1;
                        break;
                    }
                }
                if(!guestFound) {
                    printf("Guest with given Id not found!\n");
                }
                break;
            
            case 3: // delete guest
                printf("\nDeleting Guest\n");
                int guestIdToDelete;
                printf("Enter Guest Id: ");
                scanf("%d", &guestIdToDelete);
                
                int guestDeleted = 0;
                for(int i = 0; i < numGuests; i++) {
                    if(guests[i].id == guestIdToDelete) {
                        for(int j = i; j < numGuests - 1; j++) {
                            guests[j] = guests[j + 1];
                        }
                        numGuests--;
                        guestDeleted = 1;
                        printf("Guest Deleted Successfully!\n");
                        break;
                    }
                }
                if(!guestDeleted) {
                    printf("Guest with given Id not found!\n");
                }
                break;
                
            case 4: // check out
                printf("\nCheck Out\n");
                int guestIdToCheckOut;
                printf("Enter Guest Id: ");
                scanf("%d", &guestIdToCheckOut);
                
                int guestCheckedOut = 0;
                for(int i = 0; i < numGuests; i++) {
                    if(guests[i].id == guestIdToCheckOut) {
                        int cost = guests[i].totalCost;
                        for(int j = i; j < numGuests - 1; j++) {
                            guests[j] = guests[j + 1];
                        }
                        numGuests--;
                        guestCheckedOut = 1;
                        printf("Guest Checked Out Successfully!\n");
                        printf("Total Cost: $%d\n", cost);
                        break;
                    }
                }
                if(!guestCheckedOut) {
                    printf("Guest with given Id not found!\n");
                }
                break;
                
            case 5: // exit
                printf("\nThank You for using C Hotel Management System!\n");
                break;
            
            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 5);
    
    return 0;
}