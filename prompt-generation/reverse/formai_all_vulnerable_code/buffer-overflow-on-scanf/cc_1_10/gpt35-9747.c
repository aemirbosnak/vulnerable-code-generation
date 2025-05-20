//FormAI DATASET v1.0 Category: Hotel Management System ; Style: creative
// Welcome to the Unique Hotel Management System!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Guest {
    char name[50];
    char address[100];
    char email[100];
    char phone[20];
    int room_number;
    int nights;
    int price_per_night;
};

struct Room {
    int room_number;
    int price_per_night;
    int is_available;
};

void print_header(){
    printf("\n****************************");
    printf("\n*  Hotel Management System *");
    printf("\n****************************");
}

int get_guest_count(){
    int guest_count;
    printf("\nEnter the number of guests: ");
    scanf("%d", &guest_count);
    return guest_count;
}

struct Guest* get_guest_details(struct Guest *guest){
    printf("\nEnter guest name: ");
    scanf("%s", guest->name);
    printf("\nEnter guest address: ");
    scanf("%s", guest->address);
    printf("\nEnter guest email: ");
    scanf("%s", guest->email);
    printf("\nEnter guest phone number: ");
    scanf("%s", guest->phone);
    printf("\nEnter number of nights: ");
    scanf("%d", &guest->nights);
    return guest;
}

int get_room_count(){
    int room_count;
    printf("\nEnter the number of rooms: ");
    scanf("%d", &room_count);
    return room_count;
}

void initialize_rooms(struct Room *room, int room_count){
    for(int i=0; i<room_count; i++){
        printf("\nEnter room %d number: ", i+1);
        scanf("%d", &room[i].room_number);
        printf("\nEnter room %d price per night: ", i+1);
        scanf("%d", &room[i].price_per_night);
        room[i].is_available = 1;
    }
}

int book_room(struct Guest *guest, struct Room *room, int room_count){
    int is_booked = 0;
    for(int i=0; i<room_count; i++){
        if(room[i].is_available){
            guest->room_number = room[i].room_number;
            guest->price_per_night = room[i].price_per_night;
            room[i].is_available = 0;
            printf("\nRoom %d has been booked!\n", room[i].room_number);
            is_booked = 1;
            break;
        }
    }
    return is_booked;
}

void print_guest(struct Guest guest){
    printf("\nGuest Details:\n");
    printf("Name: %s\n", guest.name);
    printf("Address: %s\n", guest.address);
    printf("Email: %s\n", guest.email);
    printf("Phone: %s\n", guest.phone);
    printf("Room No: %d\n", guest.room_number);
    printf("Nights: %d\n", guest.nights);
    printf("Price per night: %d\n\n", guest.price_per_night);
}

void print_guests(struct Guest *guest, int guest_count){
    printf("\nGuest List:\n");
    for(int i=0; i<guest_count; i++){
        printf("%d. %s\n", i+1, guest[i].name);
    }
}

int main(){
    int guest_count, room_count, is_booked;
    struct Guest guests[50];
    struct Room rooms[10]; // Maximum rooms in Hotel
    
    print_header();
    
    guest_count = get_guest_count();
    
    for(int i=0; i<guest_count; i++){
        printf("\nEnter details for guest %d:\n", i+1);
        get_guest_details(&guests[i]);
        room_count = get_room_count();
        initialize_rooms(rooms, room_count);
        is_booked = book_room(&guests[i], rooms, room_count);
        if(is_booked){
            print_guest(guests[i]);
        }
        else{
            printf("\nSorry, no rooms are available.\n");
            guest_count--;
        }
    }
    
    print_guests(guests, guest_count);
    
    return 0;
}