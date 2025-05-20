//FormAI DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int room_no;
    char guest_name[20];
    int no_of_days;
    int charges;
} Room;

Room rooms[10];
int total_rooms = 10;
int count = 0;

void reserve_room(int room_no) {
    if(room_no > total_rooms || room_no <=0) {
        printf("Invalid Room Number\n");
        return;
    }
    if(rooms[room_no-1].room_no != 0) {
        printf("Room Already Reserved.\n");
        return;
    }
    Room new_room;
    new_room.room_no = room_no;
    printf("Enter Guest Name: ");
    scanf("%s", new_room.guest_name);
    printf("Enter Number of Days: ");
    scanf("%d", &new_room.no_of_days);
    new_room.charges = new_room.no_of_days * 1000;
    rooms[room_no-1] = new_room;
    printf("\nRoom Reserved Successfully!\n");
    count++;
}

void print_room_status(int room_no) {
    if(room_no > total_rooms || room_no <=0) {
        printf("Invalid Room Number\n");
        return;
    }
    if(rooms[room_no-1].room_no == 0) {
        printf("Room is Empty\n");
        return;
    }
    printf("Room Details:\n");
    printf("Room Number: %d\n", rooms[room_no-1].room_no);
    printf("Guest Name: %s\n", rooms[room_no-1].guest_name);
    printf("Number of Days: %d\n", rooms[room_no-1].no_of_days);
    printf("Total Charges: %d\n", rooms[room_no-1].charges);
}

void checkout_room(int room_no) {
    if(room_no > total_rooms || room_no <=0) {
        printf("Invalid Room Number\n");
        return;
    }
    if(rooms[room_no-1].room_no == 0) {
        printf("Room is Already Empty\n");
        return;
    }

    printf("Room Charges: %d\n", rooms[room_no-1].charges);
    rooms[room_no-1] = (Room){0, "", 0, 0};
    printf("Guest Checked out Successfully\n");
    count--;
}

void list_all() {
    printf("\tRoom No\tGuest Name\tNo of Days\tCharges\n");
    for(int i=0; i<total_rooms; i++) {
        Room r = rooms[i];
        printf("\t%d\t%s\t%d\t\t%d\n", r.room_no, r.guest_name, r.no_of_days, r.charges);
    }
    printf("\n");
}

int main() {
    int choice, room_no;
    while(1) {
        printf("Welcome to C Hotel Management System\n");
        printf("1. Reserve Room\n");
        printf("2. Print Room Status\n");
        printf("3. Check out Room\n");
        printf("4. List All Rooms\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter Room Number: ");
                scanf("%d", &room_no);
                reserve_room(room_no);
                break;
            case 2: 
                printf("Enter Room Number: ");
                scanf("%d", &room_no);
                print_room_status(room_no);
                break;
            case 3: 
                printf("Enter Room Number: ");
                scanf("%d", &room_no);
                checkout_room(room_no);
                break;
            case 4: 
                list_all();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    
    return 0;
}