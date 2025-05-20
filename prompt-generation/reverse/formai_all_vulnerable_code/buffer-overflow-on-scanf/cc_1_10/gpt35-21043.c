//FormAI DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Hotel {
    char name[50];
    char address[100];
    char email[50];
    char phone[20];
    int rooms;
    int booked_rooms;
    float room_rates;
};

void registerHotel(struct Hotel *h) {
    printf("\nEnter the Hotel name: ");
    scanf("%[^\n]%*c", h->name);
    printf("Enter the Hotel address: ");
    scanf("%[^\n]%*c", h->address);
    printf("Enter the Hotel email address: ");
    scanf("%[^\n]%*c", h->email);
    printf("Enter the Hotel phone number: ");
    scanf("%[^\n]%*c", h->phone);
    printf("Enter the number of available rooms: ");
    scanf("%d", &h->rooms);
    printf("Enter the room rate per day: ");
    scanf("%f", &h->room_rates);
    h->booked_rooms = 0;
}

void bookRoom(struct Hotel *h) {
    int n;
    printf("\nEnter the number of rooms to book: ");
    scanf("%d", &n);
    if(n > h->rooms) {
        printf("\nSorry, rooms not available!");
        return;
    }
    h->rooms -= n;
    h->booked_rooms += n;
    printf("\n%d rooms booked successfully!", n);
}

void cancelBooking(struct Hotel *h) {
    int n;
    printf("\nEnter the number of rooms to cancel: ");
    scanf("%d", &n);
    if(n > h->booked_rooms) {
        printf("\nInvalid input!");
        return;
    }
    h->rooms += n;
    h->booked_rooms -= n;
    printf("\n%d rooms canceled successfully!", n);
}

void display(struct Hotel *h) {
    printf("\nHotel Name: %s", h->name);
    printf("\nAddress: %s", h->address);
    printf("\nEmail: %s", h->email);
    printf("\nPhone: %s", h->phone);
    printf("\nAvailable Rooms: %d", h->rooms);
    printf("\nBooked Rooms: %d", h->booked_rooms);
    printf("\nRoom Rates: %.2f", h->room_rates);
}

int main() {
    struct Hotel h1;
    int choice;
    printf("Welcome to Hotel Management System!\n");
    printf("1.Register a hotel\n2.Book a room\n3.Cancel booking\n4.Display information\n5.Quit\n");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                registerHotel(&h1);
                break;
            case 2:
                bookRoom(&h1);
                break;
            case 3:
                cancelBooking(&h1);
                break;
            case 4:
                display(&h1);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
        }
        printf("\n");
    }
    return 0;
}