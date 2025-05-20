//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest {
    char name[50];
    int room_no;
    int balance;
};

struct room {
    int room_no;
    int capacity;
    int rent;
    int available;
};

int main() {
    struct guest guests[100];
    int no_of_guests = 0;

    struct room rooms[50] = {
        {101, 2, 1500, 1},
        {102, 3, 2000, 1},
        {103, 4, 3000, 1},
        {104, 1, 1000, 1},
        {105, 2, 1500, 1},
        {106, 3, 2000, 1},
        {107, 4, 3000, 1},
        {108, 2, 1500, 1},
        {109, 3, 2000, 1},
        {110, 4, 3000, 1}
    };
    int no_of_rooms = 10;

    printf("Welcome to C Hotel Management System!\n");
    printf("------------------------------------\n");

    while(1) {
        int choice;
        printf("1. Check-In\n");
        printf("2. Check-Out\n");
        printf("3. List Guests\n");
        printf("4. List Available Rooms\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter guest name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter room number: ");
                int room_no;
                scanf("%d", &room_no);

                int index = -1;
                for(int i=0;i<no_of_rooms;i++) {
                    if(rooms[i].room_no == room_no) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("Invalid room number.\n");
                    break;
                }

                if(rooms[index].available == 0) {
                    printf("Room not available.\n");
                    break;
                }

                printf("Enter amount paid: ");
                int amount;
                scanf("%d", &amount);

                guests[no_of_guests].balance = rooms[index].rent - amount;
                strcpy(guests[no_of_guests].name, name);
                guests[no_of_guests].room_no = room_no;

                rooms[index].available = 0;

                printf("Guest checked in successfully! Remaining balance: %d\n", guests[no_of_guests].balance);

                no_of_guests++;
                break;
            }
            case 2: {
                printf("Enter guest name: ");
                char name[50];
                scanf("%s", name);

                int index = -1;
                for(int i=0;i<no_of_guests;i++) {
                    if(strcmp(guests[i].name, name) == 0) {
                        index = i;
                        break;
                    }
                }
                if(index == -1) {
                    printf("Guest not found.\n");
                    break;
                }

                for(int i=0;i<no_of_rooms;i++) {
                    if(rooms[i].room_no == guests[index].room_no) {
                        rooms[i].available = 1;
                        break;
                    }
                }

                printf("Guest checked out successfully!\n");
                break;
            }
            case 3: {
                printf("List of guests:\n");
                for(int i=0;i<no_of_guests;i++) {
                    printf("%s\t%d\t%d\n", guests[i].name, guests[i].room_no, guests[i].balance);
                }
                break;
            }
            case 4: {
                printf("List of available rooms:\n");
                for(int i=0;i<no_of_rooms;i++) {
                    if(rooms[i].available == 1) {
                        printf("%d\t%d\n", rooms[i].room_no, rooms[i].rent);
                    }
                }
                break;
            }
            case 5: {
                printf("Thank you for using C Hotel Management System.\n");
                exit(0);
            }
            default: {
                printf("Invalid Choice.\n");
            }
        }
    }

    return 0;
}