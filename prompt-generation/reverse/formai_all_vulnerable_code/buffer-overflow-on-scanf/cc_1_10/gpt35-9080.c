//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int room_number;
    int num_nights;
    float price_per_night;
} Guest;

void print_menu() {
    printf("Welcome to C Hotel Management System\n");
    printf("\n");
    printf("1. Check-in a guest\n");
    printf("2. Check-out a guest\n");
    printf("3. View all guests\n");
    printf("4. Search for a guest\n");
    printf("5. Quit\n");
    printf("\n");
}

void check_in(Guest* guests, int* num_guests) {
    if(*num_guests == MAX_ROOMS) {
        printf("Hotel is fully booked\n");
        return;
    }

    Guest new_guest;
    printf("Enter guest name: ");
    scanf("%s", new_guest.name);
    printf("Enter room number: ");
    scanf("%d", &new_guest.room_number);
    printf("Enter number of nights: ");
    scanf("%d", &new_guest.num_nights);
    printf("Enter price per night: ");
    scanf("%f", &new_guest.price_per_night);

    guests[*num_guests] = new_guest;
    *num_guests += 1;

    printf("Guest checked in successfully\n");
}

int find_guest(Guest* guests, int num_guests, char* name) {
    for(int i = 0; i < num_guests; i++) {
        if(strcmp(guests[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void check_out(Guest* guests, int* num_guests) {
    char name[MAX_NAME_LEN];
    printf("Enter guest name: ");
    scanf("%s", name);

    int index = find_guest(guests, *num_guests, name);
    if(index == -1) {
        printf("Guest not found\n");
        return;
    }

    *num_guests -= 1;
    guests[index] = guests[*num_guests];

    printf("Guest checked out successfully\n");
}

void print_guest(Guest guest) {
    printf("Name: %s, Room Number: %d, Number of Nights: %d, Price per Night: $%.2f\n", guest.name, guest.room_number, guest.num_nights, guest.price_per_night);
}

void view_all_guests(Guest* guests, int num_guests) {
    printf("Current Guests:\n");
    for(int i = 0; i < num_guests; i++) {
        printf("%d. ", i+1);
        print_guest(guests[i]);
    }
}

void search_guest(Guest* guests, int num_guests) {
    char name[MAX_NAME_LEN];
    printf("Enter guest name: ");
    scanf("%s", name);

    int index = find_guest(guests, num_guests, name);
    if(index == -1) {
        printf("Guest not found\n");
        return;
    }

    printf("Guest found:\n");
    print_guest(guests[index]);
}

int main() {
    Guest guests[MAX_ROOMS];
    int num_guests = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_in(guests, &num_guests);
                break;
            case 2:
                check_out(guests, &num_guests);
                break;
            case 3:
                view_all_guests(guests, num_guests);
                break;
            case 4:
                search_guest(guests, num_guests);
                break;
            case 5:
                printf("Thank you for using C Hotel Management System\n");
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    } while(choice != 5);

    return 0;
}