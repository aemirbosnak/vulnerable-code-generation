//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
// A Donald Knuth-style hotel management system in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    int id;
    char name[50];
    int age;
    int room_number;
} Guest;

typedef struct {
    int id;
    char name[50];
    int type; // 1 for single, 2 for double, 3 for suite
    int number_of_rooms;
} Reservation;

// Function prototypes
void print_menu();
void add_guest();
void remove_guest();
void add_reservation();
void remove_reservation();
void view_reservation();

// Global variables
Guest guests[100];
Reservation reservations[100];
int guest_count = 0;
int reservation_count = 0;

// Main function
int main() {
    print_menu();

    while (1) {
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                remove_guest();
                break;
            case 3:
                add_reservation();
                break;
            case 4:
                remove_reservation();
                break;
            case 5:
                view_reservation();
                break;
            case 6:
                return 0;
        }
    }

    return 0;
}

// Function definitions
void print_menu() {
    printf("Hotel Management System\n");
    printf("1. Add guest\n");
    printf("2. Remove guest\n");
    printf("3. Add reservation\n");
    printf("4. Remove reservation\n");
    printf("5. View reservation\n");
    printf("6. Exit\n");
}

void add_guest() {
    if (guest_count >= 100) {
        printf("Hotel is full. Cannot add guest.\n");
        return;
    }

    printf("Enter guest's name: ");
    scanf("%s", &guests[guest_count].name);

    printf("Enter guest's age: ");
    scanf("%d", &guests[guest_count].age);

    printf("Enter guest's room number: ");
    scanf("%d", &guests[guest_count].room_number);

    guests[guest_count].id = guest_count + 1;
    guest_count++;
}

void remove_guest() {
    int id;

    printf("Enter guest's id: ");
    scanf("%d", &id);

    for (int i = 0; i < guest_count; i++) {
        if (guests[i].id == id) {
            guests[i] = guests[guest_count - 1];
            guest_count--;
            return;
        }
    }

    printf("Guest not found.\n");
}

void add_reservation() {
    if (reservation_count >= 100) {
        printf("Hotel is full. Cannot add reservation.\n");
        return;
    }

    printf("Enter reservation's name: ");
    scanf("%s", &reservations[reservation_count].name);

    printf("Enter reservation's type (1 for single, 2 for double, 3 for suite): ");
    scanf("%d", &reservations[reservation_count].type);

    printf("Enter reservation's number of rooms: ");
    scanf("%d", &reservations[reservation_count].number_of_rooms);

    reservations[reservation_count].id = reservation_count + 1;
    reservation_count++;
}

void remove_reservation() {
    int id;

    printf("Enter reservation's id: ");
    scanf("%d", &id);

    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].id == id) {
            reservations[i] = reservations[reservation_count - 1];
            reservation_count--;
            return;
        }
    }

    printf("Reservation not found.\n");
}

void view_reservation() {
    int id;

    printf("Enter reservation's id: ");
    scanf("%d", &id);

    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].id == id) {
            printf("Reservation:\n");
            printf("ID: %d\n", reservations[i].id);
            printf("Name: %s\n", reservations[i].name);
            printf("Type: %d\n", reservations[i].type);
            printf("Number of rooms: %d\n", reservations[i].number_of_rooms);
            return;
        }
    }

    printf("Reservation not found.\n");
}