//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

struct hotel {
    int room_no;
    char name[50];
    int capacity;
    float price;
    int status;
};

void print_room(struct hotel* room) {
    printf("Room Number: %d\n", room->room_no);
    printf("Name: %s\n", room->name);
    printf("Capacity: %d\n", room->capacity);
    printf("Price: $%.2f\n", room->price);
    printf("Status: %d\n", room->status);
}

void add_room(struct hotel* room) {
    printf("Enter room number: ");
    scanf("%d", &room->room_no);
    printf("Enter room name: ");
    scanf(" %s", room->name);
    printf("Enter room capacity: ");
    scanf("%d", &room->capacity);
    printf("Enter room price: ");
    scanf("%f", &room->price);
    printf("Enter room status (1 for available, 0 for booked): ");
    scanf("%d", &room->status);
}

void main() {
    struct hotel room[10];
    int choice, i;
    
    printf("1. Add Room\n2. Print Room\n3. Exit\n");
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                for(i=0; i<10; i++) {
                    add_room(&room[i]);
                }
                break;
            case 2:
                for(i=0; i<10; i++) {
                    print_room(&room[i]);
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while(choice!= 3);
}