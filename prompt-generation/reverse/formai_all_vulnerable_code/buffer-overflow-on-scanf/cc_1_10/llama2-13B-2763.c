//LLAMA2-13B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_GUESTS 10

typedef struct guest {
    char name[MAX_NAME_LENGTH];
    int arrival_time;
    int departure_time;
} guest_t;

typedef struct reservation {
    char name[MAX_NAME_LENGTH];
    int arrival_time;
    int departure_time;
    int status; // 0: pending, 1: confirmed, 2: cancelled
} reservation_t;

// Global variables
guest_t guests[MAX_GUESTS];
reservation_t reservations[MAX_GUESTS];
int num_guests = 0;

// Function to read names and arrival times from the user
void read_names_arrival_times() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("Enter name and arrival time for guest %d: ", i + 1);
        scanf("%255s %d", guests[i].name, &guests[i].arrival_time);
    }
}

// Function to print the list of guests and their reservations
void print_guests_reservations() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("%d. %s (arrival time: %d)\n", i + 1, guests[i].name, guests[i].arrival_time);
        if (reservations[i].status == 1) {
            printf("  - Confirmed reservation\n");
        } else if (reservations[i].status == 2) {
            printf("  - Cancelled reservation\n");
        }
    }
}

// Function to make a reservation
void make_reservation(int guest_index) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (reservations[i].status == 0) {
            break;
        }
    }
    if (i == MAX_GUESTS) {
        printf("No more reservations available\n");
        return;
    }
    strcpy(reservations[guest_index].name, guests[guest_index].name);
    reservations[guest_index].arrival_time = guests[guest_index].arrival_time;
    reservations[guest_index].status = 1; // 1: confirmed, 2: cancelled
    num_guests++;
}

// Function to cancel a reservation
void cancel_reservation(int guest_index) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (reservations[i].status == 1 && reservations[i].name == guests[guest_index].name) {
            break;
        }
    }
    if (i == MAX_GUESTS) {
        printf("No such reservation\n");
        return;
    }
    reservations[guest_index].status = 2; // 1: confirmed, 2: cancelled
    num_guests--;
}

int main() {
    srand(time(NULL)); // initialize random number generator

    // Read names and arrival times from the user
    read_names_arrival_times();

    // Print the list of guests and their reservations
    print_guests_reservations();

    // Make reservations
    for (int i = 0; i < MAX_GUESTS; i++) {
        make_reservation(i);
    }

    // Cancel reservations
    for (int i = 0; i < MAX_GUESTS; i++) {
        cancel_reservation(i);
    }

    // Print the final list of guests and their reservations
    print_guests_reservations();

    return 0;
}