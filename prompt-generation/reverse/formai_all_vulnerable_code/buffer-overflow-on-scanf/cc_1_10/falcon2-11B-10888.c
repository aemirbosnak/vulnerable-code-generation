//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char room_type[50];
    int price;
} Room;

typedef struct {
    char name[50];
    int check_in;
    int check_out;
} Reservation;

int main() {
    Room rooms[5];
    Reservation reservations[5];
    int i;
    
    for (i = 0; i < 5; i++) {
        printf("Enter the name of the room: ");
        fgets(rooms[i].name, sizeof(rooms[i].name), stdin);
        
        printf("Enter the room type: ");
        fgets(rooms[i].room_type, sizeof(rooms[i].room_type), stdin);
        
        printf("Enter the price: ");
        scanf("%d", &rooms[i].price);
    }
    
    for (i = 0; i < 5; i++) {
        printf("Enter the name of the customer: ");
        fgets(reservations[i].name, sizeof(reservations[i].name), stdin);
        
        printf("Enter the check-in date: ");
        scanf("%d", &reservations[i].check_in);
        
        printf("Enter the check-out date: ");
        scanf("%d", &reservations[i].check_out);
    }
    
    printf("Here are the rooms available:\n");
    for (i = 0; i < 5; i++) {
        printf("Room %d: %s, %s, %d\n", i + 1, rooms[i].name, rooms[i].room_type, rooms[i].price);
    }
    
    printf("Here are the reservations made:\n");
    for (i = 0; i < 5; i++) {
        printf("Customer %d: %s, check-in: %d, check-out: %d\n", i + 1, reservations[i].name, reservations[i].check_in, reservations[i].check_out);
    }
    
    return 0;
}