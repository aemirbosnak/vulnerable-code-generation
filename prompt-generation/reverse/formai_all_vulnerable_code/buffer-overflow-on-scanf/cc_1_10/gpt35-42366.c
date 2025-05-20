//FormAI DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Hotel {
    char name[50];
    int room_id;
    int price;
    int availability;
};

typedef struct Hotel hotel;

void addRoom(hotel *h, int i) {
    printf("\nEnter room details below: \n");
    printf("\nRoom Id: ");
    scanf("%d", &h[i].room_id);
    fflush(stdin);
    printf("\nName of the room: ");
    gets(h[i].name);
    printf("\nPrice per night: ");
    scanf("%d", &h[i].price);
    printf("\nAvailability (1 for available, 0 for not available): ");
    scanf("%d", &h[i].availability);
}

void displayAvailableRooms(hotel *h, int n) {
    int count = 0;
    printf("\nAvailable rooms are:\n");
    printf("\nRoom ID\t\tName\t\tPrice\t\tAvailability\n");
    for(int i = 0; i<n; i++) {
        if(h[i].availability == 1) {
            printf("%d\t\t%s\t\t%d\t\tAvailable\n", h[i].room_id, h[i].name, h[i].price);
            count++;
        }
    }
    if(count == 0) {
        printf("\nSorry, there are currently no available rooms.\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rooms: ");
    scanf("%d", &n);
    fflush(stdin);
    hotel *h = malloc(n * sizeof(hotel));
    memset(h, 0, n * sizeof(hotel));
    printf("\nEnter details of all the rooms below:\n");
    for(int i=0; i<n; i++) {
        addRoom(h, i);
    }
    displayAvailableRooms(h, n);
    free(h);
    return 0;
}