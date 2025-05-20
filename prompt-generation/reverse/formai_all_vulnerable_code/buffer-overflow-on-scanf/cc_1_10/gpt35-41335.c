//FormAI DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

//Struct to store details of each room
typedef struct{
    int roomNumber;
    int numOccupants;
    char status;
    float price;
    char guestName[50];
}room;

//Function to display the main menu
void displayMenu(){
    printf("\n\n");
    printf("---------------------------------------------------\n");
    printf("|                    MAIN MENU                    |\n");
    printf("---------------------------------------------------\n");
    printf("| 1. Add a new room                                |\n");
    printf("| 2. Remove an existing room                       |\n");
    printf("| 3. Display all rooms                             |\n");
    printf("| 4. Search for a room                             |\n");
    printf("| 5. Check in a guest                               |\n");
    printf("| 6. Check out a guest                              |\n");
    printf("| 7. Exit                                          |\n");
    printf("---------------------------------------------------\n");
    printf("\n\n");
}

//Function to add a new room to the hotel system
void addRoom(room* rooms, int* numRooms){
    printf("Enter new room number: ");
    scanf("%d", &rooms[*numRooms].roomNumber);
    
    printf("Enter price per night: ");
    scanf("%f", &rooms[*numRooms].price);
    
    rooms[*numRooms].status = 'V'; //Set room as vacant by default
    
    (*numRooms)++; //Update total number of rooms in the system
    printf("\nRoom added successfully!\n");
}

//Function to remove an existing room from the hotel system
void removeRoom(room* rooms, int* numRooms){
    int roomNumberToDelete, found = 0;
    printf("Enter room number to delete: ");
    scanf("%d", &roomNumberToDelete);
    
    //Find the room to delete and shift all rooms after that one back in the array
    for(int i=0; i<*numRooms; i++){
        if(rooms[i].roomNumber == roomNumberToDelete){
            for(int j=i+1; j<*numRooms; j++){
                rooms[j-1] = rooms[j];
            }
            (*numRooms)--; //Update total number of rooms in the system
            found = 1;
            break;
        }
    }
    
    if(found){
        printf("\nRoom deleted successfully!\n");
    }else{
        printf("\nRoom not found!\n");
    }
}

//Function to display all rooms in the hotel system
void displayAllRooms(room* rooms, int* numRooms){
    printf("\n\n");
    printf("--------------------------------------------------\n");
    printf("|  Room #  |  Capacity  |  Status  |  Guest Name  |\n");
    printf("--------------------------------------------------\n");
    
    for(int i=0; i<*numRooms; i++){
        printf("|   %3d    |    %3d     |     %c     |  %10s  |\n", rooms[i].roomNumber, rooms[i].numOccupants, rooms[i].status, rooms[i].guestName);
    }
    
    printf("--------------------------------------------------\n");
    printf("\n\n");
}

//Function to search for a room by room number and display its details
void searchForRoom(room* rooms, int* numRooms){
    int roomNumberToSearch, found = 0;
    printf("Enter room number to search for: ");
    scanf("%d", &roomNumberToSearch);
    
    //Find and display room details if it exists
    for(int i=0; i<*numRooms; i++){
        if(rooms[i].roomNumber == roomNumberToSearch){
            printf("\n\n");
            printf("--------------------------------------------------\n");
            printf("|  Room #  |  Capacity  |  Status  |  Guest Name  |\n");
            printf("--------------------------------------------------\n");
            printf("|   %3d    |    %3d     |     %c     |  %10s  |\n", rooms[i].roomNumber, rooms[i].numOccupants, rooms[i].status, rooms[i].guestName);
            printf("--------------------------------------------------\n");
            found = 1;
            break;
        }
    }
    
    if(!found){
        printf("Room not found!\n");
    }
}

//Function to allow a guest to check in to a vacant room
void checkInGuest(room* rooms, int* numRooms){
    int roomNumberToCheckIn, found = 0;
    printf("Enter room number to check in: ");
    scanf("%d", &roomNumberToCheckIn);
    
    //Find the vacant room and set its status to occupied
    for(int i=0; i<*numRooms; i++){
        if(rooms[i].roomNumber == roomNumberToCheckIn){
            if(rooms[i].status == 'V'){
                printf("Enter guest name: ");
                scanf("%s", rooms[i].guestName);
                printf("Enter number of occupants: ");
                scanf("%d", &rooms[i].numOccupants);
                
                rooms[i].status = 'O';
                
                printf("\nGuest checked in successfully!\n");
                found = 1;
                break;
            }else{
                printf("Room is already occupied!\n");
                found = 1;
                break;
            }
        }
    }
    
    if(!found){
        printf("Room not found!\n");
    }
}

//Function to allow a guest to check out of their room
void checkOutGuest(room* rooms, int* numRooms){
    int roomNumberToCheckOut, found = 0;
    printf("Enter room number to check out: ");
    scanf("%d", &roomNumberToCheckOut);
    
    //Find the occupied room and set its status to vacant
    for(int i=0; i<*numRooms; i++){
        if(rooms[i].roomNumber == roomNumberToCheckOut){
            if(rooms[i].status == 'O'){
                rooms[i].numOccupants = 0;
                rooms[i].status = 'V';
                rooms[i].guestName[0] = '\0';
                
                printf("\nGuest checked out successfully!\n");
                found = 1;
                break;
            }else{
                printf("Room is already vacant!\n");
                found = 1;
                break;
            }
        }
    }
    
    if(!found){
        printf("Room not found!\n");
    }
}

int main(){
    int selection, numRooms = 0;
    room rooms[50];
    
    while(1){
        displayMenu();
        printf("Enter selection (1-7): ");
        scanf("%d", &selection);
        
        switch(selection){
            case 1: addRoom(rooms, &numRooms);
                    break;
            case 2: removeRoom(rooms, &numRooms);
                    break;
            case 3: displayAllRooms(rooms, &numRooms);
                    break;
            case 4: searchForRoom(rooms, &numRooms);
                    break;
            case 5: checkInGuest(rooms, &numRooms);
                    break;
            case 6: checkOutGuest(rooms, &numRooms);
                    break;
            case 7: exit(0);
            default: printf("Invalid selection!\n");
        }
    }
    
    return 0;
}