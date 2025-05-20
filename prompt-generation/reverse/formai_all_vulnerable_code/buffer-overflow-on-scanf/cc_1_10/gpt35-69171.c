//FormAI DATASET v1.0 Category: Hotel Management System ; Style: retro
#include<stdio.h>
#include<string.h>

//Function to generate unique ID number for each guest
int generateID(int reservationCounter){
    return 1000 + reservationCounter + 1;
}

//Guest structure
struct Guest{
    int id;
    char name[50];
    int roomNumber;
    char checkInDate[20];
    char checkOutDate[20];
};

//Global variables
struct Guest guests[20];
int reservationCounter = 0;

//Function to display main menu
void displayMainMenu(){
    printf("\n\n");
    printf("******************************\n");
    printf("Welcome to C Hotel Management\n");
    printf("******************************\n");
    printf("1. Make a reservation\n");
    printf("2. View reservation details\n");
    printf("3. Modify reservation\n");
    printf("4. Cancel reservation\n");
    printf("5. Exit\n");
    printf("******************************\n");
}

//Function to make reservation
void makeReservation(){
    int roomId;
    char checkInDate[20];
    char checkOutDate[20];
    char name[50];
    
    printf("\n\n");
    printf("******************************\n");
    printf("         Make a Reservation   \n");
    printf("******************************\n");
    printf("Enter Guest Name: ");
    scanf("%s", &name);
    printf("Enter Room Number: ");
    scanf("%d", &roomId);
    printf("Enter Check-in Date (yyyy-mm-dd): ");
    scanf("%s", &checkInDate);
    printf("Enter Check-out Date (yyyy-mm-dd): ");
    scanf("%s", &checkOutDate);
    
    int id = generateID(reservationCounter);
    
    struct Guest guest = {
        id,
        name,
        roomId,
        checkInDate,
        checkOutDate
    };
    
    guests[reservationCounter] = guest;
    
    printf("\nReservation Made Successfully!\nYour Unique ID is: %d", id);
    
    reservationCounter++;
}

//Function to view reservation details
void viewReservation(){
    int id;
    
    printf("\n\n");
    printf("******************************\n");
    printf("      View Reservation Details\n");
    printf("******************************\n");
    printf("Enter Unique ID: ");
    scanf("%d", &id);
    
    for(int i=0; i<reservationCounter ;i++){
        struct Guest guest = guests[i];
        if(guest.id == id){
            printf("\nGuest Name: %s", guest.name);
            printf("\nRoom Number: %d", guest.roomNumber);
            printf("\nCheck-in Date: %s", guest.checkInDate);
            printf("\nCheck-out Date: %s", guest.checkOutDate);
            return;
        }
    }
    
    printf("\nNo Reservation Found for the entered ID.");
}

//Function to modify reservation
void modifyReservation(){
    int id;
    int choice;
    
    printf("\n\n");
    printf("******************************\n");
    printf("        Modify Reservation     \n");
    printf("******************************\n");
    printf("Enter Unique ID: ");
    scanf("%d", &id);
    
    for(int i=0; i<reservationCounter ;i++){
        struct Guest guest = guests[i];
        if(guest.id == id){
            printf("\nCurrent details:");
            printf("\nGuest Name: %s", guest.name);
            printf("\nRoom Number: %d", guest.roomNumber);
            printf("\nCheck-in Date: %s", guest.checkInDate);
            printf("\nCheck-out Date: %s", guest.checkOutDate);
            printf("\n\n1. Change Guest Name\n");
            printf("2. Change Room Number\n");
            printf("3. Change Check-in Date\n");
            printf("4. Change Check-out Date\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            
            scanf("%d", &choice);
            
            switch(choice){
                case 1:
                    printf("\nEnter New Guest Name: ");
                    scanf("%s", &guests[i].name);
                    break;
                case 2:
                    printf("\nEnter New Room Number: ");
                    scanf("%d", &guests[i].roomNumber);
                    break;
                case 3:
                    printf("\nEnter New Check-in Date (yyyy-mm-dd): ");
                    scanf("%s", &guests[i].checkInDate);
                    break;
                case 4:
                    printf("\nEnter New Check-out Date (yyyy-mm-dd): ");
                    scanf("%s", &guests[i].checkOutDate);
                    break;
                case 5:
                    return;
                default:
                    printf("\nInvalid Input.");
                    return;
            }
            printf("\nDetails Updated Successfully!\n");
            return;
        }
    }
    
    printf("\nNo Reservation Found for the entered ID.");
}

//Function to cancel reservation
void cancelReservation(){
    int id;
    
    printf("\n\n");
    printf("******************************\n");
    printf("        Cancel Reservation     \n");
    printf("******************************\n");
    printf("Enter Unique ID: ");
    scanf("%d", &id);
    
    for(int i=0; i<reservationCounter ;i++){
        struct Guest guest = guests[i];
        if(guest.id == id){
            for(int j=i; j<reservationCounter-1 ;j++){
                guests[j] = guests[j+1];
            }
            reservationCounter--;
            printf("\nReservation Cancelled Successfully!\n");
            return;
        }
    }
    
    printf("\nNo Reservation Found for the entered ID.");
}

//Main function
int main(){
    int choice;
    
    while(1){
        displayMainMenu();
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                makeReservation();
                break;
            case 2:
                viewReservation();
                break;
            case 3:
                modifyReservation();
                break;
            case 4:
                cancelReservation();
                break;
            case 5:
                printf("\nExiting C Hotel Management System.\n\n");
                return 0;
            default:
                printf("\nInvalid Input. Please try again.\n");
                break;
        }
    }
    
    return 0;
}