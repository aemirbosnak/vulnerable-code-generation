//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

struct hotel {
    int room_no, floor; 
    char name[SIZE], address[SIZE], phone[SIZE];
};

struct hotel room_list[SIZE];

int main() {
    int num_of_rooms, option;
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &num_of_rooms);

    for(int i=0; i<num_of_rooms; i++) {
        printf("\n\nEnter the details of Room %d:\n", i+1);
        printf("------------------------------\n");
        printf("Room No: ");
        scanf("%d", &room_list[i].room_no);

        printf("Floor: ");
        scanf("%d", &room_list[i].floor);

        printf("Name: ");
        scanf("%s", room_list[i].name);

        printf("Address: ");
        scanf("%s", room_list[i].address);

        printf("Phone Number: ");
        scanf("%s", room_list[i].phone);
    }

    while(1) {
        printf("\n\nHotel Management System\n");
        printf("------------------------\n");
        printf("1. View all rooms\n");
        printf("2. Search for a room\n");
        printf("3. Check-in\n");
        printf("4. Check-out\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n\nRoom List\n");
                printf("---------\n");
                printf("Room No. | Floor | Name | Address | Phone No.\n");

                for(int i=0; i<num_of_rooms; i++) {
                    printf("    %d      %d     %s     %s        %s\n",
                     room_list[i].room_no, room_list[i].floor, room_list[i].name,
                     room_list[i].address, room_list[i].phone);
                }
                break;

            case 2:
                printf("\n\nEnter the room number to search: ");
                int search_room_no;
                scanf("%d", &search_room_no);
                int found = 0;

                for(int i=0; i<num_of_rooms; i++) {
                    if(room_list[i].room_no == search_room_no) {
                        printf("\nRoom details:\n");
                        printf("Room No: %d\n", room_list[i].room_no);
                        printf("Floor: %d\n", room_list[i].floor);
                        printf("Name: %s\n", room_list[i].name);
                        printf("Address: %s\n", room_list[i].address);
                        printf("Phone: %s\n", room_list[i].phone);
                        found = 1;
                        break;
                    }
                }

                if(found == 0) {
                    printf("\nNo matching room found!\n");
                }
                break;

            case 3:
                printf("\n\nEnter the room number to check-in: ");
                int checkin_room_no;
                scanf("%d", &checkin_room_no);
                int checkin_found = 0;

                for(int i=0; i<num_of_rooms; i++) {
                    if(room_list[i].room_no == checkin_room_no) {
                        printf("\nEnter guest details:\n");
                        printf("---------------------\n");
                        printf("Name: ");
                        scanf("%s", room_list[i].name);
                        printf("Address: ");
                        scanf("%s", room_list[i].address);
                        printf("Phone Number: ");
                        scanf("%s", room_list[i].phone);
                        checkin_found = 1;
                        break;
                    }
                }

                if(checkin_found == 0) {
                    printf("\nNo matching room found!\n");
                } else {
                    printf("\nGuest successfully checked-in!\n");
                }
                break;

            case 4:
                printf("\n\nEnter the room number to check-out: ");
                int checkout_room_no;
                scanf("%d", &checkout_room_no);
                int checkout_found = 0;

                for(int i=0; i<num_of_rooms; i++) {
                    if(room_list[i].room_no == checkout_room_no) {
                        strcpy(room_list[i].name, "Available");
                        strcpy(room_list[i].address, "-");
                        strcpy(room_list[i].phone, "-");
                        checkout_found = 1;
                        break;
                    }
                }

                if(checkout_found == 0) {
                    printf("\nNo matching room found!\n");
                } else {
                    printf("\nGuest successfully checked-out!\n");
                }
                break;

            case 5:
                printf("\n\nGoodbye!\n");
                exit(0);

            default:
                printf("\n\nInvalid option!\n");
        }
    }
    return 0;
}