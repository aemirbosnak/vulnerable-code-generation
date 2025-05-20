//FormAI DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROOMS 100

struct Room{
    int room_num;
    int price;
    char occupied_by[50];
};

int no_of_rooms = 0;//to hold number of rooms booked.

void reserve_room(struct Room *rooms){//function to reserve a room
    if(no_of_rooms == MAX_ROOMS){
        printf("All rooms are currently occupied!\n");
        return;
    }
    printf("Enter the room number:\n");
    scanf("%d",&rooms[no_of_rooms].room_num);
    printf("Enter the price:\n");
    scanf("%d",&rooms[no_of_rooms].price);
    printf("Enter the name of the occupant:\n");
    char str[50];
    scanf("%s",str);
    strcpy(rooms[no_of_rooms].occupied_by,str);
    no_of_rooms++;
}

int search_room(struct Room *rooms, int low, int high, int room_number){//binary search for the room number
    if(high<low){
        return -1;
    }
    int mid = (low+high)/2;
    if(rooms[mid].room_num == room_number){
        return mid;
    }else if(rooms[mid].room_num > room_number){
        return search_room(rooms,low,mid-1,room_number);
    }else{
        return search_room(rooms,mid+1,high,room_number);
    }
}

void cancel_reservation(struct Room *rooms){//function to cancel a reservation
    if(no_of_rooms == 0){
        printf("No rooms to cancel!\n");
        return;
    }
    printf("Enter the room number to cancel reservation:\n");
    int room_num;
    scanf("%d",&room_num);
    int index = search_room(rooms,0,no_of_rooms-1,room_num);
    if(index == -1){
        printf("Room number not found!\n");
        return;
    }
    for(int i=index;i<no_of_rooms-1;i++){
        rooms[i] = rooms[i+1];
    }
    no_of_rooms--;
    printf("Reservation cancelled!\n");
}

void display_rooms(struct Room *rooms){//function to display all rooms
    if(no_of_rooms == 0){
        printf("No rooms reserved!\n");
    }
    printf("Room Number\tPrice\tClient Name\n");
    for(int i=0;i<no_of_rooms;i++){
        printf("%d\t\t%d\t%s\n",rooms[i].room_num,rooms[i].price,rooms[i].occupied_by);
    }
}

int main(){
    struct Room rooms[MAX_ROOMS];
    int choice;
    printf("Hotel Management System\n");
    printf("-----------------------\n");
    while(1){
        printf("Choose an option:\n");
        printf("1. Reserve a room\n");
        printf("2. Cancel a reservation\n");
        printf("3. Display all rooms\n");
        printf("4. Quit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                reserve_room(rooms);
                break;
            case 2:
                cancel_reservation(rooms);
                break;
            case 3:
                display_rooms(rooms);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}