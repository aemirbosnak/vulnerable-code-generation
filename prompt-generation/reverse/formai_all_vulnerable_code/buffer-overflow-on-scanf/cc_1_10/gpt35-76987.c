//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures
struct Customer {
    char name[50];
    char address[100];
    char phone_no[20];
};

struct Booking {
    int room_no;
    char check_in[20];
    char check_out[20];
    struct Customer customer;
};

//Global Variables
struct Booking bookings[20];
int num_of_bookings = 0;

//Functions
void display_menu() {
    printf("Welcome to the C Hotel Management System\n");
    printf("1. View all bookings\n");
    printf("2. Add a new booking\n");
    printf("3. Delete a booking\n");
    printf("4. Search for a booking\n");
    printf("5. Exit the program\n");
    printf("Enter your choice: ");
}

void view_bookings() {
    if(num_of_bookings == 0) {
        printf("No bookings found.\n");
    }
    else {
        printf("All Bookings:\n");
        printf("Room No.\tCheck-In\tCheck-Out\tName\t\tAddress\t\tPhone No.\n");
        for(int i=0; i<num_of_bookings; i++) {
            printf("%d\t\t%s\t%s\t%s\t%s\t%s\n", bookings[i].room_no, bookings[i].check_in, bookings[i].check_out, 
            bookings[i].customer.name, bookings[i].customer.address, bookings[i].customer.phone_no);
        }
    }
}

void add_booking() {
    struct Booking new_booking;
    printf("Enter Room No.: ");
    scanf("%d", &new_booking.room_no);
    printf("Enter Check-In date (DD/MM/YYYY): ");
    scanf("%s", new_booking.check_in);
    printf("Enter Check-Out date (DD/MM/YYYY): ");
    scanf("%s", new_booking.check_out);
    printf("Enter Customer Name: ");
    scanf("%s", new_booking.customer.name);
    printf("Enter Customer Address: ");
    scanf("%s", new_booking.customer.address);
    printf("Enter Customer Phone No.: ");
    scanf("%s", new_booking.customer.phone_no);
    bookings[num_of_bookings++] = new_booking;
    printf("Booking Added Successfully.\n");
}

void delete_booking() {
    int room_no, found_booking = 0;
    printf("Enter Room No. of the booking to be deleted: ");
    scanf("%d", &room_no);
    for(int i=0; i<num_of_bookings; i++) {
        if(bookings[i].room_no == room_no) {
            found_booking = 1;
            for(int j=i; j<num_of_bookings-1; j++) {
                bookings[j] = bookings[j+1];
            }
            num_of_bookings--;
            printf("Booking Deleted Successfully.\n");
            break;
        }
    }
    if(found_booking == 0) {
        printf("Booking not found.\n");
    }
}

void search_booking() {
    int room_no, found_booking = 0;
    printf("Enter Room No. of the booking to search: ");
    scanf("%d", &room_no);
    for(int i=0; i<num_of_bookings; i++) {
        if(bookings[i].room_no == room_no) {
            found_booking = 1;
            printf("Booking Found:\n");
            printf("Room No.\tCheck-In\tCheck-Out\tName\t\tAddress\t\tPhone No.\n");
            printf("%d\t\t%s\t%s\t%s\t%s\t%s\n", bookings[i].room_no, bookings[i].check_in, bookings[i].check_out, 
            bookings[i].customer.name, bookings[i].customer.address, bookings[i].customer.phone_no);
            break;
        }
    }
    if(found_booking == 0) {
        printf("Booking not found.\n");
    }
}

int main() {
    int choice;
    while(1) {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                view_bookings();
                break;
            case 2:
                add_booking();
                break;
            case 3:
                delete_booking();
                break;
            case 4:
                search_booking();
                break;
            case 5:
                printf("Exiting the C Hotel Management System...");
                exit(0);
            default:
                printf("Invalid Choice. Please Try Again.\n");
        }
    }
    return 0;
}