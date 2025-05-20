//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[32];
    char address[64];
    char phone[16];
    int  room;
    int  nights;
    float rate;
    float total;
};

struct hotel {
    char name[32];
    int  num_rooms;
    struct guest guests[100];
};

int main(void) {
    struct hotel the_plaza = {
        .name = "The Plaza",
        .num_rooms = 100,
    };

    // Check in a guest
    printf("Enter guest name: ");
    scanf("%s", the_plaza.guests[0].name);

    printf("Enter guest address: ");
    scanf("%s", the_plaza.guests[0].address);

    printf("Enter guest phone: ");
    scanf("%s", the_plaza.guests[0].phone);

    printf("Enter guest room: ");
    scanf("%d", &the_plaza.guests[0].room);

    printf("Enter guest nights: ");
    scanf("%d", &the_plaza.guests[0].nights);

    printf("Enter guest rate: ");
    scanf("%f", &the_plaza.guests[0].rate);

    // Calculate guest total
    the_plaza.guests[0].total = the_plaza.guests[0].nights * the_plaza.guests[0].rate;

    // Print guest details
    printf("\nGuest name: %s\n", the_plaza.guests[0].name);
    printf("Guest address: %s\n", the_plaza.guests[0].address);
    printf("Guest phone: %s\n", the_plaza.guests[0].phone);
    printf("Guest room: %d\n", the_plaza.guests[0].room);
    printf("Guest nights: %d\n", the_plaza.guests[0].nights);
    printf("Guest rate: %f\n", the_plaza.guests[0].rate);
    printf("Guest total: %f\n", the_plaza.guests[0].total);

    return 0;
}