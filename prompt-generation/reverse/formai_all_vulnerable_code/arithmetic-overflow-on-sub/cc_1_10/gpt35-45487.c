//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000
#define MAX_RESERVATIONS 1000

// Structs
typedef struct {
    int id;
    char name[50];
    int age;
    char phone[15];
    char email[50];
    int num_stays;
} Guest;

typedef struct {
    int id;
    int price;
    int num_guests;
    char type[20];
} Room;

typedef struct {
    int id;
    int room_id;
    int guest_id;
    int num_nights;
    char check_in[20];
    char check_out[20];
} Reservation;

// Global Variables
Guest guests[MAX_GUESTS];
Room rooms[MAX_ROOMS];
Reservation reservations[MAX_RESERVATIONS];
int num_guests = 0;
int num_rooms = 0;
int num_reservations = 0;

// Function Prototypes
void add_guest();
void add_room();
void reserve_room();
void check_out();
void display_guests();
void display_rooms();
void display_reservations();

// Main Function
int main() {
    int choice;
    printf("Welcome to C Hotel Management System!\n");

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add Guest\n");
        printf("2. Add Room\n");
        printf("3. Reserve Room\n");
        printf("4. Check Out\n");
        printf("5. Display Guests\n");
        printf("6. Display Rooms\n");
        printf("7. Display Reservations\n");
        printf("8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest();
                break;
            case 2:
                add_room();
                break;
            case 3:
                reserve_room();
                break;
            case 4:
                check_out();
                break;
            case 5:
                display_guests();
                break;
            case 6:
                display_rooms();
                break;
            case 7:
                display_reservations();
                break;
            case 8:
                printf("Thank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

// Function Definitions
void add_guest() {
    Guest guest;
    printf("\n---- ADD GUEST ----\n");
    printf("Name: ");
    getchar();
    fgets(guest.name, 50, stdin);
    printf("Age: ");
    scanf("%d", &guest.age);
    printf("Phone: ");
    scanf("%s", guest.phone);
    printf("Email: ");
    scanf("%s", guest.email);
    guest.num_stays = 0;
    guest.id = num_guests + 1;
    guests[num_guests++] = guest;
    printf("Guest Added Successfully!\n");
}

void add_room() {
    Room room;
    printf("\n---- ADD ROOM ----\n");
    printf("Type: ");
    getchar();
    fgets(room.type, 20, stdin);
    printf("Price: ");
    scanf("%d", &room.price);
    printf("Number of Guests: ");
    scanf("%d", &room.num_guests);
    room.id = num_rooms + 1;
    rooms[num_rooms++] = room;
    printf("Room Added Successfully!\n");
}

void reserve_room() {
    Guest guest;
    int guest_id, room_id, num_nights;
    char check_in[20], check_out[20];
    printf("\n---- RESERVE ROOM ----\n");
    printf("Guest ID: ");
    scanf("%d", &guest_id);
    printf("Room ID: ");
    scanf("%d", &room_id);
    printf("Number of Nights: ");
    scanf("%d", &num_nights);
    printf("Check-in Date (MM/DD/YYYY): ");
    scanf("%s", check_in);
    printf("Check-out Date (MM/DD/YYYY): ");
    scanf("%s", check_out);
    strcpy(reservations[num_reservations].check_in, check_in);
    strcpy(reservations[num_reservations].check_out, check_out);
    reservations[num_reservations].num_nights = num_nights;
    reservations[num_reservations].guest_id = guest_id;
    reservations[num_reservations].room_id = room_id;
    reservations[num_reservations++].id = num_reservations + 1;
    guest = guests[guest_id - 1];
    guest.num_stays++;
    guests[guest_id - 1] = guest;
    printf("Reservation Made Successfully!\n");
}

void check_out() {
    int res_num, guest_id, room_id, total_price;
    Guest guest;
    printf("\n---- CHECK OUT ----\n");
    printf("Reservation Number: ");
    scanf("%d", &res_num);
    guest_id = reservations[res_num - 1].guest_id;
    room_id = reservations[res_num - 1].room_id;
    reservations[res_num - 1].num_nights = 0;
    guest = guests[guest_id - 1];
    guest.num_stays--;
    guests[guest_id - 1] = guest;
    total_price = reservations[res_num - 1].num_nights * rooms[room_id - 1].price;
    printf("Total Price: %d\n", total_price);
    printf("Guest Checked Out Successfully!\n");
}

void display_guests() {
    int i;
    printf("\n---- GUESTS ----\n");
    printf("ID\tName\t\t\tAge\tPhone\t\tEmail\t\t\tNumber of Stays\n");
    for(i = 0; i < num_guests; i++) {
        printf("%d\t%s\t%d\t%s\t%s\t\t\t%d\n", guests[i].id, guests[i].name, guests[i].age, guests[i].phone, guests[i].email, guests[i].num_stays);
    }
}

void display_rooms() {
    int i;
    printf("\n---- ROOMS ----\n");
    printf("ID\tType\t\tPrice\tNumber of Guests\n");
    for(i = 0; i < num_rooms; i++) {
        printf("%d\t%s\t%d\t%d\n", rooms[i].id, rooms[i].type, rooms[i].price, rooms[i].num_guests);
    }
}

void display_reservations() {
    int i;
    printf("\n---- RESERVATIONS ----\n");
    printf("ID\tGuest ID\tRoom ID\tNumber of Nights\tCheck-in Date\tCheck-out Date\n");
    for(i = 0; i < num_reservations; i++) {
        printf("%d\t%d\t\t%d\t%d\t\t%s\t\t%s\n", reservations[i].id, reservations[i].guest_id, reservations[i].room_id, reservations[i].num_nights, reservations[i].check_in, reservations[i].check_out);
    }
}