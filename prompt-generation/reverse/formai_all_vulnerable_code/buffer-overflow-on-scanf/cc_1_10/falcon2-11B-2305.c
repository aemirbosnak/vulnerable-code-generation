//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender[5];
} Guest;

typedef struct {
    Guest guest;
    int room_number;
    int check_in_date;
    int check_out_date;
} Reservation;

void get_guest_info(Guest* guest, char* name, int* age, char* gender) {
    printf("Enter guest name: ");
    fgets(guest->name, sizeof(guest->name), stdin);
    printf("Enter guest age: ");
    scanf("%d", age);
    printf("Enter guest gender (M/F): ");
    fgets(guest->gender, sizeof(guest->gender), stdin);
}

void get_reservation_info(Reservation* reservation, char* name, int* age, char* gender, int* room_number, int* check_in_date, int* check_out_date) {
    Guest guest;
    get_guest_info(&guest, name, age, gender);
    printf("Enter room number: ");
    scanf("%d", room_number);
    printf("Enter check-in date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", check_in_date, &guest.age, &guest.age);
    printf("Enter check-out date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", check_out_date, &guest.age, &guest.age);
    reservation->guest = guest;
    reservation->room_number = *room_number;
    reservation->check_in_date = *check_in_date;
    reservation->check_out_date = *check_out_date;
}

void display_guest_info(Guest* guest) {
    printf("Guest name: %s\n", guest->name);
    printf("Guest age: %d\n", guest->age);
    printf("Guest gender: %s\n", guest->gender);
}

void display_reservation_info(Reservation* reservation) {
    Guest guest;
    display_guest_info(&guest);
    printf("Room number: %d\n", reservation->room_number);
    printf("Check-in date: %d/%d/%d\n", reservation->check_in_date, &guest.age, &guest.age);
    printf("Check-out date: %d/%d/%d\n", reservation->check_out_date, &guest.age, &guest.age);
}

int main() {
    Guest guest;
    Reservation reservation;
    char name[50], gender[5];
    int age, room_number, check_in_date, check_out_date;
    
    get_guest_info(&guest, name, &age, gender);
    printf("Guest info:\n");
    display_guest_info(&guest);
    
    get_reservation_info(&reservation, name, &age, gender, &room_number, &check_in_date, &check_out_date);
    printf("Reservation info:\n");
    display_reservation_info(&reservation);
    
    return 0;
}