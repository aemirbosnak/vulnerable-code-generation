//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hotel {
    char name[50];
    char address[100];
    int num_rooms;
    float price;
} hotel_t;

typedef struct booking {
    char name[50];
    char address[100];
    int num_nights;
    float price;
} booking_t;

hotel_t hotels[] = {
    {"The Ritz-Carlton", "112 Central Park South", 245, 1000.0},
    {"The Waldorf Astoria", "301 Park Avenue", 141, 800.0},
    {"The Plaza Hotel", "768 5th Avenue", 282, 1200.0},
    {NULL, NULL, 0, 0.0}
};

booking_t bookings[] = {
    {"John Doe", "123 Main Street", 3, 300.0},
    {"Jane Doe", "456 Elm Street", 5, 500.0},
    {NULL, NULL, 0, 0.0}
};

void print_hotels() {
    int i = 0;
    while (hotels[i].name != NULL) {
        printf("%s\n", hotels[i].name);
        printf("%s\n", hotels[i].address);
        printf("%d\n", hotels[i].num_rooms);
        printf("%.2f\n", hotels[i].price);
        printf("\n");
        i++;
    }
}

void print_bookings() {
    int i = 0;
    while (bookings[i].name != NULL) {
        printf("%s\n", bookings[i].name);
        printf("%s\n", bookings[i].address);
        printf("%d\n", bookings[i].num_nights);
        printf("%.2f\n", bookings[i].price);
        printf("\n");
        i++;
    }
}

int main() {
    print_hotels();
    print_bookings();

    return 0;
}