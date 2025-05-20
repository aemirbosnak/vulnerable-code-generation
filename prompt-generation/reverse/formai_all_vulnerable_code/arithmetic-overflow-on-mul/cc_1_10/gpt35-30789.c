//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>

//Defining the structure for hotel rooms to store data
struct RoomData{
    int roomNo;
    char guestName[50];
    int daysStaying;
    int roomType;
    float roomCharge;
} room[50];

//Function to display the menu options
void displayMenu(){
    printf("\n\n\t\tMenu\n");
    printf("\t1. Add new guest\n");
    printf("\t2. Display guest information\n");
    printf("\t3. Update guest information\n");
    printf("\t4. Delete guest information\n");
    printf("\t5. Display total earnings\n");
    printf("\t6. Exit\n");
    printf("\tEnter your choice: ");
}

//Function to add new guest information
void addGuest(){
    int roomNo, daysStaying, roomType;
    char guestName[50];
    float roomCharge;
    printf("\nEnter guest name: ");
    scanf(" %[^\n]s", guestName);
    printf("Enter room no: ");
    scanf("%d", &roomNo);
    printf("Enter days staying: ");
    scanf("%d", &daysStaying);
    printf("Room type\n1. Single Bed\n2. Double Bed\n3. Suite\nEnter room type: ");
    scanf("%d", &roomType);
    switch(roomType){
        case 1: roomCharge = daysStaying * 1000;
                break;
        case 2: roomCharge = daysStaying * 1800;
                break;
        case 3: roomCharge = daysStaying * 3000;
                break;
        default: printf("\nInvalid choice! Enter correct option.\n");
                 return;
    }
    room[roomNo].roomNo = roomNo;
    strcpy(room[roomNo].guestName, guestName);
    room[roomNo].daysStaying = daysStaying;
    room[roomNo].roomType = roomType;
    room[roomNo].roomCharge = roomCharge;
    printf("\nGuest added successfully!\n");
}

//Function to display guest information
void displayGuest(){
    int roomNo;
    printf("\nEnter room no: ");
    scanf("%d", &roomNo);
    if(room[roomNo].roomNo == 0){
        printf("\nNo guest found with given room number!\n");
        return;
    }
    printf("\n---------------------------\n");
    printf("Guest Name: %s\n", room[roomNo].guestName);
    printf("Room No: %d\n", room[roomNo].roomNo);
    printf("Days Staying: %d\n", room[roomNo].daysStaying);
    printf("Room Type: ");
    switch(room[roomNo].roomType){
        case 1: printf("Single Bed\n");
                break;
        case 2: printf("Double Bed\n");
                break;
        case 3: printf("Suite\n");
                break;
    }
    printf("Room Charge: %.2f\n", room[roomNo].roomCharge);
    printf("---------------------------\n");
}

//Function to update guest information
void updateGuest(){
    int roomNo, daysStaying, roomType;
    char guestName[50];
    float roomCharge;
    printf("\nEnter room no of the guest to update: ");
    scanf("%d", &roomNo);
    if(room[roomNo].roomNo == 0){
        printf("\nNo guest found with given room number!\n");
        return;
    }
    printf("\nEnter new guest name: ");
    scanf(" %[^\n]s", guestName);
    printf("Enter new days staying: ");
    scanf("%d", &daysStaying);
    printf("Room type\n1. Single Bed\n2. Double Bed\n3. Suite\nEnter new room type: ");
    scanf("%d", &roomType);
    switch(roomType){
        case 1: roomCharge = daysStaying * 1000;
                break;
        case 2: roomCharge = daysStaying * 1800;
                break;
        case 3: roomCharge = daysStaying * 3000;
                break;
        default: printf("\nInvalid choice! Enter correct option.\n");
                 return;
    }
    strcpy(room[roomNo].guestName, guestName);
    room[roomNo].daysStaying = daysStaying;
    room[roomNo].roomType = roomType;
    room[roomNo].roomCharge = roomCharge;
    printf("\nGuest information updated successfully!\n");
}

//Function to delete guest information
void deleteGuest(){
    int roomNo;
    printf("\nEnter room no of the guest to delete: ");
    scanf("%d", &roomNo);
    if(room[roomNo].roomNo == 0){
        printf("\nNo guest found with given room number!\n");
        return;
    }
    room[roomNo].roomNo = 0;
    strcpy(room[roomNo].guestName, "");
    room[roomNo].daysStaying = 0;
    room[roomNo].roomType = 0;
    room[roomNo].roomCharge = 0.00;
    printf("\nGuest information deleted successfully!\n");
}

//Function to display total earnings
void displayEarnings(){
    float totalEarnings = 0.00;
    for(int i=0; i<50; i++){
        totalEarnings += room[i].roomCharge;
    }
    printf("\nTotal earnings: %.2f\n", totalEarnings);
}

int main(){
    int choice;
    while(1){
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1: addGuest();
                    break;
            case 2: displayGuest();
                    break;
            case 3: updateGuest();
                    break;
            case 4: deleteGuest();
                    break;
            case 5: displayEarnings();
                    break;
            case 6: printf("\nExiting program... Goodbye!\n");
                    exit(0);
                    break;
            default: printf("\nInvalid choice! Enter correct option.\n");
                     break;
        }
    }
    return 0;
}