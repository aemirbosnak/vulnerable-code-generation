//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ROOMS 100
#define MAX_GUESTS 1000
#define MAX_DAYS 30

// Data structures
typedef struct {
    int room_number;
    char *guest_name;
    int arrival_date;
    int departure_date;
} reservation;

typedef struct {
    reservation reservations[MAX_ROOMS];
    int num_reservations;
} hotel;

// Function prototypes
void initialize_hotel(hotel *h);
void add_reservation(hotel *h, reservation *r);
void cancel_reservation(hotel *h, int room_number);
void print_reservations(hotel *h);
void save_reservations(hotel *h, char *filename);
void load_reservations(hotel *h, char *filename);

// Main function
int main() {
    // Initialize the hotel
    hotel h;
    initialize_hotel(&h);

    // Add some reservations
    reservation r1 = {101, "John Doe", 15, 20};
    reservation r2 = {102, "Jane Smith", 18, 22};
    reservation r3 = {103, "Bill Jones", 21, 25};
    add_reservation(&h, &r1);
    add_reservation(&h, &r2);
    add_reservation(&h, &r3);

    // Print the reservations
    print_reservations(&h);

    // Save the reservations to a file
    save_reservations(&h, "reservations.txt");

    // Load the reservations from a file
    load_reservations(&h, "reservations.txt");

    // Print the reservations
    print_reservations(&h);

    return 0;
}

// Function definitions
void initialize_hotel(hotel *h) {
    h->num_reservations = 0;
}

void add_reservation(hotel *h, reservation *r) {
    if (h->num_reservations < MAX_ROOMS) {
        h->reservations[h->num_reservations] = *r;
        h->num_reservations++;
    } else {
        printf("Error: Hotel is full.\n");
    }
}

void cancel_reservation(hotel *h, int room_number) {
    for (int i = 0; i < h->num_reservations; i++) {
        if (h->reservations[i].room_number == room_number) {
            // Remove the reservation from the array
            for (int j = i; j < h->num_reservations - 1; j++) {
                h->reservations[j] = h->reservations[j + 1];
            }
            h->num_reservations--;
            break;
        }
    }
}

void print_reservations(hotel *h) {
    for (int i = 0; i < h->num_reservations; i++) {
        printf("Room: %d, Guest: %s, Arrival: %d, Departure: %d\n",
               h->reservations[i].room_number,
               h->reservations[i].guest_name,
               h->reservations[i].arrival_date,
               h->reservations[i].departure_date);
    }
}

void save_reservations(hotel *h, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    for (int i = 0; i < h->num_reservations; i++) {
        fprintf(fp, "%d,%s,%d,%d\n",
                h->reservations[i].room_number,
                h->reservations[i].guest_name,
                h->reservations[i].arrival_date,
                h->reservations[i].departure_date);
    }

    fclose(fp);
}

void load_reservations(hotel *h, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    // Read the reservations from the file
    while (!feof(fp)) {
        reservation r;
        fscanf(fp, "%d,%s,%d,%d",
               &r.room_number,
               r.guest_name,
               &r.arrival_date,
               &r.departure_date);
        add_reservation(h, &r);
    }

    fclose(fp);
}