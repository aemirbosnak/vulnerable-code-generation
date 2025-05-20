//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char name[50];
    int room_number;
    int number_of_days;
    int price;
} Reservation;

typedef struct {
    char name[50];
    int room_number;
    int number_of_days;
    int price;
    int is_paid;
} Bill;

// Function Prototypes
void print_menu();
void add_reservation(Reservation reservation);
void update_reservation(Reservation reservation);
void delete_reservation(Reservation reservation);
void print_reservations();
void generate_bill(Bill bill);
void print_bill(Bill bill);

// Global Variables
Reservation reservations[100];
Bill bills[100];
int num_reservations = 0;
int num_bills = 0;

int main() {
    print_menu();
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_reservation(reservations[num_reservations]);
            num_reservations++;
            break;
        case 2:
            update_reservation(reservations[num_reservations]);
            break;
        case 3:
            delete_reservation(reservations[num_reservations]);
            num_reservations--;
            break;
        case 4:
            print_reservations();
            break;
        case 5:
            generate_bill(bills[num_bills]);
            num_bills++;
            break;
        case 6:
            print_bill(bills[num_bills]);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}

void print_menu() {
    printf("Hotel Management System\n");
    printf("1. Add Reservation\n");
    printf("2. Update Reservation\n");
    printf("3. Delete Reservation\n");
    printf("4. Print Reservations\n");
    printf("5. Generate Bill\n");
    printf("6. Print Bill\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void add_reservation(Reservation reservation) {
    printf("Enter the name of the guest: ");
    scanf("%s", reservation.name);
    printf("Enter the room number: ");
    scanf("%d", &reservation.room_number);
    printf("Enter the number of days: ");
    scanf("%d", &reservation.number_of_days);
    printf("Enter the price: ");
    scanf("%d", &reservation.price);
}

void update_reservation(Reservation reservation) {
    printf("Enter the name of the guest: ");
    scanf("%s", reservation.name);
    printf("Enter the room number: ");
    scanf("%d", &reservation.room_number);
    printf("Enter the number of days: ");
    scanf("%d", &reservation.number_of_days);
    printf("Enter the price: ");
    scanf("%d", &reservation.price);
}

void delete_reservation(Reservation reservation) {
    printf("Enter the name of the guest: ");
    scanf("%s", reservation.name);
    printf("Enter the room number: ");
    scanf("%d", &reservation.room_number);
    printf("Enter the number of days: ");
    scanf("%d", &reservation.number_of_days);
    printf("Enter the price: ");
    scanf("%d", &reservation.price);
}

void print_reservations() {
    for (int i = 0; i < num_reservations; i++) {
        printf("%s, %d, %d, %d\n", reservations[i].name, reservations[i].room_number, reservations[i].number_of_days, reservations[i].price);
    }
}

void generate_bill(Bill bill) {
    printf("Enter the name of the guest: ");
    scanf("%s", bill.name);
    printf("Enter the room number: ");
    scanf("%d", &bill.room_number);
    printf("Enter the number of days: ");
    scanf("%d", &bill.number_of_days);
    printf("Enter the price: ");
    scanf("%d", &bill.price);
    bill.is_paid = 0;
}

void print_bill(Bill bill) {
    printf("%s, %d, %d, %d, %d\n", bill.name, bill.room_number, bill.number_of_days, bill.price, bill.is_paid);
}