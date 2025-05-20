//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to represent a guest
struct Guest {
    char name[50];
    int roomNumber;
    char checkInDate[15];
    char checkOutDate[15];
};

//Function to generate new guest
struct Guest* newGuest(char name[], int roomNumber, char checkInDate[], char checkOutDate[]) {
    struct Guest* guest = (struct Guest*) malloc(sizeof(struct Guest));
    strcpy(guest->name, name);
    guest->roomNumber = roomNumber;
    strcpy(guest->checkInDate, checkInDate);
    strcpy(guest->checkOutDate, checkOutDate);
  
    return guest;
}

int main() {
    int option = 0;
    char name[50], checkInDate[15], checkOutDate[15];
    int roomNumber = 0;
    struct Guest *guest;
  
    do {
        printf("Welcome to the C Hotel Management System\n");
        printf("1. Add New Guest\n");
        printf("2. View All Guests\n");
        printf("3. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &option);
      
        switch(option) {
            case 1:
                printf("Enter Guest Name: ");
                scanf("%s", name);
                printf("Enter Room Number: ");
                scanf("%d", &roomNumber);
                printf("Enter Check In Date (dd/mm/yyyy): ");
                scanf("%s", checkInDate);
                printf("Enter Check Out Date (dd/mm/yyyy): ");
                scanf("%s", checkOutDate);
              
                guest = newGuest(name, roomNumber, checkInDate, checkOutDate);
                printf("New Guest Added Successfully\n");
                break;
          
            case 2:
                printf("Viewing All Guests\n");
                printf("--------------------------------------------------------------\n");
                printf("Name\tRoom No.\tCheck-In Date\tCheck-Out Date\n");
                printf("--------------------------------------------------------------\n");
                printf("%s\t%d\t%s\t%s\n", guest->name, guest->roomNumber, guest->checkInDate, guest->checkOutDate);
                printf("--------------------------------------------------------------\n");
                break;
          
            case 3:
                printf("Exiting C Hotel Management System\n");
                exit(0);
          
            default:
                printf("Invalid Option\n");
                break;
        }
    } while(option != 3);
  
    return 0;
}