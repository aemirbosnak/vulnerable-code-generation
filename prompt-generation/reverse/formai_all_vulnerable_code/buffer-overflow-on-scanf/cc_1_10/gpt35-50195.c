//FormAI DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct hotel {
    char name[50];
    int room_no;
    char type[20];
    float price;
    char status[10];
}h[100];

// function to display menu
void display_menu() {
    printf("\n MENU");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n1. Add a room");
    printf("\n2. Remove a room");
    printf("\n3. Display all rooms");
    printf("\n4. Check status of room");
    printf("\n5. Exit");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
}

// function to add a room
int add_room(int count) {
    printf("\n Enter the details of the room");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n Room number: ");
    scanf("%d",&h[count].room_no);
    printf(" Room type: ");
    scanf("%s",h[count].type);
    printf(" Price per night: ");
    scanf("%f",&h[count].price);
    strcpy(h[count].status,"Available");
    count++;
    printf("\n Room added successfully!");
    return count;
}

// function to remove a room
int remove_room(int count) {
    int i,room;
    printf("\n Enter the room number to remove: ");
    scanf("%d",&room);
    for(i=0;i<count;i++) {
        if(h[i].room_no==room) {
            strcpy(h[i].name,"");
            strcpy(h[i].type,"");
            h[i].price=0.0;
            strcpy(h[i].status,"Removed");
            printf("\n Room removed successfully!");
            break;
        }
    }
    if(i==count) {
        printf("\n Room not found!");
    }
    return count;
}

// function to display all rooms
void display_all_rooms(int count) {
    int i;
    printf("\n%-10s %-15s %-10s %-10s","Room No","Room Type","Price","Status");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    for(i=0;i<count;i++) {
        printf("\n%-10d %-15s %-10.2f %-10s",h[i].room_no,h[i].type,h[i].price,h[i].status);
    }
}

// function to check status of a room
void check_status(int count) {
    int i,room;
    printf("\n Enter the room number to check status: ");
    scanf("%d",&room);
    for(i=0;i<count;i++) {
        if(h[i].room_no==room) {
            printf("\n Status of room %d is %s",room,h[i].status);
            break;
        }
    }
    if(i==count) {
        printf("\n Room not found!");
    }
}

int main() {
    int choice,i,count=0;
    while(1) {
        display_menu();
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: count=add_room(count);
                    break;
            case 2: count=remove_room(count);
                    break;
            case 3: display_all_rooms(count);
                    break;
            case 4: check_status(count);
                    break;
            case 5: exit(0);
            default: printf("\n Invalid choice!");
        }
    }
    return 0;
}