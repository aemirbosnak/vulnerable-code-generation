//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
//C Hotel Management System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Hotel {
    char name[50];
    int capacity;
    float price;
};

struct Guest {
    char name[50];
    char room_type[10];
    int check_in;
    int check_out;
    int no_of_nights;
};

int main() {
    struct Hotel hotel;
    struct Guest guest;

    printf("Welcome to the C Hotel Management System!\n");
    printf("Please enter the name of the hotel: ");
    fgets(hotel.name, sizeof(hotel.name), stdin);
    printf("Please enter the capacity of the hotel: ");
    scanf("%d", &hotel.capacity);
    printf("Please enter the price of the hotel: ");
    scanf("%f", &hotel.price);

    printf("\nPlease enter the details of the guest: \n");
    printf("Please enter the name of the guest: ");
    fgets(guest.name, sizeof(guest.name), stdin);
    printf("Please enter the room type of the guest: ");
    fgets(guest.room_type, sizeof(guest.room_type), stdin);
    printf("Please enter the check-in date of the guest: ");
    scanf("%d", &guest.check_in);
    printf("Please enter the check-out date of the guest: ");
    scanf("%d", &guest.check_out);
    printf("Please enter the number of nights the guest will stay: ");
    scanf("%d", &guest.no_of_nights);

    printf("\nPlease wait while we check availability...\n");
    printf("Room type: %s\n", guest.room_type);
    printf("Check-in date: %d\n", guest.check_in);
    printf("Check-out date: %d\n", guest.check_out);
    printf("Number of nights: %d\n", guest.no_of_nights);
    printf("Total cost: %f\n", hotel.price * guest.no_of_nights);

    return 0;
}