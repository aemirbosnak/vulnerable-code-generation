//FormAI DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure definition for rooms
struct room{
    char room_no[10];
    char room_type[10];
    char room_status[10];
    char room_price[10];
};

//function to add a new room
void add_room(struct room *rooms, int size){
    printf("Enter details of room %d: \n", size+1);
    printf("Room Number: ");
    scanf("%s", rooms[size].room_no);
    printf("Room Type: ");
    scanf("%s", rooms[size].room_type);
    printf("Room Status: ");
    scanf("%s", rooms[size].room_status);
    printf("Room Price: ");
    scanf("%s", rooms[size].room_price);
    printf("Room Added Successfully!\n");
}

//function to display the rooms
void display_rooms(struct room *rooms, int size){
    printf("--------------------------------------------------\n");
    printf("| Room No. | Room Type | Room Status | Room Price |\n");
    printf("--------------------------------------------------\n");
    for(int i=0;i<size;i++){
        printf("|  %-7s|  %-8s|  %-10s|  %-9s|\n",
               rooms[i].room_no,
               rooms[i].room_type,
               rooms[i].room_status,
               rooms[i].room_price);
    }
    printf("--------------------------------------------------\n");
}

//function to search for a room based on room number
void search_room(struct room *rooms, int size){
    char search_room_no[10];
    printf("Enter Room Number to be searched: ");
    scanf("%s", search_room_no);
    for(int i=0;i<size;i++){
        if(strcmp(rooms[i].room_no, search_room_no) == 0){
            printf("--------------------------------------------------\n");
            printf("| Room No. | Room Type | Room Status | Room Price |\n");
            printf("--------------------------------------------------\n");
            printf("|  %-7s|  %-8s|  %-10s|  %-9s|\n",
                   rooms[i].room_no,
                   rooms[i].room_type,
                   rooms[i].room_status,
                   rooms[i].room_price);
            printf("--------------------------------------------------\n");
            return;
        }
    }
    printf("Room Not Found!\n");
}

//function to book a room
void book_room(struct room *rooms, int size){
    char book_room_no[10];
    printf("Enter Room Number to be booked: ");
    scanf("%s", book_room_no);
    for(int i=0;i<size;i++){
        if(strcmp(rooms[i].room_no, book_room_no) == 0){
            if(strcmp(rooms[i].room_status, "Booked") == 0){
                printf("Room is already booked!\n");
            }
            else{
                strcpy(rooms[i].room_status, "Booked");
                printf("Room Booked Successfully!\n");
            }
            return;
        }
    }
    printf("Room Not Found!\n");
}

int main(){
    struct room *rooms;
    int num_rooms, choice;
    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);
    rooms = (struct room *) malloc(num_rooms * sizeof(struct room));
    for(int i=0;i<num_rooms;i++){
        add_room(rooms, i);
    }
    while(1){
        printf("\n\n\n");
        printf("1. Display Available Rooms\n");
        printf("2. Search for a Room\n");
        printf("3. Book a Room\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("\n\n\n");
                display_rooms(rooms, num_rooms);
                break;
            case 2:
                printf("\n\n\n");
                search_room(rooms, num_rooms);
                break;
            case 3:
                printf("\n\n\n");
                book_room(rooms, num_rooms);
                break;
            case 4:
                printf("\n\n\n");
                printf("Thank You for Using our System!\n");
                exit(0);
            default:
                printf("\n\n\n");
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}