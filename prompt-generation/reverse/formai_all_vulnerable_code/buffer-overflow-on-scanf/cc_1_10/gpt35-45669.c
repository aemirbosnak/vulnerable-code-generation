//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROOMS 100

struct Room {
    int room_number;
    char guest_name[50];
    int is_occupied;
};

int num_rooms;
struct Room Rooms[MAX_ROOMS];

void initializeRooms(){
    for(int i=0; i<num_rooms; i++){
        Rooms[i].room_number = i+1;
        Rooms[i].is_occupied = 0;
        strcpy(Rooms[i].guest_name, "");
    }
    printf("Rooms initialized.\n");
}

void addGuest(int room_number, char name[]){
    if(room_number<=0 || room_number>num_rooms){
        printf("Invalid Room number!\n");
        return;
    }
    if(Rooms[room_number-1].is_occupied == 1){
        printf("Room is already occupied!\n");
        return;
    }
    Rooms[room_number-1].is_occupied = 1;
    strcpy(Rooms[room_number-1].guest_name, name);
    printf("Guest added to room %d.\n",room_number);
}

void removeGuest(int room_number){
    if(room_number<=0 || room_number>num_rooms){
        printf("Invalid Room number!\n");
        return;
    }
    if(Rooms[room_number-1].is_occupied == 0){
        printf("Room is already empty!\n");
        return;
    }
    Rooms[room_number-1].is_occupied = 0;
    strcpy(Rooms[room_number-1].guest_name, "");
    printf("Guest removed from room %d.\n",room_number);
}

void displayRooms(){
    printf("Room Number\tGuest Name\tIs Occupied\n");
    for(int i=0; i<num_rooms; i++){
        printf("%d\t\t%s\t\t",Rooms[i].room_number,Rooms[i].guest_name);
        if(Rooms[i].is_occupied==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main(){
    int choice,room_num;
    char name[50];
    printf("Enter the number of rooms: ");
    scanf("%d",&num_rooms);
    initializeRooms();
    while(1){
        printf("\n\nEnter your choice:\n");
        printf("1. Add a guest\n");
        printf("2. Remove a guest\n");
        printf("3. Display List of rooms and occupancy status\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the room number: ");
            scanf("%d",&room_num);
            printf("Enter the guest name: ");
            scanf("%s",name);
            addGuest(room_num,name);
        }
        else if(choice==2){
            printf("Enter the room number: ");
            scanf("%d",&room_num);
            removeGuest(room_num);
        }
        else if(choice==3){
            displayRooms();
        }
        else if(choice==4){
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}