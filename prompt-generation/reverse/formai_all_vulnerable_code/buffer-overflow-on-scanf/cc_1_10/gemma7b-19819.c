//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel management system structure
typedef struct hotel_management_system {
    int room_number;
    char guest_name[20];
    char guest_email[50];
    int num_of_days;
    float total_cost;
} hotel_management_system;

// Function to create a new room reservation
hotel_management_system* create_reservation() {
    hotel_management_system* new_reservation = (hotel_management_system*)malloc(sizeof(hotel_management_system));
    new_reservation->room_number = rand() % 100;
    new_reservation->guest_name[0] = '\0';
    new_reservation->guest_email[0] = '\0';
    new_reservation->num_of_days = 0;
    new_reservation->total_cost = 0.0;
    return new_reservation;
}

// Function to add guest information
void add_guest_info(hotel_management_system* reservation) {
    printf("Enter your name: ");
    scanf("%s", reservation->guest_name);
    printf("Enter your email address: ");
    scanf("%s", reservation->guest_email);
}

// Function to add number of days
void add_num_of_days(hotel_management_system* reservation) {
    printf("Enter the number of days you will be staying: ");
    scanf("%d", &reservation->num_of_days);
}

// Function to calculate total cost
void calculate_total_cost(hotel_management_system* reservation) {
    reservation->total_cost = reservation->num_of_days * 50.0;
}

// Function to print reservation details
void print_reservation_details(hotel_management_system* reservation) {
    printf("Room number: %d\n", reservation->room_number);
    printf("Guest name: %s\n", reservation->guest_name);
    printf("Guest email: %s\n", reservation->guest_email);
    printf("Number of days: %d\n", reservation->num_of_days);
    printf("Total cost: %.2f\n", reservation->total_cost);
}

int main() {
    hotel_management_system* reservation = create_reservation();
    add_guest_info(reservation);
    add_num_of_days(reservation);
    calculate_total_cost(reservation);
    print_reservation_details(reservation);

    return 0;
}