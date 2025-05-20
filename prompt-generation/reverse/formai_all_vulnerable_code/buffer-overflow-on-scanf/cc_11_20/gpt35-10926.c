//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include<stdio.h>

struct room {
    int room_no;
    char room_type[10];
    int availability;
    float cost;
};

int main() {
    int n, i, room_no, option;
    float total_cost = 0.0;
    char room_type[10];

    printf("Enter the number of rooms: ");
    scanf("%d", &n);

    struct room hotel[n];

    //Initialize the hotel rooms
    for(i = 0; i < n; i++) {
        printf("\nRoom number: ");
        scanf("%d", &hotel[i].room_no);
        printf("Room type: ");
        scanf("%s", &hotel[i].room_type);
        printf("Availability (1 for available and 0 for not available): ");
        scanf("%d", &hotel[i].availability);
        printf("Cost per night: ");
        scanf("%f", &hotel[i].cost);
    }

    //Display available rooms
    printf("\n\n------------------------------------");
    printf("\nAVAILABLE ROOMS IN THE HOTEL\n");
    printf("------------------------------------\n");
    printf("ROOM NO.   ROOM TYPE   COST PER NIGHT\n");
    for(i = 0; i < n; i++) {
        if(hotel[i].availability == 1) {
            printf("%-10d %-10s %-10.2f\n", hotel[i].room_no, hotel[i].room_type, hotel[i].cost);
        }
    }

    //Book a room
    printf("\n\nEnter the room number to book: ");
    scanf("%d", &room_no);
    for(i = 0; i < n; i++) {
        if(hotel[i].room_no == room_no && hotel[i].availability == 1) {
            hotel[i].availability = 0;
            printf("Room booked successfully!\n");
            total_cost += hotel[i].cost;
        }
        else if(hotel[i].room_no == room_no && hotel[i].availability == 0) {
            printf("Sorry! Room not available\n");
        }
    }

    //Display booked rooms and total cost
    printf("\n\n------------------------------------");
    printf("\nBOOKED ROOMS IN THE HOTEL\n");
    printf("------------------------------------\n");
    printf("ROOM NO.   ROOM TYPE   COST PER NIGHT\n");
    for(i = 0; i < n; i++) {
        if(hotel[i].availability == 0) {
            printf("%-10d %-10s %-10.2f\n", hotel[i].room_no, hotel[i].room_type, hotel[i].cost);
        }
    }
    printf("\nTotal cost: %.2f", total_cost);

    //Check out and free a room
    printf("\n\nEnter 1 to check out and free a room: ");
    scanf("%d", &option);
    if(option == 1) {
        printf("Enter the room number for check out: ");
        scanf("%d", &room_no);
        for(i = 0; i < n; i++) {
            if(hotel[i].room_no == room_no && hotel[i].availability == 0) {
                hotel[i].availability = 1;
                printf("Room number %d checked out successfully!\n", room_no);
            }
            else if(hotel[i].room_no == room_no && hotel[i].availability == 1) {
                printf("Room number %d is not occupied!\n", room_no);
            }
        }
    }

    return 0;
}