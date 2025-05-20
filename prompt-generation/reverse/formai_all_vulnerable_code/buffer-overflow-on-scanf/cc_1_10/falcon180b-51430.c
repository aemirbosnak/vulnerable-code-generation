//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200
#define MAX_BOOKINGS 1000
#define MAX_STAFF 50

typedef struct guest {
    char name[50];
    char id[10];
    int age;
    int bookings;
} Guest;

typedef struct booking {
    int guest_id;
    int room_id;
    int start_date;
    int end_date;
    int total_nights;
    int total_cost;
} Booking;

typedef struct room {
    int room_id;
    char type[20];
    int capacity;
    int price_per_night;
    int availability;
} Room;

typedef struct staff {
    char name[50];
    char id[10];
    int age;
    int salary;
    int department;
} Staff;

int main() {
    int choice;
    while(1) {
        printf("\nHotel Management System\n");
        printf("1. Guest Management\n");
        printf("2. Booking Management\n");
        printf("3. Room Management\n");
        printf("4. Staff Management\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nGuest Management\n");
                break;
            case 2:
                printf("\nBooking Management\n");
                break;
            case 3:
                printf("\nRoom Management\n");
                break;
            case 4:
                printf("\nStaff Management\n");
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}