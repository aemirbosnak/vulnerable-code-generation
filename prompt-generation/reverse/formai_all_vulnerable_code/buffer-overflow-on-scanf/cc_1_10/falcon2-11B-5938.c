//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_no;
    int price;
} Room;

typedef struct {
    char name[50];
    int room_no;
    int price;
    int status;
} Booking;

int main() {
    int n, m;
    printf("Enter the number of rooms: ");
    scanf("%d", &n);
    Room* rooms = (Room*)malloc(n * sizeof(Room));
    for (int i = 0; i < n; i++) {
        printf("Enter room details for room %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", rooms[i].name);
        printf("Room number: ");
        scanf("%d", &rooms[i].room_no);
        printf("Price: ");
        scanf("%d", &rooms[i].price);
    }
    printf("Room details:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, rooms[i].name);
    }

    printf("Enter the number of bookings: ");
    scanf("%d", &m);
    Booking* bookings = (Booking*)malloc(m * sizeof(Booking));
    for (int i = 0; i < m; i++) {
        printf("Enter booking details for booking %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", bookings[i].name);
        printf("Room number: ");
        scanf("%d", &bookings[i].room_no);
        printf("Price: ");
        scanf("%d", &bookings[i].price);
        printf("Status: ");
        scanf("%d", &bookings[i].status);
    }
    printf("Booking details:\n");
    for (int i = 0; i < m; i++) {
        printf("%d. %s - Room %d - %d\n", i + 1, bookings[i].name, bookings[i].room_no, bookings[i].price);
    }

    free(rooms);
    free(bookings);
    return 0;
}