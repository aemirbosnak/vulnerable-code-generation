//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct {
    char name[50];
    char room_no[10];
    int check_in_time;
    int check_out_time;
    int bill_amount;
} guest_info_t;

typedef struct {
    char room_no[10];
    char name[50];
} room_info_t;

int main() {
    // Hotel Management System
    printf("Welcome to the C Hotel Management System\n");

    // Initialize guest list and room list
    guest_info_t *guests = (guest_info_t *)malloc(MAX_GUESTS * sizeof(guest_info_t));
    room_info_t *rooms = (room_info_t *)malloc(MAX_ROOMS * sizeof(room_info_t));

    // Initialize guest and room lists
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_no[0] = '\0';
        guests[i].check_in_time = 0;
        guests[i].check_out_time = 0;
        guests[i].bill_amount = 0;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_no[0] = '\0';
        rooms[i].name[0] = '\0';
    }

    // Main loop
    while (1) {
        // Check for new reservations
        printf("Check for new reservations: ");
        scanf("%s%s%d%d", guests[0].name, guests[0].room_no, &guests[0].check_in_time, &guests[0].check_out_time);

        // Add new reservation to guest list
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (strcmp(guests[i].name, guests[0].name) == 0) {
                strcpy(guests[i].room_no, guests[0].room_no);
                guests[i].check_in_time = guests[0].check_in_time;
                guests[i].check_out_time = guests[0].check_out_time;
                break;
            }
        }

        // Check for check-ins
        printf("Check for check-ins: ");
        scanf("%s%s%d", guests[0].name, guests[0].room_no, &guests[0].check_in_time);

        // Add check-in to guest list
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (strcmp(guests[i].name, guests[0].name) == 0) {
                guests[i].check_in_time = guests[0].check_in_time;
                break;
            }
        }

        // Check for check-outs
        printf("Check for check-outs: ");
        scanf("%s%s%d", guests[0].name, guests[0].room_no, &guests[0].check_out_time);

        // Add check-out to guest list
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (strcmp(guests[i].name, guests[0].name) == 0) {
                guests[i].check_out_time = guests[0].check_out_time;
                break;
            }
        }

        // Calculate and print bills
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guests[i].check_out_time > 0) {
                guests[i].bill_amount = (guests[i].check_out_time - guests[i].check_in_time) * 100;
                printf("Bill for %s: %d\n", guests[i].name, guests[i].bill_amount);
            }
        }

        // Clean up
        for (int i = 0; i < MAX_GUESTS; i++) {
            guests[i].name[0] = '\0';
            guests[i].room_no[0] = '\0';
            guests[i].check_in_time = 0;
            guests[i].check_out_time = 0;
            guests[i].bill_amount = 0;
        }

        // Check for new reservations again
        printf("Check for new reservations: ");
        scanf("%s%s%d%d", guests[0].name, guests[0].room_no, &guests[0].check_in_time, &guests[0].check_out_time);
    }

    // Free memory
    free(guests);
    free(rooms);

    return 0;
}