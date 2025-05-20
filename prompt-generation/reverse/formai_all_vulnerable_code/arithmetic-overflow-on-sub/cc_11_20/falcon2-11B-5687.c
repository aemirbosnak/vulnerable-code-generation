//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_ROOMS 10
#define NUM_GUESTS 50
#define MAX_LENGTH 50

int main() {
    int room[NUM_ROOMS];
    int guests[NUM_GUESTS][MAX_LENGTH];
    int current_guest;
    int current_room;
    int i, j;
    char name[MAX_LENGTH];
    char city[MAX_LENGTH];
    char country[MAX_LENGTH];
    char room_number[MAX_LENGTH];
    int check_in_time;
    int check_out_time;
    int stay_days;
    int total_cost;
    int max_stay_days;
    int max_cost;
    int guests_left = NUM_GUESTS;
    int rooms_left = NUM_ROOMS;
    int guest_waiting_time = 0;
    int room_waiting_time = 0;
    clock_t start_time, end_time;

    // Initialize room numbers
    for (i = 0; i < NUM_ROOMS; i++) {
        room[i] = i;
    }

    // Start guests checking in
    while (guests_left > 0) {
        start_time = clock();

        // Read guest information
        printf("Enter guest information: ");
        fflush(stdin);
        scanf("%s %s %s %d %d", name, city, country, &check_in_time, &stay_days);
        fflush(stdin);

        // Check if there is a room available
        if (guests_left > 0 && rooms_left > 0) {
            // Assign room number
            current_room = room[rand() % rooms_left];

            // Check-in guest
            printf("Check-in complete. Room number: %d\n", current_room);
            fflush(stdout);
            rooms_left--;

            // Record check-in time
            guests[current_guest][0] = check_in_time;
            guests[current_guest][1] = current_room;

            // Add guest to waiting list
            printf("Guest added to waiting list.\n");
            fflush(stdout);
            guest_waiting_time++;
        } else {
            printf("No rooms available.\n");
            fflush(stdout);
            guest_waiting_time++;
        }

        end_time = clock();
        guest_waiting_time += (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Waiting time: %d seconds\n", guest_waiting_time);
        fflush(stdout);
    }

    // Start rooms checking out
    while (rooms_left > 0) {
        start_time = clock();

        // Read room information
        printf("Enter room information: ");
        fflush(stdin);
        scanf("%s %s %s %d %d", room_number, city, country, &check_out_time, &stay_days);
        fflush(stdin);

        // Check if there is a guest available
        if (guests_left > 0 && rooms_left > 0) {
            // Assign guest number
            current_guest = rand() % guests_left;

            // Check-out guest
            printf("Check-out complete. Room number: %d\n", guests[current_guest][1]);
            fflush(stdout);
            rooms_left--;

            // Record check-out time
            guests[current_guest][2] = check_out_time;

            // Remove guest from waiting list
            printf("Guest removed from waiting list.\n");
            fflush(stdout);
            guests_left--;
        } else {
            printf("No guests available.\n");
            fflush(stdout);
            room_waiting_time++;
        }

        end_time = clock();
        room_waiting_time += (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Waiting time: %d seconds\n", room_waiting_time);
        fflush(stdout);
    }

    // Calculate total cost and maximum stay days
    for (i = 0; i < guests_left; i++) {
        stay_days = guests[i][2] - guests[i][0];
        total_cost = stay_days * 100;
        printf("Guest %d stayed for %d days with a total cost of $%d\n", i + 1, stay_days, total_cost);
        fflush(stdout);
        if (max_stay_days < stay_days) {
            max_stay_days = stay_days;
        }
        if (max_cost < total_cost) {
            max_cost = total_cost;
        }
    }

    // Display results
    printf("Total guests: %d\n", guests_left);
    printf("Total rooms: %d\n", rooms_left);
    printf("Maximum stay days: %d\n", max_stay_days);
    printf("Maximum cost: $%d\n", max_cost);
    fflush(stdout);

    return 0;
}