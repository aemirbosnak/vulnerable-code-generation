//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define maximum number of rooms available
#define MAX_ROOMS 50

// define structure to store room information
struct room{
    int room_no;
    char type[10];
    int occupancy;
    int price;
};

// function to display current status of rooms
void display_rooms(struct room* rooms, int num_rooms){
    printf("\n-------------------------------------------------\n");
    printf("Current Room Status");
    printf("\n-------------------------------------------------\n");
    printf("%-10s %-10s %-10s %-10s\n", "Room No", "Type", "Occupancy", "Price");

    for(int i=0; i<num_rooms; i++){
        printf("%-10d %-10s %-10d %-10d\n", rooms[i].room_no, rooms[i].type, rooms[i].occupancy, rooms[i].price);
    }
}

// function to add a new room
int add_room(struct room* rooms, int num_rooms){
    if(num_rooms < MAX_ROOMS){
        printf("\nEnter Room Number: ");
        scanf("%d", &rooms[num_rooms].room_no);
        printf("Enter Room Type (Single/Double): ");
        scanf("%s", rooms[num_rooms].type);
        printf("Enter Room Occupancy (1/2): ");
        scanf("%d", &rooms[num_rooms].occupancy);
        printf("Enter Room Price: ");
        scanf("%d", &rooms[num_rooms].price);

        num_rooms++;
        printf("\nRoom added successfully!");
        return num_rooms;
    }else{
        printf("\nMaximum number of rooms exceeded!");
        return num_rooms;
    }
}

// function to remove an existing room
int remove_room(struct room* rooms, int num_rooms){
    int room_no, found=0;

    printf("\nEnter Room Number to delete: ");
    scanf("%d", &room_no);

    for(int i=0; i<num_rooms; i++){
        if(rooms[i].room_no == room_no){
            found = 1;
            for(int j=i; j<num_rooms-1; j++){
                rooms[j].room_no = rooms[j+1].room_no;
                strcpy(rooms[j].type, rooms[j+1].type);
                rooms[j].occupancy = rooms[j+1].occupancy;
                rooms[j].price = rooms[j+1].price;
            }
            num_rooms--;
            break;
        }
    }

    if(found){
        printf("\nRoom deleted successfully!");
        return num_rooms;
    }else{
        printf("\nRoom not found!");
        return num_rooms;
    }
}

// function to update an existing room
void update_room(struct room* rooms, int num_rooms){
    int room_no, found=0;

    printf("\nEnter Room Number to update: ");
    scanf("%d", &room_no);

    for(int i=0; i<num_rooms; i++){
        if(rooms[i].room_no == room_no){
            found = 1;
            printf("\nEnter New Room Type (Single/Double): ");
            scanf("%s", rooms[i].type);
            printf("Enter New Room Occupancy (1/2): ");
            scanf("%d", &rooms[i].occupancy);
            printf("Enter New Room Price: ");
            scanf("%d", &rooms[i].price);
            break;
        }
    }

    if(found){
        printf("\nRoom updated successfully!");
    }else{
        printf("\nRoom not found!");
    }
}

int main(){
    struct room rooms[MAX_ROOMS];
    int num_rooms=0, choice;

    while(1){
        printf("\n-------------------------------------------------\n");
        printf("           C HOTEL MANAGEMENT SYSTEM              ");
        printf("\n-------------------------------------------------\n");
        printf("1. Display Rooms\n");
        printf("2. Add Room\n");
        printf("3. Remove Room\n");
        printf("4. Update Room\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: display_rooms(rooms, num_rooms);
                    break;
            
            case 2: num_rooms = add_room(rooms, num_rooms);
                    break;

            case 3: num_rooms = remove_room(rooms, num_rooms);
                    break;

            case 4: update_room(rooms, num_rooms);
                    break;

            case 5: printf("\nExiting Program...");
                    exit(0);

            default: printf("\nInvalid Choice!");
        }
    }

    return 0;
}