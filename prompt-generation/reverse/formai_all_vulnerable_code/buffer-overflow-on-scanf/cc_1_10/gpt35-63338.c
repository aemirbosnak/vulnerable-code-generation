//FormAI DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char address[100];
    char phone[15];
} Guest;

typedef struct {
    int id;
    char type[30];
    int capacity;
    float price;
} Room;

typedef struct {
    int room_num;
    int guest_id;
    char check_in[15];
    char check_out[15];
    float total_price;
} Reservation;

Guest guests[100];
Room rooms[30];
Reservation reservations[100];
int guests_count = 0;
int rooms_count = 0;
int reservations_count = 0;

void print_guest(Guest guest) {
    printf("\nName: %s", guest.name);
    printf("\nAge: %d", guest.age);
    printf("\nGender: %s", guest.gender);
    printf("\nAddress: %s", guest.address);
    printf("\nPhone: %s", guest.phone);
}

void print_room(Room room) {
    printf("\nID: %d", room.id);
    printf("\nType: %s", room.type);
    printf("\nCapacity: %d", room.capacity);
    printf("\nPrice per night: %.2f", room.price);
}

void print_reservations() {
    printf("\nRoom\tGuest\tCheckin\t\tCheckout\tTotal Price\n");
    for (int i = 0; i < reservations_count; i++) {
        printf("%d\t%d\t%s\t%s\t%.2f\n", reservations[i].room_num, reservations[i].guest_id, reservations[i].check_in, reservations[i].check_out, reservations[i].total_price);
    }
}

void add_guest() {
    printf("\nEnter guest details:");
    printf("\nName: ");
    scanf("%s", guests[guests_count].name);
    printf("\nAge: ");
    scanf("%d", &guests[guests_count].age);
    printf("\nGender: ");
    scanf("%s", guests[guests_count].gender);
    printf("\nAddress: ");
    scanf("%s", guests[guests_count].address);
    printf("\nPhone: ");
    scanf("%s", guests[guests_count].phone);
    printf("\nGuest added successfully!\n");
    guests_count++;
}

void add_room() {
    printf("\nEnter room details:");
    printf("\nID: ");
    scanf("%d", &rooms[rooms_count].id);
    printf("\nType: ");
    scanf("%s", rooms[rooms_count].type);
    printf("\nCapacity: ");
    scanf("%d", &rooms[rooms_count].capacity);
    printf("\nPrice per night: ");
    scanf("%f", &rooms[rooms_count].price);
    printf("\nRoom added successfully!\n");
    rooms_count++;
}

void make_reservation() {
    int room_num, guest_id, num_nights;
    char check_in[15], check_out[15];
    float total_price;
    printf("\nEnter room number and guest ID:");
    scanf("%d %d", &room_num, &guest_id);
    printf("\nEnter check-in date (yyyy-mm-dd): ");
    scanf("%s", check_in);
    printf("\nEnter check-out date (yyyy-mm-dd): ");
    scanf("%s", check_out);
    printf("\nEnter number of nights: ");
    scanf("%d", &num_nights);
    for (int i = 0; i < rooms_count; i++) {
        if (rooms[i].id == room_num) {
            total_price = rooms[i].price * num_nights;
        }
    }
    printf("\nTotal price: %.2f", total_price);
    printf("\nEnter 'confirm' to make reservation: ");
    char confirm[10];
    scanf("%s", confirm);
    if (strcmp(confirm, "confirm") == 0) {
        reservations[reservations_count].room_num = room_num;
        reservations[reservations_count].guest_id = guest_id;
        strcpy(reservations[reservations_count].check_in, check_in);
        strcpy(reservations[reservations_count].check_out, check_out);
        reservations[reservations_count].total_price = total_price;
        printf("\nReservation made successfully!\n");
        reservations_count++;
    } else {
        printf("\nReservation cancelled!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n\nC Hotel Management System\n");
        printf("\n1. Add guest");
        printf("\n2. Add room");
        printf("\n3. Make reservation");
        printf("\n4. View reservations");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_guest(); break;
            case 2: add_room(); break;
            case 3: make_reservation(); break;
            case 4: print_reservations(); break;
            case 5: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}